#ifndef TriCol_h__
#define TriCol_h__

#include "VIBuffer.h"

BEGIN(Engine)

class ENGINE_DLL CTriCol
	: public CVIBuffer
{
private:
	explicit		CTriCol(LPDIRECT3DDEVICE9 pGraphicDev);
public:
	virtual			~CTriCol();

public:
	HRESULT			Initialize();
	virtual void	Render();
	virtual void	Release();

public:
	static CTriCol*		Create(LPDIRECT3DDEVICE9 pGraphicDev);
};

END

#endif // !TriCol_h__
