// project.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//


#include "OrderQueue.h"

//往数组中添加一个数
void insertArray(int* p, int num, int length) {
	if (p == NULL)
	{
		return;
	}
	int i = 0;
	while (p[i] != 0)
	{
		i++;
	}
	if (i >= length)
	{
		return;
	}
	p[i] = num;
}
//往数组中删除一个数
void deleteArray(int* p, int num, int length) {
	if (p == NULL)
	{
		return;
	}
	int i = 0;
	//int count = 0;
	int index = 0;
	while (p[i] != 0)
	{
		if (p[i] == num)
		{
			index = i;
			p[i] = 0;
		}
		i++;
	}
	while (index < length - 1)
	{
		p[index] = p[index + 1];
		index++;
	}

}

//商家--商品管理
void business(User* user, UserList* userList, GoodsList* goodsList, OrderList* orderList) {
	if (user == NULL || goodsList == NULL || orderList == NULL || userList == NULL)
	{
		return;
	}

	int flag = 1;
	int i = 0;
	int del = 0;
	int j = 0;
	Goods* goods = NULL;
	Goods newGoods = { 0 };
	Order* order = NULL;

	OrderQueue queue = { 0 };
	initOrderQueue(&queue);

	while (user->orderList[i] > 0)
	{
		order = searchOrderById(*orderList, user->orderList[i++]);
		if (order!=NULL)
		{
			putOrderQueue(&queue, *order);
		}
	}

	while (flag)
	{
		printf("\n\n1.查看商品   \n2.添加商品   \n3.删除商品   \n4.查看订单  \n5.修改订单\n");
		printf("0.退出    \n请选择:");
		scanf(" %d", &flag);


		switch (flag)
		{
		case 1:
			system("cls");
			i = 0;
			while (user->goodsList[i] > 0)
			{
				//Goods* goods = searchGoodsById(*goodsList, user->goodsList[i]);
				goods = searchGoodsById(*goodsList, user->goodsList[i]);
				if (goods!=NULL)
				{
					printGoodsInfo(*goods);
					printf("\n");
				}
				i++;
			}

			break;

		case 2:
			while (true)
			{
				system("cls");
				newGoods = { 0 };
				printf("请输入商品ID:");
				scanf(" %d", &newGoods.goodsId);

				printf("请输入商品价格:");
				scanf(" %d", &newGoods.price);

				printf("请输入商品名称:");
				scanf(" %s", &newGoods.name);

				printf("请输入商品库存:");
				scanf(" %d", &newGoods.stock);

				newGoods.userId = user->userId;

				//将商品ID保存到商家商品数组
				insertArray(user->goodsList, newGoods.goodsId, SIZE);
				//user->goodsList[goodsList->count + 1] = goods.goodsId;
				
				insertPositionGoods(goodsList, goodsList->count + 1, newGoods);

				printf("\n是否继续添加商品(1:继续,0:不继续):");
				int f = 0;
				scanf(" %d", &f);
				if (f == 0)
				{
					break;
				}
			}
			break;

		case 3:
			system("cls");
			del = 0;
			printf("请输入删除商品的ID:");
			scanf(" %d", &del);
			if (deleteGoodsById(goodsList, del)) {
				//删除商家商品数组中对应的ID
				deleteArray(user->goodsList, del, SIZE);
			}
			break;

		case 4:
			system("cls");
			j = 0;
			while (user->orderList[j] != 0 && j < SIZE)
			{
				order = searchOrderById(*orderList, user->orderList[j]);
				printOrder(*userList, *order);
				i = 0;
				while (order->goodsId[i] > 0)
				{
					printGoodsInfo(*searchGoodsById(*goodsList, order->goodsId[i]));
					printf("\t%d个\n", order->count[i++]);
				}
				printf("\n\n");
				j++;
			}

			break;


		case 5:
			//修改订单
			//打印订单信息
			printOrderList(*userList, *goodsList, queue.list);

			i = 0;
			printf("\n请输入修改的订单ID:");
			scanf(" %d", &i);

			order = searchOrderById(queue.list, i);
			if (order!=NULL)
			{
				//修改订单收货地址,收件地址存放在用户信息中
				printf("请输入新的收货地址:");
			}

			break;

		case 0:
			clearOrderQueue(&queue);
			return;
			break;
		default:
			printf("输入有误\n");
			break;
		}
	}

}

//买家
void buyer(User* user, const UserList userList, GoodsList* goodsList, OrderList* orderList) {
	if (user == NULL || goodsList == NULL || orderList == NULL)
	{
		return;
	}
	int i = 0;
	int j = 0;
	int flag = 1;
	int in = 0;
	int pre = 0;
	int n = 0;
	Order order = { 0 };
	Goods* goods = NULL;
	while (flag)
	{
		printf("\n\n1.查看商品 \n2.查看订单 \n3.下单 \n4.退单 \n5.修改个人信息 \n0.退出 \n请选择:");
		scanf(" %d", &flag);
		switch (flag)
		{
		case 1:
			//打印所有商品信息
			printGoodsrList(*goodsList);
			break;

		case 2:
			system("cls");
			i = 0;
			while (user->orderList[i] > 0)
			{
				order = { 0 };
				order = *searchOrderById(*orderList, user->orderList[i]);
				printOrder(userList, order);
				j = 0;
				while (order.goodsId[j] > 0)
				{
					printGoodsInfo(*searchGoodsById(*goodsList, order.goodsId[j]));
					printf(",%d个\n", order.count[j]);
					j++;
				}
				i++;
				printf("\n\n");
			}

			break;

		//一个订单只能购买一个用户的商品
		case 3:
			system("cls");
			//下单
			order = { 0 };
			printf("请输入订单号:");
			scanf(" %d", &order.orderId);


			printf("请输入下单时间:");
			scanf(" %s", &order.createDate);
			order.status = 1;
			order.userId = user->userId;

			n = 0;

			i = 1;
			while (i)
			{
				in = 1;
				printf("商品信息:\n");
				printGoodsrList(*goodsList);
				printf("请选择商品：");
				scanf(" %d", &in);

				if (searchGoodsById(*goodsList, in))
				{
					goods = searchGoodsById(*goodsList, in);
					n = goods->userId;
					pre = n;
					printf("请输入购买数量:");
					j = 0;
					scanf(" %d", &j);
					if (j > goods->stock || j < 1)
					{
						printf("库存不足\n");
					}
					else
					{
						
						order.businessId = n;


						goods->stock = goods->stock - j;
						insertArray(order.goodsId, in, SIZE);
						insertArray(order.count, j, SIZE);
					}
				}
				else
				{
					printf("商品ID输入有误\n");
				}

				printf("是否继续添加商品(1:继续,0:不继续):");
				scanf(" %d", &i);

			}
			insertPositionOrder(orderList, orderList->count + 1, order);
			insertArray(searchUserById(userList, order.businessId)->orderList, order.orderId, SIZE);
			insertArray(user->orderList, order.orderId, SIZE);

			break;

		case 4:
			//退单
			system("cls");
			i = 0;
			while (user->orderList[i] > 0)
			{
				printOrder(userList, *searchOrderById(*orderList, user->orderList[i]));
				j = 0;
				//printArray(order.count, SIZE);
				while (order.goodsId[j] > 0)
				{
					printGoodsInfo(*searchGoodsById(*goodsList, order.goodsId[j]));
					printf(",%d个\n", order.count[j++]);
				}

				printf("\n\n");
				i++;
			}

			printf("请输入退单的订单号:");
			scanf(" %d", &in);
			order = *searchOrderById(*orderList, in);
			if (searchOrderById(*orderList, in))
			{

				order = *searchOrderById(*orderList, in);
				n = 0;
				while (order.goodsId[n] > 0)
				{
					goods = searchGoodsById(*goodsList, order.goodsId[n]);
					goods->stock = goods->stock + order.count[n++];
				}

				deleteOrderById(orderList, in);
				deleteArray(user->orderList, in, SIZE);
				deleteArray(searchUserById(userList, order.businessId)->orderList, in, SIZE);
			}
			break;

		case 5:
			system("cls");
			//修改个人信息,修改参数中的user
			printf("请输入新密码:");
			scanf(" %s", user->passwd);

			printf("请输入新的联系方式:");
			scanf(" %s", user->phone);

			printf("请输入新的收件地址:");
			scanf(" %s", user->address);

			break;

		case 0:
			return;
			break;


		default:
			break;
		}

	}
}

//送货员
void rider(User* user, const UserList userList, GoodsList* goodsList, OrderList* orderList) {
	if (user == NULL || goodsList == NULL || orderList == NULL)
	{
		printf("参数错误\n");
		return;
	}

	OrderQueue queue = { 0 };
	initOrderQueue(&queue);


	int flag = 1;
	int i = 0;
	int j = 0;
	int del = 0;
	Order order = { 0 };
	Goods goods = { 0 };

	while (user->orderList[i] > 0)
	{
		order = *searchOrderById(*orderList, user->orderList[i++]);
		putOrderQueue(&queue, order);
	}

	while (flag)
	{
		printf("\n\n1.查看所有订单\n2.送货\n3.查看自己配送的订单\n0.退出\n");
		printf("请选择:");
		scanf(" %d", &flag);

		switch (flag)
		{
		case 1:
			system("cls");
			i = 1;
			while (i)
			{
				printOrderList(userList, *goodsList, *orderList);
				printf("请选择派送的订单(按0结束):");
				scanf(" %d", &i);
				if (searchOrderById(*orderList, i))
				{
					order = *searchOrderById(*orderList, i);
					insertArray(user->orderList, i, SIZE);
					putOrderQueue(&queue, order);
				}
				else
				{
					printf("选择的订单不存在\n");
				}
			}


			break;
		case 3:
			system("cls");
			printOrderQueue(userList, *goodsList, queue);
			break;

		case 2:
			//送货
			system("cls");
			printf("您正在配送订单,送货的订单为:\n");

			order = *getOrderQueue(&queue);
			printOrder(userList, order);
			i = 0;
			while (order.goodsId[i] > 0)
			{
				printGoodsInfo(*searchGoodsById(*goodsList, order.goodsId[i++]));
				printf("\n");
			}
			printf("\n\n");
			order.status = 3;
			break;
		case 0:
			clearOrderQueue(&queue);
			return;
		default:
			break;
		}


	}

}

void menu() {
	UserList userList = { 0 };
	initUserList(&userList);

	OrderList orderList = { 0 };
	initOrderList(&orderList);

	GoodsList goodsList = { 0 };
	initGoodsList(&goodsList);

	//读取文件内容
	getUserData(&userList);
	getOrderInfo(&orderList);
	getGoodsData(&goodsList);

	User* user = NULL;

	int select = 1;
	while (select)
	{
		printf("\t\t1.注册\n\t\t2.登录\n\t\t0.退出\n请选择:");
		scanf(" %d", &select);
		switch (select)
		{
		case 1:
			registerUser(&userList);
			break;

		case 2:
			user = loginUser(userList);
			if (user == NULL)
			{
				printf("登录失败");
				break;
			}

			//商家
			if (user->type == 1)
			{
				business(user, &userList, &goodsList, &orderList);
			}
			//买家
			else if (user->type == 2)
			{
				buyer(user, userList, &goodsList, &orderList);
			}
			//骑手
			else if (user->type == 3)
			{
				rider(user, userList, &goodsList, &orderList);
			}
			break;

		case 0:
			//将用户信息、商品信息、订单信息保存到文件
			saveUserData(userList);
			saveOrderInfo(orderList);
			saveGoods(goodsList);
			return;
		default:
			printf("输入有误\n");
			break;
		}
		system("cls");
	}

}

void testUserFile() {
	UserList list = { 0 };
	initUserList(&list);
	getUserData(&list);
	printUserList(list);
	/*User user1 = { 3,"111","一一一","1000","武汉1",1,{1},{1} };
	User user2 = { 2,"222","二二二","2000","武汉2",2,{2},{2} };
	User user3 = { 1,"333","三三三","3000","武汉3",3,{3,4,5},{3,4,5} };
	insertPositionUser(&list, list.count + 1, user1);
	insertPositionUser(&list, list.count + 1, user2);
	insertPositionUser(&list, list.count + 1, user3);

	printUserList(list);
	saveUserData(list);*/
}

void testOrderFile() {
	OrderList list = { 0 };
	initOrderList(&list);

	getOrderInfo(&list);

	Order order1 = { 1,1,2,"2011",1,{1,2,3},{4,5,6} };
	Order order2 = { 2,3,4,"2013",2,{1,2,3},{4,5,6} };
	Order order3 = { 3,5,6,"2015",3,{1,2,3},{4,5,6} };

	insertPositionOrder(&list, 1, order1);
	insertPositionOrder(&list, 1, order2);
	insertPositionOrder(&list, 1, order3);

	saveOrderInfo(list);
}

int main()
{
	//testOrderFile();
	//testUserFile();
	menu();
	return 0;
}
