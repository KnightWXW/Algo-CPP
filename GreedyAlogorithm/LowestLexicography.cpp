#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

//      给定一个 字符串类型 的数组 strs，找到一种拼接方式，
//      使得把 所有字符串 拼起来 之后形成的 字符串 具有 最低的字典序。

void printStringVec(vector<string> vec);
void printString(string s);
bool cmp(const string &a, const string &b);
string lowestLexicography(vector<string> vec);

int main()
{
    vector<string> vec = {"abc", "a", "aa", "ab", "abcc", "aba"};
    printStringVec(vec);
    string ans = lowestLexicography(vec);
    printString(ans);
}

void printStringVec(vector<string> vec)
{
    for (auto s : vec)
    {
        printf("%s  ", s.c_str());
    }
    printf("\n");
}

void printString(string s)
{
    printf("%s\n", s.c_str());
}

bool cmp(const string &a, const string &b)
{
    return a + b < b + a;
}

// 贪心
// Time: O(NlogN)
// Space: O(N)
string lowestLexicography(vector<string> vec)
{
    sort(vec.begin(), vec.end(), cmp);
    // sort(vec.begin(), vec.end(), [](string a, string b)
    //      { return (a + b) < (b + a); });

    string ans = "";
    for (auto s : vec)
    {
        ans += s;
    }
    return ans;
}