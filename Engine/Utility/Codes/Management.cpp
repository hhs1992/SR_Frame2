#include "Management.h"

USING(Engine)
IMPLEMENT_SINGLETON(CManagement)

Engine::CManagement::CManagement()
{
}

Engine::CManagement::~CManagement()
{
	Release();
}

HRESULT Engine::CManagement::Initialize(LPDIRECT3DDEVICE9 pGraphicDev)
{
	m_pGraphicDev = pGraphicDev;
	NULL_CHECK_RETURN(m_pGraphicDev, E_FAIL);

	// 兄希君 持失
	m_pRenderer = CRenderer::Create(m_pGraphicDev);
	NULL_CHECK_RETURN_MSG(m_pRenderer, E_FAIL, L"Renderer Create Fail");

	return S_OK;
}

void Engine::CManagement::Update()
{
	if (m_pScene != nullptr)
		m_pScene->Update();
}

void Engine::CManagement::Render()
{
	if (m_pScene != nullptr)
		m_pRenderer->Render();
}

void Engine::CManagement::Release()
{
	Engine::Safe_Delete(m_pScene);
	Engine::Safe_Delete(m_pRenderer);
}
