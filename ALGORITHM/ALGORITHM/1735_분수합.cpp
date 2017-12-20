#include <iostream>
using namespace std;

int gcd(int a, int b) {
	return b ? gcd(b, a%b) : a;
}

int main() {
	freopen("Text.txt", "r", stdin);
	int AU, AB, BU, BB;
	cin >> AU >> AB >> BU >> BB;
	int CB = AB*BB;
	int CU = AU*BB + BU*AB;

	int k = gcd(CB, CU);
	cout << CU / k << " " << CB / k;

	return 0;
}