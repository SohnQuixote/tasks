#pragma once

// CListenSocket 명령 대상

class CListenSocket : public CAsyncSocket
{
public:
	CListenSocket();
	virtual ~CListenSocket();
	CPtrList m_ptrChildSocketList;
	virtual void OnAccept(int nErrorCode);
	void CloseClientSocket(CSocket *pChild);
	void BroadCast(char *buf, int len);
	virtual void OnClose(int nErrorCode);
};


