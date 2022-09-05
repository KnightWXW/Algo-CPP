#include <stdio.h>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

vector<int> generateRandomVec(int low, int high, int len);
void printVecElement(vector<int> vec);
void countSort_A(vector<int> &vec);

int main()
{
    vector<int> vec_A = generateRandomVec(-100, 100, 10);
    vector<int> vec_B ;
    vec_B.assign(vec_A.begin(), vec_A.end());

    printf("数组未排序 前为：\n");
    printVecElement(vec_A);
    printVecElement(vec_B);

    countSort_A(vec_A);
    countSort_A(vec_B);

    printf("计数排序 后为：\n");
    printVecElement(vec_A);
    printVecElement(vec_B);
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

// 计数排序：
// 无 稳定性：
// Time: O(n ^ 2)
// Space: O(1)
void countSort_A(vector<int> &vec)
{
    int l = vec.size();
    int maxVal = INT_MIN;
    int minVal = INT_MAX;
    for (int i = 0; i < l; i++)
    {
        maxVal = max(maxVal, vec[i]);
        minVal = min(minVal, vec[i]);
    }

    int n = maxVal - minVal + 1;
    vector<int> help(n, 0);
    for (int i = 0; i < l; i++)
    {
        help[vec[i] - minVal]++;
    }

    int index = 0;
    for (int i = 0; i < n; i++)
    {
        while (help[i] > 0)
        {
            vec[index++] = i + minVal;
            help[i]--;
        }
    }
}

// 计数排序：
// 有 稳定性：
// Time: O(n ^ 2)
// Space: O(1)
void countSort_B(vector<int> &vec)
{
    int l = vec.size();
    int maxVal = INT_MIN;
    int minVal = INT_MAX;
    for (int i = 0; i < l; i++)
    {
        maxVal = max(maxVal, vec[i]);
        minVal = min(minVal, vec[i]);
    }

    int n = maxVal - minVal + 1;
    vector<int> help(n, 0);
    for (int i = 0; i < l; i++)
    {
        help[vec[i] - minVal]++;
    }
    for (int i = 1; i < l; i++)
    {
        help[i] += help[i - 1];
    }

    for (int i = l - 1; i >= 0; i--)
    {
        int cntIndex = vec[i] - minVal;
        int index = help[cntIndex] - 1;
        help[cntIndex]--;
        vec[index] = vec[i];
    }
}
