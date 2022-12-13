#include "data_interface.h"
#include <iostream>
#include <vector>
#include <ctime>
#include <cmath>

double rand_number(int max) {

	return rand() % max;
}

Data::Data(double x_max, double y_max, double z_max, double v_max, double delta_t) : x_max(x_max), y_max(y_max), z_max(z_max), v_max(v_max), delta_t(delta_t) {
	Coord xyz = { 0, 0, 0 };
	Coord vxyz = { 0, 0, 0 };

	setlocale(LC_ALL, "ru");
	srand(time(NULL));

	for (int i = 0; i < size; i++) {
		particle[i].coord_p = { rand_number(x_max), rand_number(y_max), rand_number(z_max)};
		particle[i].speed = { rand_number(v_max) * pow(-1, rand_number(2)), rand_number(v_max) * pow(-1, rand_number(2)), rand_number(v_max) * pow(-1, rand_number(2)) };
	}

	Energy();
}

void Data::Sum_force() {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			double dx = particle[j].coord_p.x - particle[i].coord_p.x;
			double dy = particle[j].coord_p.y - particle[i].coord_p.y;
			double dz = particle[j].coord_p.z - particle[i].coord_p.z;
			particle[i].sum_force.x += particle[i].Force(dx, dy, dz, dx, 0, 0, x_max);
			particle[i].sum_force.y += particle[i].Force(dx, dy, dz, 0, dy, 0, x_max);
			particle[i].sum_force.z += particle[i].Force(dx, dy, dz, 0, 0, dz, x_max);
		}
	}
}

void Data::Update() {
	Sum_force();
	for (int i = 0; i < size; i++) {

		particle[i].v12.x = particle[i].speed.x + particle[i].sum_force.x * delta_t / 2;
		particle[i].v12.y = particle[i].speed.y + particle[i].sum_force.y * delta_t / 2;
		particle[i].v12.z = particle[i].speed.z + particle[i].sum_force.z * delta_t / 2;

		particle[i].coord_p.x = particle[i].coord_p.x + particle[i].v12.x * delta_t;
		particle[i].coord_p.y = particle[i].coord_p.y + particle[i].v12.y * delta_t;
		particle[i].coord_p.z = particle[i].coord_p.z + particle[i].v12.z * delta_t;

		Cross(particle[i]);
		particle[i].sum_force = { 0, 0, 0 };

	}

	Sum_force();

	for (int i = 0; i < size; i++) {

		particle[i].speed.x = particle[i].v12.x + particle[i].sum_force.x * delta_t / 2;
		particle[i].speed.y = particle[i].v12.y + particle[i].sum_force.y * delta_t / 2;
		particle[i].speed.z = particle[i].v12.z + particle[i].sum_force.z * delta_t / 2;

		particle[i].sum_force = { 0, 0, 0 };

	}

	Energy();
}

void Data::Energy() {

	for (int i = 0; i < size; i++) {
		kin_energy += pow(particle[i].speed.x, 2) + pow(particle[i].speed.y, 2) + pow(particle[i].speed.z, 2) / 2;

		for (int j = 0; j < size; j++) {
			double r_sq = pow(particle[i].coord_p.x - particle[j].coord_p.x, 2) + pow(particle[i].coord_p.y - particle[j].coord_p.y, 2) + pow(particle[i].coord_p.z - particle[j].coord_p.z, 2);
	
			if (r_sq == 0) {
				pot_energy += 0;
			}
			else {
				//if (r_sq <= pow(particle[i].r_c, 2)) {
					pot_energy += (4 * (pow(pow(particle[i].sigma, 2) / r_sq, 6) - pow(pow(particle[i].sigma, 2) / r_sq, 3))) / 2;
				//}
				//if (r_sq > pow(particle[i].r_c, 2)) {
					//pot_energy += 0;
				//}
			}
		}
	}
	energy = kin_energy + pot_energy;
}

void Data::Cross(Particle &particle) {
	while (particle.coord_p.x < 0 || particle.coord_p.x > x_max) {
		particle.coord_p.x = std::abs(x_max - std::abs(particle.coord_p.x));
	}

	while (particle.coord_p.y < 0 || particle.coord_p.y > y_max) {
		particle.coord_p.y = std::abs(y_max - std::abs(particle.coord_p.y));
	}

	while (particle.coord_p.z < 0 || particle.coord_p.z > z_max) {
		particle.coord_p.z = std::abs(z_max - std::abs(particle.coord_p.z));
	}
}