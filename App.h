#pragma once
#include "EHWorld.h"
#include "EHViewMember.h"
#include "EHViewGroupName.h"

// 생성자를 App에 선언하고 cpp에서 만들지 않으면 외부참조 오류 발생

class App
{
	static App app;
public:
	static App* GetInstance(); // 단일체를 반환하는 정적 메서드
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