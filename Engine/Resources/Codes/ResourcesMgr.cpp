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

	NULL_CHECK_RETURN(pResource, E_FAIL);

	m_mapResources[eResourceType].emplace(wstrResourceKey, pResource);

	return S_OK;
}

void Engine::CResourcesMgr::Render(const wstring & wstrResourceKey)
{
	auto iter = m_mapResources[0].find(wstrResourceKey);

	if (iter == m_mapResources[0].end())
		return;

	iter->second->Render();
}

void Engine::CResourcesMgr::Release()
{
	for (size_t i = 0; i < RESOURCE_END; ++i)
	{
		for_each(m_mapResources[i].begin(), m_mapResources[i].end(), CDeleteMap());
		m_mapResources[i].clear();
	}
}


