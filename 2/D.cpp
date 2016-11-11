#include <stdio.h>
#include <stdint.h>

int main() {
	
	int32_t N;
	scanf("%d", &N);
	if (N == 1) {
		printf("1");
		return 0;
	}
	int32_t mod = 1000000000;
	int32_t *c = new int32_t[N + 1];
	c[0] = 1;
	c[1] = 1;
	for (int32_t i = 2; i <= N; i++) {
		int64_t sum = 0;	
		for (int32_t k = 0; k <= i - 1; k++) {
			sum = (sum + c[k] * c[i - k - 1]) % mod;
			
		}
		c[i] = sum;
	}
	printf("%d", c[N]);
	return 0;
}
