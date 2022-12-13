#include "particle_interface.h"
#include <iostream>
#include <vector>
#include <cmath>

Particle::Particle() {
	coord_p = { 0, 0, 0 };
	speed = { 0, 0, 0 };
	v12 = { 0, 0, 0 };
}

Particle::Particle(double x_0, double y_0, double z_0, double vx_0, double vy_0, double vz_0) {
	coord_p = { x_0, y_0, z_0 };
	speed = { vx_0, vy_0, vz_0 };
	v12 = { 0, 0, 0 };
}

double Particle::Force(double& dx, double& dy, double& dz, double coord_x, double coord_y, double coord_z, double& cell) {
	double r = std::sqrt(pow(dx, 2) + pow(dy, 2) + pow(dz, 2));
	double r_1 = r;
	double r_2 = r;
	if (coord_x != 0) {
		r_1 = std::sqrt(pow(dx - cell, 2) + pow(dy, 2) + pow(dz, 2));
		r_2 = std::sqrt(pow(dx + cell, 2) + pow(dy, 2) + pow(dz, 2));
	}

	if (coord_y != 0) {
		r_1 = std::sqrt(pow(dx, 2) + pow(dy - cell, 2) + pow(dz, 2));
		r_2 = std::sqrt(pow(dx, 2) + pow(dy + cell, 2) + pow(dz, 2));
	}

	if (coord_z != 0) {
		r_1 = std::sqrt(pow(dx, 2) + pow(dy, 2) + pow(dz - cell, 2));
		r_2 = std::sqrt(pow(dx, 2) + pow(dy, 2) + pow(dz + cell, 2));
	}
	

	/*if (r > r_c) {
		return 0;
	}
	*/
	if (r == 0) {
		return 0;
	}
	
	//if (r <= r_c) {
	double f = 9 * (48 * (coord_x + coord_y + coord_z)* pow(sigma, 12)) / (pow(r, 14)) - 9 * (24 * (coord_x + coord_y + coord_z) * pow(sigma, 6)) / (pow(r, 8));
	f += 9 * (48 * (coord_x + coord_y + coord_z - 100) * pow(sigma, 12)) / (pow(r_1, 14)) - 9 * (24 * (coord_x + coord_y + coord_z - 100) * pow(sigma, 6)) / (pow(r_1, 8));
	f += 9 * (48 * (coord_x + coord_y + coord_z + 100) * pow(sigma, 12)) / (pow(r_2, 14)) - 9 * (24 * (coord_x + coord_y + coord_z + 100) * pow(sigma, 6)) / (pow(r_2, 8));
	return f;
	//}

	/*if (r > r_s and r <= r_c) {
		return (-k1 * 3 * (r - r_c) * coord) / r + (k2 * 2 * (r - r_c) * coord) / r;
	}
	*/

}