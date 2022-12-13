#pragma once
#include "particle_interface.h"

class Data {
public:
    static const int size = 200;
    Particle particle[size];
    double x_max;
    double y_max;
    double z_max;
    double v_max;
    double delta_t;
    double energy = 0;
    double kin_energy = 0;
    double pot_energy = 0;

    Data(double x_max, double y_max, double z_max, double v_max, double delta_t);
    void Update();
    void Sum_force();
    void Energy();
    void Cross(Particle & particle);
};
