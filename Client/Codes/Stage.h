#ifndef Stage_h__
#define Stage_h__

#include "Scene.h"

namespace Engine
{
	class CManagement;
	class CRcCol;
}

class CStage
	: public Engine::CScene
{
private:
	explicit			CStage(LPDIRECT3DDEVICE9 pGraphicDev);

public:
	virtual				~CStage();

public:
	virtual void		Update();
	virtual void		Render();


private:
	virtual HRESULT		Initialize();
	virtual void		Release();

public:
	static CStage*		Create(LPDIRECT3DDEVICE9 pGraphicDev);
};

#endif // !Stage_h__
