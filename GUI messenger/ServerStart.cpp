// ServerStart.cpp: 구현 파일
//

#include "stdafx.h"
#include "GUI messenger.h"
#include "ServerStart.h"
#include "afxdialogex.h"


// ServerStart 대화 상자

IMPLEMENT_DYNAMIC(ServerStart, CDialogEx)

ServerStart::ServerStart(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SERVER, pParent)
{

}

ServerStart::~ServerStart()
{
}

void ServerStart::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT2, ipaddr);
	DDX_Control(pDX, IDC_EDIT3, port_num);
	DDX_Control(pDX, IDC_EDIT1, nick_name);
}


BEGIN_MESSAGE_MAP(ServerStart, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &ServerStart::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &ServerStart::OnBnClickedButton2)
END_MESSAGE_MAP()


// ServerStart 메시지 처리기


void ServerStart::OnBnClickedButton1()
{
	CDialogEx::OnOK();
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

#include "GUI messengerDlg.h"
void ServerStart::OnBnClickedButton2()
{
	CString temp;
	CGUImessengerDlg* parent = (CGUImessengerDlg*)AfxGetMainWnd();
	parent->finished_flag = 1;
	ipaddr.GetWindowTextW(temp);
	parent->server_ip_addr = temp;
	port_num.GetWindowTextW(temp);
	parent->server_port_num = GetDlgItemInt(IDC_EDIT3);
	parent->server_port = temp;
	nick_name.GetWindowTextW(temp);
	parent->nick_name = temp;

	CDialogEx::OnOK();
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
