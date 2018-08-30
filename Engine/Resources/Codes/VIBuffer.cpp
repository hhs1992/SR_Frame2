#include "VIBuffer.h"

USING(Engine)

Engine::CVIBuffer::CVIBuffer(LPDIRECT3DDEVICE9 pGraphicDev)
	: CResources(pGraphicDev)
{
}

Engine::CVIBuffer::~CVIBuffer()
{
	Release();
}

HRESULT Engine::CVIBuffer::CreateBuffer()
{
	m_pGraphicDev->CreateVertexBuffer(
		m_dwVtxSize * m_dwVtxCnt,
		0,
		m_dwVtxFVF,
		D3DPOOL_MANAGED,
		&m_pVB,
		NULL);

	m_pGraphicDev->CreateIndexBuffer(
		m_dwIdxSize * m_dwTriCnt,
		0,
		m_idxFmt,
		D3DPOOL_MANAGED,
		&m_pIB,
		NULL);

	return S_OK;
}

void Engine::CVIBuffer::Render()
{
	m_pGraphicDev->SetStreamSource(0, m_pVB, 0, m_dwVtxSize);
	m_pGraphicDev->SetFVF(m_dwVtxFVF);
	m_pGraphicDev->SetIndices(m_pIB);
	m_pGraphicDev->DrawIndexedPrimitive(D3DPT_TRIANGLELIST,
		0, 0, m_dwVtxCnt, 0, m_dwTriCnt);
}

void Engine::CVIBuffer::Release()
{
	Engine::Safe_Delete(m_pIB);
	Engine::Safe_Delete(m_pVB);
}
