#include<iostream>

using namespace std;

int main() {

	string OCT;
	int dec = 0;
	int base = 8;

	cout << "input octal" << endl;
	cin >> OCT;
	string tmp = OCT;

	int ex = OCT.length();

	for (int i = 0; i < ex; ++i) {

		if (OCT[i] != '0' && OCT[i] != '1' && OCT[i] != '2' && OCT[i] != '3' && OCT[i] != '4' && OCT[i] != '5' && OCT[i] != '6' && OCT[i] != '7') {

			cout << "八進数以外の文字が入力されている" << endl;
			return 1;

		}

		dec = dec * base + (OCT[i] - '0');

	}

	cout << "(" << tmp << ")" << base << "=(" << dec << ")10";
	return 0;

}