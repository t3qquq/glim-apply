﻿﻿
#pragma once
#include <vector>
#include <thread>
#include <afxwin.h>

// CMFCStartDlg 대화 상자
class CMFCStartDlg : public CDialogEx
{
// 생성입니다.
public:
	CMFCStartDlg(CWnd* pParent = nullptr);
	~CMFCStartDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFC_START_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);

// 구현입니다.
protected:
	HICON m_hIcon;
	std::vector<CPoint> m_ClickPoints;
	int m_Radius;      // 클릭 지점 원 반지름
	int m_Thickness;   // 정원 테두리 두께 (누락된 변수 추가)
	bool m_IsDragging;
	int m_DragIndex;
	std::thread m_RandomMoveThread;
	bool m_IsRandomMoving;

	void DrawCircle(CDC* pDC);
	void MoveRandomPoints();

	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedReset();
	afx_msg void OnBnClickedRandomMove();

	DECLARE_MESSAGE_MAP()
};
