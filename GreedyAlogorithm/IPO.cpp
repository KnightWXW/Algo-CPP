#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

//      LeetCode 502，IPO问题

//      链接：https://leetcode-cn.com/problems/ipo

//      假设 力扣（LeetCode）即将开始 IPO 。
//      为了以更高的价格将股票卖给风险投资公司，力扣希望在 IPO 之前开展一些项目以增加其资本。
//      由于资源有限，它只能在 IPO 之前完成最多 k 个不同的项目（串行做项目）。
//      帮助力扣设计完成最多 k 个不同项目后得到最大总资本的方式。
//      给你 n 个项目。对于每个项目 i ，
//      它都有一个纯利润 profits[i] ，
//      和启动该项目需要的最小资本 capital[i] 。
//      最初，你的资本为 w 。当你完成一个项目时，你将获得纯利润，
//      且利润将被添加到你的总资本中。
//      总而言之，从给定项目中选择 最多 k 个不同项目的列表，
//      以最大化最终资本，并输出最终可获得的最多资本。

//      示例：
//      输入：k = 2, w = 0, profits = [1,2,3], capital = [0,1,1]
//      输出：4
//      解释：
//          由于你的初始资本为 0，你仅可以从 0 号项目开始。
//          在完成后，你将获得 1 的利润，你的总资本将变为 1。
//          此时你可以选择开始 1 号或 2 号项目。
//          由于你最多可以选择两个项目，所以你需要完成 2 号项目以获得最大的资本。
//          因此，输出最后最大化的资本，为 0 + 1 + 3 = 4。

int generateRandomNum(int low, int high);
vector<int> generateRandomVec(int low, int high, int len);
void printVecElement(vector<int> vec);

int ipo(int k, int w, vector<int> &profits, vector<int> &capital);

int main()
{
    int n = generateRandomNum(1, 10);
    vector<int> profits = generateRandomVec(1, 20, n);
    vector<int> capital = generateRandomVec(1, 10, n);
    int k = generateRandomNum(1, n);
    int w = generateRandomNum(0, 10);
    printf("profits 数组 元素为: ");
    printVecElement(profits);
    printf("capital 数组 元素为: ");
    printVecElement(capital);
    int ans = ipo(k, w, profits, capital);
    printf("初始资本为 %d 的 %d 个项目, 最终可获得的最多资本为 %d。\n", w, k, ans);
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

// Project 结构体：
struct Project
{
    int profit;
    int capital;

    Project(int profit, int capital)
    {
        this->profit = profit;
        this->capital = capital;
    }
};

struct cmp1
{
    bool operator()(const Project *p1, const Project *p2)
    {
        return p1->profit < p2->profit;
    }
};

struct cmp2
{
    bool operator()(const Project *p1, const Project *p2)
    {
        return p1->capital > p2->capital;
    }
};

// 贪心：
// 两个堆：花费的小根堆 和 收益的大根堆：
//        随时更新 w:

// Time: O(NlogN)
// Space: O(N)
int ipo(int k, int w, vector<int> &profits, vector<int> &capital)
{
    priority_queue<Project *, vector<Project *>, cmp1> pqMaxProfit;
    priority_queue<Project *, vector<Project *>, cmp2> pqMinCapital;

    for (int i = 0; i < profits.size(); i++)
    {
        Project *project = new Project(profits[i], capital[i]);
        pqMinCapital.push(project);
    }

    int ans = w;
    for (int i = 0; i < k; i++)
    {
        while (!pqMinCapital.empty() && pqMinCapital.top()->capital <= ans)
        {
            pqMaxProfit.push(pqMinCapital.top());
            pqMinCapital.pop();
        }

        if (pqMaxProfit.empty())
        {
            return ans;
        }
        ans += pqMaxProfit.top()->profit;
        pqMaxProfit.pop();
    }
    return ans;
}