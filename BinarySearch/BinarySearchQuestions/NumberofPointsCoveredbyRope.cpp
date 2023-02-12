#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

//      给定一个 有序数组arr，代表坐落在X轴上的点，
//      给定一个正数K，代表绳子的长度，返回绳子最多压中几个点？
//      注意：即使绳子边缘处盖住点也算盖住

int generateRandomNum(int low, int high);
vector<int> generateRandomVec(int low, int high, int len);
void printVec(vector<int> &vec);

int NumberofPointsCoveredbyRope_A(vector<int> vec, int K);
int NumberofPointsCoveredbyRope_B(vector<int> vec, int K);
int BinaryNumberOfPointsCoveredbyRope_B(vector<int> vec, int i, int target);

int main()
{
    int n = generateRandomNum(1, 20);
    vector<int> vec = generateRandomVec(1, 100, n);
    sort(vec.begin(), vec.end());
    int K = generateRandomNum(1, 50);
    printVec(vec);
    int ans_A = NumberofPointsCoveredbyRope_A(vec, K);
    int ans_B = NumberofPointsCoveredbyRope_B(vec, K);
    printf("绳子的长度为 %d。最多压住 %d 个点。\n", K, ans_A);
    printf("绳子的长度为 %d。最多压住 %d 个点。\n", K, ans_B);
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

// 滑动窗口：
// Time: O(n)
// Space: O(1)
int NumberofPointsCoveredbyRope_A(vector<int> vec, int K)
{
    int l = vec.size();
    int left = 0;
    int right = 0;
    int ans = 0;
    while (left < l)
    {
        while (right < l && vec[right] - vec[left] <= K)
        {
            right++;
        }
        ans = max(ans, right - left);
        left++;
    }
    return ans;
}

// 二分查找：
// Time: O(NlogN)
// Space: O(1)
int NumberofPointsCoveredbyRope_B(vector<int> vec, int K)
{
    int l = vec.size();
    int ans = 1;
    for (int i = 0; i < l; i++)
    {
        int tem = BinaryNumberOfPointsCoveredbyRope_B(vec, i, vec[i] - K);
        ans = max(ans, i - tem + 1);
    }
    return ans;
}

int BinaryNumberOfPointsCoveredbyRope_B(vector<int> vec, int i, int target)
{
    int left = 0;
    int right = i;
    int ans = right;
    while (left <= right)
    {
        int mid = left + ((right - left) >> 1);
        if (vec[mid] >= target)
        {
            ans = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return ans;
}