
// GUI messengerDlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "GUI messenger.h"
#include "GUI messengerDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CGUImessengerDlg 대화 상자



CGUImessengerDlg::CGUImessengerDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_GUIMESSENGER_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CGUImessengerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_List);
	DDX_Control(pDX, IDC_EDIT1, InputText);
}

BEGIN_MESSAGE_MAP(CGUImessengerDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BUTTON1, &CGUImessengerDlg::OnBnClickedButton1)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, &CGUImessengerDlg::OnLvnItemchangedList1)
	ON_BN_CLICKED(IDC_BUTTON2, &CGUImessengerDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CGUImessengerDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CGUImessengerDlg::OnBnClickedButton4)
END_MESSAGE_MAP()


// CGUImessengerDlg 메시지 처리기

BOOL CGUImessengerDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	finished_flag = -1;
	flag = -1;
	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	CRect rect;
	CBitmap bm;
	CString temp;
	static CImageList Emoji_List;
	TCHAR path[_MAX_PATH];
	GetModuleFileName(NULL, path, sizeof(path));
	strPath = path;
	int i = strPath.ReverseFind('\\');
	strPath = strPath.Left(i);
	CString pImagename = L"\\bitmap1.bmp";
	temp = strPath + pImagename;
	CT2CA pszConvertedAnsiString(temp);
	i = strPath.ReverseFind('\\');
	strPath = strPath.Left(i);
	//AfxMessageBox(temp);
	 //불러올 파일 이름
	HBITMAP hBMP = (HBITMAP)::LoadImage(NULL, temp, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	bm.Attach(hBMP);
	m_List.GetClientRect(&rect);
	//bm.LoadBitmapW(IDB_BITMAP1);
	Emoji_List.Create(48, 48, ILC_COLORDDB|ILC_MASK, 48,18);
	Emoji_List.Add(&bm, RGB(0, 0, 0));
	//Emoji_List.Create(IDB_BITMAP1, 48, 1, RGB(0, 0, 0));
	m_List.SetImageList(&Emoji_List, LVSIL_NORMAL);
	m_List.InsertColumn(0, L"메시지", LVCFMT_LEFT, rect.Width());
	//m_List.InsertColumn(0, L"이모티콘", LVCFMT_LEFT, 100);
	m_List.InsertItem(0, L"시발",1);


/*	CPaintDC dc(this);

	BITMAP bmpinfo;
	CDC MemDC;

	MemDC.CreateCompatibleDC(&dc);

	bm.GetBitmap(&bmpinfo);

	CBitmap *pOldBmp = MemDC.SelectObject(&bm);

	dc.BitBlt(0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, &MemDC, 0, 0, SRCCOPY);

	MemDC.SelectObject(pOldBmp);*/











	//Emoji_List.Create(48, 48, ILC_COLOR8 | ILC_MASK, 8, 1);
	//bm.LoadBitmapW(IDB_BITMAP1);
	//Emoji_List.Add(&bm, RGB(0, 0, 0));

	//m_List.InsertColumn(1, L"메시지", LVCFMT_LEFT, rect.Width() - 100);
	m_select = new InitSelect();
	m_select->DoModal();
	if (flag == 0)
	{
		load_server_interface();
		if (finished_flag == 1)
		{
			/*MessageBox(server_ip_addr);
			MessageBox(server_port);
			MessageBox(nick_name);*/
			//m_interface = new MainInterface();
			//이부분에 소켓설정
			//m_interface->DoModal();
			int temp_port =-1;
			
			//server_port.Format(L"%s", temp_p);
			//temp_p = LPSTR(LPCTSTR(server_port));
			//memcpy(temp_p, (char*)(LPCTSTR)server_port, 1024);
			temp_port  = server_port_num;
			//printf("%d", temp_port);
//			MessageBox(temp_port);
			if (temp_port == -1)
			{
				//에러처리는 다음에
			}
			//이안의 함수/ 변수 전달로도 가능
			m_pListenSocket = new ListeSocket;
			if (m_pListenSocket->Create(temp_port, SOCK_STREAM))
			{
				if (m_pListenSocket->Listen())
				{

				}
				else
				{
					MessageBox(L"실패");
				}
			}
			else
			{
				MessageBox(L"실패");
			}
			connect_server();
		}
		//서버 소켓 작업
	}
	else if (flag == 1)
	{
		load_client_interface();
		if (finished_flag == 1)
		{
			/*MessageBox(server_ip_addr);
			MessageBox(server_port);
			MessageBox(nick_name);
			MessageBox(ip_addr);
			MessageBox(port);*/
		//	m_interface = new MainInterface();
			//이부분에 소켓설정
			//해야될것 소켓클래스 정의 완료
			//다이얼로그 윈도우에 출력
			//m_interface->DoModal();
			connect_server();
		}
		//클라이언트 소켓작업
	}
	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CGUImessengerDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CGUImessengerDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CGUImessengerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CGUImessengerDlg::load_client_interface()
{
	MessageBox(L"클라이언트");
	m_client = new ClientStart();
	m_client->DoModal();
}
void CGUImessengerDlg::load_server_interface()
{
	MessageBox(L"서버");
	m_server = new ServerStart();
	m_server->DoModal();
}
#include "ChildSocket.h"
void CGUImessengerDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	if (flag == 0)
	{
		POSITION pos;
		pos = m_pListenSocket->m_ptrChildSocketList.GetHeadPosition();
		ChildSocket* pChild = NULL;
		while (pos != NULL)
		{
			pChild = (ChildSocket*)m_pListenSocket->m_ptrChildSocketList.GetNext(pos);
			if (pChild != NULL)
			{
				pChild->ShutDown();
				pChild->Close();
				delete pChild;
			}
		}
	}
	m_pListenSocket->ShutDown();
	m_pListenSocket->Close();
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
}
void CGUImessengerDlg::connect_server()
{
	m_Client.Create();
	int temp_port = server_port_num;
	m_Client.Connect(server_ip_addr, temp_port);
}

void CGUImessengerDlg::OnBnClickedButton1()
{
	UpdateData(true);
	CString buf;
	InputText.GetWindowTextW(buf);
	InputText.SetSel(0, -1);
	InputText.Clear();
	buf.Insert(0, nick_name);
	buf.Insert(nick_name.GetLength() , L" : ");
	m_Client.Send(LPCTSTR(buf), buf.GetLength() * 2);

	UpdateData(false);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CGUImessengerDlg::OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	*pResult = 0;
}


void CGUImessengerDlg::OnBnClickedButton2()
{
	UpdateData(true);
	CString buf;
	//buf.Insert(0, nick_name);
	buf.Insert(0, L"/emoji");
	m_Client.Send(LPCTSTR(buf), buf.GetLength() * 2);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CGUImessengerDlg::OnBnClickedButton3()
{
	m_List.DeleteAllItems();
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CGUImessengerDlg::OnBnClickedButton4()
{
	CString temp  = L"\\MFCGUI.exe";
	strPath += temp;
	//AfxMessageBox(strPath);
	CT2CA pszConvertedAnsiString(strPath);
	WinExec(pszConvertedAnsiString, SW_SHOW);
	//ShellExecute(NULL, L"open", L" C:\\Users\\ssmin\\Desktop\\GUI messenger\\MFCGUI.exe", NULL, NULL, SW_SHOW);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
