#ifndef SceneSelector_h__
#define SceneSelector_h__

#include "include.h"
#include "Logo.h"
#include "Stage.h"

class CSceneSelector
{
public:
	CSceneSelector(SCENEID eScene)
		: m_eScene(eScene) {}

public:
	HRESULT		operator()(Engine::CScene** ppScene,
		LPDIRECT3DDEVICE9 pGraphicDev)
	{
		switch (m_eScene)
		{
		case SC_LOGO:
			*ppScene = CLogo::Create(pGraphicDev);
			break;
		case SC_STAGE:
			*ppScene = CStage::Create(pGraphicDev);
			break;
		}
		NULL_CHECK_RETURN(*ppScene, E_FAIL);

		return S_OK;
	}

private:
	SCENEID			m_eScene;
};


#endif // !SceneSelector_h__
