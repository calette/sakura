﻿#include "StdAfx.h"
#include "view/CEditView.h" // SColorStrategyInfo
#include "CFigure_ZenSpace.h"
#include "types/CTypeSupport.h"


// -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- //
//                      CFigure_ZenSpace                         //
// -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- //

bool CFigure_ZenSpace::Match(const wchar_t* pText, int nTextLen) const
{
	if( pText[0] == L'　' ){
		return true;
	}
	return false;
}


// -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- //
//                         描画実装                            //
// -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- //

//! 全角スペース描画
void CFigure_ZenSpace::DispSpace( CGraphics& gr, DispPos* pDispPos, CEditView* pcView, bool bTrans ) const
{
	//クリッピング矩形を計算。画面外なら描画しない
	RECT rc;
	if(pcView->GetTextArea().GenerateClipRect(&rc,*pDispPos,2))
	{
		//描画
		const wchar_t* szZenSpace =
			CTypeSupport(pcView,COLORIDX_ZENSPACE).IsDisp()?L"□":L"　";
		::ExtTextOutW_AnyBuild(
			gr,
			pDispPos->GetDrawPos().x,
#ifdef SI_LINE_CENTERING
			(pcView->GetLineSpace() / 2) +
#endif  // SI_
			pDispPos->GetDrawPos().y,
			ExtTextOutOption() & ~(bTrans? ETO_OPAQUE: 0),
			&rc,
			szZenSpace,
			wcslen(szZenSpace),
			pcView->GetTextMetrics().GetDxArray_AllZenkaku()
		);
	}

	//位置進める
	pDispPos->ForwardDrawCol(2);
}
