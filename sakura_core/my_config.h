#ifndef MY_CONFIG_H
#define MY_CONFIG_H

// clang-format off

// 2016.7.28, 2.1.1.4(r3825)�x�[�X
// 2016.7.29, 2.2.0.1(r4011)�x�[�X

/* --------------------------------------------------------------------------
����肽������.

- [x] #1. 2015.6.1
 �������A�I�����Ă��镶���񂪂������ꍇ�ɐ��K�\���Ƀ`�F�b�N�������Ă�����
 ���K�\���Ŏg�p����L���������I�ɃN�H�[�g����.
 PHP�� preg_quote �݂����Ȃ���.

- [ ] #2. 2015.6.2
 ���������񂪂���s�ԍ��̐F��ύX������.

- [ ] #3. 2015.6.5
 bug?, �P����폜����ہA��u�I����ԂɂȂ�

- [x] #4. 2015.6.5
 bug, �J�[�\���ړ������Ƃ��Ɉړ��O�̏�Ԃ���u�c��
 \view\CEditView_Scroll.cpp:void CEditView::ScrollDraw() �����₵��?
 ScrollWindowEx() �ōs����X�V���Ȃ�Ƃ�����΂���?

- [x] #5. 2015.6.5
 Grep�Ώۂ̃t�H���_�̕����w��.

- [ ] #6. 2015.6.8
 �N�����A�ŋߎg�����t�@�C���̐���. ���݂��Ȃ��t�@�C���̍��ڂ�r��.

- [x] #7. 2015.6.9 *pending
 �f�t�H���g�̐��K�\�����C�u�������g�p����.
 �� re2 http://naoyat.hatenablog.jp/entry/2012/01/12/220812  
 �� SRELL http://www.akenotsuki.com/misc/srell/  

- [ ] #8. 2015.6.9
 �E�B���h�E�ꗗ, DEL�ŃE�B���h�E�����.
 \window\CTabWnd.cpp : CTabWnd::TabListMenu : TrackPopupMenu()
 �� ���łɃp�b�`���� [patchunicode:#1072] �E�B���h�E�ꗗ�_�C�A���O 

- [x] #9. 2015.6.10
 �X�e�[�^�X�o�[�Ƀ^�C�v����\��.
 \window\CMainStatusBar.cpp : CMainStatusBar::CreateStatusBar()
 \apiwrap\CommonControl.h : ApiWrap::StatusBar_SetParts
 \window\CEditWnd.cpp : CEditWnd::OnSize2 : nStArr �J�����T�C�Y

- [x] #10. 2015.6.11
 ini�����W�X�g���ɂ��ǂݏ����ɂ���.

- [ ] #11. 2015.6.30
 �R�����g���̌���������̓R�����g�F�̉e�����󂯂�.

- [ ] #12. 2015.7.2
 �J���Ă���^�u�̃t�@�C�������R�s�[.

- [ ] #14. 2015.8.4
 �^�X�N�o�[�A�C�R���̂����
 \window\CTabWnd.cpp:CTabWnd::ShowHideWindow()
 SendMessageTimeout() �� TabWnd_ActivateFrameWindow() �̊֌W

- [ ] #16. 2015.8.25
 �^�u��؂�ւ����ہA�^�u���N���b�N�����ʒu�Ƃ͕ʂ̈ʒu�ɃX�N���[��?����̂𒼂�����
 LRESULT CTabWnd::OnTabLButtonUp( WPARAM wParam, LPARAM lParam )
 void CTabWnd::ShowHideWindow( HWND hwnd, BOOL bDisp )
 void CTabWnd::AdjustWindowPlacement( void )
 void CTabWnd::LayoutTab( void )
 2001�N12��: TM SOFT(http://tm-soft.seesaa.net/archives/20011218-1.html)
 TabCtrl_GetItemRect()

- [x] #17. 2015.11.23
 �u���̂Ƃ��A�u����{�b�N�X�ɒu���O�̃e�L�X�g������  

- [ ] #18. 2016.12.13
 �e�_�C�A���O�{�b�N�X�̈ʒu���f�X�N�g�b�v�̒����ł͂Ȃ�  
 �Ăяo�����E�B���h�E�̒����A�܂��͍���ɔz�u����  
  ��Grep������
  ���O���R�}���h���s�_�C�A���O

- [ ] #19. 2017.1.5
 �R�����g���̋󔒃^�u������������̂Ƃ��A�w�i�F���󔒃^�u�ɔ��f����Ȃ�
 REI_MOD_SP_COLOR �̏C���ɂ��e��  

- [x] #20. 2017.1.10
 �I�𒆂̃e�L�X�g�̑����͌��̃e�L�X�g��D�悷��

- [ ] #21. 2017.1.10
 bug?, ��ʏ�[���[�ŃL�����b�g���������^�C�~���O�ŃX�N���[��������ƃL�����b�g���������܂܃X�N���[������

- [ ] #22. 2017.3.3
 �e�L�X�g�`��A�E�[��������
 [patchunicode:#588]�����ĂĖڗ����Ȃ��͂��Ă���
 sakura_core\view\CEditView_Paint.cpp
 pcFigureManager->GetTextFigure().DrawImp(pInfo, nPosBgn, pInfo->GetPosInLogic() - nPosBgn);

-------------------------------------------------------------------------- */

// �� �t�H���g
//   https://support.microsoft.com/ja-jp/kb/74299
//   http://d.hatena.ne.jp/itoasuka/20100104/1262585983
//
// lf.lfHeight = DpiPointsToPixels(-10); // ��DPI�Ή��i�|�C���g������Z�o�j

//-------------------------------------------------------------------------
// �f�o�b�O�p
//-------------------------------------------------------------------------

// �f�o�b�O�o�� 2015.3.24  
#define REI_OUTPUT_DEBUG_STRING 0


//-------------------------------------------------------------------------
// �ҏW
//-------------------------------------------------------------------------

// �����X�N���[���̕ύX  
//  - �X�N���[���J�n�}�[�W���� 1 �ɕύX�B��ʂ̒[�ŃX�N���[���J�n 2014.5.7  
//  - �X�N���[������ 16 �ɐݒ�B��x�ɑ傫���ړ����邱�ƂŌ��₷������ (�����̓������Q��) 2015.9.2  
#define REI_MOD_HORIZONTAL_SCR 16

// �����X�N���[���̕ύX
//  - �X�N���[���}�[�W���s�𒲐�
#define REI_MOD_VERTICAL_SCR 0

// �^�u�����̃^�u�Ƌ󔒂̐؂�ւ���ǉ�
//  - S_ChangeTabWidth�}�N���ɕ��̒l��n���ƃ^�u�����̐؂�ւ�
#define REI_MOD_CHANGE_TAB_WIDTH_MACRO 1


//-------------------------------------------------------------------------
// �\��
//-------------------------------------------------------------------------

// �ύX�h�L�������g�^�u���J���[��ݒ�
// (REG/ModifiedTabCaptionColor:0x00BBGGRR)
#define REI_MOD_MODIFIED_TAB_CAPTION_COLOR (0x000000d8)

// �s�𒆉����낦�ɂ��� 2014.3.26 - 2015.7.24  
//  - �f�t�H���g�ł͍s�͏㑵���ɂȂ��Ă���̂ōs�Ԃ͉��ɕt�������  
//  - �L�����b�g���s�Ԋ܂ލ����ɂ���  
#define REI_LINE_CENTERING 1

// EOF�݂̂̍s�ɍs�ԍ���\�� 2017.3.10
#define REI_MOD_EOFLN_DISP_NR 1

// �L�����b�g�̕ύX 2012.10.11  
// 0: �ύX�Ȃ�
// 1-10: �L�����b�g�T�C�Y
// 11: 1�o�C�g�R�[�h�̎���1px�A2�o�C�g�R�[�h�̎���2px  
// 12: ���p���͂̎���1px�A�S�p���͂̎���2px 2015.8.26  
// (REG/CaretType:2)
#define REI_MOD_CARET 2

// ���p�󔒕����� "�" �ŕ`�� 2013.6.2  
#define REI_MOD_HAN_SPACE 1

// �S�p�󔒕���
#define REI_MOD_ZEN_SPACE 

// �^�u�����i���j���V(>)�͕\�����Ȃ� 2015.5.25  
//  - �u�������v�u�Z�����v���u���v 2016.8.19
#define REI_MOD_TAB 1

// �J�[�\���s�A���_�[���C��
//  - ���[���� 2015.1.30  
#define REI_MOD_CUR_UL 1

// �I��̈�̐F��ύX  
//  - �e�L�X�g�Ɣw�i�̃u�����h���ݒ� 2015.6.5  
//  - �I�����̃e�L�X�g�����i�����A�����j�ɑI��̈�ł͂Ȃ����݂̃e�L�X�g���g�p����
#define REI_MOD_SELAREA 1
  // �I��̈�̃u�����h��[%] 2015.6.5  
  // (REG/SelectAreaBlendPer:0x00000064)
  #define REI_MOD_SELAREA_BLEND_PER (/*Text=*/(0 << 8) | /*Back=*/(100))

// ��TAB,���s�̃J���[��ύX 2015.6.5  
//  - ���݂̃e�L�X�g�F�ƌ��݂̔w�i�F���u�����h���� (��TAB�̃J���[�ݒ�͖�������܂�) 2015.6.8  
//    �Ώۂ͋�TAB�ȂǂŁA�R���g���[���R�[�h�ɂ͓K�p����܂���  
#define REI_MOD_SP_COLOR 1
  // ��TAB ���݂̃J���[�̃u�����h��[%] 2015.6.5  
  // (REG/WhiteSpaceBlendPer:0x0000001E)
  #define REI_MOD_SP_BLEND_PER (30)
//						     
						     

// �J���[�ݒ�̕ύX 2016.6.25  
//  - �J�[�\���ʒu�c���A�܂�Ԃ��L�����e�L�X�g�J���[�̂�
#define REI_MOD_COLOR_STRATEGY 1

// �R�����g�s�̏C�� 2016.12.27
// 0x01: ���s�ȍ~���J���[��L���ɂ���
#define REI_MOD_COMMENT 1

// �܂�Ԃ��L���\�����ɐ܂�Ԃ��ʒu�̐��������Ȃ� 2016.6.25  
// (REG/NoWrapLine:1)
#define REI_MOD_WRAP_LINE 1

// �X�e�[�^�X�o�[��ύX 2015.6.10  
//  - �^�C�v����\��  
//  - �^�u�T�C�Y��\��  
//  - REC�̐F��Ԃɂ���  
//  - �u? �s ? ���v���u(?, ?)�v�ɕύX�A���[�ɕ\��  
#define REI_MOD_STATUSBAR 1

//-------------------------------------------------------------------------
// �@�\
//-------------------------------------------------------------------------

// �v���t�@�C���̓ǂݏ����Ƀ��W�X�g�����g�p����
//  - ���W�X�g���L�[���Ȃ��ꍇ��ini�t�@�C������ǂݍ���
//  - �o�[�W�����A�b�v���̃o�b�N�A�b�v�t�@�C���쐬�͍s��Ȃ�
// (REG/NoReadProfilesFromRegistry:0) 1�ɂ���ƃ��W�X�g������ǂݍ��܂Ȃ��Ȃ�܂�
// (REG/NoWriteProfilesToRegistry:0) 1�ɂ���ƃ��W�X�g���ɏ������܂Ȃ��Ȃ�܂�
#define REI_USE_REGISTRY_FOR_PROFILES 1

// �J����Ă���t�@�C�������ȊǗ�����O��ő��d�I�[�v���̋��� 2013.6.19  
//  - Shift�������Ȃ���t�@�C���h���b�v�ő��d�I�[�v��  
#define REI_MULTIPLE_OPEN_FILES 1

// �ő吔��ύX 2013.10.2, 2016.12.13  
// \sakura_core\config\maxdata.h
// (REG/RecentSearchKeyMax:16)
// (REG/RecentReplaceKeyMax:16)
// (REG/RecentGrepFileMax:8)
// (REG/RecentGrepFolderMax:16)
#define REI_CHG_MAXDATA 1

// ���K�\�������̍ہA����������̐��K�\���L�����N�H�[�g���� 2015.6.1  
// (REG/RegexpAutoQuote:1)
#define REI_MOD_SEARCH_KEY_REGEXP_AUTO_QUOTE 1

// Grep�ύX 2015.8.24  
//  - Grep����t�H���_�̎w��� UI�I�ɑ��₷
//    ���J���}�ŋ�؂��蕪����Ă������������₷�����A�����Ǘ������₷��.
//  - �w��t�H���_�����ׂă`�F�b�N���͂����Ɓu���ݕҏW���̃t�@�C�����猟���v�Ƃ���
//  - �u���ݕҏW���̃t�@�C�����猟���v���`�F�b�N�������̏�Ԃ�ێ����Ȃ��悤�ɂ���
//    ���{���́u���ݕҏW���̃t�@�C�����猟���v���g�p����ƁA
//      �e�����󂯂鑼�̃`�F�b�N�{�b�N�X�̏�Ԃ��ύX�����܂ܖ߂�Ȃ��̂���������.
//  - �t�@�C��(�t�B���^)�w��̓t�H���_�̂��Ƃɒu�� (�t�H���_�̂ق����ύX����@���������)  
//  - �������̃_�C�A���O�𒆉��ɒu���Ȃ��i���A���^�C�����Ɍ��Â炢�j
#define REI_MOD_GREP 1

// �u���ύX 2016.8.4  
// (REG/ReplaceTextToText:1)
//  - �u���㕶����ɒu���O�������ݒ肷��  
#define REI_MOD_REPLACE 1

// �t�H���_�I���_�C�A���O��ύX 2015.8.25  
//  - CLSID_FileOpenDialog���g�p����  
//    �g�p����ɂ� Vista�ȍ~�ɂ���K�v������  
//      WINVER=0x0500;_WIN32_WINNT=0x0500;_WIN32_IE=0x0501  
//                          ��  
//      WINVER=0x0601;_WIN32_WINNT=0x0601;_WIN32_IE=0x0800  
// [http://eternalwindows.jp/installer/originalinstall/originalinstall02.html]
// [https://msdn.microsoft.com/ja-jp/library/windows/desktop/ff485843(v=vs.85).aspx]
#define REI_MOD_SELECTDIR 1

// �_�C���N�g�^�O�W�����v�ꗗ��ύX
//  - �\������J�����̑I�ʂƕ��ёւ� 2015.8.27  
//  - ��ɒ����ɕ\��(�T�C�Y�͌p��) 2017.2.15
#define REI_MOD_DIRECTTAGJUMP 1

// �O���R�}���h���s�_�C�A���O��ύX 2016.12.20  
//  - �E�B���h�E�̈ʒu�����܂����ʒu�ɂł�悤�ɂ���
#define REI_MOD_EXECDLG 1

// �A�E�g���C����̓_�C�A���O�̕ύX 2016.12.14  
//  - �t�H���g�����C���t�H���g�ɂ���
//  - �h�b�L���O���ɃE�B���h�E�J���[���e�L�X�g�ɍ��킹�Ȃ�
// (REG/OutlineDockColorDefault:0)
#define REI_MOD_OUTLINEDLG 1

// �o�[�W�������_�C�A���O�̕ύX 2017.3.15
#define REI_MOD_VERDLG 1

// �E�F�C�g�J�[�\����ύX 2015.7.9  
//  - �ꕔ�A�������ʒu�ɏC��  
//  - ������폜���ɕ\�����Ȃ��i�A���h�D�̂Ƃ��Ȃǁj  
#define REI_MOD_WAITCUESOR 1

// SetMainFont���C��
//  - ����pt��ǉ��A�f�t�H���g��10�|�C���g�ɂ��� 2017.3.7
#define REI_MOD_SET_MAIN_FONT 1


//-------------------------------------------------------------------------
// �C��
//-------------------------------------------------------------------------

// �����_�C�A���O�́u���K�\���v���e�����󂯂Ȃ��悤�ɂ���
//  - �����}�[�N�؂�ւ��� 2015.6.1  
//  - �C���N�������^���T�[�`�� 2016.12.14
#define REI_FIX_SEARCH_KEEP_REGEXP 1

// �s�ԍ�����\���Ńu�b�N�}�[�N���\���̂Ƃ��u�b�N�}�[�N�͐��ŕ`�悷�� 2017.1.13
#define REI_FIX_DRAW_BOOKMARK_LINE_NOGYOU 1

// ���[���[��\�����́u���[���[�ƃe�L�X�g�̌��ԁv�𖳎����� 2016.12.28
#define REI_FIX_RULER_HIDE_IGNORE_BOTTOM_SPACE 0

// �s�ԍ��c�����s�ԍ��̐F�ŕ`�悷�� 2016.12.21
#define REI_FIX_LINE_TERM_TYPE 1

// �J�[�\���㉺�ړ����Ɏ��̏���?�̂Ƃ��ɉ�ʂ̍X�V���Ԃɍ��킸�ɕ`�悪����� 2015.8.4  
//  - �L�[���s�[�g������  
//  - ���ŕ`���p�ɂɍs���A�v���������Ă���  
// ��UpdateWindow() ���Ăяo�����Ƃňꎞ�Ή�  
#define REI_FIX_CALL_CURSOR_MOVE_UPDATEWINDOW 1

// �J�[�\���ړ����̂�������b��őΏ� 2015.8.4  
//  - �X�N���[���������� ScrollWindowEx() �ƍĕ`��̓������Ƃ�Ă��Ȃ�?  
//  - MacType�Ȃǂ��g�p����ƕ`��̕��ׂ������Ȃ茰���ɂȂ�B�g��Ȃ��ꍇ�͍����ɂ��ƍČ�����  
// ��MoveCursor()�ɏ������܂Ƃ߂Ă��΂炭�l�q�� 2015.8.5  
#define REI_FIX_CURSOR_MOVE_FLICKER 1

// �^�u�E�B���h�E�̏������C�� 2015.8.28  
//  - ���Ȃ��Ă��������������Ƃ��Ȃ��悤�ɂ���  
//  - 1. �͂��߂Đ؂�ւ����^�u�������ɂ���ꍇ�Ƀ^�u�̈ʒu���E�ɃY������ (�Ή���)  
//    2. Refresh()�̏������֌W���Ă���悤��  
//    3. �ǂ���炷�ׂẴE�B���h�E���^�u�R���g���[���������Ă��ă^�u���ύX����邽�тɓ������Ă���悤��  
//       2.�̋������N����̂͂��̂���  
//       ����Ȃ�΃^�u�̈ʒu�𓯊����邱�Ƃ͂ł��Ȃ����H  
#define REI_FIX_TABWND 


//
//#define USE_SSE2

// clang-format on

#include <windows.h>
#include <memory>
#include <string>
//#include <locale>
//#include <codecvt>
//#include <vector>
#include <errno.h>

//------------------------------------------------------------------
//! ���W�X�g���L�[�̓ǂݎ��(DWORD)
//! @param key_name
//! @param defValue
//------------------------------------------------------------------
inline DWORD RegGetDword(LPCTSTR key_name, DWORD defValue) {
  HKEY hKey;
  DWORD dwType = REG_DWORD;  // REG_SZ;
  DWORD dwByte = 4;
  DWORD dwValue;
  LONG rc;

  std::wstring subkey = L"Software\\sakura_REI";

  rc = RegOpenKeyEx(HKEY_CURRENT_USER,  //�e�L�[
                    subkey.c_str(),     //�T�u�L�[
                    0,                  //��Ƀ[��
                    KEY_ALL_ACCESS,     //�Z�L�����e�B�}�X�N
                    &hKey);             //�L�[�̃n���h��

  if (rc != ERROR_SUCCESS) return defValue;

  rc = RegQueryValueEx(hKey,              //�L�[�̃n���h��
                       key_name,          //�ǂݎ��L�[�̖��O
                       NULL,              //��� NULL
                       &dwType,           //�f�[�^�̃^�C�v
                       (BYTE *)&dwValue,  //�󂯎��̈�
                       &dwByte);          //�̈�̃o�C�g��(�󂯎�����o�C�g��)

  RegCloseKey(hKey);

  if (rc != ERROR_SUCCESS) {
    return defValue;
  } else {
    return dwValue;
  }
}

//------------------------------------------------------------------
//! ���W�X�g���L�[�̓ǂݎ��(SZ)
//! @param key_name
//! @param out
//------------------------------------------------------------------
inline bool RegGetString(LPCTSTR key_name, char *out) {
  HKEY hKey;
  DWORD dwType;
  DWORD dwByte;
  LONG rc;

  std::wstring subkey = L"Software\\sakura_REI";

  rc = RegOpenKeyEx(HKEY_CURRENT_USER,  //�e�L�[
                    subkey.c_str(),     //�T�u�L�[
                    0,                  //��Ƀ[��
                    KEY_ALL_ACCESS,     //�Z�L�����e�B�}�X�N
                    &hKey);             //�L�[�̃n���h��

  if (rc != ERROR_SUCCESS) return false;

  rc = RegQueryValueEx(hKey,      //�L�[�̃n���h��
                       key_name,  //�ǂݎ��L�[�̖��O
                       NULL,      //��� NULL
                       &dwType,   //�f�[�^�̃^�C�v
                       NULL,      //�󂯎��̈�
                       &dwByte);  //�̈�̃o�C�g��(�󂯎�����o�C�g��)

  if (rc != ERROR_SUCCESS) return false;

  rc = RegQueryValueEx(hKey,                  //�L�[�̃n���h��
                       key_name,              //�ǂݎ��L�[�̖��O
                       NULL,                  //��� NULL
                       &dwType,               //�f�[�^�̃^�C�v
                       (LPBYTE)(LPCTSTR)out,  //�󂯎��̈�
                       &dwByte);              //�̈�̃o�C�g��(�󂯎�����o�C�g��)

  RegCloseKey(hKey);

  if (rc != ERROR_SUCCESS) {
    return false;
  } else {
    return true;
  }
}

//------------------------------------------------------------------
//! �t�@�C�����̎擾
//! @param path �p�X��
//------------------------------------------------------------------
inline std::wstring ExtractFileName(const std::wstring &path) {
  std::wstring fname;
  size_t pos = path.rfind('\\');
  if (pos != std::wstring::npos) {
    return path.substr(pos + 1, path.size() - pos - 1);
  } else {
    pos = path.rfind('/');
    if (pos != std::wstring::npos) {
      return path.substr(pos + 1, path.size() - pos - 1);
    }
  }
  return path;
}

//------------------------------------------------------------------
//! ���W�X�g���L�[�̊m�F
//! @param profile_name �v���t�@�C����
//! @return true:���݂���, false:���݂��Ȃ�
//------------------------------------------------------------------
inline bool IsExistProfileReg(const std::wstring &profile_name) {
  HKEY hKey;
  LONG rc;

  std::wstring fname = ExtractFileName(profile_name);
  std::wstring subkey = L"Software\\" + fname;

  rc = RegOpenKeyEx(HKEY_CURRENT_USER,  //�e�L�[
                    subkey.c_str(),     //�T�u�L�[
                    0,                  //��Ƀ[��
                    KEY_ALL_ACCESS,     //�Z�L�����e�B�}�X�N
                    &hKey);             //�L�[�̃n���h��

  if (rc != ERROR_SUCCESS) return false;

  RegCloseKey(hKey);

  return true;
}

//------------------------------------------------------------------
//! ���W�X�g���L�[�̓ǂݎ��(SZ)
//! @param profile_name �v���t�@�C����
//! @param section_name �Z�N�V������
//! @param key_name �L�[��
//! @param data �f�[�^
//------------------------------------------------------------------
inline bool GetRegProfileString(const std::wstring &profile_name, const std::wstring &section_name,
                                const std::wstring &key_name, std::wstring &data) {
  HKEY hKey;
  DWORD dwType = REG_SZ;
  DWORD dwByte = 1024;
  LONG rc;

  std::wstring fname = ExtractFileName(profile_name);
  std::wstring subkey = L"Software\\" + fname + L"\\" + section_name;

  data = L"";

  rc = RegOpenKeyEx(HKEY_CURRENT_USER,  //�e�L�[
                    subkey.c_str(),     //�T�u�L�[
                    0,                  //��Ƀ[��
                    KEY_ALL_ACCESS,     //�Z�L�����e�B�}�X�N
                    &hKey);             //�L�[�̃n���h��

  if (rc != ERROR_SUCCESS) return false;

  rc = RegQueryValueExW(hKey,              //�L�[�̃n���h��
                        key_name.c_str(),  //�ǂݎ��L�[�̖��O
                        NULL,              //��� NULL
                        &dwType,           //�f�[�^�̃^�C�v
                        NULL,              //�󂯎��̈�
                        &dwByte);          //�̈�̃o�C�g��(�󂯎�����o�C�g��)

  if (rc != ERROR_SUCCESS) return false;

  if (dwType == REG_DWORD) {
    int i;
    rc = RegQueryValueExW(hKey,              //�L�[�̃n���h��
                          key_name.c_str(),  //�ǂݎ��L�[�̖��O
                          NULL,              //��� NULL
                          &dwType,           //�f�[�^�̃^�C�v
                          (BYTE *)&i,        //�󂯎��̈�
                          &dwByte);          //�̈�̃o�C�g��(�󂯎�����o�C�g��)

    RegCloseKey(hKey);

    if (rc != ERROR_SUCCESS) {
      return false;
    } else {
      data.assign(std::to_wstring(i));
      return true;
    }

  } else {
    wchar_t *buffer = new wchar_t[dwByte + 1];

    rc = RegQueryValueExW(hKey,              //�L�[�̃n���h��
                          key_name.c_str(),  //�ǂݎ��L�[�̖��O
                          NULL,              //��� NULL
                          &dwType,           //�f�[�^�̃^�C�v
                          (LPBYTE)buffer,    //�󂯎��̈�
                          &dwByte);          //�̈�̃o�C�g��(�󂯎�����o�C�g��)

    RegCloseKey(hKey);

    if (rc != ERROR_SUCCESS) {
      delete[] buffer;
      return false;
    } else {
      if (dwByte == 0) {
        data.assign(L"");
      } else {
        buffer[dwByte] = L'\0';
        data.assign(buffer);
      }
      delete[] buffer;
      return true;
    }
  }
}

//------------------------------------------------------------------
//! ���W�X�g���L�[�̏�������(SZ)
//! @param profile_name �v���t�@�C����
//! @param section_name �Z�N�V������
//! @param key_name �L�[��
//! @param data �f�[�^
//------------------------------------------------------------------
inline bool SetRegProfileString(const std::wstring &profile_name, const std::wstring &section_name,
                                const std::wstring &key_name, const std::wstring &data) {
  HKEY hKey;
  DWORD dwType = REG_SZ;
  DWORD dwDisposition;  //�V�K�쐬:REG_CREATED_NEW_KEY
                        //����:REG_OPENED_EXISTING_KEY
  LONG rc;

  std::wstring fname = ExtractFileName(profile_name);
  std::wstring subkey = L"Software\\" + fname + L"\\" + section_name;

  rc = RegCreateKeyEx(HKEY_CURRENT_USER,        //�e�L�[
                      subkey.c_str(),           //�T�u�L�[
                      0,                        //��Ƀ[��
                      NULL,                     //
                      REG_OPTION_NON_VOLATILE,  //�ċN�����Ă������Ȃ��ݒ�
                      KEY_ALL_ACCESS,           //�Z�L�����e�B�}�X�N
                      NULL,                     //
                      &hKey,                    //
                      &dwDisposition);

  if (rc != ERROR_SUCCESS) return false;

  int i = 0;
  bool is_num = false;

  if (!data.empty()) {
    wchar_t *endptr;
    errno = 0;
    i = wcstol(data.c_str(), &endptr, 10);
    is_num = !(*endptr != L'\0' || (i == INT_MAX && errno == ERANGE));
  }

  if (is_num) {
    rc = RegSetValueEx(hKey,              //�L�[�̃n���h��
                       key_name.c_str(),  //�ǂݎ��L�[�̖��O
                       NULL,              //��� NULL
                       REG_DWORD,         //�f�[�^�̃^�C�v
                       (CONST BYTE *)&i,  //�������ޗ̈�
                       sizeof(DWORD));    // data�̃T�C�Y���w�肷��
  } else {
    rc = RegSetValueEx(hKey,                                 //�L�[�̃n���h��
                       key_name.c_str(),                     //�ǂݎ��L�[�̖��O
                       NULL,                                 //��� NULL
                       REG_SZ,                               //�f�[�^�̃^�C�v
                       (CONST BYTE *)(LPCTSTR)data.c_str(),  //�������ޗ̈�
                       (int)data.length() * 2);              // data�̃T�C�Y���w�肷��
  }

  RegCloseKey(hKey);

  if (rc != ERROR_SUCCESS) {
    return false;
  } else {
    return true;
  }
}

#endif /* MY_CONFIG_H */
