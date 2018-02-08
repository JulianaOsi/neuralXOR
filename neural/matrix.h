#pragma once
#include "doubleList.h"

/*���������, ����������� ��������� ����*/
struct neural {
	double **weights;			//������� �����
	int layersNumber = 3;		//���������� ����
	int neuronsNumber = 0;		//���������� ��������	
	node<int>* head;					//��������� �� ������ ������ ������� � ������ ����
};

/*������� ���������� �������� � ���������, mtrx - ���������, ���������� ���������� ��������*/
int neuronsCounter(struct neural mtrx);

/*�������� ������� �����, mtrx - ���������, ���������� ������� �����*/
double ** matrixCreation(struct neural mtrx);

/*������ ������� ����� � ����, fileName - ��� �����, mtrx - ���������*/
void writeToFile(string fileName, struct neural mtrx);

/*�������� ���������, mtrx - ���������, expected - ��������� �����, ���������� ���������� ������� ����� */
double ** training(struct neural mtrx, double expected);

/*������������� ��������� ��� ��������� ����������, mtrx - ���������, ���������� ������� ����� � ����������� */
double ** straightPass(struct neural mtrx);

/*����� ��������� ��������������� ������, mtrx - ���������, actual - ���������� �����, expected - ��������� �����,
layerStart - ������ �������� ������ ��������� ������� ����, ���������� ���������� ������� �����*/
double **backWay(struct neural mtrx, double actual, double expected, int* layerStart);

/*�������� ��������� �� �������� �������, mtrx - ���������*/
void test(struct neural mtrx);

/*������� �������� ����� ������������� �������, x - �������� ��������, ���������� ��������� ��������*/
double sigm(double x);

/*�������� �� ������������ �������, x - �������� � �������� �������, ���������� ��������� ��������� */
double answer(double x);

neural readFromFile(struct neural neural, string fileName);
