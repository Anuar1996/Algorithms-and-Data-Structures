#include <iostream>

typedef unsigned int uint;

int main() {
	
	uint N, M;
	
	std::cin >> N >> M;
	
	uint step_cnt[N + 1];
	
	step_cnt[0] = 1;
	for (uint i = 1; i <= M; ++i) {
		step_cnt[i] = 1 << (i - 1);
	}
	for(uint i = M; i <= N; ++i) {
		uint tmp_cnt = 0;
		for (uint j = 1; j <= M; ++j) {
			if (i - j >= 0) {
				tmp_cnt += step_cnt[i - j];
			}
			else {
				break;
			}
		}
		step_cnt[i] = tmp_cnt;
	}
	
	std::cout << step_cnt[N] << std::endl;
	return 0;
}
