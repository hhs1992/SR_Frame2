#include "stdafx.h"
#include "Logo.h"

#include "include.h"
#include "Export_Function.h"
#include "SceneSelector.h"
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
	if (GetAsyncKeyState(VK_RETURN))
	{
		m_pManagement->SceneChange(CSceneSelector(SC_STAGE));
		return;
	}

	m_pPlayer->Update();
}

void CLogo::Render()
{
	m_pPlayer->Render();
}

HRESULT CLogo::Initialize()
{
	D3DXMATRIX		matView, matProj;

	// 뷰스페이스 변환 행렬 함수
	D3DXMatrixLookAtLH(&matView,	
		&D3DXVECTOR3(0.f, 0.f, -20.f),	
		&D3DXVECTOR3(0.f, 0.f, 0.f),
		&D3DXVECTOR3(0.f, 1.f, 0.f));

	m_pGraphicDev->SetTransform(D3DTS_VIEW, &matView);

	// 투영 변환 행렬 함수

	D3DXMatrixPerspectiveFovLH(&matProj,
		D3DXToRadian(45.f),			
		float(WINCX) / float(WINCY), 
		1.f,						
		1000.f);					

	m_pGraphicDev->SetTransform(D3DTS_PROJECTION, &matProj);

	// 플레이어 생성
	m_pPlayer = CPlayer::Create(m_pGraphicDev);
	NULL_CHECK_RETURN(m_pPlayer, E_FAIL);

	return S_OK;
}

void CLogo::Release()
{
	Engine::Safe_Delete(m_pPlayer);
}

CLogo * CLogo::Create(LPDIRECT3DDEVICE9 pGraphicDev)
{
	CLogo* pInstance = new CLogo(pGraphicDev);

	if (FAILED(pInstance->Initialize()))
		Engine::Safe_Delete(pInstance);

	return pInstance;
}
