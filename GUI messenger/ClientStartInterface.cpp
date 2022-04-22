// ClientStartInterface.cpp: 구현 파일
//

#include "stdafx.h"
#include "GUI messenger.h"
#include "ClientStartInterface.h"
#include "afxdialogex.h"


// ClientStartInterface 대화 상자

IMPLEMENT_DYNAMIC(ClientStartInterface, CDialogEx)

ClientStartInterface::ClientStartInterface(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SERVVER, pParent)
{

}

ClientStartInterface::~ClientStartInterface()
{
}

void ClientStartInterface::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(ClientStartInterface, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON2, &ClientStartInterface::OnBnClickedButton2)
END_MESSAGE_MAP()


// ClientStartInterface 메시지 처리기


void ClientStartInterface::OnBnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
