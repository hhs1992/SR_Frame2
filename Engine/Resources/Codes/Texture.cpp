#include "Texture.h"

USING(Engine)

Engine::CTexture::CTexture(LPDIRECT3DDEVICE9 pGraphicDev)
	: CResources(pGraphicDev)
{
}

Engine::CTexture::~CTexture()
{
	Release();
}

void Engine::CTexture::Render(const DWORD & iIndex)
{
}

HRESULT Engine::CTexture::LoadTexture(TEXTURETYPE eTexType, const wstring & wstrFilePath, const WORD & wCnt)
{
	m_vecTexture.reserve(wCnt);

	IDirect3DBaseTexture9* pTexture = nullptr;
	TCHAR szFullPath[MAX_PATH] = L"";

	for (size_t i = 0; i < wCnt; ++i)
	{
		wsprintf(szFullPath, wstrFilePath.c_str(), i);
		HRESULT hr = NULL;

		switch (eTexType)
		{
		case TEX_NORMAL:
			hr = D3DXCreateTextureFromFile(m_pGraphicDev, szFullPath, (LPDIRECT3DTEXTURE9*)&pTexture);
			break;
		case TEX_CUBE:
			hr = D3DXCreateCubeTextureFromFile(m_pGraphicDev, szFullPath, (LPDIRECT3DCUBETEXTURE9*)&pTexture);
			break;
		}

		FAILED_CHECK_MSG(hr, szFullPath);
	
		m_vecTexture.push_back(pTexture);
	}

	m_dwSize = m_vecTexture.size();

	return S_OK;
}

void Engine::CTexture::Release()
{
	for (size_t i = 0; i < m_vecTexture.size(); ++i)
		Engine::Safe_Release(m_vecTexture[i]);

	m_vecTexture.clear();
}

CTexture * CTexture::Create(LPDIRECT3DDEVICE9 pGraphicDev, TEXTURETYPE eTexType, const wstring & wstrFilePath, const WORD & wCnt)
{
	CTexture* pInstance = new CTexture(pGraphicDev);

	if (FAILED(pInstance->LoadTexture(eTexType, wstrFilePath, wCnt)))
		Engine::Safe_Delete(pInstance);

	return pInstance;
}
