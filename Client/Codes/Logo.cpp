#include "stdafx.h"
#include "Logo.h"

#include "include.h"
#include "Export_Function.h"
#include "SceneSelector.h"
#include "RcCol.h"

CLogo::CLogo(LPDIRECT3DDEVICE9 pGraphicDev)
	: Engine::CScene(pGraphicDev)
	, m_pManagement(Engine::Get_Management())
{
}

CLogo::~CLogo()
{
	Release();
}

void CLogo::Update()
{
}

void CLogo::Render()
{
}

HRESULT CLogo::Initialize()
{
	return S_OK;
}

void CLogo::Release()
{
	Engine::Safe_Delete(m_pRcCol);
}

CLogo * CLogo::Create(LPDIRECT3DDEVICE9 pGraphicDev)
{
	CLogo* pInstance = new CLogo(pGraphicDev);

	if (FAILED(pInstance->Initialize()))
		Engine::Safe_Delete(pInstance);

	return pInstance;
}
