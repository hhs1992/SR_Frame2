#ifndef ResourcesMgr_h__
#define ResourcesMgr_h__

#include "Engine_Include.h"

#include "TriCol.h"
#include "RcCol.h"

BEGIN(Engine)

class ENGINE_DLL CResourcesMgr
{
	DECLARE_SINGLETON(CResourcesMgr)

private:
	CResourcesMgr();
	~CResourcesMgr();

public:
	HRESULT		AddBuffer(LPDIRECT3DDEVICE9 pGraphicDev,
							RESOURCETYPE eResourceType,
							CVIBuffer::BUFFERTYPE eBufferType,
							const wstring& wstrResourceKey,
							const WORD& wCntX = 0,
							const WORD& wCntZ = 0,
							const WORD& wItv = 1);
	void		Render(const wstring& wstrResourceKey);
	

private:
	void		Release();

private:
	CResources*					m_pResources = nullptr;
	map<wstring, CResources*>	m_mapResources[RESOURCE_END];
};

END

#endif // !ResourcesMgr_h__
