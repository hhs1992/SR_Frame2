#include "stdafx.h"
#include "Logo.h"

#include "include.h"
#include "Export_Function.h"
#include "SceneSelector.h"
#include "RcCol.h"

#include "Player.h"

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
	m_pPlayer->Update();
}

void CLogo::Render()
{
	m_pPlayer->Render();
}

HRESULT CLogo::Initialize()
{

	m_pPlayer = CPlayer::Create(m_pGraphicDev);
	NULL_CHECK_RETURN(m_pPlayer, E_FAIL);

	return S_OK;
}

void CLogo::Release()
{
	Engine::Safe_Delete(m_pPlayer);
	Engine::Safe_Delete(m_pRcCol);
}

CLogo * CLogo::Create(LPDIRECT3DDEVICE9 pGraphicDev)
{
	CLogo* pInstance = new CLogo(pGraphicDev);

	if (FAILED(pInstance->Initialize()))
		Engine::Safe_Delete(pInstance);

	return pInstance;
}
