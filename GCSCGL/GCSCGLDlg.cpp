
// GCSCGLDlg.cpp : ʵ���ļ�
#include "stdafx.h"
#include "GCSCGL.h"
#include "GCSCGLDlg.h"
#include "afxdialogex.h"
#include "math.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif
// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���
class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();
// �Ի�������
	enum { IDD = IDD_ABOUTBOX };
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};
CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}
void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}
BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()
// CGCSCGLDlg �Ի���
CGCSCGLDlg::CGCSCGLDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CGCSCGLDlg::IDD, pParent)
	, m_edit_ds(9)
	, m_edit_mn(10)
	, m_edit_beta(9)
	, m_edit_k(1)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_radio1=0;
}
void CGCSCGLDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_listctrl_jieguo);
	DDX_Text(pDX, IDC_EDIT1, m_edit_ds);
	DDX_Text(pDX, IDC_EDIT2, m_edit_mn);
	DDX_Text(pDX, IDC_EDIT3, m_edit_beta);
	DDX_Text(pDX, IDC_EDIT4, m_edit_k);
	DDX_Control(pDX, IDC_BUTTON1, m_js);
	//  DDX_Text(pDX, IDC_EDIT6, m_cdglb);
	DDX_Control(pDX, IDC_EDIT5, m_edit_jd);
	DDX_Radio(pDX, IDC_RADIO1, m_radio1);
}
BEGIN_MESSAGE_MAP(CGCSCGLDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CGCSCGLDlg::OnBnClickedButton1)
	ON_MESSAGE(WM_XIANCHENG,ms)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_RADIO1, &CGCSCGLDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CGCSCGLDlg::OnBnClickedRadio2)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, &CGCSCGLDlg::OnLvnItemchangedList1)
END_MESSAGE_MAP()
// CGCSCGLDlg ��Ϣ�������
BOOL CGCSCGLDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	m_edit_jd.SetReadOnly(TRUE);
	m_edit_jd.SetWindowTextA("0.000005");
	int i=0;
	m_listctrl_jieguo.SetExtendedStyle(LVS_EX_GRIDLINES|LVS_EX_FULLROWSELECT);
	m_listctrl_jieguo.InsertColumn(i++,"���ֱ�   i", LVCFMT_LEFT,75);
	m_listctrl_jieguo.InsertColumn(i++,"Z1", LVCFMT_LEFT,35);
	m_listctrl_jieguo.InsertColumn(i++,"Z2", LVCFMT_LEFT,35);
	m_listctrl_jieguo.InsertColumn(i++,"Z3", LVCFMT_LEFT,35);
	m_listctrl_jieguo.InsertColumn(i++,"Z4", LVCFMT_LEFT,35);
	m_listctrl_jieguo.InsertColumn(i++,"����ʵ�����", LVCFMT_LEFT,85);
	// ��������...���˵�����ӵ�ϵͳ�˵��С�
	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	m_wndStatusBar.Create(WS_CHILD|WS_VISIBLE|CCS_BOTTOM,CRect(0,0,0,0),this,3);
	int part[3]={200,310,-1};
	m_wndStatusBar.SetParts(3,part);
	m_wndStatusBar.SetText("�������������������㰴ť",0,0);
	m_wndStatusBar.SetText("������ͨ�û�е��",1,0);
	SetTimer(1,1000,NULL);
	CTime t;
	t=CTime::GetCurrentTime();
	m_wndStatusBar.SetText(t.Format("%H:%M:%S"),2,0);
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);
	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}
	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��
	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}
void CGCSCGLDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}
// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�
void CGCSCGLDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������
		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);
		//ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;
		//����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}
//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CGCSCGLDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}
JIEGUO::JIEGUO()
{
	i=0;
	n=0;
	z1=0;
	z2=0;
	z3=0;
	z4=0;
}
JIEGUO::~JIEGUO()
{	
}
void CGCSCGLDlg::OnBnClickedButton1()
{	
	GetDlgItem(IDC_BUTTON1)->EnableWindow(FALSE);
	double PI;
	PI=3.14159326;
	CANSHU *canshu=new CANSHU;
	UpdateData();
	canshu->a=m_edit_ds*sin(m_edit_beta*PI/180)/m_edit_mn/m_edit_k;
	canshu->hwnd=m_hWnd;
	//canshu->zz=this;
	char ch[10];
	m_edit_jd.GetWindowTextA(ch,10);
	canshu->jd=atof(ch);
	//m_cdglb=(canshu->a);
	UpdateData(FALSE);
	m_listctrl_jieguo.DeleteAllItems();
	CloseHandle(CreateThread(NULL,0,XianCheng,(LPVOID)canshu,0,NULL));
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
LRESULT CGCSCGLDlg::ms(WPARAM wParam,LPARAM lParam)
{		
		CString str[6];
		str[0].Format("%7.7f",((JIEGUO*)lParam)->i);
		str[1].Format("%d",(int)((JIEGUO*)lParam)->z1);
		str[2].Format("%d",(int)((JIEGUO*)lParam)->z2);
		str[3].Format("%d",(int)((JIEGUO*)lParam)->z3);
		str[4].Format("%d",(int)((JIEGUO*)lParam)->z4);
		if(((JIEGUO*)lParam)->z1==1)
			{
				GetDlgItem(IDC_BUTTON1)->EnableWindow();
			}
		else
		{
			if(((JIEGUO*)lParam)->n)
			{
				int nRow = m_listctrl_jieguo.InsertItem(((JIEGUO*)lParam)->n,str[0]);
				m_listctrl_jieguo.SetItemText(nRow, 1, str[1]);
				m_listctrl_jieguo.SetItemText(nRow, 2, str[2]);
				m_listctrl_jieguo.SetItemText(nRow, 3, str[3]);
				m_listctrl_jieguo.SetItemText(nRow, 4, str[4]);
			}
		}
		str[5].Format("�����%d�����",((JIEGUO*)lParam)->n);
		m_wndStatusBar.SetText(str[5],0,0);
		return TRUE;
}
DWORD WINAPI CGCSCGLDlg:: XianCheng(LPVOID lpParameter)
{	
	double x=((CANSHU*)lpParameter)->a;
	HWND hwnd=((CANSHU*)lpParameter)->hwnd;
	double jd=((CANSHU*)lpParameter)->jd;
	//CGCSCGLDlg *zz=((CANSHU*)lpParameter)->zz;
	delete lpParameter;
	FILE *file;
	file=fopen("���г��ֳ���.txt","r");
	if(!file)
	{
	AfxMessageBox("��ǰĿ¼û�з��֡����г��ֳ���.txt���ļ�");
	return 0;
	}
	fseek(file,0,SEEK_END);
	int len=ftell(file) ,sum=0;
	char *pBuf;
	pBuf=new char[len+1];
	fseek(file,0,SEEK_SET);
	fread(pBuf,1,len,file);
	pBuf[len]=0;
	for(int i=0;i<=len;i++)
	{
		if(pBuf[i]==',')
			sum++;
	}
	double *z;
	z=new double[sum];
	fseek(file,0,SEEK_SET);
	long le;
	for(int j=0;j<=sum;j++)
	{
		fscanf(file,"%lf",&z[j]);
		le=ftell(file);
		fseek(file,le+1,SEEK_SET);
	}
	fseek(file,0,SEEK_SET);
	fclose(file);
	JIEGUO *stra;
	stra=new JIEGUO;
	for(int z1=0;z1<sum;z1++)
	{
		for(int z2=0;z2<sum;z2++)
		{
			for(int z3=0;z3<sum;z3++)
			{
				for(int z4=0;z4<sum;z4++)
				{
					if(z[z1]<z[z3]&&z[z2]<z[z4])
					{
						if(x<1)
							{
								if(fabs(x-z[z1]/z[z2]*z[z3]/z[z4])<=jd)
								{
									stra->i=z[z1]/z[z2]*z[z3]/z[z4]; 
									stra->z1=z[z1];
									stra->z2=z[z2];
									stra->z3=z[z3];
									stra->z4=z[z4];
									stra->n+=1;
									::SendMessage(hwnd,WM_XIANCHENG,0,(LPARAM)stra);
								}
							}
						else
							{
								if(fabs(x-1/(z[z1]/z[z2]*z[z3]/z[z4]))<=jd)
								{
									stra->i=z[z2]/z[z1]*z[z4]/z[z3]; 
									stra->z1=z[z2];
									stra->z2=z[z1];
									stra->z3=z[z4];
									stra->z4=z[z3];
									stra->n+=1;
									::SendMessage(hwnd,WM_XIANCHENG,0,(LPARAM)stra);
								}
						
							}
					}
				}
			}
		}
	}
	if(!stra->n)
	{
	::SendMessage(hwnd,WM_XIANCHENG,0,(LPARAM)stra);
	}
	stra->z1=1;
	::SendMessage(hwnd,WM_XIANCHENG,0,(LPARAM)stra);
	delete z,stra;
	delete pBuf;
	return 0;
}
void CGCSCGLDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CTime t;
	t=CTime::GetCurrentTime();
	m_wndStatusBar.SetText(t.Format("%H:%M:%S"),2,0);
	CDialogEx::OnTimer(nIDEvent);
}


void CGCSCGLDlg::OnBnClickedRadio1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_edit_jd.SetReadOnly(TRUE);
	m_edit_jd.SetWindowTextA("0.000005");
}


void CGCSCGLDlg::OnBnClickedRadio2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_edit_jd.SetReadOnly(FALSE);
	MessageBox("���������뾫��","������ʾ");
}


void CGCSCGLDlg::OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;
}
