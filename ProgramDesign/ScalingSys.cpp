#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

//      Huawei: 弹性伸缩

//      某业务系统为 “生产者-先进先出队列-消费者” 模型，
//      由一台或多台机器组成消费者集群，示意如下：
//          生产者                            消费者
//          生产者  -----  先进先出队列  ----- 消费者
//          生产者                            消费者
//      单条消息处理的时长 T = 等待时长t1 + 消费时长t2,
//      被消费前在队列中等待，被消费时所需消费时长固定为 1 秒；要求 T <= 5
//      假设消费者集群初始机器数为 1 台，集群扩容，缩容需满足如下要求：
//          扩容是增加机器，没有数量限制；扩容后实施会立刻生效，即扩容即刻可以处理消息
//          缩容是减少机器，缩容后集群机器不少于1，缩容实施后会立刻生效，
//          缩容机器即刻不能再处理消息。
//      请实现以下功能：
//          ScalingSys(int capability):
//              初始化系统，集群内每台机器每秒并行消费的消息量为 capablity;
//          int JudgeWithMsgs(int time, int msgNum):
//              系统当且仅当在时刻time进行扩缩容决策，
//              此时新生产的消息数量为msgNum(可能为 0);
//              请按照如下机制决策此刻集群扩缩容的机器数量，并返回。
//              决策机制平衡成本和平滑性，即扩缩容后，在满足以下条件下使用最少的机器；
//              假设未来不再扩缩容(即集群机器的数量保持不变)的情况下，
//              截止已收到消息都能在其生产后的 5 秒内处理完
//              注：返回时，正数为扩容，负数为缩容，值表示数量(0为既不扩也不缩)

class ScalingSys
{
public:
    int capacity;
    int time;
    ScalingSys(int capability)
    {
        this->capacity = capability;
        this->time = 0;
    }
    int JudgeWithMsgs(int time, int msgNum)
    {
        
    }
};

int main()
{
    ScalingSys *scalingSys1 = new ScalingSys(10);
    int a1 = scalingSys1->JudgeWithMsgs(0, 8); // 0
    printf("扩缩容后，在满足以下条件下使用最少的机器为: %d\n", a1);
    int a2 = scalingSys1->JudgeWithMsgs(1, 140); // 2
    printf("扩缩容后，在满足以下条件下使用最少的机器为: %d\n", a2);
    int a3 = scalingSys1->JudgeWithMsgs(2, 41); // 1
    printf("扩缩容后，在满足以下条件下使用最少的机器为: %d\n", a3);
    int a4 = scalingSys1->JudgeWithMsgs(4, 0); // -1
    printf("扩缩容后，在满足以下条件下使用最少的机器为: %d\n", a4);

    ScalingSys *scalingSys2 = new ScalingSys(2);
    int b1 = scalingSys2->JudgeWithMsgs(0, 58); // 5
    printf("扩缩容后，在满足以下条件下使用最少的机器为: %d\n", b1);
    int b2 = scalingSys2->JudgeWithMsgs(2, 6); // 0
    printf("扩缩容后，在满足以下条件下使用最少的机器为: %d\n", b2);
    int b3 = scalingSys2->JudgeWithMsgs(5, 0); // -5
    printf("扩缩容后，在满足以下条件下使用最少的机器为: %d\n", b3);
    int b4 = scalingSys2->JudgeWithMsgs(6, 0); // 0
    printf("扩缩容后，在满足以下条件下使用最少的机器为: %d\n", b4);
}