#pragma once
#include "IDoEHMember.h"
class EHViewMember : public IDoEHMember
{
public:
	virtual void operator()(EHMember *ehmember)
	{
		cout << "�Ϸù�ȣ:" << ehmember->GetSeq() << " ���̵�:" << ehmember->GetId() << " �̸�:" << ehmember->GetName() << endl;
	}
};