//
// Created by viktorm-lpc on 2019-02-02.
//

#ifndef KRAKENX_DAEMON_LINEARFUNC_H
#define KRAKENX_DAEMON_LINEARFUNC_H

#include <cstdint>
#include <algorithm>
#include <cassert>
class LinearFunc {
public:
    LinearFunc(double x0, double y0, double x1, double y1);
    uint8_t eval(double x);

private:
    double _x0, _y0, _x1, _y1, _coefficient;
};


#endif //KRAKENX_DAEMON_LINEARFUNC_H
