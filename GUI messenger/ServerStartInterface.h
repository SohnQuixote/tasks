#pragma once


// ServerStartInterface 대화 상자

class ServerStartInterface : public CDialogEx
{
	DECLARE_DYNAMIC(ServerStartInterface)

public:
	ServerStartInterface(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~ServerStartInterface();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SERVVER };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
};
