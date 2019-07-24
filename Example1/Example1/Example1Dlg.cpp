
// Example1Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Example1.h"
#include "Example1Dlg.h"
#include "afxdialogex.h"
#pragma warning(disable:4996)

#ifdef _DEBUG
#define new DEBUG_NEW
#endif



typedef struct dictionary
{
	char word[20];
	char cn[80];
}data;

int wordsNumber =0;//单词总数目 
data dicSql[8000];//单词库 

int loadSql(data *sql,char path[100]);/*加载单词库数据*/
int printAction();/*输出用户提示函数*/
void dealAction(int action);/*定义指令处理函数*/
void dictation();/*听写单词函数*/
int searchWord(char word[20]);/*返回单词在单词库中的位置*/
void searchCn(char cn[80]);/*返回中文翻译在单词库中的位置*/
void saveSql();/*保存文件函数*/
void wordsBook();/*单词本函数*/ 
void game1();//投骰子小游戏


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


// CExample1Dlg 对话框



CExample1Dlg::CExample1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CExample1Dlg::IDD, pParent)
	, word(_T(""))
	, cn(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CExample1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Text(pDX, IDC_EDIT5, word);
	DDV_MaxChars(pDX, word, 20);
	DDX_Text(pDX, IDC_EDIT6, cn);
}

BEGIN_MESSAGE_MAP(CExample1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON2, &CExample1Dlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CExample1Dlg 消息处理程序

BOOL CExample1Dlg::OnInitDialog()
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

void CExample1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CExample1Dlg::OnPaint()
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
HCURSOR CExample1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



/*void CExample1Dlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	sum =x+y;
	UpdateData(FALSE);
}*/





void CExample1Dlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	int i=0;
	FILE *fp =NULL;
	if((fp = fopen("dictionary.txt","r"))==NULL)
	{
		cn ="sss";
		UpdateData(FALSE);
		return ;
	}
	while(fscanf(fp,"%s\t%s",dicSql[i].word,dicSql[i].cn)!=EOF)
	{
		i++;
	}
	fclose(fp);
	char w[20];
	strcpy(w,CW2A(word));//将CString类型的word转化为字符数组
	int pos =searchWord(w);
	if(pos!=-1)
	{
		cn = dicSql[pos].cn;
		UpdateData(FALSE);
	}
	else
	{
		cn = "未找到！";
		UpdateData(FALSE);
	}
}

/*加载单词库数据*/
int loadSql(data *sql,char path[100])
{
	int i =0;
	i =0;
	FILE *fp =NULL;
	if((fp = fopen(path,"r"))==NULL)
	{
		return 0;
	}
	while(fscanf(fp,"%s\t%s",(sql+i)->word,(sql+i)->cn)!=EOF)
	{
		i++;
	}
	fclose(fp);
	return i;
}

/*返回单词在单词库中的位置*/
int searchWord(char word[20])
{
	wordsNumber =loadSql(dicSql,"dictionary.txt");
	/*用二分法查找*/
	int low,mid,high;
	low =0;
	high = wordsNumber;
	while(low<=high)
	{
		mid =(low+high)/2;
		if(strcmp(dicSql[mid].word,word)>0)
		    high = mid-1;
		else if(strcmp(dicSql[mid].word,word)<0)
		    low = mid+1;
		else
		    return mid;
	}
	/*用顺序查找法查找*/ 
	int i=0;
    for(i=0;i<wordsNumber;i++)
    {
        if(strcmp(dicSql[i].word,word)==0)
            return i;
    }
    return -1;//如果找不到就返回-1 
}