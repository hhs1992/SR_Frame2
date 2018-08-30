#include "stdafx.h"
#include "MainApp.h"

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
}

void CMainApp::Render()
{
}

HRESULT CMainApp::Initialize()
{
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
