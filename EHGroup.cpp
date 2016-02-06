#include "EHGroup.h"

EHGroup::EHGroup(string gname)
{
	this->gname = gname;
}

string EHGroup::GetName() const
{
	return gname;
}

void EHGroup::AddMember(EHMember* ehmember)
{
	mv.push_back(ehmember);
}

EHMember *EHGroup::FindMember(string id)
{
	MVIter seek = mv.begin();
	MVIter end = mv.end();
	EHMember *ehmember = 0;

	for (; seek != end; ++seek)
	{
		ehmember = *seek;
		if (ehmember->GetId() == id)
		{
			return ehmember;
		}
	}
	return 0;
}

void EHGroup::DoWithMember(IDoEHMember &idem)
{
	MVIter seek = mv.begin();
	MVIter end = mv.end();
	EHMember *ehmember = 0;

	for (; seek != end; ++seek)
	{
		ehmember = *seek;
		idem(ehmember);
	}
}