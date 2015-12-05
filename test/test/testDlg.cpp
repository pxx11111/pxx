
// testDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "test.h"
#include "testDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CtestDlg 对话框




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


// CtestDlg 消息处理程序

BOOL CtestDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	 m_ctrlWeb.Navigate("192.168.1.3",NULL,NULL,NULL,NULL); 
	

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CtestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CtestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CtestDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	m_winsock1.Close();

	if(m_winsock1.get_State()==0) 
	{	MessageBox("已关闭连接！","远程农作物图像获取系统控制软件");
		m_connect.EnableWindow(true);
	}

	else
	{	m_winsock1.Close();
		m_connect.EnableWindow(false);
	}
}


void CtestDlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	GetDlgItemText(IDC_EDIT1, m_editIP);
}


void CtestDlg::OnEnChangeEdit2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	GetDlgItemText(IDC_EDIT2, m_editPORT);
}


void CtestDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	long local;
	local=0;
	vtHost.vt=VT_BSTR;
	vtPort.vt=VT_BSTR;
	m_winsock1.put_LocalPort(local);
	m_winsock1.put_RemoteHost(m_editIP);
	m_winsock1.put_RemoteHost(m_editPORT);
	


	vtHost.bstrVal=m_editIP.AllocSysString();//见CString类字符串转化为系统字符串

	vtPort.bstrVal=m_editPORT.AllocSysString();

	m_winsock1.Connect(vtHost,vtPort);

	if(m_winsock1.get_State()==0) //如果m_socket已经断开连接，将connect设置为可用

		m_connect.EnableWindow(true);

	else

		m_connect.EnableWindow(false);
	
}


void CtestDlg::OnEnChangeEdit3()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	GetDlgItemText(IDC_EDIT3, m_Step);
}


void CtestDlg::OnEnChangeEdit4()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	GetDlgItemText(IDC_EDIT4, m_Speed);
}


void CtestDlg::OnBnClickedButton3()
{  CString m_sendl;
	// TODO: 在此添加控件通知处理程序代码
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
	// TODO: 在此添加控件通知处理程序代码
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
	// TODO: 在此添加控件通知处理程序代码
}
