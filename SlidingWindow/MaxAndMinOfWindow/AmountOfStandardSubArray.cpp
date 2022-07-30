#include <stdio.h>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <deque>

using namespace std;

//      给定一个整型数组arr，和一个整数 k,
//      arr 中的 某个 子数组 sub，如果想要达标，
//      必须满足：sub 中 最大值 减去 sub 中 最小值 小于等于 k,
//      返回 arr 中 达标子数组 的 数量。

int generateRandomNum(int low, int high);
void printVecElement(vector<int> vec);
vector<int> generateRandomVec(int low, int high, int len);
int minElementOfVec(vector<int> vec, int start, int end);
int maxElementOfVec(vector<int> vec, int start, int end);
int amountOfStandardSubArray_A(vector<int> vec, int k);
int amountOfStandardSubArray_B(vector<int> vec, int k);

int main()
{
    vector<int> vec = generateRandomVec(1, 10, 10);
    int maxEle = maxElementOfVec(vec,0, vec.size() - 1);
    int minEle = minElementOfVec(vec,0, vec.size() - 1);
    int k = generateRandomNum(minEle, maxEle);
    printVecElement(vec);
    int ans_A = amountOfStandardSubArray_A(vec, k);
    int ans_B = amountOfStandardSubArray_B(vec, k);
    printf("arr 中满足 子数组sub 中 最大值 减去 sub 中 最小值 小于等于 %d 的子数组的个数为 %d\n",k, ans_A);
    printf("arr 中满足 子数组sub 中 最大值 减去 sub 中 最小值 小于等于 %d 的子数组的个数为 %d\n",k, ans_B);
}

int generateRandomNum(int low, int high)
{
    srand((int)time(0));
    return (rand() % (high - low + 1)) + low;
}

void printVecElement(vector<int> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        printf("%d ", vec[i]);
    }
    printf("\n");
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

int minElementOfVec(vector<int> vec, int start, int end)
{
    int minNum = INT_MAX;
    for (int i = start; i <= end; i++)
    {
        minNum = min(vec[i], minNum);
    }
    return minNum;
}

int maxElementOfVec(vector<int> vec, int start, int end)
{
    int maxNum = INT_MIN;
    for (int i = start; i <= end; i++)
    {
        maxNum = max(vec[i], maxNum);
    }
    return maxNum;
}

int q(vector<int> vec){
    return vec[0] + 1;
}


// 双端队列
// Time: O(N)
// Space: O(N)
int amountOfStandardSubArray_A(vector<int> vec, int k)
{
    if (vec.size() <= 0 || k < 0)
    {
        return 0;
    }

    deque<int> maxDeque;
    deque<int> minDeque;

    int l = vec.size();
    int ans = 0;
    // 推论一：   若 vec[left : right] 上 max - min <= k
    //           则 vec[left : right] 之间的所有的子数组 max' - min' <= k
    // 推论二：   若 vec[left : right] 上 max - min > k
    //           则 vec[left' : right] (left' < left)
    //             包含 vec[left : right] 的所有子数组 max - min > k
    //           则 vec[left : right'] (right' > right)
    //             包含 vec[left : right] 的所有子数组 max - min > k

    // right 不回退：判断每个 left 对应的 right 所到位置：
    int right = 0;
    for (int left = 0; left < l; left++)
    {
        while (right < l)
        {
            while (!maxDeque.empty() && vec[maxDeque.back()] <= vec[right])
            {
                maxDeque.pop_back();
            }
            maxDeque.push_back(right);

            while (!minDeque.empty() && vec[minDeque.back()] >= vec[right])
            {
                minDeque.pop_back();
            }
            minDeque.push_back(right);

            if (vec[maxDeque.front()] - vec[minDeque.front()] <= k)
            {
                right++;
            }
            else
            {
                break;
            }
        }

        ans += right - left;
        if (maxDeque.front() == left)
        {
            maxDeque.pop_front();
        }
        if (minDeque.front() == left)
        {
            minDeque.pop_front();
        }
    }
    return ans;
}

// 暴力循环：
// Time: O(N^3)
// Space: O(1)
int amountOfStandardSubArray_B(vector<int> vec, int k){
    if (vec.size() <= 0 || k < 0)
    {
        return 0;
    }

    int ans = 0;
    for (int left = 0; left < vec.size(); left++){
        for (int right = left; right < vec.size(); right++){
            int minVal = minElementOfVec(vec, left, right);
            int maxVal = maxElementOfVec(vec, left, right);
            if (maxVal - minVal <= k){
                ans++;
            } 
        }
    }
    return ans;
}