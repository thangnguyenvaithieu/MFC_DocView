
// HaiND_613958_TH5Doc.h : interface of the CHaiND_613958_TH5Doc class
//


#pragma once


class CHaiND_613958_TH5Doc : public CDocument
{
protected: // create from serialization only
	CHaiND_613958_TH5Doc();
	DECLARE_DYNCREATE(CHaiND_613958_TH5Doc)

	// Attributes
public:

	// Operations
public:

	// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

	// Implementation
public:
	virtual ~CHaiND_613958_TH5Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

	// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Helper function that sets search content for a Search Handler
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	int m_mausac;
	int m_kichthuoc;
	int m_sohinh;
	int m_currentColor;
	int m_gridColor[8][8];
	afx_msg void OnThietlapKichthuoc();
	afx_msg void OnThietlapMausac();
protected:
	int testVariable;
public:
	int GetTestVariable();
	int GetSoHinh();
	int GetKichThuoc();
	int GetMauSacHienTai();
	int GetMauSacTheoViTri(int i, int j);
	void SetMauTheoViTri(int i, int j, int mauSac);
};
