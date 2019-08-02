// project_1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

/*
	发一张不重复的牌

		1.随机数

		2.排重：
			1.向前比较
			2.mark


	保存用户手牌
		用两个数组，对应下标表示一张牌


	打印手牌
		0 - 3    黑 红 梅 方
		0 - 12   A 2 - 10 J Q K


	初始化游戏
		目前暂时考虑两个用户
		尝试考虑两个以上用户的写法

*/

#include <stdlib.h>

#include <time.h>

/*
	用户类型

		1.需要记录手上的牌的花色和点数
		2.需要记录手上有多少张牌
		3.点数
*/
typedef struct Player {

	// 表示 点数
	int point[20];

	// 表示 花色
	int color[20];

	// 表示 用户手上有多少张有效的牌
	int num;

	// 表示 手牌加来的点数和
	int point_sum;

	// 标记 用户是否要牌 1表示要牌 0表示不要
	int flag;

} Player;


// 判重标记
int mark[4][13] = { 0 };



// 给一个用户的任意手牌位置发一张牌
void deal_cards(Player* p) {

	if (p == NULL)
	{
		printf(" deal_cards 函数形参为空\n");

		return;
	}

	while (true)
	{
		p->point[p->num] = rand() % 13;

		p->color[p->num] = rand() % 4;

		if (mark[p->color[p->num]][p->point[p->num]] == 0)
		{
			mark[p->color[p->num]][p->point[p->num]]++;

			p->num++;

			return;
		}
	}
}





// 打印用户手上所持有的牌
void print_cards(const Player player) {

	const char* p[13] = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };

	const char* c[4] = { "黑桃", "红桃", "梅花", "方片" };

	int i = 0;

	for (i = 0; i < player.num; i++)
	{
		printf(" [ %s %2s ] ", c[player.color[i]], p[player.point[i]]);
	}

	printf("\n");
}




// 初始化游戏
void init_game(Player* p1, Player* p2) {

	// 设置随机数 种子
	srand(time(NULL));

	/*deal_cards(&(p1->point[0]), &(p1->color[0]), &(p1->num));
	deal_cards(&(p1->point[1]), &(p1->color[1]), &(p1->num));

	deal_cards(&(p2->point[0]), &(p2->color[0]), &(p2->num));
	deal_cards(&(p2->point[1]), &(p2->color[1]), &(p2->num));*/

	deal_cards(p1);
	deal_cards(p1);

	deal_cards(p2);
	deal_cards(p2);

	// 要牌的标记 1
	p1->flag = 1;
	p2->flag = 1;
}



// 运行轮流要牌的游戏逻辑
void run_game(Player* p1, Player* p2) {

	while (true)
	{
		// 1
		if (p1->flag)
		{
			printf(" 用户 [ 1 ] 是否要牌（y/n）：");

			char c1 = 0;

			scanf(" %c", &c1);

			if (c1 == 'y' || c1 == 'Y')
			{
				deal_cards(p1);

				p1->flag = 1;
			}
			else if (c1 == 'n' || c1 == 'N')
			{
				printf(" 用户1 不发张牌\n");

				p1->flag = 0;
			}
			else
			{
				printf(" 用户1 要牌有误\n");

				return;
			}
		}

		// 2
		if (p2->flag)
		{
			printf(" 用户 [ 2 ] 是否要牌（y/n）：");

			char c2 = 0;

			scanf(" %c", &c2);

			if (c2 == 'y' || c2 == 'Y')
			{
				deal_cards(p2);

				p2->flag = 1;
			}
			else if (c2 == 'n' || c2 == 'N')
			{
				printf(" 用户2 不发张牌\n");

				p2->flag = 0;
			}
			else
			{
				printf(" 用户2 要牌有误\n");

				return;
			}
		}

		if (p1->flag == 0 && p2->flag == 0)
		{
			return;
		}

		printf("\n-----------------------------------\n\n");
		printf(" 用户【1】：");
		print_cards(*p1);
		printf(" 用户【2】：");
		print_cards(*p2);
		printf("\n-----------------------------------\n\n");
	}
}



// 所有人要牌结束之后开始计算点数
void statistical_points(Player* p) {

	if (p == NULL)
	{
		printf(" statistical_points 函数形参为空\n");

		return;
	}

	// 和打印的时候的设计思路一致
	int point_val[13] = { 11,2,3,4,5,6,7,8,9,10,10,10,10 };

	// 遍历用户的所有手牌进行点数累加
	int i = 0;

	int num_a = 0;

	for (i = 0; i < p->num; i++)
	{
		p->point_sum += point_val[p->point[i]];

		if (p->point[i] == 0)
		{
			num_a++;
		}
	}

	// 动态调整 A 的点数
	while (num_a > 0 && p->point_sum > 21)
	{
		p->point_sum -= 10;

		num_a--;
	}
}



// 点数计算完毕，开始统计输赢
void judge_win(const Player p1, const Player p2) {

	/*
		1. 1 和 2 都大于21 —— 平局
		2. 1 和 2 都小于、等于21，
			2.1 相等 —— 平局
			2.2 1 大于 2 —— 1Win
			2.3 2 大于 1 —— 2win
		3. 1 和 2 中有一个大于21，另一不大于21 —— 则不大于21的 win
	*/
	if (p1.point_sum > 21 && p2.point_sum > 21)
	{
		printf(" 平局\n");
	}
	else if (p1.point_sum <= 21 && p2.point_sum > 21)
	{
		printf(" 用户 1 获胜！\n");
	}
	else if (p1.point_sum > 21 && p2.point_sum <= 21)
	{
		printf(" 用户 2 获胜！\n");
	}
	else
	{
		if (p1.point_sum > p2.point_sum)
		{
			printf(" 用户 1 获胜！\n");
		}
		else if (p1.point_sum < p2.point_sum)
		{
			printf(" 用户 2 获胜！\n");
		}
		else
		{
			printf(" 平局\n");
		}
	}
}



// 游戏运行函数
void start_game() {

	Player p1 = { 0 };
	Player p2 = { 0 };

	init_game(&p1, &p2);

	printf(" 用户【1】：");
	print_cards(p1);
	printf(" 用户【2】：");
	print_cards(p2);

	printf("\n-----------------------------------\n\n");

	run_game(&p1, &p2);

	printf("\n-----------------------------------\n\n");

	statistical_points(&p1);
	printf(" 用户 1 的总点数：%d\n", p1.point_sum);

	statistical_points(&p2);
	printf(" 用户 2 的总点数：%d\n", p2.point_sum);

	printf("\n-----------------------------------\n\n");

	judge_win(p1, p2);
}



int main()
{
	start_game();



	/*
	Player p3 = { 0 };

	p3.point[0] = 0;
	p3.point[1] = 11;
	//p3.point[2] = 0;
	//p3.point[3] = 0;

	p3.num = 2;
	statistical_points(&p3);
	printf(" 用户 3 的总点数：%d\n", p3.point_sum);
	*/

	/*p1.point_sum = 210;
	p2.point_sum = 21;
	judge_win(p1, p2);*/


	return 0;
}




