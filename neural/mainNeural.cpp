/*Нейронная сеть для решения логической операции XOR, её создание, обучение и проверка работоспособности.*/

#include "stdafx.h"
#include "doubleList.h"
#include "learningFunction.h"
#include "mainNeural.h"
#include "matrix.h"

int main() {
	neural XOR;					//создание нейросети
	XOR.head = addHead(3);		//создание корня списка
	addInTail(XOR.head, 2);		//добавление узла в хвост списка
	addInTop(XOR.head, 1);		//добавление узла в вершину списка

	int epochNumber = 5000;		//количество эпох обучения
	bool isComplete = false, isAgree = false;	//переключатель
	int trainingSet[4][3] = { { 1,0,1 },{ 1,1,0 },{ 0,1,1 },{ 0,0,0 } };	//набор данных для обучения
	double expected;
	char ans;
	XOR.neuronsNumber = neuronsCounter(XOR);								//подсчёт количества нейронов
	cout << "Do you wanna download your matrix? Y/N";
	cin >> ans;
	if (ans == 'Y')
		isAgree = true;
	cout << "Below will display the number of passed tests. Begin?\n";
	system("pause");
	while (!isComplete) {													//пока проверка не пройдена
		XOR.weights = matrixCreation(XOR);									//создание матрицы весов
		if (isAgree == true);
		XOR = readFromFile(XOR, "weights.txt");
		for (int i = 0; i < epochNumber; i++) {								//обучение нейронной сети
			for (int k = 0; k < 4; k++) {									//перебор элементов выборки
				int j = 0;
				for (j = 0; j < findElement(XOR.head, 0); j++)				//заполнение входного слоя
					XOR.weights[j][j] = trainingSet[k][j];
				expected = trainingSet[k][j];
				XOR.weights = training(XOR, expected);						//обучение
				if (i % 25 == 0) {											//проверка на работоспособность 
					int counter = 0;										//во время обучения
					for (int k = 0; k < 4; k++) {							//перебор наборов из обучающей базы
						int j = 0;
						for (j = 0; j < findElement(XOR.head, 0); j++)		//заполнение входного слоя данными для обучения
							XOR.weights[j][j] = trainingSet[k][j];
						expected = trainingSet[k][j];
						XOR.weights = training(XOR, expected);
						if (answer(XOR.weights[5][5]) == expected)			//проверка на соответствие ожидаемого и полученного значения
							counter++;
					}
					cout << counter << "\t";
					if (counter == 4) {										//количество пройденных проверок
						isComplete = true;
						i = epochNumber;
						cout << endl;
					}
				}
			}
		}
	}
	writeToFile("weights.txt", XOR);							//запись в файл
	cout << "\nTraining completed\n";
	for (int k = 0; k < 4; k++)									//тестирование пользователем
		test(XOR);

	system("pause");
	return 0;
}