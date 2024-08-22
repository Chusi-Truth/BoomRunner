#pragma once

#pragma region ͷ�ļ�����

// Windows ͷ�ļ�: 
#include <windows.h>

// C ����ʱͷ�ļ�
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <time.h>
#include <vector>
#include <math.h>


// ��Դͷ�ļ�
#include "resource.h"
#pragma comment(lib, "Msimg32.lib")			//ͼ����ĺ����ӿڣ����磺͸��ɫ��λͼ�Ļ���TransparentBlt����


#pragma endregion


#pragma region �궨��

#define WINDOW_TITLEBARHEIGHT	32			//�������߶�
#define WINDOW_WIDTH			1024		//��Ϸ���ڿ��
#define WINDOW_HEIGHT			768			//��Ϸ���ڸ߶�


#define STAGE_STARTMENU			0		//��ʼ�����ID
#define STAGE_HELP				1		//�����˵�������ID
#define STAGE_CHOOSE			2		//ѡ��ؿ�������ID
#define STAGE_1					3		//��һ����Ϸ������ID
#define STAGE_2					4	
#define STAGE_3					5	
#define STAGE_4					6	
#define STAGE_5					7	
#define STAGE_6					8	
#define STAGE_7					9	
#define STAGE_8					10	
#define STAGE_HELP2				11
#define STAGE_HELP3				12


#define UNIT_SIZE_X				72		//��λ�Ŀ��
#define UNIT_SIZE_Y				90		
#define UNIT_BITMAP_SIZE_X		48		//��λ��λͼ�ϵĿ��
#define UNIT_BITMAP_SIZE_Y		60		
#define BUBBLE_SIZE_X			60		//����
#define BUBBLE_SIZE_Y			60		
#define BUBBLE_BITMAP_SIZE_X	46		
#define BUBBLE_BITMAP_SIZE_Y	46		
#define BLOCK_BITMAP_SIZE_X		40		//ש����λͼ�ϵĿ��
#define BLOCK_BITMAP_SIZE_Y		40

//��λ��Ӫ����
#define UNIT_SIDE_ME			10000	//�ҷ�
#define UNIT_SIDE_RIVAL			10001	//����


//��λ״̬����
#define UNIT_STATE_HOLD			0		//��ֹ
#define UNIT_STATE_WALK			1		//����
#define UNIT_STATE_ATTACK		2		//����

//��λ������
#define UNIT_DIRECT_RIGHT		2		//����
#define UNIT_DIRECT_LEFT		1		//����
#define UNIT_DIRECT_UP			3		//����
#define UNIT_DIRECT_DOWN		0		//����


//����
#define BG_SRC_COUNT			6		//������Դ����
#define BG_COLUMNS				16		//��������
#define BG_ROWS					12		//��������
#define BG_ROWS_SKY				3		//�����������
#define BG_ROWS_LAND			9		//������������
#define BG_CELL_WIDTH			64		//����������
#define BG_CELL_HEIGHT			64		//��������߶�

//��������
#define BUTTON_STARTGAME			1001	//��ʼ��Ϸ��ťID
#define BUTTON_STARTGAME_WIDTH		212		//��ʼ��Ϸ��ť���
#define BUTTON_STARTGAME_HEIGHT		76		//��ʼ��Ϸ��ť�߶�
#define BUTTON_HELP					1002	//�����˵���ťID
#define BUTTON_MENU					1003	//�ص��˵���ťID
#define BUTTON_FAKEMENU				1004	//�ٲ˵���ťID
#define BUTTON_RESTART				1005	//���¿�ʼ��Ϸ��ťID
#define BUTTON_TOMENU				1006	//�ص����˵���ťID
#define BUTTON_BACKTOGAME			1007	//�ָ���Ϸ��ťID
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

#define TIMER_GAMETIMER				1		//��Ϸ��Ĭ�ϼ�ʱ��ID
#define TIMER_GAMETIMER_ELAPSE		30		//Ĭ�ϼ�ʱ��ˢ�¼���ĺ�����//����Ҫ���漰����ʱ������
#define UNIT_SPEED					3.0		//��λ�����ٶ�	


#pragma endregion


#pragma region �ṹ������

// �����ṹ��
struct Stage
{
	int stageID;		//�������
	HBITMAP bg;			//����ͼƬ
	int timeCountDown;	//��Ϸʱ�䵹��ʱ
	bool timerOn;		//��ʱ���Ƿ����У���Ϸ�Ƿ���ͣ��

};


// ��ť�ṹ��
struct Button
{
	int buttonID;	//��ť���
	bool visible;	//��ť�Ƿ�ɼ�
	HBITMAP img;	//ͼƬ
	int x;			//����x
	int y;			//����y
	int width;		//���
	int height;		//�߶�
};

// ��λ�ṹ��
struct Unit
{
	HBITMAP img;	//ͼƬ

	int frame_row;			//��ǰ��ʾ����ͼ��ĵڼ���
	int frame_column;		//��ǰ��ʾ����ͼ��ĵڼ���

	int* frame_sequence;		//��ǰ��֡����
	int frame_count;		//֡���еĳ���
	int frame_id;			//��ǰ��ʾ����֡���еĵڼ���


	int side;		//��λ��Ӫ
	int state;		//��λ״̬
	int direction;	//��λ����

	int x;			//����x
	int y;			//����y
	double vx;		//�ٶ�x
	double vy;		//�ٶ�y
	int health;		//����ֵ
	int bubble_timer;	//����ը���ļ��
	int max_bubble;		//�洢ը�����������
	int supertime;		//�޵�ʱ��
	int boom_range;		//��ը��Χ
	int lifes;			//����
	bool skill;			//�Ƿ�ӵ�г�̼���
	int skill_energy;	//��̼���������
	bool has_switch_blood;	//ӵ�л�Ѫ����
};

struct Bubble
{
	HBITMAP img;						//ͼƬ

	int x;								//����x
	int y;								//����y
	int owner;							//��˭���õ�
	int count_down_duration;			//��ըʱ��
	int range;							//��ը�뾶
	int timer_id;						//��ʱ��id
	int frame_id;
	int frame_colume;
};
struct Boom
{
	HBITMAP img;						//ͼƬ

	int x;								//����x
	int y;								//����y
	int owner;							//��˭���õ�
	int count_down_duration;			//��ըʱ��
	int localtion;						//��ը��λ��
};

struct Cartridge_Bag
{
	HBITMAP img;
	int x;								//����x
	int y;								//����y
	int frame_id;						//ȷ���ڵڼ�֡�������ͼ
	int feature;						//ȷ��������ߵ�����
	bool used;							//ȷ����������Ƿ�ʹ�ù���


};




//TODO: �����Ϸ��Ҫ�ĸ��������ݣ����ש��ȣ�



#pragma endregion


#pragma region �¼�����������


// ��ʼ����Ϸ���庯��
void InitGame(HWND hWnd, WPARAM wParam, LPARAM lParam);

// ���̰����¼�������
void KeyDown(HWND hWnd, WPARAM wParam, LPARAM lParam);

// �����ɿ��¼�������
void KeyUp(HWND hWnd, WPARAM wParam, LPARAM lParam);

// ����ƶ��¼�������
void MouseMove(HWND hWnd, WPARAM wParam, LPARAM lParam);

// �����������¼�������
void LButtonDown(HWND hWnd, WPARAM wParam, LPARAM lParam);

// �������ɿ��¼�������
void LButtonUp(HWND hWnd, WPARAM wParam, LPARAM lParam);

// ��ʱ���¼�������
void TimerUpdate(HWND hWnd, WPARAM wParam, LPARAM lParam);

#pragma endregion


#pragma region ������Ϸ״̬����������

// ��Ӱ�ť����
Button* CreateButton(int buttonID, HBITMAP img, int width, int height, int x, int y);

// ��ӵ�λ����
Unit* CreateUnit(int side, int x, int y, int health);




// ��ʼ����������
void InitStage(HWND hWnd, int stageID);

// ˢ�µ�λ״̬����
void UpdateUnits(HWND hWnd);

//ˢ�µ���״̬����
void UpdateItems(HWND hWnd);

//�ӿ���Ϸ���̺���
void quick_game(HWND hWnd, int(*map)[16]);



//��λ��Ϊ����
void UnitBehaviour_Me(HWND hWnd);
void UnitBehaviour_Rival(HWND hWnd);
void PlaceBubble(HWND hWnd, Unit* unit,int owner);
void UpdateBubbles(HWND hWnd);

//��⺯��
void CheckBooms(HWND hWnd);							//�������ͳ�����Ƿ�����ײ
bool CheckUnitBlood(HWND hWNd);						//�������Ѫ���Ƿ����
void Check_Boom_Block(HWND hwnd,int(*map)[16]);		//��������Ƿ�ݻ��ϰ���
int Check_UnitMe_Block(HWND hwnd, int(*map)[16]);	//��������Ƿ������ϰ���
int Check_UnitRival_Block(HWND hwnd, int(*map)[16]);
void Check_Unit_Item(HWND hWnd);
void check_togo(HWND hWnd, int(*map)[16]);
void skill(HWND hWnd);
void switch_blood(HWND hWnd);
void timer_switch_blood(HWND hWnd);
void stage_warnins(HWND hWnd);
//ɾ���Ѿ�ʹ�ù������ݣ�������Լ�ը��
void delete_bubble_and_items(HWND hWnd);
//����ʱ����
void Count_Down_Timer();
//���ɵ��ߺ���
void CreateSpecialItems(HWND hWnd,int(*map)[16]);
//TODO: �����Ϸ��Ҫ�ĸ��ຯ��


#pragma endregion 


#pragma region ��ͼ��������

// ��ͼ����
void Paint(HWND hWnd);

// ��ʼ����������
HBITMAP InitBackGround(HWND hWnd, HBITMAP bmp_src);
HBITMAP InitMenuBackGround(HWND hWnd, HBITMAP bmp_src);


#pragma endregion