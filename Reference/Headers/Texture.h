#ifndef Texture_h__
#define Texture_h__

#include "Resources.h"

BEGIN(Engine)

class ENGINE_DLL CTexture
	: public CResources
{
private:
	explicit	CTexture(LPDIRECT3DDEVICE9 pGraphicDev);
public:
	virtual		~CTexture();

public:
	void		Render(const DWORD& iIndex);

private:
	HRESULT LoadTexture(TEXTURETYPE eTexType,
		const wstring& wstrFilePath,
		const WORD& wCnt);
	void Release();

private:
	vector<IDirect3DBaseTexture9*>			m_vecTexture;
	DWORD									m_dwSize = 0;

public:
	static CTexture* Create(LPDIRECT3DDEVICE9 pGraphicDev,
		TEXTURETYPE eTexType,
		const wstring& wstrFilePath,
		const WORD& wCnt);
};

END

#endif // !Texture_h__
