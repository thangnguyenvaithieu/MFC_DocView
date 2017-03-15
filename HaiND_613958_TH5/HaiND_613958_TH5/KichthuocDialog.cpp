// KichthuocDialog.cpp : implementation file
//

#include "stdafx.h"
#include "HaiND_613958_TH5.h"
#include "KichthuocDialog.h"
#include "afxdialogex.h"


// KichthuocDialog dialog

IMPLEMENT_DYNAMIC(KichthuocDialog, CDialog)

KichthuocDialog::KichthuocDialog(CWnd* pParent /*=NULL*/)
	: CDialog(KichthuocDialog::IDD, pParent)
	, kt_kichthuoc(0)
	, kt_sohinh(0)
{

}

KichthuocDialog::~KichthuocDialog()
{
}

void KichthuocDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_KICHTHUOC, kt_kichthuoc);
	DDV_MinMaxInt(pDX, kt_kichthuoc, 0, 100);
	DDX_Text(pDX, IDC_EDIT_SOHINH, kt_sohinh);
	DDV_MinMaxInt(pDX, kt_sohinh, 0, 8);
}


BEGIN_MESSAGE_MAP(KichthuocDialog, CDialog)
END_MESSAGE_MAP()


// KichthuocDialog message handlers
