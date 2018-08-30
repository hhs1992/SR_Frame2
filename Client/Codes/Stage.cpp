#include "stdafx.h"
#include "Stage.h"

CStage::CStage(LPDIRECT3DDEVICE9 pGraphicDev)
	: Engine::CScene(pGraphicDev)
{
}

CStage::~CStage()
{
	Release();
}

void CStage::Update()
{
}

void CStage::Render()
{
	int a = 0;
}

HRESULT CStage::Initialize()
{
	return S_OK;
}

void CStage::Release()
{
}

CStage * CStage::Create(LPDIRECT3DDEVICE9 pGraphicDev)
{
	CStage* pInstance = new CStage(pGraphicDev);

	if (FAILED(pInstance->Initialize()))
		Engine::Safe_Delete(pInstance);

	return pInstance;
}
