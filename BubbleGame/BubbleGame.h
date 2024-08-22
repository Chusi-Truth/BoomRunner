#pragma once

#pragma region 头文件引用

// Windows 头文件: 
#include <windows.h>

// C 运行时头文件
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <time.h>
#include <vector>
#include <math.h>


// 资源头文件
#include "resource.h"
#pragma comment(lib, "Msimg32.lib")			//图象处理的函数接口，例如：透明色的位图的绘制TransparentBlt函数


#pragma endregion


#pragma region 宏定义

#define WINDOW_TITLEBARHEIGHT	32			//标题栏高度
#define WINDOW_WIDTH			1024		//游戏窗口宽度
#define WINDOW_HEIGHT			768			//游戏窗口高度


#define STAGE_STARTMENU			0		//开始画面的ID
#define STAGE_HELP				1		//帮助菜单场景的ID
#define STAGE_CHOOSE			2		//选择关卡场景的ID
#define STAGE_1					3		//第一个游戏场景的ID
#define STAGE_2					4	
#define STAGE_3					5	
#define STAGE_4					6	
#define STAGE_5					7	
#define STAGE_6					8	
#define STAGE_7					9	
#define STAGE_8					10	
#define STAGE_HELP2				11
#define STAGE_HELP3				12


#define UNIT_SIZE_X				72		//单位的宽度
#define UNIT_SIZE_Y				90		
#define UNIT_BITMAP_SIZE_X		48		//单位在位图上的宽度
#define UNIT_BITMAP_SIZE_Y		60		
#define BUBBLE_SIZE_X			60		//泡泡
#define BUBBLE_SIZE_Y			60		
#define BUBBLE_BITMAP_SIZE_X	46		
#define BUBBLE_BITMAP_SIZE_Y	46		
#define BLOCK_BITMAP_SIZE_X		40		//砖块在位图上的宽度
#define BLOCK_BITMAP_SIZE_Y		40

//单位阵营定义
#define UNIT_SIDE_ME			10000	//我方
#define UNIT_SIDE_RIVAL			10001	//对手


//单位状态定义
#define UNIT_STATE_HOLD			0		//静止
#define UNIT_STATE_WALK			1		//行走
#define UNIT_STATE_ATTACK		2		//攻击

//单位方向定义
#define UNIT_DIRECT_RIGHT		2		//向右
#define UNIT_DIRECT_LEFT		1		//向左
#define UNIT_DIRECT_UP			3		//向上
#define UNIT_DIRECT_DOWN		0		//向下


//背景
#define BG_SRC_COUNT			6		//背景资源数量
#define BG_COLUMNS				16		//背景列数
#define BG_ROWS					12		//背景行数
#define BG_ROWS_SKY				3		//背景天空行数
#define BG_ROWS_LAND			9		//背景地面行数
#define BG_CELL_WIDTH			64		//背景单格宽度
#define BG_CELL_HEIGHT			64		//背景单格高度

//其它定义
#define BUTTON_STARTGAME			1001	//开始游戏按钮ID
#define BUTTON_STARTGAME_WIDTH		212		//开始游戏按钮宽度
#define BUTTON_STARTGAME_HEIGHT		76		//开始游戏按钮高度
#define BUTTON_HELP					1002	//帮助菜单按钮ID
#define BUTTON_MENU					1003	//回到菜单按钮ID
#define BUTTON_FAKEMENU				1004	//假菜单按钮ID
#define BUTTON_RESTART				1005	//重新开始游戏按钮ID
#define BUTTON_TOMENU				1006	//回到主菜单按钮ID
#define BUTTON_BACKTOGAME			1007	//恢复游戏按钮ID
#define BUTTON_STAGE_1				1008
#define BUTTON_STAGE_2				1009
#define BUTTON_STAGE_3				1010
#define BUTTON_STAGE_4				1011
#define BUTTON_STAGE_5				1012
#define BUTTON_STAGE_6				1013
#define BUTTON_STAGE_7				1014
#define BUTTON_STAGE_8				1015
#define BUTTON_PAGE2TOPAGE1			1016
#define BUTTON_PAGE1TOPAGE2			1017
#define BUTTON_PAGE2TOPAGE3			1018
#define BUTTON_PAGE3TOPAGE2			1019
#define BUTTON_CHOOSE_BACK			1020
#define BUTTON_INTRODUCTION_BACK	1021

#define TIMER_GAMETIMER				1		//游戏的默认计时器ID
#define TIMER_GAMETIMER_ELAPSE		30		//默认计时器刷新间隔的毫秒数//很重要，涉及到计时器问题
#define UNIT_SPEED					3.0		//单位行走速度	


#pragma endregion


#pragma region 结构体声明

// 场景结构体
struct Stage
{
	int stageID;		//场景编号
	HBITMAP bg;			//背景图片
	int timeCountDown;	//游戏时间倒计时
	bool timerOn;		//计时器是否运行（游戏是否被暂停）

};


// 按钮结构体
struct Button
{
	int buttonID;	//按钮编号
	bool visible;	//按钮是否可见
	HBITMAP img;	//图片
	int x;			//坐标x
	int y;			//坐标y
	int width;		//宽度
	int height;		//高度
};

// 单位结构体
struct Unit
{
	HBITMAP img;	//图片

	int frame_row;			//当前显示的是图像的第几行
	int frame_column;		//当前显示的是图像的第几列

	int* frame_sequence;		//当前的帧序列
	int frame_count;		//帧序列的长度
	int frame_id;			//当前显示的是帧序列的第几个


	int side;		//单位阵营
	int state;		//单位状态
	int direction;	//单位方向

	int x;			//坐标x
	int y;			//坐标y
	double vx;		//速度x
	double vy;		//速度y
	int health;		//生命值
	int bubble_timer;	//放置炸弹的间隔
	int max_bubble;		//存储炸弹的最大数量
	int supertime;		//无敌时间
	int boom_range;		//爆炸范围
	int lifes;			//命数
	bool skill;			//是否拥有冲刺技能
	int skill_energy;	//冲刺技能能量条
	bool has_switch_blood;	//拥有换血技能
};

struct Bubble
{
	HBITMAP img;						//图片

	int x;								//坐标x
	int y;								//坐标y
	int owner;							//由谁放置的
	int count_down_duration;			//爆炸时长
	int range;							//爆炸半径
	int timer_id;						//定时器id
	int frame_id;
	int frame_colume;
};
struct Boom
{
	HBITMAP img;						//图片

	int x;								//坐标x
	int y;								//坐标y
	int owner;							//由谁放置的
	int count_down_duration;			//爆炸时长
	int localtion;						//爆炸的位置
};

struct Cartridge_Bag
{
	HBITMAP img;
	int x;								//坐标x
	int y;								//坐标y
	int frame_id;						//确定在第几帧，方便绘图
	int feature;						//确定这个道具的性质
	bool used;							//确定这个道具是否被使用过了


};




//TODO: 添加游戏需要的更多种数据（地物、砖块等）



#pragma endregion


#pragma region 事件处理函数声明


// 初始化游戏窗体函数
void InitGame(HWND hWnd, WPARAM wParam, LPARAM lParam);

// 键盘按下事件处理函数
void KeyDown(HWND hWnd, WPARAM wParam, LPARAM lParam);

// 键盘松开事件处理函数
void KeyUp(HWND hWnd, WPARAM wParam, LPARAM lParam);

// 鼠标移动事件处理函数
void MouseMove(HWND hWnd, WPARAM wParam, LPARAM lParam);

// 鼠标左键按下事件处理函数
void LButtonDown(HWND hWnd, WPARAM wParam, LPARAM lParam);

// 鼠标左键松开事件处理函数
void LButtonUp(HWND hWnd, WPARAM wParam, LPARAM lParam);

// 定时器事件处理函数
void TimerUpdate(HWND hWnd, WPARAM wParam, LPARAM lParam);

#pragma endregion


#pragma region 其它游戏状态处理函数声明

// 添加按钮函数
Button* CreateButton(int buttonID, HBITMAP img, int width, int height, int x, int y);

// 添加单位函数
Unit* CreateUnit(int side, int x, int y, int health);




// 初始化场景函数
void InitStage(HWND hWnd, int stageID);

// 刷新单位状态函数
void UpdateUnits(HWND hWnd);

//刷新道具状态函数
void UpdateItems(HWND hWnd);

//加快游戏进程函数
void quick_game(HWND hWnd, int(*map)[16]);



//单位行为函数
void UnitBehaviour_Me(HWND hWnd);
void UnitBehaviour_Rival(HWND hWnd);
void PlaceBubble(HWND hWnd, Unit* unit,int owner);
void UpdateBubbles(HWND hWnd);

//检测函数
void CheckBooms(HWND hWnd);							//检测人物和冲击波是否发生碰撞
bool CheckUnitBlood(HWND hWNd);						//检测人物血量是否归零
void Check_Boom_Block(HWND hwnd,int(*map)[16]);		//检测冲击波是否摧毁障碍物
int Check_UnitMe_Block(HWND hwnd, int(*map)[16]);	//检测人物是否碰到障碍物
int Check_UnitRival_Block(HWND hwnd, int(*map)[16]);
void Check_Unit_Item(HWND hWnd);
void check_togo(HWND hWnd, int(*map)[16]);
void skill(HWND hWnd);
void switch_blood(HWND hWnd);
void timer_switch_blood(HWND hWnd);
void stage_warnins(HWND hWnd);
//删除已经使用过的泡泡，冲击波以及炸弹
void delete_bubble_and_items(HWND hWnd);
//倒计时函数
void Count_Down_Timer();
//生成道具函数
void CreateSpecialItems(HWND hWnd,int(*map)[16]);
//TODO: 添加游戏需要的更多函数


#pragma endregion 


#pragma region 绘图函数声明

// 绘图函数
void Paint(HWND hWnd);

// 初始化背景函数
HBITMAP InitBackGround(HWND hWnd, HBITMAP bmp_src);
HBITMAP InitMenuBackGround(HWND hWnd, HBITMAP bmp_src);


#pragma endregion