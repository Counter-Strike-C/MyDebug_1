#include "Common.cpp"

int divide(int dividend, int divisor) {
    if (dividend == 0) {
        return 0;
    }
    if (dividend == INT_MIN && divisor == -1) {
        return INT_MAX;
    }
    int result = dividend / divisor;
    return result;
}

//void main()
//{
//
//	cout << divide(10, 3);
//	system("pause");
//}