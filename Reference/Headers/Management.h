#ifndef Management_h__
#define	Management_h__

#include "Renderer.h"

BEGIN(Engine)

class ENGINE_DLL CManagement
{
	DECLARE_SINGLETON(CManagement)

private:
	CManagement();
	~CManagement();

public:
	HRESULT					Initialize(LPDIRECT3DDEVICE9 pGraphicDev);
	void					Update();
	void					Render();

public:
	template<typename T>
	HRESULT SceneChange(T& Functor);

private:
	void					Release();

private:
	LPDIRECT3DDEVICE9		m_pGraphicDev = nullptr;
	CRenderer*				m_pRenderer = nullptr;
	CScene*					m_pScene = nullptr;
};

END

template<typename T>
HRESULT Engine::CManagement::SceneChange(T& Functor)
{
	if (m_pScene != nullptr)
		Engine::Safe_Delete(m_pScene);

	FAILED_CHECK(Functor(&m_pScene, m_pGraphicDev));

	m_pRenderer->SetScene(m_pScene);

	return S_OK;
}

#endif // !Management_h__
