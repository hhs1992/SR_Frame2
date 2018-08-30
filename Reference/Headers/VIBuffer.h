#ifndef VIBuffer_h__
#define VIBuffer_h__

#include "Resources.h"

BEGIN(Engine)

class ENGINE_DLL CVIBuffer
	: public CResources
{
public:
	enum BUFFERTYPE {
		BUFFER_TRICOL,
		BUFFER_RCCOL,
		BUFFER_RCTEX,
		BUFFER_TERRAIN,
		BUFFER_TERRAINTEX
	};

protected:
	explicit		CVIBuffer(LPDIRECT3DDEVICE9 pGraphicDev);
public:
	virtual			~CVIBuffer();

public:
	HRESULT			CreateBuffer();
	virtual void	Render();
	virtual void	Release();

protected:
	LPDIRECT3DVERTEXBUFFER9		m_pVB = nullptr;
	LPDIRECT3DINDEXBUFFER9		m_pIB = nullptr;

	DWORD						m_dwVtxSize = 0;
	DWORD						m_dwVtxCnt = 0;
	DWORD						m_dwTriCnt = 0;
	DWORD						m_dwVtxFVF = 0;
	DWORD						m_dwIdxSize = 0;
	D3DFORMAT					m_IdxFmt;
};

END

#endif // !VIBuffer_h__
