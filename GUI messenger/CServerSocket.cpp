// CServerSocket.cpp: 구현 파일
//

#include "stdafx.h"
#include "GUI messenger.h"
#include "CServerSocket.h"
#include "CClientSocket.h"

// CServerSocket

CServerSocket::CServerSocket()
{
}

CServerSocket::~CServerSocket()
{
}
void CServerSocket::SetListenSocket(CAsyncSocket* pSocket)
{

	m_pListenSocket = pSocket;
}

// CServerSocket 멤버 함수

#include "CListenSocket.h"
void CServerSocket::OnClose(int nErrorCode)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	CListenSocket* pServerSocket = (CListenSocket*)m_pListenSocket;
	pServerSocket->CloseClientSocket(this);

	CSocket::OnClose(nErrorCode);
}


void CServerSocket::OnReceive(int nErrorCode)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.

	CSocket::OnReceive(nErrorCode);
}
