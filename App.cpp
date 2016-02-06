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

// EHWorld ����ü�� ���� �����ϰ� �ϱ� ���� ������ �޼���
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
		case F1: AddGroup(); break; // �׷� �߰�
		case F2: AddMember(); break; // ��� �߰�
		case F3: SearchMember(); break; // ��� �˻�
		case F4: ViewGroup(); break; // Ư�� �׷� ���� ����
		case F5: ViewGroupList(); break; // ��ü �׷� ���� ����
		case F6: ViewMemberList(); break; // ��ü ��� ����
		default: cout << "�߸��� �޴��� �����Ͽ����ϴ�." << endl;
		}

		cout << "�ƹ�Ű�� ��������." << endl;
		ehglobal::getkey();
	}
}

keydata App::SelectMenu()
{
	ehglobal::clrscr();

	cout << "EH World �޴�" << endl;
	cout << "[F1]: �׷� �߰�" << endl;
	cout << "[F2]: ��� �߰�" << endl;
	cout << "[F3]: ��� �˻�" << endl;
	cout << "[F4]: Ư�� �׷� ����" << endl;
	cout << "[F5]: ��ü �׷� ����" << endl;
	cout << "[F6]: ��ü ��� ����" << endl;
	cout << "[ESC]: ���α׷� ����" << endl;
	cout << "�޴��� �����ϼ���." << endl;

	return ehglobal::getkey();
}

void App::AddGroup()
{
	EHWorld *ehworld = GetEHWorld(); // ����ü�� ����

	int gcnt = ehworld->GetGroupCount();
	cout << gcnt + 1 << "��° �׷��� �̸��� �Է��ϼ���." << endl;
	string gname = "";
	gname = ehglobal::getstr();

	// gname�� �׷� ������ ��û
	if (ehworld->MakeEHGroup(gname))
	{
		cout << gname << "�׷��� �����Ͽ����ϴ�." << endl;
	}
	else
	{
		cout << gname << "�׷��� �������� ���Ͽ����ϴ�." << endl;
	}
}

void App::AddMember()
{
	cout << "�߰��� ��� ���̵� �Է��ϼ���." << endl;
	string id = ehglobal::getstr();

	EHWorld *ehworld = GetEHWorld(); //EHWorld ����ü�� ����

	if (ehworld->ExistMember(id)) // ������ ����߿� id�� ��ġ�ϴ� ����� ������ ��
	{
		cout << id << "�� �̹� �����մϴ�." << endl;
		return;
	}

	//������ ��� �߿� id�� ��ġ�ϴ� ����� �������� ���� ��
	cout << "��� �̸��� �Է��ϼ���." << endl;
	string mname = ehglobal::getstr();

	//����� ���� �׷��� ������
	ViewAllGroupName();
	cout << "����� ���� �׷� �̸��� �Է��ϼ���." << endl;
	string gname = ehglobal::getstr();

	if (ehworld->AddMember(id, mname, gname))
	{
		cout << "�߰��Ͽ����ϴ�." << endl;
	}
	else
	{
		cout << "�׷��� �������� �ʾ� ���������� �߰����� ���Ͽ����ϴ�." << endl;
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
		case F1: SearchById(); break; // id�� ��� �˻�
		case F2: SearchAtGroup(); break; // �׷��� ���� �Ŀ� ��� �˻�
		default: cout << "�߸��� �޴��� �����Ͽ����ϴ�." << endl;
		}
		cout << "�ƹ�Ű�� ��������." << endl;
		ehglobal::getkey();
	}
}

keydata App::SelectSearchMenu()
{
	ehglobal::clrscr();
	cout << "��� �˻� �޴�" << endl;
	cout << "[F1]: ���̵�� �˻�" << endl;
	cout << "[F2]: �׷쿡�� ����" << endl;
	cout << "�޴��� �����ϼ���." << endl;
	return ehglobal::getkey();
}

void App::SearchById()
{
	cout << "�˻��� ��� id�� �Է��ϼ���." << endl;
	string id = ehglobal::getstr();

	EHWorld *ehworld = GetEHWorld();

	EHMember *ehmember = ehworld->FindMember(id); // id�� ��� ã��
	ViewMember(ehmember);

}

void App::ViewMember(EHMember *ehmember)
{
	if (ehmember == 0)
	{
		cout << "�������� �ʴ� id�Դϴ�." << endl;
	}
	else
	{
		int seq = ehmember->GetSeq();
		string id = ehmember->GetId();
		string name = ehmember->GetName();
		cout << "�Ϸù�ȣ:" << seq << " ���̵�:" << id << " �̸�" << name << endl;
	}
}

void App::SearchAtGroup()
{
	ViewAllGroupName(); // ��ü �׷� �Ϲ� �����ֱ�

	cout << "����, ����� ���� �׷� �̸��� �Է��ϼ���." << endl;
	string gname = ehglobal::getstr();

	EHWorld *ehworld = GetEHWorld();

	if (!ehworld->ExistGroup(gname))
	{
		cout << "�������� �ʴ� �׷��Դϴ�." << endl;
		return;
	}

	cout << "�˻��� ��� id�� �Է��ϼ���." << endl;
	string id = ehglobal::getstr();

	EHMember *ehmember = ehworld->FindMember(id, gname);
	ViewMember(ehmember);
}

void App::ViewGroup()
{
	ViewAllGroupName();

	cout << "Ȯ���ϰ��� �ϴ� �׷� �̸��� �Է��ϼ���." << endl;
	string gname = ehglobal::getstr();
	EHWorld *ehworld = GetEHWorld();

	if (!ehworld->ExistGroup(gname))
	{
		cout << "�������� �ʴ� �׷��Դϴ�." << endl;
		return;
	}

	EHViewMember evm; //����� ������ �����ִ� �Լ� ��ü ����

	//�Լ� ��ü�� �̿��Ͽ� gname�� �׷� ���� ��� ��� ���� ����
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

