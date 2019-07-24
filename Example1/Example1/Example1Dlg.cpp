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
int searchWord(char word[20]);/*返回单词在单词库中的位置*/


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
	, cn2(_T(""))
	, word2(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CExample1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Text(pDX, IDC_EDIT5, word);
	DDV_MaxChars(pDX, word, 20);
	DDX_Text(pDX, IDC_EDIT6, cn);
	DDX_Text(pDX, IDC_EDIT1, cn2);
	DDX_Text(pDX, IDC_EDIT2, word2);
}

BEGIN_MESSAGE_MAP(CExample1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_EDIT5, &CExample1Dlg::XW_1_jianting)
	ON_EN_CHANGE(IDC_EDIT1, &CExample1Dlg::XW_2_jianting)
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



//英译汉中文框中实时显现对应单词
void CExample1Dlg::XW_1_jianting()
{
	UpdateData(TRUE);
	if(strcmp(CW2A(word),"")!=0)//如果英译汉单词输入框发生了改变则执行if内语句
	{
		cn ="";
		char wordtmp[20];//临时变量，用于存储获取的单词
		strcpy(wordtmp,CW2A(word));//将CString类型转换成字符数组类型存储在临时变量中，cn为英译汉中输出中文那个编辑框的变量
		wordsNumber =loadSql(dicSql,"dictionary.txt");//用loadSql函数读取文件，将所有单词放在结构体数组中并且返回单词数量
		int i =0,judge =-1;
		for(;i<wordsNumber;i++)
		{
			if(strstr(dicSql[i].word,wordtmp)!=NULL){//遍历结构体数组将包含用户输入单词的词条找出来
				cn +=dicSql[i].word; //以下四行是将单词不停地加载cn这个字符串后面
				cn +='\t';
				cn +=dicSql[i].cn;
				cn +="\r\n";
				judge =1;
			}	    
		}
		if(judge==-1)
		{
			cn="对不起，未找到该单词！\n\n";
		} 
		UpdateData(FALSE);
	}
}

//汉译英中文框中实时显现对应单词
void CExample1Dlg::XW_2_jianting()
{
	UpdateData(TRUE);//首先从控件处获取信息赋值给变量
	if(strcmp(CW2A(cn2),"")!=0)
	{
		word2 ="";//word2为汉译英中单词界面的变量
		char cn2tmp[80];//临时变量，用于存储获取的中文
		strcpy(cn2tmp,CW2A(cn2));//将CString类型转换成字符数组类型存储在临时变量中，cn2为汉译英中输入中文那个编辑框的变量
		wordsNumber =loadSql(dicSql,"dictionary.txt");//用loadSql函数读取文件，将所有单词放在结构体数组中并且返回单词数量
		int i =0,judge =-1;
		for(;i<wordsNumber;i++)
		{
			if(strstr(dicSql[i].cn,cn2tmp)!=NULL){//遍历结构体数组将包含用户输入中文的词条找出来
				word2 +=dicSql[i].word; //以下四行是将单词不停地加载word2这个字符串后面
				word2 +='\t';
				word2 +=dicSql[i].cn;
				word2 +="\r\n";
				judge =1;
			}	    
		}
		if(judge==-1)
		{
			word2="对不起，未找到该中文对应的单词！\n\n";
		} 
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
	return i;//返回值为int型，即文件中所有单词的数量
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







