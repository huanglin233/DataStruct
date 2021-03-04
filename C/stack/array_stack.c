#include<stdio.h>
#include<stdlib.h>

/**
 * 用数组实现栈
 */

// 保存数据的数组
static int *arr = NULL;
// 栈的实际大小
static int count;

// 创建栈,默认栈的大小为12
int create_array_stack(int size) {
    arr = (int *)malloc(size * sizeof(int));

    if(!arr) {
        printf("arr malloc error");

        return -1;
    }

    return 0;
}

// 摧毁栈
int destory_array_stack() {
    if(arr) {
        free(arr);
        arr = NULL;
    }

    return 0;
}

// 将数据value添加到栈中
void push(int value) {
    arr[count++] = value;
}

// 返回栈顶元素
int peek() {
    return arr[count - 1];
}

// 返回栈顶元素,并删除栈顶的元素
int pop() {
    int ret = arr[count - 1];
    count--;

    return ret;
}

// 返回栈的大小
int size() {
    return count;
}

// 判断栈是否为空
int is_empty() {
    return size() == 0;
}

// 打印栈数据
void print_array_stack() {
    if(is_empty()) {
        printf("stack is empty");

        return;
    }

    printf("stack size=%d\n", size());

    int i = size() - 1;
    while(i >= 0) {
        printf("%d\n", arr[i]);
        i--;
    }
}

void main() {
    int tmp = 0;

    // 创建栈
    create_array_stack(12);
    // 讲数据10,20,30,40依次存入栈中
    push(10);
    push(20);
    push(30);
    push(40);

    print_array_stack();
    // 将栈顶元素赋值给tmp并删除栈顶元素
    tmp = pop();
    printf("tmp = %d\n", tmp);
    print_array_stack();
    // 将栈顶元素赋值给tmp不删除栈顶元素
    tmp = peek();
    printf("tmp = %d\n", tmp);
    print_array_stack();

    //摧毁栈
    destory_array_stack();
}
