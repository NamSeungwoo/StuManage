#pragma once
#include "EHWorld.h"
#include "EHViewMember.h"
#include "EHViewGroupName.h"

// �����ڸ� App�� �����ϰ� cpp���� ������ ������ �ܺ����� ���� �߻�

class App
{
	static App app;
public:
	static App* GetInstance(); // ����ü�� ��ȯ�ϴ� ���� �޼���
	void Run();
private: 
	EHWorld* GetEHWorld();
	keydata SelectMenu();
	void AddGroup();
	void AddMember();
	void SearchMember();
	void ViewGroup();
	void ViewGroupList();
	void ViewMemberList();
	void ViewAllGroupName();
	keydata SelectSearchMenu();
	void SearchById();
	void SearchAtGroup();
	void ViewMember(EHMember *ehmember);
	
	App(void);
	~App(void);
};