#include "stdafx.h"
#include "fight_handler.h"

FightHandler::FightHandler()
{
    m_hGameDlg = NULL;
}

void FightHandler::SetGameDlg(HWND hWnd)
{
    m_hGameDlg = hWnd;
}

void FightHandler::OutCard(UINT nIndex)
{
    m_Game.OutCard(nIndex);
    m_FightInfo.iSelfOutCard = nIndex;
    m_FightInfo.iSeftDamage = m_Game.GetSelfDamageLift();
    m_FightInfo.iComputeDamage = m_Game.GetComputeDamageLift();
    m_FightInfo.outComputeCard = m_Game.GetOutComputeyCard();
    m_FightInfo.outSelfCard = m_Game.GetOutSelfCard();
    m_FightInfo.GameInfo.iSeftLift = m_Game.GetSelfLift();
    m_FightInfo.GameInfo.iComputeLift = m_Game.GetComputeyLift();
    ///因为没有消息 所以暂时直接发送
    NotifyResult(emOutCarNotifyResult_OutCard);
}

void FightHandler::NotifyResult(FightNotifyResult emNotityResult)
{
    m_Game.GetCardList(m_SeftCard_vec);

    switch (emNotityResult)
    {
    case emOutCarNotifyResult_Null:
        break;
    case emOutCarNotifyResult_Update:
        ::PostMessage(m_hGameDlg, msg_game_update, (WPARAM)&m_SeftCard_vec, (LPARAM)&m_GameInfo);
        break;
    case emOutCarNotifyResult_OutCard:
        ::PostMessage(m_hGameDlg, msg_game_out_card, (WPARAM)&m_SeftCard_vec, (LPARAM)&m_FightInfo);
        break;
    default:
        break;
    }
}

void FightHandler::NotifyResult(std::string& strErr)
{
    ::PostMessage(m_hGameDlg, msg_game_update, 3, (LPARAM)strErr.c_str());
}

void FightHandler::InitializeGame(UINT nCard, UINT nLeft)
{
    m_Game.Initialize();
    m_GameInfo.iSeftLift = m_Game.GetSelfLift();
    m_GameInfo.iComputeLift = m_Game.GetComputeyLift();
    NotifyResult(emOutCarNotifyResult_Update);
}
