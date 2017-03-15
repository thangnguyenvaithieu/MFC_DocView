
// HaiND_613958_TH5View.h : interface of the CHaiND_613958_TH5View class
//

#pragma once


class CHaiND_613958_TH5View : public CView
{
protected: // create from serialization only
	CHaiND_613958_TH5View();
	DECLARE_DYNCREATE(CHaiND_613958_TH5View)

// Attributes
public:
	CHaiND_613958_TH5Doc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Implementation
public:
	virtual ~CHaiND_613958_TH5View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // debug version in HaiND_613958_TH5View.cpp
inline CHaiND_613958_TH5Doc* CHaiND_613958_TH5View::GetDocument() const
   { return reinterpret_cast<CHaiND_613958_TH5Doc*>(m_pDocument); }
#endif

