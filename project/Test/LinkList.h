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

	//��ʼ��
	LinkList();

	//��������
	~LinkList();



	//��������
	LinkList(const LinkList& that) :head(NULL),tail(NULL),count(0){
		Node<T>* temp = that.head;
		while (temp!=NULL)
		{
			T t = temp->getData();
			this->add(this->size()+1,t);
			temp = temp->getNext();
		}
	}



	//�п�
	bool isEmpoty() const;




	//�ڵ�index��λ�ò�������data
	bool add(const int index, const T& data);



	//��ӡ����
	void print() const;




	//���
	bool clear();




	//ɾ��--����λ��ɾ��,����ɾ��������
	T* remove(const int index);




	//���� flase:����ʧ��,true:���ҳɹ�
	bool search(const T& data)const;




	//��������Ĵ�С
	int size() const;
};


