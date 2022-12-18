#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

//      LeetCode 881. 救生艇

//      链接：https://leetcode.cn/problems/boats-to-save-people/

//      给定数组 people 。people[i]表示第 i 个人的体重 ，船的数量不限，
//      每艘船可以承载的最大重量为 limit。
//      每艘船最多可同时载两人，但条件是这些人的重量之和最多为 limit。
//      返回 承载所有人所需的最小船数 。
//      示例 1：
//          输入：people = [1,2], limit = 3
//          输出：1
//          解释：1 艘船载 (1, 2)
//      示例 2：
//          输入：people = [3,2,2,1], limit = 3
//          输出：3
//          解释：3 艘船分别载 (1, 2), (2) 和 (3)
//      示例 3：
//          输入：people = [3,5,3,4], limit = 5
//          输出：4
//          解释：4 艘船分别载 (3), (3), (4), (5)
//      提示：
//          1 <= people.length <= 5 * 104
//          1 <= people[i] <= limit <= 3 * 104

int generateRandomNum(int low, int high);
vector<int> generateRandomVec(int low, int high, int len);
void printVec(vector<int> &vec);

int NumRescueBoats_A(vector<int> &people, int limit);
int NumRescueBoats_B(vector<int> &people, int limit);

int main()
{
    int n = generateRandomNum(1, 30);
    vector<int> vec_A = generateRandomVec(1, 30, n);
    vector<int> vec_B(vec_A);
    int limit = generateRandomNum(30, 50);
    printVec(vec_A);
    int ans_A = NumRescueBoats_A(vec_A, limit);
    int ans_B = NumRescueBoats_B(vec_B, limit);
    printf("承载所有人所需的最小船数 为 %d.\n", ans_A);
    printf("承载所有人所需的最小船数 为 %d.\n", ans_B);
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
    printf("vector的元素依次为：");
    for (int i = 0; i < vec.size(); i++)
    {
        printf("%d ", vec[i]);
    }
    printf("\n");
}

// 贪心 + 双指针：
// Time: O(NlogN)
// Space: O(logN)
int NumRescueBoats_A(vector<int> &people, int limit)
{
    sort(people.begin(), people.end());
    int l = people.size();
    int boats = 0;
    int left = 0;
    int right = l - 1;
    while (left <= right)
    {
        if (people[left] + people[right] <= limit)
        {
            right--;
            left++;
            boats++;
        }
        else
        {
            right--;
            boats++;
        }
    }
    return boats;
}

// 贪心 + 双指针(简写)：
// Time: O(NlogN)
// Space: O(logN)
int NumRescueBoats_B(vector<int> &people, int limit)
{
    sort(people.begin(), people.end());
    int l = people.size();
    int boats = 0;
    int left = 0;
    int right = l - 1;
    while (left <= right)
    {
        if (people[left] + people[right] <= limit)
        {
            left++;
        }
        right--;
        boats++;
    }
    return boats;
}