// ClientStart.cpp: 구현 파일
//

#include "stdafx.h"
#include "GUI messenger.h"
#include "ClientStart.h"
#include "afxdialogex.h"


// ClientStart 대화 상자

IMPLEMENT_DYNAMIC(ClientStart, CDialogEx)

ClientStart::ClientStart(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CLIENT, pParent)
{

}

ClientStart::~ClientStart()
{
}

void ClientStart::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT2, server_ip_addr);
	DDX_Control(pDX, IDC_EDIT3, server_port);
	DDX_Control(pDX, IDC_EDIT1, nick_name);
	DDX_Control(pDX, IDC_EDIT5, ip_addr);
	DDX_Control(pDX, IDC_EDIT4, port);
}


BEGIN_MESSAGE_MAP(ClientStart, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &ClientStart::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &ClientStart::OnBnClickedButton2)
END_MESSAGE_MAP()


// ClientStart 메시지 처리기


void ClientStart::OnBnClickedButton1()
{
	//여기서 그냥 데이터로 옮기는걸로함
	//실제 소켓 생성은 dlg에서
	CDialogEx::OnOK();
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

#include "GUI messengerDlg.h"
void ClientStart::OnBnClickedButton2()
{
	CGUImessengerDlg* parent = (CGUImessengerDlg*)AfxGetMainWnd();
	parent->finished_flag = 1;
	CString temp;
	ip_addr.GetWindowTextW(temp);
	parent->ip_addr = temp;
	nick_name.GetWindowTextW(temp);
	parent->nick_name = temp;
	port.GetWindowTextW(temp);
	parent->port = temp;
	server_ip_addr.GetWindowTextW(temp);
	parent->server_ip_addr = temp;
	server_port.GetWindowTextW(temp);
	parent->server_port_num = GetDlgItemInt(IDC_EDIT3);
	parent->server_port = temp;
//	parent->connect_server();
	CDialogEx::OnOK();
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
