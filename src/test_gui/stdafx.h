#pragma once

// Modify the following defines if you have to target a platform prior to the ones specified below.
// Refer to MSDN for the latest info on corresponding values for different platforms.
#ifndef WINVER				// Allow use of features specific to Windows XP or later.
#define WINVER 0x0501		// Change this to the appropriate value to target other versions of Windows.
#endif

#ifndef _WIN32_WINNT		// Allow use of features specific to Windows XP or later.
#define _WIN32_WINNT 0x0501	// Change this to the appropriate value to target other versions of Windows.
#endif						

#ifndef _WIN32_WINDOWS		// Allow use of features specific to Windows 98 or later.
#define _WIN32_WINDOWS 0x0410 // Change this to the appropriate value to target Windows Me or later.
#endif

#ifndef _WIN32_IE			// Allow use of features specific to IE 6.0 or later.
#define _WIN32_IE 0x0600	// Change this to the appropriate value to target other versions of IE.
#endif

///> c/c++��
#include <stdio.h>
#include <tchar.h>
#include <assert.h>

///> windows��
#include <windows.h>

///> gdi
#include <wingdi.h>


///> zpublic��
//#include "zpublic.hpp"

//////////////////////////////////////////////////////////////////////////
///> atl
#include <atlbase.h>
#include <atlwin.h>
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
///> wtl
/*
 * ���塢������util��
 * ��Ҫ��һ������
 */
#include "atlapp.h"
/*
 * ��ԴID����
 */
#include "atlres.h"
/*
 * ��Ϣ�ɷ���
 */
#include "atlcrack.h"
/*
 * _U_RECT
 * _U_MENUorID
 * _U_STRINGorID
 * һЩ��Ϣ��
 */
#include "atlwinx.h"
/*
 * ���õ�һЩ�࣬CPoint��CString��
 * #define _WTL_NO_CSTRING
 */
#include "atlmisc.h"
/*
 * DDXʵ��
 */
#include "atlddx.h"
/*
 * ��ͨ�ؼ�
 * �߼��ؼ�
 * CommandBar�ؼ�
 */
#include "atlctrls.h"
#include "atlctrlx.h"
#include "atlctrlw.h"
/*
 * ��ܴ��ڷ�װ
 */
#include "atlframe.h"
/*
 * ���ֶԻ����װ
 */
#include "atldlgs.h"
/*
 * �༭����ҹ��ܷ�װ
 */
#include "atlfind.h"
/*
 * GDI��ͼ��װ
 */
#include "atlgdi.h"
/*
 * ��Դ�����װ
 */
#include "atluser.h"
/*
 * ���ڷָ��װ
 */
#include "atlsplit.h"
/*
 * ��������װ
 */
#include "atlscrl.h"
/*
 * ��ӡ��װ
 */
#include "atlprint.h"
/*
 * ���������DWM��Aero�ȷ�װ
 * requires _WIN32_WINNT >= 0x0600
 */
//#include "atldwm.h"
/*
 * ribbon����װ
 * requires the Windows 7 SDK or higher
 */
//#include "atlribbon.h"
/*
 * ϵͳƤ������װ
 */
//#include "atltheme.h"
//////////////////////////////////////////////////////////////////////////

extern CAppModule g_module;