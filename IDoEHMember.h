#pragma once
#include "EHMember.h"

//멤버의 위치 정보를 인자로 받는 함수 개체의 추상화
struct IDoEHMember
{
	virtual void operator()(EHMember *ehmember) = 0;
};
