
// Example1Dlg.cpp : ʵ���ļ�
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

int wordsNumber =0;//��������Ŀ 
data dicSql[8000];//���ʿ� 

int loadSql(data *sql,char path[100]);/*���ص��ʿ�����*/
int printAction();/*����û���ʾ����*/
void dealAction(int action);/*����ָ�����*/
void dictation();/*��д���ʺ���*/
int searchWord(char word[20]);/*���ص����ڵ��ʿ��е�λ��*/
void searchCn(char cn[80]);/*�������ķ����ڵ��ʿ��е�λ��*/
void saveSql();/*�����ļ�����*/
void wordsBook();/*���ʱ�����*/ 
void game1();//Ͷ����С��Ϸ


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


// CExample1Dlg �Ի���



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


// CExample1Dlg ��Ϣ�������

BOOL CExample1Dlg::OnInitDialog()
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

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CExample1Dlg::OnPaint()
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
HCURSOR CExample1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



/*void CExample1Dlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	sum =x+y;
	UpdateData(FALSE);
}*/





void CExample1Dlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	strcpy(w,CW2A(word));//��CString���͵�wordת��Ϊ�ַ�����
	int pos =searchWord(w);
	if(pos!=-1)
	{
		cn = dicSql[pos].cn;
		UpdateData(FALSE);
	}
	else
	{
		cn = "δ�ҵ���";
		UpdateData(FALSE);
	}
}

/*���ص��ʿ�����*/
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

/*���ص����ڵ��ʿ��е�λ��*/
int searchWord(char word[20])
{
	wordsNumber =loadSql(dicSql,"dictionary.txt");
	/*�ö��ַ�����*/
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
	/*��˳����ҷ�����*/ 
	int i=0;
    for(i=0;i<wordsNumber;i++)
    {
        if(strcmp(dicSql[i].word,word)==0)
            return i;
    }
    return -1;//����Ҳ����ͷ���-1 
}