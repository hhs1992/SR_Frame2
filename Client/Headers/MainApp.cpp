#include "stdafx.h"
#include "MainApp.h"
#include "SceneSelector.h"

CMainApp::CMainApp()
	: m_pDevice(Engine::Get_GraphicDev())
	, m_pManagement(Engine::Get_Management())
{
}

CMainApp::~CMainApp()
{
	Release();
}

void CMainApp::Update()
{
	m_pManagement->Update();
}

void CMainApp::Render()
{
	m_pManagement->Render();
}

HRESULT CMainApp::Initialize()
{
	// GraphicDev
	FAILED_CHECK(m_pDevice->InitGraphicDev(Engine::CGraphicDev::MODE_WIN,
		g_hWnd, WINCX, WINCY));

	// LPDIRECTDEIVICE9
	m_pGraphicDev = m_pDevice->GetDevice();
	NULL_CHECK_RETURN(m_pGraphicDev, E_FAIL);

	// Management
	FAILED_CHECK(m_pManagement->Initialize(m_pGraphicDev));

	// SceneSelect
	FAILED_CHECK(m_pManagement->SceneChange(CSceneSelector(SC_LOGO)));


	return S_OK;
}

void CMainApp::Release()
{
}

CMainApp * CMainApp::Create()
{
	CMainApp* pInstance = new CMainApp;

	if (FAILED(pInstance->Initialize()))
	{
		delete pInstance;
		pInstance = nullptr;
	}

	return pInstance;
}
