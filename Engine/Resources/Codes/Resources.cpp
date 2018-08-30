#include "Resources.h"

USING(Engine)

Engine::CResources::CResources(LPDIRECT3DDEVICE9 pGraphicDev)
	: m_pGraphicDev(pGraphicDev)
{
}

Engine::CResources::~CResources()
{
	Release();
}

void Engine::CResources::Release()
{
}

void Engine::CResources::Render()
{
}
