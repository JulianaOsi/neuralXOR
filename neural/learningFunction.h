#pragma once
struct learningOptions {
	double learningRate = 0.3;
	double wDelta;
};
double wDeltaOfLastLayer(double actual, double expected);
double newWeightOfLastLayer(double valueOfNeuron, double weightFrom, struct learningOptions lrnOpt);
double errorOfNeuron(double weightFrom, struct learningOptions lrnOpt);
double newWeight(double valueOfNeu, double weightTo, double error, struct learningOptions* lrnOpt);