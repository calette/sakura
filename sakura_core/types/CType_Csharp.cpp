/*
	Copyright (C) 2008, kobake
	Copyright (C) 2014, Moca

	This software is provided 'as-is', without any express or implied
	warranty. In no event will the authors be held liable for any damages
	arising from the use of this software.

	Permission is granted to anyone to use this software for any purpose,
	including commercial applications, and to alter it and redistribute it
	freely, subject to the following restrictions:

		1. The origin of this software must not be misrepresented;
		   you must not claim that you wrote the original software.
		   If you use this software in a product, an acknowledgment
		   in the product documentation would be appreciated but is
		   not required.

		2. Altered source versions must be plainly marked as such,
		   and must not be misrepresented as being the original software.

		3. This notice may not be removed or altered from any source
		   distribution.
*/
#include "StdAfx.h"
#include "types/CType.h"
#include "types/CTypeInit.h"
#include "view/colors/EColorIndexType.h"

int g_nKeywordsIdx_CSHARP = -1;
int g_nKeywordsIdx_CSHARP2 = -1;

/* C# */
void CType_Csharp::InitTypeConfigImp(STypeConfig* pType)
{
	//���O�Ɗg���q
	_tcscpy( pType->m_szTypeName, _T("C#") );
	_tcscpy( pType->m_szTypeExts, _T("cs") );

	//�ݒ�
	pType->m_cLineComment.CopyTo( 0, L"//", -1 );
	pType->m_cBlockComments[0].SetBlockCommentRule( L"/*", L"*/" );
	pType->m_nStringType = STRING_LITERAL_CSHARP;
	pType->m_bStringLineOnly = true;
	pType->m_nKeyWordSetIdx[0] = g_nKeywordsIdx_CSHARP;
	pType->m_nKeyWordSetIdx[1] = g_nKeywordsIdx_CSHARP2;
	pType->m_ColorInfoArr[COLORIDX_DIGIT].m_bDisp = true;
#if REI_MOD_UNIFY_QUOTE == 0
	pType->m_ColorInfoArr[COLORIDX_SSTRING].m_bDisp = true;
#endif // rei_
	pType->m_ColorInfoArr[COLORIDX_WSTRING].m_bDisp = true;
	pType->m_ColorInfoArr[COLORIDX_BRACKET_PAIR].m_bDisp = true;
}


