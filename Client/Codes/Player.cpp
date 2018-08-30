#include "stdafx.h"
#include "Player.h"

#include "Export_Function.h"
#include "include.h"

CPlayer::CPlayer(LPDIRECT3DDEVICE9 pGraphicDev)
	: m_pGraphicDev(pGraphicDev)
	, m_pResourceMgr(Engine::Get_ResourcesMgr())
{
	ZeroMemory(&m_tInfo, sizeof(Engine::INFO));
	D3DXMatrixIdentity(&m_tInfo.matWorld);
}

CPlayer::~CPlayer()
{
	Release();
}

void CPlayer::Update()
{
	KeyInput();
	SetDirection();

	D3DXMATRIX	matRotY, matTrnas;

	D3DXMatrixRotationY(&matRotY, D3DXToRadian(m_fAngle));
	D3DXMatrixTranslation(&matTrnas,
		m_tInfo.vPos.x,
		m_tInfo.vPos.y,
		m_tInfo.vPos.z);

	m_tInfo.matWorld = matRotY * matTrnas;
}

void CPlayer::Render()
{
	m_pGraphicDev->SetTransform(D3DTS_WORLD, &m_tInfo.matWorld);
	m_pResourceMgr->Render(L"Buffer_RcCol");
}

HRESULT CPlayer::Initialize()
{
	FAILED_CHECK_RETURN(m_pResourceMgr->AddBuffer(m_pGraphicDev,
		Engine::RESOURCE_STATIC,
		Engine::CVIBuffer::BUFFER_RCCOL,
		L"Buffer_RcCol"), E_FAIL);

	return S_OK;
}

void CPlayer::Release()
{
}

void CPlayer::KeyInput()
{
	if (GetAsyncKeyState(VK_UP) & 0x8000)
		m_tInfo.vPos += m_tInfo.vDir * 0.02f;

	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		m_tInfo.vPos -= m_tInfo.vDir * 0.02f;

	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		m_fAngle += 0.02f;

	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		m_fAngle -= 0.02f;
}

void CPlayer::SetDirection()
{
	D3DXVec3TransformNormal(&m_tInfo.vDir, &g_vLook, &m_tInfo.matWorld);
	D3DXVec3Normalize(&m_tInfo.vDir, &m_tInfo.vDir);
}

CPlayer * CPlayer::Create(LPDIRECT3DDEVICE9 pGraphicDev)
{
	CPlayer*	pInstance = new CPlayer(pGraphicDev);

	if (FAILED(pInstance->Initialize()))
		Engine::Safe_Delete(pInstance);

	return pInstance;
}
