#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include "data_interface.h"

void entry(Data& data, int iter) {
	std::ofstream fout;
	fout.open("Данные.txt");
	for (int j = 0; j < iter; j++) {
		fout << data.size << std::endl;
		fout << "Lattice=\"100.0 0.0 0.0 0.0 100.0 0.0 0.0 0.0 100.0\"" << " " << "Properties=species:S:1:pos:R:3" << std::endl;
		for (int i = 0; i < data.size; i++) {
			fout << "None" << " " << data.particle[i].coord_p.x << " " << data.particle[i].coord_p.y << " " << data.particle[i].coord_p.z<< " " << data.particle[i].speed.x << std::endl;
		}

		std::cout << j << " " << data.energy << " " << data.kin_energy << " " << data.pot_energy << " " << std::endl;

		data.energy = 0;
		data.kin_energy = 0;
		data.pot_energy = 0;
		data.Update();
	}
	fout.close();
}

int main() {
	int x_max = 100;
	int y_max = 100;
	int z_max = 100;
	int v_max = 5;
	double delta_t = 0.05;
	int iter = 100;
	
	Data* data1 = new Data(x_max, y_max, z_max, v_max, delta_t);

	entry(*data1, iter);

}