#pragma once
#include "EHGlobal.h"
class EHMember
{
	int seq;
	string id;
	string name;
public:
	EHMember(int seq, string id, string name);
	~EHMember(void);
	int GetSeq() const;
	string GetId() const;
	string GetName() const;
};