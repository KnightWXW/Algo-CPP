#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

//      LeetCode 1775. 通过最少操作次数使数组的和相等

//      链接：https://leetcode.cn/problems/equal-sum-arrays-with-minimum-number-of-operations/

//      给你两个长度可能不等的整数数组 nums1 和 nums2。
//      两个数组中的所有值都在 1 到 6 之间（包含 1 和 6）。
//      每次操作中，你可以选择 任意 数组中的任意一个整数，
//      将它变成 1 到 6 之间 任意 的值（包含 1 和 6）。
//      请你返回使 nums1 中所有数的和与 nums2 中所有数的和相等的最少操作次数。
//      如果无法使两个数组的和相等，请返回 -1。
//      示例 1：
//          输入：nums1 = [1,2,3,4,5,6], nums2 = [1,1,2,2,2,2]
//          输出：3
//          解释：你可以通过 3 次操作使 nums1 中所有数的和与 nums2 中所有数的和相等。
//                以下数组下标都从 0 开始。
//              - 将 nums2[0] 变为 6 。 nums1 = [1,2,3,4,5,6], nums2 = [6,1,2,2,2,2] 。
//              - 将 nums1[5] 变为 1 。 nums1 = [1,2,3,4,5,1], nums2 = [6,1,2,2,2,2] 。
//              - 将 nums1[2] 变为 2 。 nums1 = [1,2,2,4,5,1], nums2 = [6,1,2,2,2,2] 。
//      示例 2：
//          输入：nums1 = [1,1,1,1,1,1,1], nums2 = [6]
//          输出：-1
//          解释：没有办法减少 nums1 的和或者增加 nums2 的和使二者相等。
//      示例 3：
//          输入：nums1 = [6,6], nums2 = [1]
//          输出：3
//          解释：你可以通过 3 次操作使 nums1 中所有数的和与 nums2 中所有数的和相等。以下数组下标都从 0 开始。
//              - 将 nums1[0] 变为 2。 nums1 = [2,6], nums2 = [1]。
//              - 将 nums1[1] 变为 2。 nums1 = [2,2], nums2 = [1]。
//              - 将 nums2[0] 变为 4。 nums1 = [2,2], nums2 = [4]。
//      提示：
//          1 <= nums1.length, nums2.length <= 105
//          1 <= nums1[i], nums2[i] <= 6

int generateRandomNum(int low, int high);
string generateRandomString(int n);
void printString(string s);
void printVecElement(vector<int> vec);

vector<int> MinOperationsOfMoveBalls(string boxes);

int main()
{
    int n = generateRandomNum(0, 4);
    string str = generateRandomString(n);
    printf("数字的字符串为：");
    printString(str);
    vector<string> vec = LetterCombinations_A(str);
    printf("它能表示的字母组合：\n");
    printStringVecElement(vec);
}

int generateRandomNum(int low, int high)
{
    srand((unsigned)time(NULL));
    return (rand() % (high - low + 1)) + low;
}

string generateRandomString(int n)
{
    string str = "";
    srand((int)time(0));
    char arr[] = "23456789";
    for (int i = 0; i < n; i++)
    {
        int index = rand() % (sizeof(arr) - 1);
        str += arr[index];
    }
    return str;
}

void printString(string s)
{
    printf("%s\n", s.c_str());
}

void printVecElement(vector<int> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        printf("%d ", vec[i]);
    }
    printf("\n");
}
