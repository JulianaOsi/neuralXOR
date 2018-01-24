#include "stdafx.h"
#include "learningFunction.h"

/* дельта для весов,которые идут к последнему слою */
double wDeltaOfLastLayer(double actual, double expected) {
	double wDelta;
	double error = expected - actual;
	wDelta = error * actual*(1 - actual);
	return wDelta;
}

/*новое значение весов,которые идут к последнему слою*/
double newWeightOfLastLayer(double valueOfNeuron, double weightFrom, struct learningOptions options) {
	double newWeight = weightFrom + valueOfNeuron * options.wDelta*options.learningRate;
	return newWeight;
}

/*вычисление ошибки нейрона*/
double errorOfNeuron(double weightFrom, struct learningOptions options) {
	double error = weightFrom * options.wDelta;
	return error;
}

/*новое значение весов для предыдущих слоев*/
double newWeight(double valueOfNeuron, double weightTo, double error, struct learningOptions* options) {
	options->wDelta = error * valueOfNeuron*(1 - valueOfNeuron);
	double newWeight = weightTo + valueOfNeuron * options->wDelta*options->learningRate;
	return newWeight;
}
