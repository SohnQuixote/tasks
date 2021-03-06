// ClientSocket.cpp: 구현 파일
//

#include "stdafx.h"
#include "GUI messenger.h"
#include "ClientSocket.h"


// ClientSocket

ClientSocket::ClientSocket()
{
}

ClientSocket::~ClientSocket()
{
}


// ClientSocket 멤버 함수

#include "GUI messengerDlg.h"
void ClientSocket::OnClose(int nErrorCode)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	ShutDown();
	Close();


	CSocket::OnClose(nErrorCode);
	AfxMessageBox(L"접속 종료합니다.");
}


void ClientSocket::OnReceive(int nErrorCode)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	char szBuffer[1024];
	::RtlZeroMemory(szBuffer, 1024);
	if (Receive(szBuffer, 1024) > 0)
	{
		CGUImessengerDlg *pMain = (CGUImessengerDlg *)AfxGetMainWnd();
		int location;
		location = pMain->m_List.GetItemCount();
		if (!strcmp(szBuffer, "/emoji"))
		{
			pMain->m_List.InsertItem(location+1, L"", 0);
		}
		else
		{
			//pMain->m_List.InsertItem(LVIF_TEXT | LVIF_IMAGE, 7, "", 0, 0, 1, 0L);
			pMain->m_List.InsertItem(location + 1, LPCTSTR(szBuffer),0);
			//pMain->m_List.InsertItem(location + 1, L"d", 0);
			//pMain->m_List.SetItemState(location + 1, LVIS_SELECTED|LVIS_FOCUSED, LVIS_SELECTED|LVIS_FOCUSED);
		
		/*	LVITEM li;
			li.mask = LVIF_TEXT | LVIF_IMAGE | LVIF_STATE;
			li.iItem = location + 1;
			li.iSubItem = 0;
			li.iImage = 0;
			li.stateMask = LVIS_STATEIMAGEMASK;
			li.state = INDEXTOSTATEIMAGEMASK(1);
			li.pszText = L"시발";
			pMain->m_List.InsertItem(&li);*/
			
			
			
			CSize sz(0, 10 * location + 1);
			pMain->m_List.Scroll(sz);
			
		}
	}
	CSocket::OnReceive(nErrorCode);
}
