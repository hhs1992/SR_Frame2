#ifndef Logo_h__
#define Logo_h__

#include "Scene.h"

namespace Engine
{
	class CManagement;
	class CRcCol;
}

class CPlayer;
class CLogo
	: public Engine::CScene
{
private:
	explicit			CLogo(LPDIRECT3DDEVICE9 pGraphicDev);

public:
	virtual				~CLogo();

public:
	virtual void		Update();
	virtual void		Render();

private:
	virtual HRESULT		Initialize();
	virtual void		Release();

private:
	Engine::CManagement*		m_pManagement = nullptr;
	Engine::CRcCol*				m_pRcCol = nullptr;
	CPlayer*					m_pPlayer = nullptr;

public:
	static CLogo*		Create(LPDIRECT3DDEVICE9 pGraphicDev);
};

#endif // !Logo_h__
