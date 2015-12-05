
// testDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "test.h"
#include "testDlg.h"
#include "afxdialogex.h"

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


// CtestDlg �Ի���




CtestDlg::CtestDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CtestDlg::IDD, pParent)
{   m_editIP = _T("192.168.1.3");
m_editPORT = _T("4660");
	
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CtestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_editIP);
	DDX_Text(pDX, IDC_EDIT2, m_editPORT);
	DDX_Control(pDX, IDC_WINSOCK1, m_winsock1);
	DDX_Control(pDX, IDC_EXPLORER1, m_ctrlWeb);
}
	

BEGIN_MESSAGE_MAP(CtestDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	
	ON_BN_CLICKED(IDC_BUTTON2, &CtestDlg::OnBnClickedButton2)
	ON_EN_CHANGE(IDC_EDIT1, &CtestDlg::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT2, &CtestDlg::OnEnChangeEdit2)
	ON_BN_CLICKED(IDC_BUTTON1, &CtestDlg::OnBnClickedButton1)
	ON_EN_CHANGE(IDC_EDIT3, &CtestDlg::OnEnChangeEdit3)
	ON_EN_CHANGE(IDC_EDIT4, &CtestDlg::OnEnChangeEdit4)
	ON_BN_CLICKED(IDC_BUTTON3, &CtestDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CtestDlg::OnBnClickedButton4)
	
END_MESSAGE_MAP()


// CtestDlg ��Ϣ�������

BOOL CtestDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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
	 m_ctrlWeb.Navigate("192.168.1.3",NULL,NULL,NULL,NULL); 
	

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CtestDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CtestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CtestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CtestDlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_winsock1.Close();

	if(m_winsock1.get_State()==0) 
	{	MessageBox("�ѹر����ӣ�","Զ��ũ����ͼ���ȡϵͳ�������");
		m_connect.EnableWindow(true);
	}

	else
	{	m_winsock1.Close();
		m_connect.EnableWindow(false);
	}
}


void CtestDlg::OnEnChangeEdit1()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	GetDlgItemText(IDC_EDIT1, m_editIP);
}


void CtestDlg::OnEnChangeEdit2()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	GetDlgItemText(IDC_EDIT2, m_editPORT);
}


void CtestDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	long local;
	local=0;
	vtHost.vt=VT_BSTR;
	vtPort.vt=VT_BSTR;
	m_winsock1.put_LocalPort(local);
	m_winsock1.put_RemoteHost(m_editIP);
	m_winsock1.put_RemoteHost(m_editPORT);
	


	vtHost.bstrVal=m_editIP.AllocSysString();//��CString���ַ���ת��Ϊϵͳ�ַ���

	vtPort.bstrVal=m_editPORT.AllocSysString();

	m_winsock1.Connect(vtHost,vtPort);

	if(m_winsock1.get_State()==0) //���m_socket�Ѿ��Ͽ����ӣ���connect����Ϊ����

		m_connect.EnableWindow(true);

	else

		m_connect.EnableWindow(false);
	
}


void CtestDlg::OnEnChangeEdit3()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	GetDlgItemText(IDC_EDIT3, m_Step);
}


void CtestDlg::OnEnChangeEdit4()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	GetDlgItemText(IDC_EDIT4, m_Speed);
}


void CtestDlg::OnBnClickedButton3()
{  CString m_sendl;
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int size1;
	int size2;
	size1=strlen(m_Step);
	size2=strlen(m_Speed);
	
	if (size1==1)
		m_Step="00000"+m_Step;
	if (size1==2)
		m_Step="0000"+m_Step;
	if (size1==3)
		m_Step="000"+m_Step;
	if (size1==4)
		m_Step="00"+m_Step;
	if (size1==5)
		m_Step="0"+m_Step;
	if (size2==1)
		m_Speed="0"+m_Speed;
	m_sendl="2010"+m_Step+m_Speed;
	

	
	VARIANT txtSendl;
	txtSendl.vt=VT_BSTR;
	txtSendl.bstrVal=m_sendl.AllocSysString();
	m_winsock1.SendData(txtSendl);
}


void CtestDlg::OnBnClickedButton4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString m_sendr;
	int size1;
	int size2;
	size1=strlen(m_Step);
	size2=strlen(m_Speed);
	if (size1==1)
		m_Step="00000"+m_Step;
	if (size1==2)
		m_Step="0000"+m_Step;
	if (size1==3)
		m_Step="000"+m_Step;
	if (size1==4)
		m_Step="00"+m_Step;
	if (size1==5)
		m_Step="0"+m_Step;
	if (size2==1)
		m_Speed="0"+m_Speed;
	m_sendr="2000"+m_Step+m_Speed;

	VARIANT txtSendr;
	txtSendr.vt=VT_BSTR;
	txtSendr.bstrVal=m_sendr.AllocSysString();
	m_winsock1.SendData(txtSendr);
}


void CtestDlg::OnBnClickedButton5()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
