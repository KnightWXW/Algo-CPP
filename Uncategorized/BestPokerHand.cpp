#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

//      LeetCode 2347. 最好的扑克手牌

//      链接：https://leetcode.cn/problems/best-poker-hand/

//      给你一个整数数组 ranks 和一个字符数组 suit 。
//      你有 5 张扑克牌，第 i 张牌大小为 ranks[i] ，花色为 suits[i] 。
//      下述是从好到坏你可能持有的 手牌类型 ：
//          "Flush"：同花，五张相同花色的扑克牌。
//          "Three of a Kind"：三条，有 3 张大小相同的扑克牌。
//          "Pair"：对子，两张大小一样的扑克牌。
//          "High Card"：高牌，五张大小互不相同的扑克牌。
//      请你返回一个字符串，表示给定的 5 张牌中，你能组成的 最好手牌类型 。
//      注意：返回的字符串 大小写 需与题目描述相同。
//      示例 1：
//          输入：ranks = [13,2,3,1,9], suits = ["a","a","a","a","a"]
//          输出："Flush"
//          解释：5 张扑克牌的花色相同，所以返回 "Flush" 。
//      示例 2：
//          输入：ranks = [4,4,2,4,4], suits = ["d","a","a","b","c"]
//          输出："Three of a Kind"
//          解释：第一、二和四张牌组成三张相同大小的扑克牌，所以得到 "Three of a Kind" 。
//              注意我们也可以得到 "Pair" ，但是 "Three of a Kind" 是更好的手牌类型。
//              有其他的 3 张牌也可以组成 "Three of a Kind" 手牌类型。
//      示例 3：
//          输入：ranks = [10,10,2,12,9], suits = ["a","b","c","a","d"]
//          输出："Pair"
//          解释：第一和第二张牌大小相同，所以得到 "Pair"。
//              我们无法得到 "Flush" 或者 "Three of a Kind"。
//      提示：
//          ranks.length == suits.length == 5
//          1 <= ranks[i] <= 13
//          'a' <= suits[i] <= 'd'
//          任意两张扑克牌不会同时有相同的大小和花色。


int generateRandomNum(int low, int high);
void printVecElement(vector<int> &vec);
vector<int> generateRandomVec(int low, int high, int len);
string generateRandomString(int n);
void printString(string s);
vector<string> generateRandomStringVector(int n, int low, int high);
void printStringVecElement(vector<string> vec);

string BestPokerHand(vector<int>& ranks, vector<string>& suits);

int main()
{
    int n = generateRandomNum(1, 20);
    vector<int> vec = generateRandomVec(-100, 100, n);
    int k = generateRandomNum(1, 21);
    printf("k 为 %d 时, 数组元素为：\n", k);
    printVecElement(vec);
    bool ans = CanArrange(vec, k);
    printBool(ans);
}

int generateRandomNum(int low, int high)
{
    srand((int)time(0));
    return (rand() % (high - low + 1)) + low;
}

vector<int> generateRandomVec(int low, int high, int len)
{
    vector<int> vec;
    srand(time(0));
    for (int i = 0; i < len; i++)
    {
        int v = (rand() % (high - low + 1)) + low;
        vec.push_back(v);
    }
    return vec;
}

void printVecElement(vector<int> &vec)
{
    printf("vector的元素依次为：");
    for (int i = 0; i < vec.size(); i++)
    {
        printf("%d ", vec[i]);
    }
    printf("\n");
}

string generateRandomString(int n)
{
    string str = "";
    srand((int)time(0));
    char arr[] = "23456789";
    for (int i = 0; i < n; i++)
    {
        int index = rand() % (sizeof(arr) - 1);
        str += arr[index];
    }
    return str;
}

void printString(string s)
{
    printf("%s\n", s.c_str());
}

vector<string> generateRandomStringVector(int n, int low, int high)
{
    vector<string> vec;
    srand((int)time(0));
    for (int i = 0; i < n; i++)
    {
        string tem = "";
        int l = (rand() % (high - low + 1)) + low;
        generateRandomString(l, tem);
        vec.push_back(tem);
    }
    return vec;
}

void printStringVecElement(vector<string> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        printf("%s\n", vec[i].c_str());
    }
    printf("\n");
}

void printBool(bool b)
{
    if (b == true)
    {
        printf("True\n");
    }
    else
    {
        printf("False\n");
    }
}

string BestPokerHand(vector<int>& ranks, vector<char>& suits){
    
}