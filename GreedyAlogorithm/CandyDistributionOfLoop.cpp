#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

//      网易: 环形分发糖果

//      给定一个正数数组arr，表示每个小朋友的得分
//      任何两个相邻的小朋友，如果得分一样，怎么分糖果无所谓，
//      但如果得分不一样，分数大的一定要比分数少的多拿一些糖果
//      假设所有的小朋友坐成一个环形，返回在不破坏上一条规则的情况下，
//      需要的最少糖果数

int generateRandomNum(int low, int high);
vector<int> generateRandomVec(int low, int high, int len);
void printVec(vector<int> &vec);

int CandyDistributionOfLooped(vector<int> &ratings);

int main()
{
    int n = generateRandomNum(1, 30);
    vector<int> vec = generateRandomVec(1, 100, n);
    printVec(vec);
    int ans = CandyDistributionOfLooped(vec);
    printf("需要准备的 最少糖果数目为 %d。", ans);
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

void printVec(vector<int> &vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        printf("%d ", vec[i]);
    }
    printf("\n");
}

int CandyDistributionOfLooped(vector<int> &ratings)
{
    int l = ratings.size();
    if (l == 0)
    {
        return 0;
    }
    else if (l == 1)
    {
        return 1;
    }
    int ans = 0;
    int minIndex = -1;
    int minVal = INT_MAX;
    for (int i = 0; i < l; i++)
    {
        if (ratings[i] < minVal)
        {
            minVal = ratings[i];
            minIndex = i;
        }
    }
    vector<int> arr(l, 0);
    for (int i = 0; i < l; i++)
    {
        arr[i] = ratings[(i + minIndex) % l];
    }
    arr.push_back(minVal);

    vector<int> leftArr(l + 1, 1);
    for (int i = 1; i <= l; i++)
    {
        if (arr[i] > arr[i - 1])
        {
            leftArr[i] = leftArr[i - 1] + 1;
        }
    }

    vector<int> rightArr(l + 1, 1);
    for (int i = l - 1; i >= 0; i--)
    {
        if (arr[i] > arr[i + 1])
        {
            rightArr[i] = rightArr[i + 1] + 1;
        }
    }

    for (int i = 0; i < l; i++)
    {
        ans += max(leftArr[i], rightArr[i]);
    }
    return ans;
}