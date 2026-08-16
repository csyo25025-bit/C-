#include<iostream>

using namespace std;

int main() {

	string HEX;
	int dec = 0;
	int base = 16;
	int dis = base - 1;
	int num = 0;

	cout << "input hexadecimal" << endl;
	cin >> HEX;
	string tmp = HEX;

	int ex = HEX.length();

	for (int i = 0; i < ex; ++i) {

		if ('A' <= HEX[i] && HEX[i] <= 'F') {
		
			num = (HEX[i] - 'A') + 10;

		}
		
		else if ('0'<=HEX[i] && HEX[i] <= '9') {
		
			num = HEX[i] - '0';

		}
		
		else {
		
			cout << "16進数以外の文字が入力されている" << endl;
			return 1;
		
		}

		dec = dec * base + num;

	}

	cout << "(" << tmp << ")" << base << "=(" << dec << ")10";
	return 0;

}