#pragma once
#include "IDoEHGroup.h"
class EHViewGroupName : public IDoEHGroup
{
public:
	virtual void operator()(EHGroup *ehgroup)
	{
		cout << "그룹이름:" << ehgroup->GetName() << endl;
	}
};