#include<stdio.h>
#include<stdlib.h>

/**
 * 用数组实现队列,并且只能存储int数据
 */

// 保存数据的数组
static int *arr = NULL;
// 队列的实际大小
static int count;

// 创建队列
int create_array_queue(int size) {
    arr = (int *)malloc(size*sizeof(int));
    if (!arr) {
        printf("arr malloc error!");

        return -1;
    }
    count = 0;

    return 0;
}

// 销毁“队列”
int destory_array_queue() {
    if(arr) {
        free(arr);
        arr = NULL;
    }

    return 0;
}

//将val数据添加到的末尾
void add(int val) {
    arr[count++] = val;
}

// 返回队列开头数据
int front() {
    return arr[0];
}

// 返回并删除队列开头数据
int pop() {
    int tmp = arr[0];
    count--;
    int i = 0;
    while(i++ < count) {
        arr[i - 1] = arr[i];
    }

    return tmp;
}

// 返回队列的大小
int size() {
    return count;
}

// 返回队列是否为空
int is_empty() {
    return size() == 0;
}

void main() {
    int tmp = 0;
    
    //创建队列
    create_array_queue(12);
    //将数据存入队列中
    add(10);
    add(11);
    add(12);
    add(13);
    
    printf("queue size = %d\n", size());
    // 将队列开头数据赋值给tmp,并删除该元素
    tmp = pop();
    printf("tmp = %d\n", tmp);
    printf("queue size = %d\n", size());
    // 把队列开头的数据赋值给tmp
    tmp = front();
    printf("tmp = %d\n", tmp);
    printf("queue size = %d\n", size());
    // 答应队列
    while(!is_empty()) {
        printf("%d\n", pop());
    }

    // 摧毁队列
    destory_array_queue();
}