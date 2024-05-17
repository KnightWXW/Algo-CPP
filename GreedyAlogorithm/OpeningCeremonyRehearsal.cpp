#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//      得物：开幕式排练

//      导演在组织进行大运会开幕式的排练，
//      其中一个环节是需要参演人员围成一个环形。演出人员站成了一圈，
//      出于美观度的考虑，导演不希望某一个演员身边的其他人比他低太多或者高太多。
//      现在给出n个参演人员的身高，问在他们站成一圈时，相邻演员的身高差的最大值至少是多少?
//      请你帮忙计算。
//      输入描述
//          输入包括两行，第一行有1个正整数，代表人数 n。
//          第二行有n个空格隔开的正整数h表示第i个演员的身高。
//      输出描述
//          输出包括一个正整数，表示答案。
//      输入：
//          5
//          2 1 1 3 2
//      输出：
//          1
//      输入：
//          2
//          10 20
//      输出：
//          10
//      样例1中排为1, 2, 3, 2, 1即可；样例2中排为10, 20即可

int generateRandomNum(int low, int high);
vector<int> generateRandomVec(int low, int high, int len);
void printVecElement(vector<int> &vec);

int OpeningCeremonyRehearsal(vector<int> vec);

int main()
{
    int n = generateRandomNum(1, 30);
    vector<int> vec = generateRandomVec(1, 1000, n);
    printVecElement(vec);
    int ans_A = OpeningCeremonyRehearsal(vec);
    printf("相邻演员的身高差的最大值至少为：%d\n", ans_A);
}

int generateRandomNum(int low, int high)
{
    srand((unsigned)time(NULL));
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
    for (int i = 0; i < vec.size(); i++)
    {
        printf("%d ", vec[i]);
    }
    printf("\n");
}

// 贪心: 排序后最大的在中间，左右递减，山形排列
// Time: O(N)
// Space: O(N)
int OpeningCeremonyRehearsal(vector<int> vec)
{
    int ans = 0;
    int l = vec.size();
    sort(vec.begin(), vec.end());
    if (l == 1)
    {
        return 0;
    }
    else if (l == 2)
    {
        return vec[1] - vec[0];
    }
    vector<int> tem;
    int index = l - 1;
    tem.push_back(vec[index--]);
    if ((l & 1) == 0)
    {
        tem.push_back(vec[index--]);
    }
    while (index >= 0)
    {
        tem.insert(tem.begin(), vec[index--]);
        tem.insert(tem.end(), vec[index--]);
    }
    ans = abs(tem[0] - tem[l - 1]);
    for (int i = 0; i < l - 1; i++)
    {
        ans = max(ans, abs(tem[i] - tem[i + 1]));
    }
    return ans;
}