#pragma once
#include "EHGroup.h"
// �׷��� ��ġ ������ ���ڷ� �޴� �Լ� ��ü�� �߻�ȭ

struct IDoEHGroup
{
	virtual void operator()(EHGroup *ehgroup) = 0;
};