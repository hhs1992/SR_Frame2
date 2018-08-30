#include "Renderer.h"

USING(Engine)

Engine::CRenderer::CRenderer(LPDIRECT3DDEVICE9 pGraphicDev)
	: m_pGraphicDev(pGraphicDev)
{
}

Engine::CRenderer::~CRenderer()
{
}

void Engine::CRenderer::SetScene(CScene * pScene)
{
	m_pScene = pScene;
}

HRESULT Engine::CRenderer::Initialize()
{
	return S_OK;
}

void Engine::CRenderer::Render()
{
	m_pGraphicDev->Clear(0,
		NULL,
		D3DCLEAR_TARGET | D3DCLEAR_STENCIL | D3DCLEAR_ZBUFFER,
		D3DCOLOR_ARGB(255, 0, 0, 255),
		1.f,
		0);
	m_pGraphicDev->BeginScene();

	if (nullptr != m_pScene)
		m_pScene->Render();

	m_pGraphicDev->EndScene();
	m_pGraphicDev->Present(NULL, NULL, NULL, NULL);
}

Engine::CRenderer * Engine::CRenderer::Create(LPDIRECT3DDEVICE9 pGraphicDev)
{
	CRenderer* pInstance = new CRenderer(pGraphicDev);

	if (FAILED(pInstance->Initialize()))
		Engine::Safe_Delete(pInstance);

	return pInstance;
}
