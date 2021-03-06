// ChildSocket.cpp: 구현 파일
//

#include "stdafx.h"
#include "GUI messenger.h"
#include "ChildSocket.h"


// ChildSocket

ChildSocket::ChildSocket()
{
}

ChildSocket::~ChildSocket()
{
}

void ChildSocket::SetListenSocket(CAsyncSocket *pSocket)
{
	m_pListenSocket = pSocket;
}
// ChildSocket 멤버 함수

#include "ListeSocket.h"
void ChildSocket::OnClose(int nErrorCode)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	ListeSocket *pServerSocket = (ListeSocket*)m_pListenSocket;
	pServerSocket->CloseClientSocket(this);

	CSocket::OnClose(nErrorCode);
}
#include "MainInterface.h"
#include "ChildSocket.h"
#include "ListeSocket.h"
#include "GUI messengerDlg.h"

void ChildSocket::OnReceive(int nErrorCode)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	CString tmp = _T("");
	CString IPAdress = _T("");
	UINT uportNumber = 0;
	char szBuffer[1024];
	::ZeroMemory(szBuffer, 1024);
	GetPeerName(IPAdress, uportNumber);
	int len;

	if ((len = Receive(szBuffer, 1024)) > 0)
	{
		CGUImessengerDlg* pMain = (CGUImessengerDlg*)AfxGetMainWnd();
		/*tmp.Format(L"(%s : %s)", IPAdress, szBuffer);
		int location;
		location = pMain->m_List.GetItemCount();
		pMain->m_List.InsertItem(location, tmp);*/
		//출력
		ListeSocket *pServerSocket = (ListeSocket*)m_pListenSocket;
		pServerSocket->BroadCast(szBuffer, len);
	}
	CSocket::OnReceive(nErrorCode);
}
