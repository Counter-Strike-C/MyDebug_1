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

int romanToInt(string s) {
    unordered_map<char, int> symbolValues = {
     {'I', 1},
     {'V', 5},
     {'X', 10},
     {'L', 50},
     {'C', 100},
     {'D', 500},
     {'M', 1000},
    };

    int ans = 0;
    for (int i = 0; i < s.length(); i++)
    {
        int value = symbolValues[s[i]];
        if (i < s.length() && value < symbolValues[s[i + 1]])
            ans -= value;
        else
        {
            ans += value;
        }

    }

    return ans;
}

//void main()
//{
//    auto start1 = std::chrono::high_resolution_clock::now(); //记录当前时间
//    cout << intToRoman(123231) << endl;
//    auto end1 = std::chrono::high_resolution_clock::now(); //记录结束时间
//
//    std::chrono::duration<float> duration1 = end1 - start1; //记录经过了多长时间
//
//    std::cout << duration1.count() << "s" << std::endl; //输出运行时间
//
//    system("pause");
//}