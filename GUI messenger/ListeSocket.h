#pragma once

// ListeSocket 명령 대상
#include "MainInterface.h"
class ListeSocket : public CSocket
{
public:
	ListeSocket();
	virtual ~ListeSocket();
	void CloseClientSocket(CSocket *pChild);
	void BroadCast(char* pszBuffer, int len);

public:
	CPtrList m_ptrChildSocketList;
//	MainInterface *m_interface;
	virtual void OnAccept(int nErrorCode);
	//MainInterface *main_interface;
};


