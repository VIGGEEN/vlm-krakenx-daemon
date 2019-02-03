//
// Created by viktorm-lpc on 2019-02-02.
//

#ifndef KRAKENX_DAEMON_KRAKENXCONFIG_H
#define KRAKENX_DAEMON_KRAKENXCONFIG_H

#include <cstdint>
#include <algorithm>
#include <cassert>
#include <string>

class KrakenXConfig {
public:
    void set_fan_speed(uint8_t target);

    void set_pump_speed(uint8_t target);

    uint8_t get_fan_speed();

    uint8_t get_pump_speed();

    void apply();

    void _apply();

private:
    uint8_t _fan_speed_target = 50;
    uint8_t _pump_speed_target = 60;

    uint8_t _fan_speed_applied = 0;
    uint8_t _pump_speed_applied = 0;
};


#endif //KRAKENX_DAEMON_KRAKENXCONFIG_H
