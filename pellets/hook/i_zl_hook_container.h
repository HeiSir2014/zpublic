/*************************************************************************
 *                                                                       *
 *  I|*j^3Cl|a   "+!*%                  qt          Nd   gW              *
 *  l]{y+l?MM*  !#Wla\NNP               NW          MM   I|              *
 *        PW    ?E|    tWg              Wg  sC!     AW           ~@v~    *
 *       NC     ?M!    yN|  WW     MK   MW@K1Y%M@   RM   #Q    QP@tim    *
 *     CM|      |WQCljAE|   MD     Mg   RN     cM~  NM   WQ   MQ         *
 *    #M        aQ?         MW     M3   Mg      Q(  HQ   YR  IM|         *
 *   Dq         {Ql         MH    iMX   Mg     MM   QP   QM   Eg         *
 * !EWNaPRag2$  +M"          $WNaHaN%   MQE$%EXW    QQ   CM    %M%a$D    *
 *                                                                       *
 *                               ZPublic                                 *
 *                  Developer: zapline(278998871@qq.com)                 *
 *               Website: https://github.com/zpublic/zpublic             *
 *                                                                       *
 ************************************************************************/
#ifndef ZL_I_HOOK_CONTAINER_H
#define ZL_I_HOOK_CONTAINER_H

interface IHookContainer
{
    //************************************
    // ���API hook
    // Returns:   BOOL
    // Parameter: LPCSTR pszDLLName     Ҫhook��dll��
    // Parameter: LPCSTR pszApiName     Ҫhook��api��
    // Parameter: PVOID pvHookProxyFunc ��������ַ
    // Parameter: PVOID * ppvRealAddr   ִ���������������ȥִ�е�stub
    // Parameter: LPCWSTR lpName        ��hook�ı���������unhook��ΪNULL��
    // ʹ�ô�������ַ��unhook
    //************************************
    virtual BOOL AddApiHook(
        LPCSTR pszDLLName,
        LPCSTR pszApiName, 
        PVOID pvHookProxyFunc, 
        OUT PVOID* ppvRealAddr,
        LPCWSTR lpName = NULL
        ) = 0;

    //************************************
    // Method:    ��ӵ�ַ hook
    // Returns:   BOOL
    // Parameter: PVOID pvHookTarget    Ҫhook�ĵ�ַ
    // Parameter: PVOID pvHookProxyFunc ��������ַ
    // Parameter: PVOID * ppvRealAddr   ִ���������������ȥִ�е�stub
    // Parameter: LPCWSTR lpName        ��hook�ı���������unhook��ΪNULL��
    // ʹ�ô�������ַ��unhook
    //************************************
    virtual BOOL AddAddrHook(
        PVOID pvHookTarget,  
        PVOID pvHookProxyFunc, 
        PVOID* ppvRealAddr,
        LPCWSTR lpName = NULL
        ) = 0;

    ///> ʹ�ô�������ַ��unhook
    virtual BOOL AddUnhookRoutine(LPVOID p_proxy_routine_address) = 0;

    ///> ʹ�ú���������unhook
    virtual BOOL AddunhookName(LPCWSTR lpName) = 0;
};

#endif