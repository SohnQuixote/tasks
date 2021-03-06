// ServerInterface.cpp: 구현 파일
//

#include "stdafx.h"
#include "GUI messenger.h"
#include "ServerInterface.h"
#include "afxdialogex.h"


// ServerInterface 대화 상자

IMPLEMENT_DYNAMIC(ServerInterface, CDialogEx)

ServerInterface::ServerInterface(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SERVVER, pParent)
{

}

ServerInterface::~ServerInterface()
{
}

void ServerInterface::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(ServerInterface, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON2, &ServerInterface::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &ServerInterface::OnBnClickedButton1)
END_MESSAGE_MAP()


// ServerInterface 메시지 처리기


void ServerInterface::OnBnClickedButton2()
{
	ServerInterface::OnClose();
	this->DestroyWindow();
	delete(this);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void ServerInterface::OnBnClickedButton1()
{
	m_interface = new CMainInterface();
	m_interface->DoModal();
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
