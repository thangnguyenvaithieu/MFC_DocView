#pragma once


// MauSacDialog dialog

class MauSacDialog : public CDialog
{
	DECLARE_DYNAMIC(MauSacDialog)

public:
	MauSacDialog(CWnd* pParent = NULL);   // standard constructor
	virtual ~MauSacDialog();

// Dialog Data
	enum { IDD = IDD_MAUSACDIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	int ms_mausac;
};
