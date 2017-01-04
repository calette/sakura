/*!	@file
	@brief �������v���Ԃ̌v���N���X

	�f�o�b�O�ړI�ŗp����

	@author Norio Nakatani
	@date 1998/03/06  �V�K�쐬
*/
/*
	Copyright (C) 1998-2001, Norio Nakatani
	Copyright (C) 2002, genta

	This source code is designed for sakura editor.
	Please contact the copyright holder to use this code for other purpose.
*/

#include "StdAfx.h"
#include <MMSystem.h>
#include "debug/CRunningTimer.h"
#include "_main/global.h"

#ifdef USE_RUNTIMER

#if !defined(_DEBUG) && defined(USE_RUNTIMER)
// Debug1.h
void DebugOutW( LPCWSTR lpFmt, ...);
void DebugOutA( LPCSTR lpFmt, ...);
#endif
#ifdef _UNICODE
#define DebugOutT DebugOutW
#else
#define DebugOutT DebugOutA
#endif

#pragma comment(lib, "winmm.lib")

int CRunningTimer::m_nNestCount = 0;

CRunningTimer::CRunningTimer( const char* pszText )
{
	timeBeginPeriod(1);
	Reset();
	if( pszText != NULL )
		strcpy( m_szText, pszText );
	else
		m_szText[0] = '\0';
	m_nDeapth = m_nNestCount++;
	DebugOutT( _T("%3d:\"%hs\" : Enter \n"), m_nDeapth, m_szText );
	return;
}


CRunningTimer::~CRunningTimer()
{
	WriteTrace("Exit Scope");
	m_nNestCount--;
	timeEndPeriod(1);
	return;
}


void CRunningTimer::Reset()
{
	m_nStartTime = timeGetTime();
}


DWORD CRunningTimer::Read()
{
	return timeGetTime() - m_nStartTime;
}

/*!
	@date 2002.10.15 genta
*/
void CRunningTimer::WriteTrace(const char* msg) const
{
	DebugOutT( _T("%3d:\"%hs\", %d�_�b : %hs\n"), m_nDeapth, m_szText, timeGetTime() - m_nStartTime, msg );
}
#endif // USE_RUNTIMER


