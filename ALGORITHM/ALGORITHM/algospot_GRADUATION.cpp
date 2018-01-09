#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Graduation {
private:
	int attendingLecture, N, K, M, L, cnt;
	int prerequisiteSubject[12] = { 0, };
public:
	Graduation() {
		if (K == 0)
			cout << '0' << endl;
		else {
			cin >> N >> K >> M >> L;
			cnt = 0;
			attendingLecture = (1 << N) - 1;
			initPrerequisite();
			int answer = countMinSemester();
			if (answer) cout << answer << endl;
			else cout << "IMPOSSIBLE" << endl;
		}
	}
	void initPrerequisite() {
		string str;
		getline(cin, str);
		for (int i = 0; i < N; i++) {
			size_t s = 0, e = 0;
			getline(cin, str);
			while ((e = str.find(' ', s)) != string::npos) {
				int len = e - s;
				if (len)
					prerequisiteSubject[i] |= (1 << stoi(str.substr(s, len)));
				s = e + 1;
			}
			prerequisiteSubject[i] |= (1 << stoi(str.substr(s)));
		}
	}
	int countMinSemester() {
		vector<vector<int>> lecture;
		for (int i = 0; i < M; i++) {
			int k, input;
			cin >> k;
			vector<int> subLecture;
			for (int j = 0; j < k; j++) {
				cin >> input;
				subLecture.push_back(input);
			}
			lecture.push_back(subLecture);
		}
		while (cnt = N - __popcnt(attendingLecture) < K) {
		
		}
		return 0;
	}
};

int main() {
	freopen("Text.txt", "r", stdin);
	int C;
	cin >> C;
	for (int i = 0; i < C;i++)
		new Graduation();
	return 0;
}