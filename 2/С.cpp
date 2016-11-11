#include <iostream>
#include <queue>
#include <limits>


const long long MOD = 1000 * 1000 * 1000; 

int main() {
	
	long long N;
	std::cin >> N;
	
	std::queue<int> a, b;
	
	for (int i = 0; i < N; ++i){ 
		int tmp;
		std::cin >> tmp;
		a.push(tmp);
	}
	
	for (int i = 0; i < N; ++i){ 
		int tmp;
		std::cin >> tmp;
		b.push(tmp);
	}
	
	long long sum = 0;
	bool odd = true;
	while(!a.empty() || !b.empty()) {
		int a_value = std::numeric_limits<int>::max(), b_value = a_value;
		int op = 0;
		if (!a.empty()) {
			a_value = a.front();
		}
		if (!b.empty()) {
			b_value = b.front();
		}
		if (a_value < b_value) {
			op = a_value;
			a.pop();
		} else {
			op = b_value;
			b.pop();
		}
		if (odd) {
			sum += op;
			sum %= MOD;
		}
		odd = !odd;
	}
	
	std::cout << sum << std::endl;
	
	return 0;
}
