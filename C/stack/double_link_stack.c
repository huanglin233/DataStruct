#include<stdio.h>
#include "double_link.h"

/**
 * 双向链表实现栈,可以任意类型数据
 */

// 创建栈
int create_double_link_stack() {
    return create_dlink();
}

// 摧毁栈
int destory_double_link_stack() {
    return destroy_dlink();
}

// 将数据插入到中
int push(void *p) {
    return dlink_insert_first(p);
}

// 返回栈顶元素
void* peek() {
    return dlink_get_first();
}

// 返回栈顶元素并删除
void* pop() {
    void *p = peek();
    //删除栈顶元素
    dlink_delete_first();

    return p;
}

// 返回栈的大小
int size() {
    return dlink_size();
}

// 判断栈是否为空
int is_empty() {
    return dlink_is_empty();
}

typedef struct tag_stu {
    int id;
    char name[20];
}stu;

static stu arr_stu[] = {
    {10, "tom"},
    {11, "jack"},
    {12, "merry"}
};

#define ARR_STU_SIZE ((sizeof(arr_stu)) / (sizeof(arr_stu[0])))

static void print_stu(stu *p) {
    if(!p) {
        return;
    }

    printf("id = %d,namn = %s\n", p->id, p->name);
}

void main() {
    stu *pval = NULL;

    // 创建栈
    create_double_link_stack();

    // 将arr_stu中的数据放入栈中
    int arr_stu_size = ARR_STU_SIZE;
    int i = 0;
    for(i = 0; i < arr_stu_size; i++) {
        push(&arr_stu[i]);
    }
    // 输出栈的大小
    printf("stack is size = %d\n", size());
    // 将栈顶元素放在pval中并删除栈顶元素
    pval = pop();
    printf("pval id = %d, name = %s\n", pval->id, pval->name);
    // 将栈顶元素给pval
    pval = peek();
    printf("pval id = %d, name = %s\n", pval->id, pval->name);

    // 打印栈中所有元素
    while(!is_empty()) {
        pval = pop();
        print_stu(pval);
    }

    // 摧毁栈
    destory_double_link_stack();
}