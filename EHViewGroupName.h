#pragma once
#include "IDoEHGroup.h"
class EHViewGroupName : public IDoEHGroup
{
public:
	virtual void operator()(EHGroup *ehgroup)
	{
		cout << "�׷��̸�:" << ehgroup->GetName() << endl;
	}
};