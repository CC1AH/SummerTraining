
// Example1Dlg.h : 头文件
//

#pragma once


// CExample1Dlg 对话框
class CExample1Dlg : public CDialogEx
{
// 构造
public:
	CExample1Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_EXAMPLE1_DIALOG };

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
	
	afx_msg void OnEnChangeEdit4();
	CString word;
	afx_msg void OnLbnSelchangeList1();
	CString cn;
	CString cn2;
	CString word2;
	afx_msg void XW_2_jianting();
	afx_msg void XW_1_jianting();
};
