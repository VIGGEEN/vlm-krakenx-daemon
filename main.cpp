#include <iostream>
#include <unistd.h>
#include <sys/types.h>

#include "LinearFunc.h"
#include "KrakenXConfig.h"
#include "CpuPackageTemp.h"

KrakenXConfig kraken_config;
CpuPackageTemp cpu_package;
LinearFunc fan_func(25, 25, 60, 100);
LinearFunc pump_func(25, 60, 60, 100);

int system(const char *command);

void daemonize() {
    if (fork() != 0) {
        exit(0);
    }

    setsid();
}

void update() {
    const double temp = cpu_package.get_temperature();
    kraken_config.set_fan_speed(fan_func.eval(temp));
    kraken_config.set_pump_speed(pump_func.eval(temp));
    kraken_config.apply();

#ifdef DEBUG
    std::cout << "[Package: " << cpu_package.get_temperature() << "C] "
                  << "[Fan:" << (uint32_t) kraken_config.get_fan_speed() << "%] "
                  << "[Pump:" << (uint32_t) kraken_config.get_pump_speed() << "%] "
                  << std::endl;
#endif
}

int main(int argc, char *argv[]) {

    if (argc == 5) {
        fan_func = LinearFunc(static_cast<double>(atoi(argv[1])), static_cast<double>(atoi(argv[2])),
                              static_cast<double>(atoi(argv[3])), static_cast<double>(atoi(argv[4])));
    } else if (argc == 9) {
        fan_func = LinearFunc(static_cast<double>(atoi(argv[1])), static_cast<double>(atoi(argv[2])),
                              static_cast<double>(atoi(argv[3])), static_cast<double>(atoi(argv[4])));
        pump_func = LinearFunc(static_cast<double>(atoi(argv[5])), static_cast<double>(atoi(argv[6])),
                               static_cast<double>(atoi(argv[7])), static_cast<double>(atoi(argv[8])));
    }

    update();
    //daemonize();

    while (true) {
        usleep(1000);
        update();
    }
}