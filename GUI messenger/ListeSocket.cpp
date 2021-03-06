// ListeSocket.cpp: 구현 파일
//

#include "stdafx.h"
#include "GUI messenger.h"
#include "ListeSocket.h"


// ListeSocket

ListeSocket::ListeSocket()
{
	//main_interface =(MainInterface*)main;
}

ListeSocket::~ListeSocket()
{
}


// ListeSocket 멤버 함수

#include "ChildSocket.h"
#include "GUI messengerDlg.h"
void ListeSocket::OnAccept(int nErrorCode)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	ChildSocket *pChild = new ChildSocket;
	BOOL check = Accept(*pChild);
	if (check == FALSE)
	{
		delete pChild;
		AfxMessageBox(L"접속실패");
		return;
	}
	pChild->SetListenSocket(this);
	m_ptrChildSocketList.AddTail(pChild);
	int location;
	//mainInterface에 출력 ->애초에 maininterface에서 생성하도록 함
	CGUImessengerDlg* pMain = (CGUImessengerDlg*)AfxGetMainWnd();
	location = pMain->m_List.GetItemCount();
	pMain->m_List.InsertItem(location+1,_T("누군가가 접속함"));
	//pMain->m_List.SetCur
	CSocket::OnAccept(nErrorCode);
}
void ListeSocket::CloseClientSocket(CSocket *pChild)
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
void ListeSocket::BroadCast(char *pszBuffer, int len)
{
	POSITION pos;
	pos = m_ptrChildSocketList.GetHeadPosition();
	ChildSocket *pChild = NULL;

	while (pos != NULL)
	{
		pChild = (ChildSocket*)m_ptrChildSocketList.GetNext(pos);
		if (pChild != NULL)
		{
			pChild->Send(pszBuffer, len * 2);
		}
	}
}
