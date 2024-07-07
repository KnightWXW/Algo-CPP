#include <stdio.h>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <math.h>

using namespace std;

//      Huawei: 雪场海拔

//      某雪场共有 N 座雪山，数组 altitude 中存储了各雪山海拔
//      (精确到整数)，雪场出售新手票与老手票。新手区票价较高。
//      若该雪场内最高海拔与最低海拔的差值大于difference, 则为老手区；否则为新手区。
//      现在是滑雪活动旺季，雪场经营者希望获得更大收益，想要将整个雪场改造为新手雪场。
//      改造某座雪山海拔高度的成本为：变更高度的平方(注意：变更高度仅为整数)。
//      变更工程可以增加雪山海拔，也可以降低雪山海拔。
//      请问雪场经营者改造需要投入的最少成本是多少？
//      (所有改造雪山的成本之和)，结果需要取模1e9 + 7
//      示例1：
//          输入：altitude = [5,1,4,3,8], difference = 3;
//          输出：8
//      示例2：
//          输入：altitude = [1,2,99999,3,100000], difference = 3;
//          输出：998679962

int generateRandomNum(int low, int high);
void printVecElement(vector<int> vec);
vector<int> generateRandomVec(int low, int high, int len);

int SnowFieldAltitude(vector<int> altitude, int difference);

int main()
{
    int n = generateRandomNum(0, 10);
    int dif = generateRandomNum(0, 10);
    vector<int> vec = generateRandomVec(0, 100, n);
    printVecElement(vec);
    int ans = SnowFieldAltitude(vec, dif);
    printf("difference 为 %d 时，雪场经营者改造需要投入的最少成本是为 %d。\n", dif, ans);

    int dif2 = 3;
    vector<int> vec2 = {5, 1, 4, 3, 8};
    printVecElement(vec2);
    int ans2 = SnowFieldAltitude(vec2, dif2);
    printf("difference 为 %d 时，雪场经营者改造需要投入的最少成本是为 %d。\n", dif2, ans2);
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

int SnowFieldAltitude(vector<int> altitude, int difference)
{
    int l = altitude.size();
    int ans = INT_MAX;
    int minVal = *min_element(altitude.begin(), altitude.end());
    int maxVal = *max_element(altitude.begin(), altitude.end());
    printf("%d  ^^^^%^^  %d  \n", minVal, maxVal);
    int low = minVal + difference;
    int high = maxVal - difference;
    if (low >= high)
    {
        return 0;
    }
    printf("%d  /////  %d  \n", low, high);
    for (int i = low; i <= high; i++)
    {
        int sum = 0;
        for (int j = 0; j < l; j++)
        {
            if ((altitude[j] >= i - difference) && (altitude[j] <= i + difference))
            {
                continue;
            }
            else
            {
                sum += (altitude[j] - i) * (altitude[j] - i);
            }
        }
        ans = min(ans, sum);
    }
    return ans;
}