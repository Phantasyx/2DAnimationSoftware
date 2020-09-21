/**
 * \file ViewTimeline.h
 *
 * \author Jordan Hill
 *
 * View window for the animation timeline
 */

#pragma once
#include "PictureObserver.h"
class CMainFrame;

/** View window for the animation timeline */
class CViewTimeline : public CScrollView, public CPictureObserver
{
	DECLARE_DYNCREATE(CViewTimeline)

public:
    static const int Height = 90;      ///< Height to make this window
	void SetMainFrame(CMainFrame *mainFrame) { mMainFrame = mainFrame; }
	virtual void UpdateObserver() override;

protected:
	CViewTimeline();           // protected constructor used by dynamic creation
	virtual ~CViewTimeline();

private :
	CMainFrame *mMainFrame = nullptr;


protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	virtual void OnInitialUpdate();     // first time after construct

	DECLARE_MESSAGE_MAP()

public:
    afx_msg BOOL OnEraseBkgnd(CDC* pDC);
    afx_msg void OnEditSetkeyframe();
    afx_msg void OnEditDeletekeyframe();
};


