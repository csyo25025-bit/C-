#include<iostream>

using namespace std;

int main() {
	
	string BIN;
	int dec = 0;
	int base = 2;

	cout << "input binary" << endl;
	cin >> BIN;
	string tmp = BIN;

	int ex = BIN.length();

	for (int i = 0; i < ex; ++i) {

		if (BIN[i] != '0' && BIN[i] != '1') {
		
			cout << "二進数以外の文字が入力されている" << endl;
			return 1;
		
		}

		dec = dec * base + (BIN[i] - '0');

	}

	cout << "(" << tmp << ")2=(" << dec << ")10";
	return 0;

}