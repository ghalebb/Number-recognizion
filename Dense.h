//
// Created by galeb on 10/06/2020.
//

#include "Activation.h"
#include "Matrix.h"

#ifndef EX4_DENSE_H
#define EX4_DENSE_H

/** @brief Dense class deceleration*/
class Dense
{
public:

	/** @brief constructor*/
	Dense(const Matrix &w, const Matrix &bias, ActivationType activationType);

	/** @brief weight getter*/
	Matrix getWeights() const
	{
		return _w;
	};

	/** @brief Bias getter*/
	Matrix getBias() const
	{
		return _bias;
	}

	/** @brief Activation getter*/
	Activation getActivation() const
	{
		return _activation;
	}

	/** @brief () operator overload*/
	Matrix operator()(Matrix &x)
	{
		return _activation(_w * x + _bias);
	}

private:
	Matrix _w, _bias;
	Activation _activation;
};

#endif //EX4_DENSE_H
