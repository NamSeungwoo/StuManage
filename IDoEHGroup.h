#pragma once
#include "EHGroup.h"
// 그룹의 위치 정보를 인자로 받는 함수 개체의 추상화

struct IDoEHGroup
{
	virtual void operator()(EHGroup *ehgroup) = 0;
};