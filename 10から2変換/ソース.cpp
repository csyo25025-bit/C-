#include<iostream>

using namespace std;

int main() {

	const int bit_num = 16;

	int change[bit_num] = { 0 };

	cout << "input decimal:";

	int num = 0;
	cin >> num;

	int tmp = num;
	int i = 0;

	while (tmp > 0 && i < bit_num) {
	
		change[i] = tmp % 2;
		tmp /= 2;
		i++;
	
	}

	cout << "(" << num << ")10=(";

	for (int j = bit_num - 1; j >= 0;--j ) {
	
		cout << change[j];
	
	}

	cout << ")2" << endl;

	return 0;

}