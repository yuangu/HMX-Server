#include "WorldServer_PCH.h"
#include "WorldUserMgr.h"
#include "SceneRegMgr.h"

WorldUserMgr::WorldUserMgr()
{

}

WorldUserMgr::~WorldUserMgr()
{

}

bool WorldUserMgr::getUniqeID(QWORD& tempid)
{
	return true;
}

void WorldUserMgr::putUniqeID(const QWORD& tempid)
{
}

WorldUser* WorldUserMgr::CreateObj()
{
	return objpool.CreateObj();
}

void WorldUserMgr::DestroyObj(WorldUser* user)
{
	objpool.DestroyObj(user);
}

bool WorldUserMgr::add(WorldUser *user)
{
	return zEntryMgrsessid::addEntry(user);
}

WorldUser* WorldUserMgr::get(QWORD id)
{
	return (WorldUser*)zEntryMgrsessid::getEntryByID(id);
}

WorldUser* WorldUserMgr::getBySessID(QWORD sessid)
{
	return (WorldUser*)getEntryBysessid(sessid);
}

WorldUser* WorldUserMgr::getByName(const char* name)
{
	return (WorldUser*)zEntryMgrsessid::getEntryByName(name);
}

void WorldUserMgr::remove(WorldUser* user)
{
	zEntryMgrsessid::removeEntry(user);
}

//////////////////////////////////////////////////////////////////////////

bool WorldUserMgr::checkmd5(int64 accid, int32 keytime, const char* keymd5)
{
	// У��md5
	std::ostringstream outstr;
	outstr << accid;
	outstr << SERVERKEY;
	outstr << keytime;

	unsigned char makeKeymd5[MAX_NAMESIZE + 1];
	memset(makeKeymd5, 0, sizeof(makeKeymd5));
	EncryptMD5(makeKeymd5, (unsigned char*)outstr.str().c_str());
	makeKeymd5[MAX_NAMESIZE] = '\0';

	char reciveKeymd5[MAX_NAMESIZE + 1];
	memset(reciveKeymd5, 0, sizeof(reciveKeymd5));
	strncpy(reciveKeymd5, keymd5, MAX_NAMESIZE);

	if (stricmp((const char*)makeKeymd5, (const char*)reciveKeymd5) != 0)
	{
		Zebra::logger->error("Md5����ʧ�ܣ���Կ��ƥ�� ��Ҫ:%s,����:%s", makeKeymd5, reciveKeymd5);
		return false;
	}

	if (keytime + 86400 < Zebra::timeTick->getNowTime())
	{
		Zebra::logger->error("Md5����ʧ��,ʱ�����");
		return false;
	}

	return true;
}

void WorldUserMgr::sendRoleList(int64 accid, int64 fepsid, int64 sessid)
{
	char wheres[100];
	memset(wheres, 0, sizeof(wheres));
	sprintf(wheres, "`accid`=%lld AND `status`=%d", accid, 0);

	const dbCol fields[] =
	{
		{ "id",DB_QWORD,sizeof(int64) },
		{ "name",DB_STR,MAX_NAMESIZE +1 },
		{ "level",DB_WORD,sizeof(int16) },
		{ NULL,0,0 }
	};

#pragma pack(push,1)
	struct MyStruct
	{
		int64 id;
		char name[MAX_NAMESIZE + 1];
		int16 level;
		MyStruct()
		{
			id = level = 0;
			memset(name, 0, sizeof(name));
		}
	};
#pragma pack(pop)

	MyStruct* dataList, *dataTmp;
	int32 retsize = NetService::getMe().getDbMysql()->ExecSelect("User", fields, wheres, NULL, (unsigned char**)&dataList);
	if (retsize < 0)
	{
		Zebra::logger->warn("��ȡ��ɫ�б�ʧ��");
	}

	W2CUserList send;
	if (retsize && dataList)
	{
		dataTmp = &dataList[0];
		for (int i = 0; i < retsize && i < sizeof(send.datas) / sizeof(send.datas[0]); ++i)
		{
			send.datas[i].id = dataTmp->id;
			send.datas[i].level = dataTmp->level;
			strncpy(send.datas[i].name, dataTmp->name, MAX_NAMESIZE);
			dataTmp++;
		}
		SAFE_DELETE_VEC(dataList);
	}

	if (sessid && fepsid) // ת����fep 
	{
		zSession* fepSs = NetService::getMe().getSessionMgr().getFep(fepsid);
		if (fepSs)
		{
			send.sessid = sessid;
			send.fepsid = fepsid;
			fepSs->sendMsg(&send, send.GetPackLength());
			return;
		}
		else
		{
			Zebra::logger->error("fepsid=%lld����,",fepsid);
			ASSERT(0);
			return;
		}
	}
	else
	{
		Zebra::logger->error("sessid=%lld��fepsid=%lld����,",sessid,fepsid);
		ASSERT(0);
		return;
	}
}