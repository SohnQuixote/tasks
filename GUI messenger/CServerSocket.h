#pragma once

// CServerSocket 명령 대상

class CServerSocket : public CSocket
{
public:
	CServerSocket();
	virtual ~CServerSocket();
	CAsyncSocket * m_pListenSocket;
	void SetListenSocket(CAsyncSocket * pSocket);
	virtual void OnClose(int nErrorCode);
	virtual void OnReceive(int nErrorCode);
};


