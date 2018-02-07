#pragma once

/*структура, содержащая данные для обучения*/
struct learningOptions {
	double learningRate = 0.3;			//коэффициент обучения
	double wDelta;						//сдвиг значений весов
};

/*высчитывание сдвига весов для последнего слоя, actual - полученное значение, expected - ожидаемое, возвращает сдвиг весов*/
double wDeltaOfLastLayer(double actual, double expected);

/*пересчитывание значений весов для последнего слоя, valueOfNeuron - значение нейрона,
weightFrom - вес, идущий из нейрона, options - данные для обучения, возвращает новое значение веса*/
double newWeightOfLastLayer(double valueOfNeuron, double weightFrom, struct learningOptions options);

/*высчитывание ошибки для нейрона, weightFrom - вес, идущий из нейрона, options - данные для обучения, возвращает ошибку*/
double errorOfNeuron(double weightFrom, struct learningOptions options);

/*пересчитывание значений весов, valueOfNeuron - значение нейрона,
weightTo - вес, идущий к нейрону, error - ошибка нейрона, options - данные для обучения, возвращает новое значение веса*/
double newWeight(double valueOfNeuron, double weightTo, double error, struct learningOptions* options);