// BubbleGame.cpp : 定义应用程序的入口点。
//

//#include "stdafx.h"
#include "BubbleGame.h"
using namespace std;

#define MAX_LOADSTRING 100

// 全局变量:

HINSTANCE hInst;								// 当前实例
TCHAR szTitle[MAX_LOADSTRING];					// 标题栏文本
TCHAR szWindowClass[MAX_LOADSTRING];			// 主窗口类名

HBITMAP bmp_Grass;			//背景图像资源
HBITMAP bmp_StartButton;	//开始按钮图像资源
HBITMAP bmp_Unit_Me;
HBITMAP bmp_Unit_Rival;
HBITMAP bmp_Background;		//生成的背景图像
HBITMAP bmp_Bubble;			//泡泡图像资源
HBITMAP bmp_block;			//地图砖块图像
HBITMAP bmp_HelpButton;		//帮助菜单按钮图像资源
HBITMAP bmp_MenuButton;		//回到主菜单按钮图像资源
HBITMAP bmp_BeginBG;		//初始页面背景
HBITMAP bmp_FakeMenuButton;		//充当菜单背景的按钮图像资源
HBITMAP bmp_RestartButton;		//重新开始游戏按钮的图像资源
HBITMAP bmp_ToMenuButton;			//回到主菜单按钮图像资源
HBITMAP bmp_BackToGameButton;		//恢复游戏按钮图像资源
HBITMAP bmp_Bubble_Boom;			//爆炸冲击波图像资源
HBITMAP bmp_Bubble_Boom2;			//爆炸冲击波图像资源
HBITMAP bmp_Lost_Menu;				//失败菜单
HBITMAP bmp_Numbers;				//倒计时图像资源
HBITMAP bmp_Blood;					//血条资源
HBITMAP bmp_Head_Me;				//玩家头像资源
HBITMAP bmp_Head_Rival;				//AI头像资源
HBITMAP bmp_Cb;						//弹药匣资源
HBITMAP bmp_Power_Liquid;			//威力药水资源
HBITMAP bmp_Speed_Liquid;			//速度药水图像资源
HBITMAP bmp_BackGround_Help;		//教程背景
HBITMAP bmp_finalmenu;				//最终菜单
HBITMAP bmp_continue;				//继续游戏图像
HBITMAP bmp_restart;				//重新游戏图像
HBITMAP bmp_earth;					//泥土资源图像
HBITMAP bmp_undead;					//不死图腾图像
HBITMAP bmp_broken_undead;			//破碎不死图腾图像
HBITMAP bmp_skill;					//变身道具图像
HBITMAP bmp_energy_bar;				//能量条图像
HBITMAP bmp_broken_skill;			//破碎变身道具图像
HBITMAP bmp_switch_blood;			//换血道具图像
HBITMAP bmp_using_switch_blood;		//换血道具吟唱图像
HBITMAP bmp_bubble_rival;
HBITMAP bmp_boom_rival;
HBITMAP bmp_boom2_rival;
HBITMAP bmp_bubble_stage;
HBITMAP bmp_boom_stage;
HBITMAP bmp_boom2_stage;
HBITMAP bmp_win_menu;				//游戏胜利图像
HBITMAP bmp_equal_menu;				//游戏平局图像
HBITMAP bmp_choose_background;		//选择关卡背景
HBITMAP bmp_STAGE_1;
HBITMAP bmp_STAGE_2;
HBITMAP bmp_STAGE_3;
HBITMAP bmp_STAGE_4;
HBITMAP bmp_STAGE_5;
HBITMAP bmp_STAGE_6;
HBITMAP bmp_STAGE_7;
HBITMAP bmp_STAGE_8;
HBITMAP bmp_warnings;
HBITMAP bmp_introduction1;
HBITMAP bmp_introduction2;
HBITMAP bmp_introduction3;
HBITMAP bmp_right_page;
HBITMAP bmp_left_page;
HBITMAP bmp_introduction_back;
HBITMAP bmp_choose_back;
HBITMAP bmp_pre_cb;
HBITMAP bmp_pre_speed;
HBITMAP bmp_pre_power;
HBITMAP bmp_pre_undead;
HBITMAP bmp_pre_bs;
HBITMAP bmp_pre_switch;


Stage* currentStage = NULL; //当前场景状态
vector<Unit*> units;		//单位
vector<Button*> buttons;	//按钮	
vector<Bubble*> bubbles;	//泡泡
vector<Boom*> booms;		//冲击波
vector<Cartridge_Bag*> Cbs;	//弹药匣
int next_bubble_timer_id = 1001;		//下一个泡泡的计时器id
int pause_t=0;				//这个是十分重要的
int last_StageID = NULL;	//这个是记录上一个场景的变量
int ifwin = 2;
int AI_level = 1;			//AI智能程度
int last_time_bu = 0;
int last_time_skill = 0;
bool me_has_speed_liquid = false;
bool rival_has_speed_liquid = false;
bool skilling = false;
bool keyFdown = false;
bool rival_skilling = false;
bool rival_catching = false;
bool rival_noticed = false;
int rival_catching_timer = 0;
bool rival_thriving = false;
bool keyEdown = false;
int switch_blood_timer = 0;
bool start_switch_blood_timer = false;
bool start_warning = false;
bool have_warned = false;
int warning_timer = 0;
bool me_has_undead = false;
bool rival_has_undead = false;
bool me_has_bs = false;
bool rival_has_bs = false;




bool AI_toleft = true;		//记录AI是否可以走
bool AI_toright = true;
bool AI_toup = true;
bool AI_todown = true;
int blocked_time_x=0;
int blocked_time_y = 0;


int mouseX = 0;
int mouseY = 0;
bool mouseDown = false;
bool keyUpDown = false;
bool keyDownDown = false;
bool keyLeftDown = false;
bool keyRightDown = false;


//帧
int FRAMES_HOLD[] = { 0 };
int FRAMES_HOLD_COUNT = sizeof(FRAMES_HOLD) / sizeof(int);
int FRAMES_WALK[] = { 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, };
int FRAMES_WALK_COUNT = sizeof(FRAMES_WALK) / sizeof(int);
int FRAMES_BUBBLE[] = { 0,0,0,0,0,0,1,1,1,1,1,1,2,2,2,2,2,2,3,3,3,3,3,3,4,4,4,4,4,4,5,5,5,5,5,5, };
int FRAMES_BUBBLE_COUNT = sizeof(FRAMES_BUBBLE) / sizeof(int);

//地图

//第一关地图：旷野之争
int map1[][16] = {
    {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,},
    {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,},
    {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,},
    {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,},
    {2,0,0,0,0,0,1,1,1,1,0,0,0,0,0,2,},
    {2,0,0,0,0,0,1,1,1,1,0,0,0,0,0,2,},
    {2,0,0,0,0,0,1,1,1,1,0,0,0,0,0,2,},
    {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,},
    {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,},
    {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,},
    {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,},
    {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,},
};
//第二关地图：迂回前进
int map2[][16] = {
	{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,},
	{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,},
	{2,0,1,1,1,1,1,1,1,1,1,1,1,1,0,2,},
	{2,0,1,0,0,0,0,0,0,0,0,0,0,1,0,2,},
	{2,0,1,0,1,1,1,1,1,1,1,1,0,1,0,2,},
	{2,0,1,0,1,0,0,0,0,0,0,1,0,1,0,2,},
	{2,0,1,0,1,0,0,0,0,0,0,1,0,1,0,2,},
	{2,0,1,0,1,0,1,1,1,1,1,1,0,1,0,2,},
	{2,0,1,0,1,0,0,0,0,0,0,0,0,1,0,2,},
	{2,0,1,0,1,1,1,1,1,1,1,1,1,1,0,2,},
	{2,0,1,0,0,0,0,0,0,0,0,0,0,1,0,2,},
	{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,},
};
//第三关地图：点状网络
int map3[][16] = {
	{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,},
	{2,0,1,0,1,0,1,0,1,0,1,0,1,0,1,2,},
	{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,},
	{2,0,1,0,1,0,1,0,1,0,1,0,1,0,1,2,},
	{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,},
	{2,0,1,0,1,0,1,0,1,0,1,0,1,0,1,2,},
	{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,},
	{2,0,1,0,1,0,1,0,1,0,1,0,1,0,1,2,},
	{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,},
	{2,0,1,0,1,0,1,0,1,0,1,0,1,0,1,2,},
	{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,},
	{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,},
};
//第四关地图：障碍重重
int map4[][16] = {
	{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,},
	{2,0,1,1,1,1,1,1,1,1,1,1,1,1,1,2,},
	{2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,},
	{2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,},
	{2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,},
	{2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,},
	{2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,},
	{2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,},
	{2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,},
	{2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,},
	{2,1,1,1,1,1,1,1,1,1,1,1,1,1,0,2,},
	{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,},
};
//第五关地图：狭路相逢
int map5[][16] = {
	{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,},
	{2,0,0,0,0,0,1,1,1,1,1,1,1,1,1,2,},
	{2,1,1,0,0,0,0,1,1,1,1,1,1,1,1,2,},
	{2,1,1,1,0,0,0,0,1,1,1,1,1,1,1,2,},
	{2,1,1,1,1,0,0,0,0,1,1,1,1,1,1,2,},
	{2,1,1,1,1,1,0,0,0,0,1,1,1,1,1,2,},
	{2,1,1,1,1,1,1,0,0,0,0,1,1,1,1,2,},
	{2,1,1,1,1,1,1,1,0,0,0,0,1,1,1,2,},
	{2,1,1,1,1,1,1,1,1,0,0,0,0,1,1,2,},
	{2,1,1,1,1,1,1,1,1,1,0,0,0,0,1,2,},
	{2,1,1,1,1,1,1,1,1,1,1,0,0,0,0,2,},
	{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,},
};
//第六关地图：困兽之斗
int map6[][16] = {
	{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,},
	{2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,},
	{2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,},
	{2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,},
	{2,1,1,1,1,1,0,0,0,0,1,1,1,1,1,2,},
	{2,1,1,1,1,1,0,0,0,0,1,1,1,1,1,2,},
	{2,1,1,1,1,1,0,0,0,0,1,1,1,1,1,2,},
	{2,1,1,1,1,1,0,0,0,0,1,1,1,1,1,2,},
	{2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,},
	{2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,},
	{2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,},
	{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,},
};
//第七关地图：阡陌纵横
int map7[][16] = {
	{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,},
	{2,0,0,1,0,0,0,1,0,0,0,1,0,0,0,2,},
	{2,0,1,0,1,0,1,0,1,0,1,0,1,0,1,2,},
	{2,1,0,0,0,1,0,0,0,1,0,0,0,1,0,2,},
	{2,0,1,0,1,0,1,0,1,0,1,0,1,0,1,2,},
	{2,0,0,1,0,0,0,1,0,0,0,1,0,0,0,2,},
	{2,0,1,0,1,0,1,0,1,0,1,0,1,0,1,2,},
	{2,1,0,0,0,1,0,0,0,1,0,0,0,1,0,2,},
	{2,0,1,0,1,0,1,0,1,0,1,0,1,0,1,2,},
	{2,0,0,1,0,0,0,1,0,0,0,1,0,1,0,2,},
	{2,0,1,0,1,0,1,0,1,0,1,0,1,0,0,2,},
	{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,},
};


//这个地图是载入地图，十分重要
int map[][16]= {
	{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,},
	{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,},
	{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,},
	{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,},
	{2,0,0,0,0,0,1,1,1,1,0,0,0,0,0,2,},
	{2,0,0,0,0,0,1,1,1,1,0,0,0,0,0,2,},
	{2,0,0,0,0,0,1,1,1,1,0,0,0,0,0,2,},
	{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,},
	{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,},
	{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,},
	{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,},
	{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,},
};
// TODO: 在此添加其它全局变量

double const PI = acos(double(-1));



// 此代码模块中包含的函数的前向声明:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPTSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

 	// TODO: 在此放置代码。
	MSG msg;
	HACCEL hAccelTable;

	// 初始化全局字符串
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_BUBBLEGAME, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// 执行应用程序初始化:
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_BUBBLEGAME));

	// 主消息循环:
	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int) msg.wParam;
}



//
//  函数: MyRegisterClass()
//
//  目的: 注册窗口类。
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_TITLEBAR));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_BUBBLEGAME);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_TITLEBAR));

	return RegisterClassEx(&wcex);
}

//
//   函数: InitInstance(HINSTANCE, int)
//
//   目的: 保存实例句柄并创建主窗口
//
//   注释:
//
//        在此函数中，我们在全局变量中保存实例句柄并
//        创建和显示主程序窗口。
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   HWND hWnd;

   hInst = hInstance; // 将实例句柄存储在全局变量中

   hWnd = CreateWindowW(szWindowClass, szTitle, 
	   WS_OVERLAPPEDWINDOW & ~WS_THICKFRAME & ~WS_MAXIMIZEBOX, // 设置窗口样式，不可改变大小，不可最大化,
	   CW_USEDEFAULT,
	   CW_USEDEFAULT,
	   WINDOW_WIDTH,
	   WINDOW_HEIGHT + WINDOW_TITLEBARHEIGHT,
	   nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  函数: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  目的: 处理主窗口的消息。
//
//  WM_COMMAND	- 处理应用程序菜单
//  WM_PAINT	- 绘制主窗口
//  WM_DESTROY	- 发送退出消息并返回
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_CREATE:
        // 初始化游戏窗体
        InitGame(hWnd, wParam, lParam);
        break;
    case WM_KEYDOWN:
        // 键盘按下事件
        KeyDown(hWnd, wParam, lParam);
        break;
    case WM_KEYUP:
        // 键盘松开事件
        KeyUp(hWnd, wParam, lParam);
        break;
    case WM_MOUSEMOVE:
        // 鼠标移动事件
        MouseMove(hWnd, wParam, lParam);
        break;
    case WM_LBUTTONDOWN:
        // 鼠标左键按下事件
        LButtonDown(hWnd, wParam, lParam);
        break;
    case WM_LBUTTONUP:
        // 鼠标左键松开事件
        LButtonUp(hWnd, wParam, lParam);
        break;
    case WM_TIMER:
        // 定时器事件
        if (currentStage != NULL && currentStage->timerOn) TimerUpdate(hWnd, wParam, lParam);
        break;
    case WM_PAINT:
        // 绘图
        Paint(hWnd);
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}


// 初始化游戏窗体函数
void InitGame(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	//加载图像资源
	bmp_Grass = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_GRASS));
	bmp_StartButton = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_START));
	bmp_Unit_Me = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_ME));
	bmp_Unit_Rival = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_RIVAL));
	bmp_Bubble = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BUBBLE));
	bmp_block = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BLOCK));
	bmp_HelpButton= LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_Help));
	bmp_MenuButton = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_Menu));
	bmp_BeginBG= LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BEGINBG));
	bmp_Bubble_Boom= LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP4));
	bmp_Bubble_Boom2 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_Bubble_Boom2));
	bmp_Lost_Menu= LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_Lost_Menu));
	bmp_Numbers= LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_NUMBERS));
	bmp_Blood= LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BLOOD));
	bmp_Head_Me= LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_HEAD_ME));
	bmp_Head_Rival = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_HEAD_RIVAL));
	bmp_Cb = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_CB));
	bmp_Power_Liquid= LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_POWER_LIQUID));
	bmp_Speed_Liquid= LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_SPEED_LIQUID));
	bmp_finalmenu= LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_FINALMENU));
	bmp_restart = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_RESTART));
	bmp_continue = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_CONTINUE_GAME));
	bmp_ToMenuButton= LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_MENU2));
	bmp_earth=LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_EARTH));
	bmp_undead= LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_UNDEAD));
	bmp_broken_undead= LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_broken_undead));
	bmp_skill= LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_SKILL));
	bmp_energy_bar= LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_ENERGY_BAR));
	bmp_broken_skill= LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BROKEN_SKILL));
	bmp_switch_blood= LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_SWITCH_BLOOD));
	bmp_using_switch_blood= LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_USING_SWITCH_BLOOD));
	bmp_bubble_rival= LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_bubble_rival));
	bmp_boom_rival = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_boom_rival));
	bmp_boom2_rival = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_boom2_rival));
	bmp_bubble_stage = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_bubble_stage));
	bmp_boom_stage = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_boom_stage));
	bmp_boom2_stage = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_boom2_stage));
	bmp_win_menu= LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_WIN_MENU));
	bmp_equal_menu= LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_EQUAL_MENU));
	bmp_choose_background= LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_STAGE_CHOOSE));
	bmp_STAGE_1 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_STAGE_1));
	bmp_STAGE_2 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_STAGE_2));
	bmp_STAGE_3 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_STAGE_3));
	bmp_STAGE_4 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_STAGE_4));
	bmp_STAGE_5 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_STAGE_5));
	bmp_STAGE_6 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_STAGE_6));
	bmp_STAGE_7 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_STAGE_7));
	bmp_STAGE_8 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_STAGE_8));
	bmp_warnings= LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_WARNINGS));
	bmp_introduction1= LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_INTRODUCTION1));
	bmp_introduction2 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_INTRODUCTION2));
	bmp_introduction3 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_INTRODUCION3));
	bmp_left_page= LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_LEFT_PAGE));
	bmp_right_page = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_RIGHT_PAGE));
	bmp_introduction_back= LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_INTRODUCTION_BACK));
	bmp_choose_back= LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_CHOOSE_BACK));
	bmp_pre_cb= LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_PRE_CB));
	bmp_pre_speed = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_PRE_SPEED));
	bmp_pre_power = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_PRE_POWER));
	bmp_pre_undead = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_PRE_UNDEAD));
	bmp_pre_bs = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_PRE_BS));
	bmp_pre_switch = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_PRE_SWITCH));
	//添加按钮
	//添加按钮

	Button* startButton = CreateButton(BUTTON_STARTGAME, bmp_StartButton, BUTTON_STARTGAME_WIDTH, BUTTON_STARTGAME_HEIGHT,
		(WINDOW_WIDTH - BUTTON_STARTGAME_WIDTH) / 2, (WINDOW_WIDTH - BUTTON_STARTGAME_HEIGHT) / 2);
	buttons.push_back(startButton);
	Button* helpButton = CreateButton(BUTTON_HELP, bmp_HelpButton, BUTTON_STARTGAME_WIDTH, BUTTON_STARTGAME_HEIGHT,
		(WINDOW_WIDTH - BUTTON_STARTGAME_WIDTH) / 2, (WINDOW_WIDTH - BUTTON_STARTGAME_HEIGHT) / 2+100);
	buttons.push_back(helpButton);
	Button* menuButton = CreateButton(BUTTON_MENU, bmp_MenuButton, BUTTON_STARTGAME_WIDTH, BUTTON_STARTGAME_HEIGHT,
		(WINDOW_WIDTH - BUTTON_STARTGAME_WIDTH) / 2, (WINDOW_WIDTH - BUTTON_STARTGAME_HEIGHT) / 2 + 200);
	buttons.push_back(menuButton);
	
	//添加关卡按钮
	Button* button_stage_1 = CreateButton(BUTTON_STAGE_1, bmp_STAGE_1, 130, 40, 70, 220);
	buttons.push_back(button_stage_1);
	Button* button_stage_2 = CreateButton(BUTTON_STAGE_2, bmp_STAGE_2, 130, 40, 374, 220);
	buttons.push_back(button_stage_2);
	Button* button_stage_3 = CreateButton(BUTTON_STAGE_3, bmp_STAGE_3, 130, 40, 678, 220);
	buttons.push_back(button_stage_3);
	Button* button_stage_4 = CreateButton(BUTTON_STAGE_4, bmp_STAGE_4, 130, 40, 70, 450);
	buttons.push_back(button_stage_4);
	Button* button_stage_5 = CreateButton(BUTTON_STAGE_5, bmp_STAGE_5, 130, 40, 374, 450);
	buttons.push_back(button_stage_5);
	Button* button_stage_6 = CreateButton(BUTTON_STAGE_6, bmp_STAGE_6, 130, 40, 678, 450);
	buttons.push_back(button_stage_6);
	Button* button_stage_7 = CreateButton(BUTTON_STAGE_7, bmp_STAGE_7, 130, 40, 70, 680);
	buttons.push_back(button_stage_7);
	Button* button_stage_8 = CreateButton(BUTTON_STAGE_8, bmp_STAGE_8, 130, 40, 374, 680);
	buttons.push_back(button_stage_8);
	
	//教程翻页按钮
	Button* button_Page2toPage1 = CreateButton(BUTTON_PAGE2TOPAGE1, bmp_left_page, 128, 48, 275, 680);
	buttons.push_back(button_Page2toPage1);

	Button* button_Page2toPage3 = CreateButton(BUTTON_PAGE2TOPAGE3, bmp_right_page, 128, 48, 600, 680);
	buttons.push_back(button_Page2toPage3);

	Button* button_Page1toPage2 = CreateButton(BUTTON_PAGE1TOPAGE2, bmp_right_page, 128, 48, 600, 680);
	buttons.push_back(button_Page1toPage2);

	Button* button_Page3toPage2 = CreateButton(BUTTON_PAGE3TOPAGE2, bmp_left_page, 128, 48, 275, 680);
	buttons.push_back(button_Page3toPage2);
	//两个返回按钮
	Button* button_choose_back = CreateButton(BUTTON_CHOOSE_BACK, bmp_choose_back, 128, 128, 678, 550);
	buttons.push_back(button_choose_back);
	Button* button_introduction_back = CreateButton(BUTTON_INTRODUCTION_BACK, bmp_introduction_back, 64, 64, 30, 30);
	buttons.push_back(button_introduction_back);







	//暂停菜单的三个按钮
	//请注意图片资源还没有加入
	//假菜单按钮
	Button* fakemenuButton = CreateButton(BUTTON_FAKEMENU, bmp_finalmenu, 480, 480,272, 112);
	buttons.push_back(fakemenuButton);
	//重新开始游戏按钮
	Button* restartButton = CreateButton(BUTTON_RESTART, bmp_restart, 106, 38,450,400);
	buttons.push_back(restartButton);
	//回到主菜单按钮
	Button* tomenuButton = CreateButton(BUTTON_TOMENU, bmp_ToMenuButton, 106, 38,450,450);
	buttons.push_back(tomenuButton);
	//恢复游戏按钮
	Button* backtogameButton = CreateButton(BUTTON_BACKTOGAME, bmp_continue, 106, 38,450, 350);
	buttons.push_back(backtogameButton);

	//初始化背景
	//bmp_Background = InitMenuBackGround(hWnd, bmp_BeginBG);
	bmp_Background = InitMenuBackGround(hWnd, bmp_BeginBG);
	


	//初始化开始场景
	InitStage(hWnd, STAGE_STARTMENU);

	//初始化主计时器
	SetTimer(hWnd, TIMER_GAMETIMER, TIMER_GAMETIMER_ELAPSE, NULL);
}

// 键盘按下事件处理函数
void KeyDown(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	switch (wParam)
	{
	case 0x57:
		keyUpDown = true;
		break;
	case 0x53:
		keyDownDown = true;
		break;
	case 0x41:
		keyLeftDown = true;
		break;
	case 0x44:
		keyRightDown = true;
		break;
	case VK_SPACE:
		PlaceBubble(hWnd, units[0],0);		//默认第0个人是自己
		break;
	case VK_ESCAPE:

		pause_t = (pause_t+1)%2;
		for (int i = 0; i < buttons.size(); i++)
		{
			if (buttons[i]->buttonID == BUTTON_FAKEMENU|| buttons[i]->buttonID == BUTTON_RESTART||
				buttons[i]->buttonID == BUTTON_BACKTOGAME|| buttons[i]->buttonID == BUTTON_TOMENU)
			{
				if (pause_t == 1)
				{
					buttons[i]->visible = true;
				}
				else
				{
					buttons[i]->visible = false;
				}
			}
		}
	
		//currentStage->timerOn = false;
		break;
	case 0x46:
		keyFdown = true;
		break;
	case 0x45:
		keyEdown = true;
	default:
		break;
	}
}

// 键盘松开事件处理函数
void KeyUp(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	// TODO
	switch (wParam)
	{
	case 0x57:
		keyUpDown = false;
		break;
	case 0x53:
		keyDownDown = false;
		break;
	case 0x41:
		keyLeftDown = false;
		break;
	case 0x44:
		keyRightDown = false;
		break;
	case VK_ESCAPE:
		break;
	case 0x46:
		keyFdown = false;
	case 0x45:
		keyEdown = false;
	default:
		break;
	}
}

// 鼠标移动事件处理函数
void MouseMove(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	mouseX = LOWORD(lParam);
	mouseY = HIWORD(lParam);
}

// 鼠标左键按下事件处理函数
void LButtonDown(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	mouseX = LOWORD(lParam);
	mouseY = HIWORD(lParam);
	mouseDown = true;

	for (int i = 0; i < buttons.size(); i++)
	{
		Button* button = buttons[i];
		if (button->visible)
		{
			if (button->x <= mouseX
				&& button->x + button->width >= mouseX
				&& button->y <= mouseY
				&& button->y + button->height >= mouseY)
			{
				switch (button->buttonID) {
				case BUTTON_STARTGAME:
				{
					//TODO：判断进入哪个关卡
					InitStage(hWnd, STAGE_CHOOSE);
					break;
				}
				case BUTTON_INTRODUCTION_BACK:
				{
					InitStage(hWnd, STAGE_STARTMENU);
					break;
				}
				case BUTTON_CHOOSE_BACK:
				{
					InitStage(hWnd, STAGE_STARTMENU);
					break;
				}
				case BUTTON_PAGE1TOPAGE2:
				{
					InitStage(hWnd, STAGE_HELP2);
					break;
				}
				case BUTTON_PAGE2TOPAGE3:
				{
					InitStage(hWnd, STAGE_HELP3);
					break;
				}
				case BUTTON_PAGE3TOPAGE2:
				{
					InitStage(hWnd, STAGE_HELP2);
					break;
				}
				case BUTTON_PAGE2TOPAGE1:
				{
					InitStage(hWnd, STAGE_HELP);
					break;
				}
				case BUTTON_STAGE_1:
				{
					InitStage(hWnd, STAGE_1);
					break;
				}
				case BUTTON_STAGE_2:
				{
					InitStage(hWnd, STAGE_2);
					break;
				}
				case BUTTON_STAGE_3:
				{
					InitStage(hWnd, STAGE_3);
					break;
				}
				case BUTTON_STAGE_4:
				{
					InitStage(hWnd, STAGE_4);
					break;
				}
				case BUTTON_STAGE_5:
				{
					InitStage(hWnd, STAGE_5);
					break;
				}
				case BUTTON_STAGE_6:
				{
					InitStage(hWnd, STAGE_6);
					break;
				}
				case BUTTON_STAGE_7:
				{
					InitStage(hWnd, STAGE_7);
					break;
				}
				case BUTTON_STAGE_8:
				{
					InitStage(hWnd, STAGE_8);
					break;
				}
				
				case BUTTON_HELP:
				{
					InitStage(hWnd, STAGE_HELP);
				}
				break;

				case BUTTON_MENU:
				{
					InitStage(hWnd, STAGE_STARTMENU);
				}
				break;
				case BUTTON_BACKTOGAME:
				{
					pause_t = 0;
					for (int i = 0; i < buttons.size(); i++)
					{
						if (buttons[i]->buttonID == BUTTON_FAKEMENU || buttons[i]->buttonID == BUTTON_RESTART ||
							buttons[i]->buttonID == BUTTON_BACKTOGAME || buttons[i]->buttonID == BUTTON_TOMENU)
						{
							buttons[i]->visible = false;
						}
					}
				}
				break;
				case BUTTON_TOMENU:
				{
					pause_t = 0;
					InitStage(hWnd, STAGE_STARTMENU);
					for (int i = 0; i < buttons.size(); i++)
					{
						if (buttons[i]->buttonID == BUTTON_FAKEMENU || buttons[i]->buttonID == BUTTON_RESTART ||
							buttons[i]->buttonID == BUTTON_BACKTOGAME || buttons[i]->buttonID == BUTTON_TOMENU)
						{
							buttons[i]->visible = false;
						}
					}
				}
				break;
				case BUTTON_RESTART:
				{
					pause_t = 0;
					InitStage(hWnd, currentStage->stageID);
					for (int i = 0; i < buttons.size(); i++)
					{
						if (buttons[i]->buttonID == BUTTON_FAKEMENU || buttons[i]->buttonID == BUTTON_RESTART ||
							buttons[i]->buttonID == BUTTON_BACKTOGAME || buttons[i]->buttonID == BUTTON_TOMENU)
						{
							buttons[i]->visible = false;
						}
					}
				}
				}
			}
		}
	}

}

// 鼠标左键松开事件处理函数
void LButtonUp(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	mouseX = LOWORD(lParam);
	mouseY = HIWORD(lParam);
	mouseDown = false;
}

// 定时器事件处理函数
void TimerUpdate(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	if (pause_t == 0)
	{
		UpdateUnits(hWnd);
	}

	//刷新显示
	InvalidateRect(hWnd, NULL, FALSE);
}



//TODO: 添加游戏需要的更多函数

// 添加按钮函数
Button* CreateButton(int buttonID, HBITMAP img, int width, int height, int x, int y)
{
	Button* button = new Button();
	button->buttonID = buttonID;
	button->img = img;
	button->width = width;
	button->height = height;
	button->x = x;
	button->y = y;

	button->visible = false;
	return button;
}

// 添加主角函数
Unit* CreateUnit(int side, int x, int y, int health)
{
	Unit* unit = new Unit();
	unit->side = side;
	if (side == UNIT_SIDE_ME) {
		unit->img = bmp_Unit_Me;
		unit->direction = UNIT_DIRECT_RIGHT;
		unit->vx = 6;
		unit->vy = 6;
		unit->bubble_timer = 1000;
		unit->max_bubble = 1;
	}
	else if (side == UNIT_SIDE_RIVAL) {
		unit->img = bmp_Unit_Rival;
		unit->direction = UNIT_DIRECT_LEFT;
		unit->vx = 3;
		unit->vy = 3;
		unit->bubble_timer = 1000;
		unit->max_bubble = 1;
	}

	unit->state = UNIT_STATE_HOLD;


	unit->frame_row = unit->direction;
	unit->frame_column = 0;

	unit->frame_sequence = FRAMES_HOLD;
	unit->frame_count = FRAMES_HOLD_COUNT;
	unit->frame_id = 0;

	unit->x = x;
	unit->y = y;

	unit->health = health;
	unit->supertime = 2400;
	unit->boom_range = 2;		//设定初始爆炸范围数据为2//但是感觉这样可维护性不高
	unit->lifes = 1;			//初始的命数是1
	unit->skill = false;		//设定一开始没有技能
	unit->skill_energy = 0;		//设定一开始能量为0
	unit->has_switch_blood = false;	//设定一开始没有换血技能
	return unit;
}
//生成冲击波
Boom* CreateBoom(HBITMAP img,int x, int y, int owner, int count_down_duration,int location)
{
	Boom* boom = new Boom();
	boom->img = img;
	boom->x = x;
	boom->y = y;
	boom->owner = owner;
	boom->count_down_duration = count_down_duration;
	boom->localtion = location;//1定义为上下，0定义为左右
	return boom;
}



// 初始化游戏场景函数
void InitStage(HWND hWnd, int stageID)
{
	// 初始化场景实例
	if (currentStage != NULL) delete currentStage;
	currentStage = new Stage();
	currentStage->stageID = stageID;
	units.clear();
	bubbles.clear();
	booms.clear();
	Cbs.clear();
	have_warned = false;
	start_warning = false;
	pause_t = 0;
	me_has_undead = false;
	rival_has_undead = false;
	me_has_bs = false;
	rival_has_bs = false;
	me_has_speed_liquid = false;
	rival_has_speed_liquid = false;



	if (stageID == STAGE_STARTMENU) {
		bmp_Background= InitMenuBackGround(hWnd, bmp_BeginBG);
		currentStage->bg = bmp_Background;
		currentStage->timeCountDown = -200;
		currentStage->timerOn = false;

		//显示开始界面的按钮
		for (int i = 0; i < buttons.size(); i++)
		{
			Button* button = buttons[i];
			if (button->buttonID == BUTTON_STARTGAME|| button->buttonID == BUTTON_HELP)
			{
				button->visible = true;
			}
			else
			{
				button->visible = false;
			}
		}


	}
	else if (stageID == STAGE_HELP)
	{
		bmp_Background = InitMenuBackGround(hWnd, bmp_introduction1);
		currentStage->bg = bmp_Background;
		currentStage->timeCountDown = -200;
		currentStage->timerOn = false;

		//显示开始界面的按钮
		for (int i = 0; i < buttons.size(); i++)
		{
			Button* button = buttons[i];
			if (button->buttonID == BUTTON_PAGE1TOPAGE2|| button->buttonID == BUTTON_INTRODUCTION_BACK)
			{
				button->visible = true;
			}
			else
			{
				button->visible = false;
			}
		}


	}
	else if (stageID == STAGE_HELP2)
	{
		bmp_Background = InitMenuBackGround(hWnd, bmp_introduction2);
		currentStage->bg = bmp_Background;
		currentStage->timeCountDown = -200;
		currentStage->timerOn = false;

		//显示开始界面的按钮
		for (int i = 0; i < buttons.size(); i++)
		{
			Button* button = buttons[i];
			if (button->buttonID == BUTTON_PAGE2TOPAGE3|| button->buttonID == BUTTON_PAGE2TOPAGE1 || button->buttonID == BUTTON_INTRODUCTION_BACK)
			{
				button->visible = true;
			}
			else
			{
				button->visible = false;
			}
		}


	}
	else if (stageID == STAGE_HELP3)
	{
		bmp_Background = InitMenuBackGround(hWnd, bmp_introduction3);
		currentStage->bg = bmp_Background;
		currentStage->timeCountDown = -200;
		currentStage->timerOn = false;

		//显示开始界面的按钮
		for (int i = 0; i < buttons.size(); i++)
		{
			Button* button = buttons[i];
			if (button->buttonID == BUTTON_PAGE3TOPAGE2 || button->buttonID == BUTTON_INTRODUCTION_BACK)
			{
				button->visible = true;
			}
			else
			{
				button->visible = false;
			}
		}


	}
	else if (stageID == STAGE_CHOOSE)
	{
		bmp_Background = InitMenuBackGround(hWnd,bmp_choose_background);
		currentStage->bg = bmp_Background;
		currentStage->timeCountDown = -200;
		currentStage->timerOn = false;
		for (int i = 0; i < buttons.size(); i++)
		{
			Button* button = buttons[i];
			if (button->buttonID == BUTTON_STAGE_1|| button->buttonID == BUTTON_STAGE_2|| button->buttonID == BUTTON_STAGE_3||
				button->buttonID == BUTTON_STAGE_4|| button->buttonID == BUTTON_STAGE_5|| button->buttonID == BUTTON_STAGE_6||
				button->buttonID == BUTTON_STAGE_7|| button->buttonID == BUTTON_STAGE_8 || button->buttonID == BUTTON_CHOOSE_BACK)
			{
				button->visible = true;
			}
			else
			{
				button->visible = false;
			}
		}
	}
	else if (stageID >= STAGE_1&&stageID<=STAGE_8) //TODO：添加多个游戏场景
	{
		currentStage->bg = bmp_Grass;
		currentStage->timeCountDown = 180000;
		currentStage->timerOn = true;
		//这个作用是载入地图
		if (stageID == STAGE_1)
		{
			for (int i = 0; i < 12; i++)
			{
				for (int j = 0; j < 16; j++)
				{
					*(map[i] + j) = map1[i][j];
				}
			}
		}
		else if (stageID == STAGE_2)
		{
			for (int i = 0; i < 12; i++)
			{
				for (int j = 0; j < 16; j++)
				{
					*(map[i] + j) = map2[i][j];
				}
			}
		}
		else if (stageID == STAGE_3)
		{
			for (int i = 0; i < 12; i++)
			{
				for (int j = 0; j < 16; j++)
				{
					*(map[i] + j) = map3[i][j];
				}
			}
		}
		else if (stageID == STAGE_4)
		{
			for (int i = 0; i < 12; i++)
			{
				for (int j = 0; j < 16; j++)
				{
					*(map[i] + j) = map4[i][j];
				}
			}
		}
		else if (stageID == STAGE_5)
		{
			for (int i = 0; i < 12; i++)
			{
				for (int j = 0; j < 16; j++)
				{
					*(map[i] + j) = map5[i][j];
				}
			}
		}
		else if (stageID == STAGE_6)
		{
			for (int i = 0; i < 12; i++)
			{
				for (int j = 0; j < 16; j++)
				{
					*(map[i] + j) = map6[i][j];
				}
			}
		}
		else if (stageID == STAGE_7)
		{
			for (int i = 0; i < 12; i++)
			{
				for (int j = 0; j < 16; j++)
				{
					*(map[i] + j) = map7[i][j];
				}
			}
		}
		else if (stageID == STAGE_8)
		{
			for (int i = 1; i < 11; i++)
			{
				for (int j = 1; j < 15; j++)
				{
					*(map[i] + j) = rand() % 2;
				}
				*(map[1] + 1) = 0;
				*(map[10] + 14) = 0;

			}
		}


		//显示游戏界面的按钮
		
		for (int i = 0; i < buttons.size(); i++)
		{
			Button* button = buttons[i];
			if (button->buttonID==BUTTON_FAKEMENU&&button->visible) //TODO：加载游戏界面需要的按钮
			{
				button->visible = true;
			}
			else
			{
				button->visible = false;
			}
		}
		
		// 按场景初始化单位
	}
	switch (stageID) {
	case STAGE_1:
		units.push_back(CreateUnit(UNIT_SIDE_ME, 100, 70, 100));
		units.push_back(CreateUnit(UNIT_SIDE_RIVAL, 925, 650, 100));
		break;
	case STAGE_2:
		units.push_back(CreateUnit(UNIT_SIDE_ME, 100, 70, 100));
		units.push_back(CreateUnit(UNIT_SIDE_RIVAL, 925, 650, 100));
		break;
	case STAGE_3:
		units.push_back(CreateUnit(UNIT_SIDE_ME, 100, 70, 100));
		units.push_back(CreateUnit(UNIT_SIDE_RIVAL, 925, 650, 100));
		break;
	case STAGE_4:
		units.push_back(CreateUnit(UNIT_SIDE_ME, 100, 70, 100));
		units.push_back(CreateUnit(UNIT_SIDE_RIVAL, 925, 650, 100));
		break;
	case STAGE_5:
		units.push_back(CreateUnit(UNIT_SIDE_ME, 100, 70, 100));
		units.push_back(CreateUnit(UNIT_SIDE_RIVAL, 925, 650, 100));
		break;
	case STAGE_6:
		units.push_back(CreateUnit(UNIT_SIDE_ME, 420, 270, 100));
		units.push_back(CreateUnit(UNIT_SIDE_RIVAL, 610, 460, 100));
		break;
	case STAGE_7:
		units.push_back(CreateUnit(UNIT_SIDE_ME, 100, 70, 100));
		units.push_back(CreateUnit(UNIT_SIDE_RIVAL, 925, 650, 100));
		break;
	case STAGE_8:
		units.push_back(CreateUnit(UNIT_SIDE_ME, 100, 70, 100));
		units.push_back(CreateUnit(UNIT_SIDE_RIVAL, 925, 650, 100));
		break;
	default:
		break;
	}

	//刷新显示
	InvalidateRect(hWnd, NULL, FALSE);
}


// 刷新单位状态函数
void UpdateUnits(HWND hWnd)
{
	
	UnitBehaviour_Me(hWnd);
	UnitBehaviour_Rival(hWnd);
	UpdateBubbles(hWnd);
	CheckBooms(hWnd);
	Check_Boom_Block(hWnd, map);
	Count_Down_Timer();
	CreateSpecialItems(hWnd, map);
	UpdateItems(hWnd);
	Check_Unit_Item(hWnd);
	quick_game(hWnd, map);
	skill(hWnd);
	switch_blood(hWnd);
	timer_switch_blood(hWnd);
	delete_bubble_and_items(hWnd);
	stage_warnins(hWnd);
	

}
//这个函数是独立于计时器之外，进行暂停时用的

//单位行为函数
void UnitBehaviour_Me(HWND hWnd) {
	Unit* unit = units[0];
	//改变状态
	//如果键盘按下，设置状态为WALK
	if (keyLeftDown || keyUpDown || keyRightDown || keyDownDown) {
		unit->state = UNIT_STATE_WALK;
		unit->frame_sequence = FRAMES_WALK;
		unit->frame_count = FRAMES_WALK_COUNT;
		if (keyLeftDown) {
			unit->direction = UNIT_DIRECT_LEFT;
		}
		else if (keyUpDown) {
			unit->direction = UNIT_DIRECT_UP;
		}
		else if (keyRightDown) {
			unit->direction = UNIT_DIRECT_RIGHT;
		}
		else if (keyDownDown) {
			unit->direction = UNIT_DIRECT_DOWN;
		}
		unit->frame_row = unit->direction;
	}
	else {
		unit->state = UNIT_STATE_HOLD;
		unit->frame_sequence = FRAMES_HOLD;
		unit->frame_count = FRAMES_HOLD_COUNT;
	}
	//炸弹存储过程
	if (unit->bubble_timer < unit->max_bubble * 1000)
	{
		unit->bubble_timer += 20;
	}
	//更新无敌时间
	if (unit->supertime > 0)
	{
		unit->supertime -= 30;
	}
	//能量条恢复过程
	if (units[0]->skill == true && skilling == false)
	{
		units[0]->skill_energy += 15;
		if (units[0]->skill_energy >= 3200)
		{
			units[0]->skill_energy = 3200;
		}

	}
	//更新位置
	if (unit->state == UNIT_STATE_WALK) {
		int Unit_Block_Judge = Check_UnitMe_Block(hWnd, map);
		switch (unit->direction) {
		case UNIT_DIRECT_LEFT:
			if (Unit_Block_Judge != 3)
			{
				unit->x -= unit->vx;
			}
			break;
		case UNIT_DIRECT_UP:
			if (Unit_Block_Judge != 1)
			{
				unit->y -= unit->vy;
			}
			break;
		case UNIT_DIRECT_RIGHT:
			if (Unit_Block_Judge != 4)
			{
				unit->x += unit->vx;
			}
			break;
		case UNIT_DIRECT_DOWN:
			if (Unit_Block_Judge != 2)
			{
				unit->y += unit->vy;
			}
			break;
		default:
			break;
		};
	}

	//动画运行到下一帧
	unit->frame_id++;
	unit->frame_id = unit->frame_id % unit->frame_count;
	unit->frame_column = unit->frame_sequence[unit->frame_id];
}

//AI行为
void UnitBehaviour_Rival(HWND hWnd) {
	if (AI_level == 1)
	{
		Unit* me = units[0];
		Unit* rival = units[1];
		int dist_x = me->x - rival->x;							//两个人物之间的x距离
		int dist_y = me->y - rival->y;							//两个人物之间的y距离
		int dist = sqrt(dist_x * dist_x + dist_y * dist_y);		//两个人物之间的直线距离

		int Unit_Block_Judge = Check_UnitRival_Block(hWnd, map);
		//AI使用变身道具
		if (units[1]->skill == true)
		{
			if (units[1]->skill_energy > 1000 && dist <= 300&&rival_thriving==false)
			{
				rival_catching = true;
				rival_catching_timer = 10000;
				units[1]->vx = 8;
				units[1]->vy = 8;
				rival_skilling = true;
				units[1]->skill_energy -= 30;
			}
			else
			{
				if (rival_has_speed_liquid == true)
				{
					units[1]->vx = 5;
					units[1]->vy = 5;
					rival_skilling = false;
				}
				else
				{
					units[1]->vx = 3;
					units[1]->vy = 3;
					rival_skilling = false;
				}
				if (rival_catching == true)
				{
					rival_thriving = true;
					rival_catching_timer -= 30;
					if (rival_catching_timer <= 0)
					{
						rival_catching_timer = 0;
						rival_catching = false;
						rival_thriving = false;
					}
				}
			}
		}
		//AI使用换血道具
		if (rival->has_switch_blood == true&&rival->health<=40&&rival->health<units[0]->health)
		{
			
			start_switch_blood_timer = true; 
			rival->has_switch_blood = false;
		}



		
		//更新状态
		if (dist <= 10) {//当两个人物的距离小于20个像素时，不动
			rival->state = UNIT_STATE_HOLD;
			rival->frame_sequence = FRAMES_HOLD;
			rival->frame_count = FRAMES_HOLD_COUNT;
			blocked_time_x = 0;
			blocked_time_y = 0;
		}
		else {
			rival->state = UNIT_STATE_WALK;
			rival->frame_sequence = FRAMES_WALK;
			rival->frame_count = FRAMES_WALK_COUNT;
			if (dist_x < -10) 		//turn left
				rival->direction = UNIT_DIRECT_LEFT;
			else if (dist_y < -10)
				rival->direction = UNIT_DIRECT_UP;
			else if (dist_x > 10)
				rival->direction = UNIT_DIRECT_RIGHT;
			else if (dist_y > 10)
				rival->direction = UNIT_DIRECT_DOWN;
			rival->frame_row = rival->direction;
		}
		//炸弹存储过程
		if (rival->bubble_timer < rival->max_bubble * 1000)
		{
			rival->bubble_timer += 20;
		}
		//更新无敌时间
		if (rival->supertime > 0)
		{
			rival->supertime -= 30;
		}
		//更新能量条
		if (units[1]->skill == true && rival_skilling == false)
		{
			units[1]->skill_energy += 30;
			if (units[1]->skill_energy >= 3200)
			{
				units[1]->skill_energy = 3200;
			}
		}


		if (rival->state == UNIT_STATE_WALK) {
			switch (rival->direction) {
			case UNIT_DIRECT_LEFT:
				if (Unit_Block_Judge != 3)
				{
					rival->x -= rival->vx;
				}
				break;
			case UNIT_DIRECT_UP:
				if (Unit_Block_Judge != 1)
				{
					rival->y -= rival->vy;
				}
				break;
			case UNIT_DIRECT_RIGHT:
				if (Unit_Block_Judge != 4)
				{
					rival->x += rival->vx;
				}
				break;
			case UNIT_DIRECT_DOWN:
				if (Unit_Block_Judge != 2)
				{
					rival->y += rival->vy;
				}
				break;
			default:
				break;
			};
		}

		//这里看上去是放置炸弹的逻辑，在后期可以调整试一试
		//当人物之间的距离小于100像素的时候放炸弹
		if ((dist<=100)|| Unit_Block_Judge != 0) {
			PlaceBubble(hWnd, rival, 1);

		}


		//动画运行到下一帧
		rival->frame_id++;
		rival->frame_id = rival->frame_id % rival->frame_count;
		rival->frame_column = rival->frame_sequence[rival->frame_id];
	}
	
}

// 放置泡泡
void PlaceBubble(HWND hWnd, Unit* unit,int owner)
{
	Bubble* newBubble = new Bubble();
	int x = unit->x;
	int y = unit->y + 0.5 * UNIT_SIZE_Y - 0.5 * BUBBLE_SIZE_Y;			//应放置在脚下
	newBubble->x = BG_CELL_WIDTH * (x / BG_CELL_WIDTH + 0.5);		//把泡泡调整在格子中间//这个可以保证在正中间，可以为日后的冲击波-箱子检测提供基础
	newBubble->y = BG_CELL_HEIGHT * (y / BG_CELL_HEIGHT + 0.5);

	//若此处已有泡泡，则不创建
	bool hasBubble = false;
	int curx = newBubble->x / BG_CELL_WIDTH;
	int cury = newBubble->y / BG_CELL_HEIGHT;
	for (int i = 0; i < bubbles.size(); i++)
	{	
		//对判断是否有泡泡的修正：加入了已有泡泡是否已经爆炸的判断
		if (bubbles[i]->x == newBubble->x && bubbles[i]->y == newBubble->y&&bubbles[i]->count_down_duration>=0)
		{
			hasBubble = true;
			break;
		}
	}
	if ((!hasBubble)&&unit->bubble_timer>=1000) {//加入是否已经储存了一颗炸弹的判断
		newBubble->count_down_duration = 2000;		//爆炸时长毫秒
		//根据人物参数调节爆炸范围
		if (unit->boom_range == 2)
		{
			newBubble->range = 2;					//爆炸半径
		}
		else
		{
			newBubble->range = 3;					//这个是确定新的爆炸范围的函数
		}
		newBubble->frame_id = 0;
		newBubble->frame_colume = 0;
		newBubble->owner = owner;
		if (owner == 0)
		{
			newBubble->img = bmp_Bubble;
		}
		if (owner == 1)
		{
			newBubble->img = bmp_bubble_rival;
		}
		
		newBubble->timer_id = next_bubble_timer_id;
		next_bubble_timer_id += 1;
		bubbles.push_back(newBubble);
		//将这行注释掉解决了卡顿的问题，但不知道这一行具体有什么用
		//SetTimer(hWnd, newBubble->timer_id, newBubble->count_down_duration, NULL);
		unit->bubble_timer -= 1000;//减少一颗炸弹
	}
}

//生成道具的函数
void CreateSpecialItems(HWND hWnd,int(*map)[16])
{
	bool if_number_thrive = false;		//是否已经生成过不死图腾
	bool if_number_skill = false;		//是否已经生成过变身道具
	bool if_switch_blood = false;		//是否已经生成过换血道具

	//分别计算不同道具在场上的个数
	int number_cartridge = 0;		//弹药匣道具的个数
	int number_boom_range = 0;		//威力药水的个数
	int number_speed_liquid = 0;	//速度药水个数
	int number_thrive = 0;			//不死图腾的个数
	for (int i = 0; i < Cbs.size(); i++)
	{
		Cartridge_Bag* cb = Cbs[i];
		if (cb->used == false)
		{
			switch (cb->feature)
			{
			case 1:
				number_cartridge++;
				break;
			case 2:
				number_boom_range++;
				break;
			case 3:
				number_speed_liquid++;
				break;
			case 4:
				number_thrive++;
				break;
			default:
				break;
			}

		}
	}
	for (int i = 0; i < Cbs.size(); i++)
	{
		Cartridge_Bag* cb = Cbs[i];
		switch (cb->feature)
		{
		case 4:
			if_number_thrive = true;
			break;
		case 5:
			if_number_skill = true;
			break;
		case 6:
			if_switch_blood = true;
		default:
			break;
		}

		
	}

	//随机生成弹药匣道具
	if (rand() % 300 == 0)
	{
		//生成思路：随机生成两个地图坐标，判断是否可以放置道具，如果可以就放置
		int x_ray = rand() % 16;		//分别生成两个坐标
		int y_ray = rand() % 12;
		bool right_block = false;
		bool no_item = true;
		if (*(map[y_ray] + x_ray) == 0 && number_cartridge < 1)
		{
			right_block = true;
			for (int i = 0; i < Cbs.size(); i++)
			{
				Cartridge_Bag* cb = Cbs[i];
				if (cb->x == x_ray * 64 + 32 && cb->y == y_ray * 64 + 32)
				{
					no_item = false;		//判断这个方块是否有道具
				}
			}
			if (no_item == true)
			{
				//进行道具的创建
				Cartridge_Bag* new_cb = new Cartridge_Bag();
				new_cb->img = bmp_Cb;
				new_cb->x = x_ray * 64 + 32;
				new_cb->y = y_ray * 64 + 32;
				new_cb->frame_id = 0;
				new_cb->used = false;
				new_cb->feature = 1;		//弹药匣的特征值是1
				Cbs.push_back(new_cb);
			}
		}
	}
	//随机生成威力药水道具
	if (rand() % 300 == 0)
	{
		//生成思路：随机生成两个地图坐标，判断是否可以放置道具，如果可以就放置
		int x_ray = rand() % 16;		//分别生成两个坐标
		int y_ray = rand() % 12;
		bool right_block = false;
		bool no_item = true;
		if (*(map[y_ray] + x_ray) == 0 && number_boom_range < 1)
		{
			right_block = true;
			for (int i = 0; i < Cbs.size(); i++)
			{
				Cartridge_Bag* cb = Cbs[i];
				if (cb->x == x_ray * 64 + 32 && cb->y == y_ray * 64 + 32)
				{
					no_item = false;		//判断这个方块是否有道具
				}
			}
			if (no_item == true)
			{
				//进行道具的创建
				Cartridge_Bag* new_cb = new Cartridge_Bag();
				new_cb->img = bmp_Power_Liquid;
				new_cb->x = x_ray * 64 + 32;
				new_cb->y = y_ray * 64 + 32;
				new_cb->frame_id = 0;
				new_cb->used = false;
				new_cb->feature = 2;		//威力药水的特征值是2
				Cbs.push_back(new_cb);
			}
		}
	}
	//随机生成速度药水道具
	if (rand() % 300 == 0)
	{
		//生成思路：随机生成两个地图坐标，判断是否可以放置道具，如果可以就放置
		int x_ray = rand() % 16;		//分别生成两个坐标
		int y_ray = rand() % 12;
		bool right_block = false;
		bool no_item = true;
		if (*(map[y_ray] + x_ray) == 0 && number_speed_liquid < 1)
		{
			right_block = true;
			for (int i = 0; i < Cbs.size(); i++)
			{
				Cartridge_Bag* cb = Cbs[i];
				if (cb->x == x_ray * 64 + 32 && cb->y == y_ray * 64 + 32)
				{
					no_item = false;		//判断这个方块是否有道具
				}
			}
			if (no_item == true)
			{
				//进行道具的创建
				Cartridge_Bag* new_cb = new Cartridge_Bag();
				new_cb->img = bmp_Speed_Liquid;
				new_cb->x = x_ray * 64 + 32;
				new_cb->y = y_ray * 64 + 32;
				new_cb->frame_id = 0;
				new_cb->used = false;
				new_cb->feature = 3;		//速度药水的特征值是3
				Cbs.push_back(new_cb);
			}
		}
	}
	//随机生成不死图腾道具
	if (currentStage->timeCountDown >= 60000 && currentStage->timeCountDown <=120000)
	{
		if (rand() % 200 == 0&&if_number_thrive==false)
		{
			//生成思路：随机生成两个地图坐标，判断是否可以放置道具，如果可以就放置
			int x_ray = rand() % 16;		//分别生成两个坐标
			int y_ray = rand() % 12;
			bool right_block = false;
			bool no_item = true;
			if (*(map[y_ray] + x_ray) == 0 && number_thrive < 1)
			{
				right_block = true;
				for (int i = 0; i < Cbs.size(); i++)
				{
					Cartridge_Bag* cb = Cbs[i];
					if (cb->x == x_ray * 64 + 32 && cb->y == y_ray * 64 + 32)
					{
						no_item = false;		//判断这个方块是否有道具
					}
				}
				if (no_item == true)
				{
					//进行道具的创建
					Cartridge_Bag* new_cb = new Cartridge_Bag();
					new_cb->img = bmp_undead;
					new_cb->x = x_ray * 64 + 32;
					new_cb->y = y_ray * 64 + 32;
					new_cb->frame_id = 0;
					new_cb->used = false;
					new_cb->feature = 4;		//不死图腾的特征值是4
					Cbs.push_back(new_cb);
					//说明已经生成过不死图腾，不再生成
					if_number_thrive = true;
				}
			}
		}
	}
	//随机生成变身道具
	if(currentStage->timeCountDown >= 120000 && currentStage->timeCountDown <= 180000)
	{
		if (rand() % 200 == 0 && if_number_skill == false)
		{
			//生成思路：随机生成两个地图坐标，判断是否可以放置道具，如果可以就放置
			int x_ray = rand() % 16;		//分别生成两个坐标
			int y_ray = rand() % 12;
			bool right_block = false;
			bool no_item = true;
			if (*(map[y_ray] + x_ray) == 0)
			{
				right_block = true;
				for (int i = 0; i < Cbs.size(); i++)
				{
					Cartridge_Bag* cb = Cbs[i];
					if (cb->x == x_ray * 64 + 32 && cb->y == y_ray * 64 + 32)
					{
						no_item = false;		//判断这个方块是否有道具
					}
				}
				if (no_item == true)
				{
					//进行道具的创建
					Cartridge_Bag* new_cb = new Cartridge_Bag();
					new_cb->img = bmp_skill;
					new_cb->x = x_ray * 64 + 32;
					new_cb->y = y_ray * 64 + 32;
					new_cb->frame_id = 0;
					new_cb->used = false;
					new_cb->feature = 5;		//变身道具的特征值是5
					Cbs.push_back(new_cb);
					//说明已经生成过变身道具，不再生成（这一行好像没什么用）
					if_number_skill = true;
				}
			}
		}
	}
	//随机生成换血道具
	if (currentStage->timeCountDown >= 0 && currentStage->timeCountDown <= 60000)
	{
		if (rand() % 200 == 0 && if_switch_blood == false)
		{
			//生成思路：随机生成两个地图坐标，判断是否可以放置道具，如果可以就放置
			int x_ray = rand() % 16;		//分别生成两个坐标
			int y_ray = rand() % 12;
			bool right_block = false;
			bool no_item = true;
			if (*(map[y_ray] + x_ray) == 0)
			{
				right_block = true;
				for (int i = 0; i < Cbs.size(); i++)
				{
					Cartridge_Bag* cb = Cbs[i];
					if (cb->x == x_ray * 64 + 32 && cb->y == y_ray * 64 + 32)
					{
						no_item = false;		//判断这个方块是否有道具
					}
				}
				if (no_item == true)
				{
					//进行道具的创建
					Cartridge_Bag* new_cb = new Cartridge_Bag();
					new_cb->img = bmp_switch_blood;
					new_cb->x = x_ray * 64 + 32;
					new_cb->y = y_ray * 64 + 32;
					new_cb->frame_id = 0;
					new_cb->used = false;
					new_cb->feature = 6;		//换血道具的特征值是6
					Cbs.push_back(new_cb);
					//说明已经生成过换血道具，不再生成（这一行好像没什么用）
					if_switch_blood = true;
				}
			}
		}
	}
	

}

//更新道具状态的函数
void UpdateItems(HWND hWnd)
{
	for (int i = 0; i < Cbs.size(); i++)
	{
		Cartridge_Bag* cb = Cbs[i];
		cb->frame_id = (cb->frame_id + 1) % 48;
	}
}

//检测人物和道具是否发生碰撞
void Check_Unit_Item(HWND hWnd)
{
	for (int i = 0; i < units.size(); i++)
	{
		Unit* unit = units[i];
		for (int j = 0; j < Cbs.size(); j++)
		{
			Cartridge_Bag* cb = Cbs[j];
			//利用脚底判定，如果和道具坐标接近就判定为拿到了道具
			if (cb->used == false)//先判断这个道具有没有用过
			{
				
				int abs_length = sqrt((cb->x - unit->x) * (cb->x - unit->x) + (cb->y - unit->y-35) * (cb->y - unit->y-35));
				if (abs_length <= 25)
				{
					cb->used = true;
					switch (cb->feature)
					{
						//识别到道具是弹药匣
					case 1:
						unit->max_bubble += 1;
						break;
						//识别到道具是威力药水
					case 2:
						unit->boom_range += 1;
						break;
						//识别到道具是速度药水
					case 3:
						//这个是为了帮助变身道具进行的必要操作
						if (i == 0)
						{
							unit->vx = 8;
							unit->vy = 8;
							me_has_speed_liquid = true;
						}
						else
						{
							unit->vx = 5;
							unit->vy = 5;
							rival_has_speed_liquid = true;
						}
						
						break;
					case 4:
						unit->lifes += 1;
						if (unit->side == UNIT_SIDE_ME)
						{
							me_has_undead = true;
						}
						else
						{
							rival_has_undead = true;
						}
						//识别到是不死图腾
						break;
					case 5:
						unit->lifes += 1;
						unit->skill = true;
						unit->skill_energy = 3200;
						if (unit->side == UNIT_SIDE_ME)
						{
							me_has_bs = true;
						}
						else
						{
							rival_has_bs = true;
						}
						//识别到变身道具
						break;
					case 6:
						unit->has_switch_blood = true;
						//识别到是换血道具
						break;
					}


				}
			}
		}
	}
}

//加速游戏进程函数
void quick_game(HWND hWnd,int (*map)[16])
{
	//当游戏的剩余时间小于一分钟的时候，随机放置泡泡
	if (currentStage->timeCountDown <= 60000 && currentStage->timeCountDown >= 0)
	{
		if (rand() % 50 == 0)
		{
			int x_ray = rand() % 16;		//分别生成两个坐标
			int y_ray = rand() % 12;
			if (*(map[y_ray] + x_ray) == 0)
			{
				//若此处已有泡泡，则不创建
				Bubble* newBubble = new Bubble();
				bool hasBubble = false;
				newBubble->x = 64 * x_ray + 32;
				newBubble->y = 64 * y_ray + 32;
				for (int i = 0; i < bubbles.size(); i++)
				{
					//对判断是否有泡泡的修正：加入了已有泡泡是否已经爆炸的判断
					if (bubbles[i]->x == newBubble->x && bubbles[i]->y == newBubble->y && bubbles[i]->count_down_duration >= 0)
					{
						hasBubble = true;
						break;
					}
				}
				for (int i = 0; i < Cbs.size(); i++)
				{
					//是否有道具
					if (Cbs[i]->x == newBubble->x && Cbs[i]->y == newBubble->y && Cbs[i]->used==false)
					{
						hasBubble = true;
						break;
					}
				}
				if (hasBubble == false)
				{
					newBubble->count_down_duration = 2000;		//爆炸时长毫秒
					newBubble->range = 3;					
					newBubble->frame_id = 0;
					newBubble->frame_colume = 0;
					newBubble->owner = 3;
					newBubble->img = bmp_bubble_stage;
					newBubble->timer_id = next_bubble_timer_id;
					bubbles.push_back(newBubble);
				}

			}
		}
	}
}

//检测变身道具能量
void skill(HWND hWnd)
{
	if (keyFdown == true)
	{
		if (units[0]->skill == true)
		{
			if (units[0]->skill_energy > 30)
			{
				skilling = true;
				units[0]->vx = 12;
				units[0]->vy = 12;
				units[0]->skill_energy -= 30;
			}
			if (units[0]->skill_energy <= 30)
			{
				if (me_has_speed_liquid == true)
				{
					units[0]->vx = 8;
					units[0]->vy = 8;
				}
				else
				{
					units[0]->vx = 6;
					units[0]->vy = 6;
				}
			}

		}
	}
	if (keyFdown == false)
	{
		if (units[0]->skill == true)
		{
			skilling = false;
			if (me_has_speed_liquid == true)
			{
				units[0]->vx = 8;
				units[0]->vy = 8;
			}
			else
			{
				units[0]->vx = 6;
				units[0]->vy = 6;
			}

		}
	}
}

//玩家使用换血道具函数
void switch_blood(HWND hWnd)
{
	if (keyEdown == true && units[0]->has_switch_blood == true)
	{
		
		start_switch_blood_timer = true;

	}
}

//换血道具吟唱计时器
void timer_switch_blood(HWND hWnd)
{
	if (start_switch_blood_timer == true)
	{
		switch_blood_timer += 30;
	}
}

//删除已经使用过的泡泡，冲击破以及道具(不算上三个特殊道具）
void delete_bubble_and_items(HWND hWnd)
{
	vector<Bubble*>::iterator it1;
	for (it1 = bubbles.begin(); it1 != bubbles.end();)
	{
		if ((*it1)->count_down_duration == -100)
		{
			it1 = bubbles.erase(it1);
		}
		else
		{
			++it1;
		}
	}
	vector<Cartridge_Bag*>::iterator it2;
	for (it2 = Cbs.begin(); it2 != Cbs.end();)
	{
		if ((*it2)->used==true&&(*it2)->feature!=4&& (*it2)->feature != 5&&(*it2)->feature != 6)
		{
			it2 = Cbs .erase(it2);
		}
		else
		{
			++it2;
		}
	}
	vector<Boom*>::iterator it3;
	for (it3 = booms.begin(); it3 != booms.end();)
	{
		if ((*it3)->count_down_duration == -100)
		{
			it3 = booms.erase(it3);
		}
		else
		{
			++it3;
		}
	}

}

void stage_warnins(HWND hWnd)
{
	if (currentStage->timeCountDown <= 60000 && currentStage->timeCountDown <= 60000)
	{
		start_warning = true;
	}
}



//更新泡泡的帧动画
void UpdateBubbles(HWND hWnd)
{
	for (int i = 0; i < bubbles.size(); i++) {
		Bubble* bubble = bubbles[i];
		bubble->frame_id = (bubble->frame_id + 1) % FRAMES_BUBBLE_COUNT;
		bubble->frame_colume = FRAMES_BUBBLE[bubble->frame_id];
		if (bubble->count_down_duration > -20)//写一个防止爆炸时长溢出的判断，当爆炸时长为-20的时候不再发生改变
		{
			bubble->count_down_duration -= 20;//这个是每一帧刷新时减少每一个泡泡的爆炸时长
			//最终计时器的数值会停留在-20（没有进行爆炸操作的时候）
		}
		//新建冲击波成员
		if (bubble->count_down_duration == -20)
		{
			{
				if (bubble->range == 2)//强化前的爆炸范围
				{

					//分成四个部分建立
					booms.push_back(CreateBoom(bmp_Bubble_Boom, bubble->x, bubble->y + 64, bubble->owner, 1000, 1));
					booms.push_back(CreateBoom(bmp_Bubble_Boom, bubble->x, bubble->y - 64, bubble->owner, 1000, 1));
					booms.push_back(CreateBoom(bmp_Bubble_Boom, bubble->x + 64, bubble->y, bubble->owner, 1000, 0));
					booms.push_back(CreateBoom(bmp_Bubble_Boom, bubble->x - 64, bubble->y, bubble->owner, 1000, 0));
				}
				else//强化后的爆炸范围
				{
					booms.push_back(CreateBoom(bmp_Bubble_Boom, bubble->x, bubble->y + 64, bubble->owner, 1000, 1));
					booms.push_back(CreateBoom(bmp_Bubble_Boom, bubble->x, bubble->y - 64, bubble->owner, 1000, 1));
					booms.push_back(CreateBoom(bmp_Bubble_Boom, bubble->x + 64, bubble->y, bubble->owner, 1000, 0));
					booms.push_back(CreateBoom(bmp_Bubble_Boom, bubble->x - 64, bubble->y, bubble->owner, 1000, 0));

					booms.push_back(CreateBoom(bmp_Bubble_Boom, bubble->x, bubble->y + 128, bubble->owner, 1000, 1));
					booms.push_back(CreateBoom(bmp_Bubble_Boom, bubble->x, bubble->y - 128, bubble->owner, 1000, 1));
					booms.push_back(CreateBoom(bmp_Bubble_Boom, bubble->x + 128, bubble->y, bubble->owner, 1000, 0));
					booms.push_back(CreateBoom(bmp_Bubble_Boom, bubble->x - 128, bubble->y, bubble->owner, 1000, 0));
				}
				bubble->count_down_duration = -100;//设定特殊状态为删除做准备
			}
		}
		
		//删除已经爆炸的泡泡
		//先不做这个看看vector内元素过多会不会导致问题
	}
	/*
	for (int i = 0; i < delete_bubbles.size(); i++)
	{
		auto iter = bubbles.erase(bubbles.begin() + delete_bubbles.size() - 1 - i);
	}
	delete_bubbles.clear();
	*/
}

void CheckBooms(HWND hWnd)
{
		Unit* unit0 = units[0];
		Unit* unit1 = units[1];
		//暂且写成两个人物吧
		for (int i = 0; i < booms.size(); i++)
		{
			Boom* boom = booms[i];
			if ((boom->count_down_duration >= 0)&&(boom->owner!=0))
			{
				//先不进行冲击波所属者判定
				

					//检测是否和人物发生了碰撞
					//应当设计无敌时间
					if (
						//这个是人物的右下角和冲击波的左上角
						//(unit0->x + 0.5 * UNIT_SIZE_X > boom->x - 0.5 * BUBBLE_SIZE_X) &&
						//(unit0->x + 0.5 * UNIT_SIZE_X < boom->x + 0.5 * BUBBLE_SIZE_X) &&
						//(unit0->y + 0.5 * UNIT_SIZE_Y > boom->x - 0.5 * BUBBLE_SIZE_Y) &&
						//(unit0->y + 0.5 * UNIT_SIZE_Y < boom->x + 0.5 * BUBBLE_SIZE_Y) ||
						((unit0->x > boom->x - 0.5 * BUBBLE_SIZE_X) && (unit0->x < boom->x + 0.5 * BUBBLE_SIZE_X) && (unit0->y + 0.5 * UNIT_SIZE_Y > boom->y - 0.5 * BUBBLE_SIZE_Y) && (unit0->y + 0.5 * UNIT_SIZE_Y < boom->y + 0.5 * BUBBLE_SIZE_Y))
						)
					{
						if (unit0->supertime <= 0)
						{
							unit0->health -= 20;//减少人物的血量（自己）
							unit0->supertime = 2400;//受到伤害后给予2.4秒的无敌时间
						}
					}
					else if
						(
							//这个是人物的左下角和冲击波的右上角
							//(unit0->x - 0.5 * UNIT_SIZE_X > boom->x - 0.5 * BUBBLE_SIZE_X) &&
							//(unit0->x - 0.5 * UNIT_SIZE_X < boom->x + 0.5 * BUBBLE_SIZE_X) &&
							//(unit0->y + 0.5 * UNIT_SIZE_Y < boom->x + 0.5 * BUBBLE_SIZE_Y) &&
							//(unit0->y + 0.5 * UNIT_SIZE_Y > boom->x - 0.5 * BUBBLE_SIZE_Y) ||
							((unit0->x > boom->x - 0.5 * BUBBLE_SIZE_X) && (unit0->x < boom->x + 0.5 * BUBBLE_SIZE_X) && (unit0->y + 0.5 * UNIT_SIZE_Y > boom->y - 0.5 * BUBBLE_SIZE_Y) && (unit0->y + 0.5 * UNIT_SIZE_Y < boom->y + 0.5 * BUBBLE_SIZE_Y))
							)

					{
						if (unit0->supertime <= 0)
						{
							unit0->health -= 20;//减少人物的血量（自己）
							unit0->supertime = 2400;//受到伤害后给予2.4秒的无敌时间
						}
					}


					else if
						(
							//这个是人物的左上角和冲击波的右下角
							//(unit0->x - 0.5 * UNIT_SIZE_X > boom->x - 0.5 * BUBBLE_SIZE_X) &&
							//(unit0->x - 0.5 * UNIT_SIZE_X < boom->x + 0.5 * BUBBLE_SIZE_X) &&
							//(unit0->y - 0.5 * UNIT_SIZE_Y < boom->x + 0.5 * BUBBLE_SIZE_Y) &&
							//(unit0->y - 0.5 * UNIT_SIZE_Y > boom->x - 0.5 * BUBBLE_SIZE_Y) || 
							((unit0->x > boom->x - 0.5 * BUBBLE_SIZE_X) && (unit0->x < boom->x + 0.5 * BUBBLE_SIZE_X) && (unit0->y + 0.5 * UNIT_SIZE_Y > boom->y - 0.5 * BUBBLE_SIZE_Y) && (unit0->y + 0.5 * UNIT_SIZE_Y < boom->y + 0.5 * BUBBLE_SIZE_Y))
							)

					{
						if (unit0->supertime <= 0)
						{
							unit0->health -= 20;//减少人物的血量（自己）
							unit0->supertime = 2400;//受到伤害后给予2.4秒的无敌时间
						}
					}

					else if
						(
							//这个是人物的右上角和冲击波的左下角
							//(unit0->x + 0.5 * UNIT_SIZE_X > boom->x - 0.5 * BUBBLE_SIZE_X) &&
							//(unit0->x + 0.5 * UNIT_SIZE_X < boom->x + 0.5 * BUBBLE_SIZE_X) &&
							//(unit0->y - 0.5 * UNIT_SIZE_Y < boom->x + 0.5 * BUBBLE_SIZE_Y) &&
							//(unit0->y - 0.5 * UNIT_SIZE_Y > boom->x - 0.5 * BUBBLE_SIZE_Y) || 
							((unit0->x > boom->x - 0.5 * BUBBLE_SIZE_X) && (unit0->x < boom->x + 0.5 * BUBBLE_SIZE_X) && (unit0->y + 0.5 * UNIT_SIZE_Y > boom->y - 0.5 * BUBBLE_SIZE_Y) && (unit0->y + 0.5 * UNIT_SIZE_Y < boom->y + 0.5 * BUBBLE_SIZE_Y))
							)
					{
						if (unit0->supertime <= 0)
						{
							unit0->health -= 20;//减少人物的血量（自己）
							unit0->supertime = 2400;//受到伤害后给予2.4秒的无敌时间
						}
					}
				
			}
			if ((boom->count_down_duration >= 0) && (boom->owner !=1))
			{
				//先不进行冲击波所属者判定


					//检测是否和人物发生了碰撞
					//应当设计无敌时间
				if (

					((unit1->x > boom->x - 0.5 * BUBBLE_SIZE_X) &&
						(unit1->x < boom->x + 0.5 * BUBBLE_SIZE_X) &&
						(unit1->y + 0.5 * UNIT_SIZE_Y > boom->y - 0.5 * BUBBLE_SIZE_Y) && 
						(unit1->y + 0.5 * UNIT_SIZE_Y < boom->y + 0.5 * BUBBLE_SIZE_Y))
					)
				{
					if (unit1->supertime <= 0)
					{
						unit1->health -= 20;//减少人物的血量（敌人）
						unit1->supertime = 2400;//受到伤害后给予2.4秒的无敌时间
					}
				}
				else if
					(
		
						((unit1->x > boom->x - 0.5 * BUBBLE_SIZE_X) && 
							(unit1->x < boom->x + 0.5 * BUBBLE_SIZE_X) && 
							(unit1->y + 0.5 * UNIT_SIZE_Y > boom->y - 0.5 * BUBBLE_SIZE_Y) && 
							(unit1->y + 0.5 * UNIT_SIZE_Y < boom->y + 0.5 * BUBBLE_SIZE_Y))
						)

				{
					if (unit1->supertime <= 0)
					{
						unit1->health -= 20;//减少人物的血量（敌人）
						unit1->supertime = 2400;//受到伤害后给予2.4秒的无敌时间
					}
				}


				else if
					(
	
						((unit1->x > boom->x - 0.5 * BUBBLE_SIZE_X) &&
							(unit1->x < boom->x + 0.5 * BUBBLE_SIZE_X) &&
							(unit1->y + 0.5 * UNIT_SIZE_Y > boom->y - 0.5 * BUBBLE_SIZE_Y) &&
							(unit1->y + 0.5 * UNIT_SIZE_Y < boom->y + 0.5 * BUBBLE_SIZE_Y))
						)

				{
					if (unit1->supertime <= 0)
					{
						unit1->health -= 20;//减少人物的血量（敌人）
						unit1->supertime = 2400;//受到伤害后给予2.4秒的无敌时间
					}
				}

				else if
					(
	
						((unit1->x > boom->x - 0.5 * BUBBLE_SIZE_X) &&
							(unit1->x < boom->x + 0.5 * BUBBLE_SIZE_X) &&
							(unit1->y+0.5*UNIT_SIZE_Y > boom->y - 0.5 * BUBBLE_SIZE_Y) &&
							(unit1->y+0.5 * UNIT_SIZE_Y < boom->y + 0.5 * BUBBLE_SIZE_Y))
						)
				{
					if (unit1->supertime <= 0)
					{
						unit1->health -= 20;//减少人物的血量（敌人）
						unit1->supertime = 2400;//受到伤害后给予2.4秒的无敌时间
					}
				}
			}
			if (unit0->health <= 0)
			{
				if (unit0->lifes != 1)
				{
					if (unit0->lifes == 2)
					{
						if (unit0->skill == false)
						{
							unit0->lifes = 1;
							unit0->health = 100;
							last_time_bu = 2000;
							me_has_undead = false;
						}
						else
						{
							me_has_bs = false;
							unit0->skill = false; 
							unit0->skill_energy = 0;
							if (me_has_speed_liquid == true)
							{
								units[0]->vx = 8;
								units[0]->vy = 8;
							}
							else
							{
								units[0]->vx = 6;
								units[0]->vy = 6;
							}
							unit0->lifes = 1;
							unit0->health = 100;
							last_time_skill = 2000;

						}
					}
					if (unit0->lifes == 3)
					{
						unit0->lifes = 2;
						unit0->health = 100;
						last_time_bu = 2000;
						me_has_undead = false;
					}
				}
				else
				{
					for (int j = 0; j < buttons.size(); j++)
					{
						Button* button = buttons[j];
						if (button->buttonID == BUTTON_RESTART || button->buttonID == BUTTON_TOMENU)
						{
							button->visible = true;
						}

					}
					pause_t = 1;
				}
			}
			if (unit1->health <= 0)
			{
				if (unit1->lifes != 1)
				{
					if (unit1->lifes == 2)
					{
						if (unit1->skill == false)
						{
							rival_has_undead = false;
							unit1->lifes = 1;
							unit1->health = 100;
							last_time_bu = 2000;
						}
						else
						{
							rival_has_bs = false;
							unit1->skill = false;
							unit1->skill_energy = 0;
							if (rival_has_speed_liquid == true)
							{
								units[1]->vx = 5;
								units[1]->vy = 5;

							}
							else
							{
								units[1]->vx = 3;
								units[1]->vy = 3;

							}
							unit1->lifes = 1;
							unit1->health = 100;
							last_time_skill = 2000;
						}
					}
					if (unit1->lifes == 3)
					{
						rival_has_undead = false;
						unit1->lifes = 2;
						unit1->health = 100;
						last_time_bu = 2000;
					}
				}
				else
				{
					for (int j = 0; j < buttons.size(); j++)
					{
						Button* button = buttons[j];
						if (button->buttonID == BUTTON_RESTART || button->buttonID == BUTTON_TOMENU)
						{
							button->visible = true;
						}

					}
					pause_t = 1;
				}
			}
		}
	
}

void Check_Boom_Block(HWND hWnd,int (*map)[16])
{
	for (int i = 0; i < booms.size(); i++)
	{
		Boom* boom = booms[i];
		for (int j = 0; j<12; j++)
		{
			for (int k = 0; k < 16; k++)
			{
				//如果冲击波的位置和背景格坐标重合，改变map数据
				if (*(map[j]+k) == 1)
				{
					if ((boom->x == k * 64 + 32) && (boom->y == j * 64 + 32))
					{
						*(map[j] + k) = 0;
					}
				}
			}
		}
	}
}

int Check_UnitMe_Block(HWND hWnd, int(*map)[16])
{
	//考虑把脚下的坐标分为三个
	//分别用1，2，3，4代表上下左右四个方向被阻挡，若没有方向被阻挡则返回0
	{
		Unit* unit = units[0];
		for (int j = 0; j < 12; j++)
		{
			for (int k = 0; k < 16; k++)
			{
				if (*(map[j] + k) == 1|| *(map[j] + k) == 2)
				{
					int x = k * 64 + 32;
					int y = j * 64 + 32;
					if (unit->direction == UNIT_DIRECT_LEFT)//第一种情况是单位向左走，单位的左边与障碍物的右边进行判定
					{
						if ((unit->x - 0.5 * UNIT_SIZE_X >= x - 32) && (unit->x - 0.5 * UNIT_SIZE_X<=x+32)&&(unit->y+0.5*UNIT_SIZE_Y>=y-35)&& (unit->y + 0.5 * UNIT_SIZE_Y <= y + 35))
						{
							return 3;
						}
						
					}
					if (unit->direction == UNIT_DIRECT_RIGHT)//第二种情况是单位向右走，单位的右边与障碍物的左边进行判定
					{
						if ((unit->x + 0.5 * UNIT_SIZE_X <= x + 32)&&(unit->x + 0.5 * UNIT_SIZE_X >= x - 32) && (unit->y + 0.5 * UNIT_SIZE_Y >= y - 35) && (unit->y + 0.5 * UNIT_SIZE_Y <= y + 35))
						{
							return 4;
						}
						
					}
					if (unit->direction == UNIT_DIRECT_UP)//第三种情况是单位向上走，单位的上边与障碍物的下边进行判定
					{
						if (
							//(
							//	((unit->x + 0.5 * UNIT_SIZE_X >= x - 32) && (unit->x + 0.5 * UNIT_SIZE_X <= x + 32)) ||
							//	((unit->x - 0.5 * UNIT_SIZE_X >= x - 32) && (unit->x - 0.5 * UNIT_SIZE_X <= x + 32)) ||
							//	((unit->x - 0.5 * UNIT_SIZE_X <= x - 32) && (unit->x + 0.5 * UNIT_SIZE_X > +x + 32))
							//	) &&
							//(unit->y - 0.5 * UNIT_SIZE_Y <= y + 32)
							(unit->x>=x-35)&&(unit->x<=x+35)&& (unit->y  <= y+24) && (unit->y >= y - 24)
							)
						{
							return 1;
						}
				
					}
					if (unit->direction == UNIT_DIRECT_DOWN)
					{
						if ((unit->x >= x - 30) && (unit->x <= x + 30) && (unit->y + 0.5 * UNIT_SIZE_Y >= y-40) && (unit->y + 0.5 * UNIT_SIZE_Y <= y + 40))
						{
							return 2;
						}
					}
				}
			}
		}
	}
	return 0;


}

void check_togo(HWND hWnd, int(*map)[16])
{
	int done1 = 0;
	int done2 = 0;
	int done3 = 0;
	int done4 = 0;

	Unit* unit = units[1];
	for (int j = 0; j < 12; j++)
	{
		for (int k = 0; k < 16; k++)
		{
			if (*(map[j] + k) == 1 || *(map[j] + k) == 2)
			{
				int x = k * 64 + 32;
				int y = j * 64 + 32;
				if ((unit->x - 0.5 * UNIT_SIZE_X >= x - 35) && (unit->x - 0.5 * UNIT_SIZE_X <= x + 35) && (unit->y + 0.5 * UNIT_SIZE_Y >= y - 35) && (unit->y + 0.5 * UNIT_SIZE_Y <= y + 35))
				{
					AI_toleft = false;
					done1 = 1;
					break;
				}
				else
				{
					AI_toleft = true;
				}
			}
		}
		if (done1 == 1)
		{
			break;
		}
	}
	for (int j = 0; j < 12; j++)
	{
		for (int k = 0; k < 16; k++)
		{
			if (*(map[j] + k) == 1 || *(map[j] + k) == 2)
			{
				int x = k * 64 + 32;
				int y = j * 64 + 32;
				if ((unit->x + 0.5 * UNIT_SIZE_X <= x + 32) && (unit->x + 0.5 * UNIT_SIZE_X >= x - 32) && (unit->y + 0.5 * UNIT_SIZE_Y >= y - 32) && (unit->y + 0.5 * UNIT_SIZE_Y <= y + 32))
				{
					AI_toright = false;
					done2 = 1;
					break;
				}
				else
				{
					AI_toright = true;
				}
			}
		}
		if(done2==1)
		{
			break;
		}
	}
	for (int j = 0; j < 12; j++)
	{
		for (int k = 0; k < 16; k++)
		{
			if (*(map[j] + k) == 1 || *(map[j] + k) == 2)
			{
				int x = k * 64 + 32;
				int y = j * 64 + 32;
				if (
					(unit->x >= x - 35) && (unit->x <= x + 35) && (unit->y <= y + 24) && (unit->y >= y - 24)
					)
				{
					AI_toup = false;
					done3 = 1;
					break;
				}
				else
				{

					AI_toup = true;
				}
			}
		}
		if (done3 == 1)
		{
			break;
		}
	}
	for (int j = 0; j < 12; j++)
	{
		for (int k = 0; k < 16; k++)
		{
			if (*(map[j] + k) == 1 || *(map[j] + k) == 2)
			{
				int x = k * 64 + 32;
				int y = j * 64 + 32;
				if ((unit->x >= x - 30) && (unit->x <= x + 30) && (unit->y + 0.5 * UNIT_SIZE_Y >= y - 40) && (unit->y + 0.5 * UNIT_SIZE_Y <= y + 40))
				{
					AI_todown = false;
					done4 = 1;
					break;
				}
				else
				{
					AI_todown = true;
				}
			}
		}
		if (done4 == 1)
		{
			break;
		}
	}

}

int Check_UnitRival_Block(HWND hWnd, int(*map)[16])
{
	//考虑把脚下的坐标分为三个
	//分别用1，2，3，4代表上下左右四个方向被阻挡，若没有方向被阻挡则返回0
	{
		Unit* unit = units[1];
		for (int j = 0; j < 12; j++)
		{
			for (int k = 0; k < 16; k++)
			{
				if (*(map[j] + k) == 1 || *(map[j] + k) == 2)
				{
					int x = k * 64 + 32;
					int y = j * 64 + 32;
					
					if (unit->direction == UNIT_DIRECT_LEFT)//第一种情况是单位向左走，单位的左边与障碍物的右边进行判定
					{
						if ((unit->x - 0.5 * UNIT_SIZE_X >= x - 35)&&(unit->x - 0.5 * UNIT_SIZE_X <= x + 35) && (unit->y + 0.5 * UNIT_SIZE_Y >= y - 35) && (unit->y + 0.5 * UNIT_SIZE_Y <= y + 35))
						{

							return 3;
						}

					}
					if (unit->direction == UNIT_DIRECT_RIGHT)//第二种情况是单位向右走，单位的右边与障碍物的左边进行判定
					{
						if ((unit->x + 0.5 * UNIT_SIZE_X <= x + 32)&&(unit->x + 0.5 * UNIT_SIZE_X >= x - 32) && (unit->y + 0.5 * UNIT_SIZE_Y >= y - 32) && (unit->y + 0.5 * UNIT_SIZE_Y <= y + 32))
						{
	
							return 4;
						}
						
					}
					if (unit->direction == UNIT_DIRECT_UP)//第三种情况是单位向上走，单位的上边与障碍物的下边进行判定
					{
						if (
							//(
							//	((unit->x + 0.5 * UNIT_SIZE_X >= x - 32) && (unit->x + 0.5 * UNIT_SIZE_X <= x + 32)) ||
							//	((unit->x - 0.5 * UNIT_SIZE_X >= x - 32) && (unit->x - 0.5 * UNIT_SIZE_X <= x + 32)) ||
							//	((unit->x - 0.5 * UNIT_SIZE_X <= x - 32) && (unit->x + 0.5 * UNIT_SIZE_X > +x + 32))
							//	) &&
							//(unit->y - 0.5 * UNIT_SIZE_Y <= y + 32)
							(unit->x >= x - 35) && (unit->x <= x + 35) && (unit->y <= y + 24) && (unit->y >= y - 24)
							)
						{
							
							return 1;
						}
					
					}
					if (unit->direction == UNIT_DIRECT_DOWN)
					{
						if ((unit->x >= x - 30) && (unit->x <= x + 30) && (unit->y + 0.5 * UNIT_SIZE_Y >= y - 40) && (unit->y + 0.5 * UNIT_SIZE_Y <= y + 40))
						{
							return 2;
						}
					
					}
				}
			}
		}
	}
	return 0;


}

bool CheckUnitBlood(HWND hWNd)
{

	
		Unit* unit0 = units[0];
		Unit* unit1 = units[1];
		if (unit0->health == 0)
		{
			return 0;//自己死亡，游戏失败
		}
		if (unit0->health == 0)
		{
			return 1;//win
		}
	
}

void Count_Down_Timer()
{
	if (currentStage->timeCountDown >= -100 && currentStage->timerOn)//防止在非游戏场景刷新出游戏超时菜单
	{
		currentStage->timeCountDown -= 30;//每次刷新间隔为30毫秒，故每次执行函数的时候减少30毫秒的倒计时
	}
}

// 绘图函数
void Paint(HWND hWnd)
{

	PAINTSTRUCT ps;
	HDC hdc_window = BeginPaint(hWnd, &ps);

	HDC hdc_memBuffer = CreateCompatibleDC(hdc_window);
	HDC hdc_loadBmp = CreateCompatibleDC(hdc_window);

	//初始化缓存
	HBITMAP	blankBmp = CreateCompatibleBitmap(hdc_window, WINDOW_WIDTH, WINDOW_HEIGHT);
	SelectObject(hdc_memBuffer, blankBmp);

	// 绘制背景到缓存
	//SelectObject(hdc_loadBmp, currentStage->bg);
	SelectObject(hdc_loadBmp, bmp_Background);

	BitBlt(hdc_memBuffer, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, hdc_loadBmp, 0, 0, SRCCOPY);

	// 按场景分类绘制内容到缓存
	if (currentStage->stageID == STAGE_STARTMENU) {

	}
	else if (currentStage->stageID >= STAGE_1 && currentStage->stageID <= STAGE_8) //TODO：添加多个游戏场景
	{
		//绘制地图
		//注意到是每一帧都在重新绘图，所以破坏方块的操作就可以直接转化为改变map数组内的数值//可以考虑对被破坏的场景进行特殊处理
		for (int i = 0; i < sizeof(map) / sizeof(map[0]); i++) {
			for (int j = 0; j < sizeof(map[0]) / sizeof(map[0][0]); j++) {
				SelectObject(hdc_loadBmp, bmp_block);
				TransparentBlt(
					hdc_memBuffer,
					j * BG_CELL_WIDTH, i * BG_CELL_HEIGHT,					// 界面上起始绘制点
					BG_CELL_WIDTH, BG_CELL_HEIGHT,											// 界面上绘制宽度高度
					hdc_loadBmp,
					map[i][j] * BLOCK_BITMAP_SIZE_X, 0,										// 位图上起始绘制点//确定是哪个图像
					BLOCK_BITMAP_SIZE_X, BLOCK_BITMAP_SIZE_Y,								// 位图上绘制宽度高度
					RGB(255, 255, 255));
			}
		}
		//绘制泡泡
		for (int i = 0; i < bubbles.size(); i++) {
			Bubble* bubble = bubbles[i];
			SelectObject(hdc_loadBmp, bubble->img);
			if (bubble->count_down_duration >= 0)
			{
				TransparentBlt(
					hdc_memBuffer,
					bubble->x - 0.5 * BUBBLE_SIZE_X, bubble->y - 0.5 * BUBBLE_SIZE_Y,		// 界面上起始绘制点
					BUBBLE_SIZE_X, BUBBLE_SIZE_Y,											// 界面上绘制宽度高度
					hdc_loadBmp,
					bubble->frame_colume * BUBBLE_BITMAP_SIZE_X, 0,							// 位图上起始绘制点
					BUBBLE_BITMAP_SIZE_X, BUBBLE_BITMAP_SIZE_Y,								// 位图上绘制宽度高度
					RGB(255, 255, 255));
			}
		}
		//绘制冲击波
		for (int i = 0; i < booms.size(); i++) {
			Boom* boom = booms[i];
			if (boom->count_down_duration >= 0)
			if (boom->count_down_duration >= 0)
			{
				if (boom->owner == 0)
				{


					if (boom->localtion == 1)
					{
						SelectObject(hdc_loadBmp, bmp_Bubble_Boom);
						TransparentBlt(
							hdc_memBuffer,
							boom->x - 0.5 * BUBBLE_SIZE_X, boom->y - 0.5 * BUBBLE_SIZE_Y,		// 界面上起始绘制点
							BUBBLE_SIZE_X, BUBBLE_SIZE_Y,											// 界面上绘制宽度高度
							hdc_loadBmp,
							0, 0,							// 位图上起始绘制点
							BUBBLE_BITMAP_SIZE_X, BUBBLE_BITMAP_SIZE_Y,								// 位图上绘制宽度高度
							RGB(255, 255, 255));
					}
					if (boom->localtion == 0)
					{
						SelectObject(hdc_loadBmp, bmp_Bubble_Boom2);
						TransparentBlt(
							hdc_memBuffer,
							boom->x - 0.5 * BUBBLE_SIZE_X, boom->y - 0.5 * BUBBLE_SIZE_Y,		// 界面上起始绘制点
							BUBBLE_SIZE_X, BUBBLE_SIZE_Y,											// 界面上绘制宽度高度
							hdc_loadBmp,
							0, 0,							// 位图上起始绘制点
							BUBBLE_BITMAP_SIZE_X, BUBBLE_BITMAP_SIZE_Y,								// 位图上绘制宽度高度
							RGB(255, 255, 255));
					}
				}
				else if (boom->owner == 1)
				{
					if (boom->localtion == 1)
					{
						SelectObject(hdc_loadBmp, bmp_boom_rival);
						TransparentBlt(
							hdc_memBuffer,
							boom->x - 0.5 * BUBBLE_SIZE_X, boom->y - 0.5 * BUBBLE_SIZE_Y,		// 界面上起始绘制点
							BUBBLE_SIZE_X, BUBBLE_SIZE_Y,											// 界面上绘制宽度高度
							hdc_loadBmp,
							0, 0,							// 位图上起始绘制点
							BUBBLE_BITMAP_SIZE_X, BUBBLE_BITMAP_SIZE_Y,								// 位图上绘制宽度高度
							RGB(255, 255, 255));
					}
					if (boom->localtion == 0)
					{
						SelectObject(hdc_loadBmp, bmp_boom2_rival);
						TransparentBlt(
							hdc_memBuffer,
							boom->x - 0.5 * BUBBLE_SIZE_X, boom->y - 0.5 * BUBBLE_SIZE_Y,		// 界面上起始绘制点
							BUBBLE_SIZE_X, BUBBLE_SIZE_Y,											// 界面上绘制宽度高度
							hdc_loadBmp,
							0, 0,							// 位图上起始绘制点
							BUBBLE_BITMAP_SIZE_X, BUBBLE_BITMAP_SIZE_Y,								// 位图上绘制宽度高度
							RGB(255, 255, 255));
					}
				}
				else
				{
					if (boom->localtion == 1)
					{
						SelectObject(hdc_loadBmp, bmp_boom_stage);
						TransparentBlt(
							hdc_memBuffer,
							boom->x - 0.5 * BUBBLE_SIZE_X, boom->y - 0.5 * BUBBLE_SIZE_Y,		// 界面上起始绘制点
							BUBBLE_SIZE_X, BUBBLE_SIZE_Y,											// 界面上绘制宽度高度
							hdc_loadBmp,
							0, 0,							// 位图上起始绘制点
							BUBBLE_BITMAP_SIZE_X, BUBBLE_BITMAP_SIZE_Y,								// 位图上绘制宽度高度
							RGB(255, 255, 255));
					}
					if (boom->localtion == 0)
					{
						SelectObject(hdc_loadBmp, bmp_boom2_stage);
						TransparentBlt(
							hdc_memBuffer,
							boom->x - 0.5 * BUBBLE_SIZE_X, boom->y - 0.5 * BUBBLE_SIZE_Y,		// 界面上起始绘制点
							BUBBLE_SIZE_X, BUBBLE_SIZE_Y,											// 界面上绘制宽度高度
							hdc_loadBmp,
							0, 0,							// 位图上起始绘制点
							BUBBLE_BITMAP_SIZE_X, BUBBLE_BITMAP_SIZE_Y,								// 位图上绘制宽度高度
							RGB(255, 255, 255));
					}
				}

				if (pause_t == 0)
				{
					boom->count_down_duration -= 20;
					if (boom->count_down_duration <= -100)
					{
						boom->count_down_duration = -100;//
					}
				}
				//此时代表着冲击波结束
			}
		}



		//绘制道具
		for (int i = 0; i < Cbs.size(); i++)
		{
			Cartridge_Bag* cb = Cbs[i];
			if (cb->used == false)
			{
				SelectObject(hdc_loadBmp, cb->img);
				TransparentBlt(
					hdc_memBuffer,
					cb->x - 32, cb->y - 32,
					64, 64,
					hdc_loadBmp,
					(cb->frame_id / 8) * 64, 0,								// 位图上起始绘制点//确定是哪个图像
					64, 64,											// 位图上绘制宽度高度
					RGB(255, 255, 255)
				);
			}

		}
		// 绘制人物
		//从这一行可以看出这个是用来专门在有游戏内绘图的，以后的绘图也要在这里绘制
		for (int i = 0; i < units.size(); i++) {
			Unit* unit = units[i];
			SelectObject(hdc_loadBmp, unit->img);
			TransparentBlt(
				hdc_memBuffer,
				unit->x - 0.5 * UNIT_SIZE_X, unit->y - 0.5 * UNIT_SIZE_Y,			// 界面上起始绘制点
				UNIT_SIZE_X, UNIT_SIZE_Y,											// 界面上绘制宽度高度
				hdc_loadBmp,
				UNIT_BITMAP_SIZE_X * unit->frame_column, UNIT_BITMAP_SIZE_Y * unit->frame_row,	// 位图上起始绘制点
				UNIT_BITMAP_SIZE_X, UNIT_BITMAP_SIZE_Y,											// 位图上绘制宽度高度
				RGB(255, 255, 255)
			);
		}


		//绘制倒计时
		{
			//获取当下剩余的秒数
			//最大秒数应当小于等于999秒，也就是999000毫秒
			int current_time;
			if (currentStage->timeCountDown % 1000 == 0)
			{
				current_time = currentStage->timeCountDown / 1000;
			}
			else
			{
				current_time = currentStage->timeCountDown / 1000 + 1;
			}
			//获取三个位置的时间
			int third_time = current_time % 10;
			current_time = current_time / 10;
			int second_time = current_time % 10;
			current_time = current_time / 10;
			int first_time = current_time % 10;
			SelectObject(hdc_loadBmp, bmp_Numbers);
			TransparentBlt(
				hdc_memBuffer,
				408, 0,
				48, 48,
				hdc_loadBmp,
				first_time * 48, 0,								// 位图上起始绘制点//确定是哪个图像
				48, 48,								// 位图上绘制宽度高度
				RGB(255, 255, 255)
			);
			TransparentBlt(
				hdc_memBuffer,
				456, 0,
				48, 48,
				hdc_loadBmp,
				second_time * 48, 0,								// 位图上起始绘制点//确定是哪个图像
				48, 48,								// 位图上绘制宽度高度
				RGB(255, 255, 255)
			);
			if (currentStage->timeCountDown <= 0)
			{
				TransparentBlt(
					hdc_memBuffer,
					504, 0,
					48, 48,
					hdc_loadBmp,
					0, 0,								// 位图上起始绘制点//确定是哪个图像
					48, 48,								// 位图上绘制宽度高度
					RGB(255, 255, 255)
				);
			}
			else
			{
				TransparentBlt(
					hdc_memBuffer,
					504, 0,
					48, 48,
					hdc_loadBmp,
					third_time * 48, 0,								// 位图上起始绘制点//确定是哪个图像
					48, 48,								// 位图上绘制宽度高度
					RGB(255, 255, 255)
				);
			}
		}
		//绘制人物图像和血条和能量条
		{
			if (currentStage->timeCountDown != -200)//确保是在游戏场景而不是其他的东西
			{
				SelectObject(hdc_loadBmp, bmp_Head_Me);
				TransparentBlt(
					hdc_memBuffer,
					0, 0,
					48, 40,
					hdc_loadBmp,
					0, 0,								// 位图上起始绘制点//确定是哪个图像
					48, 40,								// 位图上绘制宽度高度
					RGB(255, 255, 255)
				);
				SelectObject(hdc_loadBmp, bmp_Head_Rival);
				TransparentBlt(
					hdc_memBuffer,
					964, 0,
					48, 40,
					hdc_loadBmp,
					0, 0,								// 位图上起始绘制点//确定是哪个图像
					48, 40,								// 位图上绘制宽度高度
					RGB(255, 255, 255)
				);
				int my_blood = units[0]->health / 20;
				SelectObject(hdc_loadBmp, bmp_Blood);
				TransparentBlt(
					hdc_memBuffer,
					56, 8,
					my_blood*64, 24,
					hdc_loadBmp,
					0, 0,								// 位图上起始绘制点//确定是哪个图像
					my_blood*64, 24,								// 位图上绘制宽度高度
					RGB(255, 255, 255)
				);
				int rival_blood = units[1]->health / 20;
				SelectObject(hdc_loadBmp, bmp_Blood);
				TransparentBlt(
					hdc_memBuffer,
					636+(5-rival_blood)*64, 8,
					rival_blood * 64, 24,
					hdc_loadBmp,
					0, 0,								// 位图上起始绘制点//确定是哪个图像
					rival_blood * 64, 24,								// 位图上绘制宽度高度
					RGB(255, 255, 255)
				);
				//绘制玩家的能量条
				SelectObject(hdc_loadBmp, bmp_energy_bar);

				int long_bar = units[0]->skill_energy / 10;

				TransparentBlt(
					hdc_memBuffer,
					56, 36,
					long_bar, 8,
					hdc_loadBmp,
					0, 0,								// 位图上起始绘制点//确定是哪个图像
					long_bar, 8,								// 位图上绘制宽度高度
					RGB(255, 255, 255)
				);
				//绘制AI的能量条
				SelectObject(hdc_loadBmp, bmp_energy_bar);

				int rival_long_bar = units[1]->skill_energy / 10;

				TransparentBlt(
					hdc_memBuffer,
					636+(320-rival_long_bar),36,
					rival_long_bar, 8,
					hdc_loadBmp,
					0, 0,								// 位图上起始绘制点//确定是哪个图像
					rival_long_bar, 8,								// 位图上绘制宽度高度
					RGB(255, 255, 255)
				);
			}
		}

		//绘制状态栏
		{
			
			//绘制炸弹状态
			{
				if (units[0]->max_bubble >= 2)
				{
					SelectObject(hdc_loadBmp, bmp_pre_cb);
					TransparentBlt(

						hdc_memBuffer,
						0, 50,
						48, 48,
						hdc_loadBmp,
						0, 0,								// 位图上起始绘制点//确定是哪个图像
						48, 48,								// 位图上绘制宽度高度
						RGB(255, 255, 255)
					);
				}
				if (units[1]->max_bubble >= 2)
				{
					SelectObject(hdc_loadBmp, bmp_pre_cb);
					TransparentBlt(

						hdc_memBuffer,
						964, 50,
						48, 48,
						hdc_loadBmp,
						0, 0,								// 位图上起始绘制点//确定是哪个图像
						48, 48,								// 位图上绘制宽度高度
						RGB(255, 255, 255)
					);
				}
			}
			//绘制速度状态
			{
				if (me_has_speed_liquid == true)
				{
					SelectObject(hdc_loadBmp, bmp_pre_speed);
					TransparentBlt(

						hdc_memBuffer,
						0, 98,
						48, 48,
						hdc_loadBmp,
						0, 0,								// 位图上起始绘制点//确定是哪个图像
						48, 48,								// 位图上绘制宽度高度
						RGB(255, 255, 255)
					);
				}
				if (rival_has_speed_liquid == true)
				{
					SelectObject(hdc_loadBmp, bmp_pre_speed);
					TransparentBlt(

						hdc_memBuffer,
						964, 98,
						48, 48,
						hdc_loadBmp,
						0, 0,								// 位图上起始绘制点//确定是哪个图像
						48, 48,								// 位图上绘制宽度高度
						RGB(255, 255, 255)
					);
				}
			}
			//绘制力量状态
			{
				if (units[0]->boom_range > 2)
				{
					SelectObject(hdc_loadBmp, bmp_pre_power);
					TransparentBlt(

						hdc_memBuffer,
						0, 146,
						48, 48,
						hdc_loadBmp,
						0, 0,								// 位图上起始绘制点//确定是哪个图像
						48, 48,								// 位图上绘制宽度高度
						RGB(255, 255, 255)
					);
				}
				if (units[1]->boom_range >2)
				{
					SelectObject(hdc_loadBmp, bmp_pre_power);
					TransparentBlt(

						hdc_memBuffer,
						964, 146,
						48, 48,
						hdc_loadBmp,
						0, 0,								// 位图上起始绘制点//确定是哪个图像
						48, 48,								// 位图上绘制宽度高度
						RGB(255, 255, 255)
					);
				}

			}
			//绘制不死图腾状态
			{
				if (me_has_undead == true)
				{
					SelectObject(hdc_loadBmp, bmp_pre_undead);
					TransparentBlt(

						hdc_memBuffer,
						0, 194,
						48, 48,
						hdc_loadBmp,
						0, 0,								// 位图上起始绘制点//确定是哪个图像
						48, 48,								// 位图上绘制宽度高度
						RGB(255, 255, 255)
					);
				}
				if (rival_has_undead == true)
				{
					SelectObject(hdc_loadBmp, bmp_pre_undead);
					TransparentBlt(

						hdc_memBuffer,
						964, 194,
						48, 48,
						hdc_loadBmp,
						0, 0,								// 位图上起始绘制点//确定是哪个图像
						48, 48,								// 位图上绘制宽度高度
						RGB(255, 255, 255)
					);
				}
			}
			//绘制变身道具状态
			{
				if (me_has_bs == true)
				{
					SelectObject(hdc_loadBmp, bmp_pre_bs);
					TransparentBlt(

						hdc_memBuffer,
						0, 242,
						48, 48,
						hdc_loadBmp,
						0, 0,								// 位图上起始绘制点//确定是哪个图像
						48, 48,								// 位图上绘制宽度高度
						RGB(255, 255, 255)
					);
				}
				if (rival_has_bs == true)
				{
					SelectObject(hdc_loadBmp, bmp_pre_bs);
					TransparentBlt(

						hdc_memBuffer,
						964, 242,
						48, 48,
						hdc_loadBmp,
						0, 0,								// 位图上起始绘制点//确定是哪个图像
						48, 48,								// 位图上绘制宽度高度
						RGB(255, 255, 255)
					);
				}
			}
			//绘制换血沙漏状态
			{
				if (units[0]->has_switch_blood == true)
				{
					SelectObject(hdc_loadBmp, bmp_pre_switch);
					TransparentBlt(

						hdc_memBuffer,
						0, 290,
						48, 48,
						hdc_loadBmp,
						0, 0,								// 位图上起始绘制点//确定是哪个图像
						48, 48,								// 位图上绘制宽度高度
						RGB(255, 255, 255)
					);
				}
				if (units[1]->has_switch_blood == true)
				{
					SelectObject(hdc_loadBmp, bmp_pre_switch);
					TransparentBlt(

						hdc_memBuffer,
						964, 290,
						48, 48,
						hdc_loadBmp,
						0, 0,								// 位图上起始绘制点//确定是哪个图像
						48, 48,								// 位图上绘制宽度高度
						RGB(255, 255, 255)
					);
				}
			}
		}




		//绘制不死图腾破碎画面
		if (last_time_bu>0)
		{
			SelectObject(hdc_loadBmp, bmp_broken_undead);
			TransparentBlt(
				hdc_memBuffer,
				272, 112,
				480, 480,
				hdc_loadBmp,
				0, 0,								// 位图上起始绘制点//确定是哪个图像
				480, 480,								// 位图上绘制宽度高度
				RGB(255, 255, 255)
			);
			if (last_time_bu > 0)
			{
				last_time_bu -= 30;
			}
		}
		//绘制变身道具破碎画面
		if (last_time_skill > 0)
		{
			SelectObject(hdc_loadBmp, bmp_broken_skill);
			TransparentBlt(
				hdc_memBuffer,
				272, 112,
				480, 480,
				hdc_loadBmp,
				0, 0,								// 位图上起始绘制点//确定是哪个图像
				480, 480,								// 位图上绘制宽度高度
				RGB(255, 255, 255)
			);
			if (last_time_skill > 0)
			{
				last_time_skill -= 30;
			}
		}
		//绘制换血道具吟唱画面
		if (switch_blood_timer != 0)
		{
			int location = 0;
			//确定绘制位图时x的坐标
			if (switch_blood_timer > 0 && switch_blood_timer <= 300)
			{
				location = 0;
			}
			else if (switch_blood_timer > 300 && switch_blood_timer <= 600)
			{
				location = 480;
			}
			else if (switch_blood_timer > 600 && switch_blood_timer <= 900)
			{
				location = 960;
			}
			else if (switch_blood_timer > 900 && switch_blood_timer <= 1200)
			{
				location = 1440;
			}
			else if (switch_blood_timer > 1200 && switch_blood_timer <= 1500)
			{
				location = 1920;
			}
			SelectObject(hdc_loadBmp, bmp_using_switch_blood);
			TransparentBlt(
				hdc_memBuffer,
				272, 112,
				480, 480,
				hdc_loadBmp,
				location, 0,								// 位图上起始绘制点//确定是哪个图像
				480, 480,								// 位图上绘制宽度高度
				RGB(255, 255, 255)
			);
			if (switch_blood_timer >= 1500)
			{
				switch_blood_timer = 0;
				start_switch_blood_timer = false;
				//开始进行换血操作
				if (units[0]->has_switch_blood == true)
				{
					int temp = units[1]->health;
					units[1]->health = units[0]->health;
					units[0]->health = temp;
					units[0]->has_switch_blood = false;
				}
				else
				{
					int temp = units[1]->health;
					units[1]->health = units[0]->health;
					units[0]->health = temp;
					units[1]->has_switch_blood = false;
				}

			}
		}
		if (start_warning == true && have_warned == false)
		{
			int location = 0;
			//确定绘制位图时x的坐标
			if (warning_timer > 0 && warning_timer <= 600)
			{
				location = 0;
			}
			else if (warning_timer > 600 && warning_timer <= 1200)
			{
				location = 480;
			}
			else if (warning_timer > 1200 && warning_timer <= 1800)
			{
				location = 960;
			}
			else if (warning_timer > 1800 && warning_timer <= 2400)
			{
				location = 1440;
			}
			else if (warning_timer > 2400 && warning_timer <= 3000)
			{
				location = 1920;
			}
			SelectObject(hdc_loadBmp, bmp_warnings);
			TransparentBlt(
				hdc_memBuffer,
				272, 112,
				480, 480,
				hdc_loadBmp,
				location, 0,								// 位图上起始绘制点//确定是哪个图像
				480, 480,								// 位图上绘制宽度高度
				RGB(255, 255, 255)
			);
			if (pause_t == 0)
			{
				warning_timer += 30;
			}
			if (warning_timer >= 3000)
			{
				warning_timer = 0;
				have_warned = true;
			}
		}


		//绘制游戏失败页面
		Unit* unit0 = units[0];
		if (unit0->health <= 0)//输了的话绘制图片
		{
			SelectObject(hdc_loadBmp, bmp_Lost_Menu);
			TransparentBlt(
				hdc_memBuffer,
				272, 112,
				480, 480,
				hdc_loadBmp,
				0, 0,								// 位图上起始绘制点//确定是哪个图像
				480, 480,								// 位图上绘制宽度高度
				RGB(255, 255, 255)
			);
		}

		//绘制游戏成功页面
		Unit* unit1 = units[1];
		if (unit1->health <= 0)//输了的话绘制图片//成功绘制
		{
			SelectObject(hdc_loadBmp, bmp_win_menu);
			TransparentBlt(
				hdc_memBuffer,
				272, 112,
				480, 480,
				hdc_loadBmp,
				0, 0,								// 位图上起始绘制点//确定是哪个图像
				480, 480,								// 位图上绘制宽度高度
				RGB(255, 255, 255)
			);
		}
		//绘制倒计时结束页面
		if (currentStage->timeCountDown <= -10 && currentStage->timeCountDown >= -100)//一个判断是否到时间，一个判断是否不是游戏场景
		{
			currentStage->timerOn = false;
			SelectObject(hdc_loadBmp, bmp_equal_menu);
			TransparentBlt(
				hdc_memBuffer,
				272, 112,
				480, 480,
				hdc_loadBmp,
				0, 0,								// 位图上起始绘制点//确定是哪个图像
				480, 480,								// 位图上绘制宽度高度
				RGB(255, 255, 255)
			);
			for (int j = 0; j < buttons.size(); j++)
			{
				Button* button = buttons[j];
				if (button->buttonID == BUTTON_RESTART || button->buttonID == BUTTON_TOMENU)
				{
					button->visible = true;
				}

			}
		}
		



	}



	// 绘制按钮到缓存
	
	for (int i = 0; i < buttons.size(); i++)
	{
		Button* button = buttons[i];
		if (button->visible)
		{
			SelectObject(hdc_loadBmp, button->img);
			TransparentBlt(
				hdc_memBuffer, button->x, button->y,
				button->width, button->height,
				hdc_loadBmp, 0, 0, button->width, button->height,
				RGB(255, 255, 255)
			);
		}
	}
	


	// 最后将所有的信息绘制到屏幕上
	BitBlt(hdc_window, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, hdc_memBuffer, 0, 0, SRCCOPY);

	// 回收资源所占的内存（非常重要）
	DeleteObject(blankBmp);
	DeleteDC(hdc_memBuffer);
	DeleteDC(hdc_loadBmp);

	// 结束绘制
	EndPaint(hWnd, &ps);
}
// 初始化背景函数
HBITMAP InitBackGround(HWND hWnd, HBITMAP bmp_src) {

	srand(time(NULL));
	PAINTSTRUCT ps;
	HDC hdc_window = BeginPaint(hWnd, &ps);

	HDC hdc_memBuffer = CreateCompatibleDC(hdc_window);
	HDC hdc_loadBmp = CreateCompatibleDC(hdc_window);

	//初始化缓存
	HBITMAP	bmp_output = CreateCompatibleBitmap(hdc_window, WINDOW_WIDTH, WINDOW_HEIGHT);
	SelectObject(hdc_memBuffer, bmp_output);

	//加载资源
	SelectObject(hdc_loadBmp, bmp_src);


	for (int i = 0; i < BG_ROWS; i++) {

		int src_row = 1;
		if (i >= BG_ROWS_SKY)
			src_row = 0;

		for (int j = 0; j < BG_COLUMNS; j++) {
			int src_column = rand() % BG_SRC_COUNT;

			TransparentBlt(
				hdc_memBuffer,
				j * BG_CELL_WIDTH, i * BG_CELL_HEIGHT,
				BG_CELL_WIDTH, BG_CELL_HEIGHT,
				hdc_loadBmp, 
				src_column * BG_CELL_WIDTH, src_row * BG_CELL_HEIGHT,
				BG_CELL_WIDTH, BG_CELL_HEIGHT,
				RGB(255, 255, 255)
			);

		}
	}

	// 最后将所有的信息绘制到屏幕上
	BitBlt(hdc_window, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, hdc_memBuffer, 0, 0, SRCCOPY);

	// 回收资源所占的内存（非常重要）
	DeleteDC(hdc_memBuffer);
	DeleteDC(hdc_loadBmp);

	// 结束绘制
	EndPaint(hWnd, &ps);

	return bmp_output;
}

HBITMAP InitMenuBackGround(HWND hWnd, HBITMAP bmp_src) {

	srand(time(NULL));
	PAINTSTRUCT ps;
	HDC hdc_window = BeginPaint(hWnd, &ps);

	HDC hdc_memBuffer = CreateCompatibleDC(hdc_window);
	HDC hdc_loadBmp = CreateCompatibleDC(hdc_window);

	//初始化缓存
	HBITMAP	bmp_output = CreateCompatibleBitmap(hdc_window, WINDOW_WIDTH, WINDOW_HEIGHT);
	SelectObject(hdc_memBuffer, bmp_output);

	//加载资源
	SelectObject(hdc_loadBmp, bmp_src);

			TransparentBlt
			(
				hdc_memBuffer,
				0, 0,
				1023, 766,
				hdc_loadBmp,
				0, 0,
				1023, 766,
				RGB(255, 255, 255)
			);

		
	

	// 最后将所有的信息绘制到屏幕上
	BitBlt(hdc_window, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, hdc_memBuffer, 0, 0, SRCCOPY);

	// 回收资源所占的内存（非常重要）
	DeleteDC(hdc_memBuffer);
	DeleteDC(hdc_loadBmp);

	// 结束绘制
	EndPaint(hWnd, &ps);

	return bmp_output;
}
