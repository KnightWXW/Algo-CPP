#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <unordered_map>

using namespace std;

//      Huawei: 单词学习系统

//      请你设计一个单词学习系统：
//      WordLearningSystem(int wordNum, int learningCnt):
//          初始化函数，总共 wordNum个单词，按照序号录入，每个单词固定学习 learningCnt 遍
//      vector<int> Learn(int num):
//          选取 num 个单词进行背诵，如果不满足num个，则按照不足数量处理，返回序号数列
//          按照单词还没背诵的次数，从大到小排序，如果没有背诵次数相同的，则按照单词序号从小到大排序
//          单词背诵一次需要次数减一，直到为零
//      void Reset(vector<int> wordList)
//          重置 wordList 数组中的 需要背诵的次数为 learningCnt 次数
//      int Query():
//          查询还需要背诵的单词总量，(背诵次数大于0的个数)

void printVecElement(vector<int> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        printf("%d ", vec[i]);
    }
    printf("\n");
}

class WordLearningSystem
{
    WordLearningSystem(int wordNum, int learningCnt)
    {
    }
    vector<int> Learn(int num)
    {
    }
    void Reset(vector<int> wordList)
    {
    }
    int Query()
    {
    }
};

int Main()
{
    WordLearningSystem *wordLearningSystem = new WordLearningSystem(6, 2);
    int a1 = wordLearningSystem->Query();
    printf("还需要背诵的单词总量 为：%d\n", a1);
    vector<int> a2 = wordLearningSystem->Learn(3);
    printf("序号数列 为：%d\n");
    printVecElement(a2);
    vector<int> a3 = wordLearningSystem->Learn(5);
    printf("序号数列 为：%d\n");
    printVecElement(a3);
    int a4 = wordLearningSystem->Query();
    printf("还需要背诵的单词总量 为：%d\n", a4);
    vector<int> a5 = wordLearningSystem->Learn(6);
    printf("序号数列 为：%d\n");
    printVecElement(a5);
    vector<int> a6 = wordLearningSystem->Learn(2);
    printf("序号数列 为：%d\n");
    printVecElement(a6);
    wordLearningSystem->Reset({0, 2});
    vector<int> a7 = wordLearningSystem->Learn(1);
    printf("序号数列 为：%d\n");
    printVecElement(a7);
    wordLearningSystem->Reset({3});
    int a8 = wordLearningSystem->Query();
    printf("还需要背诵的单词总量 为：%d\n", a8);
}
