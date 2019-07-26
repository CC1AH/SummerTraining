
// dictionaryDlg.cpp : ʵ���ļ�
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
struct dictionary//�ʿ�
{
	char word[50];
	char cn[50];

};
int num;//�ʿⵥ������ 
struct dictionary dic[10000];


void add(struct dictionary dic[],char key1[],char key2[],int num);


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


// CdictionaryDlg �Ի���



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


// CdictionaryDlg ��Ϣ�������

BOOL CdictionaryDlg::OnInitDialog()
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CdictionaryDlg::OnPaint()
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
HCURSOR CdictionaryDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CdictionaryDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	int i=0;
	FILE *fPtr;
	fPtr = fopen("d:\\dictionary.txt","r");
	if(fPtr== NULL){
		output1="���ʧ��";
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
	char word1tmp[20];//������ʱ����¼ӵĵ���
	char cn1tmp[20];//������ʱ����¼ӵĵ��ʵ����Ľ���	
	strcpy(word1tmp,CW2A(word1));
	strcpy(cn1tmp,CW2A(cn1));
	strcpy(dic[num].word,word1tmp);
	strcpy(dic[num].cn,cn1tmp);
	if(dic[num].word!=NULL&&dic[num].cn!=NULL)//�ж���ӵ���֮���Ƿ���ӳɹ�
	{output1="��ӳɹ�";
	num+=1;
	}
	else
		output1="���ʧ��";
		 	
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
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

//#1015

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CdictionaryDlg::OnEnChangeEdit2()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

//#1015

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CdictionaryDlg::OnEnChangeEdit3()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

//#1015

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}



void CdictionaryDlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	int i=0;
	int flag=0;
	FILE *fPtr;
	fPtr = fopen("d:\\dictionary.txt","r");
	if(fPtr== NULL){
		output2="�ļ���ʧ��";
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
	//output2="�޸�ʧ�ܣ��ʿ���û�иĵ���";
	for(i=0;i<num;i++)
	{
		if(strcmp(dic[i].word,word2tmp)==0)
		{			
		    strcpy(dic[i].word,word3tmp);
			flag=1;
		}
	}
	if(flag==1)
		output2="�޸ĳɹ�";
	else
		output2="�޸�ʧ�ܣ��ʿ���û�иõ���"; 
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


int loadword(struct dictionary dic[])  //����һӢ�Ķ�Ӧ�����ĵĴʿ�
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
		 printf("��ȡ�ɹ���\n");		
	}
	fclose(fPtr);
	return i;

}
