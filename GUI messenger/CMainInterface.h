#pragma once


// CMainInterface 대화 상자

class CMainInterface : public CDialogEx
{
	DECLARE_DYNAMIC(CMainInterface)

public:
	CMainInterface(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CMainInterface();

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
