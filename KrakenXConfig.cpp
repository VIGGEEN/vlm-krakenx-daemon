//
// Created by viktorm-lpc on 2019-02-02.
//

#include "KrakenXConfig.h"

/**
 * @param target target fan speed
 */
void KrakenXConfig::set_fan_speed(uint8_t target) {
    assert(target >= 25 && target <= 100);
    _fan_speed_target = target;
}

/**
 * @param target pump speed
 */
void KrakenXConfig::set_pump_speed(uint8_t target) {
    assert(target >= 60 && target <= 100);
    _pump_speed_target = target;
}

/**
 * @return applied fan speed
 */
uint8_t KrakenXConfig::get_fan_speed() {
    return _fan_speed_applied;
}

/**
 * @return applied pump speed
 */
uint8_t KrakenXConfig::get_pump_speed() {
    return _pump_speed_applied;
}

/**
 * Applies target pump and fan speeds to underlying device IF an apply is truly necessary
 */
void KrakenXConfig::apply() {
    if ((_fan_speed_target == 100 && _fan_speed_applied != 100) ||
        (_pump_speed_target == 100 && _pump_speed_applied != 100)) {
        _apply();
        return;
    }

    if (std::abs(_fan_speed_target - _fan_speed_applied) < 5 &&
        std::abs(_pump_speed_target - _pump_speed_applied) < 5) {
        return;
    }

    _apply();
}

/**
 * Applies target pump and fan speed to underlying device
 */
void KrakenXConfig::_apply() {
    _fan_speed_applied = _fan_speed_target;
    _pump_speed_applied = _pump_speed_target;

    const auto cmd =
            "sudo colctl --fan_speed " + std::to_string(_fan_speed_target) +
            " --pump_speed " + std::to_string(_pump_speed_target);
    system(&cmd[0]);
}