#include "stdafx.h"
#include "matrix.h"
#include "doubleList.h"
#include "learningFunction.h"


/*�������� ������� ����� ��������� ����*/
double ** matrixCreation(struct neural mtrx) {
	srand((unsigned)time(NULL));
	int *layerStart;
	int neuronsNumber = 0;
	double **weights;
	layerStart = new int[mtrx.layersNumber];
	for (int i = 0; i < mtrx.layersNumber; i++) {		//��������� ������ ��������� ��������, 
		layerStart[i] = neuronsNumber;					//� ������� ���������� ����
		neuronsNumber += findElement(mtrx.head, i);
	}

	weights = new double*[neuronsNumber];
	for (int i = 0; i < neuronsNumber; i++) {			//�������� ���������������� �������
		weights[i] = new double[i + 1];
		for (int j = 0; j < i + 1; j++)					//��������� �������
			weights[i][j] = 0;
	}

	/*������������ ��������� �������� �����*/
	for (int i = 0; i < mtrx.layersNumber - 1; i++)		//������� ���� ���������
		for (int k = layerStart[i]; k < layerStart[i] + findElement(mtrx.head, i); k++)	//������� ��������� � ������ ����
			for (int j = layerStart[i + 1]; j < layerStart[i + 1] + findElement(mtrx.head, i + 1); j++)	//������� ��������� � ��������� ����
				weights[j][k] = (double)rand() / (RAND_MAX + 1) * (1 - 0) + 0; //���������� ���� ����� �������� ������ ���� � �������� ����������  
	delete[]layerStart;
	return weights;
}
/*������ ������� � ����*/
void writeToFile(string fileName, struct neural mtrx) {
	ofstream file(fileName);
	for (int i = 0; i < mtrx.neuronsNumber; i++) {		//������� ����� �������
		for (int j = 0; j < i + 1; j++)				//������� ��������� ������ 
			file << fixed << mtrx.weights[i][j] << "\t";	//����������� �������� � ���� � ������������� ����
		file << "\n";
	}
	file.close();

};

/*������� ���������� �������� � ��������� ����*/
int neuronsCounter(struct neural mtrx) {
	int neuronsNumber = 0;
	for (int i = 0; i < mtrx.layersNumber; i++) {		//������� ���� 
		neuronsNumber += findElement(mtrx.head, i);		//����������� �������� ������� ����
	}
	return neuronsNumber;
}

/*����������� ������ ��������� ��������*/
double ** straightPass(struct neural mtrx) {
	int *layerStart = new int[mtrx.layersNumber];
	layerStart[0] = 0;
	/*����������� ������� ��������� �������� ������� ����*/
	for (int i = 1; i < mtrx.layersNumber; i++) {			//������� ���� 
		layerStart[i] = layerStart[i - 1] + findElement(mtrx.head, i - 1); //������ �������� ������ ��������� ����
		for (int k = 0; k < findElement(mtrx.head, i); k++) { //������� ��������� � ����
			mtrx.weights[layerStart[i] + k][layerStart[i] + k] = 0; //��������� �������� ��������
			for (int j = 0; j < findElement(mtrx.head, i - 1); j++) //������� ��������� ����������� ����
																  /*������������ �������� � ������ �������*/
				mtrx.weights[layerStart[i] + k][layerStart[i] + k] += mtrx.weights[layerStart[i - 1] + j][layerStart[i - 1] + j] * mtrx.weights[layerStart[i] + k][layerStart[i - 1] + j];
			/*������� ������� ����� ������������� �������*/
			mtrx.weights[layerStart[i] + k][layerStart[i] + k] = sigm(mtrx.weights[layerStart[i] + k][layerStart[i] + k]);
		}
	}
	delete[]layerStart;
	return mtrx.weights;
}

/*�������� ��������� ����*/
double ** training(struct neural mtrx, double expected) {
	int *layerStart = new int[mtrx.layersNumber];
	layerStart[0] = 0;
	/*����������� ������� ��������� �������� ������� ����*/
	for (int i = 1; i < mtrx.layersNumber; i++) {	//������� ����
		layerStart[i] = layerStart[i - 1] + findElement(mtrx.head, i - 1);	//������ �������� ������ ��������� ����
		for (int k = 0; k < findElement(mtrx.head, i); k++) {		//������� ��������� ����
			mtrx.weights[layerStart[i] + k][layerStart[i] + k] = 0; //��������� ��������
			for (int j = 0; j < findElement(mtrx.head, i - 1); j++)	//������� ��������� ����������� ����
																	/*������������ �������� � ������ �������*/
				mtrx.weights[layerStart[i] + k][layerStart[i] + k] += mtrx.weights[layerStart[i - 1] + j][layerStart[i - 1] + j] * mtrx.weights[layerStart[i] + k][layerStart[i - 1] + j];
			/*������� ������� ����� ������������� �������*/
			mtrx.weights[layerStart[i] + k][layerStart[i] + k] = sigm(mtrx.weights[layerStart[i] + k][layerStart[i] + k]);
		}
	}
	/*�������� ������� ��������� ��������������� ������*/
	mtrx.weights = backWay(mtrx, mtrx.weights[layerStart[mtrx.layersNumber - 1]][layerStart[mtrx.layersNumber - 1]], expected, layerStart);
	delete[]layerStart;
	return mtrx.weights;
}

/*����� ��������� ��������������� ������*/
double **backWay(struct neural mtrx, double actual, double expected, int* layerStart) {
	learningOptions options;
	options.wDelta = wDeltaOfLastLayer(actual, expected);	//���������� ������ ���������� ����	
	for (int i = layerStart[mtrx.layersNumber - 2]; i < layerStart[mtrx.layersNumber - 1]; i++) { //������� �������� ����������� ����
																								  /*���������� �����, ������ � ���������� ����*/
		mtrx.weights[layerStart[mtrx.layersNumber - 1]][i] = newWeightOfLastLayer(mtrx.weights[i][i], mtrx.weights[layerStart[mtrx.layersNumber - 1]][i], options);
	}

	for (int i = layerStart[mtrx.layersNumber - 2]; i < layerStart[mtrx.layersNumber - 1]; i++) { //������� �������� ����������� ����
		double error = errorOfNeuron(mtrx.weights[layerStart[mtrx.layersNumber - 1]][i], options);	//������������ �������� ������ ��� ������� �������
		for (int k = mtrx.layersNumber - 2; k > 0; k--)		//������� ���� ������ ����
			for (int m = layerStart[k]; m < layerStart[k + 1]; m++)	//������� �������� ������� ����
				for (int j = layerStart[k - 1]; j < layerStart[k]; j++) { //������� �������� ����������� ����
					mtrx.weights[m][j] = newWeight(mtrx.weights[m][m], mtrx.weights[m][j], error, &options); //���������� �������� ����
				}
	}
	return mtrx.weights;

}

/*������������ ��������� ���� �������������*/
void test(struct neural mtrx) {
	int value1;
	int value2;
	cout << "Enter 1 input value: ";
	cin >> value1;
	mtrx.weights[0][0] = value1;
	cout << "Enter 2 input value: ";
	cin >> value2;
	mtrx.weights[1][1] = value2;
	mtrx.weights = straightPass(mtrx); //������� ������� �������� ����� ���������
	cout << "\nValue of output neuron: " << mtrx.weights[5][5]; //����� �������� ������� ��������� ���� �� ������
	cout << "\nAnswer: " << answer(mtrx.weights[5][5]) << "\n\n"; //������� ������� ��������� ���� ����� �������
}

/*������� ������� ����� ������������� ������� (�������� �������)*/
double sigm(double x) {
	double sigm = (1 / (1 + exp(-x)));
	return sigm;
}

/*���������� ��������� ��������*/
double answer(double x) {
	if (x >= 0.5)				//�������� �� ������� ��������� �������
		return 1;
	else return 0;
}