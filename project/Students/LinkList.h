#pragma once

#include <iostream>

using namespace std;


template <class T>
class Node {
private:
	T data;

	Node* pre;

	Node* next;

public:
	Node() {
		this->pre = NULL;
		this->next = NULL;
		this->data = NULL;
	}

	Node(T data, Node* pre, Node* next) {
		this->data = data;
		this->pre = pre;
		this->next = next;
	}

	T getData() const {
		return this->data;
	}

	Node* getPre() const {
		return this->pre;
	}

	Node* getNext() const {
		return this->next;
	}

	void setData(T data) {
		this->data = data;
	}

	void setPre(Node* pre) {
		this->pre = pre;
	}

	void setNext(Node* next) {
		this->next = next;
	}

};


template <class T>
class LinkList {
private:
	Node<T>* head;

	Node<T>* tail;

	int count;

public:

	//��ʼ��
	LinkList() {
		Node<T>* temp = this->head;

		while (this->head != NULL)
		{
			//��ͷ�����ƶ�һ��
			this->head = temp->getNext();

			//�ͷſռ�
			delete temp;

			//ָ����һ���ͷŵĿռ�
			temp = this->head;
		}

		//βָ����λNULL
		this->tail = NULL;
		this->count = 0;
	}

	//��������
	~LinkList() {
		this->clear();
	}


	//�п�
	bool isEmpoty() const;




	//�ڵ�index��λ�ò�������data
	bool add(const int index, const T data);



	//��ӡ����
	void print() const;




	//���
	bool clear();




	//ɾ��--����λ��ɾ��,����ɾ��������
	T* remove(const int index);




	//���� flase:����ʧ��,true:���ҳɹ�
	bool search(const T data)const;




	//��������Ĵ�С
	int size() const;
};






//
//template <class T>
//bool LinkList<T>::isEmpoty() const {
//	if (this->count == 0)
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}
//
//
//
//
//template <class T>
//bool LinkList<T>::add(const int index, const T data) {
//
//	if (index < 1 || index > this->count + 1)
//	{
//		cout << "����λ�ò���ȷ" << endl;
//		return false;
//	}
//
//	//�²���Ľڵ�
//	Node<T>* node = new Node<T>;
//	node->setData(data);
//
//	//����Ϊ��
//	if (this->count == 0)
//	{
//		//�½ڵ����ͷ���Ҳ��β���
//		this->head = node;
//		this->tail = node;
//
//		//ͷ������һ����β����ǰһ����ΪNULL
//		this->head->setNext(NULL);
//		this->tail->setPre(NULL);
//	}
//	//����ǿգ���ͷ��β����
//	else if (this->count != 0 && (index == 1 || index == this->count + 1))
//	{
//		//��ͷ����
//		if (index == 1)
//		{
//			//�½ڵ����һ���ڵ�Ϊͷ���
//			node->setNext(this->head);
//
//			//�½ڵ��ǰһ���ڵ���ͷ����ǰһ���ڵ㣨NULL��
//			node->setPre(this->head->getPre());
//
//			//ͷ�ڵ��ǰһ���ڵ����½ڵ�
//			this->head->setPre(node);
//
//			//���½ڵ�����Ϊ�µ�ͷ���
//			this->head = node;
//		}
//		//��β����
//		else
//		{
//			//�½ڵ����һ���ڵ�Ϊβ������һ���ڵ㣨NULL��
//			node->setNext(this->tail->getNext());
//
//			//�½ڵ��ǰһ���ڵ���β���
//			node->setPre(this->tail);
//
//			//β������һ���ڵ����½ڵ�
//			this->tail->setNext(node);
//
//			//���½ڵ�����Ϊ�µ�β���
//			this->tail = node;
//		}
//	}
//	//���м����
//	else
//	{
//		//��¼�����λ��
//		Node<T>* temp = this->head;
//
//		//ѭ�����������ҵ������λ��
//		int i = 1;
//		while (i < index)
//		{
//			temp = temp->getNext();
//			i++;
//		}
//		//�ȸı�next����Ϊ2��
//		//1.�½ڵ����һ��ָ��index��λ��
//		node->setNext(temp);
//
//		//2.����λ�õ�ǰһ��ָ���½ڵ�
//		temp->getPre()->setNext(node);
//
//
//		//�ٸı�pre,��Ϊ2��
//		//1.�½ڵ��ǰһ��ָ�����ڵ��ǰһ��
//		node->setPre(temp->getPre());
//
//		//2.����λ�õ�ǰһ��ָ���½ڵ�
//		temp->setPre(node);
//	}
//
//	//��ЧԪ�ؼ�1
//	this->count++;
//
//	return true;
//}
//
//
//
//
//template <class T>
//void LinkList<T>::print() const {
//	Node<T>* temp = this->head;
//
//	while (temp != NULL)
//	{
//		cout << temp->getData();
//		temp = temp->getNext();
//	}
//}
//
//
//
//
//template <class T>
//bool LinkList<T>::clear() {
//
//	if (this->isEmpoty())
//	{
//		return true;
//	}
//
//	Node<T>* temp = this->head;
//
//	while (this->head != NULL)
//	{
//		//��ͷ�����ƶ�һ��
//		this->head = temp->getNext();
//
//		//�ͷſռ�
//		delete temp;
//
//		//ָ����һ���ͷŵĿռ�
//		temp = this->head;
//	}
//
//	//βָ����λNULL
//	this->tail = NULL;
//	this->count = 0;
//	return true;
//}
//
//
//
//template <class T>
//T* LinkList<T>::remove(const int index) {
//	if (this->isEmpoty())
//	{
//		//printf("˫������Ϊ��,�޷�ɾ��\n");
//		return NULL;
//	}
//
//
//	if (index < 1 || index > this->count)
//	{
//		cout << "ɾ��λ�ò���ȷ" << endl;
//
//		return NULL;
//	}
//
//	// ��Ҫʹ����ʱ��������ɾ��������
//	T* res = new T;
//
//	if (this->count == 1)
//	{
//		// ��¼����ֵ
//		*res = this->head->getData();
//
//		// ��Ϊֻ��Ψһһ����㣬��ôֱ���ͷ�
//		delete this->head;
//
//		// ͷβָ��ȫ�� �ÿ�
//		this->head = NULL;
//		this->tail = NULL;
//	}
//	else if (this->count > 1 && (index == 1 || index == this->count))
//	{
//		// ͷβ������������
//		if (index == 1)
//		{
//			// ��¼����ֵ
//			*res = this->head->getData();
//
//			Node<T>* temp = this->head;
//
//			// �� head ���Ų��һ��ָ��ԭ˫����ĵڶ������ĵ�ַ
//			this->head = this->head->getNext();
//
//			// �� ��˫����ĵ�һ��������ǰָ�� �ÿ�
//			this->head->setPre(NULL);
//
//			// �ͷ� ԭ˫����ĵ�һ�������ڴ�ռ�
//			delete temp;
//
//			temp = NULL;
//		}
//		else
//		{
//			// ��¼����ֵ
//			*res = this->tail->getData();
//
//			// �� tail ��ǰŲ��һ��ָ��ԭ˫����ĵ����ڶ������ĵ�ַ
//			this->tail = this->tail->getPre();
//
//			// �� tail ����ָ������ ��˫��������һ���������ָ�� ��ָ��� ���ռ��ͷŵ�
//			delete this->tail->getNext();
//
//			// �� tail ��ָ��Ľ��� next ָ�� �ÿ�
//			this->tail->setNext(NULL);
//		}
//	}
//	else
//	{
//		// ����ѭ����������λ
//		int i = 0;
//
//		// ����ʱָ����� temp ����λ���Ŀռ��ַ
//		Node<T>* temp = this->head;
//
//		while (i < index - 1)
//		{
//			// ��λָ����� ���Ų��һ��
//			temp = temp->getNext();
//
//			// �ۼƴ���
//			i++;
//		}
//
//		temp->getPre()->setNext(temp->getNext());
//
//		temp->getNext()->setPre(temp->getPre());
//
//		// ������Ҫ���ص���ֵ
//		*res = temp->getData();
//
//		delete temp;
//	}
//
//	// ��Ч���Ԫ�صĸ��� -1
//	this->count--;
//
//	return res;
//}
//
//
//
//
//template <class T>
//bool LinkList<T>::search(const T data)const {
//	if (this->isEmpoty())
//	{
//		return false;
//	}
//
//	Node<T>* node = this->head;
//
//	while (node != NULL)
//	{
//		if (node->getData() == data)
//		{
//			return true;
//		}
//		node = node->getNext();
//	}
//
//	return false;
//}
//
//
//
//
//template <class T>
//int LinkList<T>::size()const {
//	return this->count;
//}
//
