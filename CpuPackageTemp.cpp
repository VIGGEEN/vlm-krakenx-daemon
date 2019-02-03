//
// Created by viktorm-lpc on 2019-02-02.
//

#include "CpuPackageTemp.h"

CpuPackageTemp::CpuPackageTemp() {
    sensors_init(nullptr);
    _find_temperature_sensor();
}

/**
 * Reads temperature from chip->feature->subfeature into _package_temperature
 * @return true on successful update, false otherwise
 */
bool CpuPackageTemp::_update_temperature() {
    double val;
    if (_subfeature->flags & SENSORS_MODE_R) {
        const int rc = sensors_get_value(_chip_name, _subfeature->number, &val);
        if (rc < 0) {
            std::cerr << "error_code: " << rc << std::endl;
            exit(rc);
        } else {
            _package_temperature = val;
            return true;
        }
    }
    return false;
}

/**
 * @return Current _package_temperature
 */
double CpuPackageTemp::get_temperature() {
    _update_temperature();
    return _package_temperature;
}

/**
 * Attempts to find correct cpu package sensor for future reading
 */
void CpuPackageTemp::_find_temperature_sensor() {
    int c = 0;
    while ((_chip_name = sensors_get_detected_chips(0, &c)) != 0) {

        // Assure we have a chip with prefix containing CORETEMP
        std::string chip_prefix(_chip_name->prefix);
        if (chip_prefix.find("coretemp") == std::string::npos) {
            continue;
        }

        // Assume first sensor_feature is indeed PACKAGE_TEMP
        int f = 0;
        _feature = sensors_get_features(_chip_name, &f);

        // Get sensor_subfeature of type TEMP_INPUT
        _subfeature = sensors_get_subfeature(_chip_name, _feature,
                                             sensors_subfeature_type::SENSORS_SUBFEATURE_TEMP_INPUT);

        break;
    }

    // Make sure that operation was successful
    if (_chip_name == nullptr || _feature == nullptr || _subfeature == nullptr) {
        exit(19);
    }
}