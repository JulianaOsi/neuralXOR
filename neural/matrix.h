#pragma once
#include "doubleList.h"

/*структура, описывающая нейронную сеть*/
struct neural {
	double **weights;			//матрица весов
	int layersNumber = 3;		//количество слоёв
	int neuronsNumber = 0;		//количество нейронов	
	node<int>* head;					//указатель на корень списка нейроно в каждом слое
};

/*подсчёт количества нейронов в нейросети, mtrx - нейросеть, возвращает количество нейронов*/
int neuronsCounter(struct neural mtrx);

/*создание матрицы весов, mtrx - нейросеть, возвращает матрицу весов*/
double ** matrixCreation(struct neural mtrx);

/*запись матрицы весов в файл, fileName - имя файла, mtrx - нейросеть*/
void writeToFile(string fileName, struct neural mtrx);

/*обучение нейросети, mtrx - нейросеть, expected - ожидаемый ответ, возвращает измененную матрицу весов */
double ** training(struct neural mtrx, double expected);

/*использование нейросети для получения результата, mtrx - нейросеть, возвращает матрицу весов с результатом */
double ** straightPass(struct neural mtrx);

/*метод обратного распространения ошибки, mtrx - нейросеть, actual - полученный ответ, expected - ожидаемый ответ,
layerStart - массив индексов первых элементов каждого слоя, возвращает измененную матрицу весов*/
double **backWay(struct neural mtrx, double actual, double expected, int* layerStart);

/*проверка нейросети на тестовой выборке, mtrx - нейросеть*/
void test(struct neural mtrx);

/*пропуск значения через сигмоидальную функцию, x - входящее значение, возвращает результат сигмоиды*/
double sigm(double x);

/*проверка на соответствие условию, x - значение в выходном нейроне, возвращает результат нейросети */
double answer(double x);

neural readFromFile(struct neural neural, string fileName);
