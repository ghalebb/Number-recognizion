//
// Created by galeb on 13/06/2020.
//

#include "Dense.h"

/** @brief Dense class implementation
 * Dense constructor*/
Dense::Dense(const Matrix &w, const Matrix &bias, ActivationType activationType) :
		_w(w), _bias(bias), _activation(activationType)
{}

