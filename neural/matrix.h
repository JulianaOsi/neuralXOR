#pragma once
struct neural {
	double **weights;
	int layersNumber = 3;
	int neuronsNumber = 0;
	int neuronsPerLayer[3] = { 2,3,1 };
	//int *neuronsPerLayer = NULL;
};

int neuronsCounter(struct neural mtrx);
double ** matrixCreation(struct neural mtrx);
void writeToFile(string fileName, struct neural mtrx);
double ** training(struct neural mtrx, double expected);
double ** straightPass(struct neural mtrx);
double **backWay(struct neural mtrx, double actual, double expected, int* layerStart);
void test(struct neural mtrx);
double sigm(double x);
double answer(double x);