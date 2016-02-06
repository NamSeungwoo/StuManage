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
	if (FindEHGroup(gname)) // gname의 그룹 찾기 성공했을 때
	{
		return false;
	}

	// gname의 그룹 찾기 실패 했을 때
	EHGroup *ehgroup = new EHGroup(gname);
	gl.push_back(ehgroup);
	return true; 

}

EHGroup* EHWorld::FindEHGroup(string gname)
{
	GLIter seek = gl.begin();
	GLIter end = gl.end();
	EHGroup *ehgroup = 0;

	//반복자를 이용하여 차례대로 그룹 이름 비교
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
	EHGroup *ehgroup = FindEHGroup(gname); // 그룹이름이 gname인 그룹 찾기

	if (ehgroup) // 그룹이름이 gname인 그룹을 찾았을 때
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

	//반복자를 차례대로 이동하면서 보관된 요소를 함수 개체에 적용
	for (; seek != end; ++seek)
	{
		ideg(*seek); // 보관된 요소를 함수 개체에 적용
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
		ideg(ehgroup); // 그룹의 이름을 보여주는 함수 개체 수행
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