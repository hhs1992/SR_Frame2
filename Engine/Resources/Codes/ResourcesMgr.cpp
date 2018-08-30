#include "ResourcesMgr.h"

USING(Engine)
IMPLEMENT_SINGLETON(CResourcesMgr)

Engine::CResourcesMgr::CResourcesMgr()
{
}

Engine::CResourcesMgr::~CResourcesMgr()
{
	Release();
}

HRESULT Engine::CResourcesMgr::AddBuffer(LPDIRECT3DDEVICE9 pGraphicDev, RESOURCETYPE eResourceType, CVIBuffer::BUFFERTYPE eBufferType, const wstring & wstrResourceKey, const WORD & wCntX, const WORD & wCntZ, const WORD & wItv)
{
	auto iter = m_mapResources[eResourceType].find(wstrResourceKey);

	if (iter != m_mapResources[eResourceType].end())
	{
		TAGERR_BOX(wstrResourceKey.c_str(), L"중복된 리소스");
		return E_FAIL;
	}

	CResources* pResource = nullptr;

	switch (eBufferType)
	{
	case CVIBuffer::BUFFER_TRICOL:
		pResource = CTriCol::Create(pGraphicDev);
		break;
	case CVIBuffer::BUFFER_RCCOL:
		pResource = CRcCol::Create(pGraphicDev);
		break;
	case CVIBuffer::BUFFER_RCTEX:
		pResource = CRcTex::Create(pGraphicDev);
		break;
	case CVIBuffer::BUFFER_TERRAIN:
		break;
	case CVIBuffer::BUFFER_TERRAINTEX:
		break;
	}

	return S_OK;
}

void Engine::CResourcesMgr::Render(const wstring & wstrResourceKey)
{
}

void Engine::CResourcesMgr::Release()
{
}


