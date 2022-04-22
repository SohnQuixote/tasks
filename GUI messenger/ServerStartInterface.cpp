// ServerStartInterface.cpp: 구현 파일
//

#include "stdafx.h"
#include "GUI messenger.h"
#include "ServerStartInterface.h"
#include "afxdialogex.h"


// ServerStartInterface 대화 상자

IMPLEMENT_DYNAMIC(ServerStartInterface, CDialogEx)

ServerStartInterface::ServerStartInterface(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SERVVER, pParent)
{

}

ServerStartInterface::~ServerStartInterface()
{
}

void ServerStartInterface::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(ServerStartInterface, CDialogEx)
END_MESSAGE_MAP()


// ServerStartInterface 메시지 처리기
