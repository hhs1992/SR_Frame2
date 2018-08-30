#include "TriCol.h"

USING(Engine)

Engine::CTriCol::CTriCol(LPDIRECT3DDEVICE9 pGraphicDev)
	: CVIBuffer(pGraphicDev)
{
}

Engine::CTriCol::~CTriCol()
{
	Release();
}

HRESULT Engine::CTriCol::Initialize()
{
	return S_OK;
}

void Engine::CTriCol::Render()
{
	CVIBuffer::Render();
}

void Engine::CTriCol::Release()
{
}

Engine::CTriCol * Engine::CTriCol::Create(LPDIRECT3DDEVICE9 pGraphicDev)
{
	CTriCol* pInstance = new CTriCol(pGraphicDev);

	if (FAILED(pInstance->Initialize()))
		Engine::Safe_Delete(pInstance);

	return pInstance;
}
