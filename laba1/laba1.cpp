#include <iostream>
#include <ctime>
#include <random>
#include <chrono>
#include <map>
#include <cstdlib>
#include <cmath>

using namespace std;

void output(const int row, const int col, int arr[][50])
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;
}

void main()
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	for (int i = 0; i < 100; i++)
	{
		int count = 0;
		const int ROW = 50;
		const int COL = ROW;

		int arr[ROW][COL]{ 1 };

		for (int i = 0; i < ROW; i++)
		{
			for (int j = 0; j < COL; j++)
			{
				arr[i][j] = 1;
			}
		}
		const int n = 3;
		int n_0 = 0;
		//output(ROW, COL, arr);
		int arr_ind[n][3]{ 1 };

		for (int i = 0; i < n; i++)
		{
			arr_ind[i][0] = rand() % ROW;
			arr_ind[i][1] = rand() % COL;
			arr[arr_ind[i][0]][arr_ind[i][1]] = 0;
		}

		//output(ROW, COL, arr);

		for (int i = 0; i < n; i++)
		{
			if (n_0 != n)
			{
				if (arr_ind[i][0] == 0 || arr_ind[i][0] == ROW - 1)
				{
					if (arr_ind[i][1] == 0 || arr_ind[i][1] == ROW - 1)
					{
						arr_ind[i][2] = 1;
						n_0 = 0;
					}
				}

				if (arr_ind[i][2] == 0)
				{
					arr[arr_ind[i][0]][arr_ind[i][1]] = 1;
					random_device r;
					default_random_engine e1(r());
					uniform_int_distribution<int>uniform_dist(-1, 1);
					int di_1 = uniform_dist(e1);
					arr_ind[i][0] += di_1;
					if (arr[arr_ind[i][0]][arr_ind[i][1]] == 0)
					{
						di_1 = (-1) * di_1;
						arr_ind[i][0] += 2 * di_1;
					}
					if (arr_ind[i][0] > ROW - 1 || arr_ind[i][0] < 0)
					{
						arr_ind[i][0] -= 2 * di_1;
					}
					if (di_1 == 0)
					{
						int dj_1 = pow(-1, rand() % 3);
						arr_ind[i][1] += dj_1;
						if (arr[arr_ind[i][0]][arr_ind[i][1]] == 0)
						{
							dj_1 = (-1) * dj_1;
							arr_ind[i][1] += 2 * dj_1;
						}
						if (arr_ind[i][1] > COL - 1 || arr_ind[i][1] < 0)
						{
							arr_ind[i][1] -= 2 * dj_1;
						}
					}
					arr[arr_ind[i][0]][arr_ind[i][1]] = 0;
					//output(ROW, COL, arr);
				}
				if (i == n - 1)
				{
					count += 1;

					for (int i = 0; i < n; i++)
					{
						if (arr[arr_ind[i][0] + 1][arr_ind[i][1]] == 0 || arr[arr_ind[i][0] - 1][arr_ind[i][1]] == 0 || arr[arr_ind[i][0]][arr_ind[i][1] + 1] == 0 || arr[arr_ind[i][0]][arr_ind[i][1] - 1] == 0)
						{
							arr_ind[i][2] = 1;
							n_0 = 0;
						}
					}
				}

				if (i == n - 1)
				{
					for (int i = 0; i < n; i++)
					{
						if (arr_ind[i][2] == 1)
						{
							n_0 += 1;
						}
					}
					i = -1;
				}
			}
		}
		cout << count  << "\t";
		cout << "," << "\t";
	}
}
