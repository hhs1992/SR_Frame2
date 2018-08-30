#ifndef Renderer_h__
#define	Renderer_h__

#include "Engine_Include.h"
#include "Scene.h"

BEGIN(Engine)

class ENGINE_DLL CRenderer
{
private:
	CRenderer(LPDIRECT3DDEVICE9 pGraphicDev);
public:
	~CRenderer();

public:
	void			SetScene(CScene* pScene);

public:
	HRESULT			Initialize();
	void			Render();

private:
	LPDIRECT3DDEVICE9	m_pGraphicDev = nullptr;
	CScene*				m_pScene = nullptr;

public:
	static CRenderer*	Create(LPDIRECT3DDEVICE9 pGraphicDev);
};

END

#endif // !Renderer_h__
