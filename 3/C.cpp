#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <stdio.h>

typedef std::vector<std::pair<double, double> > arr_t;

double dist(const std::pair<double, double> &a, const std::pair<double, double> &b) {
	return sqrt(pow(b.first - a.first, 2) + pow(b.second - a.second, 2));
}

bool vect_prod1(const std::pair<double, double> &a, const std::pair<double, double> &b, const std::pair<double, double> &c) {
	return a.first * (b.second - c.second) + b.first * (c.second - a.second) + c.first * (a.second - b.second) < 0;
}

bool vect_prod2(const std::pair<double, double> &a, const std::pair<double, double> &b, const std::pair<double, double> &c) {
	return a.first * (b.second - c.second) + b.first * (c.second - a.second) + c.first * (a.second - b.second) > 0;
}

void convex_hull (arr_t & coords) {
	std::sort (coords.begin(), coords.end());
	arr_t up, down;
	std::pair<double, double> p1 = coords[0];
	std::pair<double, double> p2 = coords.back();
	up.push_back (p1);
	down.push_back (p1);
	for (uint i = 1; i < coords.size(); ++i) {
		if (i == coords.size() - 1 || vect_prod1(p1, coords[i], p2)) {
			while (up.size() >= 2 && !vect_prod1(up[up.size() - 2], up[up.size() - 1], coords[i]))
				up.pop_back();
			up.push_back (coords[i]);
		}
		if (i == coords.size() - 1 || vect_prod2(p1, coords[i], p2)) {
			while (down.size() >= 2 && !vect_prod2(down[down.size() - 2], down[down.size() - 1], coords[i]))
				down.pop_back();
			down.push_back (coords[i]);
		}
	}
	coords.clear();
	for (size_t i = 0; i < up.size(); ++i)
		coords.push_back (up[i]);
	for (size_t i = down.size() - 2; i > 0; --i)
		coords.push_back (down[i]);
}

int main() {
	
	int N;
	
	std::cin >> N;
	arr_t coords(N);
	
	for (arr_t::iterator it = coords.begin(); it != coords.end(); ++it) {
		double x, y;
		std::cin >> x >> y;
		*it = std::make_pair(x, y);
	}
	
	/*std::sort(coords.begin(), coords.end());
	
	std::sort(coords.begin(), coords.end(), comparer);
	
	std::stack<std::pair<double, double> > hull;
	hull.push(coords[0]);
	hull.push(coords[1]);
	
	double res = 0.0;
	
	for (int i = 2; i < N; ++i) {
		while vect_prod() < 0
	}*/
	
	double res = 0.0;
	convex_hull(coords);
	
	for (uint i = 0; i < coords.size() - 1; ++i) {
		res += dist(coords[i], coords[i + 1]);
	}
	res += dist(coords[0], coords[coords.size() - 1]);
	printf("%.2f", res);
	
	return 0;
}
