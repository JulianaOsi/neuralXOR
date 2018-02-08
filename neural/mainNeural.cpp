/*��������� ���� ��� ������� ���������� �������� XOR, � ��������, �������� � �������� �����������������.*/

#include "stdafx.h"
#include "doubleList.h"
#include "learningFunction.h"
#include "mainNeural.h"
#include "matrix.h"

int main() {
	neural XOR;					//�������� ���������
	XOR.head = addHead(3);		//�������� ����� ������
	addInTail(XOR.head, 2);		//���������� ���� � ����� ������
	addInTop(XOR.head, 1);		//���������� ���� � ������� ������

	int epochNumber = 5000;		//���������� ���� ��������
	bool isComplete = false, isAgree = false;	//�������������
	int trainingSet[4][3] = { { 1,0,1 },{ 1,1,0 },{ 0,1,1 },{ 0,0,0 } };	//����� ������ ��� ��������
	double expected;
	char ans;
	XOR.neuronsNumber = neuronsCounter(XOR);								//������� ���������� ��������
	cout << "Do you wanna download your matrix? Y/N";
	cin >> ans;
	if (ans == 'Y')
		isAgree = true;
	cout << "Below will display the number of passed tests. Begin?\n";
	system("pause");
	while (!isComplete) {													//���� �������� �� ��������
		XOR.weights = matrixCreation(XOR);									//�������� ������� �����
		if (isAgree == true);
		XOR = readFromFile(XOR, "weights.txt");
		for (int i = 0; i < epochNumber; i++) {								//�������� ��������� ����
			for (int k = 0; k < 4; k++) {									//������� ��������� �������
				int j = 0;
				for (j = 0; j < findElement(XOR.head, 0); j++)				//���������� �������� ����
					XOR.weights[j][j] = trainingSet[k][j];
				expected = trainingSet[k][j];
				XOR.weights = training(XOR, expected);						//��������
				if (i % 25 == 0) {											//�������� �� ����������������� 
					int counter = 0;										//�� ����� ��������
					for (int k = 0; k < 4; k++) {							//������� ������� �� ��������� ����
						int j = 0;
						for (j = 0; j < findElement(XOR.head, 0); j++)		//���������� �������� ���� ������� ��� ��������
							XOR.weights[j][j] = trainingSet[k][j];
						expected = trainingSet[k][j];
						XOR.weights = training(XOR, expected);
						if (answer(XOR.weights[5][5]) == expected)			//�������� �� ������������ ���������� � ����������� ��������
							counter++;
					}
					cout << counter << "\t";
					if (counter == 4) {										//���������� ���������� ��������
						isComplete = true;
						i = epochNumber;
						cout << endl;
					}
				}
			}
		}
	}
	writeToFile("weights.txt", XOR);							//������ � ����
	cout << "\nTraining completed\n";
	for (int k = 0; k < 4; k++)									//������������ �������������
		test(XOR);

	system("pause");
	return 0;
}