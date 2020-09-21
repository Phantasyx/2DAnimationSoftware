/**
 * \file ViewActors.h
 *
 * \author Jordan Hill
 *
 * Class that provides a view windows for actors.
 */

#pragma once
#include "PictureObserver.h"

class CMainFrame;
/** Class that provides a view windows for actors. */
class CViewActors : public CScrollView, public CPictureObserver
{
	DECLARE_DYNCREATE(CViewActors)
public:
    static const int Width = 150;  ///< Width we want for this window 
	void SetMainFrame(CMainFrame *mainFrame) { mMainFrame = mainFrame; }/// pointer to the CMainFrame window
	virtual void UpdateObserver() override;
protected:
	CViewActors();           // protected constructor used by dynamic creation
	virtual ~CViewActors();
private:
	CMainFrame *mMainFrame = nullptr;
protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	virtual void OnInitialUpdate();     // first time after construct

	DECLARE_MESSAGE_MAP()

public:
    afx_msg BOOL OnEraseBkgnd(CDC* pDC);
};


