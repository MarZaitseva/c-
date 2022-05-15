#include <iostream>
#include<string>
#include<vector>

using namespace std;

int min(int a, int b, int c) {
	int min_1 = 0;
	int seq[3] = { a, b, c };
	for (int i = 1; i < 3; i++) {
		if (seq[i - 1] <= seq[i]) {
			min_1 = seq[i - 1];
		}
		else {
			min_1 = seq[i];
		}
	}
	return min_1;
}

int m(char a, char b) {
	if ( a == b) {
		return 0;
	}
	else {
		return 1;
	}
}

int distance_search(string s1, string s2,int s1_l,int s2_l) {
	vector<vector<int>> d(s1_l, vector<int>(s2_l));
	for (int i = 0; i < s1_l; i++) {
		for (int j = 0; j < s2_l; j++) {
			if (i == 0 && j == 0) {
				d[i][j] = m(s1[i], s2[j]);
			}
			if (j == 0 && i > 0) {
				d[i][j] = i;
			}
			if (i == 0 && j > 0) {
				d[i][j] = j;
			}
			if (i > 0 && j > 0) {
				d[i][j] = min(distance_search(s1, s2, s1_l, s2_l - 1) + 1, distance_search(s1, s2, s1_l - 1, s2_l) + 1, distance_search(s1, s2, s1_l - 1, s2_l - 1) + m(s1[i], s2[j]));
			}
		}
	}
	return d[s1_l - 1][s2_l - 1];
}

int main()
{
	string s1 = "cat";
	string s2 = "dog";
	cout << distance_search(s1, s2, s1.size(), s2.size()) << endl;
}
