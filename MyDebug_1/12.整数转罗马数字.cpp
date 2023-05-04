#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <unordered_map>
#include <string>
#include <chrono>
using namespace std;

string intToRoman(int num) {
    const pair<int, string> valueSymbols[] = {
    {1000, "M"},
    {900,  "CM"},
    {500,  "D"},
    {400,  "CD"},
    {100,  "C"},
    {90,   "XC"},
    {50,   "L"},
    {40,   "XL"},
    {10,   "X"},
    {9,    "IX"},
    {5,    "V"},
    {4,    "IV"},
    {1,    "I"},
    };
    string s;
    for (const auto& [value, symbol] : valueSymbols)
    {
        while (num >= value)
        {
            num -= value;
            s += symbol;
        }
        if (num == 0)break;
    }
    return s;
}

//void main()
//{
//	auto start1 = std::chrono::high_resolution_clock::now(); //��¼��ǰʱ��
//	cout << intToRoman(123231) << endl;
//	auto end1 = std::chrono::high_resolution_clock::now(); //��¼����ʱ��
//
//	std::chrono::duration<float> duration1 = end1 - start1; //��¼�����˶೤ʱ��
//
//	std::cout << duration1.count() << "s" << std::endl; //�������ʱ��
//
//	system("pause");
//}	