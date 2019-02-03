//
// Created by viktorm-lpc on 2019-02-02.
//

#ifndef KRAKENX_DAEMON_CPUPACKAGETEMP_H
#define KRAKENX_DAEMON_CPUPACKAGETEMP_H


#include <sensors/sensors.h>
#include <iostream>

class CpuPackageTemp {
public:
    CpuPackageTemp();

    double get_temperature();

private:
    sensors_chip_name const *_chip_name = nullptr;
    sensors_feature const *_feature = nullptr;
    sensors_subfeature const *_subfeature = nullptr;

    double _package_temperature = 0.0;

    bool _update_temperature();

    void _find_temperature_sensor();
};


#endif //KRAKENX_DAEMON_CPUPACKAGETEMP_H
