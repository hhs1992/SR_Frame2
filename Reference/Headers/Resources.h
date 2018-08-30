#ifndef Resources_h__
#define Resources_h__

#include "Engine_Include.h"

BEGIN(Engine)

class ENGINE_DLL CResources
{
protected:
	explicit	CResources(LPDIRECT3DDEVICE9 pGraphicDev);
public:
	virtual		~CResources();

public:
	void			Release();
	virtual void	Render();

protected:
	LPDIRECT3DDEVICE9			m_pGraphicDev = nullptr;
};

END

#endif // !Resources_h__
