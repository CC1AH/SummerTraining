
// dictionaryDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "dictionary.h"
#include "dictionaryDlg.h"
#include "afxdialogex.h"
#pragma warning(disable:4996)
#include<string.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
struct dictionary//词库
{
	char word[50];
	char cn[50];

};
int num;//词库单词数量 
struct dictionary dic[10000];


void add(struct dictionary dic[],char key1[],char key2[],int num);


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


// CdictionaryDlg 对话框



CdictionaryDlg::CdictionaryDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CdictionaryDlg::IDD, pParent)
	, word1(_T(""))
	, cn1(_T(""))
	, output1(_T(""))
	, word2(_T(""))
	, word3(_T(""))
	, output2(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CdictionaryDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, word1);
	DDX_Text(pDX, IDC_EDIT2, cn1);
	DDX_Text(pDX, IDC_EDIT3, output1);
	DDX_Text(pDX, IDC_EDIT4, word2);
	DDX_Text(pDX, IDC_EDIT5, word3);
	DDX_Text(pDX, IDC_EDIT6, output2);
}

BEGIN_MESSAGE_MAP(CdictionaryDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CdictionaryDlg::OnBnClickedButton1)
	ON_EN_CHANGE(IDC_EDIT1, &CdictionaryDlg::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT2, &CdictionaryDlg::OnEnChangeEdit2)
	ON_EN_CHANGE(IDC_EDIT3, &CdictionaryDlg::OnEnChangeEdit3)
	ON_BN_CLICKED(IDC_BUTTON2, &CdictionaryDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CdictionaryDlg 消息处理程序

BOOL CdictionaryDlg::OnInitDialog()
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

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CdictionaryDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CdictionaryDlg::OnPaint()
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
HCURSOR CdictionaryDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CdictionaryDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	int i=0;
	FILE *fPtr;
	fPtr = fopen("d:\\dictionary.txt","r");
	if(fPtr== NULL){
		output1="添加失败";
		UpdateData(FALSE);
	}
	else{
		 while(!feof(fPtr))   
		 {
    
        fscanf(fPtr,"%s\t%s", dic[i].word, dic[i].cn);                   
        i++;
		num=i;	
		 }
	}
	fclose(fPtr);
	char word1tmp[20];//用来临时存放新加的单词
	char cn1tmp[20];//用来临时存放新加的单词的中文解释	
	strcpy(word1tmp,CW2A(word1));
	strcpy(cn1tmp,CW2A(cn1));
	strcpy(dic[num].word,word1tmp);
	strcpy(dic[num].cn,cn1tmp);
	if(dic[num].word!=NULL&&dic[num].cn!=NULL)//判断添加单词之后是否添加成功
	{output1="添加成功";
	num+=1;
	}
	else
		output1="添加失败";
		 	
	if((fPtr =fopen("d:\\dictionary.txt","w"))==NULL){
		return;
	}
	else
	{
		for(i=0;i<num;i++)
		{
			fprintf(fPtr,"%s\t%s\n",dic[i].word,dic[i].cn);
		}
	   
	}
	fclose(fPtr);
	UpdateData(FALSE);
	
}


void CdictionaryDlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

//#1015

	// TODO:  在此添加控件通知处理程序代码
}


void CdictionaryDlg::OnEnChangeEdit2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

//#1015

	// TODO:  在此添加控件通知处理程序代码
}


void CdictionaryDlg::OnEnChangeEdit3()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

//#1015

	// TODO:  在此添加控件通知处理程序代码
}



void CdictionaryDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	int i=0;
	int flag=0;
	FILE *fPtr;
	fPtr = fopen("d:\\dictionary.txt","r");
	if(fPtr== NULL){
		output2="文件打开失败";
		UpdateData(FALSE);
	}
	else{
		 while(!feof(fPtr))   
    
        {
			fscanf(fPtr,"%s\t%s", dic[i].word, dic[i].cn);                   
            i++;
		}	
		
	}
	fclose(fPtr);
	char word2tmp[20];
	char word3tmp[20];
	strcpy(word2tmp,CW2A(word2));
	strcpy(word3tmp,CW2A(word3));
	//output2="修改失败，词库中没有改单词";
	for(i=0;i<num;i++)
	{
		if(strcmp(dic[i].word,word2tmp)==0)
		{			
		    strcpy(dic[i].word,word3tmp);
			flag=1;
		}
	}
	if(flag==1)
		output2="修改成功";
	else
		output2="修改失败，词库中没有该单词"; 
	if((fPtr =fopen("d:\\dictionary.txt","w"))==NULL){
		return;
	}
	else
	{
		for(i=0;i<num;i++)
		{
			fprintf(fPtr,"%s\t%s\n",dic[i].word,dic[i].cn);
		}
	   
	}
	UpdateData(FALSE);
	



}


int loadword(struct dictionary dic[])  //载入一英文对应多中文的词库
{	
	int i=0;
	FILE *fPtr;
	fPtr = fopen("d:\\dictionarywtc.txt","r");
	if(fPtr== NULL){
		puts("could not open the file!");	
	}
	else{
		 while(!feof(fPtr))   
    {
        fscanf(fPtr,"%s\t%s", dic[i].word, dic[i].cn);                   
        i++;	
    }
		 printf("读取成功！\n");		
	}
	fclose(fPtr);
	return i;

}
