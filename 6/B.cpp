#include <iostream>

typedef unsigned long long ull;

int main(){
	ull n;
	std::cin >> n;
	
	ull zeros_end[n], ones_end[n];
	
	zeros_end[0] = ones_end[0] = 1;
	for (ull i = 1; i < n; ++i) {
		zeros_end[i] = zeros_end[i - 1] + ones_end[i - 1];
		ones_end[i] = zeros_end[i - 1];
	}
	
	std::cout << zeros_end[n - 1] + ones_end[n - 1] << std::endl;
	
	return 0;
}
