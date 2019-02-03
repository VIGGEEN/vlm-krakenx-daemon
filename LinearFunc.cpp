//
// Created by viktorm-lpc on 2019-02-02.
//

#include "LinearFunc.h"

/**
 * A linear function specified from two points
 * @param x0 first point x-coordinate
 * @param y0 first point y-coordinate
 * @param x1 second point x-coordinate
 * @param y1 second point y-coordinate
 */
LinearFunc::LinearFunc(double x0, double y0, double x1, double y1) {
    assert(x0 <= x1);
    assert(y0 <= y1);
    this->_x0 = x0;
    this->_y0 = y0;
    this->_x1 = x1;
    this->_y1 = y1;
    this->_coefficient = (y1 - y0) / (x1 - x0);
}

/**
 * Evaluates the linear function
 * @param x
 * @return f(x)
 */
uint8_t LinearFunc::eval(double x) {
    return static_cast<uint8_t >(std::clamp<double>(_coefficient * (x - _x0) + _y0, _y0, _y1));
}