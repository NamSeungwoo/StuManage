#include "EHWorld.h"

EHWorld EHWorld::ehworld;

EHWorld::EHWorld()
{

}

EHWorld::~EHWorld()
{

}
EHWorld* EHWorld::GetEHWorld()
{
	return &ehworld;
}

int EHWorld::GetGroupCount() const
{
	return gl.size();
}

bool EHWorld::MakeEHGroup(string gname)
{
	if (FindEHGroup(gname)) // gname�� �׷� ã�� �������� ��
	{
		return false;
	}

	// gname�� �׷� ã�� ���� ���� ��
	EHGroup *ehgroup = new EHGroup(gname);
	gl.push_back(ehgroup);
	return true; 

}

EHGroup* EHWorld::FindEHGroup(string gname)
{
	GLIter seek = gl.begin();
	GLIter end = gl.end();
	EHGroup *ehgroup = 0;

	//�ݺ��ڸ� �̿��Ͽ� ���ʴ�� �׷� �̸� ��
	for (; seek != end; ++seek)
	{
		ehgroup = *seek;

		if (ehgroup->GetName() == gname)
		{
			return ehgroup;
		}
	}
	return 0;
}

bool EHWorld::ExistMember(string id)
{
	EHMember *ehmember = mm[id];
	return ehmember != 0;
}

bool EHWorld::AddMember(string id, string mname, string gname)
{
	EHGroup *ehgroup = FindEHGroup(gname); // �׷��̸��� gname�� �׷� ã��

	if (ehgroup) // �׷��̸��� gname�� �׷��� ã���� ��
	{
		mcount++;
		mm[id] = new EHMember(mcount, id, mname);
		ehgroup->AddMember(mm[id]);
		return true;
	}
	return false;
}

void EHWorld::ListGroup(IDoEHGroup &ideg)
{
	GLIter seek = gl.begin();
	GLIter end = gl.end();

	//�ݺ��ڸ� ���ʴ�� �̵��ϸ鼭 ������ ��Ҹ� �Լ� ��ü�� ����
	for (; seek != end; ++seek)
	{
		ideg(*seek); // ������ ��Ҹ� �Լ� ��ü�� ����
	}
}

EHMember *EHWorld::FindMember(string id)
{
	return mm[id];
}

bool EHWorld::ExistGroup(string gname)
{
	return FindEHGroup(gname) != 0;
}

EHMember *EHWorld::FindMember(string id, string gname)
{
	EHGroup *ehgroup = FindEHGroup(gname);
	if (ehgroup)
	{
		return ehgroup->FindMember(id);
	}
	return 0;
}

void EHWorld::ViewGroupData(string gname, IDoEHMember &idem)
{
	EHGroup *ehgroup = FindEHGroup(gname);

	if (ehgroup)
	{
		ehgroup->DoWithMember(idem);
	}
}

void EHWorld::ViewAll(IDoEHGroup &ideg, IDoEHMember &idem)
{
	GLIter seek = gl.begin();
	GLIter end = gl.end();
	EHGroup *ehgroup = 0;
	for (; seek != end; ++seek)
	{
		ehgroup = *seek;
		ideg(ehgroup); // �׷��� �̸��� �����ִ� �Լ� ��ü ����
		ehgroup->DoWithMember(idem);
	}
}

void EHWorld::DoItAllMember(IDoEHMember &idem)
{
	MMIter seek = mm.begin();
	MMIter end = mm.end();
	EHMember *ehmember = 0;

	for (; seek != end; ++seek)
	{
		ehmember = (*seek).second;
		if (ehmember)
		{
			idem(ehmember);
		}
	}
}