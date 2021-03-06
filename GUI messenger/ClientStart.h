#pragma once


// ClientStart 대화 상자

class ClientStart : public CDialogEx
{
	DECLARE_DYNAMIC(ClientStart)

public:
	ClientStart(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~ClientStart();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CLIENT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	CEdit server_ip_addr;
	CEdit server_port;
	CEdit nick_name;
	CEdit ip_addr;
	CEdit port;
};
