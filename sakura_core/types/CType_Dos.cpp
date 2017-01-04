/*
	Copyright (C) 2008, kobake

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

int g_nKeywordsIdx_BAT = -1;

/* MS-DOS�o�b�`�t�@�C�� */
void CType_Dos::InitTypeConfigImp(STypeConfig* pType)
{
	//���O�Ɗg���q
	_tcscpy( pType->m_szTypeName, _T("MS-DOS�o�b�`�t�@�C��") );
	_tcscpy( pType->m_szTypeExts, _T("bat") );

	//�ݒ�
	pType->m_cLineComment.CopyTo( 0, L"REM ", -1 );	/* �s�R�����g�f���~�^ */
	pType->m_nKeyWordSetIdx[0] = g_nKeywordsIdx_BAT;

	pType->m_eDefaultOutline = OUTLINE_FILE;		/* �A�E�g���C����͕��@ */
	auto_strcpy( pType->m_szOutlineRuleFilename, _T("Keyword\\bat.rl") );

	pType->m_KeyHelpArr[0].m_bUse = true;
	auto_strcpy( pType->m_KeyHelpArr[0].m_szAbout, _T(";�o�b�`�t�@�C���̃L�[���[�h�w���v��`") );
	auto_strcpy( pType->m_KeyHelpArr[0].m_szPath, _T("Keyword\\bat_win2k.khp") );
	pType->m_bUseKeyWordHelp = true;		// �����I���@�\�̎g�p��
	pType->m_nKeyHelpNum = 1;				// �o�^������
}



#ifdef BUILD_OPT_IMPKEYWORD
const wchar_t* g_ppszKeywordsBAT[] = {
	L"PATH",
	L"PROMPT",
	L"TEMP",
	L"TMP",
	L"TZ",
	L"CONFIG",
	L"COMSPEC",
	L"DIRCMD",
	L"COPYCMD",
	L"winbootdir",
	L"windir",
	L"DIR",
	L"CALL",
	L"CHCP",
	L"RENAME",
	L"REN",
	L"ERASE",
	L"DEL",
	L"TYPE",
	L"REM",
	L"COPY",
	L"PAUSE",
	L"DATE",
	L"TIME",
	L"VER",
	L"VOL",
	L"CD",
	L"CHDIR",
	L"MD",
	L"MKDIR",
	L"RD",
	L"RMDIR",
	L"BREAK",
	L"VERIFY",
	L"SET",
	L"EXIT",
	L"CTTY",
	L"ECHO",
	L"@ECHO",	//Oct. 31, 2000 JEPRO '@' �������\�ɂ����̂Œǉ�
	L"LOCK",
	L"UNLOCK",
	L"GOTO",
	L"SHIFT",
	L"IF",
	L"FOR",
	L"DO",	//Nov. 2, 2000 JEPRO �ǉ�
	L"IN",	//Nov. 2, 2000 JEPRO �ǉ�
	L"ELSE",	//Nov. 2, 2000 JEPRO �ǉ� Win2000�Ŏg����
	L"CLS",
	L"TRUENAME",
	L"LOADHIGH",
	L"LH",
	L"LFNFOR",
	L"ON",
	L"OFF",
	L"NOT",
	L"ERRORLEVEL",
	L"EXIST",
	L"NUL",
	L"CON",
	L"AUX",
	L"COM1",
	L"COM2",
	L"COM3",
	L"COM4",
	L"PRN",
	L"LPT1",
	L"LPT2",
	L"LPT3",
	L"CLOCK",
	L"CLOCK$",
	L"CONFIG$"
};
int g_nKeywordsBAT = _countof(g_ppszKeywordsBAT);
#endif
