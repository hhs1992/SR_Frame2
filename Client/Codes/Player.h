#ifndef CPlayer_h__
#define CPlayer_h__

#include "Engine_Include.h"

namespace Engine {
	class CRcCol;
	class CResourcesMgr;
}

class CPlayer
{
private:
	explicit			CPlayer(LPDIRECT3DDEVICE9 pGraphicDev);
public:
						~CPlayer();

public:
	void				Update();
	void				Render();

private:
	HRESULT				Initialize();
	void				Release();
	void				KeyInput();
	void				SetDirection();

private:
	LPDIRECT3DDEVICE9		m_pGraphicDev = nullptr;
	Engine::CResourcesMgr*	m_pResourceMgr = nullptr;
	Engine::INFO			m_tInfo;
	float					m_fAngle = 0.f;
	float					m_fSpeed = 10.f;

public:
	static CPlayer* Create(LPDIRECT3DDEVICE9 pGraphicDev);
};

#endif // !CPlayer_h__
