#include "RcCol.h"

USING(Engine)

CRcCol::CRcCol(LPDIRECT3DDEVICE9 pGraphicDev)
	: CVIBuffer(pGraphicDev)
{
}

CRcCol::~CRcCol()
{
}

HRESULT CRcCol::Initialize()
{
	m_dwTriCnt = 2;
	m_dwVtxCnt = 4;
	m_dwVtxFVF = VTXFVF_COL;
	m_dwVtxSize = sizeof(VTXCOL);
	m_dwIdxSize = sizeof(INDEX32);
	m_idxFmt = D3DFMT_INDEX32;

	return S_OK;
}

void CRcCol::Render()
{
	CVIBuffer::Render();
}

void CRcCol::Release()
{
}

CRcCol * CRcCol::Create(LPDIRECT3DDEVICE9 m_pGraphicDev)
{
	CRcCol* pInstance = new CRcCol(m_pGraphicDev);

	if (FAILED(pInstance->Initialize()))
		Engine::Safe_Delete(pInstance);

	return pInstance;
}
