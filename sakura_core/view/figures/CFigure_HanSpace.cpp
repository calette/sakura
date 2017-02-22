#include "StdAfx.h"
#include "view/CEditView.h" // SColorStrategyInfo

#include "CFigure_HanSpace.h"
#include "types/CTypeSupport.h"

// -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- //
//                     CFigure_HanSpace                        //
// -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- //

bool CFigure_HanSpace::Match(const wchar_t* pText, int nTextLen) const
{
	if( pText[0] == L' ' ){
		return true;
	}
	return false;
}


// -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- //
//                         �`�����                            //
// -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- //

//! ���p�X�y�[�X�`��
void CFigure_HanSpace::DispSpace(CGraphics& gr, DispPos* pDispPos, CEditView* pcView, bool bTrans) const
{
	//�N���b�s���O��`���v�Z�B��ʊO�Ȃ�`�悵�Ȃ�
	CMyRect rcClip;
	if(pcView->GetTextArea().GenerateClipRect(&rcClip,*pDispPos,1))
	{
#if REI_MOD_HAN_SPACE
		// �󔒂ŏ���
		CMyRect rcClipBottom=rcClip;
		::ExtTextOutW_AnyBuild(
			gr,
			pDispPos->GetDrawPos().x,
  #if REI_LINE_CENTERING
			(pcView->m_pTypeData->m_nLineSpace/2) +
  #endif  // rei_
			pDispPos->GetDrawPos().y,
			ExtTextOutOption() & ~(bTrans? ETO_OPAQUE: 0),
			&rcClipBottom,
			L" ",//L"�",
			1,
			pcView->GetTextMetrics().GetDxArray_AllHankaku()
		);
		
		// ���p�X�y�[�X���h�b�g�ŕ\��
		int x = rcClip.left + (rcClip.right - rcClip.left) / 2;
		int y = rcClip.top + (rcClip.bottom - rcClip.top) / 2;
  #if REI_LINE_CENTERING
		y += (pcView->m_pTypeData->m_nLineSpace/2);
  #endif  // rei_
		gr.SetPen( gr.GetCurrentTextForeColor() );
		x--; // ��������
		::MoveToEx( gr, x, y-2, NULL );
		::LineTo(   gr, x+2, y-2 );
		::MoveToEx( gr, x, y-1, NULL );
		::LineTo(   gr, x+2, y-1 );
#else  //REI_MOD_HAN_SPACE
		//������"o"�̉��������o��
		CMyRect rcClipBottom=rcClip;
		rcClipBottom.top=rcClip.top+pcView->GetTextMetrics().GetHankakuHeight()/2;
		::ExtTextOutW_AnyBuild(
			gr,
			pDispPos->GetDrawPos().x,
			pDispPos->GetDrawPos().y,
			ExtTextOutOption() & ~(bTrans? ETO_OPAQUE: 0),
			&rcClipBottom,
			L"o",
			1,
			pcView->GetTextMetrics().GetDxArray_AllHankaku()
		);
		
		//�㔼���͕��ʂ̋󔒂ŏo�́i"o"�̏㔼���������j
		CMyRect rcClipTop=rcClip;
		rcClipTop.bottom=rcClip.top+pcView->GetTextMetrics().GetHankakuHeight()/2;
		::ExtTextOutW_AnyBuild(
			gr,
			pDispPos->GetDrawPos().x,
			pDispPos->GetDrawPos().y,
			ExtTextOutOption() & ~(bTrans? ETO_OPAQUE: 0),
			&rcClipTop,
			L" ",
			1,
			pcView->GetTextMetrics().GetDxArray_AllHankaku()
		);
#endif  //REI_MOD_HAN_SPACE
	}

	//�ʒu�i�߂�
	pDispPos->ForwardDrawCol(1);
}
