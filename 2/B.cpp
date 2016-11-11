#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

int main() {
	
	int N;
	std::cin >> N;
	
	std::vector<double> x_coord(N);
	for (std::vector<double>::iterator it = x_coord.begin(); it != x_coord.end(); ++it) {
		std::cin >> *it;
	}
	std::sort(x_coord.begin(), x_coord.end());
	
	double left_border = -std::numeric_limits<double>::max();
	int ans = 0;
	for (std::vector<double>::iterator it = x_coord.begin(); it != x_coord.end(); ++it) {
		if (*it > left_border + 1) {
			++ans;
			left_border = *it;
		}
	}
	
	std::cout << ans << std::endl;
	
	return 0;
}
