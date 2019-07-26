
// EleDic_GroupDlg.cpp: 实现文件

#include "pch.h"
#include "framework.h"
#include "EleDic_Group.h"
#include "EleDic_GroupDlg.h"
#include "afxdialogex.h"
#include "windows.h"
#include "time.h"
#include "stdlib.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
//邢国浩_添加的全局变量_用于定义字体和实现VIP用户操作
int ifVIP = 0;
CFont font;
CFont font2;
CFont font3;
CFont titleFont;
//熊伟_添加的全局变量_用于实现单词的查询功能模块
typedef struct dictionary
{
	char word[50];
	char cn[80];
}data;

int wordsNumber = 0;//单词总数目 
data dicSql[8000];//单词库 
int loadSql(data* sql, char path[100]);/*加载单词库数据*/
int searchWord(char word[20]);/*返回单词在单词库中的位置*/

//常智裕——添加的全局变量
struct czy_dict
{
	char en[40];
	char cn[80];
};
struct czy_dict czy_dictionary[20000];
struct czy_dict czy_dictionarytemp[1];
int openfiles(void);
void czy_getnum(int sum);

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
	, favoritesAddEn(_T(""))
	, favoritesAddCn(_T(""))
	, deleteInputValue(_T(""))
	, addResultValue(_T(""))
	, deleteResultValue(_T(""))
	, czy_judge(_T(""))
	, czy_word(_T(""))
	, czy_trans(_T(""))
	, JC_TopicTitle(_T(""))
	, JC_SCORE_TITLE1(_T(""))
	, JC_TIMER_ECHO(_T(""))
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
	DDX_Text(pDX, inputEn, favoritesAddEn);
	DDX_Text(pDX, inputCn, favoritesAddCn);
	DDX_Text(pDX, deleteEnInput, deleteInputValue);
	DDX_Text(pDX, addResultTips, addResultValue);
	DDX_Text(pDX, deleteResultTips, deleteResultValue);
	DDX_Text(pDX, czy_IDC_EDIT3, czy_judge);
	DDX_Text(pDX, czy_IDC_EDIT1, czy_word);
	DDX_Text(pDX, czy_IDC_EDIT2, czy_trans);
	DDX_Control(pDX, IDC_JC_ANSBUTTON1, JC_AnsButton1);
	DDX_Control(pDX, IDC_JC_ANSBUTTON2, JC_AnsButton2);
	DDX_Control(pDX, IDC_JC_ANSBUTTON3, JC_AnsButton3);
	DDX_Control(pDX, IDC_JC_ANSBUTTON4, JC_AnsButton4);
	DDX_Control(pDX, IDC_JC_SOCER, JC_SCORE_TITLE);
	DDX_Text(pDX, IDC_JC_TOPIC_ECHO, JC_TopicTitle);
	DDX_Control(pDX, IDC_JC_SKILLBUTTON1, JC_SkillButton1);
	DDX_Control(pDX, IDC_JC_SKILLBUTTON2, JC_SKILL_BUTTON2);
	DDX_Control(pDX, IDC_JC_SKILLBUTTON3, JC_SKILLBUTTON3);
	DDX_Control(pDX, IDC_BUTTON3, JC_GAMEPAUSE);
	DDX_Control(pDX, IDC_JC_TOPIC_ECHO, JC_TopicTitle1);
	DDX_Text(pDX, IDC_JC_SOCER, JC_SCORE_TITLE1);
	DDX_Text(pDX, IDC_JC_TIMER_ECHO, JC_TIMER_ECHO);
}

BEGIN_MESSAGE_MAP(CEleDicGroupDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDEXIT, &CEleDicGroupDlg::OnBnClickedExit)
	ON_WM_TIMER()
	ON_WM_CTLCOLOR()
	ON_EN_CHANGE(IDC_EDIT5, &CEleDicGroupDlg::XW_1_jianting)
	ON_BN_CLICKED(VIP_INPUT_CONFIRM, &CEleDicGroupDlg::OnBnClickedInputConfirm)
	ON_BN_CLICKED(IDC_VIEWRAW, &CEleDicGroupDlg::OnBnClickedViewraw)
	ON_BN_CLICKED(IDC_TIMESHOWCMD, &CEleDicGroupDlg::OnBnClickedTimeshowcmd)
	ON_BN_CLICKED(favoritesAddWord, &CEleDicGroupDlg::OnBnClickedfavoritesaddword)
	ON_BN_CLICKED(favoritesopenBt, &CEleDicGroupDlg::OnBnClickedfavoritesopenbt)
	ON_BN_CLICKED(deleteWordsBt, &CEleDicGroupDlg::OnBnClickeddeletewordsbt)
	ON_BN_CLICKED(czy_IDC_BUTTON1, &CEleDicGroupDlg::OnBnClickedIdcButton1)
	ON_BN_CLICKED(czy_IDC_BUTTON4, &CEleDicGroupDlg::OnBnClickedIdcButton4)
	ON_BN_CLICKED(IDD_ABOUTBOX, &CEleDicGroupDlg::OnBnClickedAboutbox)
	ON_EN_CHANGE(IDC_EDIT1_XW, &CEleDicGroupDlg::OnEnChangeEdit1Xw)
	ON_BN_CLICKED(IDC_JC_ANSBUTTON1, &CEleDicGroupDlg::OnBnClickedJcAnsbutton1)
	ON_BN_CLICKED(IDC_JC_ANSBUTTON2, &CEleDicGroupDlg::OnBnClickedJcAnsbutton2)
	ON_BN_CLICKED(IDC_JC_ANSBUTTON4, &CEleDicGroupDlg::OnBnClickedJcAnsbutton4)
	ON_BN_CLICKED(IDC_JC_ANSBUTTON3, &CEleDicGroupDlg::OnBnClickedJcAnsbutton3)
	ON_BN_CLICKED(IDC_BUTTON3, &CEleDicGroupDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_JC_GAMESTART, &CEleDicGroupDlg::OnBnClickedJcGamestart)
	ON_BN_CLICKED(IDC_JC_SKILLBUTTON1, &CEleDicGroupDlg::OnBnClickedJcSkillbutton1)
	ON_BN_CLICKED(IDC_JC_SKILLBUTTON2, &CEleDicGroupDlg::OnBnClickedJcSkillbutton2)
	ON_BN_CLICKED(IDC_JC_SKILLBUTTON3, &CEleDicGroupDlg::OnBnClickedJcSkillbutton3)
	ON_BN_CLICKED(IDC_OPENSONFUNCTIONEXE, &CEleDicGroupDlg::OnBnClickedOpensonfunctionexe)
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

	//字体初始化代码
	font.CreatePointFont(160, _T("楷体"));
	font2.CreatePointFont(200, _T("黑体"));
	font3.CreatePointFont(100, _T("楷体"));
	titleFont.CreatePointFont(300, _T("楷体"));
	GetDlgItem(IDC_STATIC_PROGRAMTITLE)->SetFont(&font2);
	//初始化搜索框的代码
	GetDlgItem(IDC_STATIC_SEARCHBRANCHTITLE_ENG)->SetFont(&font);
	GetDlgItem(IDC_STATIC_SEARCHBRANCHTITLE_CHN)->SetFont(&font);
	GetDlgItem(IDC_STATIC_SEARCHTITLE2)->SetFont(&font2);
	GetDlgItem(IDC_STATIC_DICTTITLE)->SetFont(&font2);
	GetDlgItem(IDC_STATIC_MARKTITLE)->SetFont(&font2);
	GetDlgItem(IDC_STATIC_GAMETITLE4)->SetFont(&font2);
	GetDlgItem(IDC_STATIC_SEARCHINPUTTITLE_ENG)->SetFont(&font3);
	GetDlgItem(IDC_STATIC_SEARCHINPUTTITLE_CHN)->SetFont(&font3);
	GetDlgItem(inputCnTips)->SetFont(&font3);
	GetDlgItem(inputEnTips)->SetFont(&font3);
	GetDlgItem(AFX_ID_PREVIEW_CLOSE)->SetFont(&font3);
	GetDlgItem(deleteEnTips)->SetFont(&font3);
	GetDlgItem(czy_IDC_STATIC1)->SetFont(&font3);
	GetDlgItem(czy_IDC_STATIC2)->SetFont(&font3);
	GetDlgItem(czy_IDC_BUTTON4)->SetFont(&font3);
	GetDlgItem(czy_IDC_BUTTON1)->SetFont(&font3);
	GetDlgItem(favoritesAddWord)->SetFont(&font3);
	GetDlgItem(deleteWordsBt)->SetFont(&font3);
	GetDlgItem(deleteTips)->SetFont(&font3);
	GetDlgItem(IDC_VIEWRAW)->SetFont(&font3);
	GetDlgItem(VIP_INPUT_CONFIRM)->SetFont(&font3);
	GetDlgItem(IDC_STATIC_GAMETITLE)->SetFont(&font3);
	GetDlgItem(IDC_STATIC_GAMESCORETITLE)->SetFont(&font3);
	GetDlgItem(IDC_STATIC_GAMESKILLTITLE)->SetFont(&font3);
	GetDlgItem(favoritesopenBt)->SetFont(&font3);
	GetDlgItem(IDC_OPENSONFUNCTIONEXE)->SetFont(&font3);
	GetDlgItem(IDC_JC_SKILLBUTTON1)->SetFont(&font3);
	GetDlgItem(IDC_JC_SKILLBUTTON2)->SetFont(&font3);
	GetDlgItem(IDC_JC_SKILLBUTTON3)->SetFont(&font3);
	GetDlgItem(IDC_BUTTON3)->SetFont(&font3);
	GetDlgItem(IDC_JC_GAMESTART)->SetFont(&font3);
	GetDlgItem(IDC_STATIC_GAMEIPUTTIPTITLE)->SetFont(&font);
	//初始化VIP登陆界面的代码
	GetDlgItem(VIP_LOG_TITLE)->SetFont(&font3);
	GetDlgItem(IDEXIT)->SetFont(&font3);

	//贾聪_添加的额外初始化代码
	srand((int)time(0));
	socer = 0;
	second = 60;
	SetTimer(1, 1000, NULL);
	JC_SCORE_TITLE1.Format(_T("%d"), socer);
	JC_TIMER_ECHO.Format(_T("%d"), second);
	//UpdateData(false);
	strcpy_s(chToEng.eng, "$$$$");
	if ((fopen_s(&fp, "dictionary.txt", "rt")) == 0) {

		while (!feof(fp))
		{
			int ch = 0, en = 0, con = 0;
			char chn[50], eng[40], temp;
			link* tempLink;
			tempLink = (link*)malloc(sizeof(link));
			tempLink->next == NULL;
			while ((temp = fgetc(fp)) != '\n')
			{
				if (temp == -1)
					break;
				if (temp == '\t')
					con = 1;
				if (con == 0 && temp != '\t' && temp >= 'a' && temp <= 'z')
					eng[en++] = temp;
				if (con == 1 && temp != '\t')
					chn[ch++] = temp;

			}

			if (temp == -1)
				break;
			eng[en] = '\0';
			chn[ch] = '\0';
			strcpy_s(tempLink->eng, eng);
			strcpy_s(tempLink->chn, chn);
			p->next = tempLink;
			p = p->next;
		}
	}

	for (int i = 0; i < 4; i++) {
		if (i == correctAnsButton)
			ansList[i] = true;
		else
			ansList[i] = false;
	}
	correctTopicPos = rand()%7900;
	tempP = chToEng.next;
	while (correctTopicPos > 0) {
		tempP = tempP->next;
		correctTopicPos--;
	}
	CString correctEng(tempP->eng);
	CString topictitle(tempP->chn);
	JC_TopicTitle.Format(topictitle);
	UpdateData(false);
	if (ansList[0])
		JC_AnsButton1.SetWindowTextW(correctEng);
	else {
		int wrongAnsPos = rand() % 7900;
		tempP = chToEng.next;
		while (wrongAnsPos > 0) {
			tempP = tempP->next;
			wrongAnsPos--;
		}
		CString wrongEng(tempP->eng);
		JC_AnsButton1.SetWindowTextW(wrongEng);
	}

	if (ansList[1])
		JC_AnsButton2.SetWindowTextW(correctEng);
	else {
		int wrongAnsPos = rand() % 7900;
		tempP = chToEng.next;
		while (wrongAnsPos > 0) {
			tempP = tempP->next;
			wrongAnsPos--;
		}
		CString wrongEng(tempP->eng);
		JC_AnsButton2.SetWindowTextW(wrongEng);
	}

	if (ansList[2])
		JC_AnsButton3.SetWindowTextW(correctEng);
	else {
		int wrongAnsPos = rand() % 7900;
		tempP = chToEng.next;
		while (wrongAnsPos > 0) {
			tempP = tempP->next;
			wrongAnsPos--;
		}
		CString wrongEng(tempP->eng);
		JC_AnsButton3.SetWindowTextW(wrongEng);
	}

	if (ansList[3])
		JC_AnsButton4.SetWindowTextW(correctEng);
	else {
		int wrongAnsPos = rand() % 7900;
		tempP = chToEng.next;
		while (wrongAnsPos > 0) {
			tempP = tempP->next;
			wrongAnsPos--;
		}
		CString wrongEng(tempP->eng);
		JC_AnsButton4.SetWindowTextW(wrongEng);
	}
	//Timer初始化代码
	m_Seconds = 0;

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
	// 贾聪 添加的Timer代码
	if (gameStart && !gamePause) {
		if (timeNotStop) {
			if (second > 0) {
				second -= 1;
				JC_TIMER_ECHO.Format(_T("%d"), second);
				UpdateData(false);
			}
			else {
				gameStart = false;
				gamePause = false;
				CString gameover("游戏结束！");
				JC_TIMER_ECHO.Format(gameover);
				UpdateData(false);
			}
		}
		else {
			if (stoppingTime > 15)
				timeNotStop = true;
			stoppingTime++;
		}
	}
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
	if (pWnd->GetDlgCtrlID() == IDC_STATIC_GAMEIPUTTIPTITLE)// IDC_Display为所选文本框ID
	{
		pDC->SetTextColor(RGB(0, 0, 0));//设置字体颜色
		pDC->SetBkColor(RGB(200, 255, 255));//设置背景颜色
	}
	if (pWnd->GetDlgCtrlID() == IDC_STATIC_DICTTITLE)// IDC_Display为所选文本框ID
	{
		pDC->SetTextColor(RGB(100, 0, 0));//设置字体颜色
		pDC->SetBkColor(RGB(0, 255, 0));//设置背景颜色
	}
	if (pWnd->GetDlgCtrlID() == IDC_STATIC_SEARCHTITLE2)// IDC_Display为所选文本框ID
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

//VIP登陆按钮
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
//查看原词库文件按钮
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

//常智裕定义的函数
int openfiles(void)
{
	int sum = 0;
	FILE* fp;
	if ((fp = fopen("dictionary.txt", "r")) == NULL)
	{
		return 0;
	}
	while (!feof(fp))
	{
		fscanf(fp, "%s\t%s", czy_dictionary[sum].en, czy_dictionary[sum].cn);
		++sum;
	}
	fclose(fp);
	return sum;
}
void czy_getnum(int sum)
{
	int i = 0;
	i = rand() % sum;
	czy_dictionarytemp[0] = czy_dictionary[i];
}

//xw增加收藏夹单词按钮
void CEleDicGroupDlg::OnBnClickedfavoritesaddword()
{
	data words[500];
	FILE* fp1 = NULL;
	FILE* fp2 = NULL;
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	//以“r”方式打开文件，读取文件信息
	//if((fopen_s(&fp1,"favorites.txt","r"))!=0)
	if ((fp1 = fopen("favorites.txt", "r")) == NULL)
	{
		return;
	}
	int i = 0;
	int favoritesNum;
	int favoritesJudge = 0;
	while (fscanf(fp1, "%s\t%s", words[i].word, words[i].cn) != EOF)
	{
		i++;
	}
	fclose(fp1);
	favoritesNum = i;

	//以“w”方式打开文件，后面将结构体数组写入文件
	if ((fp2 = fopen("favorites.txt", "w")) == NULL)
	{
		return;
	}
	strcpy(words[favoritesNum].word, CW2A(favoritesAddEn));
	strcpy(words[favoritesNum].cn, CW2A(favoritesAddCn));
	for (i = 0;i <= favoritesNum;i++)
	{
		fprintf(fp2, "%s\t%s\n", words[i].word, words[i].cn);
		favoritesJudge = 1;
	}
	fclose(fp2);
	if (favoritesJudge == 1)
	{
		addResultValue = "添加成功";
		favoritesAddEn = "";
		favoritesAddCn = "";
	}

	else
	{
		addResultValue = "添加失败";
		favoritesAddEn = "";
		favoritesAddCn = "";
	}
	UpdateData(FALSE);
}
//xw打开收藏夹单词按钮
void CEleDicGroupDlg::OnBnClickedfavoritesopenbt()
{
	ShellExecute(NULL, _T("open"), _T("favorites.txt"), NULL, NULL, SW_SHOW);
}
//xw删除收藏夹单词按钮
void CEleDicGroupDlg::OnBnClickeddeletewordsbt()
{

	data words[500];
	FILE* fp1 = NULL;
	FILE* fp2 = NULL;
	UpdateData(TRUE);

	//以“r”方式打开文件，读取文件信息
	//if((fopen_s(&fp1,"favorites.txt","r"))!=0)
	if ((fp1 = fopen("favorites.txt", "r")) == NULL)
	{
		return;
	}
	int i = 0;
	int favoritesNum;
	int favoritesJudge = 0;
	while (fscanf(fp1, "%s\t%s", words[i].word, words[i].cn) != EOF)
	{
		i++;
	}
	fclose(fp1);
	favoritesNum = i;

	//以“w”方式打开文件，后面将结构体数组写入文件
	if ((fp2 = fopen("favorites.txt", "w")) == NULL)
	{
		return;
	}
	//将需要删除的单词标记
	for (i = 0;i < favoritesNum;i++)
	{
		if (strcmp(words[i].word, CW2A(deleteInputValue)) == 0)
		{
			char a[5] = "#";
			strcpy(words[i].word, a);
			favoritesJudge = 1;
		}
	}
	//将结构体数组重写进文件，若被标记则不写入
	for (i = 0;i < favoritesNum;i++)
	{
		if (strcmp(words[i].word, "#") != 0)
		{
			fprintf(fp2, "%s\t%s\n", words[i].word, words[i].cn);
		}
	}
	fclose(fp2);
	if (favoritesJudge == 1)
	{
		deleteResultValue = "删除成功";
		deleteInputValue = "";
	}
	else
	{
		deleteResultValue = "删除失败,单词不存在";
		deleteInputValue = "";
	}
	UpdateData(FALSE);
}

//czy听写：开始/下一个按钮
void CEleDicGroupDlg::OnBnClickedIdcButton1()
{
	UpdateData(TRUE);
	int sum = openfiles();
	czy_getnum(sum);
	czy_word = czy_dictionarytemp[0].cn;
	UpdateData(FALSE);
}
//czy听写：批改按钮
void CEleDicGroupDlg::OnBnClickedIdcButton4()
{
	UpdateData(TRUE);
	int sum = openfiles();
	if (czy_dictionarytemp[0].en == czy_trans)
	{
		czy_judge = "正确！";
	}
	else
	{
		czy_judge = "错误！";
	}
	UpdateData(FALSE);
}
//显示时间按钮
void CEleDicGroupDlg::OnBnClickedAboutbox()
{
	m_timeEcho.Format(_T("%ds"), m_Seconds);
	UpdateData(FALSE);
}
//xw中文查询输入监听
void CEleDicGroupDlg::OnEnChangeEdit1Xw()
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

//贾聪定义的游戏模块监听函数
void CEleDicGroupDlg::OnBnClickedJcAnsbutton1()
{
	// TODO: 在此添加控件通知处理程序代码
	JC_AnsButton1.ShowWindow(true);
	JC_AnsButton2.ShowWindow(true);
	JC_AnsButton3.ShowWindow(true);
	JC_AnsButton4.ShowWindow(true);

	if (gameStart && !gamePause) {
		if (ansList[0]) {
			second += 3;
			socer++;
			JC_SCORE_TITLE1.Format(_T("%d"), socer);
			UpdateData(false);
		}
		else {
			second -= 10;
			JC_TIMER_ECHO.Format(_T("%d"), second);
			UpdateData(false);
		}


		//以下为点击按钮之后的变化函数，我就不精简代码了,直接复制粘贴了/(0.0)\

		correctAnsButton = rand() % 7900;
		for (int i = 0; i < 4; i++) {
			if (i == correctAnsButton)
				ansList[i] = true;
			else
				ansList[i] = false;
		}
		correctTopicPos = rand() % 7900;
		tempP = chToEng.next;
		while (correctTopicPos > 0) {
			tempP = tempP->next;
			correctTopicPos--;
		}
		CString correctEng(tempP->eng);
		CString topictitle(tempP->chn);
		JC_TopicTitle.Format(topictitle);
		UpdateData(false);

		if (ansList[0])
			JC_AnsButton1.SetWindowTextW(correctEng);
		else {
			int wrongAnsPos = rand() % 7900;
			tempP = chToEng.next;
			while (wrongAnsPos > 0) {
				tempP = tempP->next;
				wrongAnsPos--;
			}
			CString wrongEng(tempP->eng);
			JC_AnsButton1.SetWindowTextW(wrongEng);
		}

		if (ansList[1])
			JC_AnsButton2.SetWindowTextW(correctEng);
		else {
			int wrongAnsPos = rand() % 7900;
			tempP = chToEng.next;
			while (wrongAnsPos > 0) {
				tempP = tempP->next;
				wrongAnsPos--;
			}
			CString wrongEng(tempP->eng);
			JC_AnsButton2.SetWindowTextW(wrongEng);
		}

		if (ansList[2])
			JC_AnsButton3.SetWindowTextW(correctEng);
		else {
			int wrongAnsPos = rand() % 7900;
			tempP = chToEng.next;
			while (wrongAnsPos > 0) {
				tempP = tempP->next;
				wrongAnsPos--;
			}
			CString wrongEng(tempP->eng);
			JC_AnsButton3.SetWindowTextW(wrongEng);
		}

		if (ansList[3])
			JC_AnsButton4.SetWindowTextW(correctEng);
		else {
			int wrongAnsPos = rand() % 7900;
			tempP = chToEng.next;
			while (wrongAnsPos > 0) {
				tempP = tempP->next;
				wrongAnsPos--;
			}
			CString wrongEng(tempP->eng);
			JC_AnsButton4.SetWindowTextW(wrongEng);
		}
	}
}
void CEleDicGroupDlg::OnBnClickedJcAnsbutton2()
{
	JC_AnsButton1.ShowWindow(true);
	JC_AnsButton2.ShowWindow(true);
	JC_AnsButton3.ShowWindow(true);
	JC_AnsButton4.ShowWindow(true);

	if (gameStart && !gamePause) {
		if (ansList[1]) {
			second += 3;
			socer++;
			JC_SCORE_TITLE1.Format(_T("%d"), socer);
			UpdateData(false);
		}
		else {
			second -= 10;
			JC_TIMER_ECHO.Format(_T("%d"), second);
			UpdateData(false);
		}


		//以下为点击按钮之后的变化函数，我就不精简代码了,直接复制粘贴了/(0.0)\

		correctAnsButton = rand() % 7900;
		for (int i = 0; i < 4; i++) {
			if (i == correctAnsButton)
				ansList[i] = true;
			else
				ansList[i] = false;
		}
		correctTopicPos = rand() % 7900;
		tempP = chToEng.next;
		while (correctTopicPos > 0) {
			tempP = tempP->next;
			correctTopicPos--;
		}
		CString correctEng(tempP->eng);
		CString topictitle(tempP->chn);
		JC_TopicTitle.Format(topictitle);
		UpdateData(false);

		if (ansList[0])
			JC_AnsButton1.SetWindowTextW(correctEng);
		else {
			int wrongAnsPos = rand() % 7900;
			tempP = chToEng.next;
			while (wrongAnsPos > 0) {
				tempP = tempP->next;
				wrongAnsPos--;
			}
			CString wrongEng(tempP->eng);
			JC_AnsButton1.SetWindowTextW(wrongEng);
		}

		if (ansList[1])
			JC_AnsButton2.SetWindowTextW(correctEng);
		else {
			int wrongAnsPos = rand()%7900;
			tempP = chToEng.next;
			while (wrongAnsPos > 0) {
				tempP = tempP->next;
				wrongAnsPos--;
			}
			CString wrongEng(tempP->eng);
			JC_AnsButton2.SetWindowTextW(wrongEng);
		}

		if (ansList[2])
			JC_AnsButton3.SetWindowTextW(correctEng);
		else {
			int wrongAnsPos = rand()%7900;
			tempP = chToEng.next;
			while (wrongAnsPos > 0) {
				tempP = tempP->next;
				wrongAnsPos--;
			}
			CString wrongEng(tempP->eng);
			JC_AnsButton3.SetWindowTextW(wrongEng);
		}

		if (ansList[3])
			JC_AnsButton4.SetWindowTextW(correctEng);
		else {
			int wrongAnsPos = rand()%7900;
			tempP = chToEng.next;
			while (wrongAnsPos > 0) {
				tempP = tempP->next;
				wrongAnsPos--;
			}
			CString wrongEng(tempP->eng);
			JC_AnsButton4.SetWindowTextW(wrongEng);
		}
	}
}
void CEleDicGroupDlg::OnBnClickedJcAnsbutton4()
{
	// TODO: 在此添加控件通知处理程序代码
	JC_AnsButton1.ShowWindow(true);
	JC_AnsButton2.ShowWindow(true);
	JC_AnsButton3.ShowWindow(true);
	JC_AnsButton4.ShowWindow(true);

	if (gameStart && !gamePause) {
		if (ansList[3]) {
			second += 3;
			socer++;
			JC_SCORE_TITLE1.Format(_T("%d"), socer);
			UpdateData(false);
		}
		else {
			second -= 10;
			JC_TIMER_ECHO.Format(_T("%d"), second);
			UpdateData(false);
		}

		//以下为点击按钮之后的变化函数，我就不精简代码了,直接复制粘贴了/(0.0)\

		correctAnsButton = rand()%4;
		for (int i = 0; i < 4; i++) {
			if (i == correctAnsButton)
				ansList[i] = true;
			else
				ansList[i] = false;
		}
		correctTopicPos = rand()%7900;
		tempP = chToEng.next;
		while (correctTopicPos > 0) {
			tempP = tempP->next;
			correctTopicPos--;
		}
		CString correctEng(tempP->eng);
		CString topictitle(tempP->chn);
		JC_TopicTitle.Format(topictitle);
		UpdateData(false);

		if (ansList[0])
			JC_AnsButton1.SetWindowTextW(correctEng);
		else {
			int wrongAnsPos = rand()%7900;
			tempP = chToEng.next;
			while (wrongAnsPos > 0) {
				tempP = tempP->next;
				wrongAnsPos--;
			}
			CString wrongEng(tempP->eng);
			JC_AnsButton1.SetWindowTextW(wrongEng);
		}

		if (ansList[1])
			JC_AnsButton2.SetWindowTextW(correctEng);
		else {
			int wrongAnsPos = rand()%7900;
			tempP = chToEng.next;
			while (wrongAnsPos > 0) {
				tempP = tempP->next;
				wrongAnsPos--;
			}
			CString wrongEng(tempP->eng);
			JC_AnsButton2.SetWindowTextW(wrongEng);
		}

		if (ansList[2])
			JC_AnsButton3.SetWindowTextW(correctEng);
		else {
			int wrongAnsPos = rand() % 7900;
			tempP = chToEng.next;
			while (wrongAnsPos > 0) {
				tempP = tempP->next;
				wrongAnsPos--;
			}
			CString wrongEng(tempP->eng);
			JC_AnsButton3.SetWindowTextW(wrongEng);
		}

		if (ansList[3])
			JC_AnsButton4.SetWindowTextW(correctEng);
		else {
			int wrongAnsPos = rand() % 7900;
			tempP = chToEng.next;
			while (wrongAnsPos > 0) {
				tempP = tempP->next;
				wrongAnsPos--;
			}
			CString wrongEng(tempP->eng);
			JC_AnsButton4.SetWindowTextW(wrongEng);
		}
	}
}
void CEleDicGroupDlg::OnBnClickedJcAnsbutton3()
{
	// TODO: 在此添加控件通知处理程序代码
	JC_AnsButton1.ShowWindow(true);
	JC_AnsButton2.ShowWindow(true);
	JC_AnsButton3.ShowWindow(true);
	JC_AnsButton4.ShowWindow(true);

	if (gameStart && !gamePause) {
		if (ansList[2]) {
			second += 3;
			socer++;
			JC_SCORE_TITLE1.Format(_T("%d"), socer);
			UpdateData(false);
		}
		else {
			second -= 10;
			JC_TIMER_ECHO.Format(_T("%d"), second);
			UpdateData(false);
		}

		//以下为点击按钮之后的变化函数，我就不精简代码了,直接复制粘贴了/(0.0)\

		correctAnsButton = rand() % 4;
		for (int i = 0; i < 4; i++) {
			if (i == correctAnsButton)
				ansList[i] = true;
			else
				ansList[i] = false;
		}
		correctTopicPos = rand() % 7900;
		tempP = chToEng.next;
		while (correctTopicPos > 0) {
			tempP = tempP->next;
			correctTopicPos--;
		}
		CString correctEng(tempP->eng);
		CString topictitle(tempP->chn);
		JC_TopicTitle.Format(topictitle);
		UpdateData(false);

		if (ansList[0])
			JC_AnsButton1.SetWindowTextW(correctEng);
		else {
			int wrongAnsPos = rand() % 7900;
			tempP = chToEng.next;
			while (wrongAnsPos > 0) {
				tempP = tempP->next;
				wrongAnsPos--;
			}
			CString wrongEng(tempP->eng);
			JC_AnsButton1.SetWindowTextW(wrongEng);
		}

		if (ansList[1])
			JC_AnsButton2.SetWindowTextW(correctEng);
		else {
			int wrongAnsPos = rand() % 7900;
			tempP = chToEng.next;
			while (wrongAnsPos > 0) {
				tempP = tempP->next;
				wrongAnsPos--;
			}
			CString wrongEng(tempP->eng);
			JC_AnsButton2.SetWindowTextW(wrongEng);
		}

		if (ansList[2])
			JC_AnsButton3.SetWindowTextW(correctEng);
		else {
			int wrongAnsPos = rand() % 7900;
			tempP = chToEng.next;
			while (wrongAnsPos > 0) {
				tempP = tempP->next;
				wrongAnsPos--;
			}
			CString wrongEng(tempP->eng);
			JC_AnsButton3.SetWindowTextW(wrongEng);
		}

		if (ansList[3])
			JC_AnsButton4.SetWindowTextW(correctEng);
		else {
			int wrongAnsPos = rand() % 7900;
			tempP = chToEng.next;
			while (wrongAnsPos > 0) {
				tempP = tempP->next;
				wrongAnsPos--;
			}
			CString wrongEng(tempP->eng);
			JC_AnsButton4.SetWindowTextW(wrongEng);
		}
	}
}
void CEleDicGroupDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	if (gameStart) {
		if (gamePause) {
			CString text("暂停游戏");
			JC_GAMEPAUSE.SetWindowTextW(text);
		}
		else {
			CString text("继续游戏");
			JC_GAMEPAUSE.SetWindowTextW(text);
		}


		gamePause = !gamePause;
	}
}
void CEleDicGroupDlg::OnBnClickedJcGamestart()
{
	// TODO: 在此添加控件通知处理程序代码
	second = 60;
	socer = 0;
	timeNotStop = true;
	stoppingTime = 0;
	gameStart = true;
	gamePause = false;
	JC_SkillButton1.ShowWindow(true);
	JC_SKILL_BUTTON2.ShowWindow(true);
	JC_SKILLBUTTON3.ShowWindow(true);
	JC_SCORE_TITLE1.Format(_T("%d"), socer);

	correctAnsButton = rand()%4;
	for (int i = 0; i < 4; i++) {
		if (i == correctAnsButton)
			ansList[i] = true;
		else
			ansList[i] = false;
	}
	correctTopicPos = rand() % 7900;
	tempP = chToEng.next;
	while (correctTopicPos > 0) {
		tempP = tempP->next;
		correctTopicPos--;
	}
	CString correctEng(tempP->eng);
	CString topictitle(tempP->chn);
	JC_TopicTitle.Format(topictitle);
	UpdateData(false);

	if (ansList[0])
		JC_AnsButton1.SetWindowTextW(correctEng);
	else {
		int wrongAnsPos = rand() % 7900;
		tempP = chToEng.next;
		while (wrongAnsPos > 0) {
			tempP = tempP->next;
			wrongAnsPos--;
		}
		CString wrongEng(tempP->eng);
		JC_AnsButton1.SetWindowTextW(wrongEng);
	}

	if (ansList[1])
		JC_AnsButton2.SetWindowTextW(correctEng);
	else {
		int wrongAnsPos = rand() % 7900;
		tempP = chToEng.next;
		while (wrongAnsPos > 0) {
			tempP = tempP->next;
			wrongAnsPos--;
		}
		CString wrongEng(tempP->eng);
		JC_AnsButton2.SetWindowTextW(wrongEng);
	}

	if (ansList[2])
		JC_AnsButton3.SetWindowTextW(correctEng);
	else {
		int wrongAnsPos = rand() % 7900;
		tempP = chToEng.next;
		while (wrongAnsPos > 0) {
			tempP = tempP->next;
			wrongAnsPos--;
		}
		CString wrongEng(tempP->eng);
		JC_AnsButton3.SetWindowTextW(wrongEng);
	}

	if (ansList[3])
		JC_AnsButton4.SetWindowTextW(correctEng);
	else {
		int wrongAnsPos = rand() % 7900;
		tempP = chToEng.next;
		while (wrongAnsPos > 0) {
			tempP = tempP->next;
			wrongAnsPos--;
		}
		CString wrongEng(tempP->eng);
		JC_AnsButton4.SetWindowTextW(wrongEng);
	}

	UpdateData(false);
}
void CEleDicGroupDlg::OnBnClickedJcSkillbutton1()
{
	if (gameStart && !gamePause) {
		JC_SkillButton1.ShowWindow(false);
		int wrongAns, nums = 0;
		bool show[4] = { true,true,true,true };
		while (1) {
			if (nums == 2)
				break;
			wrongAns = rand() % 4;

			if (!ansList[0] && wrongAns == 0 && show[0]) {
				nums++;
				show[0] = false;
				JC_AnsButton1.ShowWindow(false);
			}

			if (!ansList[1] && wrongAns == 1 && show[1]) {
				nums++;
				show[1] = false;
				JC_AnsButton2.ShowWindow(false);
			}

			if (!ansList[2] && wrongAns == 2 && show[2]) {
				nums++;
				show[2] = false;
				JC_AnsButton3.ShowWindow(false);
			}

			if (!ansList[3] && wrongAns == 3 && show[3]) {
				nums++;
				show[3] = false;
				JC_AnsButton4.ShowWindow(false);
			}
		}
	}
}
void CEleDicGroupDlg::OnBnClickedJcSkillbutton2()
{
	// TODO: 在此添加控件通知处理程序代码
	if (gameStart && !gamePause) {
		JC_SKILL_BUTTON2.ShowWindow(false);
		timeNotStop = false;
	}
}
void CEleDicGroupDlg::OnBnClickedJcSkillbutton3()
{
	// TODO: 在此添加控件通知处理程序代码
	if (gameStart && !gamePause) {
		JC_SKILLBUTTON3.ShowWindow(false);

		correctAnsButton = rand() % 4;
		for (int i = 0; i < 4; i++) {
			if (i == correctAnsButton)
				ansList[i] = true;
			else
				ansList[i] = false;
		}
		correctTopicPos = rand() % 7900;
		tempP = chToEng.next;
		while (correctTopicPos > 0) {
			tempP = tempP->next;
			correctTopicPos--;
		}
		CString correctEng(tempP->eng);
		CString topictitle(tempP->chn);
		JC_TopicTitle.Format(topictitle);
		UpdateData(false);

		if (ansList[0])
			JC_AnsButton1.SetWindowTextW(correctEng);
		else {
			int wrongAnsPos = rand() % 7900;
			tempP = chToEng.next;
			while (wrongAnsPos > 0) {
				tempP = tempP->next;
				wrongAnsPos--;
			}
			CString wrongEng(tempP->eng);
			JC_AnsButton1.SetWindowTextW(wrongEng);
		}

		if (ansList[1])
			JC_AnsButton2.SetWindowTextW(correctEng);
		else {
			int wrongAnsPos = rand() % 7900;
			tempP = chToEng.next;
			while (wrongAnsPos > 0) {
				tempP = tempP->next;
				wrongAnsPos--;
			}
			CString wrongEng(tempP->eng);
			JC_AnsButton2.SetWindowTextW(wrongEng);
		}

		if (ansList[2])
			JC_AnsButton3.SetWindowTextW(correctEng);
		else {
			int wrongAnsPos = rand() % 7900;
			tempP = chToEng.next;
			while (wrongAnsPos > 0) {
				tempP = tempP->next;
				wrongAnsPos--;
			}
			CString wrongEng(tempP->eng);
			JC_AnsButton3.SetWindowTextW(wrongEng);
		}

		if (ansList[3])
			JC_AnsButton4.SetWindowTextW(correctEng);
		else {
			int wrongAnsPos = rand() % 7900;
			tempP = chToEng.next;
			while (wrongAnsPos > 0) {
				tempP = tempP->next;
				wrongAnsPos--;
			}
			CString wrongEng(tempP->eng);
			JC_AnsButton4.SetWindowTextW(wrongEng);
		}
	}
}

//打开_樊阳定义的增删词典子功能模块
void CEleDicGroupDlg::OnBnClickedOpensonfunctionexe()
{
	WinExec("fyMFCaddchange.exe", SW_NORMAL);
}
