#include <stdio.h>
#include <stdlib.h>

// Structure of a single perceptron
typedef struct perceptron_t
{
	float *fWeights;
	float fLearningRate;
} Perceptron;

// Functions on each perceptron
void Initialize(Perceptron *this, size_t cnWeights, float fLearningRate);
void Train(Perceptron *this, float *fInputs, float fTarget);
int FeedForward(Perceptron *this, float *fInputs);
int Activate(Perceptron *this, float fWeightedSum);

#define MAGIC 14820

/* to return a pseudo-random number on -1 -> 1 */
float random(void)
{
	float fRandom = (float) rand();
	if(fRandom > MAGIC)
		return fRandom / (RAND_MAX+1);
	else
		return -1.0 * fRandom / (RAND_MAX+1);
}

void Initialize(Perceptron *this, size_t cnWeights, float fLearningRate)
{
	int i;
	float fRandom;

	this->fWeights = (float *) calloc(cnWeights, sizeof(float));
	
	srand(time(NULL));

	printf("Initializing Perceptron:\n");
	for(i=0; i<cnWeights; i++)
	{
		fRandom = random();
		this->fWeights[i] = fRandom;
		printf("\t%f\n", this->fWeights[i]);
	}

	this->fLearningRate = fLearningRate;
	printf("Learning Rate = %f", this->fLearningRate);
}

int Activate(Perceptron *this, float fSum)
{
	if(fSum > 0)
		return 1;
	else
		return -1;
}

int FeedForward(Perceptron *this, float *fInputs)
{
	int i, cnWeights = sizeof(this->fWeights) / sizeof(float);
	float fSum=0;
	
	for(i=0; i<cnWeights; i++)
		fSum += fInputs[i] * this->fWeights[i];

	return Activate(this, fSum);
}

void Train(Perceptron *this, float *fInputs, float fTarget)
{
	int i, cnWeights=sizeof(this->fWeights) / sizeof(float);

	float fGuess = FeedForward(this, fInputs);
	float fError = fTarget - fGuess;

	for(i=0; i<cnWeights; i++)
		this->fWeights[i] += this->fLearningRate * fError * fInputs[i];
}
