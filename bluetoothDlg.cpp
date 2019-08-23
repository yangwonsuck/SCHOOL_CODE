
// bluetoothDlg.cpp : ���� ����
//
//�ﰢ��
#include "stdafx.h"
#include "bluetooth.h"
#include "bluetoothDlg.h"
#include "afxdialogex.h"
#include "windows.h"
#include "resource.h"
#include "math.h"
#include <stdlib.h>
#include <stdio.h>
#define SWAP(a,b){int t;t=a;a=b;b=t;}
void InsertionSort(int *base,int n)
{
	int i,j;
	for(i=1;i<n;i++)
	{
		for(j=i;j>0;j--)
		{
			if(base[j-1]>base[j])
			{
				SWAP(base[j-1],base[j]);
			}
			else
			{
				break;
			}
		}
	}
}
#ifdef _DEBUG
#define new DEBUG_NEW
#endif
struct position
{
	char name;
	char dir;
	char angle;
	char distance;
};
// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.
struct position a1;
struct position b1;
struct position d1;

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// �����Դϴ�.
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


// CbluetoothDlg ��ȭ ����

CbluetoothDlg::CbluetoothDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CbluetoothDlg::IDD, pParent)
	, m_str_comport(_T(""))
	, m_str_baudrate(_T(""))
	, Stand_X(0)
	, Stand_Y(0)
	, x2(0)
	, y2(0)
	, x3(0)
	, y3(0)
	, Goal_X(0)
	, Goal_Y(0)
	, LEFT_DOWN_X(0)
	, LEFT_DOWN_Y(0)
	, LEFT_UP_X(0)
	, LEFT_UP_Y(0)
	, RIGHT_UP_X(0)
	, RIGHT_UP_Y(0)
	, LEFT_UP_ANG(0)
	, LEFT_UP_DISTANCE(0)
	, RIGHT_UP_ANG(0)
	, RIGHT_UP_DISTANCE(0)
	, LEFT_DOWN_ANG(0)
	, LEFT_DOWN_DISTANCE(0)
	, LEFT_UP_X1(0)
	, LEFT_UP_Y1(0)
	, LEFT_UP_Y2(0)
	, LEFT_UP_X2(0)
	, RIGHT_UP_X1(0)
	, RIGHT_UP_X2(0)
	, RIGHT_UP_Y1(0)
	, RIGHT_UP_Y2(0)
	, LEFT_DOWN_X1(0)
	, LEFT_DOWN_X2(0)
	, LEFT_DOWN_Y1(0)
	, LEFT_DOWN_Y2(0)
	, Leng(0)
	, P_DIS(0)
	, P_ANG(0)
	, P2_X(0)
	, P2_Y(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CbluetoothDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_COMPORT, m_combo_comport_list);
	DDX_Control(pDX, IDC_COMBO_BAUDRATE, m_combo_baudrate_list);
	DDX_CBString(pDX, IDC_COMBO_COMPORT, m_str_comport);
	DDX_CBString(pDX, IDC_COMBO_BAUDRATE, m_str_baudrate);
	DDX_Control(pDX, IDC_EDIT_RCV_VIEW, m_edit_rcv_view);
	DDX_Control(pDX, IDC_EDIT_SEND_DATA, m_edit_send_data);
	DDX_Text(pDX, IDC_EDIT1, Stand_X);
	DDX_Text(pDX, IDC_EDIT2, Stand_Y);
	DDX_Text(pDX, IDC_EDIT15, x2);
	DDX_Text(pDX, IDC_EDIT16, y2);
	DDX_Text(pDX, IDC_EDIT17, x3);
	DDX_Text(pDX, IDC_EDIT18, y3);
	DDX_Text(pDX, IDC_EDIT4, Goal_X);
	DDX_Text(pDX, IDC_EDIT6, Goal_Y);
	DDX_Text(pDX, IDC_EDIT9, LEFT_DOWN_X);
	DDX_Text(pDX, IDC_EDIT7, LEFT_DOWN_Y);
	DDX_Text(pDX, IDC_EDIT5, LEFT_UP_X);
	DDX_Text(pDX, IDC_EDIT8, LEFT_UP_Y);
	DDX_Text(pDX, IDC_EDIT11, RIGHT_UP_X);
	DDX_Text(pDX, IDC_EDIT12, RIGHT_UP_Y);
	DDX_Text(pDX, IDC_EDIT14, LEFT_UP_ANG);
	DDX_Text(pDX, IDC_EDIT21, LEFT_UP_DISTANCE);
	DDX_Text(pDX, IDC_EDIT22, RIGHT_UP_ANG);
	DDX_Text(pDX, IDC_EDIT23, RIGHT_UP_DISTANCE);
	DDX_Text(pDX, IDC_EDIT24, LEFT_DOWN_ANG);
	DDX_Text(pDX, IDC_EDIT25, LEFT_DOWN_DISTANCE);
	DDX_Text(pDX, IDC_EDIT28, LEFT_UP_X1);
	DDX_Text(pDX, IDC_EDIT29, LEFT_UP_Y1);
	DDX_Text(pDX, IDC_EDIT37, LEFT_UP_Y2);
	DDX_Text(pDX, IDC_EDIT36, LEFT_UP_X2);
	DDX_Text(pDX, IDC_EDIT31, RIGHT_UP_X1);
	DDX_Text(pDX, IDC_EDIT40, RIGHT_UP_X2);
	DDX_Text(pDX, IDC_EDIT33, RIGHT_UP_Y1);
	DDX_Text(pDX, IDC_EDIT41, RIGHT_UP_Y2);
	DDX_Text(pDX, IDC_EDIT30, LEFT_DOWN_X1);
	DDX_Text(pDX, IDC_EDIT38, LEFT_DOWN_X2);
	DDX_Text(pDX, IDC_EDIT32, LEFT_DOWN_Y1);
	DDX_Text(pDX, IDC_EDIT39, LEFT_DOWN_Y2);
	DDX_Text(pDX, IDC_EDIT3, Leng);
	DDX_Text(pDX, IDC_EDIT10, P_DIS);
	DDX_Text(pDX, IDC_EDIT13, P_ANG);
	DDX_Text(pDX, IDC_EDIT26, P2_X);
	DDX_Text(pDX, IDC_EDIT27, P2_Y);
}
BEGIN_MESSAGE_MAP(CbluetoothDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_MESSAGE(WM_MYCLOSE, &CbluetoothDlg::OnThreadClosed)
    ON_MESSAGE(WM_MYRECEIVE,&CbluetoothDlg::OnReceive)
	ON_BN_CLICKED(IDC_BT_CONNECT, &CbluetoothDlg::OnBnClickedBtConnect)
	ON_CBN_SELCHANGE(IDC_COMBO_COMPORT, &CbluetoothDlg::OnCbnSelchangeComboComport)
	ON_BN_CLICKED(IDC_BT_CLEAR, &CbluetoothDlg::OnBnClickedBtClear)
	ON_BN_CLICKED(IDC_BT_SEND, &CbluetoothDlg::OnBnClickedBtSend)
	ON_EN_CHANGE(IDC_EDIT_BI_X, &CbluetoothDlg::OnEnChangeEditBiX)
	ON_EN_CHANGE(IDC_EDIT_BI_Y, &CbluetoothDlg::OnEnChangeEditBiY)
	ON_BN_CLICKED(IDC_BUTTON1, &CbluetoothDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CbluetoothDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CbluetoothDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON10, &CbluetoothDlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON14, &CbluetoothDlg::OnBnClickedButton14)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON4, &CbluetoothDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON23, &CbluetoothDlg::OnBnClickedButton23)
	ON_BN_CLICKED(IDC_BUTTON25, &CbluetoothDlg::OnBnClickedButton25)
	ON_BN_CLICKED(IDC_BUTTON26, &CbluetoothDlg::OnBnClickedButton26)
	ON_BN_CLICKED(IDC_BUTTON27, &CbluetoothDlg::OnBnClickedButton27)
	ON_BN_CLICKED(IDC_BUTTON28, &CbluetoothDlg::OnBnClickedButton28)
	//ON_EN_CHANGE(IDC_EDIT1, &CbluetoothDlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON34, &CbluetoothDlg::OnBnClickedButton34)
	ON_BN_CLICKED(IDC_BUTTON35, &CbluetoothDlg::OnBnClickedButton35)
	ON_BN_CLICKED(IDC_BUTTON40, &CbluetoothDlg::OnBnClickedButton40)
	ON_BN_CLICKED(IDC_BT_SEND2, &CbluetoothDlg::OnBnClickedBtSend2)
	ON_BN_CLICKED(IDC_BT_SEND3, &CbluetoothDlg::OnBnClickedBtSend3)
	ON_BN_CLICKED(IDC_BT_SEND4, &CbluetoothDlg::OnBnClickedBtSend4)
END_MESSAGE_MAP()


// CbluetoothDlg �޽��� ó����
LRESULT CbluetoothDlg::OnThreadClosed(WPARAM length, LPARAM lpara)
{
        //overlapped i/o �ڵ����ݴ´�.

        ((CMycomm*)lpara)->HandleClose();

        delete ((CMycomm*)lpara);

 

        return 0;

}
int a=0,b=0,c=0,d=0,e=0,f=0;
int fix=1;
int fix2=1;
int sum=0;
char copy[7];
LRESULT CbluetoothDlg::OnReceive(WPARAM length, LPARAM lpara)
{
        CString str;
		CString str2;
		char data[200];
		char copied[200];
		a1.name='P';
		b1.name='Q';
		d1.name='S';
        if(m_comm)
        {
               m_comm->Receive(data,length); //length ���̸�ŭ�����͸��޴´�.
               data[length]=_T('\0');
               str+=_T("\r\r");
			   strcpy_s(copied, data);
               for(int i = 0;i<(int)length;i++)
               {
                       str+=copied[i];
					   copied[i] =str[i+1];
               }
			   
			   if((int)length==8)
			   {
				   if(copied[2]=='S')
					{
						e=copied[3]+copied[4];
						f=copied[5]+copied[6];
						if(fix)
						{
							x3=e;
							y3=f;
						}
					}
				   else if(copied[2]=='P')
					{
						a=copied[3]+copied[4];
						b=copied[5]+copied[6];
							if((fix==1)&&(fix2==1))
							{
								Stand_X=a;
								Stand_Y=b;
								P2_X=a;
								P2_Y=b;
							}
							else if((fix==1)&&(fix2==0))
							{
								P2_X=a;
								P2_Y=b;
							}
							P_DIS=sqrt((double)((P2_X-Stand_X)*(P2_X-Stand_X)+(P2_Y-Stand_Y)*(P2_Y-Stand_Y)));
							P_ANG=atan2((double)(P2_Y-Stand_Y),(double)(P2_X-Stand_X))*180/3.141592;
							P_ANG=-P_ANG+90;
							if(P_ANG<0)
								P_ANG+=360;
					}
					else if(copied[2]=='Q')
					{
						c=copied[3]+copied[4];
						d=copied[5]+copied[6];
						if(fix)
						{
							x2=c;
							y2=d;
						}
					}
			   }

			   else if((int)length == 7)
			   {
				if(copied[1]=='P')
				{
					a=copied[2]+copied[3];
					b=copied[4]+copied[5];
					if((fix==1)&&(fix2==1))
					{
						Stand_X=a;
						Stand_Y=b;
						P2_X=a;
						P2_Y=b;
					}
					else if((fix==1)&&(fix2==0))
					{
						P2_X=a;
						P2_Y=b;
					}
					P_DIS=sqrt((double)((P2_X-Stand_X)*(P2_X-Stand_X)+(P2_Y-Stand_Y)*(P2_Y-Stand_Y)));
					P_ANG=atan2((double)(P2_Y-Stand_Y),(double)(P2_X-Stand_X))*180/3.141592;
					P_ANG=-P_ANG+90;
					if(P_ANG<0)
								P_ANG+=360;
				}
				else if(copied[1]=='Q')
				{
					c=copied[2]+copied[3];
					d=copied[4]+copied[5];
					if(fix)
					{
						x2=c;
						y2=d;
					}
				}
				else if(copied[1]=='S')
				{
					e=copied[2]+copied[3];
					f=copied[4]+copied[5];
					if(fix)
					{
						x3=e;
						y3=f;
					}
				}
			}
			   Leng=length;
               m_edit_rcv_view.ReplaceSel(str); //����Ʈ�ڽ���ǥ���ϱ�����/
               UpdateData(FALSE);
               m_edit_rcv_view.LineScroll(m_edit_rcv_view.GetLineCount());
        }
        return 0;
}
BOOL CbluetoothDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.
	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
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

	// �� ��ȭ ������ �������� �����մϴ�. ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.
	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	m_combo_comport_list.AddString(_T("COM1"));
    m_combo_comport_list.AddString(_T("COM2"));
    m_combo_comport_list.AddString(_T("COM3"));
    m_combo_comport_list.AddString(_T("COM4"));
	m_combo_comport_list.AddString(_T("COM16"));
    m_combo_comport_list.AddString(_T("COM17"));
    m_combo_comport_list.AddString(_T("COM18"));
    m_combo_comport_list.AddString(_T("COM19"));
	m_combo_comport_list.AddString(_T("COM20"));
    m_combo_comport_list.AddString(_T("COM21"));
    m_combo_comport_list.AddString(_T("COM22"));
    m_combo_comport_list.AddString(_T("COM23"));
	m_combo_comport_list.AddString(_T("COM24"));
    m_combo_comport_list.AddString(_T("COM25"));
    m_combo_comport_list.AddString(_T("COM26"));
    m_combo_comport_list.AddString(_T("COM27"));
	m_combo_comport_list.AddString(_T("COM28"));
    m_combo_comport_list.AddString(_T("COM29"));
    m_combo_comport_list.AddString(_T("COM30"));
    m_combo_comport_list.AddString(_T("COM31"));
	m_combo_comport_list.AddString(_T("COM32"));
    m_combo_comport_list.AddString(_T("COM33"));
    m_combo_comport_list.AddString(_T("COM34"));
    m_combo_comport_list.AddString(_T("COM35"));
    m_combo_baudrate_list.AddString(_T("9600"));
    m_combo_baudrate_list.AddString(_T("19200"));
    m_combo_baudrate_list.AddString(_T("115200"));

	comport_state=false;

       GetDlgItem(IDC_BT_CONNECT)->SetWindowText(_T("OPEN"));

       m_str_comport = _T("COM23");

       m_str_baudrate = _T("9600");

       UpdateData(FALSE);
	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

void CbluetoothDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�. ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CbluetoothDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR CbluetoothDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CbluetoothDlg::OnBnClickedBtConnect()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if(comport_state)

         {

                  if(m_comm)        //����Ʈ�������ϸ�

                  {

                           m_comm->Close();

                           m_comm = NULL;

                           AfxMessageBox(_T("COM ��Ʈ����"));

                           comport_state=false;

                           GetDlgItem(IDC_BT_CONNECT)->SetWindowText(_T("OPEN"));

                           GetDlgItem(IDC_BT_SEND)->EnableWindow(false);

                  }

         }

         else

         {

                  m_comm= new CMycomm(_T("\\\\.\\")+m_str_comport,m_str_baudrate,_T("None"),_T("8 Bit"),_T("1 Bit"));         // initial Comm port

                  if(      m_comm->Create(GetSafeHwnd()) != 0) //�����Ʈ���������������ڵ����ѱ��.

                  {

                           AfxMessageBox(_T("COM ��Ʈ����"));

                           comport_state=true;

                           GetDlgItem(IDC_BT_CONNECT)->SetWindowText(_T("CLOSE"));

                           GetDlgItem(IDC_BT_SEND)->EnableWindow(true);

                  }

                  else

                  {

                           AfxMessageBox(_T("ERROR!"));

                  }

 

         }
}


void CbluetoothDlg::OnCbnSelchangeComboComport()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData();
}


void CbluetoothDlg::OnBnClickedBtClear()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	GetDlgItem(IDC_EDIT_RCV_VIEW)->SetWindowText(_T(" "));
}
bool move =1;
void CbluetoothDlg::OnBnClickedBtSend()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	int array1[3]={LEFT_UP_DISTANCE,RIGHT_UP_DISTANCE,LEFT_DOWN_DISTANCE};
	InsertionSort(array1,3);
	if(LEFT_UP_DISTANCE==array1[0])
	{
		if((0<=  LEFT_UP_ANG) &&(LEFT_UP_ANG <=180))
							{
								b1.name='Q';
								b1.dir='R';
								b1.distance=LEFT_UP_DISTANCE;
								b1.angle=LEFT_UP_ANG;
							}
							else if((181<=LEFT_UP_ANG)&&(LEFT_UP_ANG<=360))
							{
								b1.name='Q';
								b1.dir='L';
								b1.distance=LEFT_UP_DISTANCE;
								b1.angle=LEFT_UP_ANG-180;
							}
	}
	else if(RIGHT_UP_DISTANCE==array1[0])
	{
		if((0<=RIGHT_UP_ANG)&&(RIGHT_UP_ANG<=180))
							{
								b1.name='Q';
								b1.dir='R';
								b1.distance=RIGHT_UP_DISTANCE;
								b1.angle=RIGHT_UP_ANG;
							}
							else if((181<=RIGHT_UP_ANG)&&(RIGHT_UP_ANG<=360))
							{
								b1.name='Q';
								b1.dir='L';
								b1.distance=RIGHT_UP_DISTANCE;
								b1.angle=RIGHT_UP_ANG-180;
							}
	}
	else if(LEFT_DOWN_DISTANCE==array1[0])
	{
		if((0<=LEFT_DOWN_ANG)&&(LEFT_DOWN_ANG<=180))
							{
								b1.name='Q';
								b1.dir='R';
								b1.distance=LEFT_DOWN_DISTANCE;
								b1.angle=LEFT_DOWN_ANG;
							}
							else if((181<=LEFT_DOWN_ANG)&&(LEFT_DOWN_ANG<=360))
							{
								b1.name='Q';
								b1.dir='L';
								b1.distance=LEFT_DOWN_DISTANCE;
								b1.angle=LEFT_DOWN_ANG-180;
							}
	}
	int array2[3]={RIGHT_UP_Y1,LEFT_DOWN_Y1,LEFT_UP_Y1};
	InsertionSort(array2,3);
	if(RIGHT_UP_Y1==array2[0])
	{
							if((0<=RIGHT_UP_X1)&&(RIGHT_UP_X1<=180))
							{
								a1.name='P';
								a1.dir='R';
								a1.distance=RIGHT_UP_Y1;
								a1.angle=RIGHT_UP_X1;
							}
							else if((181<=RIGHT_UP_X1)&&(RIGHT_UP_X1<=360))
							{
								a1.name='P';
								a1.dir='L';
								a1.distance=RIGHT_UP_Y1;
								a1.angle=RIGHT_UP_X1-180;
							}
	}
	else if(LEFT_DOWN_Y1==array2[0])
	{
							if((0<=LEFT_DOWN_X1)&&(LEFT_DOWN_X1<=180))
							{
								a1.name='P';
								a1.dir='R';
								a1.distance=LEFT_DOWN_Y1;
								a1.angle=LEFT_DOWN_X1;
							}
							else if((181<=LEFT_DOWN_X1)&&(LEFT_DOWN_X1<=360))
							{
								a1.name='P';
								a1.dir='L';
								a1.distance=LEFT_DOWN_Y1;
								a1.angle=LEFT_DOWN_X1-180;
							}
	}
	else if(LEFT_UP_Y1==array2[0])
	{
							if((0<=LEFT_UP_X1)&&(LEFT_UP_X1<=180))
							{
								a1.name='P';
								a1.dir='R';
								a1.distance=LEFT_UP_Y1;
								a1.angle=LEFT_UP_X1;
							}
							else if((181<=LEFT_UP_X1)&&(LEFT_UP_X1<=360))
							{
								a1.name='P';
								a1.dir='L';
								a1.distance=LEFT_UP_Y1;
								a1.angle=LEFT_UP_X1-180;
							}
	}
	int array3[3]={RIGHT_UP_Y2,LEFT_DOWN_Y2,LEFT_UP_Y2};
	InsertionSort(array3,3);
	if(RIGHT_UP_Y2==array3[0])
	{
							if((0<=RIGHT_UP_X2)&&(RIGHT_UP_X2<=180))
							{
								d1.name='S';
								d1.dir='R';
								d1.distance=RIGHT_UP_Y2;
								d1.angle=RIGHT_UP_X2;
							}
							else if((181<=RIGHT_UP_X2)&&(RIGHT_UP_X2<=360))
							{
								d1.name='S';
								d1.dir='L';
								d1.distance=RIGHT_UP_Y2;
								d1.angle=RIGHT_UP_X2-180;
							}
	}
	else if(LEFT_DOWN_Y2==array3[0])
	{
							if((0<=LEFT_DOWN_X2)&&(LEFT_DOWN_X2<=180))
							{
								d1.name='S';
								d1.dir='R';
								d1.distance=LEFT_DOWN_Y2;
								d1.angle=LEFT_DOWN_X2;
							}
							else if((181<=LEFT_DOWN_X2)&&(LEFT_DOWN_X2<=360))
							{
								d1.name='S';
								d1.dir='L';
								d1.distance=LEFT_DOWN_Y2;
								d1.angle=LEFT_DOWN_X2-180;
							}
	}
	else if(LEFT_UP_Y2==array3[0])
	{
							if((0<=LEFT_UP_X2)&&(LEFT_UP_X2<=180))
							{
								d1.name='S';
								d1.dir='R';
								d1.distance=LEFT_UP_Y2;
								d1.angle=LEFT_UP_X2;
							}
							else if((181<=LEFT_UP_X2)&&(LEFT_UP_X2<=360))
							{
								d1.name='S';
								d1.dir='L';
								d1.distance=LEFT_UP_Y2;
								d1.angle=LEFT_UP_X2-180;
							}
	}
	
		move=1;
		SetTimer(1,300,NULL);
		
		//UpdateData(FALSE);
}
void CbluetoothDlg::OnEnChangeEditBiX()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialogEx::OnInitDialog() �Լ��� ������ 
	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
	// �� �˸� �޽����� ������ �ʽ��ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CbluetoothDlg::OnEnChangeEditBiY()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialogEx::OnInitDialog() �Լ��� ������ 
	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
	// �� �˸� �޽����� ������ �ʽ��ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}

void CbluetoothDlg::OnBnClickedButton1()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);
	if(fix)
		fix=0;
	else
		fix=1;
	UpdateData(FALSE);
}


void CbluetoothDlg::OnBnClickedButton2()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);
	LEFT_DOWN_X=Goal_X;
	LEFT_DOWN_Y=Goal_Y;
	LEFT_UP_X=Goal_X+50;
	LEFT_UP_Y=Goal_Y;
	RIGHT_UP_X=Goal_X+25;
	RIGHT_UP_Y=Goal_Y+25;
	UpdateData(FALSE);
}


void CbluetoothDlg::OnBnClickedButton3()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	int left_up_dis;
	int left_up_ang;
    left_up_dis=sqrt((double)((LEFT_UP_X-x2)*(LEFT_UP_X-x2)+(LEFT_UP_Y-y2)*(LEFT_UP_Y-y2)));
	left_up_ang=atan2((double)(LEFT_UP_Y-y2),(double)(LEFT_UP_X-x2))*180/3.141592;
	left_up_ang=-left_up_ang+90;
	if(left_up_ang<0)
	{
		left_up_ang=left_up_ang+360;
	}
	LEFT_UP_ANG=left_up_ang;  //
	LEFT_UP_DISTANCE=left_up_dis;  //


	int right_up_dis;
	int right_up_ang;
    right_up_dis=sqrt((double)((RIGHT_UP_X-x2)*(RIGHT_UP_X-x2)+(RIGHT_UP_Y-y2)*(RIGHT_UP_Y-y2)));
	right_up_ang=atan2((double)(RIGHT_UP_Y-y2),(double)(RIGHT_UP_X-x2))*180/3.141592;
	right_up_ang=-right_up_ang+90;

	if(right_up_ang<0)
	{
		right_up_ang=right_up_ang+360;
	}
	else if(right_up_ang>=360)
	{
		right_up_ang=right_up_ang-360;
	}
	RIGHT_UP_ANG=right_up_ang;  //
	RIGHT_UP_DISTANCE=right_up_dis;  //


	int left_down_dis;
	int left_down_ang;
    left_down_dis=sqrt((double)((LEFT_DOWN_X-x2)*(LEFT_DOWN_X-x2)+(LEFT_DOWN_Y-y2)*(LEFT_DOWN_Y-y2)));
	left_down_ang=atan2((double)(LEFT_DOWN_Y-y2),(double)(LEFT_DOWN_X-x2))*180/3.141592;
	left_down_ang=-left_down_ang+90;
	if(left_down_ang<0)
	{
		left_down_ang=left_down_ang+360;
	}
	else if(left_down_ang>=360)
	{
		left_down_ang=left_down_ang-360;
	}
	LEFT_DOWN_ANG=left_down_ang; //
	LEFT_DOWN_DISTANCE=left_down_dis; //

	UpdateData(FALSE);
}

void CbluetoothDlg::OnBnClickedButton10()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	int left_up_disH;
	int left_up_angH;
    left_up_disH=sqrt((double)((LEFT_UP_X-Stand_X)*(LEFT_UP_X-Stand_X)+(LEFT_UP_Y-Stand_Y)*(LEFT_UP_Y-Stand_Y)));
	left_up_angH=atan2((double)(LEFT_UP_Y-Stand_Y),(double)(LEFT_UP_X-Stand_X))*180/3.141592;
	left_up_angH=-left_up_angH+90;
	if(left_up_angH<0)
	{
		left_up_angH=left_up_angH+360;
	}
	else if(left_up_angH>=360)
	{
		left_up_angH=left_up_angH-360;
	}
	LEFT_UP_X1=left_up_angH;  //
	LEFT_UP_Y1=left_up_disH;  //


	int right_up_disJ;
	int right_up_angJ;
    right_up_disJ=sqrt((double)((RIGHT_UP_X-Stand_X)*(RIGHT_UP_X-Stand_X)+(RIGHT_UP_Y-Stand_Y)*(RIGHT_UP_Y-Stand_Y)));
	right_up_angJ=atan2((double)(RIGHT_UP_Y-Stand_Y),(double)(RIGHT_UP_X-Stand_X))*180/3.141592;
	right_up_angJ=-right_up_angJ+90;
	if(right_up_angJ<0)
	{
		right_up_angJ=right_up_angJ+360;
	}
	else if(right_up_angJ>=360)
	{
		right_up_angJ=right_up_angJ-360;
	}
	RIGHT_UP_X1=right_up_angJ;  //
	RIGHT_UP_Y1=right_up_disJ;   //
	
	int left_down_disL;
	int left_down_angL;
    left_down_disL=sqrt((double)((LEFT_DOWN_X-Stand_X)*(LEFT_DOWN_X-Stand_X)+(LEFT_DOWN_Y-Stand_Y)*(LEFT_DOWN_Y-Stand_Y)));
	left_down_angL=atan2((double)(LEFT_DOWN_Y-Stand_Y),(double)(LEFT_DOWN_X-Stand_X))*180/3.141592;
	left_down_angL=-left_down_angL+90;
	if(left_down_angL<0)
	{
		left_down_angL=left_down_angL+360;
	}
	else if(left_down_angL>=360)
	{
		left_down_angL=left_down_angL-360;
	}
	LEFT_DOWN_X1=left_down_angL;  //
	LEFT_DOWN_Y1=left_down_disL;  //


	UpdateData(FALSE);
}
void CbluetoothDlg::OnBnClickedButton14()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	int left_up_disP;
	int left_up_angP;
    left_up_disP=sqrt((double)((LEFT_UP_X-x3)*(LEFT_UP_X-x3)+(LEFT_UP_Y-y3)*(LEFT_UP_Y-y3)));
	left_up_angP=atan2((double)(LEFT_UP_Y-y3),(double)(LEFT_UP_X-x3))*180/3.141592;
	left_up_angP=-left_up_angP+90;
	if(left_up_angP<0)
	{
		left_up_angP=left_up_angP+360;
	}
	else if(left_up_angP>=360)
	{
		left_up_angP=left_up_angP-360;
	}
	LEFT_UP_X2=left_up_angP; //
	LEFT_UP_Y2=left_up_disP; //



	int right_up_disQ;
	int right_up_angQ;
    right_up_disQ=sqrt((double)((RIGHT_UP_X-x3)*(RIGHT_UP_X-x3)+(RIGHT_UP_Y-y3)*(RIGHT_UP_Y-y3)));
	right_up_angQ=atan2((double)(RIGHT_UP_Y-y3),(double)(RIGHT_UP_X-x3))*180/3.141592;
	right_up_angQ=-right_up_angQ+90;
	if(right_up_angQ<0)
	{
		right_up_angQ=right_up_angQ+360;
	}
	else if(right_up_angQ>=360)
	{
		right_up_angQ=right_up_angQ-360;
	}
	RIGHT_UP_X2=right_up_angQ;  //
	RIGHT_UP_Y2=right_up_disQ;  //

	int left_down_disS;
	int left_down_angS;
    left_down_disS=sqrt((double)((LEFT_DOWN_X-x3)*(LEFT_DOWN_X-x3)+(LEFT_DOWN_Y-y3)*(LEFT_DOWN_Y-y3)));
	left_down_angS=atan2((double)(LEFT_DOWN_Y-y3),(double)(LEFT_DOWN_X-x3))*180/3.141592;
	left_down_angS=-left_down_angS+90;
	if(left_down_angS<0)
	{
		left_down_angS=left_down_angS+360;
	}
	else if(left_down_angS>=360)
	{
		left_down_angS=left_down_angS-360;
	}
	LEFT_DOWN_X2=left_down_angS;  //
	LEFT_DOWN_Y2=left_down_disS;  //

	UpdateData(FALSE);
}

int j=0;
int k=0;
void CbluetoothDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if(nIDEvent==1)
	{
		char Pon[4];
		char Poff[4];
		char Qon[4];
		char Qoff[4];
		char Son[4];
		char Soff[4];
		if(move==0)
		{
			if(k==0)
			{
				a1.name='P';
				a1.dir='P';
				a1.angle='0';
				a1.distance='0';
				m_comm->Send((LPCTSTR)&a1,sizeof(a1));
			}
			else if(k==1)
			{
				a1.name='X';
				a1.dir='X';
				a1.angle='X';
				a1.distance='X';
				//m_comm->Send((LPCTSTR)&a1,sizeof(a1));
			}
			else if(k==2)
			{
				b1.name='Q';
				b1.dir='Q';
				b1.angle='0';
				b1.distance='0';
				m_comm->Send((LPCTSTR)&b1,sizeof(b1));
			}
			else if(k==3)
			{
				b1.name='X';
				b1.dir='X';
				b1.angle='X';
				b1.distance='X';
				//m_comm->Send((LPCTSTR)&b1,sizeof(b1));
			}
			else if(k==4)
			{
				d1.name='S';
				d1.dir='S';
				d1.angle='0';
				d1.distance='0';
				m_comm->Send((LPCTSTR)&d1,sizeof(d1));
			}
			else if(k==5)
			{
				d1.name='X';
				d1.dir='X';
				d1.angle='X';
				d1.distance='X';
				//m_comm->Send((LPCTSTR)&d1,sizeof(d1));
				k=-1;
			}
			k++;
		}
/////////�κ� �����̰� �ϴ� Ÿ�̸�

		
		if(move==1)
		{
			if(j==0)
			{
				m_comm->Send((LPCTSTR)&a1,sizeof(a1));
			}
			else if(j==2)
			{
				m_comm->Send((LPCTSTR)&b1,sizeof(b1));
			}

			else if(j==4)
			{
				m_comm->Send((LPCTSTR)&d1,sizeof(d1));
				j=-1;
				move=0;
			}
			j++;
		}	
	}
	CDialogEx::OnTimer(nIDEvent);
}
void CbluetoothDlg::OnBnClickedButton4()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CString str;

        GetDlgItem(IDC_EDIT_SEND_DATA)->GetWindowText(str);
        str+= "\r\n";
		m_comm->Send(str,str.GetLength());
}


void CbluetoothDlg::OnBnClickedButton23()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	d1.name='SSSS';
	d1.dir='SSSS';
	d1.distance='SSSS';
	d1.angle='SSSS';
	m_comm->Send((LPCTSTR)&d1,sizeof(d1));
}


void CbluetoothDlg::OnBnClickedButton25()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	b1.name='QQQQ';
	b1.dir='QQQQ';
	b1.distance='QQQQ';
	b1.angle='QQQQ';
	m_comm->Send((LPCTSTR)&b1,sizeof(b1));
}


void CbluetoothDlg::OnBnClickedButton26()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	a1.name='PPPP';
	a1.dir='PPPP';
	a1.distance='PPPP';
	a1.angle='PPPP';
	m_comm->Send((LPCTSTR)&a1,sizeof(a1));
}
void CbluetoothDlg::OnBnClickedButton27()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	a1.name='P';
	a1.dir='R';
	a1.distance=0;
	a1.angle=30;
	b1.name='Q';
	b1.dir='R';
	b1.distance=0;
	b1.angle=30;
	d1.name='S';
	d1.dir='R';
	d1.distance=0;
	d1.angle=30;
	move=1;
	SetTimer(1,300,NULL);
}


void CbluetoothDlg::OnBnClickedButton28()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	a1.name='P';
	a1.dir='T';
	a1.distance=30;
	a1.angle=45;
	b1.name='Q';
	b1.dir='T';
	b1.distance=30;
	b1.angle=45;
	d1.name='S';
	d1.dir='T';
	d1.distance=30;
	d1.angle=45;
	move=1;
	SetTimer(1,300,NULL);
}
void CbluetoothDlg::OnBnClickedButton34()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
		move=0;
		SetTimer(1,300,NULL);
}

void CbluetoothDlg::OnBnClickedButton35()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	KillTimer(1);
}



void CbluetoothDlg::OnBnClickedButton40()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);
	if(fix2)
		fix2=0;
	else
		fix2=1;
	UpdateData(FALSE);
}


void CbluetoothDlg::OnBnClickedBtSend2()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
						//a1.name='P';
						//a1.dir='R';
						//a1.distance=P_DIS;
						//a1.angle=LEFT_UP_ANG;
						
							
							if((0<=  P_ANG) &&(P_ANG <=180))
							{
								b1.name='Q';
								b1.dir='R';
								b1.distance=P_DIS;
								b1.angle=P_ANG;
							}
							else if((181<=P_ANG)&&(P_ANG<360))
							{
								b1.name='Q';
								b1.dir='L';
								b1.distance=P_DIS;
								b1.angle=P_ANG-180;
							}
							
							if((0<=  P_ANG) &&(P_ANG <=180))
							{
								d1.name='S';
								d1.dir='R';
								d1.distance=P_DIS;
								d1.angle=P_ANG;
							}
							else if((181<=P_ANG)&&(P_ANG<360))
							{
								d1.name='S';
								d1.dir='L';
								d1.distance=P_DIS;
								d1.angle=P_ANG-180;
							}
							move=1;
							SetTimer(1,300,NULL);
						
						
}


void CbluetoothDlg::OnBnClickedBtSend3()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.



	int array1[3]={LEFT_UP_DISTANCE,RIGHT_UP_DISTANCE,LEFT_DOWN_DISTANCE};
	InsertionSort(array1,3);
	if(LEFT_UP_DISTANCE==array1[0])
	{
		if((0<=  LEFT_UP_ANG) &&(LEFT_UP_ANG <=180))
							{
								b1.name='Q';
								b1.dir='R';
								b1.distance=LEFT_UP_DISTANCE;
								b1.angle=LEFT_UP_ANG+180;
							}
							else if((181<=LEFT_UP_ANG)&&(LEFT_UP_ANG<=360))
							{
								b1.name='Q';
								b1.dir='L';
								b1.distance=LEFT_UP_DISTANCE;
								b1.angle=LEFT_UP_ANG;
							}
	}
	else if(RIGHT_UP_DISTANCE==array1[0])
	{
		if((0<=RIGHT_UP_ANG)&&(RIGHT_UP_ANG<=180))
							{
								b1.name='Q';
								b1.dir='R';
								b1.distance=RIGHT_UP_DISTANCE;
								b1.angle=RIGHT_UP_ANG+180;
							}
							else if((181<=RIGHT_UP_ANG)&&(RIGHT_UP_ANG<=360))
							{
								b1.name='Q';
								b1.dir='L';
								b1.distance=RIGHT_UP_DISTANCE;
								b1.angle=RIGHT_UP_ANG;
							}
	}
	else if(LEFT_DOWN_DISTANCE==array1[0])
	{
		if((0<=LEFT_DOWN_ANG)&&(LEFT_DOWN_ANG<=180))
							{
								b1.name='Q';
								b1.dir='R';
								b1.distance=LEFT_DOWN_DISTANCE;
								b1.angle=LEFT_DOWN_ANG+180;
							}
							else if((181<=LEFT_DOWN_ANG)&&(LEFT_DOWN_ANG<=360))
							{
								b1.name='Q';
								b1.dir='L';
								b1.distance=LEFT_DOWN_DISTANCE;
								b1.angle=LEFT_DOWN_ANG;
							}
	}
	int array2[3]={RIGHT_UP_Y1,LEFT_DOWN_Y1,LEFT_UP_Y1};
	InsertionSort(array2,3);
	if(RIGHT_UP_Y1==array2[0])
	{
							if((0<=RIGHT_UP_X1)&&(RIGHT_UP_X1<=180))
							{
								a1.name='P';
								a1.dir='R';
								a1.distance=RIGHT_UP_Y1;
								a1.angle=RIGHT_UP_X1+180;
							}
							else if((181<=RIGHT_UP_X1)&&(RIGHT_UP_X1<=360))
							{
								a1.name='P';
								a1.dir='L';
								a1.distance=RIGHT_UP_Y1;
								a1.angle=RIGHT_UP_X1;
							}
	}
	else if(LEFT_DOWN_Y1==array2[0])
	{
							if((0<=LEFT_DOWN_X1)&&(LEFT_DOWN_X1<=180))
							{
								a1.name='P';
								a1.dir='R';
								a1.distance=LEFT_DOWN_Y1;
								a1.angle=LEFT_DOWN_X1+180;
							}
							else if((181<=LEFT_DOWN_X1)&&(LEFT_DOWN_X1<=360))
							{
								a1.name='P';
								a1.dir='L';
								a1.distance=LEFT_DOWN_Y1;
								a1.angle=LEFT_DOWN_X1;
							}
	}
	else if(LEFT_UP_Y1==array2[0])
	{
							if((0<=LEFT_UP_X1)&&(LEFT_UP_X1<=180))
							{
								a1.name='P';
								a1.dir='R';
								a1.distance=LEFT_UP_Y1;
								a1.angle=LEFT_UP_X1+180;
							}
							else if((181<=LEFT_UP_X1)&&(LEFT_UP_X1<=360))
							{
								a1.name='P';
								a1.dir='L';
								a1.distance=LEFT_UP_Y1;
								a1.angle=LEFT_UP_X1;
							}
	}
	int array3[3]={RIGHT_UP_Y2,LEFT_DOWN_Y2,LEFT_UP_Y2};
	InsertionSort(array3,3);
	if(RIGHT_UP_Y2==array3[0])
	{
							if((0<=RIGHT_UP_X2)&&(RIGHT_UP_X2<=180))
							{
								d1.name='S';
								d1.dir='R';
								d1.distance=RIGHT_UP_Y2;
								d1.angle=RIGHT_UP_X2+180;
							}
							else if((181<=RIGHT_UP_X2)&&(RIGHT_UP_X2<=360))
							{
								d1.name='S';
								d1.dir='L';
								d1.distance=RIGHT_UP_Y2;
								d1.angle=RIGHT_UP_X2;
							}
	}
	else if(LEFT_DOWN_Y2==array3[0])
	{
							if((0<=LEFT_DOWN_X2)&&(LEFT_DOWN_X2<=180))
							{
								d1.name='S';
								d1.dir='R';
								d1.distance=LEFT_DOWN_Y2;
								d1.angle=LEFT_DOWN_X2+180;
							}
							else if((181<=LEFT_DOWN_X2)&&(LEFT_DOWN_X2<=360))
							{
								d1.name='S';
								d1.dir='L';
								d1.distance=LEFT_DOWN_Y2;
								d1.angle=LEFT_DOWN_X2;
							}
	}
	else if(LEFT_UP_Y2==array3[0])
	{
							if((0<=LEFT_UP_X2)&&(LEFT_UP_X2<=180))
							{
								d1.name='S';
								d1.dir='R';
								d1.distance=LEFT_UP_Y2;
								d1.angle=LEFT_UP_X2+180;
							}
							else if((181<=LEFT_UP_X2)&&(LEFT_UP_X2<=360))
							{
								d1.name='S';
								d1.dir='L';
								d1.distance=LEFT_UP_Y2;
								d1.angle=LEFT_UP_X2;
							}
	}
	
		move=1;
		SetTimer(1,300,NULL);
		
		//UpdateData(FALSE);
}



void CbluetoothDlg::OnBnClickedBtSend4()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	int des_P_DIS;
	int des_P_ANG;
    des_P_DIS=sqrt((double)((17-Stand_X)*(17-Stand_X)+(144-Stand_Y)*(144-Stand_Y)));
	des_P_ANG=atan2((double)(144-Stand_Y),(double)(17-Stand_X))*180/3.141592;
	des_P_ANG=-des_P_ANG+90;
	if(des_P_ANG<0)
	{
		des_P_ANG=des_P_ANG+360;
			if((0<=  des_P_ANG) &&(des_P_ANG <=180))
		{
			a1.name='P';
			a1.dir='R';
			a1.distance=des_P_DIS;
			a1.angle=des_P_ANG;
		}
		else if((181<=des_P_ANG)&&(des_P_ANG<=360))
		{
			a1.name='P';
			a1.dir='L';
			a1.distance=des_P_DIS;
			a1.angle=des_P_ANG-180;
		}
	}
	else if(des_P_ANG>=360)
	{
		des_P_ANG=des_P_ANG-360;
			if((0<=  des_P_ANG) &&(des_P_ANG <=180))
		{
			a1.name='P';
			a1.dir='R';
			a1.distance=des_P_DIS;
			a1.angle=des_P_ANG;
		}
		else if((181<=des_P_ANG)&&(des_P_ANG<=360))
		{
			a1.name='P';
			a1.dir='L';
			a1.distance=des_P_DIS;
			a1.angle=des_P_ANG-180;
		}
	}
	else
	{
		if((0<=  des_P_ANG) &&(des_P_ANG <=180))
		{
			a1.name='P';
			a1.dir='R';
			a1.distance=des_P_DIS;
			a1.angle=des_P_ANG;
		}
		else if((181<=des_P_ANG)&&(des_P_ANG<=360))
		{
			a1.name='P';
			a1.dir='L';
			a1.distance=des_P_DIS;
			a1.angle=des_P_ANG-180;
		}
	}
	

	int des_Q_DIS;
	int des_Q_ANG;
    des_Q_DIS=sqrt((double)((16-x2)*(16-x2)+(21-y2)*(21-y2)));
	des_Q_ANG=atan2((double)(21-y2),(double)(16-x2))*180/3.141592;
	des_Q_ANG=-des_Q_ANG+90;
	if(des_Q_ANG<0)
	{
		des_Q_ANG=des_Q_ANG+360;
		if((0<=  des_Q_ANG) &&(des_Q_ANG <=180))
		{
			b1.name='Q';
			b1.dir='R';
			b1.distance=des_Q_DIS;
			b1.angle=des_Q_ANG;
		}
		else if((181<=des_Q_ANG)&&(des_Q_ANG<=360))
		{
			b1.name='Q';
			b1.dir='L';
			b1.distance=des_Q_DIS;
			b1.angle=des_Q_ANG-180;
		}
	}
	else if(des_Q_ANG>=360)
	{
		des_Q_ANG=des_Q_ANG-360;
			if((0<=  des_Q_ANG) &&(des_Q_ANG <=180))
		{
			b1.name='Q';
			b1.dir='R';
			b1.distance=des_Q_DIS;
			b1.angle=des_Q_ANG;
		}
		else if((181<=des_Q_ANG)&&(des_Q_ANG<=360))
		{
			b1.name='Q';
			b1.dir='L';
			b1.distance=des_Q_DIS;
			b1.angle=des_Q_ANG-180;
		}
	}
	else
	{
		if((0<=  des_Q_ANG) &&(des_Q_ANG <=180))
		{
			b1.name='Q';
			b1.dir='R';
			b1.distance=des_Q_DIS;
			b1.angle=des_Q_ANG;
		}
		else if((181<=des_Q_ANG)&&(des_Q_ANG<=360))
		{
			b1.name='Q';
			b1.dir='L';
			b1.distance=des_Q_DIS;
			b1.angle=des_Q_ANG-180;
		}
	}

	int des_S_DIS;
	int des_S_ANG;
    des_S_DIS=sqrt((double)((123-x3)*(123-x3)+(21-y3)*(21-y3)));
	des_S_ANG=atan2((double)(21-y3),(double)(123-x3))*180/3.141592;
	des_S_ANG=-des_S_ANG+90;
	if(des_S_ANG<0)
	{
		des_S_ANG=des_S_ANG+360;
			if((0<=  des_S_ANG) &&(des_S_ANG <=180))
		{
			d1.name='S';
			d1.dir='R';
			d1.distance=des_S_DIS;
			d1.angle=des_S_ANG;
		}
		else if((181<=des_S_ANG)&&(des_S_ANG<=360))
		{
			d1.name='S';
			d1.dir='L';
			d1.distance=des_S_DIS;
			d1.angle=des_S_ANG-180;
		}
	}
	else if(des_S_ANG>=360)
	{
		des_S_ANG=des_S_ANG-360;
		if((0<=  des_S_ANG) &&(des_S_ANG <=180))
		{
			d1.name='S';
			d1.dir='R';
			d1.distance=des_S_DIS;
			d1.angle=des_S_ANG;
		}
		else if((181<=des_S_ANG)&&(des_S_ANG<=360))
		{
			d1.name='S';
			d1.dir='L';
			d1.distance=des_S_DIS;
			d1.angle=des_S_ANG-180;
		}
	}
	else
	{
		if((0<=  des_S_ANG) &&(des_S_ANG <=180))
		{
			d1.name='S';
			d1.dir='R';
			d1.distance=des_S_DIS;
			d1.angle=des_S_ANG;
		}
		else if((181<=des_S_ANG)&&(des_S_ANG<=360))
		{
			d1.name='S';
			d1.dir='L';
			d1.distance=des_S_DIS;
			d1.angle=des_S_ANG-180;
		}
	}
		move=1;
		SetTimer(1,300,NULL);

}
