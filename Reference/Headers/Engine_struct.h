#ifndef Engine_struct_h__
#define Engine_struct_h__

namespace Engine
{
	typedef struct tagVertexColor
	{
		D3DXVECTOR3			vPos;
		DWORD				dwColor;
	} VTXCOL;

	const DWORD		VTXFVF_COL = D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX0;

	typedef struct tagVertexTex
	{
		D3DXVECTOR3			vPos;
		D3DXVECTOR2			vTex;
	} VTXTEX;

	const DWORD		VTXFVF_TEX = D3DFVF_XYZ | D3DFVF_TEX1;

	typedef struct tagIndex16
	{
		WORD				_1, _2, _3;
	} INDEX16;

	typedef struct tagIndex32
	{
		WORD				_1, _2, _3;
	} INDEX32;

	typedef struct tagInfo
	{
		D3DXVECTOR3		vPos;
		D3DXVECTOR3		vDir;
		D3DXVECTOR3		vLook;

		D3DXMATRIX		matWorld;
	} INFO;
}


#endif // Engine_struct_h__
