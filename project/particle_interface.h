#pragma once
#include <iostream>
#include <vector>
#include "coordinates.h"

class Particle {
private:
    double epsilon = 1;
    double r_s = 1.24;
    double k1 = -387072 / (61009 * pow(r_s, 2));
    double k2 = -24192 / (3211 * pow(r_s, 2));

public:
    double sigma = 1;
    std::vector <double> t = { 0 };
    Coord coord_p;
    Coord speed;
    Coord v12;
    Coord sum_force = { 0, 0, 0 };
    double r_c = 1.73;
    double u_lj = 4 * epsilon * (pow(sigma / r_c, 12) - pow(sigma / r_c, 6));

    Particle();
    Particle(double x_0, double y_0, double z_0, double vx_0, double vy_0, double vz_0);

    double Force(double& dx, double& dy, double& dz, double coord_x, double coord_y, double coord_z, double& cell);
};
