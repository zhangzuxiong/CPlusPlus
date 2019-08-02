
#include "Order.h"


//��ʼ��
void initOrderList(OrderList* p) {
	//ָ���п�
	if (p == NULL)
	{
		//printf("��ʼ������Ϊ��\n");
		return;
	}

	//��ʱָ����������ͷ�˫������֮ǰ���ڵĿռ�
	OrderNode* temp = p->head;
	while (p->head != NULL)
	{
		//��ͷ�����ƶ�һ��
		p->head = temp->next;

		//�ͷſռ�
		free(temp);

		//ָ����һ���ͷŵĿռ�
		temp = p->head;
	}

	//βָ����λNULL
	p->tail = NULL;

	//��ЧԪ����λ0
	p->count = 0;

}


//�п�
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


//���룬�ڵ�position��λ�ò���һ���û�
int insertPositionOrder(OrderList* p, const const int position, const Order order) {
	if (p == NULL)
	{
		//printf("����˫����Ĳ���Ϊ��\n");
		return 0;
	}

	if (position < 1 || position > p->count + 1)
	{
		//printf("����λ�ò�����\n");
		return 0;
	}

	//�²���Ľڵ�
	OrderNode* node = (OrderNode*)malloc(sizeof(OrderNode));
	node->order = order;

	//����Ϊ��
	if (p->count == 0)
	{
		//�½ڵ����ͷ���Ҳ��β���
		p->head = node;
		p->tail = node;

		//ͷ������һ����β����ǰһ����ΪNULL
		p->head->next = NULL;
		p->tail->pre = NULL;
	}
	//����ǿգ���ͷ��β����
	else if (p->count != 0 && (position == 1 || position == p->count + 1))
	{
		//��ͷ����
		if (position == 1)
		{
			//�½ڵ����һ���ڵ�Ϊͷ���
			node->next = p->head;

			//�½ڵ��ǰһ���ڵ���ͷ����ǰһ���ڵ㣨NULL��
			node->pre = p->head->pre;

			//ͷ�ڵ��ǰһ���ڵ����½ڵ�
			p->head->pre = node;

			//���½ڵ�����Ϊ�µ�ͷ���
			p->head = node;
		}
		//��β����
		else
		{
			//�½ڵ����һ���ڵ�Ϊβ������һ���ڵ㣨NULL��
			node->next = p->tail->next;

			//�½ڵ��ǰһ���ڵ���β���
			node->pre = p->tail;

			//β������һ���ڵ����½ڵ�
			p->tail->next = node;

			//���½ڵ�����Ϊ�µ�β���
			p->tail = node;
		}
	}
	//���м����
	else
	{
		//��¼�����λ��
		OrderNode* index = p->head;

		//ѭ�����������ҵ������λ��
		int i = 1;
		while (i < position)
		{
			index = index->next;
			i++;
		}
		//�ȸı�next����Ϊ2��
		//1.�½ڵ����һ��ָ��index��λ��
		node->next = index;

		//2.����λ�õ�ǰһ��ָ���½ڵ�
		index->pre->next = node;


		//�ٸı�pre,��Ϊ2��
		//1.�½ڵ��ǰһ��ָ�����ڵ��ǰһ��
		node->pre = index->pre;

		//2.����λ�õ�ǰһ��ָ���½ڵ�
		index->pre = node;
	}

	//��ЧԪ�ؼ�1
	p->count++;

	return 1;
}


//ɾ��--����Idɾ��
Order* deleteOrderById(OrderList* p, const int Id) {
	if (p == NULL)
	{
		//printf("ɾ������Ϊ��\n");
		return 0;
	}

	if (judgeEmpotOrderList(*p))
	{
		//printf("˫������Ϊ��,�޷�ɾ��\n");
		return 0;
	}
	//��¼ɾ����λ��
	OrderNode* index = p->head;

	//����ɾ��������
	Order* res = (Order*)malloc(sizeof(Order));

	//ֻ��һ��Ԫ��
	if (p->count == 1)
	{
		*res = index->order;

		//�ͷſռ�
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

				//�½ڵ��ǰһ���ڵ���λNULL
				p->head->pre = NULL;

			}
			else if (index->next == NULL)
			{
				p->tail = p->tail->pre;

				//��ĩβ��ǰһ����next��λNULL��Ȼ���ͷ�ԭ�����ĩβ�ڵ�
				free(p->tail->next);
				p->tail->next = NULL;
			}
			else
			{
				index->pre->next = index->next;
				index->next->pre = index->pre;

				free(index);
			}

			//��ЧԪ�ؼ�1
			p->count--;
			return res;
		}
		index = index->next;
	}

	printf("û���ҵ�ɾ����Id\n");
	return NULL;
}


//����λ��ɾ��
Order* deletePositionOrderList(OrderList* p, const int position) {
	if (p == NULL)
	{
		//printf("ɾ������Ϊ��\n");
		return 0;
	}

	if (judgeEmpotOrderList(*p))
	{
		//printf("˫������Ϊ��,�޷�ɾ��\n");
		return 0;
	}

	if (position < 1 || position > p->count)
	{
		//printf("ɾ����λ�ò�����\n");
		return 0;
	}

	//��¼ɾ����λ��
	OrderNode* index = p->head;

	//����ɾ��������
	Order* res = (Order*)malloc(sizeof(Order));

	//˫����ֻ��һ��Ԫ�أ�ֱ���ͷ�ͷ��ͷβ��NULL
	if (p->count == 1)
	{
		*res = p->head->order;

		//�ͷſռ�
		free(p->head);
		p->head = NULL;
		p->tail = NULL;
	}
	//ɾ��֮�󲻿գ�����ɾ����λ���ڵ�һ��
	else if (position == 1 && p->count > 1)
	{
		*res = p->head->order;

		//��head����ƶ�һ��
		p->head = index->next;

		free(index);

		index = NULL;

		//�½ڵ��ǰһ���ڵ���λNULL
		p->head->pre = NULL;
	}
	//ɾ�����һ��������˫������ЧԪ�ش���1��
	else if (position == p->count && p->count > 1)
	{
		*res = p->tail->order;

		//��tail��ǰ�ƶ�һ��
		p->tail = p->tail->pre;

		//��ĩβ��ǰһ����next��λNULL��Ȼ���ͷ�ԭ�����ĩβ�ڵ�
		free(p->tail->next);
		p->tail->next = NULL;
	}
	//ɾ�����м�
	else
	{
		//ѭ�����������ҵ�ɾ����λ��
		int i = 1;
		while (i < position)
		{
			index = index->next;
			i++;
		}
		*res = index->order;

		//��ǰɾ���ڵ��ǰһ���ڵ�nextָ��ɾ���ڵ��next
		index->pre->next = index->next;

		//��ǰɾ���ڵ�next��preָ��index��pre
		index->next->pre = index->pre;

		//�ͷſռ�
		free(index);
	}

	//��ЧԪ�ؼ�1
	p->count--;
	printf("ɾ���ɹ�\n");
	return res;
}


//����--����ֵ��ѯ���ز����û�
Order* searchOrderById(const OrderList list, const int orderId) {
	if (judgeEmpotOrderList(list))
	{
		printf("˫�����Ѿ�Ϊ�գ����ܲ���\n");
		return NULL;
	}

	//��ʱָ����������ҵ��ĵ�ַ
	OrderNode* temp = list.head;

	while (temp != NULL)
	{
		if (temp->order.orderId == orderId)
		{
			return &(temp->order);
		}
		//ָ����һ�����ҵ�λ��
		temp = temp->next;
	}
	printf("û���ҵ�\n");
	return NULL;
}

//���
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

//��ӡһ������
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

//��ӡ
void printOrderList(const UserList userList,const GoodsList goodsList,const OrderList list) {
	if (judgeEmpotOrderList(list)||judgeEmpotGoodsList(goodsList)||judgeEmpotUserList(userList))
	{
		return;
	}

	//printf("\t%-10s%-10s%-10s%-10s\n", "����ID", "��Ʒ����", "��Ʒ�۸�", "���");
	OrderNode* temp = list.head;
	User buyer = { 0 };
	User bussiness = { 0 };
	Goods goods = { 0 };


	while (temp != NULL)
	{
		buyer = *searchUserById(userList, temp->order.userId);
		bussiness = *searchUserById(userList, temp->order.businessId);
		/*printf("����ID:%d,�û�����:%s,�̼�:%s,�µ�ʱ��:%s\n",temp->order.orderId,
			buyer.name,bussiness.name,temp->order.createDate);*/

		printOrder(userList, temp->order);

		int i = 0;
		while (temp->order.goodsId[i]>0)
		{
			printGoodsInfo(*searchGoodsById(goodsList, temp->order.goodsId[i]));
			printf(",��%d��\n", temp->order.count[i++]);
		}

		printf("\n\n");
		//printf("\t%-10d\n", temp->order.orderId);
		temp = temp->next;
	}
}


//��ӡһ������
void printOrder(const UserList userList, const Order order) {
	User buyer = *searchUserById(userList, order.userId);
	User bussiness = *searchUserById(userList, order.businessId);
	printf("����ID:%d,�������:%s,�����ϵ�绰:%s,�ռ���ַ:%s,�̼�����:%s,�̼���ϵ�绰:%s,������ַ:%s,�µ�ʱ��:%s\n", 
		order.orderId, buyer.name,buyer.phone,buyer.address, bussiness.name,bussiness.phone,bussiness.address, order.createDate);
}


//���涩����Ϣ
void saveOrderInfo(const OrderList list) {
	FILE* file = fopen("../OrderProject/order.txt", "w");
	if (!file)
	{
		printf("�ļ���ʧ��\n");
		return;
	}

	OrderNode* node = list.head;

	//ѭ��������ÿ������д���ļ�
	while (node != NULL)
	{
		//���涩��ID���û�ID���̼�ID���µ�ʱ�䡢״̬
		fprintf(file, "%d\t%d\t\%d\t\%s\t%d\t",
			node->order.orderId, node->order.userId, node->order.businessId,
			node->order.createDate, node->order.status);
		int i = 0;

		//������Ʒ��Ϣ
		while (node->order.goodsId[i] > 0)
		{
			fprintf(file, "%d\t%d\t", node->order.goodsId[i],node->order.count[i]);
			i++;
		}
		fprintf(file, "%d\t%d\n", 0,0);


		node = node->next;
	}

	//printf("��Ʒ����ɹ�\n");

	//�ļ��ر�
	fclose(file);
}

//��ȡ������Ϣ
void getOrderInfo(OrderList* p) {
	if (p==NULL)
	{
		return;
	}

	FILE* file = fopen("../OrderProject/order.txt", "r");
	if (!file)
	{
		printf("�ļ���ʧ��\n");
		return;
	}

	Order order = { 0 };

	fscanf(file, "%d\t%d\t\%d\t\%s\t%d\t",
		&order.orderId, &order.userId, &order.businessId,
		order.createDate, &order.status);
	if (order.userId < 1)
	{
		printf("�ļ�Ϊ��\n");
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

	//���ļ����ݶ�ȡ����
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

	//�ر��ļ�
	fclose(file);
}