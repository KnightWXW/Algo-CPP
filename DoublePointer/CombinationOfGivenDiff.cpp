#include <stdio.h>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

//      Huawei: 给定差值的组合

//      给定一个数组，每个元素的值是唯一的，
//      找出其中两个元素相减等于给定差值diff的所有不同组合的个数。
//      组合是无序的：如(1,4) 和 (4,1) 表示同一个组合。
//      示例1：
//          输入：
//              3
//              1 3 2 5 4
//          输出:
//              2
//      示例2：
//          输入：
//              -1
//              1 2 3
//          输出:
//              2

int generateRandomNum(int low, int high);
void printVecElement(vector<int> vec);
vector<int> generateRandomVec(int low, int high, int len);

int CombinationOfGivenDiff(vector<int> vec, int diff);

int main()
{
    int n = generateRandomNum(0, 30);
    vector<int> vec = generateRandomVec(0, 100, n);
    int diff = generateRandomNum(0, 10);
    int ans_A = CombinationOfGivenDiff(vec, diff);
    printVecElement(vec);
    printf("数组中两个元素相减等于给定差值 %d 的所有不同组合的个数为 %d\n", diff, ans_A);
}

int generateRandomNum(int low, int high)
{
    srand((int)time(0));
    return (rand() % (high - low + 1)) + low;
}

vector<int> generateRandomVec(int low, int high, int len)
{
    srand((int)time(0));
    vector<int> vec;
    for (int i = 0; i < len; i++)
    {
        int v = (rand() % (high - low + 1)) + low;
        vec.push_back(v);
    }
    return vec;
}

void printVecElement(vector<int> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        printf("%d ", vec[i]);
    }
    printf("\n");
}

int CombinationOfGivenDiff(vector<int> vec, int diff)
{
    int l = vec.size();
    sort(vec.begin(), vec.end());
    int left = 0;
    int right = 1;
    int ans = 0;
    while (left < l && right < l)
    {
        if (left >= right)
        {
            right = left + 1;
        }
        else if (vec[right] - vec[left] > diff)
        {
            left++;
        }
        else if (vec[right] - vec[left] < diff)
        {
            right++;
        }
        else if (vec[right] - vec[left] == diff)
        {
            left++;
            right++;
            ans++;
        }
    }
    return ans;
}
