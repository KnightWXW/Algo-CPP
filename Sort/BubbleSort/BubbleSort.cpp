#include <stdio.h>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

vector<int> generateRandomVec(int low, int high, int len);
void printVecElement(vector<int> vec);
void bubbleSort(vector<int> vec);

int main(){
    vector<int> vec = generateRandomVec(-100, 100, 10);
    printVecElement(vec);
    printf("冒泡排序 后为：");
    printVecElement(vec);
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

void bubbleSort(vector<int> vec)
{
    for(int i = 0; i < vec.size(); i++){
        for (int j = i + 1; j < vec.size(); j++){
            if (vec[j])
            {
                /* code */
            }
            
        }
    }
}