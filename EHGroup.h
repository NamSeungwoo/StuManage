#pragma once
#include "EHMember.h"
#include "IDoEHMember.h"
#include <vector>
using std::vector;

//멤버의 위치 정보를 보관하는 vector를 MemberVector이름으로 typedef
typedef vector<EHMember*> MemberVector;

//멤버의 위치 정보를 보관하는 vector의 반복자를 MVIter이름으로 typedef
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