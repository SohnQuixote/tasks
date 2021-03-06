// CListenSocket.cpp: 구현 파일
//

#include "stdafx.h"
#include "GUI messenger.h"
#include "CListenSocket.h"


// CListenSocket

CListenSocket::CListenSocket()
{
}

CListenSocket::~CListenSocket()
{
}


// CListenSocket 멤버 함수

#include "CServerSocket.h"
#include "CMainInterface.h"
#include "GUI messengerDlg.h"
void CListenSocket::OnAccept(int nErrorCode)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	CServerSocket *pChild;
	pChild = new CServerSocket;

	BOOL check = Accept(*pChild);

	if (check == FALSE)
	{
		delete pChild;
		return;
	}
	pChild->SetListenSocket(this);
	m_ptrChildSocketList.AddTail(pChild);
	CGUImessengerDlg * parrent = (CGUImessengerDlg*)AfxGetMainWnd();
	//CMainInterface pMain = (CMainInterface)parrent->m_interface;
	//리스트에 관련된 함수
	CAsyncSocket::OnAccept(nErrorCode);
}
void CListenSocket::CloseClientSocket(CSocket* pChild)
{
	POSITION pos;
	pos = m_ptrChildSocketList.Find(pChild);
	if (pos != NULL)
	{
		if (pChild != NULL)
		{
			pChild->ShutDown();
			pChild->Close();
		}
		m_ptrChildSocketList.RemoveAt(pos);
		delete pChild;


	}
}
void CListenSocket::BroadCast(char* buf, int len)
{
	POSITION pos;
	pos = m_ptrChildSocketList.GetHeadPosition();
	CServerSocket* pChild = NULL;
	while (pos != NULL)
	{

		pChild = (CServerSocket*)m_ptrChildSocketList.GetNext(pos);
		if (pChild != NULL)
		{

			pChild->Send(buf, len * 2);//왜 2*len??
		}

	}

}


void CListenSocket::OnClose(int nErrorCode)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	CAsyncSocket::OnClose(nErrorCode);
}
