#include <iostream>
#include <cmath>
using namespace std;
#define PI 3.1415926535
int Answer, A, B, C, D, E;

int point(int distance, int angle) {
	int ret = 0, tmp;
	if (distance <= A) return 50;
	if (angle >= 0)
		tmp = (angle + 9) / 18;
	else
		tmp = (angle - 9) / 18;
	switch (tmp) {
	case 0:
		ret = 6; break;
	case 1:
		ret = 13; break;
	case 2:
		ret = 4; break;
	case 3:
		ret = 18; break;
	case 4:
		ret = 1; break;
	case 5:
		ret = 20; break;
	case 6:
		ret = 5; break;
	case 7:
		ret = 12; break;
	case 8:
		ret = 9; break;
	case 9:
		ret = 14; break;
	case 10:
		ret = 11; break;
	case -10:
		ret = 11; break;
	case -9:
		ret = 8; break;
	case -8:
		ret = 16; break;
	case -7:
		ret = 7; break;
	case -6:
		ret = 19; break;
	case -5:
		ret = 3; break;
	case -4:
		ret = 17; break;
	case -3:
		ret = 2; break;
	case -2:
		ret = 15; break;
	case -1:
		ret = 10; break;
	}

	if (distance >= E) return 0;
	else if (distance <E && distance >= D) return ret * 2;
	else if (distance <C && distance >= B) return ret * 3;
	else return ret;
}


int main(int argc, char** argv)
{
	int T, test_case,  N, i;
	double x, y, distance, angle;
	freopen("input.txt", "r", stdin);

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		Answer = 0;
		cin >> A >> B >> C >> D >> E;
		cin >> N;
		for (i = 0; i < N; i++) {
			cin >> x >> y;
			distance = sqrt(pow(x,2) + pow(y,2));
			angle = (180.0 / PI)*atan2(y, x);
			Answer += point(distance, angle);
		}
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;
}