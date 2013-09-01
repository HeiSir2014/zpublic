/* -------------------------------------------------------------------------
//  File        :   word.h
//  Author      :   Sum
//  Datet       :   2013/8/19 16:07
//  Brief       :   
//
// -----------------------------------------------------------------------*/
#ifndef _ZUI_BUTTON_
#define _ZUI_BUTTON_

#include "atlctrls.h"
#include "atlgdi.h"
#include "atlmisc.h"
#include <Windows.h>

namespace zui
{

class CButton
{
public:
    CButton();

    virtual ~CButton();

    bool Creat();

    bool SetText();

    bool GetText() const;


private:
    HWND m_hWnd;
    CFont m_TextFont;
    CStirng m_strText;
};

}

#endif