#include <ctime>
#include <stdio.h>
#include <cstdlib>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

//      Huawei: 参赛排名

//      小明发现他参加Online Judge的比赛表现极不稳定，于是他翻开历史记录，
//      发现他在每一轮的比赛中他的排名R都能整除参赛人数N(包括他自己)，
//      于是他每次参赛都会预测他的排名情况，以给自己更大的自信。
//      输入：
//          参赛人数 N
//      输出：
//          在一行输出小明参赛可能获得的排名数S
//          以及从小到大输出各个排名Ri(0< i < S)
//      输入样例1：
//          10
//      输出样例1：
//          4 1 2 5 10

int generateRandomNum(int low, int high);
void printVecElement(vector<int> &vec);

vector<int> ContestRanking(int num);

int main()
{
    int n = generateRandomNum(1, 999999);
    vector<int> vec = ContestRanking(n);
    printf("当有 %d 名选手参赛时，小明参赛可能获得的排名为：\n", n);
    printVecElement(vec);
}

int generateRandomNum(int low, int high)
{
    srand((int)time(0));
    return (rand() % (high - low + 1)) + low;
}

void printVecElement(vector<int> &vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        printf("%d ", vec[i]);
    }
    printf("\n");
}

// 模拟：
// Time: O(N^1/2)
// Space: O(1)
vector<int> ContestRanking(int num)
{
    vector<int> ans;
    int k = 1;
    while (k <= (int)(sqrt(num)))
    {
        if (num % k == 0)
        {
            ans.push_back(k);
            ans.push_back(num / k);
        }
        k++;
    }
    sort(ans.begin(), ans.end());
    return ans;
}