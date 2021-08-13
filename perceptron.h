#ifndef PERCEPTRON_H
#define PERCEPTRON_H

#include <stdlib.h>

typedef struct _perceptron
{
	float *fWeights;
	float fLearningRate;
} Perceptron;

// Functions on each perceptron
void Initialize(Perceptron *this, size_t cnWeights, float fLearningRate);
void Train(Perceptron *this, float *fInputs, float fTarget);
int FeedForward(Perceptron *this, float *fInputs);
int Activate(Perceptron *this, float fWeightedSum);
float random(void);

#endif
