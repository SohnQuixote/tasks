
// GUI messengerDlg.h: 헤더 파일
//

#pragma once

#define HOST
#define CLIENT
// CGUImessengerDlg 대화 상자
#include "InitSelect.h"
#include "ClientStart.h"
#include "ServerStart.h"
#include "MainInterface.h"
#include "ListeSocket.h"
#include "ClientSocket.h"
class CGUImessengerDlg : public CDialogEx
{
// 생성입니다.
public:
	CGUImessengerDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
public :
	InitSelect *m_select;
	int flag;
	int finished_flag;//스타트 부분에서 완성되면 소켓 만들고 ok함
	int setting_flag;
	ClientStart *m_client;
	ServerStart *m_server;
	MainInterface *m_interface;
	CString server_ip_addr;
	CString server_port;
	int server_port_num;
	CString nick_name;
	CString ip_addr;
	CString port;
	int port_num;
	ListeSocket *m_pListenSocket;
	ClientSocket m_Client;
	CString strPath;
	char *temp_p;
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_GUIMESSENGER_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
	void load_client_interface();
	void load_server_interface();
	
public:
	CListCtrl m_List;
	afx_msg void OnDestroy();
	void connect_server();
	afx_msg void OnBnClickedButton1();
	CEdit InputText;
	afx_msg void OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
};
