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

	//初始化
	LinkList() {
		Node<T>* temp = this->head;

		while (this->head != NULL)
		{
			//把头往后移动一个
			this->head = temp->getNext();

			//释放空间
			delete temp;

			//指向下一个释放的空间
			temp = this->head;
		}

		//尾指针置位NULL
		this->tail = NULL;
		this->count = 0;
	}

	//析构函数
	~LinkList() {
		this->clear();
	}


	//判空
	bool isEmpoty() const;




	//在地index个位置插入数据data
	bool add(const int index, const T data);



	//打印所有
	void print() const;




	//清空
	bool clear();




	//删除--根据位置删除,返回删除的数据
	T* remove(const int index);




	//查找 flase:查找失败,true:查找成功
	bool search(const T data)const;




	//返回链表的大小
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
//		cout << "插入位置不正确" << endl;
//		return false;
//	}
//
//	//新插入的节点
//	Node<T>* node = new Node<T>;
//	node->setData(data);
//
//	//链表为空
//	if (this->count == 0)
//	{
//		//新节点既是头结点也是尾结点
//		this->head = node;
//		this->tail = node;
//
//		//头结点的下一个和尾结点的前一个置为NULL
//		this->head->setNext(NULL);
//		this->tail->setPre(NULL);
//	}
//	//链表非空，在头或尾插入
//	else if (this->count != 0 && (index == 1 || index == this->count + 1))
//	{
//		//在头插入
//		if (index == 1)
//		{
//			//新节点的下一个节点为头结点
//			node->setNext(this->head);
//
//			//新节点的前一个节点是头结点的前一个节点（NULL）
//			node->setPre(this->head->getPre());
//
//			//头节点的前一个节点是新节点
//			this->head->setPre(node);
//
//			//将新节点设置为新的头结点
//			this->head = node;
//		}
//		//在尾插入
//		else
//		{
//			//新节点的下一个节点为尾结点的下一个节点（NULL）
//			node->setNext(this->tail->getNext());
//
//			//新节点的前一个节点是尾结点
//			node->setPre(this->tail);
//
//			//尾结点的下一个节点是新节点
//			this->tail->setNext(node);
//
//			//将新节点设置为新的尾结点
//			this->tail = node;
//		}
//	}
//	//在中间插入
//	else
//	{
//		//记录插入的位置
//		Node<T>* temp = this->head;
//
//		//循环计数器，找到插入的位置
//		int i = 1;
//		while (i < index)
//		{
//			temp = temp->getNext();
//			i++;
//		}
//		//先改变next，分为2步
//		//1.新节点的下一个指向index的位置
//		node->setNext(temp);
//
//		//2.插入位置的前一个指向新节点
//		temp->getPre()->setNext(node);
//
//
//		//再改变pre,分为2步
//		//1.新节点的前一个指向插入节点的前一个
//		node->setPre(temp->getPre());
//
//		//2.插入位置的前一个指向新节点
//		temp->setPre(node);
//	}
//
//	//有效元素加1
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
//		//把头往后移动一个
//		this->head = temp->getNext();
//
//		//释放空间
//		delete temp;
//
//		//指向下一个释放的空间
//		temp = this->head;
//	}
//
//	//尾指针置位NULL
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
//		//printf("双向链表为空,无法删除\n");
//		return NULL;
//	}
//
//
//	if (index < 1 || index > this->count)
//	{
//		cout << "删除位置不正确" << endl;
//
//		return NULL;
//	}
//
//	// 需要使用临时变量保存删除的数据
//	T* res = new T;
//
//	if (this->count == 1)
//	{
//		// 记录返回值
//		*res = this->head->getData();
//
//		// 因为只有唯一一个结点，那么直接释放
//		delete this->head;
//
//		// 头尾指针全部 置空
//		this->head = NULL;
//		this->tail = NULL;
//	}
//	else if (this->count > 1 && (index == 1 || index == this->count))
//	{
//		// 头尾操作进行区分
//		if (index == 1)
//		{
//			// 记录返回值
//			*res = this->head->getData();
//
//			Node<T>* temp = this->head;
//
//			// 将 head 向后挪动一格，指向原双链表的第二个结点的地址
//			this->head = this->head->getNext();
//
//			// 将 新双链表的第一个结点的向前指针 置空
//			this->head->setPre(NULL);
//
//			// 释放 原双链表的第一个结点的内存空间
//			delete temp;
//
//			temp = NULL;
//		}
//		else
//		{
//			// 记录返回值
//			*res = this->tail->getData();
//
//			// 将 tail 向前挪动一格，指向原双链表的倒数第二个结点的地址
//			this->tail = this->tail->getPre();
//
//			// 将 tail 现在指向的这个 新双链表的最后一个结点的向后指针 所指向的 结点空间释放掉
//			delete this->tail->getNext();
//
//			// 将 tail 所指向的结点的 next 指针 置空
//			this->tail->setNext(NULL);
//		}
//	}
//	else
//	{
//		// 利用循环遍历来定位
//		int i = 0;
//
//		// 用临时指针变量 temp 来定位结点的空间地址
//		Node<T>* temp = this->head;
//
//		while (i < index - 1)
//		{
//			// 定位指针变量 向后挪动一格
//			temp = temp->getNext();
//
//			// 累计次数
//			i++;
//		}
//
//		temp->getPre()->setNext(temp->getNext());
//
//		temp->getNext()->setPre(temp->getPre());
//
//		// 保存需要返回的数值
//		*res = temp->getData();
//
//		delete temp;
//	}
//
//	// 有效结点元素的个数 -1
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
