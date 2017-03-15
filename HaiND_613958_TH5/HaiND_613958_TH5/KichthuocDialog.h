#pragma once


// KichthuocDialog dialog

class KichthuocDialog : public CDialog
{
	DECLARE_DYNAMIC(KichthuocDialog)

public:
	KichthuocDialog(CWnd* pParent = NULL);   // standard constructor
	virtual ~KichthuocDialog();

// Dialog Data
	enum { IDD = IDD_KICHTHUOCDIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	int kt_kichthuoc;
	int kt_sohinh;
};
