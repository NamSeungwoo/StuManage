#include "App.h"

App App::app;

App::App()
{

}

App::~App()
{

}
App* App::GetInstance()
{
	return &app;
}

// EHWorld 단일체를 쉽게 접근하게 하기 위해 래핑한 메서드
EHWorld* App::GetEHWorld()
{
	return EHWorld::GetEHWorld();
}

void App::Run()
{
	keydata key = NO_DEFINED;

	while ((key = SelectMenu()) != ESC)
	{
		switch (key)
		{
		case F1: AddGroup(); break; // 그룹 추가
		case F2: AddMember(); break; // 멤버 추가
		case F3: SearchMember(); break; // 멤버 검색
		case F4: ViewGroup(); break; // 특정 그룹 정보 보기
		case F5: ViewGroupList(); break; // 전체 그룹 정보 보기
		case F6: ViewMemberList(); break; // 전체 멤버 보기
		default: cout << "잘못된 메뉴를 선택하였습니다." << endl;
		}

		cout << "아무키나 누르세요." << endl;
		ehglobal::getkey();
	}
}

keydata App::SelectMenu()
{
	ehglobal::clrscr();

	cout << "EH World 메뉴" << endl;
	cout << "[F1]: 그룹 추가" << endl;
	cout << "[F2]: 멤버 추가" << endl;
	cout << "[F3]: 멤버 검색" << endl;
	cout << "[F4]: 특정 그룹 보기" << endl;
	cout << "[F5]: 전체 그룹 보기" << endl;
	cout << "[F6]: 전체 멤버 보기" << endl;
	cout << "[ESC]: 프로그램 종료" << endl;
	cout << "메뉴를 선택하세요." << endl;

	return ehglobal::getkey();
}

void App::AddGroup()
{
	EHWorld *ehworld = GetEHWorld(); // 단일체를 얻어옴

	int gcnt = ehworld->GetGroupCount();
	cout << gcnt + 1 << "번째 그룹의 이름을 입력하세요." << endl;
	string gname = "";
	gname = ehglobal::getstr();

	// gname의 그룹 생성을 요청
	if (ehworld->MakeEHGroup(gname))
	{
		cout << gname << "그룹을 생성하였습니다." << endl;
	}
	else
	{
		cout << gname << "그룹을 생성하지 못하였습니다." << endl;
	}
}

void App::AddMember()
{
	cout << "추가할 멤버 아이디를 입력하세요." << endl;
	string id = ehglobal::getstr();

	EHWorld *ehworld = GetEHWorld(); //EHWorld 단일체를 얻어옴

	if (ehworld->ExistMember(id)) // 보관된 멤버중에 id가 일치하는 멤버가 존재할 때
	{
		cout << id << "는 이미 존재합니다." << endl;
		return;
	}

	//보관된 멤버 중에 id가 일치하는 멤버가 존재하지 않을 때
	cout << "멤버 이름을 입력하세요." << endl;
	string mname = ehglobal::getstr();

	//멤버가 속할 그룹을 선택함
	ViewAllGroupName();
	cout << "멤버가 속할 그룹 이름을 입력하세요." << endl;
	string gname = ehglobal::getstr();

	if (ehworld->AddMember(id, mname, gname))
	{
		cout << "추가하였습니다." << endl;
	}
	else
	{
		cout << "그룹이 존재하지 않아 정상적으로 추가하지 못하였습니다." << endl;
	}
}

void App::ViewAllGroupName()
{
	EHWorld *ehworld = GetEHWorld();
	EHViewGroupName evgn;
	ehworld->ListGroup(evgn);
}

void App::SearchMember()
{
	keydata key = NO_DEFINED;

	while ((key = SelectSearchMenu()) != ESC)
	{
		switch (key)
		{
		case F1: SearchById(); break; // id로 멤버 검색
		case F2: SearchAtGroup(); break; // 그룹을 선택 후에 멤버 검색
		default: cout << "잘못된 메뉴를 선택하였습니다." << endl;
		}
		cout << "아무키나 누르세요." << endl;
		ehglobal::getkey();
	}
}

keydata App::SelectSearchMenu()
{
	ehglobal::clrscr();
	cout << "멤버 검색 메뉴" << endl;
	cout << "[F1]: 아이디로 검색" << endl;
	cout << "[F2]: 그룹에서 선택" << endl;
	cout << "메뉴를 선택하세요." << endl;
	return ehglobal::getkey();
}

void App::SearchById()
{
	cout << "검색할 멤버 id를 입력하세요." << endl;
	string id = ehglobal::getstr();

	EHWorld *ehworld = GetEHWorld();

	EHMember *ehmember = ehworld->FindMember(id); // id로 멤버 찾기
	ViewMember(ehmember);

}

void App::ViewMember(EHMember *ehmember)
{
	if (ehmember == 0)
	{
		cout << "존재하지 않는 id입니다." << endl;
	}
	else
	{
		int seq = ehmember->GetSeq();
		string id = ehmember->GetId();
		string name = ehmember->GetName();
		cout << "일련번호:" << seq << " 아이디:" << id << " 이름" << name << endl;
	}
}

void App::SearchAtGroup()
{
	ViewAllGroupName(); // 전체 그룹 일므 보여주기

	cout << "먼저, 멤버가 속한 그룹 이름을 입력하세요." << endl;
	string gname = ehglobal::getstr();

	EHWorld *ehworld = GetEHWorld();

	if (!ehworld->ExistGroup(gname))
	{
		cout << "존재하지 않는 그룹입니다." << endl;
		return;
	}

	cout << "검색할 멤버 id를 입력하세요." << endl;
	string id = ehglobal::getstr();

	EHMember *ehmember = ehworld->FindMember(id, gname);
	ViewMember(ehmember);
}

void App::ViewGroup()
{
	ViewAllGroupName();

	cout << "확인하고자 하는 그룹 이름을 입력하세요." << endl;
	string gname = ehglobal::getstr();
	EHWorld *ehworld = GetEHWorld();

	if (!ehworld->ExistGroup(gname))
	{
		cout << "존재하지 않는 그룹입니다." << endl;
		return;
	}

	EHViewMember evm; //멤버의 정보를 보여주는 함수 개체 선언

	//함수 개체를 이용하여 gname의 그룹 내의 모든 멤버 정보 보기
	ehworld->ViewGroupData(gname, evm);
}

void App::ViewGroupList()
{
	EHWorld *ehworld = GetEHWorld();
	EHViewGroupName evgn; 
	EHViewMember evm;
	ehworld->ViewAll(evgn, evm);
}

void App::ViewMemberList()
{
	EHWorld *ehworld = GetEHWorld();
	EHViewMember evm;
	ehworld->DoItAllMember(evm);
}

