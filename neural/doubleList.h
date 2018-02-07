#pragma once
#include "stdafx.h"

/*���������, ����������� ���� ������*/
template <typename T>
struct node {
	T value;			//�������� � ����
	node<T>* next;			//��������� �� ��������� ����
	node<T>* previous;		//��������� �� ���������� ����
};

template <typename T>
struct node<T>* addHead(T value) {
	node<T>* head = new node<T>;		//�������� ��������� ����

	head->previous = NULL;		//��������� ��������� �� ���������� ����
	head->next = NULL;			//��������� ��������� �� ��������� ����
	head->value = value;		//��������� �������� � ����
	return head;				//����������� ��������� ����
}

template <typename T>
void addInTail(node<T>* head, T data) {

	node<T>* tail = head;			//�������� ���������� ��������� �� ������
	while (tail->previous) {	//����� ���������� ����
		tail = tail->previous;
	}

	node<T>* newElement = new node<T>;//�������� ��������� �� ����� ����
								/*�������� ������������ ����� ����� ��������� ����� � ���������*/
	tail->previous = newElement;
	newElement->next = tail;
	newElement->previous = NULL;//��������� ��������� �� ���������� ����
	newElement->value = data;	//��������� �������� � ����� ����
}

template <typename T>
void addInTop(node<T>* head, T data) {

	node<T>* top = head;			//�������� ���������� ��������� �� ������
	while (top->next) {			//����� �������� ����
		top = top->next;
	}

	node<T>* newElement = new node<T>;//�������� ��������� �� ����� ����
								/*�������� ������������ ����� ����� ��������� ����� � �������*/
	top->next = newElement;
	newElement->previous = top;

	newElement->next = NULL;	//��������� ��������� �� ��������� ����
	newElement->value = data;	//��������� �������� � ����� ����
}
template <typename T>
void printElements(node<T>* head) {
	node<T>* p = head;				//�������� ���������� ��������� �� ������
	while (p->previous) {		//����� ���������� ����
		p = p->previous;
	}

	while (p)					//������ �������� ���� �����, ������� � ����������
	{
		cout << p->value << endl;
		p = p->next;
	}
}
template <typename T>
T findElement(node<T>* head, int index) {
	node<T>* p = head;				//�������� ���������� ��������� �� ������
	while (p->previous) {		//����� ���������� ����
		p = p->previous;
	}
	int ind = 0;
	while (ind != index) {		//������� ���� �����, ������� � ����������
		p = p->next;			//���� �� ������ ���� � ������ ��������
		ind++;
	}
	return p->value;			//����������� �������� � ����
}
