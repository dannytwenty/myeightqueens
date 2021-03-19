#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;
bool check(vector<vector<int>>, int, int);
vector<vector<int>> stand(vector<vector<int>>, int, int);
int main() {
	int row;
	cout << "Input the row:";
	cin >> row;
	vector<vector<int>>vec(7);
	for (int i = 0; i < 7; i++) {
		vec[i].resize(7, 10);
	}
	//vec.resize(7, vector<int>(7, 10));
	vec = stand(vec, row, 0);
	check(vec, 0, 1);
	return 0;
}

vector<vector<int>> stand(vector<vector<int>>vec, int row, int column) {
	for (int i = 0; i < 7; i++) {
		vec[i][column] = 0;
	}
	for (int i = 0; i < 7; i++) {
		vec[row][i] = 0;
	}
	for (int i = 0; i < 7; i++) {
		if (row - i < 7 && row - i>-1 && column + i<7 && column + i>-1) {
			vec[row - i][column + i] = 0;
		}
	}
	for (int i = 0; i < 7; i++) {
		if (row + i < 7 && row + i>-1 && column + i<7 && column + i>-1) {
			vec[row + i][column + i] = 0;
		}
	}
	vec[row][column] = 1;
	return vec;
}

bool check(vector<vector<int>>vec, int row, int column) {
	if (column == 7) {
		for (int i = 0; i < 7; i++) {
			for (int j = 0; j < 7; j++) {
				if (j == 6) {
					cout << vec[i][j] << endl;
				}
				else {
					cout << vec[i][j] << setw(4);
				}
			}
		}
		return true;
	}
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 7; j++) {
			if (vec[i][column] == 10) {
				if (check(stand(vec, i, column), 0, column + 1)) {
					return true;
				}
			}
		}
	}
	return false;
}