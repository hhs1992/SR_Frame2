#ifndef MainApp_h__
#define MainApp_h__

#include "include.h"
#include "Export_Function.h"

class CMainApp
{
private:
	explicit CMainApp();
	
public:
	~CMainApp();

public:
	void				Update();
	void				Render();

private:
	HRESULT				Initialize();
	void				Release();

private:
	Engine::CGraphicDev*		m_pDevice = nullptr;
	Engine::CManagement*		m_pManagement = nullptr;

	LPDIRECT3DDEVICE9			m_pGraphicDev = nullptr;

public:
	static CMainApp*	Create();
};
#endif // !MainApp_h__
