//MlpNetwork.h

#ifndef MLPNETWORK_H
#define MLPNETWORK_H

#include "Matrix.h"
#include "Activation.h"
#include "Dense.h"
#include "Digit.h"

#define MLP_SIZE 4

const MatrixDims imgDims = {28, 28};
const MatrixDims weightsDims[] = {{128, 784},
								  {64,  128},
								  {20,  64},
								  {10,  20}};
const MatrixDims biasDims[] = {{128, 1},
							   {64,  1},
							   {20,  1},
							   {10,  1}};

/** mlp network class*/
class MlpNetwork
{
public:
	/** @brief constructor*/
	MlpNetwork(Matrix weights[MLP_SIZE], Matrix biases[MLP_SIZE]);

	/** @overload () operator*/
	Digit operator()(Matrix &img);

private:
	Dense layer1, layer2, layer3, layer4;

	/** Private getter*/
	int _getNumber(const Matrix &mtx) const;

};

#endif // MLPNETWORK_H
