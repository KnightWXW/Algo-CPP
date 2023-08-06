#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

//      LeetCode 622. 设计循环队列

//      链接：https://leetcode.cn/problems/design-circular-queue/

//      设计你的循环队列实现。
//      循环队列是一种线性数据结构，其操作表现基于 FIFO（先进先出）原则
//      并且队尾被连接在队首之后以形成一个循环。它也被称为“环形缓冲器”。
//      循环队列的一个好处是我们可以利用这个队列之前用过的空间。
//      在一个普通队列里，一旦一个队列满了，我们就不能插入下一个元素，即使在队列前面仍有空间。
//      但是使用循环队列，我们能使用这些空间去存储新的值。
//      你的实现应该支持如下操作：
//          MyCircularQueue(k): 构造器，设置队列长度为 k 。
//          Front: 从队首获取元素。如果队列为空，返回 -1 。
//          Rear: 获取队尾元素。如果队列为空，返回 -1 。
//          enQueue(value): 向循环队列插入一个元素。如果成功插入则返回真。
//          deQueue(): 从循环队列中删除一个元素。如果成功删除则返回真。
//          isEmpty(): 检查循环队列是否为空。
//          isFull(): 检查循环队列是否已满。
//      示例：
//          MyCircularQueue circularQueue = new MyCircularQueue(3); // 设置长度为 3
//          circularQueue.enQueue(1);  // 返回 true
//          circularQueue.enQueue(2);  // 返回 true
//          circularQueue.enQueue(3);  // 返回 true
//          circularQueue.enQueue(4);  // 返回 false，队列已满
//          circularQueue.Rear();  // 返回 3
//          circularQueue.isFull();  // 返回 true
//          circularQueue.deQueue();  // 返回 true
//          circularQueue.enQueue(4);  // 返回 true
//          circularQueue.Rear();  // 返回 4
//      提示：
//          所有的值都在 0 至 1000 的范围内；
//          操作数将在 1 至 1000 的范围内；
//          请不要使用内置的队列库。

void printBool(bool b)
{
    if (b == true)
    {
        printf("True\n");
    }
    else
    {
        printf("False\n");
    }
}

class MyCircularQueue
{
public:
    int front;
    int rear;
    int capacity;
    vector<int> myQueue;
    MyCircularQueue(int k)
    {
        front = 0;
        rear = 0;
        capacity = k + 1;
        myQueue = vector<int>(capacity, 0);
    }

    bool enQueue(int value)
    {
        if (isFull())
        {
            return false;
        }
        myQueue[rear] = value;
        rear = (rear + 1) % capacity;
        return true;
    }

    bool deQueue()
    {
        if (isEmpty())
        {
            return false;
        }
        front = (front + 1) % capacity;
        return true;
    }

    int Front()
    {
        if (isEmpty() == true)
        {
            return -1;
        }
        return myQueue[front];
    }

    int Rear()
    {
        if (isEmpty() == true)
        {
            return -1;
        }
        return myQueue[(rear - 1 + capacity) % capacity];
    }

    bool isEmpty()
    {
        return front == rear;
    }

    bool isFull()
    {
        return (rear + 1) % capacity == front;
    }
};

int main()
{
    MyCircularQueue *circularQueue = new MyCircularQueue(3); // 设置长度为 3
    bool e1 = circularQueue->enQueue(1);                     // 返回 true
    printf("入队操作结果为：\n");
    printBool(e1);
    bool e2 = circularQueue->enQueue(2); // 返回 true
    printf("入队操作结果为：\n");
    printBool(e2);
    bool e3 = circularQueue->enQueue(3); // 返回 true
    printf("入队操作结果为：\n");
    printBool(e3);
    bool e4 = circularQueue->enQueue(4); // 返回 false，队列已满
    printf("入队操作结果为：\n");
    printBool(e4);
    int r1 = circularQueue->Rear(); // 返回 3
    printf("尾节点元素为：\n%d\n", r1);
    bool i1 = circularQueue->isFull(); // 返回 true
    printf("队列是否为空：\n");
    printBool(i1);
    bool d1 = circularQueue->deQueue(); // 返回 true
    printf("入队操作结果为：\n");
    printBool(d1);
    bool e5 = circularQueue->enQueue(4); // 返回 true
    printf("入队操作结果为：\n");
    printBool(e5);
    int r2 = circularQueue->Rear(); // 返回 4
    printf("入队操作结果为：\n%d\n", r2);
}
