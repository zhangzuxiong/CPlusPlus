
#include "User.h"


//初始化
void initUserList(UserList* p) {
	//指针判空
	if (p == NULL)
	{
		//printf("初始化参数为空\n");
		return;
	}

	//临时指针变量，来释放双链表中之前存在的空间
	UserNode* temp = p->head;
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
bool judgeEmpotUserList(const UserList list) {
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
int insertPositionUser(UserList* p, const const int position, const User user) {
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
	UserNode* node = (UserNode*)malloc(sizeof(UserNode));
	node->user = user;

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
		UserNode* index = p->head;

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
User* deleteUserById(UserList* p, const int Id) {
	if (p == NULL)
	{
		//printf("删除参数为空\n");
		return 0;
	}

	if (judgeEmpotUserList(*p))
	{
		//printf("双向链表为空,无法删除\n");
		return 0;
	}

	//记录删除的位置
	UserNode* index = p->head;

	//保存删除的数据
	User* res = (User*)malloc(sizeof(User));

	//只有一个元素
	if (p->count == 1)
	{
		*res = index->user;

		//释放空间
		free(p->head);
		p->head = NULL;
		p->tail = NULL;
	}

	while (index != NULL)
	{
		if (index->user.userId == Id)
		{
			*res = index->user;

			//删除第一个
			if (index->pre == NULL)
			{
				p->head = index->next;

				free(index);

				index = NULL;

				//新节点的前一个节点置位NULL
				p->head->pre = NULL;

			}
			//删除最后后一个
			else if (index->next == NULL)
			{
				p->tail = p->tail->pre;

				//将末尾的前一个的next置位NULL，然后释放原链表的末尾节点
				free(p->tail->next);
				p->tail->next = NULL;
			}

			//删除中间
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

	//printf("没有找到删除的Id\n");
	return NULL;
}



//查找--按照值查询返回查找用户
User* searchUserById(const UserList list, const int userId) {
	if (judgeEmpotUserList(list))
	{
		//printf("双链表已经为空，不能查找\n");
		return NULL;
	}

	//临时指针变量保存找到的地址
	UserNode* temp = list.head;

	while (temp != NULL)
	{
		if (temp->user.userId == userId)
		{
			return &(temp->user);
		}
		//指向下一个查找的位置
		temp = temp->next;
	}
	//printf("没有找到\n");
	return NULL;
}

//清空
void clearUserList(UserList* p) {
	if (p == NULL)
	{
		return;
	}

	if (judgeEmpotUserList(*p))
	{
		return;
	}

	initUserList(p);
}


//打印
void printUserList(const UserList list) {
	if (judgeEmpotUserList(list))
	{
		return;
	}

	printf("%-7s%-10s%-10s%-10s%-10s %s\n", "用户ID", "用户密码", "用户姓名", "联系方式", "收件地址", "类型[1:商家/2:普通用户/3:送货员");
	UserNode* temp = list.head;

	while (temp != NULL)
	{
		printf("%-7d%-10s%-10s%-10s%-10s%15d\n", temp->user.userId, temp->user.passwd, temp->user.name, temp->user.phone, temp->user.address, temp->user.type);
		temp = temp->next;
	}
}



//注册
void registerUser(UserList* p) {
	int type = 1;
	printf("1.商家\n2.买家\n3.送货员\n请选择注册的用户类型:");
	User user = { 0 };
	scanf(" %d", &type);
	user.type = type;
	//买家
	if (type == 2)
	{
		printf("请输入用户ID:");
		scanf(" %d", &user.userId);

		printf("请输入用户密码:");
		scanf(" %s", user.passwd);

		printf("请输入姓名:");
		scanf(" %s", user.name);

		printf("请输入联系方式:");
		scanf(" %s", user.phone);

		printf("请输入收件地址:");
		scanf(" %s", user.address);
	}

	//商家
	if (type == 1)
	{
		printf("请输入用户ID:");
		scanf(" %d", &user.userId);

		printf("请输入用户密码:");
		scanf(" %s", user.passwd);

		printf("请输入店名:");
		scanf(" %s", user.name);

		printf("请输入联系方式:");
		scanf(" %s", user.phone);

		printf("请输入发货地址:");
		scanf(" %s", user.address);
	}

	if (type == 3)
	{
		printf("请输入用户ID:");
		scanf(" %d", &user.userId);

		printf("请输入用户密码:");
		scanf(" %s", user.passwd);

		printf("请输入姓名:");
		scanf(" %s", user.name);

		printf("请输入联系方式:");
		scanf(" %s", user.phone);
	}

	insertPositionUser(p, p->count + 1, user);
}


//登录
User* loginUser(const UserList list) {

	if (judgeEmpotUserList(list)) {
		return NULL;
	}

	User* temp = (User*)malloc(sizeof(User));

	printf("请输入ID:");
	scanf(" %d", &temp->userId);

	printf("请输入密码:");
	scanf(" %s", temp->passwd);

	User* user = searchUserById(list, temp->userId);

	if (user == NULL)
	{
		printf("登录失败，用户名不正确\n");
		return NULL;
	}

	if (strcmp(user->passwd, temp->passwd))
	{
		printf("登录失败，密码错误\n");
		return NULL;
	}

	return user;
}


//保存用户信息
void saveUserData(const UserList usreList) {
	FILE* file = fopen("../OrderProject/user.txt", "w");
	if (!file)
	{
		printf("文件打开失败\n");
		return;
	}

	UserNode* node = usreList.head;

	//循环遍历将每个用户写入文件
	while (node != NULL)
	{
		//保存用户ID、用户密码、用户姓名、联系方式、收件地址、用户类型
		fprintf(file, "%d\t%s\t\%s\t\%s\t\%s\t%d\t", 
			node->user.userId, node->user.passwd, node->user.name, node->user.phone, node->user.address, node->user.type);
		int i = 0;

		//保存用户的订单信息
		while (node->user.orderList[i]>0)
		{
			fprintf(file, "%d\t", node->user.orderList[i]);
			i++;
		}
		fprintf(file, "%d\t", 0);

		//保存商品信息
		int j = 0;
		while (node->user.goodsList[j]>0)
		{
			fprintf(file, "%d\t", node->user.goodsList[j]);
			j++;
		}
		fprintf(file, "%d\n", 0);

		//fprintf(file, "%d\t%d\n", node->user.orderList[i], node->user.goodsList[i]);
		//fprintf(file, "\n");
		
		node = node->next;
	}

	//printf("用户保存成功\n");

	//文件关闭
	fclose(file);
}


//读取用户信息
void getUserData(UserList* userList) {
	if (userList==NULL)
	{
		return;
	}
	FILE* file = fopen("../OrderProject/user.txt", "r");
	if (!file)
	{
		printf("文件打开失败\n");
		return;
	}

	User user = { 0 };

	fscanf(file, "%d\t%s\t\%s\t\%s\t\%s\t%d\t",
		&user.userId, user.passwd, user.name, user.phone, 
		user.address, &user.type);
	if (user.userId < 1)
	{
		printf("文件为空\n");
		return;
	}
	int i = 0;
	int j = 0;

	fscanf(file, "%d\t%d\t", &user.orderList[i], &user.goodsList[i]);
	while (user.orderList[i] > 0)
	{
		i++;
		fscanf(file, "%d\t", &user.orderList[i]);
	}
	while (user.goodsList[j] > 0)
	{
		j++;
		fscanf(file, "%d\t", &user.goodsList[j]);
	}
	fscanf(file, "\n");
	insertPositionUser(userList,1, user);

	//将文件内容读取出来
	while (!feof(file))
	{
		fscanf(file, "%d\t%s\t\%s\t\%s\t\%s\t%d\t",
			&user.userId, user.passwd, user.name, user.phone,
			user.address, &user.type);
		i = 0;

		fscanf(file, "%d\t", &user.orderList[i]);
		while (user.orderList[i] > 0)
		{
			i++;
			fscanf(file, "%d\t", &user.orderList[i]);
		}
		j = 0;
		fscanf(file, "%d\t", &user.goodsList[j]);
		while (user.goodsList[j] > 0)
		{
			j++;
			fscanf(file, "%d\t", &user.goodsList[j]);
		}
		fscanf(file, "\n");
		insertPositionUser(userList,  1, user);
	}


	//关闭文件
	fclose(file);
}