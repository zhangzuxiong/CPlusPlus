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

	/*Node(const Node& that) :data(NULL), pre(NULL), next(NULL) {
		this->data = that.data;
		this->pre = new Node;
		this->pre = NULL;
		this->next = new Node;
		this->next = NULL;
		if (that.pre!=NULL)
		{
			*(this->pre) = *(that.pre);
		}
		if (that.next!=NULL)
		{
			*(this->next) = *(that.next);
		}
	}*/

	~Node() {
		/*delete pre;
		delete next;
		pre = NULL;
		next = NULL;*/
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
	LinkList();

	//析构函数
	~LinkList();



	//拷贝构造
	LinkList(const LinkList& that) :head(NULL),tail(NULL),count(0){
		Node<T>* temp = that.head;
		while (temp!=NULL)
		{
			T t = temp->getData();
			this->add(this->size()+1,t);
			temp = temp->getNext();
		}
	}



	//判空
	bool isEmpoty() const;




	//在地index个位置插入数据data
	bool add(const int index, const T& data);



	//打印所有
	void print() const;




	//清空
	bool clear();




	//删除--根据位置删除,返回删除的数据
	T* remove(const int index);




	//查找 flase:查找失败,true:查找成功
	bool search(const T& data)const;




	//返回链表的大小
	int size() const;
};


