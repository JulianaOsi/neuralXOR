#pragma once

/*���������, ���������� ������ ��� ��������*/
struct learningOptions {
	double learningRate = 0.3;			//����������� ��������
	double wDelta;						//����� �������� �����
};

/*������������ ������ ����� ��� ���������� ����, actual - ���������� ��������, expected - ���������, ���������� ����� �����*/
double wDeltaOfLastLayer(double actual, double expected);

/*�������������� �������� ����� ��� ���������� ����, valueOfNeuron - �������� �������,
weightFrom - ���, ������ �� �������, options - ������ ��� ��������, ���������� ����� �������� ����*/
double newWeightOfLastLayer(double valueOfNeuron, double weightFrom, struct learningOptions options);

/*������������ ������ ��� �������, weightFrom - ���, ������ �� �������, options - ������ ��� ��������, ���������� ������*/
double errorOfNeuron(double weightFrom, struct learningOptions options);

/*�������������� �������� �����, valueOfNeuron - �������� �������,
weightTo - ���, ������ � �������, error - ������ �������, options - ������ ��� ��������, ���������� ����� �������� ����*/
double newWeight(double valueOfNeuron, double weightTo, double error, struct learningOptions* options);