#include <stdio.h>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <unordered_map>
#include <algorithm>

using namespace std;

//      Tencent: 鹅厂文化衫问题

//      企鹅厂每年都会发文化衫，文化衫有很多种，
//      厂庆的时候，企鹅们都需要穿文化衫来拍照
//      一次采访中，记者随机遇到的企鹅，
//      企鹅会告诉记者还有多少企鹅跟他穿一种文化衫
//      我们将这些回答放在 answers 数组里，返回鹅厂中企鹅的最少数量。
//	    输入: answers = [1]    输出：2
//	    输入: answers = [1, 1, 2]    输出：5

int generateRandomNum(int low, int high);
void printVecElement(vector<int> vec);
vector<int> generateRandomVec(int low, int high, int len);

int TencentTShirt_A(vector<int> vec);
int TencentTShirt_B(vector<int> vec);

int main()
{
    int n = generateRandomNum(0, 50);
    vector<int> answers = generateRandomVec(1, 5, n);
    printVecElement(answers);
    int ans_A = TencentTShirt_A(answers);
    printf("鹅厂中企鹅的最少数量为 %d\n", ans_A);
    int ans_B = TencentTShirt_B(answers);
    printf("鹅厂中企鹅的最少数量为 %d\n", ans_B);
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

int TencentTShirt_A(vector<int> answers)
{
    int l = answers.size();
    sort(answers.begin(), answers.end());
    int cnt = 1;
    int pre = answers[0];
    int ans = 0;
    for (int i = 1; i < l; i++)
    {
        if (pre == answers[i])
        {
            cnt++;
        }
        else
        {
            ans += ((cnt + pre) / (pre + 1)) * (pre + 1);
            pre = answers[i];
            cnt = 1;
        }
    }
    return ans + ((cnt + pre) / (pre + 1)) * (pre + 1);
}

int TencentTShirt_B(vector<int> answers)
{
    unordered_map<int, int> umap;
    for (auto v : answers)
    {
        umap[v]++;
    }
    int ans = 0;
    for (auto it = umap.begin(); it != umap.end(); it++)
    {
        ans += (it->first + it->second) / (it->first + 1) * (it->first + 1);
        ans += ((it->second - 1) / (it->first + 1) + 1) * (it->first + 1);
    }
    return ans;
}