//
// Created by galeb on 13/06/2020.
//

#include "MlpNetwork.h"
#include "Dense.h"

/** mlp network implementation*/
MlpNetwork::MlpNetwork(Matrix *weights, Matrix *biases) :
		layer1(weights[0], biases[0], Relu),
		layer2(weights[1], biases[1], Relu),
		layer3(weights[2], biases[2], Relu),
		layer4(weights[3], biases[3], Softmax)
{

}

/** getter*/
int MlpNetwork::_getNumber(const Matrix &mtx) const
{
	int sum = 0;
	for (int i = 1; i < mtx.getRows(); ++i)
	{
		if (mtx[sum] < mtx[i])
		{
			sum = i;
		}
	}
	return sum;
}

/** operator overloading*/
Digit MlpNetwork::operator()(Matrix &img)
{
	Digit digit;
	Matrix r1 = layer1(img);
	Matrix r2 = layer2(r1);
	Matrix r3 = layer3(r2);
	Matrix r4 = layer4(r3);
	digit.value = _getNumber(r4);
	digit.probability = r4[_getNumber(r4)];

	return digit;
}

