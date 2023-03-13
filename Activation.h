//Activation.h

#ifndef ACTIVATION_H
#define ACTIVATION_H

#include "Matrix.h"

/**
 * @enum ActivationType
 * @brief Indicator of activation function.
 */
enum ActivationType
{
	Relu,
	Softmax
};

/**
 * @brief Activation class deceleration
 */
class Activation
{
public:
	/** @brief Activation class constructor*/
	Activation(ActivationType actType);

	/** @overload the () operator*/
	Matrix &operator()(Matrix m);

	/** @brief getter the the activationType type*/
	ActivationType getActivationType() const;

private:
	ActivationType _activation;

	static Matrix &_relu(Matrix &x);

	static Matrix &_softmax(Matrix &x);
};

#endif //ACTIVATION_H
