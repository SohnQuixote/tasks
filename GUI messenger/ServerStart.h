#pragma once


// ServerStart 대화 상자

class ServerStart : public CDialogEx
{
	DECLARE_DYNAMIC(ServerStart)

public:
	ServerStart(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~ServerStart();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SERVER };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	CEdit ipaddr;
	CEdit port_num;
	CEdit nick_name;
};
