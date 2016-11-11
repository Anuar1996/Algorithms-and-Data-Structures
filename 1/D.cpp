#include <iostream>
#include "stdlib.h"

using namespace std;

const int MAXN = 20000;

struct _set {
	bool a[MAXN];
	
	void construct() {
		for (int i = 0; i < MAXN; i++)
			a[i] = false;
	}
	
	void add(int n) {
		a[n] = true;
	}
	void print(){
		for (int i = 0; i<MAXN; i++)
			if (a[i]) {
				cout << i + 1 << " ";
			}
	}
	
	bool exist(int n) {
		return a[n - 1];
	}
	
	bool is_empty() {
		for (int i = 0; i < MAXN; i++)
			if (a[i])
				return false;
		return true;
	}
};

int main() {
	
	_set A;
	_set B;
	A.construct();
	B.construct();
	int tmp;
	cin >> tmp;
	while (tmp != 0) {
		A.add(tmp - 1);
		cin >> tmp;
	}
	cin >> tmp;
	while (tmp != 0) {
		B.add(tmp - 1);
		cin >> tmp;
	}
	
	_set AB;
	
	AB.construct();
	
	for (int i = 0; i < MAXN; i++) {
		if ((A.exist(i + 1) && !B.exist(i + 1))
		|| (!A.exist(i + 1) && B.exist(i + 1)))
			AB.add(i);
	}
	if (AB.is_empty())
		cout << 0;
	else 
		AB.print();
	return 0;
}
