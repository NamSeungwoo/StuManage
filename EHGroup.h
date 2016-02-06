#pragma once
#include "EHMember.h"
#include "IDoEHMember.h"
#include <vector>
using std::vector;

//����� ��ġ ������ �����ϴ� vector�� MemberVector�̸����� typedef
typedef vector<EHMember*> MemberVector;

//����� ��ġ ������ �����ϴ� vector�� �ݺ��ڸ� MVIter�̸����� typedef
typedef vector<EHMember*>::iterator MVIter;


class EHGroup
{
	string gname;
	MemberVector mv;
public:
	EHGroup(string gname);
	~EHGroup(void);
	string GetName() const;
	void AddMember(EHMember *ehmember);
	EHMember* FindMember(string id);
	void DoWithMember(IDoEHMember &idem);
};