
// bluetoothDlg.h : 헤더 파일
//

#pragma once
#include "afxwin.h"
#include "Mycomm.h"

// CbluetoothDlg 대화 상자
class CbluetoothDlg : public CDialogEx
{
// 생성입니다.
	CMycomm* m_comm;

public:
       LRESULT      OnThreadClosed(WPARAM length, LPARAM lpara);

       LRESULT      OnReceive(WPARAM length, LPARAM lpara);
	CbluetoothDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
	enum { IDD = IDD_BLUETOOTH_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	BOOL comport_state;
	CComboBox m_combo_comport_list;
	CComboBox m_combo_baudrate_list;
	CString m_str_comport;
	CString m_str_baudrate;
	CEdit m_edit_rcv_view;
	CEdit m_edit_send_data;
	afx_msg void OnBnClickedBtConnect();
	afx_msg void OnCbnSelchangeComboComport();
	afx_msg void OnBnClickedBtClear();
	afx_msg void OnBnClickedBtSend();
	int m_nNum1;
	int m_nNum2;
	int m_nReulst_x_1;
	int m_nResult_1_y;
	int m_nResult_2_x;
	int m_nResult_2_y;
	int m_nResult_3_x;
	int m_nResult_3_y;
	int m_nResult_tri_x_1;
	int m_nResult_tri_y_1;
	int m_nResult_tri_2_x;
	int m_nReulst_tri_2_y;
	afx_msg void OnBnClickedButtonSquare();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButtonTri();
	afx_msg void OnEnChangeEditBiX();
	afx_msg void OnEnChangeEditBiY();
	CString gray_to_decimal_x;
	CString gray_to_decimal_y;
	int m_gray_x;
	CString m_gray_x1;
	CString m_gray_y1;
	int m_decimal_x;
	int m_decimal_y;
	afx_msg void OnBnClickedButtonTrans();
	int m_gray_x11;
	int m_gray_y11;
	int m_gray_x111;
	int m_gray_y111;
	int m_gray_Y;
	int m_gray_y;
	afx_msg void OnBnClickedButtonTrans2();
	afx_msg void OnBnClickedButtonTrans3();
	afx_msg void OnBnClickedButtonTrans4();
	afx_msg void OnBnClickedButtonTrans7();
	afx_msg void OnBnClickedButtonTrans8();
	afx_msg void OnBnClickedButtonTrans6();
	afx_msg void OnBnClickedButtonTrans5();
	int Stand_X;
	int Stand_Y;
	int x2;
	int y2;
	int x3;
	int y3;
	int x4;
	int y4;
	afx_msg void OnBnClickedButton1();
	int Goal_X;
	int Goal_Y;
	int LEFT_DOWN_X;
	int LEFT_DOWN_Y;
	int LEFT_UP_X;
	int LEFT_UP_Y;
	int RIGHT_UP_X;
	int RIGHT_UP_Y;
	int RIGHT_DOWN_X;
	int RIGHT_DOWN_Y;
	afx_msg void OnBnClickedButton2();
	int LEFT_UP_ANG;
	int LEFT_UP_DISTANCE;
	int RIGHT_UP_ANG;
	int RIGHT_UP_DISTANCE;
	int LEFT_DOWN_ANG;
	int LEFT_DOWN_DISTANCE;
	int RIGHT_DOWN_ANG;
	int RIGHT_DOWN_DISTANCE;
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();
	int LEFT_UP_X1;
	int LEFT_UP_Y1;
	int LEFT_UP_Y2;
	int LEFT_UP_Y3;
	int LEFT_UP_X2;
	int LEFT_UP_X3;
	int RIGHT_UP_X1;
	int RIGHT_UP_X2;
	int RIGHT_UP_X3;
	int RIGHT_UP_Y1;
	int RIGHT_UP_Y2;
	int RIGHT_UP_Y3;
	int LEFT_DOWN_X1;
	int LEFT_DOWN_X2;
	int LEFT_DOWN_X3;
	int LEFT_DOWN_Y1;
	int LEFT_DOWN_Y2;
	int LEFT_DOWN_Y3;
	int RIGHT_DOWN_X1;
	int RIGHT_DOWN_X2;
	int RIGHT_DOWN_X3;
	int RIGHT_DOWN_Y1;
	int RIGHT_DOWN_Y2;
	int RIGHT_DOWN_Y3;
	afx_msg void OnBnClickedButton10();
	afx_msg void OnBnClickedButton11();
	afx_msg void OnBnClickedButton12();
	afx_msg void OnBnClickedButton13();
	afx_msg void OnBnClickedButton14();
	afx_msg void OnBnClickedButton18();
	afx_msg void OnBnClickedButton16();
	afx_msg void OnBnClickedButton20();
	afx_msg void OnBnClickedButton15();
	afx_msg void OnBnClickedButton19();
	afx_msg void OnBnClickedButton17();
	afx_msg void OnBnClickedButton21();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnEnChangeEdit50();
	afx_msg void OnEnChangeEdit14();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton22();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton24();
	afx_msg void OnEnChangeEdit38();
	afx_msg void OnBnClickedButton23();
	afx_msg void OnBnClickedButton25();
	afx_msg void OnBnClickedButton26();
	afx_msg void OnBnClickedButton29();
	afx_msg void OnBnClickedButton31();
	afx_msg void OnBnClickedButton27();
	afx_msg void OnBnClickedButton28();
	afx_msg void OnBnClickedButton30();
	afx_msg void OnBnClickedButton32();
	afx_msg void OnBnClickedButton33();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedButton34();
	int Leng;
	afx_msg void OnBnClickedButton35();
	afx_msg void OnBnClickedButton38();
	afx_msg void OnBnClickedButton39();
	int P_DIS;
	int P_ANG;
	afx_msg void OnBnClickedButton36();
	afx_msg void OnBnClickedButton37();
	int P2_X;
	int P2_Y;
	afx_msg void OnBnClickedButton40();
	afx_msg void OnBnClickedBtSend2();
	afx_msg void OnBnClickedBtSend3();
	afx_msg void OnBnClickedBtSend4();
};
