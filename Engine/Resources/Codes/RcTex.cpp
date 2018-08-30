#include "RcTex.h"

USING(Engine)

Engine::CRcTex::CRcTex(LPDIRECT3DDEVICE9 pGraphicDev)
	: CVIBuffer(pGraphicDev)
{
}

Engine::CRcTex::~CRcTex()
{
	Release();
}

HRESULT Engine::CRcTex::Initialize()
{
	return E_NOTIMPL;
}

void Engine::CRcTex::Render()
{
	CVIBuffer::Render();
}

void Engine::CRcTex::Release()
{
}

Engine::CRcTex * Engine::CRcTex::Create(LPDIRECT3DDEVICE9 pGraphicDev)
{
	CRcTex* pInstance = new CRcTex(pGraphicDev);

	if (FAILED(pInstance->Initialize()))
		Engine::Safe_Delete(pInstance);

	return pInstance;
}
