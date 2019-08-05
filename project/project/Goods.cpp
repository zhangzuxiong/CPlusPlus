
#include "Goods.h"


//初始化
void initGoodsList(GoodsList* p) {
	//指针判空
	if (p == NULL)
	{
		//printf("初始化参数为空\n");
		return;
	}

	//临时指针变量，来释放双链表中之前存在的空间
	GoodsNode* temp = p->head;
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
bool judgeEmpotGoodsList(const GoodsList list) {
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
int insertPositionGoods(GoodsList* p, const const int position, const Goods goods) {
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
	GoodsNode* node = (GoodsNode*)malloc(sizeof(GoodsNode));
	node->goods = goods;

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
		GoodsNode* index = p->head;

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
Goods* deleteGoodsById(GoodsList* p, const int Id) {
	if (p == NULL)
	{
		//printf("删除参数为空\n");
		return 0;
	}

	if (judgeEmpotGoodsList(*p))
	{
		//printf("双向链表为空,无法删除\n");
		return 0;
	}
	//记录删除的位置
	GoodsNode* index = p->head;

	//保存删除的数据
	Goods* res = (Goods*)malloc(sizeof(Goods));

	//只有一个元素
	if (p->count == 1)
	{
		*res = index->goods;

		//释放空间
		free(p->head);
		p->head = NULL;
		p->tail = NULL;
	}

	while (index != NULL)
	{
		if (index->goods.goodsId == Id)
		{
			*res = index->goods;

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



//查找--按照值查询返回查找用户
Goods* searchGoodsById(const GoodsList list, const int goodsId) {
	if (judgeEmpotGoodsList(list))
	{
		printf("双链表已经为空，不能查找\n");
		return NULL;
	}

	//临时指针变量保存找到的地址
	GoodsNode* temp = list.head;

	while (temp != NULL)
	{
		if (temp->goods.goodsId == goodsId)
		{
			return &(temp->goods);
		}
		//指向下一个查找的位置
		temp = temp->next;
	}
	printf("没有找到\n");
	return NULL;
}

//清空
void clearGoodsList(GoodsList* p) {
	if (p == NULL)
	{
		return;
	}

	if (judgeEmpotGoodsList(*p))
	{
		return;
	}

	initGoodsList(p);
}


//打印所有
void printGoodsrList(const GoodsList list) {
	if (judgeEmpotGoodsList(list))
	{
		return;
	}

	printf("\t%-10s%-10s%-10s%-10s\n", "商品ID", "商品名称", "商品价格", "库存");
	GoodsNode* temp = list.head;

	while (temp != NULL)
	{
		printf("\t%-10d%-10s%-10d%-10d\n", temp->goods.goodsId, temp->goods.name, temp->goods.price, temp->goods.stock);
		temp = temp->next;
	}
}


//打印单个商品信息
void printGoodsInfo(const Goods goods) {
	printf("商品Id:%d,商品名称:%s,商品价格:%d,库存:%d", goods.goodsId, goods.name, goods.price, goods.stock);
}


//将商品信息保存到文件
void saveGoods(const GoodsList list) {
	FILE* file = fopen("../project/goods.txt", "w");
	if (!file)
	{
		printf("文件打开失败\n");
		return;
	}

	//保存商品的节点
	GoodsNode* node = list.head;

	//循环遍历将每一个商品写入文件
	while (node != NULL)
	{
		fprintf(file, "%d\t%s\t\%d\t%d\n", node->goods.goodsId, node->goods.name, node->goods.price, node->goods.stock);
		node = node->next;
	}

	printf("商品保存成功\n");

	//文件关闭
	fclose(file);
}


//将文件中的商品读取到队列
void getGoodsData(GoodsList* p) {
	FILE* file = fopen("../project/goods.txt", "r");
	if (!file)
	{
		printf("文件打开失败\n");
		return;
	}

	Goods goods = { 0 };

	fscanf(file, "%d\t%s\t\%d\t%d\n", &goods.goodsId, goods.name, &goods.price, &goods.stock);
	if (goods.goodsId < 1)
	{
		printf("文件为空\n");
		return;
	}

	//将文件内容读取出来
	while (!feof(file))
	{

		insertPositionGoods(p, 1, goods);
		fscanf(file, "%d\t%s\t\%d\t%d\n", &goods.goodsId, goods.name, &goods.price, &goods.stock);

	}


	//关闭文件
	fclose(file);
}