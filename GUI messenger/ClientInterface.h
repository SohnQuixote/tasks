#pragma once


// ClientInterface 대화 상자
#include "CMainInterface.h"
class ClientInterface : public CDialogEx
{
	DECLARE_DYNAMIC(ClientInterface)

public:
	ClientInterface(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~ClientInterface();
	CMainInterface *m_interface;
// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CLIENT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton1();
};
