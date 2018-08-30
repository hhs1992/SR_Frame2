#include "ResourcesMgr.h"

USING(Engine)
IMPLEMENT_SINGLETON(CResourcesMgr)

CResourcesMgr::CResourcesMgr()
{
}

CResourcesMgr::~CResourcesMgr()
{
}

HRESULT CResourcesMgr::AddBuffer(LPDIRECT3DDEVICE9 pGraphicDev, RESOURCETYPE eResourceType, CVIBuffer::BUFFERTYPE eBufferType, const wstring & wstrResourceKey, const WORD & wCntX, const WORD & wCntZ, const WORD & wItv)
{
	return S_OK;
}

void CResourcesMgr::Render(const wstring & wstrResourceKey)
{
}

void CResourcesMgr::Release()
{
}


