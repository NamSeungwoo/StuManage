#pragma once
#include "IDoEHMember.h"
class EHViewMember : public IDoEHMember
{
public:
	virtual void operator()(EHMember *ehmember)
	{
		cout << "일련번호:" << ehmember->GetSeq() << " 아이디:" << ehmember->GetId() << " 이름:" << ehmember->GetName() << endl;
	}
};