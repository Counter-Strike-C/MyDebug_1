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

string longestCommonPrefix(vector<string>& strs) {
    int i = 0;
    int j = 0;
    string s;
    for (int i=0; i < strs[0].length(); i++)
    {
        
        char c = strs[0][i];
       for(int j=1;j<strs.size();j++)
        {
           if (i == strs[j].length() || strs[j][i] != c)
               return strs[0].substr(0, i);
        }
    }
    return strs[0];
}

//void main()
//{
//    auto start1 = std::chrono::high_resolution_clock::now(); //��¼��ǰʱ��
//    //cout << intToRoman(123231) << endl;
//    auto end1 = std::chrono::high_resolution_clock::now(); //��¼����ʱ��
//
//    std::chrono::duration<float> duration1 = end1 - start1; //��¼�����˶೤ʱ��
//
//    std::cout << duration1.count() << "s" << std::endl; //�������ʱ��
//
//    system("pause");
//}