#include<stdio.h>
#include "double_link.h"

/**
 * 使用双向链表实现队列
 */

// 创建队列
int create_dlink_queue() {
    return create_dlink();
}

// 销毁队列
int destory_dlink_queue() {
    return destroy_dlink();
}

// 将p添加到队列的末尾中
int add(void *p) {
    return dlink_append_last(p);
}

// 返回队列的头数据
void* front() {
    return dlink_get_first();
}

// 返回队列的头数据并删除
void* pop() {
    void *tmp = dlink_get_first();
    dlink_delete_first();

    return tmp;
}

// 返回队列的大小
int size() {
    return dlink_size();
}

// 判断队列是否为空
int is_empty() {
    return dlink_is_empty();
}

typedef struct tag_stu {
    int id;
    char name[20];
}stu;

static stu stu_arr[] = {
    {10, "tom"},
    {11, "jack"},
    {12, "meery"},
};

#define STU_ARR_SIZE ((sizeof(stu_arr)) / (sizeof(stu_arr[0])))

static void print_stu(stu *p) {
    if(!p) {
        return ;
    }

    printf("id = %d, name = %s\n", p->id, p->name);
};

void main() {
    stu *pval = NULL;

    // 创建队列
    create_dlink_queue();

    //将stu_arr中数据存入队列中
    int i = 0;
    for(i; i < STU_ARR_SIZE; i++) {
        add(&stu_arr[i]);
    }

    printf("queue size = %d\n", size());
    // 将队列的头数据赋值给pval,并删除头数据
    pval = pop();
    printf("pval id = %d, name = %s\n", pval->id, pval->name);
    printf("queue size = %d\n", size());
    // 将队列头数据赋值给pval
    pval = front();
    printf("pval id = %d, name = %s\n", pval->id, pval->name);
    printf("queue size = %d\n", size());
    //打印所有数据
    while(!is_empty()) {
        pval = pop();
        print_stu(pval);
    }
    // 销毁队列
    destory_dlink_queue();
}