
// Example1Dlg.h : ͷ�ļ�
//

#pragma once


// CExample1Dlg �Ի���
class CExample1Dlg : public CDialogEx
{
// ����
public:
	CExample1Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_EXAMPLE1_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
