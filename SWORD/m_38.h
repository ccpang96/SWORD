#include<iostream>
#include<algorithm>
#include<string>
#include<sstream>
#include<queue>
using namespace std;

class Solution {
public:
	void permutation1(vector<string>&result, string &s, size_t start) {
		if (start == s.size())
			result.push_back(s);
		else {
			for (size_t i = start; i < s.size(); i++) {

				char temp = s[start];
				s[start] = s[i];
				s[i] = temp;
				permutation1(result, s, start + 1);

				temp = s[start];
				s[start] = s[i];
				s[i] = temp;
			}
		}
	}
	vector<string> Permutation(string str) {
		vector<string>result;
		if (str.empty())
			return result;

		permutation1(result, str, 0); //传入的字符串分别是s和起始字符0

		return result;
	}
};

int main() {

	string line;
	while (getline(cin, line)) {
		vector<string> result = Solution().Permutation(line);
		for (auto m : result)
			cout << m << endl;
	}
	system("pause");
	return 0;
}