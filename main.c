#include <stdio.h>
#include <stdlib.h>
#include "perceptron.h"

#define TRAINING_DATA_SIZE 2000
#define PERCEPTRON_INPUTS_COUNT 3
#define TRAINING_RATE 0.001

typedef struct _trainstruct
{
	float *fInputs;
	int iOutput;
} TrainStruct;

float f(float x) { return 0.3 * x + 0.4; }

void InitializeTrainingData(TrainStruct* trDataArray)
{
	int i, j;
	for(i=0; i<TRAINING_DATA_SIZE; i++)
	{
		for(j=0; j<PERCEPTRON_INPUTS_COUNT; j++)
		{
			trDataArray[i].fInputs = (float *) calloc(PERCEPTRON_INPUTS_COUNT, sizeof(float));
		}
	}
}

void main(void)
{
	int i, j, answer, count=0, xmin=-1, ymin=-1, xmax=1, ymax=1;
	float x, y;

	TrainStruct trDataArray[TRAINING_DATA_SIZE];
	Perceptron ptron;

	Initialize(&ptron, PERCEPTRON_INPUTS_COUNT, TRAINING_RATE);
	InitializeTrainingData(trDataArray);

	srand(time(NULL));
	for(i=0; i<TRAINING_DATA_SIZE; i++)
	{
		x = random();
		y = random();

		answer = 1;
		if(y < f(x))
			answer = -1;

		trDataArray[i].fInputs[0] = x;
		trDataArray[i].fInputs[1] = y;
		trDataArray[i].fInputs[2] = 1;
		trDataArray[i].iOutput = answer;
	}
}
