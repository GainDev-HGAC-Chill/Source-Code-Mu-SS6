//=============================================================================
//	NewUIScrollBar.cpp
//=============================================================================
#include "StdAfx.h"
#include "CBNewUiEx.h"
#include "Import.h"
#include "Offset.h"
#include "SEASON3B.h"
//#include "InterfaceBase.h"

CNewUIScrollBar gNewUIScrollBar;

CNewUIScrollBar::CNewUIScrollBar()
{
	memset(&m_ptPos, 0, sizeof(POINT));
	memset(&m_ptScrollBtnStartPos, 0, sizeof(POINT));
	memset(&m_ptScrollBtnPos, 0, sizeof(POINT));

	m_iScrollBarPickGap = 0;

	m_iScrollBarMovePixel = 1;
	m_iScrollBarHeightPixel = 0;
	m_iScrollBarMiddleNum = 0;
	m_iScrollBarMiddleRemainderPixel = 0;

	m_iScrollBtnMouseEvent = SCROLLBAR_MOUSEBTN_NORMAL;
	m_bScrollBtnActive = false;

	m_fPercentOfSize = 1.0f;

	m_iBeginPos = 0;
	m_iCurPos = 0;
	m_iMaxPos = 1;
	MouseWheelWindow = false;
}

CNewUIScrollBar::~CNewUIScrollBar()
{

}

bool CNewUIScrollBar::Create(int iX, int iY, int iHeight)
{
	m_iHeight = iHeight;
	SetPos(iX, iY);

	//Show( true );
	m_bScrollBtnActive = true;

	return true;
}

void CNewUIScrollBar::Release()
{
	memset(&m_ptPos, 0, sizeof(POINT));
	memset(&m_ptScrollBtnStartPos, 0, sizeof(POINT));
	memset(&m_ptScrollBtnPos, 0, sizeof(POINT));

	m_iScrollBarPickGap = 0;

	m_iScrollBarMovePixel = 1;
	m_iScrollBarHeightPixel = 0;
	m_iScrollBarMiddleNum = 0;
	m_iScrollBarMiddleRemainderPixel = 0;

	m_iScrollBtnMouseEvent = SCROLLBAR_MOUSEBTN_NORMAL;
	m_bScrollBtnActive = false;

	m_fPercentOfSize = 1.0f;

	m_iBeginPos = 0;
	m_iCurPos = 0;
	m_iMaxPos = 1;
	MouseWheelWindow = false;
}



void CNewUIScrollBar::SetPos(int x, int y)
{
	m_ptPos.x = x;
	m_ptPos.y = y;

	m_ptScrollBtnStartPos.x = m_ptPos.x - (SCROLLBTN_WIDTH / 2 - SCROLLBAR_TOP_WIDTH / 2);
	m_ptScrollBtnStartPos.y = m_ptPos.y;

	m_ptScrollBtnPos.x = m_ptScrollBtnStartPos.x;
	m_ptScrollBtnPos.y = m_ptScrollBtnStartPos.y;

	m_iScrollBarMovePixel = m_iHeight - SCROLLBTN_HEIGHT;
	if (m_iScrollBarMovePixel < 0)
		m_iScrollBarMovePixel = 1;

	m_iScrollBarHeightPixel = m_iHeight;

	m_iScrollBarMiddleNum = (m_iScrollBarHeightPixel - (SCROLLBAR_TOP_HEIGHT * 2)) / SCROLLBAR_MIDDLE_HEIGHT;
	m_iScrollBarMiddleRemainderPixel = (m_iScrollBarHeightPixel - (SCROLLBAR_TOP_HEIGHT * 2)) % SCROLLBAR_MIDDLE_HEIGHT;
}

bool CNewUIScrollBar::UpdateBtnEvent()
{
	if (pIsKeyRelease(VK_LBUTTON))
	{
		m_iScrollBtnMouseEvent = SCROLLBAR_MOUSEBTN_NORMAL;
		m_iScrollBarPickGap = 0;
		return true;
	}

	if (pCheckMouseOver(m_ptScrollBtnPos.x, m_ptScrollBtnPos.y, SCROLLBTN_WIDTH, SCROLLBTN_HEIGHT))
	{
		if (pIsKeyPress(VK_LBUTTON) && m_bScrollBtnActive == true)
		{
			m_iScrollBarPickGap = pCursorY - m_ptScrollBtnPos.y;
			m_iScrollBtnMouseEvent = SCROLLBAR_MOUSEBTN_CLICKED;
			return false;
		}
	}

	if (pCheckMouseOver(m_ptPos.x, m_ptPos.y, SCROLLBAR_TOP_WIDTH, m_iScrollBarHeightPixel))
	{
		if (pIsKeyPress(VK_LBUTTON) && m_bScrollBtnActive == true)
		{
			float fPercent = (float)(pCursorY - m_ptPos.y) / (float)m_iScrollBarMovePixel;
			SetPercent(fPercent);
			return true;
		}

	}

	if (MouseWheelWindow)
	{
		if (MouseWheel < 0)
		{
			ScrollUp(MouseWheel);
			MouseWheel = 0;
			return true;
		}
		if (MouseWheel > 0)
		{
			ScrollDown(MouseWheel);
			MouseWheel = 0;
			return true;
		}
	}
	return true;
}

bool CNewUIScrollBar::UpdateMouseEvent()
{

	if (UpdateBtnEvent() == true)
		return false;

	return true;
}

bool CNewUIScrollBar::UpdateKeyEvent()
{

	return true;
}

bool CNewUIScrollBar::Update()
{
	if (m_iScrollBtnMouseEvent == SCROLLBAR_MOUSEBTN_CLICKED)
	{
		float fPercent = (float)(pCursorY - m_iScrollBarPickGap - m_ptPos.y) / (float)m_iScrollBarMovePixel;
		SetPercent(fPercent);
	}

	return true;
}

bool CNewUIScrollBar::Render()
{
	pSetBlend(true);
	glColor3f(1.0, 1.0, 1.0);
	pDrawGUI(IMAGE_SCROLL_TOP, m_ptPos.x, m_ptPos.y, SCROLLBAR_TOP_WIDTH, SCROLLBAR_TOP_HEIGHT);

	for (int i = 0; i<m_iScrollBarMiddleNum; i++)
	{
		pDrawGUI(IMAGE_SCROLL_MIDDLE, m_ptPos.x,
			m_ptPos.y + SCROLLBAR_TOP_HEIGHT + (i * SCROLLBAR_MIDDLE_HEIGHT), SCROLLBAR_TOP_WIDTH, SCROLLBAR_MIDDLE_HEIGHT);
	}

	if (m_iScrollBarMiddleRemainderPixel > 0)
	{
		pDrawGUI(IMAGE_SCROLL_MIDDLE, m_ptPos.x, m_ptPos.y + SCROLLBAR_TOP_HEIGHT + (m_iScrollBarMiddleNum * SCROLLBAR_MIDDLE_HEIGHT), SCROLLBAR_TOP_WIDTH, m_iScrollBarMiddleRemainderPixel);
	}

	pDrawGUI(IMAGE_SCROLL_BOTTOM, m_ptPos.x, m_ptPos.y + m_iHeight - SCROLLBAR_TOP_HEIGHT, SCROLLBAR_TOP_WIDTH, SCROLLBAR_TOP_HEIGHT);

	if (m_bScrollBtnActive == true)
	{
		if (m_iScrollBtnMouseEvent == SCROLLBAR_MOUSEBTN_CLICKED)
		{
			glColor4f(0.7f, 0.7f, 0.7f, 1.0f);
		}
		pDrawGUI(IMAGE_SCROLLBAR_ON, m_ptScrollBtnPos.x, m_ptScrollBtnPos.y,
			SCROLLBTN_WIDTH, SCROLLBTN_HEIGHT);
	}
	else
	{
		pDrawGUI(IMAGE_SCROLLBAR_OFF, m_ptScrollBtnPos.x, m_ptScrollBtnPos.y,
			SCROLLBTN_WIDTH, SCROLLBTN_HEIGHT);
	}
	glColor3f(1.0f, 1.0f, 1.0f); //Xoa mau
	pGLSwitch();
	EnableAlphaTest(0);
	return true;
}


void CNewUIScrollBar::UpdateScrolling()
{
	m_ptScrollBtnPos.y = m_ptScrollBtnStartPos.y + m_fPercentOfSize * m_iScrollBarMovePixel;
}

void CNewUIScrollBar::ScrollUp(int iMoveValue)
{
	SetCurPos(m_iCurPos + iMoveValue);
}

void CNewUIScrollBar::ScrollDown(int iMoveValue)
{
	SetCurPos(m_iCurPos - iMoveValue);
}

void CNewUIScrollBar::SetPercent(float fPercent)
{
	if (fPercent <= 0.0f)
		m_fPercentOfSize = 0.0f;
	else if (fPercent >= 1.0f)
		m_fPercentOfSize = 1.0f;
	else
		m_fPercentOfSize = fPercent;

	m_iCurPos = m_iMaxPos * m_fPercentOfSize;
	UpdateScrolling();
}

void CNewUIScrollBar::SetMaxPos(int iMaxPos)
{
	if (iMaxPos < 1)
		iMaxPos = 1;

	m_iMaxPos = iMaxPos;
}

void CNewUIScrollBar::SetCurPos(int iPosValue)
{
	if (m_iBeginPos >= iPosValue)
		m_iCurPos = m_iBeginPos;
	else if (m_iMaxPos <= iPosValue)
		m_iCurPos = m_iMaxPos;
	else
		m_iCurPos = iPosValue;

	m_fPercentOfSize = (float)m_iCurPos / (float)m_iMaxPos;
	UpdateScrolling();
}
