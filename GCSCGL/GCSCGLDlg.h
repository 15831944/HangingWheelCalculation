
// GCSCGLDlg.h : ͷ�ļ�
//

#pragma once
#include "afxcmn.h"
#include "afxwin.h"
#define WM_XIANCHENG WM_USER+1

// CGCSCGLDlg �Ի���
class CGCSCGLDlg : public CDialogEx
{
// ����
public:
	CGCSCGLDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_GCSCGL_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg LRESULT ms(WPARAM wParam,LPARAM lParam);
	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_listctrl_jieguo;
	double m_edit_ds;
	double m_edit_mn;
	double m_edit_beta;
	double m_edit_k;
	CStatusBarCtrl m_wndStatusBar;
	afx_msg void OnBnClickedButton1();
	static DWORD WINAPI XianCheng(LPVOID lpParameter);
	CButton m_js;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	CEdit m_edit_jd;
	int m_radio1;
	afx_msg void OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult);
};
struct CANSHU
{
	double a;
	double jd;
	HWND hwnd;
	//CGCSCGLDlg *zz;���ݴ���ָ�뵽�߳��� ���ƿؼ�
};
class JIEGUO
{
public:
	 JIEGUO();
	~JIEGUO();
	double i;
	double z1;
	double z2;
	double z3;
	double z4;
	int n;
};
