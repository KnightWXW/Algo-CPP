#include <stdio.h>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <stack>

using namespace std;

//      Huawei: 货物抓取

//      码头抓取货物，优先抓取编号连续数目最多的货物，
//      如果多个货物数目相同，优先抓取最左侧的货物。
//      如果货物被抓取后，右侧货物自动向左侧补齐。
//      输出抓取完货物的次数。
//      示例1：
//          输入：{8,8,8,5,5,5,8,1,1,2,3}
//          输出：6

int generateRandomNum(int low, int high);
void printVecElement(vector<int> vec);
vector<int> generateRandomVec(int low, int high, int len);

int GrabGoods(vector<int> goods);

int main()
{
    int n = generateRandomNum(0, 50);
    vector<int> vec = generateRandomVec(1, 3, n);
    printVecElement(vec);
    int ans_A = GrabGoods(vec);
    printf("抓取完货物的次数为 %d\n", ans_A);
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

// 贪心：
// Time: O(N)
// Space: O(N)
int GrabGoods(vector<int> goods)
{
    vector<int> arr;
    vector<int> *cur = &goods;
    vector<int> *next = &arr;
    vector<int> *tem;
    int ans = 0;

    while (cur->size() != 0)
    {
        int preEle = (*cur)[0];
        int cnt = 1;
        int maxCnt = 1;
        int index = 0;
        for (int i = 1; i < cur->size(); i++)
        {
            if ((*cur)[i] == preEle)
            {
                cnt++;
                continue;
            }
            else
            {
                if (cnt > maxCnt)
                {
                    index = i - cnt;
                    maxCnt = cnt;
                }
                preEle = (*cur)[i];
                cnt = 1;
            }
        }
        ans++;
        next->resize(0);
        for (int i = 0; i < index; i++)
        {
            next->push_back((*cur)[i]);
        }
        for (int i = index + maxCnt; i < cur->size(); i++)
        {
            next->push_back((*cur)[i]);
        }
        tem = cur;
        cur = next;
        next = tem;
    }
    return ans;
}