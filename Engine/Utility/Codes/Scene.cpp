#include "Scene.h"

USING(Engine)

Engine::CScene::CScene(LPDIRECT3DDEVICE9 pGraphicDev)
	: m_pGraphicDev(pGraphicDev)
{
}

Engine::CScene::~CScene()
{
	Release();
}

HRESULT Engine::CScene::Initialize()
{
	return S_OK;
}

void Engine::CScene::Update()
{
}

void Engine::CScene::Render()
{
}

void Engine::CScene::Release()
{
}
