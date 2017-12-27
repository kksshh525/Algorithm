#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
class findLargestSquare {
private:
	int width;
	vector<vector<int>> dp;
public:
	findLargestSquare(vector<vector<char>> &board) {
		width = board[0].size();
		dp.assign(width, vector<int>(width, 0));
		cout << findSquare(board) << endl;
	}
	int findSquare(vector<vector<char>> &board) {
		int answer = 0;
		for (int i = 0; i < width; i++) {
			if (board[0][i] == 'O') dp[0][i] = 1;
			else dp[0][i] = 0;
		}
		for (int i = 1; i < width; i++) {
			if (board[i][0] == 'O') dp[i][0] = 1;
			else dp[i][0] = 0;
			for (int j = 1; j < width; j++) {
				if (board[i][j] == 'O') dp[i][j] = 1;
				else dp[i][j] = 0;
				if (board[i - 1][j - 1] == 'O'
					&& board[i][j - 1] == 'O'
					&& board[i - 1][j] == 'O')
					dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j]));
				if (answer < dp[i][j]) answer = dp[i][j];
			}
		}
		return answer*answer;
	}
};*/

int width, height;
vector<vector<int>> dp;

int findSquare(vector<vector<char>> &board) {
	int answer = 0;
	for (int i = 0; i < width; i++) {
		if (board[0][i] == 'O') dp[0][i] = 1;
		else dp[0][i] = 0;
	}
	for (int i = 1; i < height; i++) {
		if (board[i][0] == 'O') dp[i][0] = 1;
		else dp[i][0] = 0;
		for (int j = 1; j < width; j++) {
			if (board[i][j] == 'O') dp[i][j] = 1;
			else dp[i][j] = 0;
			if (board[i - 1][j - 1] == 'O'
				&& board[i][j - 1] == 'O'
				&& board[i - 1][j] == 'O')
				dp[i][j] += min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j]));
			if (answer < dp[i][j]) answer = dp[i][j];
		}
	}
	return answer*answer;
}

int findLargestSquare(vector<vector<char>> board)
{
	width = board[0].size();
	height = board.size();
	if (width == 1) {
		for (int i = 0; i < height; i++) {
			if (board[i][0] == 'O') return 1;
		}
		return 0;
	}
	dp.assign(width, vector<int>(width, 0));
	return findSquare(board);
}

int main() {
	vector<vector<char>> board{
		{'O','O','O','X','X','X' },
		{'O','X','O','O','O','O'},
		{'O','O','O','O','X','O'} };
	//new findLargestSquare(board);
	cout<<findLargestSquare(board);
	return 0;
}