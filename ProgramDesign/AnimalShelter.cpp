#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

//      面试题 03.06. 动物收容所

//      链接：https://leetcode.cn/problems/animal-shelter-lcci/

//      动物收容所。有家动物收容所只收容狗与猫，且严格遵守“先进先出”的原则。
//      在收养该收容所的动物时，收养人只能收养所有动物中“最老”
//      （由其进入收容所的时间长短而定）的动物，
//      或者可以挑选猫或狗（同时必须收养此类动物中“最老”的）。
//      换言之，收养人不能自由挑选想收养的对象。
//      请创建适用于这个系统的数据结构，实现各种操作方法，
//      比如enqueue、dequeueAny、dequeueDog和dequeueCat。
//      允许使用Java内置的LinkedList数据结构。
//      enqueue方法有一个animal参数，
//      animal[0]代表动物编号，animal[1]代表动物种类，其中 0 代表猫，1 代表狗。
//      dequeue*方法返回一个列表[动物编号, 动物种类]，
//      若没有可以收养的动物,则返回[-1,-1]。
//      示例1:
//          输入：
//              ["AnimalShelf", "enqueue", "enqueue", "dequeueCat", "dequeueDog", "dequeueAny"]
//              [[], [[0, 0]], [[1, 0]], [], [], []]
//          输出：
//              [null,null,null,[0,0],[-1,-1],[1,0]]
//      示例2:
//          输入：
//              ["AnimalShelf", "enqueue", "enqueue", "enqueue", "dequeueDog", "dequeueCat", "dequeueAny"]
//              [[], [[0, 0]], [[1, 0]], [[2, 1]], [], [], []]
//          输出：
//              [null,null,null,null,[2,1],[0,0],[1,0]]
//      说明:
//          收纳所的最大容量为20000

void printVecElement(vector<int> &vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        printf("%d ", vec[i]);
    }
    printf("\n");
}

class AnimalShelf
{
public:
    deque<vector<int>> catDeque;
    deque<vector<int>> dogDeque;

    AnimalShelf()
    {
    }

    void enqueue(vector<int> animal)
    {
        int type = animal[1];
        if (type == 0)
        {
            catDeque.push_back(animal);
        }
        else
        {
            dogDeque.push_back(animal);
        }
    }

    vector<int> dequeueAny()
    {
        vector<int> ans = {-1, -1};
        if (dogDeque.empty() && catDeque.empty())
        {
            return ans;
        }
        else if (!dogDeque.empty() && catDeque.empty())
        {
            return dequeueDog();
        }
        else if (dogDeque.empty() && !catDeque.empty())
        {
            return dequeueCat();
        }
        else
        {
            if (dogDeque.front()[0] < catDeque.front()[0])
            {
                return dequeueDog();
            }
            else
            {
                return dequeueCat();
            }
        }
    }

    vector<int> dequeueDog()
    {
        if (!dogDeque.empty())
        {
            vector<int> ans = dogDeque.front();
            dogDeque.pop_front();
            return ans;
        }
        else
        {
            return {-1, -1};
        }
    }

    vector<int> dequeueCat()
    {
        if (!catDeque.empty())
        {
            vector<int> ans = catDeque.front();
            catDeque.pop_front();
            return ans;
        }
        else
        {
            return {-1, -1};
        }
    }
};

int main()
{
    AnimalShelf* animalShelf = new AnimalShelf();
    animalShelf->enqueue({0, 0});
    animalShelf->enqueue({1, 0});
    animalShelf->enqueue({2, 1});
    vector<int> d1 = animalShelf->dequeueDog();
    printVecElement(d1);
    vector<int> d2 = animalShelf->dequeueCat();
    printVecElement(d2);
    vector<int> d3 = animalShelf->dequeueAny();
    printVecElement(d3);
}