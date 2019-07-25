
// EleDic_GroupDlg.h: 头文件
//

#pragma once

// CEleDicGroupDlg 对话框
class CEleDicGroupDlg : public CDialogEx
{
// 构造
public:
	CEleDicGroupDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ELEDIC_GROUP_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedExit();
private:

	//Timer的辅助变量和控制变量
	int m_Seconds;
	CString m_timeEcho;
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);

	//熊伟_定义的辅助控制变量 用于控制单词查询框
	CString cn2;
	CString word;
	CString word2;
	CString cn;

	//熊伟_定义的监听函数 用于实现单词的查询
	afx_msg void XW_1_jianting();
	afx_msg void OnEnChangeEdit1();

	//邢国浩_定义的控制变量
	CString vip_code;
	//邢国好_定义的监听函数
	afx_msg void OnBnClickedInputConfirm();
	afx_msg void OnBnClickedViewraw();
	afx_msg void OnBnClickedTimeshowcmd();


	//樊阳_定义的控制变量 用于控制词库修改
	CString word1;
	CString cn1;
	CString output1;
	CString word21;
	CString word3;
	CString output2;
	//樊阳_定义的监听函数 用于控制词库修改
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();

	//熊伟_定义的控制变量 收藏夹
	CString favoritesAddEn;
	CString favoritesAddCn;
	CString deleteInputValue;
	afx_msg void OnBnClickedfavoritesaddword();
	afx_msg void OnBnClickedfavoritesopenbt();
	afx_msg void OnBnClickeddeletewordsbt();
	CString addResultValue;
	CString deleteResultValue;

	//常智裕_添加的控制变量 听写功能
	CString czy_judge;
	CString czy_word;
	afx_msg void OnBnClickedIdcButton1();
	CString czy_trans;
	afx_msg void OnBnClickedIdcButton4();
	afx_msg void OnBnClickedAboutbox();
	afx_msg void OnEnChangeEdit1Xw();

	//贾聪_定义的控制变量和应用变量
	CButton JC_AnsButton1;
	CButton JC_AnsButton2;
	CButton JC_AnsButton3;
	CButton JC_AnsButton4;
	CStatic JC_SCORE_TITLE;
	CString JC_SCORE_TITLE1;
	CString JC_TopicTitle;
	CStatic JC_TopicTitle1;
	CButton JC_SkillButton1;
	CButton JC_SKILL_BUTTON2;
	CButton JC_SKILLBUTTON3;
	CButton JC_GAMEPAUSE;
	FILE* fp;
	typedef struct linklist {
		char eng[40];
		char chn[50];
		struct linklist* next;
	}link;
	link chToEng, * p = &chToEng, * tempP;
	bool ansList[4];
	int second, correctAnsButton, correctTopicPos, tempTopicPos, topicHis[4];
	char eng[40];
	int socer;
	bool timeNotStop = true;
	int stoppingTime = 10;
	bool gameStart = false;
	bool gamePause = false;
	afx_msg void OnBnClickedJcAnsbutton1();
	afx_msg void OnBnClickedJcAnsbutton2();
	afx_msg void OnBnClickedJcAnsbutton4();
	afx_msg void OnBnClickedJcAnsbutton3();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedJcGamestart();
	afx_msg void OnBnClickedJcSkillbutton1();
	afx_msg void OnBnClickedJcSkillbutton2();
	afx_msg void OnBnClickedJcSkillbutton3();
	CString JC_TIMER_ECHO;
};
