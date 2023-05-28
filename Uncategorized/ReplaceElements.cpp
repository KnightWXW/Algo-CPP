#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

//      LeetCode 1299. 将每个元素替换为右侧最大元素

//      链接：https://leetcode.cn/problems/replace-elements-with-greatest-element-on-right-side/

//      给你一个数组 arr ，请你将每个元素用它右边最大的元素替换，
//      如果是最后一个元素，用 -1 替换。
//      完成所有替换操作后，请你返回这个数组。
//      示例 1：
//          输入：arr = [17,18,5,4,6,1]
//          输出：[18,6,6,6,1,-1]
//      解释：
//          - 下标 0 的元素 --> 右侧最大元素是下标 1 的元素 (18)
//          - 下标 1 的元素 --> 右侧最大元素是下标 4 的元素 (6)
//          - 下标 2 的元素 --> 右侧最大元素是下标 4 的元素 (6)
//          - 下标 3 的元素 --> 右侧最大元素是下标 4 的元素 (6)
//          - 下标 4 的元素 --> 右侧最大元素是下标 5 的元素 (1)
//          - 下标 5 的元素 --> 右侧没有其他元素，替换为 -1
//      示例 2：
//          输入：arr = [400]
//          输出：[-1]
//          解释：下标 0 的元素右侧没有其他元素。
//      提示：
//          1 <= arr.length <= 104
//          1 <= arr[i] <= 105

int generateRandomNum(int low, int high);
vector<int> generateRandomVec(int low, int high, int len);
void printVec(vector<int> &vec);

vector<int> ReplaceElements(vector<int> &arr);

int main()
{
    int n = generateRandomNum(1, 100);
    vector<int> vec = generateRandomVec(1, 100, n);
    printVec(vec);
    vector<int> ans = ReplaceElements(vec);
    printf("每个元素用它右边最大的元素替换后，数组为:\n");
    printVec(ans);
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

vector<int> ReplaceElements(vector<int> &arr)
{
    int l = arr.size();
    vector<int> ans(l, -1);
    int maxVal = arr[l - 1];
    for (int i = l - 2; i >= 0; i--)
    {
        ans[i] = maxVal;
        if (arr[i] > maxVal)
        {
            maxVal = arr[i];
        }
    }
    return ans;
}