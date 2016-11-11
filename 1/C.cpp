#include <iostream>
#include <cmath>
#include "stdio.h"

using namespace std;

int search_max(double* x, double* y, bool* mass, bool* on_Ox, int size) {
	
	int pos;
	
	for (int i = 0; i < size; i++)
		if (mass[i] && on_Ox[i]) {
			pos = i;
			break;
		}
	
	for (int i = pos; i < size; i++)
		if (mass[i] && on_Ox[i] &&  (x[i] >= x[pos]))
			pos = i;
	
	return pos;
}

int search_min(double* x, double* y, bool* mass, bool* on_Ox, int size) {
	
	int pos;
	
	for (int i = 0; i < size; i++)
		if (mass[i] && on_Ox[i]) {
			pos = i;
			break;
		}
	
	for (int i = pos; i < size; i++)
		if (mass[i] && on_Ox[i] && (x[i] <= x[pos]))
			pos = i;
	
	return pos;
}

double square(double x1, double y1, double x2, double y2) {
	return abs(1.0 / 2.0 * (x1 * y2 - y1 * x2)); 
}

double max_square(double* x, double* y, bool* mass, bool* on_Ox, int size) {
	int pos_max = search_max(x, y, mass, on_Ox, size);
	int pos_min =  search_min(x, y, mass, on_Ox, size);
	
	double max_s = 0.0;
	
	for (int i = 0; i < size; i++) {
		if (mass[i] && (y[i] != 0.0)) {
			max_s = square(x[i] - x[pos_max], y[i] - y[pos_max], 
						x[pos_min] - x[pos_max], y[pos_min] - y[pos_max]);
			break;
		}
	}
	
	for (int i = 0; i < size; i++) {
		if (mass[i] && (y[i] != 0.0) && 
		(max_s <= square(x[i] - x[pos_max], y[i] - y[pos_max], 
				x[pos_min] - x[pos_max], y[pos_min] - y[pos_max]))) {
			max_s = square(x[i] - x[pos_max], y[i] - y[pos_max], 
				x[pos_min] - x[pos_max], y[pos_min] - y[pos_max]);
		}
	
	}
	
	return max_s;
}

int main() {
	int N;
	cin >> N;
	double* x = new double[N];
	double* y = new double[N];
	bool* on_Ox = new bool[N];
	bool* left_dots = new bool[N];
	bool* right_dots =  new bool[N];
	
	for (int i = 0; i < N; i++) {
		cin >> x[i] >> y[i];
		if (x[i] < 0.0)
			left_dots[i] = true;
		else if (x[i] >= 0.0)
			right_dots[i] = true;
		if (y[i] == 0.0)
			on_Ox[i] = true;
	}
	
	double square_left = max_square(x, y, left_dots, on_Ox, N);
	double square_right = max_square(x, y, right_dots, on_Ox, N);
	double max_s = square_left;
	
	
	if (square_left < square_right)
		max_s = square_right;
	if (max_s == 0.0)
		cout << 0;
	else
		printf("%.4f", max_s);
	return 0;
}
