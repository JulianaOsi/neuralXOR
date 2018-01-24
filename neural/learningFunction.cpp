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
double newWeightOfLastLayer(double valueOfNeuron, double weightFrom, struct learningOptions lrnOpt) {
	double newWeight = weightFrom + valueOfNeuron * lrnOpt.wDelta*lrnOpt.learningRate;
	return newWeight;
}

/*вычисление ошибки нейрона*/
double errorOfNeuron(double weightFrom, struct learningOptions lrnOpt) {
	double error = weightFrom * lrnOpt.wDelta;
	return error;
}

/*новое значение весов для предыдущих слоев*/
double newWeight(double valueOfNeuron, double weightTo, double error, struct learningOptions* lrnOpt) {
	lrnOpt->wDelta = error * valueOfNeuron*(1 - valueOfNeuron);
	double newWeight = weightTo + valueOfNeuron * lrnOpt->wDelta*lrnOpt->learningRate;
	return newWeight;
}
