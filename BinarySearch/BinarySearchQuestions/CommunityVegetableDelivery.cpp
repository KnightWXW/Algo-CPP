#include <stdio.h>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

//      Huawei: 社区蔬菜配送

//      疫情期间，有一批社区的家庭需要配送爱心蔬菜，
//      每个社区的家庭个数用 communities 数组表示,
//      (下标表示社区编号，值表示对应社区的家庭个数,
//      例如, communities[0] == 5, 表示第 0 个社区有 5 个家庭)。
//      现有 num 个志愿者为这些社区家庭配送蔬菜，配送规则如下：
//      每个社区只能被分配一次任务，配送编号连续的若干个社区。
//      为每个家庭配送爱心蔬菜耗时均为 1 小时。
//      志愿者可以并行配送。
//      请合理分配志愿者，使得能够在最短的时间内完成配送任务，并返回所需要的小时数。
//      输入样例1:
//          2
//          40 10 20
//      输出样例 40
//      输入样例2:
//          2
//          1 1 6 2
//      输出样例 8
//      输入样例3:
//          3
//          1 2
//      输出样例 2

int generateRandomNum(int low, int high);
vector<int> generateRandomVec(int low, int high, int len);
void printVecElement(vector<int> vec);

bool HelperCommunityVegetableDelivery(int mid, int num, vector<int> communities);
int CommunityVegetableDelivery(int num, vector<int> communities);

int main()
{
    int n = generateRandomNum(1, 20);
    vector<int> communities = generateRandomVec(0, 50, n);
    int num = generateRandomNum(1, 100);
    int ans_A = CommunityVegetableDelivery(num, communities);
    printVecElement(communities);
    printf("志愿者个数为 %d 时, 完成配送任务的最少小时数是 %d\n", num, ans_A);
}

int generateRandomNum(int low, int high)
{
    srand((unsigned)time(NULL));
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

bool HelperCommunityVegetableDelivery(int mid, int num, vector<int> communities)
{
    int l = communities.size();
    int sum = 0;
    int cnt = 1;
    for (int  i = 0; i < l; i++){
        if(communities[i] + sum <= mid){
            sum += communities[i];
        }else{
            sum = communities[i];
            cnt++;
        }
    }
    return cnt <= num;
}

// 二分查找：
// Time: O(logN)
// Space: O(1)
int CommunityVegetableDelivery(int num, vector<int> communities)
{
    int l = communities.size();
    int maxVal = 0;
    int sumVal = 0;
    for (int i = 0; i < l; i++)
    {
        maxVal = max(maxVal, communities[i]);
        sumVal += communities[i];
    }
    int left = maxVal;
    int right = sumVal;
    while (left <= right)
    {
        int mid = left + ((right - left) >> 1);
        if (HelperCommunityVegetableDelivery(mid, num, communities))
        {
            right = mid - 1;
        }
        else
        {   
            left = mid + 1;
        }
    }
    return left;
}