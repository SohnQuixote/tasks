#pragma once


// MainInterface 대화 상자
#include "ListeSocket.h"
class MainInterface : public CDialogEx
{
	DECLARE_DYNAMIC(MainInterface)

public:
	MainInterface(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~MainInterface();
//	ListeSocket* m_pListenSocket;
// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MAININTERFACE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton3();
};
