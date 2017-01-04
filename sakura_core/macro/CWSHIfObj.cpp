/*!	@file
	@brief WSH�C���^�t�F�[�X�I�u�W�F�N�g��{�N���X

	@date 2009.10.29 syat CWSH.cpp����؂�o��
*/
/*
	Copyright (C) 2002, �S, genta
	Copyright (C) 2003, FILE
	Copyright (C) 2004, genta
	Copyright (C) 2005, FILE, zenryaku
	Copyright (C) 2009, syat

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
#include "macro/CWSHIfObj.h"
#include "macro/CSMacroMgr.h" // MacroFuncInfo
#include "Funccode_enum.h" // EFunctionCode::FA_FROMMACRO
#include "util/other_util.h" // auto_array_ptr


//�R�}���h�E�֐�����������
void CWSHIfObj::ReadyMethods( CEditView* pView, int flags )
{
	this->m_pView = pView;
	//	 2007.07.20 genta : �R�}���h�ɍ������ރt���O��n��
	ReadyCommands(GetMacroCommandInfo(), flags | FA_FROMMACRO );
	ReadyCommands(GetMacroFuncInfo(), 0);
	/* CWSHIfObj���p�������T�u�N���X����ReadyMethods���Ăяo�����ꍇ�A
	 * �T�u�N���X��GetMacroCommandInfo,GetMacroFuncInfo���Ăяo�����B */
}

/** WSH�}�N���G���W���փR�}���h�o�^���s��

	@date 2007.07.20 genta flags�ǉ��Dflag�̓R�}���h�o�^�i�K�ō����Ă����D
*/
void CWSHIfObj::ReadyCommands(MacroFuncInfo *Info, int flags)
{
	while(Info->m_nFuncID != -1)	// Aug. 29, 2002 genta �Ԑl�̒l���ύX���ꂽ�̂ł������ύX
	{
		wchar_t FuncName[256];
		wcscpy(FuncName, Info->m_pszFuncName);

		int ArgCount = 0;
		if( Info->m_pData ){
			ArgCount = Info->m_pData->m_nArgMinSize;
		}else{
			for(int i = 0; i < 4; ++i){
				if(Info->m_varArguments[i] != VT_EMPTY) 
					++ArgCount;
			}
		}
		VARTYPE* varArgTmp = NULL;
		VARTYPE* varArg = Info->m_varArguments;
		if( 4 < ArgCount ){
			varArgTmp = varArg = new VARTYPE[ArgCount];
			for( int i = 0; i < ArgCount; i++ ){
				if( i < 4 ){
					varArg[i] = Info->m_varArguments[i];
				}else{
					varArg[i] = Info->m_pData->m_pVarArgEx[i-4];
				}
			}
		}
		//	2007.07.21 genta : flag���������l��o�^����
		this->AddMethod(
			FuncName,
			(Info->m_nFuncID | flags),
			varArg,
			ArgCount,
			Info->m_varResult,
			reinterpret_cast<CIfObjMethod>(&CWSHIfObj::MacroCommand)
			/* CWSHIfObj���p�������T�u�N���X����ReadyCommands���Ăяo�����ꍇ�A
			 * �T�u�N���X��MacroCommand���Ăяo�����B */
		);
		delete [] varArgTmp;
		++Info;
	}
}

/*!
	�}�N���R�}���h�̎��s

	@date 2005.06.27 zenryaku �߂�l�̎󂯎�肪�����Ă��G���[�ɂ����Ɋ֐������s����
	@date 2013.06.07 Moca 5�ȏ�̈����̎������̂��C���BNUL���܂ޕ�����Ή�
*/
HRESULT CWSHIfObj::MacroCommand(int IntID, DISPPARAMS *Arguments, VARIANT* Result, void *Data)
{
	int I;
	int ArgCount = Arguments->cArgs;

	const EFunctionCode ID = static_cast<EFunctionCode>(IntID);
	//	2007.07.22 genta : �R�}���h�͉���16�r�b�g�̂�
	if(LOWORD(ID) >= F_FUNCTION_FIRST)
	{
		VARIANT ret; // 2005.06.27 zenryaku �߂�l�̎󂯎�肪�����Ă��֐������s����
		VariantInit(&ret);

		// 2011.3.18 syat �����̏����𐳂������ɂ���
		auto_array_ptr<VARIANTARG> rgvargParam( new VARIANTARG[ArgCount] );
		for(I = 0; I < ArgCount; I++){
			::VariantInit(&rgvargParam[ArgCount - I - 1]);
			::VariantCopy(&rgvargParam[ArgCount - I - 1], &Arguments->rgvarg[I]);
		}

		// 2009.9.5 syat HandleFunction�̓T�u�N���X�ŃI�[�o�[���C�h����
		bool r = HandleFunction(m_pView, ID, &rgvargParam[0], ArgCount, ret);
		if(Result) {::VariantCopyInd(Result, &ret);}
		VariantClear(&ret);
		for(I = 0; I < ArgCount; I++){
			::VariantClear(&rgvargParam[I]);
		}
		return r ? S_OK : E_FAIL;
	}
	else
	{
		// �Œ�4�͊m��
		int argCountMin = t_max(4, ArgCount);
		//	Nov. 29, 2005 FILE �����𕶎���Ŏ擾����
		// 2014.06.09 Warp(VARIANT)->GetW()����̂���߂�Variant�̂܂ܕێ�����
		auto_array_ptr<LPWSTR> StrArgs( new LPWSTR[argCountMin] );
		auto_array_ptr<int> strLengths( new int[argCountMin] );
		auto_array_ptr<Variant> varArgs( new Variant[ArgCount] ); // VT_BYREF���ƍ���̂ŃR�s�[�p
		for(I = ArgCount; I < argCountMin; I++ ){
			StrArgs[I] = NULL;
			strLengths[I] = 0;
		}
		for(I = 0; I < ArgCount; ++I)
		{
			VARIANT* const pvArg = &Arguments->rgvarg[I];
			BSTR bstr;
			if( pvArg->vt == VT_BSTR ){
				bstr = pvArg->bstrVal;
			}else if( pvArg->vt == (VT_BYREF | VT_BSTR) ){
				bstr = *(pvArg->pbstrVal);
			}else if( pvArg->vt == (VT_BYREF | VT_VARIANT) && pvArg->pvarVal->vt == VT_BSTR ){
				bstr = pvArg->pvarVal->bstrVal;
			}else{
				if( VariantChangeType(&varArgs[I].Data, pvArg, 0, VT_BSTR) != S_OK ){
					// Error
					SysString str(L"", 0);
					varArgs[I].Receive(str);
				}
				bstr = varArgs[I].Data.bstrVal;
			}
			// DISPPARAMS�͈����̏������t�]���Ă��邽�ߐ��������ɒ���
			StrArgs[ArgCount - I - 1] = bstr;
			strLengths[ArgCount - I - 1] = ::SysStringLen(bstr);
		}

		// 2009.10.29 syat HandleCommand�̓T�u�N���X�ŃI�[�o�[���C�h����
		HandleCommand(m_pView, ID, const_cast<WCHAR const **>(&StrArgs[0]), &strLengths[0], ArgCount);

		return S_OK;
	}
}
