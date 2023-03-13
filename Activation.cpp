//
// Created by galeb on 11/06/2020.
//

#include "Activation.h"
#include <cmath>

/** @brief Activation class constructor*/
Activation::Activation(ActivationType actType) :
		_activation(actType)
{
}

/** @overload the () operator*/
Matrix &Activation::operator()(Matrix m)
{
	if (_activation == Relu)
	{
		return _relu(m);
	}

	return _softmax(m);

}

/** @brief _relu's function implantation*/
Matrix &Activation::_relu(Matrix &x)
{
	for (int i = 0; i < x.getRows(); ++i)
	{
		for (int j = 0; j < x.getCols(); ++j)
		{
			if (x[i * x.getCols() + j] < 0)
			{
				x[i * x.getCols() + j] = 0;
			}
		}
	}
	return x;
}

/** @brief _softmax's function implantation*/
Matrix &Activation::_softmax(Matrix &x)
{
	for (int j = 0; j < x.getCols(); ++j)
	{
		float sum = 0.0f;
		for (int i = 0; i < x.getRows(); ++i)
		{
			x(i, j) = expf(x(i, j));
			sum += x(i, j);
		}
		for (int i = 0; i < x.getRows(); ++i)
		{
			x(i, j) = (1 / sum) * x(i, j);
		}
	}

	return x;
}

/** @brief getter the the activationType type*/
ActivationType Activation::getActivationType() const
{
	return this->_activation;
}

