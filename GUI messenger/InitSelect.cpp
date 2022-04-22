// InitSelect.cpp: 구현 파일
//

#include "stdafx.h"
#include "GUI messenger.h"
#include "InitSelect.h"
#include "afxdialogex.h"


// InitSelect 대화 상자

IMPLEMENT_DYNAMIC(InitSelect, CDialogEx)

InitSelect::InitSelect(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_INIT, pParent)
{

}

InitSelect::~InitSelect()
{
}

void InitSelect::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(InitSelect, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &InitSelect::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_RADIO1, &InitSelect::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &InitSelect::OnBnClickedRadio2)
END_MESSAGE_MAP()


// InitSelect 메시지 처리기

#include "GUI messengerDlg.h"
void InitSelect::OnBnClickedButton1()
{
	CGUImessengerDlg* parent = (CGUImessengerDlg*)AfxGetMainWnd();
	parent->flag = flag;
	//에러처리
	CDialogEx::OnOK();
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void InitSelect::OnBnClickedRadio1()
{
	flag = 0;
	return;
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void InitSelect::OnBnClickedRadio2()
{
	flag = 1;
	return;
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
