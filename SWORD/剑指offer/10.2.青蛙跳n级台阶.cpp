
#include<cmath>

//青蛙每次可以跳1级、2级、n级。
int jumpFloor(int number) {
	return pow(2, number - 1);
}