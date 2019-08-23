
// bluetoothDlg.cpp : 구현 파일
//
//삼각형
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
// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.
struct position a1;
struct position b1;
struct position d1;

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
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


// CbluetoothDlg 대화 상자

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


// CbluetoothDlg 메시지 처리기
LRESULT CbluetoothDlg::OnThreadClosed(WPARAM length, LPARAM lpara)
{
        //overlapped i/o 핸들을닫는다.

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
               m_comm->Receive(data,length); //length 길이만큼데이터를받는다.
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
               m_edit_rcv_view.ReplaceSel(str); //에디트박스에표시하기위함/
               UpdateData(FALSE);
               m_edit_rcv_view.LineScroll(m_edit_rcv_view.GetLineCount());
        }
        return 0;
}
BOOL CbluetoothDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.
	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
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

	// 이 대화 상자의 아이콘을 설정합니다. 응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.
	// TODO: 여기에 추가 초기화 작업을 추가합니다.
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
	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다. 문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CbluetoothDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CbluetoothDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CbluetoothDlg::OnBnClickedBtConnect()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if(comport_state)

         {

                  if(m_comm)        //컴포트가존재하면

                  {

                           m_comm->Close();

                           m_comm = NULL;

                           AfxMessageBox(_T("COM 포트닫힘"));

                           comport_state=false;

                           GetDlgItem(IDC_BT_CONNECT)->SetWindowText(_T("OPEN"));

                           GetDlgItem(IDC_BT_SEND)->EnableWindow(false);

                  }

         }

         else

         {

                  m_comm= new CMycomm(_T("\\\\.\\")+m_str_comport,m_str_baudrate,_T("None"),_T("8 Bit"),_T("1 Bit"));         // initial Comm port

                  if(      m_comm->Create(GetSafeHwnd()) != 0) //통신포트를열고윈도우의핸들을넘긴다.

                  {

                           AfxMessageBox(_T("COM 포트열림"));

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
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData();
}


void CbluetoothDlg::OnBnClickedBtClear()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	GetDlgItem(IDC_EDIT_RCV_VIEW)->SetWindowText(_T(" "));
}
bool move =1;
void CbluetoothDlg::OnBnClickedBtSend()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
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
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CbluetoothDlg::OnEnChangeEditBiY()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

void CbluetoothDlg::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	if(fix)
		fix=0;
	else
		fix=1;
	UpdateData(FALSE);
}


void CbluetoothDlg::OnBnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
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
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
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
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
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
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
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
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
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
/////////로봇 움직이게 하는 타이머

		
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
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str;

        GetDlgItem(IDC_EDIT_SEND_DATA)->GetWindowText(str);
        str+= "\r\n";
		m_comm->Send(str,str.GetLength());
}


void CbluetoothDlg::OnBnClickedButton23()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	d1.name='SSSS';
	d1.dir='SSSS';
	d1.distance='SSSS';
	d1.angle='SSSS';
	m_comm->Send((LPCTSTR)&d1,sizeof(d1));
}


void CbluetoothDlg::OnBnClickedButton25()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	b1.name='QQQQ';
	b1.dir='QQQQ';
	b1.distance='QQQQ';
	b1.angle='QQQQ';
	m_comm->Send((LPCTSTR)&b1,sizeof(b1));
}


void CbluetoothDlg::OnBnClickedButton26()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	a1.name='PPPP';
	a1.dir='PPPP';
	a1.distance='PPPP';
	a1.angle='PPPP';
	m_comm->Send((LPCTSTR)&a1,sizeof(a1));
}
void CbluetoothDlg::OnBnClickedButton27()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
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
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
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
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
		move=0;
		SetTimer(1,300,NULL);
}

void CbluetoothDlg::OnBnClickedButton35()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	KillTimer(1);
}



void CbluetoothDlg::OnBnClickedButton40()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	if(fix2)
		fix2=0;
	else
		fix2=1;
	UpdateData(FALSE);
}


void CbluetoothDlg::OnBnClickedBtSend2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
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
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.



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
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
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
