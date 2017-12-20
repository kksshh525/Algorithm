#include <cstdio>
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
	vector<char> v;
	stack<char> s;
	char tmp;
	int N, i, result, iterator = 1;
	vector<char>::iterator vectorIterator;
	scanf("%d", &N);
	scanf("%c", &tmp);
	for (i = 0; i < N; i++){
		scanf("%c", &tmp);
		v.push_back(tmp);
	}

	for (i = 0; i < N; i++)
		printf("%c", v.at(i));

	//vectorIterator = v.begin();
	s.push(v.at(0));
	for (i = 1; v.size() != 0; i++){
		tmp = v.at(iterator);
		if (s.size() == 0){
			s.push(v.at(0));
			tmp = v.at(++iterator);
		}
		if (tmp == s.top()){
			//vectorIterator--;
			iterator--;
			s.pop();
			//v.erase(vectorIterator, vectorIterator + 1);
			//vectorIterator--;
			v.erase(v.begin() + iterator, v.begin() + iterator + 2);
			iterator--;
		}
		else
			s.push(tmp);
		//vectorIterator++;
		iterator++;
	}
	if (s.empty())
		result = 1;
	else
		result = 0;
	printf("%d\n", result);

	return 0;
}