
// EleDic_GroupDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "EleDic_Group.h"
#include "EleDic_GroupDlg.h"
#include "afxdialogex.h"
#include "windows.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//在此处添加额外的全局变量声明和全局函数声明
//邢国浩_添加的全局变量_用于定义字体和实现VIP用户操作
int ifVIP = 0;
CFont font;
CFont font2;
CFont font3;
CFont titleFont;
//熊伟_添加的全局变量_用于实现单词的查询功能模块
typedef struct dictionary
{
	char word[20];
	char cn[80];
}data;

int wordsNumber = 0;//单词总数目 
data dicSql[8000];//单词库 
int loadSql(data* sql, char path[100]);/*加载单词库数据*/
int searchWord(char word[20]);/*返回单词在单词库中的位置*/


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CEleDicGroupDlg 对话框



CEleDicGroupDlg::CEleDicGroupDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ELEDIC_GROUP_DIALOG, pParent)
	, m_timeEcho(_T(""))
	, cn2(_T(""))
	, word(_T(""))
	, word2(_T(""))
	, cn(_T(""))
	, vip_code(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CEleDicGroupDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_STATIC_usedTimeText, m_timeEcho);
	DDX_Text(pDX, IDC_EDIT1, cn2);
	DDX_Text(pDX, IDC_EDIT5, word);
	DDX_Text(pDX, IDC_EDIT2, word2);
	DDX_Text(pDX, IDC_EDIT6, cn);
	DDX_Text(pDX, VIP_INPUT, vip_code);
}

BEGIN_MESSAGE_MAP(CEleDicGroupDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDEXIT, &CEleDicGroupDlg::OnBnClickedExit)
	ON_WM_TIMER()
	ON_WM_CTLCOLOR()
	ON_EN_CHANGE(IDC_EDIT5, &CEleDicGroupDlg::XW_1_jianting)
	ON_EN_CHANGE(IDC_EDIT1, &CEleDicGroupDlg::OnEnChangeEdit1)
	ON_BN_CLICKED(VIP_INPUT_CONFIRM, &CEleDicGroupDlg::OnBnClickedInputConfirm)
	ON_BN_CLICKED(IDC_VIEWRAW, &CEleDicGroupDlg::OnBnClickedViewraw)
	ON_BN_CLICKED(IDC_TIMESHOWCMD, &CEleDicGroupDlg::OnBnClickedTimeshowcmd)
END_MESSAGE_MAP()


// CEleDicGroupDlg 消息处理程序

BOOL CEleDicGroupDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	//字体初始化代码
	font.CreatePointFont(160, _T("楷体"));
	font2.CreatePointFont(200, _T("黑体"));
	font3.CreatePointFont(100, _T("楷体"));
	titleFont.CreatePointFont(300, _T("楷体"));
	//初始化搜索框的代码
	GetDlgItem(IDC_STATIC_SEARCHBRANCHTITLE_ENG)->SetFont(&font);
	GetDlgItem(IDC_STATIC_SEARCHBRANCHTITLE_CHN)->SetFont(&font);
	GetDlgItem(IDC_STATIC_SEARCHTITLE2)->SetFont(&font2);
	GetDlgItem(IDC_STATIC_DICTTITLE)->SetFont(&font2);
	GetDlgItem(IDC_STATIC_MARKTITLE)->SetFont(&font2);
	GetDlgItem(IDC_STATIC_GAMETITLE4)->SetFont(&font2);
	GetDlgItem(IDC_STATIC_SEARCHINPUTTITLE_ENG)->SetFont(&font3);
	GetDlgItem(IDC_STATIC_SEARCHINPUTTITLE_CHN)->SetFont(&font3);
	GetDlgItem(IDC_STATIC_PROGRAMTITLE)->SetFont(&titleFont);
	//初始化VIP登陆界面的代码
	GetDlgItem(VIP_LOG_TITLE)->SetFont(&font3);
	GetDlgItem(IDEXIT)->SetFont(&font3);
	//Timer初始化代码
	m_Seconds = 0;
	SetTimer(0, 1000, NULL);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CEleDicGroupDlg::OnSysCommand(UINT nID, LPARAM lParam)
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
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CEleDicGroupDlg::OnPaint()
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
		//CDialogEx::OnPaint();
		//CDialog::OnPaint();//要禁止这个调用
		//加载调用背景图片 背景图片的资源文件是IDB_BACKGROUNDIMAGE
		CPaintDC   dc(this);
		CRect   rect;
		GetClientRect(&rect);
		CDC   dcMem;
		dcMem.CreateCompatibleDC(&dc);
		CBitmap   bmpBackground;
		bmpBackground.LoadBitmap(IDB_BACKGOUNDIMAGE); 
		BITMAP   bitmap;
		bmpBackground.GetBitmap(&bitmap);
		CBitmap* pbmpOld = dcMem.SelectObject(&bmpBackground);
		dc.StretchBlt(0, 0, rect.Width(), rect.Height(), &dcMem, 0, 0,
		bitmap.bmWidth, bitmap.bmHeight, SRCCOPY);

	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CEleDicGroupDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

//此监听函数负责让程序退出
void CEleDicGroupDlg::OnBnClickedExit()
{
	//char* 转换为LPCTSTR
	char* p = "确定要退出吗？";
	CString   m(p);
	LPCTSTR   lp = (LPCTSTR)m;
	char* q = "提示";
	CString   n(q);
	LPCTSTR   lp2 = (LPCTSTR)n;
	if (MessageBox(lp, lp2, MB_YESNO | MB_DEFBUTTON2) == IDYES)
		PostQuitMessage(0);
}


//此舰艇函数负责Timer的响应
void CEleDicGroupDlg::OnTimer(UINT_PTR nIDEvent)
{
	m_Seconds++;
	//注意 此处不能直接update data 否则编辑框输入会清空
}
void CEleDicGroupDlg::OnBnClickedTimeshowcmd()
{
	m_timeEcho.Format(_T("%ds"), m_Seconds);
	UpdateData(FALSE);
	// TODO: 在此添加控件通知处理程序代码
}


HBRUSH CEleDicGroupDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性
	// 根据DC的ID控制DC的属性
	//标题控件的颜色属性
	if (pWnd->GetDlgCtrlID() == IDC_STATIC_SEARCHTITLE2)// IDC_Display为所选文本框ID
	{
		      pDC->SetTextColor(RGB(100,0, 0));//设置字体颜色
			  pDC->SetBkColor(RGB(0, 255, 0));//设置背景颜色
	}
	if (pWnd->GetDlgCtrlID() == IDC_STATIC_DICTTITLE)// IDC_Display为所选文本框ID
	{
		pDC->SetTextColor(RGB(100, 0, 0));//设置字体颜色
		pDC->SetBkColor(RGB(0, 255, 0));//设置背景颜色
	}
	if (pWnd->GetDlgCtrlID() == IDC_STATIC_MARKTITLE)// IDC_Display为所选文本框ID
	{
		pDC->SetTextColor(RGB(100, 0, 0));//设置字体颜色
		pDC->SetBkColor(RGB(0, 255, 0));//设置背景颜色
	}
	if (pWnd->GetDlgCtrlID() == IDC_STATIC_GAMETITLE4)// IDC_Display为所选文本框ID
	{
		pDC->SetTextColor(RGB(100, 0, 0));//设置字体颜色
		pDC->SetBkColor(RGB(0, 255, 0));//设置背景颜色
	}

	//控件“使用时间”（IDC_STATIC_usedTimeText）的颜色属性
	if (pWnd->GetDlgCtrlID() == IDC_STATIC_usedTimeText)// IDC_Display为所选文本框ID
	{
		pDC->SetTextColor(RGB(0, 0, 100));//设置字体颜色
	}
	//控件 程序标题（IDC_STATIC_PROGRAMTITLE）的颜色属性
	if (pWnd->GetDlgCtrlID() == IDC_STATIC_PROGRAMTITLE)// IDC_Display为所选文本框ID
	{
		pDC->SetTextColor(RGB(255, 0, 0));//设置字体颜色
	}
	
	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}

//熊伟_定义的监听函数 用于实现英译汉中文框中实时显现对应单词
void CEleDicGroupDlg::XW_1_jianting()
{
	UpdateData(TRUE);
	if (strcmp(CW2A(word), "") != 0)//如果英译汉单词输入框发生了改变则执行if内语句
	{
		cn = "";
		char wordtmp[20];//临时变量，用于存储获取的单词
		strcpy(wordtmp, CW2A(word));//将CString类型转换成字符数组类型存储在临时变量中，cn为英译汉中输出中文那个编辑框的变量
		wordsNumber = loadSql(dicSql, "dictionary.txt");//用loadSql函数读取文件，将所有单词放在结构体数组中并且返回单词数量
		int i = 0, judge = -1;
		for (;i < wordsNumber;i++)
		{
			if (strstr(dicSql[i].word, wordtmp) != NULL) {//遍历结构体数组将包含用户输入单词的词条找出来
				cn += dicSql[i].word; //以下四行是将单词不停地加载cn这个字符串后面
				cn += '\t';
				cn += dicSql[i].cn;
				cn += "\r\n";
				judge = 1;
			}
		}
		if (judge == -1)
		{
			cn = "对不起，未找到该单词！\n\n";
		}
		UpdateData(FALSE);
	}
}

//熊伟_定义的监听函数 用于实现汉译英中文框中实时显现对应单词
void CEleDicGroupDlg::OnEnChangeEdit1()
{
	UpdateData(TRUE);//首先从控件处获取信息赋值给变量
	if (strcmp(CW2A(cn2), "") != 0)
	{
		word2 = "";//word2为汉译英中单词界面的变量
		char cn2tmp[80];//临时变量，用于存储获取的中文
		strcpy(cn2tmp, CW2A(cn2));//将CString类型转换成字符数组类型存储在临时变量中，cn2为汉译英中输入中文那个编辑框的变量
		wordsNumber = loadSql(dicSql, "dictionary.txt");//用loadSql函数读取文件，将所有单词放在结构体数组中并且返回单词数量
		int i = 0, judge = -1;
		for (;i < wordsNumber;i++)
		{
			if (strstr(dicSql[i].cn, cn2tmp) != NULL) {//遍历结构体数组将包含用户输入中文的词条找出来
				word2 += dicSql[i].word; //以下四行是将单词不停地加载word2这个字符串后面
				word2 += '\t';
				word2 += dicSql[i].cn;
				word2 += "\r\n";
				judge = 1;
			}
		}
		if (judge == -1)
		{
			word2 = "对不起，未找到该中文对应的单词！\n\n";
		}
		UpdateData(FALSE);
	}
}

//熊伟_定义的子功能模块函数
/*加载单词库数据*/
int loadSql(data* sql, char path[100])
{
	int i = 0;
	i = 0;
	FILE* fp = NULL;
	if ((fp = fopen(path, "r")) == NULL)
	{
		return 0;
	}
	while (fscanf(fp, "%s\t%s", (sql + i)->word, (sql + i)->cn) != EOF)
	{
		i++;
	}
	fclose(fp);
	return i;//返回值为int型，即文件中所有单词的数量
}

/*返回单词在单词库中的位置*/
int searchWord(char word[20])
{
	wordsNumber = loadSql(dicSql, "dictionary.txt");
	/*用二分法查找*/
	int low, mid, high;
	low = 0;
	high = wordsNumber;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (strcmp(dicSql[mid].word, word) > 0)
			high = mid - 1;
		else if (strcmp(dicSql[mid].word, word) < 0)
			low = mid + 1;
		else
			return mid;
	}
	/*用顺序查找法查找*/
	int i = 0;
	for (i = 0;i < wordsNumber;i++)
	{
		if (strcmp(dicSql[i].word, word) == 0)
			return i;
	}
	return -1;//如果找不到就返回-1 
}

void CEleDicGroupDlg::OnBnClickedInputConfirm()
{
	UpdateData(TRUE);
	if (ifVIP == 1) {
		char* p = "您已登陆成功，不需要再登";
		CString   m(p);
		LPCTSTR   lp = (LPCTSTR)m;
		char* q = "VIP成功登入";
		CString   n(q);
		LPCTSTR   lp2 = (LPCTSTR)n;
		MessageBox(lp, lp2, MB_DEFBUTTON1);
		return;
	}
		
	if (strcmp((CW2A)vip_code, "015") == 0) {
		//char* 转换为LPCTSTR
		char* p = "您已登陆成功，尊贵不堪的VIP用户";
		CString   m(p);
		LPCTSTR   lp = (LPCTSTR)m;
		char* q = "VIP成功登入";
		CString   n(q);
		LPCTSTR   lp2 = (LPCTSTR)n;
		if (MessageBox(lp, lp2, MB_YESNO | MB_DEFBUTTON2) == IDYES)
			ifVIP = 1;
		//如果用户点击了否 那么相当于没有登陆
	}
	else {
		char* p = "VIP码输入错误。你想要力量吗？";
		CString   m(p);
		LPCTSTR   lp = (LPCTSTR)m;
		char* q = "VIP登入失败";
		CString   n(q);
		LPCTSTR   lp2 = (LPCTSTR)n;
		if (MessageBox(lp, lp2, MB_YESNO | MB_DEFBUTTON2) == IDYES)
		{
			ShellExecute(NULL, NULL, _T("https://github.com/CC1AH/SummerTraining/"), NULL, NULL, SW_SHOWNORMAL);
		}
	}
	UpdateData(FALSE);
}


void CEleDicGroupDlg::OnBnClickedViewraw()
{
	if (ifVIP) {
		ShellExecute(NULL, NULL, _T("dictionary.txt"), NULL, NULL, SW_SHOWNORMAL);
	}
	else {
		char* p = "您还不是尊贵不堪的VIP用户，不能看。请点击最上面的登陆";
		CString   m(p);
		LPCTSTR   lp = (LPCTSTR)m;
		char* q = "VIP未登入";
		CString   n(q);
		LPCTSTR   lp2 = (LPCTSTR)n;
		MessageBox(lp, lp2, MB_DEFBUTTON1);
	}
}