#pragma once
#include<iostream>
#include<string>
#include<sstream>
#include<vector>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(nullptr) {}
};

class Input {
public:

	//将string转换为vector
	vector<int> stringToIntegerVector(string input) {
		vector<int>result;
		input = input.substr(1, input.length() - 2);
		stringstream ss;
		ss.str(input);
		string item;
		char delim = ' '; //分隔符
		while (getline(ss, item, delim)) {
			result.push_back(stoi(item));
		}
		return result;
	}

	//将string转换为ListNode
	ListNode * stringToListNode(string input) {
		vector<int> v1 = stringToIntegerVector(input);
		ListNode *dummyHead = new ListNode(0);
		ListNode *curr = dummyHead;

		for (auto item : v1) {
			curr->next = new ListNode(item);
			curr = curr->next;
		}
		curr = dummyHead->next;
		delete dummyHead;
		return curr;
	}
};

class Output {
public:
	string listNodeToString(ListNode* head) {
		if (head == nullptr)
			return "[]";
		string result;
		while (head != nullptr) {
			result += std::to_string(head->val) + " ";
			head = head->next;
		}
		return "[" + result.substr(0, result.length() - 1) + "]";
	}

};

class Solution {
public:
	ListNode * deleteNode(ListNode* head, int val) {
		ListNode * dummyHead = new ListNode(0);
		ListNode *curr = dummyHead;
		dummyHead->next = head;
		while (curr != nullptr && curr->next != nullptr) {
			if (curr->next->val == val) {
				curr->next = curr->next->next;
				break;
			}
			curr = curr->next;
		}
		curr = dummyHead->next;
		delete dummyHead;
		return curr;
	}
};

int main() {

	string line;
	while (getline(cin, line)) {
		ListNode * head = Input().stringToListNode(line);
		getline(cin, line);
		int val = stoi(line);
		ListNode *result = Solution().deleteNode(head, val);
		string output = Output().listNodeToString(result);
		cout << output << endl;
	}
	system("pause");
	return 0;
}

