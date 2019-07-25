
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
	CString vip_code;
	afx_msg void OnBnClickedInputConfirm();
	afx_msg void OnBnClickedViewraw();
	afx_msg void OnBnClickedTimeshowcmd();
};
