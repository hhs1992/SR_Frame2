#ifndef Scene_h__
#define Scene_h__

#include "Engine_Include.h"

BEGIN(Engine)

class ENGINE_DLL CScene
{
protected:
	explicit CScene(LPDIRECT3DDEVICE9 pGraphicDev);
public:
	virtual ~CScene();

public:
	virtual HRESULT				Initialize();
	virtual void				Update();
	virtual void				Render();

private:
	virtual void				Release();

private:
	LPDIRECT3DDEVICE9			m_pGraphicDev = nullptr;
};

END

#endif // !Scene_h__
