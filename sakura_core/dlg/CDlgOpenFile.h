﻿/*!	@file
	@brief ファイルオープンダイアログボックス

	@author Norio Nakatani
	@date	1998/08/10 作成
*/
/*
	Copyright (C) 1998-2001, Norio Nakatani
	Copyright (C) 2001, genta
	Copyright (C) 2002, YAZAKI, Moca
	Copyright (C) 2003, ryoji
	Copyright (C) 2004, genta, MIK
	Copyright (C) 2005, ryoji
	Copyright (C) 2006, Moca, ryoji

	This source code is designed for sakura editor.
	Please contact the copyright holder to use this code for other purpose.
*/

#ifndef _CDLGOPENFILE_H_
#define _CDLGOPENFILE_H_

#include <CommDlg.h>
#include <boost/container/vector.hpp>
#include "util/design_template.h"
#include "CEol.h"
#include "basis/CMyString.h"
#include "dlg/CDialog.h"

struct SLoadInfo;	// doc/CDocListener.h
struct SSaveInfo;	// doc/CDocListener.h
struct OPENFILENAMEZ;
class CDlgOpenFileMem;


/*!	ファイルオープンダイアログボックス

	@date 2002.2.17 YAZAKI CShareDataのインスタンスは、CProcessにひとつあるのみ。
*/
class CDlgOpenFile
{
public:
	//コンストラクタ・デストラクタ
	CDlgOpenFile();
	~CDlgOpenFile();
	void Create(
		HINSTANCE					hInstance,
		HWND						hwndParent,
		const TCHAR*				pszUserWildCard,
		const TCHAR*				pszDefaultPath,
		const boost::container::vector<LPCTSTR>& vMRU			= boost::container::vector<LPCTSTR>(),
		const boost::container::vector<LPCTSTR>& vOPENFOLDER		= boost::container::vector<LPCTSTR>()
	);

	//操作
	bool DoModal_GetOpenFileName( TCHAR*, bool bSetCurDir = false, bool bAddTextFilter = true );	/* 開くダイアログ モーダルダイアログの表示 */	//2002/08/21 moca	引数追加
	bool DoModal_GetSaveFileName( TCHAR*, bool bSetCurDir = false );	/* 保存ダイアログ モーダルダイアログの表示 */	//2002/08/21 30,2002 moca	引数追加
	bool DoModalOpenDlg( SLoadInfo* pLoadInfo, boost::container::vector<std::tstring>*, bool bOptions = true );	/* 開くダイアグ モーダルダイアログの表示 */
	bool DoModalSaveDlg( SSaveInfo*	pSaveInfo, bool bSimpleMode );	/* 保存ダイアログ モーダルダイアログの表示 */

protected:
	CDlgOpenFileMem*	m_mem;

	/*
	||  実装ヘルパ関数
	*/

	//	May 29, 2004 genta エラー処理をまとめる (advised by MIK)
	void	DlgOpenFail(void);

	// 2005.11.02 ryoji OS バージョン対応の OPENFILENAME 初期化用関数
	void InitOfn( OPENFILENAMEZ* );

	// 2005.11.02 ryoji 初期レイアウト設定処理
	static void InitLayout( HWND hwndOpenDlg, HWND hwndDlg, HWND hwndBaseCtrl );

	// 2006.09.03 Moca ファイルダイアログのエラー回避
	//! リトライ機能付き GetOpenFileName
	bool _GetOpenFileNameRecover( OPENFILENAMEZ* ofn );
	//! リトライ機能付き GetOpenFileName
	bool GetSaveFileNameRecover( OPENFILENAMEZ* ofn );

	friend UINT_PTR CALLBACK OFNHookProc( HWND hdlg, UINT uiMsg, WPARAM wParam, LPARAM lParam );

public:
	// 設定フォルダ相対ファイル選択(共有データ,ini位置依存)
	static BOOL SelectFile(HWND parent, HWND hwndCtl, const TCHAR* filter, bool resolvePath, bool bAddTextFilter = true);

private:
	DISALLOW_COPY_AND_ASSIGN(CDlgOpenFile);
};



///////////////////////////////////////////////////////////////////////
#endif /* _CDLGOPENFILE_H_ */



