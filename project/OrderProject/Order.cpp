
#include "Order.h"


//初始化
void initOrderList(OrderList* p) {
	//指针判空
	if (p == NULL)
	{
		//printf("初始化参数为空\n");
		return;
	}

	//临时指针变量，来释放双链表中之前存在的空间
	OrderNode* temp = p->head;
	while (p->head != NULL)
	{
		//把头往后移动一个
		p->head = temp->next;

		//释放空间
		free(temp);

		//指向下一个释放的空间
		temp = p->head;
	}

	//尾指针置位NULL
	p->tail = NULL;

	//有效元素置位0
	p->count = 0;

}


//判空
bool judgeEmpotOrderList(const OrderList list) {
	if (list.count == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}


//插入，在第position个位置插入一个用户
int insertPositionOrder(OrderList* p, const const int position, const Order order) {
	if (p == NULL)
	{
		//printf("插入双链表的参数为空\n");
		return 0;
	}

	if (position < 1 || position > p->count + 1)
	{
		//printf("插入位置不合理\n");
		return 0;
	}

	//新插入的节点
	OrderNode* node = (OrderNode*)malloc(sizeof(OrderNode));
	node->order = order;

	//链表为空
	if (p->count == 0)
	{
		//新节点既是头结点也是尾结点
		p->head = node;
		p->tail = node;

		//头结点的下一个和尾结点的前一个置为NULL
		p->head->next = NULL;
		p->tail->pre = NULL;
	}
	//链表非空，在头或尾插入
	else if (p->count != 0 && (position == 1 || position == p->count + 1))
	{
		//在头插入
		if (position == 1)
		{
			//新节点的下一个节点为头结点
			node->next = p->head;

			//新节点的前一个节点是头结点的前一个节点（NULL）
			node->pre = p->head->pre;

			//头节点的前一个节点是新节点
			p->head->pre = node;

			//将新节点设置为新的头结点
			p->head = node;
		}
		//在尾插入
		else
		{
			//新节点的下一个节点为尾结点的下一个节点（NULL）
			node->next = p->tail->next;

			//新节点的前一个节点是尾结点
			node->pre = p->tail;

			//尾结点的下一个节点是新节点
			p->tail->next = node;

			//将新节点设置为新的尾结点
			p->tail = node;
		}
	}
	//在中间插入
	else
	{
		//记录插入的位置
		OrderNode* index = p->head;

		//循环计数器，找到插入的位置
		int i = 1;
		while (i < position)
		{
			index = index->next;
			i++;
		}
		//先改变next，分为2步
		//1.新节点的下一个指向index的位置
		node->next = index;

		//2.插入位置的前一个指向新节点
		index->pre->next = node;


		//再改变pre,分为2步
		//1.新节点的前一个指向插入节点的前一个
		node->pre = index->pre;

		//2.插入位置的前一个指向新节点
		index->pre = node;
	}

	//有效元素加1
	p->count++;

	return 1;
}


//删除--根据Id删除
Order* deleteOrderById(OrderList* p, const int Id) {
	if (p == NULL)
	{
		//printf("删除参数为空\n");
		return 0;
	}

	if (judgeEmpotOrderList(*p))
	{
		//printf("双向链表为空,无法删除\n");
		return 0;
	}
	//记录删除的位置
	OrderNode* index = p->head;

	//保存删除的数据
	Order* res = (Order*)malloc(sizeof(Order));

	//只有一个元素
	if (p->count == 1)
	{
		*res = index->order;

		//释放空间
		free(p->head);
		p->head = NULL;
		p->tail = NULL;
	}

	while (index != NULL)
	{
		if (index->order.orderId == Id)
		{
			*res = index->order;

			if (index->pre == NULL)
			{
				p->head = index->next;

				free(index);

				index = NULL;

				//新节点的前一个节点置位NULL
				p->head->pre = NULL;

			}
			else if (index->next == NULL)
			{
				p->tail = p->tail->pre;

				//将末尾的前一个的next置位NULL，然后释放原链表的末尾节点
				free(p->tail->next);
				p->tail->next = NULL;
			}
			else
			{
				index->pre->next = index->next;
				index->next->pre = index->pre;

				free(index);
			}

			//有效元素减1
			p->count--;
			return res;
		}
		index = index->next;
	}

	printf("没有找到删除的Id\n");
	return NULL;
}


//根据位置删除
Order* deletePositionOrderList(OrderList* p, const int position) {
	if (p == NULL)
	{
		//printf("删除参数为空\n");
		return 0;
	}

	if (judgeEmpotOrderList(*p))
	{
		//printf("双向链表为空,无法删除\n");
		return 0;
	}

	if (position < 1 || position > p->count)
	{
		//printf("删除的位置不合理\n");
		return 0;
	}

	//记录删除的位置
	OrderNode* index = p->head;

	//保存删除的数据
	Order* res = (Order*)malloc(sizeof(Order));

	//双链表只有一个元素，直接释放头，头尾赋NULL
	if (p->count == 1)
	{
		*res = p->head->order;

		//释放空间
		free(p->head);
		p->head = NULL;
		p->tail = NULL;
	}
	//删除之后不空，并且删除的位置在第一个
	else if (position == 1 && p->count > 1)
	{
		*res = p->head->order;

		//将head向后移动一个
		p->head = index->next;

		free(index);

		index = NULL;

		//新节点的前一个节点置位NULL
		p->head->pre = NULL;
	}
	//删除最后一个，并且双链表有效元素大于1个
	else if (position == p->count && p->count > 1)
	{
		*res = p->tail->order;

		//将tail向前移动一个
		p->tail = p->tail->pre;

		//将末尾的前一个的next置位NULL，然后释放原链表的末尾节点
		free(p->tail->next);
		p->tail->next = NULL;
	}
	//删除在中间
	else
	{
		//循环计数器，找到删除的位置
		int i = 1;
		while (i < position)
		{
			index = index->next;
			i++;
		}
		*res = index->order;

		//当前删除节点的前一个节点next指向删除节点的next
		index->pre->next = index->next;

		//当前删除节点next的pre指向index的pre
		index->next->pre = index->pre;

		//释放空间
		free(index);
	}

	//有效元素减1
	p->count--;
	printf("删除成功\n");
	return res;
}


//查找--按照值查询返回查找用户
Order* searchOrderById(const OrderList list, const int orderId) {
	if (judgeEmpotOrderList(list))
	{
		printf("双链表已经为空，不能查找\n");
		return NULL;
	}

	//临时指针变量保存找到的地址
	OrderNode* temp = list.head;

	while (temp != NULL)
	{
		if (temp->order.orderId == orderId)
		{
			return &(temp->order);
		}
		//指向下一个查找的位置
		temp = temp->next;
	}
	printf("没有找到\n");
	return NULL;
}

//清空
void clearOrderList(OrderList* p) {
	if (p == NULL)
	{
		return;
	}

	if (judgeEmpotOrderList(*p))
	{
		return;
	}

	initOrderList(p);
}

//打印一个数组
void printArray(int* p, int length) {
	if (p == NULL)
	{
		return;
	}
	else
	{
		int i = 0;
		while (i < length)
		{
			printf("%d ", p[i++]);
		}
		printf("\n");
	}
}

//打印
void printOrderList(const UserList userList,const GoodsList goodsList,const OrderList list) {
	if (judgeEmpotOrderList(list)||judgeEmpotGoodsList(goodsList)||judgeEmpotUserList(userList))
	{
		return;
	}

	//printf("\t%-10s%-10s%-10s%-10s\n", "订单ID", "商品名称", "商品价格", "库存");
	OrderNode* temp = list.head;
	User buyer = { 0 };
	User bussiness = { 0 };
	Goods goods = { 0 };


	while (temp != NULL)
	{
		buyer = *searchUserById(userList, temp->order.userId);
		bussiness = *searchUserById(userList, temp->order.businessId);
		/*printf("订单ID:%d,用户姓名:%s,商家:%s,下单时间:%s\n",temp->order.orderId,
			buyer.name,bussiness.name,temp->order.createDate);*/

		printOrder(userList, temp->order);

		int i = 0;
		while (temp->order.goodsId[i]>0)
		{
			printGoodsInfo(*searchGoodsById(goodsList, temp->order.goodsId[i]));
			printf(",总%d个\n", temp->order.count[i++]);
		}

		printf("\n\n");
		//printf("\t%-10d\n", temp->order.orderId);
		temp = temp->next;
	}
}


//打印一个订单
void printOrder(const UserList userList, const Order order) {
	User buyer = *searchUserById(userList, order.userId);
	User bussiness = *searchUserById(userList, order.businessId);
	printf("订单ID:%d,买家姓名:%s,买家联系电话:%s,收件地址:%s,商家名称:%s,商家联系电话:%s,发货地址:%s,下单时间:%s\n", 
		order.orderId, buyer.name,buyer.phone,buyer.address, bussiness.name,bussiness.phone,bussiness.address, order.createDate);
}


//保存订单信息
void saveOrderInfo(const OrderList list) {
	FILE* file = fopen("../OrderProject/order.txt", "w");
	if (!file)
	{
		printf("文件打开失败\n");
		return;
	}

	OrderNode* node = list.head;

	//循环遍历将每个订单写入文件
	while (node != NULL)
	{
		//保存订单ID、用户ID、商家ID、下单时间、状态
		fprintf(file, "%d\t%d\t\%d\t\%s\t%d\t",
			node->order.orderId, node->order.userId, node->order.businessId,
			node->order.createDate, node->order.status);
		int i = 0;

		//保存商品信息
		while (node->order.goodsId[i] > 0)
		{
			fprintf(file, "%d\t%d\t", node->order.goodsId[i],node->order.count[i]);
			i++;
		}
		fprintf(file, "%d\t%d\n", 0,0);


		node = node->next;
	}

	//printf("商品保存成功\n");

	//文件关闭
	fclose(file);
}

//读取订单信息
void getOrderInfo(OrderList* p) {
	if (p==NULL)
	{
		return;
	}

	FILE* file = fopen("../OrderProject/order.txt", "r");
	if (!file)
	{
		printf("文件打开失败\n");
		return;
	}

	Order order = { 0 };

	fscanf(file, "%d\t%d\t\%d\t\%s\t%d\t",
		&order.orderId, &order.userId, &order.businessId,
		order.createDate, &order.status);
	if (order.userId < 1)
	{
		printf("文件为空\n");
		return;
	}
	int i = 0;

	fscanf(file, "%d\t%d\t", &order.goodsId[i], &order.count[i]);
	while (order.goodsId[i] > 0)
	{
		i++;
		fscanf(file, "%d\t%d\t", &order.goodsId[i], &order.count[i]);
	}
	fscanf(file, "\n");
	insertPositionOrder(p, 1, order);

	//将文件内容读取出来
	while (!feof(file))
	{
		fscanf(file, "%d\t%d\t\%d\t\%s\t%d\t",
			&order.orderId, &order.userId, &order.businessId,
			order.createDate, &order.status);
		i = 0;

		fscanf(file, "%d\t%d\t", &order.goodsId[i], &order.count[i]);
		while (order.goodsId[i] > 0)
		{
			i++;
			fscanf(file, "%d\t%d\t", &order.goodsId[i], &order.count[i]);
		}
		fscanf(file, "\n");
		insertPositionOrder(p, 1, order);
	}

	//关闭文件
	fclose(file);
}