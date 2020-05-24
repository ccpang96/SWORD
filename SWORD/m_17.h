#pragma once

#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Output {
public:
	string integerVectorToString(vector<int>&v1) {

		if (v1.size() == 0)
			return "[]";
		string output;
		for (int index = 0; index < v1.size(); index++) {
			int number = v1[index];
			output += std::to_string(number) + ",";
		}
		return "[" + output.substr(0, output.length() - 1) + "]";
	}
};

/*
�ⷨһ:��򵥵Ľⷨ,��������û���κμ�������,����û�п��ǵ�����������
*/
class Solution_1 {
public:
	vector<int> printNumbers(int n) {
		vector<int>output;
		int maxValue = pow(10, n) - 1;
		for (int index = 1; index <= maxValue; index++)
			output.push_back(index);
		return output;
	}
};

/*
�ⷨ��:�����ⷨchar��
*/
class Solution_2 {
public:
	//vector<int> res;
	void  printNumbers(int n) {
		if (n <= 0) return;
		//����һ�����������ֵ���ַ�����,������һλҪ�洢'\0'�����Ҫ����һ��
		char* number = new char[n + 1];
		//��ʼȫ������Ϊ0
		memset(number, '0', n);
		number[n] = '\0';//��nλ��Ϊ'\0'
		while (!Increment(number))
		{
			PrintNumber(number);
		}
		delete[]number;//ע��Ҫ�ͷ��ڴ�
	}
	bool Increment(char* number) {//�βδ���char*ָ��
		bool isOverflow = false;//����Ƿ�Խ��
		int nTakeOver = 0;//�洢��λ
		int nLength = strlen(number);//����Ϊn,����n+1 ɨ��ֱ������һ���ַ���������'\0'Ϊֹ��Ȼ�󷵻ؼ�����ֵ(���Ȳ�����'\0')��
		for (int i = nLength - 1; i >= 0; i--)
		{
			int nSum = number[i] - '0' + nTakeOver; //
			if (i == nLength - 1) //����Ǹ�λ��ֵ,��Ӽ�
			{
				nSum++;
			}



			if (nSum >= 10)
				//�н�λ
			{
				if (i == 0)	//��������λ�н�λ��˵�������˸����õ����ֵ��Խ��
				{
					isOverflow = true;
				}
				else//�����λ�н�λ
				{
					nTakeOver = 1;
					number[i] = nSum - 10 + '0';//�Ե�iλ�������� Ϊ0
				}
			}
			else//û�н�λ
				//���õ�iλ����
				//��ֱ������ѭ��
			{
				number[i] = nSum + '0';
				break;
			}
		}
		return isOverflow;
	}
	void PrintNumber(char* number)
		//�βδ���char*ָ�룬�˴��ı��β�numberָ���λ�ã�����ʹԭʼ��numberָ����ָλ�øı�
	{
		string s = "";
		bool isBegin0 = true;
		while (*number != '\0')
		{
			if (isBegin0 && *number != '0')
				isBegin0 = false;
			//����'0'�������
			if (!isBegin0)
			{
				printf("%c", *number);
			}
			number++;
		}
		printf("\t");
	}
};

/*
�ⷨ���������ⷨstring��
*/

class Solution_3 {
public:
	vector<int> res;
	vector<int> printNumbers(int n) {
		if (n <= 0) return res;
		//����һ�����������ֵ���ַ�����
		string number(n, '0');
		//��ʼȫ������Ϊ0
		while (!Increment(number))
		{
			saveNumber(number);
		}
		return res;
	}
	bool Increment(string& number) {
		//ע��Ҫʹ�����ô��ݣ������޷��޸�number
		bool isOverflow = false;//����Ƿ�Խ��
		int nTakeOver = 0;//�洢��λ
		int nLength = number.size();
		for (int i = nLength - 1; i >= 0; i--)
		{
			int nSum = number[i] - '0' + nTakeOver;
			if (i == nLength - 1)
				//����ǵ�һλ����λ
			{
				nSum++;
			}
			if (nSum >= 10)//�н�λ
			{
				if (i == 0)
					//��������λ�н�λ��˵�������˸����õ����ֵ��Խ��
				{
					isOverflow = true;
				}
				else
				{
					nTakeOver = 1;
					number[i] = nSum - 10 + '0';//�Ե�iλ��������
				}
			}
			else//û�н�λ
				//���õ�iλ����
				//��ֱ������ѭ��
			{
				number[i] = nSum + '0';
				break;
			}
		}
		return isOverflow;
	}
	void saveNumber(string number)
		//���ڴ˴����������Ҫ�޸�number����˲���Ҫ������
	{
		string s = "";
		bool isBegin0 = true;
		string::iterator it = number.begin();
		while (it != number.end())
		{
			if (isBegin0 && *it != '0') isBegin0 = false;
			if (!isBegin0)
			{
				s += *it;
			}
			it++;
		}
		int num = stoi(s);
		res.push_back(num);
	}
};

/*
�ⷨ��:
*/
class Solution_4
{
public:
	vector<int> res;
	vector<int> printNumbers(int n) {
		if (n <= 0) return res;
		string number(n, '0');
		for (int i = 0; i <= 9; i++)
			//�Ӹ�λ����λ����ȫ����
		{
			number[0] = i + '0';//���ַ�����ֵ
			permutationNumbers(number, n, 1);//������һλ
		}
		return res;
	}
	//������ȫ����
	void permutationNumbers(string& number, int length, int index) {
		if (index == length) {//�ݹ�߽�
			saveNumber(number);//�洢���
			return;
		}
		else
		{
			for (int i = 0; i <= 9; i++)
			{
				number[index] = '0' + i;//���õ�indexλ���ַ�
				permutationNumbers(number, length, index + 1);
			}
		}
	}
	//�洢���
	//ֻ�ܴ洢ǰ����0������
	void saveNumber(string number) {
		bool isBegin0 = true;
		string tempStr = "";
		string::iterator it = number.begin();
		while (it != number.end())
		{
			if (isBegin0 && *it != '0') isBegin0 = false;
			if (!isBegin0) {
				tempStr += *it;
			}
			it++;
		}
		//�Ӹ�λ����λȫ���У�Ҫע�����ַ�Ϊ0ʱ��tempStrΪ�գ�����ִ��stoi
		if (tempStr != "") {
			int tempNum = stoi(tempStr);
			res.push_back(tempNum);
		}
	}
};

int main() {

	int n = 4;
	/*
	vector<int> v1 = Solution_4().printNumbers(n);
	string output = Output().integerVectorToString(v1);
	cout << output << endl;
	*/

	//�ⷨ����
	Solution_2().printNumbers(n);
	system("pause");
	return 0;
}

