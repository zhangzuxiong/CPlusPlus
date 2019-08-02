
#include "User.h"


//��ʼ��
void initUserList(UserList* p) {
	//ָ���п�
	if (p == NULL)
	{
		//printf("��ʼ������Ϊ��\n");
		return;
	}

	//��ʱָ����������ͷ�˫������֮ǰ���ڵĿռ�
	UserNode* temp = p->head;
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


//���룬�ڵ�position��λ�ò���һ���û�
int insertPositionUser(UserList* p, const const int position, const User user) {
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
	UserNode* node = (UserNode*)malloc(sizeof(UserNode));
	node->user = user;

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
		UserNode* index = p->head;

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
User* deleteUserById(UserList* p, const int Id) {
	if (p == NULL)
	{
		//printf("ɾ������Ϊ��\n");
		return 0;
	}

	if (judgeEmpotUserList(*p))
	{
		//printf("˫������Ϊ��,�޷�ɾ��\n");
		return 0;
	}

	//��¼ɾ����λ��
	UserNode* index = p->head;

	//����ɾ��������
	User* res = (User*)malloc(sizeof(User));

	//ֻ��һ��Ԫ��
	if (p->count == 1)
	{
		*res = index->user;

		//�ͷſռ�
		free(p->head);
		p->head = NULL;
		p->tail = NULL;
	}

	while (index != NULL)
	{
		if (index->user.userId == Id)
		{
			*res = index->user;

			//ɾ����һ��
			if (index->pre == NULL)
			{
				p->head = index->next;

				free(index);

				index = NULL;

				//�½ڵ��ǰһ���ڵ���λNULL
				p->head->pre = NULL;

			}
			//ɾ������һ��
			else if (index->next == NULL)
			{
				p->tail = p->tail->pre;

				//��ĩβ��ǰһ����next��λNULL��Ȼ���ͷ�ԭ�����ĩβ�ڵ�
				free(p->tail->next);
				p->tail->next = NULL;
			}

			//ɾ���м�
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

	//printf("û���ҵ�ɾ����Id\n");
	return NULL;
}



//����--����ֵ��ѯ���ز����û�
User* searchUserById(const UserList list, const int userId) {
	if (judgeEmpotUserList(list))
	{
		//printf("˫�����Ѿ�Ϊ�գ����ܲ���\n");
		return NULL;
	}

	//��ʱָ����������ҵ��ĵ�ַ
	UserNode* temp = list.head;

	while (temp != NULL)
	{
		if (temp->user.userId == userId)
		{
			return &(temp->user);
		}
		//ָ����һ�����ҵ�λ��
		temp = temp->next;
	}
	//printf("û���ҵ�\n");
	return NULL;
}

//���
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


//��ӡ
void printUserList(const UserList list) {
	if (judgeEmpotUserList(list))
	{
		return;
	}

	printf("%-7s%-10s%-10s%-10s%-10s %s\n", "�û�ID", "�û�����", "�û�����", "��ϵ��ʽ", "�ռ���ַ", "����[1:�̼�/2:��ͨ�û�/3:�ͻ�Ա");
	UserNode* temp = list.head;

	while (temp != NULL)
	{
		printf("%-7d%-10s%-10s%-10s%-10s%15d\n", temp->user.userId, temp->user.passwd, temp->user.name, temp->user.phone, temp->user.address, temp->user.type);
		temp = temp->next;
	}
}



//ע��
void registerUser(UserList* p) {
	int type = 1;
	printf("1.�̼�\n2.���\n3.�ͻ�Ա\n��ѡ��ע����û�����:");
	User user = { 0 };
	scanf(" %d", &type);
	user.type = type;
	//���
	if (type == 2)
	{
		printf("�������û�ID:");
		scanf(" %d", &user.userId);

		printf("�������û�����:");
		scanf(" %s", user.passwd);

		printf("����������:");
		scanf(" %s", user.name);

		printf("��������ϵ��ʽ:");
		scanf(" %s", user.phone);

		printf("�������ռ���ַ:");
		scanf(" %s", user.address);
	}

	//�̼�
	if (type == 1)
	{
		printf("�������û�ID:");
		scanf(" %d", &user.userId);

		printf("�������û�����:");
		scanf(" %s", user.passwd);

		printf("���������:");
		scanf(" %s", user.name);

		printf("��������ϵ��ʽ:");
		scanf(" %s", user.phone);

		printf("�����뷢����ַ:");
		scanf(" %s", user.address);
	}

	if (type == 3)
	{
		printf("�������û�ID:");
		scanf(" %d", &user.userId);

		printf("�������û�����:");
		scanf(" %s", user.passwd);

		printf("����������:");
		scanf(" %s", user.name);

		printf("��������ϵ��ʽ:");
		scanf(" %s", user.phone);
	}

	insertPositionUser(p, p->count + 1, user);
}


//��¼
User* loginUser(const UserList list) {

	if (judgeEmpotUserList(list)) {
		return NULL;
	}

	User* temp = (User*)malloc(sizeof(User));

	printf("������ID:");
	scanf(" %d", &temp->userId);

	printf("����������:");
	scanf(" %s", temp->passwd);

	User* user = searchUserById(list, temp->userId);

	if (user == NULL)
	{
		printf("��¼ʧ�ܣ��û�������ȷ\n");
		return NULL;
	}

	if (strcmp(user->passwd, temp->passwd))
	{
		printf("��¼ʧ�ܣ��������\n");
		return NULL;
	}

	return user;
}


//�����û���Ϣ
void saveUserData(const UserList usreList) {
	FILE* file = fopen("../OrderProject/user.txt", "w");
	if (!file)
	{
		printf("�ļ���ʧ��\n");
		return;
	}

	UserNode* node = usreList.head;

	//ѭ��������ÿ���û�д���ļ�
	while (node != NULL)
	{
		//�����û�ID���û����롢�û���������ϵ��ʽ���ռ���ַ���û�����
		fprintf(file, "%d\t%s\t\%s\t\%s\t\%s\t%d\t", 
			node->user.userId, node->user.passwd, node->user.name, node->user.phone, node->user.address, node->user.type);
		int i = 0;

		//�����û��Ķ�����Ϣ
		while (node->user.orderList[i]>0)
		{
			fprintf(file, "%d\t", node->user.orderList[i]);
			i++;
		}
		fprintf(file, "%d\t", 0);

		//������Ʒ��Ϣ
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

	//printf("�û�����ɹ�\n");

	//�ļ��ر�
	fclose(file);
}


//��ȡ�û���Ϣ
void getUserData(UserList* userList) {
	if (userList==NULL)
	{
		return;
	}
	FILE* file = fopen("../OrderProject/user.txt", "r");
	if (!file)
	{
		printf("�ļ���ʧ��\n");
		return;
	}

	User user = { 0 };

	fscanf(file, "%d\t%s\t\%s\t\%s\t\%s\t%d\t",
		&user.userId, user.passwd, user.name, user.phone, 
		user.address, &user.type);
	if (user.userId < 1)
	{
		printf("�ļ�Ϊ��\n");
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

	//���ļ����ݶ�ȡ����
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


	//�ر��ļ�
	fclose(file);
}