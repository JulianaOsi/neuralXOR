#pragma once

/*���������, ����������� ���� ������*/
struct node {
	int value;			//�������� � ����
	node* next;			//��������� �� ��������� ����
	node* previous;		//��������� �� ���������� ����
};

/*������� ������ ������, value - �������� � �����, ���������� ��������� �� ������ ������*/
struct node* addHead(int value);

/*���������� �������� � ����� ������, head - ��������� �� ������ ������ , data - ����������*/
void addInTail(node* head, int data);

/*���������� �������� � ������ ������, head - ��������� �� ������ ������ , data - ����������*/
void addInTop(node* head, int data);

/*����� ������ �� ������, head - ��������� �� ������ ������*/
void printElements(node* head);

/*����� �������� �� �������, head - ��������� �� ������ ������ , index - ���������� �����, ���������� �������� � ����*/
int findElement(node* head, int index);

