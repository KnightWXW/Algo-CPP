#include <stdio.h>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

//      给定一个无序数组arr（arr[i] >= 0 元素 必须为正）与一个正整数 k，
//      找到 arr 的所有 子数组 里，
//      累加和 等于 k 并且长度最大的子数组，并返回其长度。

int generateRandomNum(int low, int high);
void printVecElement(vector<int> vec);
vector<int> generateRandomVec(int low, int high, int len);
int digitSum(vector<int> vec, int start, int end);
int longestSubArrayLengthInPositiveArrayEqualSum_A(vector<int> vec, int k);
int longestSubArrayLengthInPositiveArrayEqualSum_B(vector<int> vec, int k);
int longestSubArrayLengthInPositiveArrayEqualSum_C(vector<int> vec, int k);

int main()
{
    vector<int> vec = generateRandomVec(0, 1, 10);
    int sumAll = digitSum(vec, 0, vec.size() - 1);
    printVecElement(vec);
    int k = generateRandomNum(1, sumAll);
    printf("(滑动窗口)累加和等于%d,并且长度最大的子数组的长度为%d\n", k, longestSubArrayLengthInPositiveArrayEqualSum_A(vec, k));
    printf("(暴力循环)累加和等于%d,并且长度最大的子数组的长度为%d\n", k, longestSubArrayLengthInPositiveArrayEqualSum_B(vec, k));
    printf("(前缀和数组)累加和等于%d,并且长度最大的子数组的长度为%d\n", k, longestSubArrayLengthInPositiveArrayEqualSum_C(vec, k));
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

int digitSum(vector<int> vec, int start, int end)
{
    int sum = 0;
    for (int i = start; i <= end; i++)
    {
        sum += vec[i];
    }
    return sum;
}

// 滑动窗口：
// Time: O(n)
// Space: O(1)
int longestSubArrayLengthInPositiveArrayEqualSum_A(vector<int> vec, int k)
{
    if(vec.size() <= 0){
        return 0;
    }

    int ans = 0, sum = vec[0];
    int left = 0, right = 0;
    while (right < vec.size())
    {
        if (sum < k)
        {   
            right++;
            if(right >= vec.size()){
                break;
            }
            sum += vec[right];
        }
        else if (sum > k)
        {
            sum -= vec[left];
            left++;
        }
        else
        {
            ans = max(right - left + 1, ans);
            right++;
            if(right >= vec.size()){
                break;
            }
            sum += vec[right];
        }
    }
    return ans;
}

// 暴力循环：
// Time: O(n^3)
// Space: O(1)
int longestSubArrayLengthInPositiveArrayEqualSum_B(vector<int> vec, int k){
    int ans = 0; 
    for (int i = 0; i < vec.size();i++){
        for(int j = i ; j < vec.size();j++){
            if (digitSum(vec, i, j) == k){
                ans = max(j - i + 1, ans);
            }
        }
    }
    return ans;
}

// 前缀和数组：
// Time: O(n^2)
// Space: O(n)
int longestSubArrayLengthInPositiveArrayEqualSum_C(vector<int> vec, int k){
    int ans = 0; 
    vector<int> sumArr (vec.size() + 1, 0);

    for (int i = 1; i < sumArr.size(); i++){
        sumArr[i] = sumArr[i - 1] + vec[i - 1];
    }

    for (int i = 0; i <= vec.size(); i++){
        for (int j = i ; j <= vec.size(); j++){
            if(sumArr[j] - sumArr[i] == k){
                ans = max(ans, j - i);
            }
        }
    }
    return ans;
}