#include <iostream>

using namespace std;

int main()
{
	int N;
	int a[1000000];
	cin >> N;
	for (int i = 0; i<N; i++)
		cin >> a[i];
	int max1 = a[0];
	int max2 = a[1];
	if (max1 <= max2) {
		max1 = a[1];
		max2 = a[0];
	}
	for (int i = 2; i<N; i++) {
		if (a[i] >= max1) {
			max2 = max1; 
			max1 = a[i];
		}
		else if (a[i] >= max2 && a[i] <= max1)
			max2 = a[i];
	}
	
	cout << max2;
	return 0;
}
