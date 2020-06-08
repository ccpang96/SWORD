/************************************************************************/
/*@File Name         : 7.�ؽ�������.cpp
/*@Created Date      : 2020/6/2 9:08
/*@Author            : ccpang(ccpang96@163.com)
/*@blog              : www.cnblogs.com/ccpang
/*@Description       :
/************************************************************************/

/************************************************************************/
/*@ Problem Name         : 7.�ؽ�������
/*@ Description 		 :����ĳ��������ǰ���������������Ľ�������ؽ����ö�����.
���������ǰ���������������Ľ���ж������ظ������֡�
��������ǰ���������{1,2,4,7,3,5,6,8}�������������{4,7,2,1,5,3,8,6}�����ؽ������������ء�
*************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<string>
#include<sstream>
#include<queue>
#include<stack>
using namespace std;


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


class Solution {
public:
	TreeNode * reConstructBinaryTree(vector<int> pre, vector<int> vin) {
		if (pre.size() == 0)
			return nullptr;
		TreeNode *root = new TreeNode(pre[0]);	//���ڵ�

		vector<int>left_pre, left_vin, right_pre, right_vin;

		//������������ҵ����ڵ��λ��
		int m = 0;
		for (int i = 0; i < vin.size(); i++) {
			if (vin[i] == pre[0]) {
				m = i;
				break;
			}
		}

		//Ȼ��ֱ�ǰ��������������������ֱ����left_pre,left_vin,right_pre,right_vin
		for (int i = 0; i < m; i++) {
			left_pre.push_back(pre[i + 1]);
			left_vin.push_back(vin[i]);
		}

		for (int i = m + 1; i < vin.size(); i++) {
			right_pre.push_back(pre[i]);
			right_vin.push_back(vin[i]);
		}

		root->left = reConstructBinaryTree(left_pre, left_vin);
		root->right = reConstructBinaryTree(right_pre, right_vin);

		return root;
	}
};
 
