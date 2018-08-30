#ifndef RcCol_h__
#define RcCol_h__

#include "VIBuffer.h"

BEGIN(Engine)

class ENGINE_DLL CRcCol
	: public CVIBuffer
{
private:
	explicit			CRcCol(LPDIRECT3DDEVICE9 pGraphicDev);

public:
	virtual				~CRcCol();

public:
	HRESULT				Initialize();
	virtual void		Render();
	virtual void		Release();

public:
	static CRcCol*		Create(LPDIRECT3DDEVICE9 m_pGraphicDev);

};

END
#endif // !RcCol_h__
