#pragma once

// ChildSocket 명령 대상

class ChildSocket : public CSocket
{
public:
	ChildSocket();
	virtual ~ChildSocket();
	CAsyncSocket *m_pListenSocket;
	void SetListenSocket(CAsyncSocket *pSocket);
	virtual void OnClose(int nErrorCode);
	virtual void OnReceive(int nErrorCode);
};


