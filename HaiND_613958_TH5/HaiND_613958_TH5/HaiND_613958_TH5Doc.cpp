
// HaiND_613958_TH5Doc.cpp : implementation of the CHaiND_613958_TH5Doc class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "HaiND_613958_TH5.h"
#endif

#include "HaiND_613958_TH5Doc.h"
#include "KichthuocDialog.h"
#include "MauSacDialog.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CHaiND_613958_TH5Doc

IMPLEMENT_DYNCREATE(CHaiND_613958_TH5Doc, CDocument)

BEGIN_MESSAGE_MAP(CHaiND_613958_TH5Doc, CDocument)
	ON_COMMAND(ID_THIETLAP_KICHTHUOC, &CHaiND_613958_TH5Doc::OnThietlapKichthuoc)
	ON_COMMAND(ID_THIETLAP_MAUSAC, &CHaiND_613958_TH5Doc::OnThietlapMausac)
END_MESSAGE_MAP()


// CHaiND_613958_TH5Doc construction/destruction

CHaiND_613958_TH5Doc::CHaiND_613958_TH5Doc()
{
	// TODO: add one-time construction code here

	m_mausac = 0;
	m_kichthuoc = 0;
	m_sohinh = 0;
	testVariable = 0;
}

CHaiND_613958_TH5Doc::~CHaiND_613958_TH5Doc()
{
}

BOOL CHaiND_613958_TH5Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}




// CHaiND_613958_TH5Doc serialization

void CHaiND_613958_TH5Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		ar << m_currentColor;
		ar << m_sohinh;
		ar << m_kichthuoc;
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				ar << m_gridColor[i][j];
			}
		}
		// TODO: add storing code here
	}
	else
	{
		ar >> m_currentColor;
		ar >> m_sohinh;
		ar >> m_kichthuoc;
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				ar >> m_gridColor[i][j];
			}
		}
		// TODO: add loading code here
	}
}

#ifdef SHARED_HANDLERS

// Support for thumbnails
void CHaiND_613958_TH5Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Modify this code to draw the document's data
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Support for Search Handlers
void CHaiND_613958_TH5Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// Set search contents from document's data. 
	// The content parts should be separated by ";"

	// For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CHaiND_613958_TH5Doc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CHaiND_613958_TH5Doc diagnostics

#ifdef _DEBUG
void CHaiND_613958_TH5Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CHaiND_613958_TH5Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CHaiND_613958_TH5Doc commands


void CHaiND_613958_TH5Doc::OnThietlapKichthuoc()
{
	// TODO: Add your command handler code here
	KichthuocDialog kt = new KichthuocDialog();
	
	//UpdateData(true);

	kt.kt_sohinh = m_sohinh;
	kt.kt_kichthuoc = m_kichthuoc;
	
	if (kt.DoModal() == IDOK)
	{
		m_sohinh = kt.kt_sohinh;
		m_kichthuoc = kt.kt_kichthuoc;
		//testVariable = 5;
		UpdateAllViews(NULL);
	}
}


void CHaiND_613958_TH5Doc::OnThietlapMausac()
{
	// TODO: Add your command handler code here
	MauSacDialog ms = new MauSacDialog();
	//UpdateData(true);
	ms.ms_mausac = m_mausac;
	if (ms.DoModal() == IDOK)
	{
		m_mausac = ms.ms_mausac;
		if (m_mausac == 0)
		{
			m_currentColor = 1;
		}
		if (m_mausac == 1)
		{
			m_currentColor = 2;
		}
		if (m_mausac == 2)
		{
			m_currentColor = 3;
		}
	}
}

int CHaiND_613958_TH5Doc::GetTestVariable()
{
	return testVariable;
}


int CHaiND_613958_TH5Doc::GetSoHinh()
{
	return m_sohinh;
}


int CHaiND_613958_TH5Doc::GetKichThuoc()
{
	return m_kichthuoc;
}


int CHaiND_613958_TH5Doc::GetMauSacHienTai()
{

	return m_currentColor;
}


int CHaiND_613958_TH5Doc::GetMauSacTheoViTri(int i, int j)
{
	return m_gridColor[i][j];
}


void CHaiND_613958_TH5Doc::SetMauTheoViTri(int i, int j, int mauSac)
{
	m_gridColor[i][j] = mauSac;
	SetModifiedFlag(true);
	UpdateAllViews(NULL);
}
