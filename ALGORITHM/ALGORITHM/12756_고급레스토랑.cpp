#include <iostream>
using namespace std;

int main() {
	freopen("Text.txt", "r", stdin);
	int AA, AH, BA, BH;
	cin >> AA >> AH >> BA >> BH;
	int cntA = (AH%BA == 0) ? (AH / BA) : (AH / BA + 1);
	int cntB = (BH%AA == 0) ? (BH / AA) : (BH / AA + 1);
	if (cntA > cntB)
		cout << "PLAYER A" << endl;
	else if(cntA<cntB)
		cout << "PLAYER B" << endl;
	else
		cout << "DRAW" << endl;

	return 0;
}