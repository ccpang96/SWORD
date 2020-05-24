#pragma once
#include<iostream>
#include<vector>
#include<stack>
#include<sstream>
#include<cmath>

using namespace std;

class Input {
public:
	vector<int> stringToIntegerVector(string input) {
		vector<int>output;
		input = input.substr(1, input.length() - 2);
		stringstream ss;
		ss.str(input);
		char delim = ',';
		string item;
		while (getline(ss, item, delim)) {
			output.push_back(stoi(item));
		}

		return output;
	}
};


//方法一： 87 / 87 个通过测试用例
//执行用时:480 ms, 在所有 C++ 提交中击败了10.72% 的用户
//内存消耗 : 39.6 MB, 在所有 C++ 提交中击败了100.00%的用户

//将传入的string改为string &word后：
//执行用时:36 ms, 在所有 C++ 提交中击败了72.22% 的用户
//内存消耗 : 8.6 MB, 在所有 C++ 提交中击败了100.00%的用户

class Solution {
public:
	bool dfs(vector<vector<char>>& board, vector<vector<int>>&visit, int cur_i, int cur_j, string &word, int word_index) {


		if (cur_i < 0 || cur_j < 0 || cur_i == board.size() || cur_j == board[0].size() || board[cur_i][cur_j] != word[word_index] || visit[cur_i][cur_j] == 1) {
			return false;
		}
		visit[cur_i][cur_j] = 1;
		word_index++;

		if (word_index == word.length())
			return true;

		int di[4] = { 0,0,1,-1 };
		int dj[4] = { -1,1,0,0 };
		for (int index = 0; index < 4; index++) {
			int next_i = cur_i + di[index], next_j = cur_j + dj[index];
			if (dfs(board, visit, next_i, next_j, word, word_index))
				return true;
		}

		//四个方向都找完了，还没找到，则返回false,并且重置当前节点为未访问
		visit[cur_i][cur_j] = 0; //将原先访问过的节点重新设置为0
		return false;

	}
	bool exist(vector<vector<char>>& board, string word) {
		//1.在board中找到一个入口使得board[i][j] = word[0]
		//2.由于格子不能再次访问，所以新建一个visit数组用来辅助判断是否被访问过
		//3.接着再次找到下一个入口，再次开始
		vector<vector<int>>visit;
		vector<int>temp(board[0].size());
		visit.resize(board.size(), temp);
		bool found = false;
		for (int i = 0; i < board.size(); i++)
			for (int j = 0; j < board[0].size(); j++) {
				if (board[i][j] == word[0]) {
					if (dfs(board, visit, i, j, word, 0))
						found = true;
				}
			}
		return found;
	}
};

//人家的答案
//执行用时:28 ms, 在所有 C++ 提交中击败了81.75% 的用户
//内存消耗 : 7.7 MB, 在所有 C++ 提交中击败了100.00%的用户
class Solution_1 {
public:
	bool exist(vector<vector<char>>& board, string word) {
		if (board.empty())
			return false;
		int row = board.size(), column = board[0].size();

		for (int i = 0; i < row; ++i) {
			for (int j = 0; j < column; ++j) {
				if (board[i][j] == word[0])
					if (dfs(board, i, j, 0, word))
						return true;
			}
		}
		return false;
	}
	bool dfs(vector<vector<char>> & board, int x, int y, int i, const string & word) {

		if (i == word.size())
			return true;
		bool flag = false;
		if (x >= 0 && y >= 0 && x < board.size() && y < board[0].size() && i < word.size() && word[i] == board[x][y]) {
			++i;
			char temp = board[x][y];
			board[x][y] = '.';
			flag = dfs(board, x + 1, y, i, word) ||
				dfs(board, x, y + 1, i, word) ||
				dfs(board, x - 1, y, i, word) ||
				dfs(board, x, y - 1, i, word);
			if (!flag) {
				--i;
				board[x][y] = temp;
			}
		}
		return flag;
	}
};




/*
int main() {

	vector<vector<char>>board;
	string word = "ABCESEEEFS";
	vector<char>temp1{ 'A','B','C','E' };
	vector<char>temp2{ 'S','F','E','S' };
	vector<char>temp3{ 'A','D','E','E' };
	board.push_back(temp1);
	board.push_back(temp2);
	board.push_back(temp3);
	cout << Solution_1().exist(board, word) << endl;

	system("pause");
	return 0;
}
*/




