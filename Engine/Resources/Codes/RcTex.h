#ifndef RcTex_h__
#define RcTex_h__

#include "VIBuffer.h"

BEGIN(Engine)

class ENGINE_DLL CRcTex
	: public CVIBuffer
{
private:
	explicit		CRcTex(LPDIRECT3DDEVICE9 pGraphicDev);
public:
	virtual			~CRcTex();

public:
	HRESULT			Initialize();
	virtual void	Render();
	virtual void	Release();

public:
	static CRcTex*	Create(LPDIRECT3DDEVICE9 pGraphicDev);
};

END

#endif // !RcTex_h__
