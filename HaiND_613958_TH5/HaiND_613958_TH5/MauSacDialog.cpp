// MauSacDialog.cpp : implementation file
//

#include "stdafx.h"
#include "HaiND_613958_TH5.h"
#include "MauSacDialog.h"
#include "afxdialogex.h"


// MauSacDialog dialog

IMPLEMENT_DYNAMIC(MauSacDialog, CDialog)

MauSacDialog::MauSacDialog(CWnd* pParent /*=NULL*/)
	: CDialog(MauSacDialog::IDD, pParent)
	, ms_mausac(0)
{

}

MauSacDialog::~MauSacDialog()
{
}

void MauSacDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_RADIO_RED, ms_mausac);
}


BEGIN_MESSAGE_MAP(MauSacDialog, CDialog)
END_MESSAGE_MAP()


// MauSacDialog message handlers
