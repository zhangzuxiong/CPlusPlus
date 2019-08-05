
#include "Goods.h"


//��ʼ��
void initGoodsList(GoodsList* p) {
	//ָ���п�
	if (p == NULL)
	{
		//printf("��ʼ������Ϊ��\n");
		return;
	}

	//��ʱָ����������ͷ�˫������֮ǰ���ڵĿռ�
	GoodsNode* temp = p->head;
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


//���룬�ڵ�position��λ�ò���һ���û�
int insertPositionGoods(GoodsList* p, const const int position, const Goods goods) {
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
	GoodsNode* node = (GoodsNode*)malloc(sizeof(GoodsNode));
	node->goods = goods;

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
		GoodsNode* index = p->head;

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
Goods* deleteGoodsById(GoodsList* p, const int Id) {
	if (p == NULL)
	{
		//printf("ɾ������Ϊ��\n");
		return 0;
	}

	if (judgeEmpotGoodsList(*p))
	{
		//printf("˫������Ϊ��,�޷�ɾ��\n");
		return 0;
	}
	//��¼ɾ����λ��
	GoodsNode* index = p->head;

	//����ɾ��������
	Goods* res = (Goods*)malloc(sizeof(Goods));

	//ֻ��һ��Ԫ��
	if (p->count == 1)
	{
		*res = index->goods;

		//�ͷſռ�
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



//����--����ֵ��ѯ���ز����û�
Goods* searchGoodsById(const GoodsList list, const int goodsId) {
	if (judgeEmpotGoodsList(list))
	{
		printf("˫�����Ѿ�Ϊ�գ����ܲ���\n");
		return NULL;
	}

	//��ʱָ����������ҵ��ĵ�ַ
	GoodsNode* temp = list.head;

	while (temp != NULL)
	{
		if (temp->goods.goodsId == goodsId)
		{
			return &(temp->goods);
		}
		//ָ����һ�����ҵ�λ��
		temp = temp->next;
	}
	printf("û���ҵ�\n");
	return NULL;
}

//���
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


//��ӡ����
void printGoodsrList(const GoodsList list) {
	if (judgeEmpotGoodsList(list))
	{
		return;
	}

	printf("\t%-10s%-10s%-10s%-10s\n", "��ƷID", "��Ʒ����", "��Ʒ�۸�", "���");
	GoodsNode* temp = list.head;

	while (temp != NULL)
	{
		printf("\t%-10d%-10s%-10d%-10d\n", temp->goods.goodsId, temp->goods.name, temp->goods.price, temp->goods.stock);
		temp = temp->next;
	}
}


//��ӡ������Ʒ��Ϣ
void printGoodsInfo(const Goods goods) {
	printf("��ƷId:%d,��Ʒ����:%s,��Ʒ�۸�:%d,���:%d", goods.goodsId, goods.name, goods.price, goods.stock);
}


//����Ʒ��Ϣ���浽�ļ�
void saveGoods(const GoodsList list) {
	FILE* file = fopen("../project/goods.txt", "w");
	if (!file)
	{
		printf("�ļ���ʧ��\n");
		return;
	}

	//������Ʒ�Ľڵ�
	GoodsNode* node = list.head;

	//ѭ��������ÿһ����Ʒд���ļ�
	while (node != NULL)
	{
		fprintf(file, "%d\t%s\t\%d\t%d\n", node->goods.goodsId, node->goods.name, node->goods.price, node->goods.stock);
		node = node->next;
	}

	printf("��Ʒ����ɹ�\n");

	//�ļ��ر�
	fclose(file);
}


//���ļ��е���Ʒ��ȡ������
void getGoodsData(GoodsList* p) {
	FILE* file = fopen("../project/goods.txt", "r");
	if (!file)
	{
		printf("�ļ���ʧ��\n");
		return;
	}

	Goods goods = { 0 };

	fscanf(file, "%d\t%s\t\%d\t%d\n", &goods.goodsId, goods.name, &goods.price, &goods.stock);
	if (goods.goodsId < 1)
	{
		printf("�ļ�Ϊ��\n");
		return;
	}

	//���ļ����ݶ�ȡ����
	while (!feof(file))
	{

		insertPositionGoods(p, 1, goods);
		fscanf(file, "%d\t%s\t\%d\t%d\n", &goods.goodsId, goods.name, &goods.price, &goods.stock);

	}


	//�ر��ļ�
	fclose(file);
}