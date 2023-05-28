#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

//      Huawei 集五福

//      作为近年来大家喜闻乐见迎新春活动，
//      集合爱国福、富强福、和谐福、友善福、敬业福即可分享超大红包。
//      以 0 和 1 组成的长度为 5 的字符串代表每个人所得到的福卡，
//      每一位代表一种福卡，1 表示已经获得该福卡，单类型福卡不超过 1 张，
//      随机抽取一个小于 10 人团队，求该团队最多可以集齐多少套五福？
//      输入描述
//          输入若干个由0、1组成的长度等于5的字符串，代表团队中每个人福卡获得情况。
//          注意1：1人也可以是一个团队 注意2：1人可以有0到5张福卡，但福卡不能重复
//      输出描述
//          输出该团队最多能凑齐多少套五福
//      示例一
//          输入
//              11001,11101
//          输出
//              0
//      示例二
//          输入
//              11101,10111
//          输出
//              1

int generateRandomNum(int low, int high);
string generateRandomString(int n);
vector<string> generateRandomStringVector(int n, int low, int high);
void printString(string s);
void printStringVecElement(vector<string> vec);

int GatheringFiveBlessings(vector<string> vec);

int main()
{
    int n = generateRandomNum(1, 10);
    vector<string> strs = generateRandomStringVector(n, 5, 5);
    printStringVecElement(strs);
    int ans_A = GatheringFiveBlessings(strs);
    printf("该团队最多能凑齐 %d 套五福。\n", ans_A);
}

int generateRandomNum(int low, int high)
{
    srand((int)time(0));
    return (rand() % (high - low + 1)) + low;
}

void generateRandomString(int n, string &str)
{
    char arr[] = "01";
    for (int i = 0; i < n; i++)
    {
        int index = rand() % (sizeof(arr) - 1);
        str += arr[index];
    }
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

int GatheringFiveBlessings(vector<string> vec)
{
    int l = vec.size();
    int ans = l;
    int tem = 0;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < l; j++)
        {
            tem += (vec[j][i] - '0');
        }
        ans = min(tem, ans);
    }
    return ans;
}