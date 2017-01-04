/*!	@file
	@brief �������v���Ԃ̌v���N���X

	�f�o�b�O�ړI�ŗp����

	@author Norio Nakatani
	@date 1998/03/06  �V�K�쐬
*/
/*
	Copyright (C) 1998-2001, Norio Nakatani
	Copyright (C) 2002, genta

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

#ifndef SAKURA_CRUNNINGTIMER_H_
#define SAKURA_CRUNNINGTIMER_H_

#include <windows.h>
// RunningTimer�Ōo�ߎ��Ԃ̑�����s���ꍇ�ɂ̓R�����g���O���Ă�������
//#define TIME_MEASURE

// 2014.11.21 Moca Release���[�h�ł�CRunningTimer���g�����߂̒�`
//#define USE_RUNTIMER


#if defined(TIME_MEASURE) || defined(_DEBUG)
#ifndef USE_RUNTIMER
#define USE_RUNTIMER 1
#endif
#endif

/*-----------------------------------------------------------------------
�N���X�̐錾
-----------------------------------------------------------------------*/
#ifdef USE_RUNTIMER
#define USE_RELPRINT2 1
/*!
	@brief �������v���Ԃ̌v���N���X

	��`�̐؂�ւ��݂̂Ń^�C�}�[��ON/OFF���s����悤�ɂ��邽�߁C
	���̃N���X�𒼐ڎg�킸�C���ɂ���MY_RUNNINGTIMER��MY_TRACETIME��
	�g�����ƁD

	@date 2002/10/16  genta WriteTrace�y�у}�N���ǉ�
*/
class CRunningTimer
{
public:
	/*
	||  Constructors
	*/
	CRunningTimer( const char* Text = NULL);
	~CRunningTimer();

	/*
	|| �֐�
	*/
	void Reset();
	DWORD Read();
	
	void WriteTrace(const char* msg = "") const;

protected:
	DWORD	m_nStartTime;
	char	m_szText[100];	//!< �^�C�}�[��
	int		m_nDeapth;	//!< ���̃I�u�W�F�N�g�̃l�X�g�̐[��

	static int m_nNestCount;
};
#endif // USE_RUNTIMER

//	Oct. 16, 2002 genta
//	#ifdef _DEBUG�`#endif�Œ���͂܂Ȃ��Ă��ȒP�Ƀ^�C�}�[��ON/OFF���s�����߂̃}�N��
#ifdef TIME_MEASURE
  #define MY_TRACETIME(c,m) (c).WriteTrace(m)
  #define MY_RUNNINGTIMER(c,m) CRunningTimer c(m)
#else
  #define MY_TRACETIME(c,m)
  #define MY_RUNNINGTIMER(c,m)
#endif

// Release��USE_RUNTIMER�̂Ƃ������s����p
#ifdef USE_RUNTIMER
  #define MY_TRACETIME2(c,m) (c).WriteTrace(m)
  #define MY_RUNNINGTIMER2(c,m) CRunningTimer c(m)
#else
  #define MY_TRACETIME2(c,m)
  #define MY_RUNNINGTIMER2(c,m)
#endif

///////////////////////////////////////////////////////////////////////
#endif /* SAKURA__CRUNNINGTIMER_H_ */



