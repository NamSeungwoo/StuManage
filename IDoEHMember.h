#pragma once
#include "EHMember.h"

//����� ��ġ ������ ���ڷ� �޴� �Լ� ��ü�� �߻�ȭ
struct IDoEHMember
{
	virtual void operator()(EHMember *ehmember) = 0;
};
