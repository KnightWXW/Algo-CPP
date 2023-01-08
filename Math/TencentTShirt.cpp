#include <stdio.h>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

//      鹅厂文化衫问题
//      LeetCode 781. 森林中的兔子

//      链接：https://leetcode.cn/problems/rabbits-in-forest/

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

int TencentTShirt(vector<int> vec);

int main()
{
    int n = generateRandomNum(0, 30);
    vector<int> buttons = generateRandomVec(1, 20, n);
    printVecElement(buttons);
    long ans = SonOfHeavenAbandoned(buttons);
    printf("最多的按按钮次数 %d\n", ans);
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

int TencentTShirt(vector<int> vec){
    
}