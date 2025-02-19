﻿
#include "pch.h"
#include "framework.h"
#include "MFC_Start.h"
#include "MFC_StartDlg.h"
#include "afxdialogex.h"
#include "resource.h"  // resource.h 포함 추가
#include <random>
#include <gdiplus.h>

using namespace Gdiplus;
#pragma comment(lib, "gdiplus.lib")

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CMFCStartDlg::CMFCStartDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFC_START_DIALOG, pParent), m_Radius(10), m_Thickness(2), m_IsDragging(false), m_IsRandomMoving(false)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

CMFCStartDlg::~CMFCStartDlg()
{
	if (m_RandomMoveThread.joinable()) {
		m_IsRandomMoving = false;
		m_RandomMoveThread.join();
	}
}

void CMFCStartDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCStartDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_BN_CLICKED(IDC_BUTTON_RESET, &CMFCStartDlg::OnBnClickedReset)
	ON_BN_CLICKED(IDC_BUTTON_RANDOM_MOVE, &CMFCStartDlg::OnBnClickedRandomMove)
END_MESSAGE_MAP()
