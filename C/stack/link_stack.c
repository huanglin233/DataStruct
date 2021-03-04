#include<stdio.h>
#include<stdlib.h>

/**
 * 用单向简单链表实现栈, 只能存储int类型
 */

// 单向链表的"节点"
struct node {
    int val;
    struct node *next;
};

// 单向链表的表头
static struct node *phead = NULL;

// 创建节点
static struct node* create_node(int val) {
    struct node *pnode = NULL;
    pnode = (struct node*)malloc(sizeof(struct node));
    if(!pnode) {
        return NULL;
    }
    pnode->val = val;
    pnode->next = NULL;

    return pnode;
}

// 摧毁单向链表
static int destory_link_stack() {
    struct node *pnode = NULL;

    while(phead != NULL) {
        pnode = phead;
        phead = phead->next;
        free(pnode);
    }

    return 0;
}

// 将val插入到表头
static struct node* push(int val) {
    struct node* pnode = NULL;
    pnode = create_node(val);
    pnode->next = phead;
    phead = pnode;

    return phead;
}

// 删除链表的表头,并返回表头数据
static int pop() {
    if(!phead) {
        printf("remove phead failed! stack is empty");

        return -1;
    }

    int ret;
    struct node *pnode;
    ret = phead->val;
    pnode = phead;
    phead = phead->next;
    free(pnode);

    return ret;
}

// 返回表头数据
static int peek() {
    if(!phead) {
        printf("remove phead failed! stack is empty");

        return -1;
    }

    return phead->val;
}

// 返回链表的个数
static int size() {
    int count = 0;
    struct node *pnode = phead;
    while(pnode != NULL) {
        pnode = pnode->next;
        count++;
    }

    return count;
}

// 判断链表是否为null
static int is_empty() {
    return phead == NULL;
}

// 打印栈数据
static void print_link_stack() {
    if(is_empty()) {
        printf("stack is empty\n");

        return ;
    }

    printf("stack size = %d\n", size());

    struct node *pnode = phead;
    while(pnode != NULL) {
        printf("%d\n", pnode->val);
        pnode = pnode->next;
    }
}

void main() {
    int tmp = 0;

    // 讲数据10,20,30,40依次存入栈中
    push(10);
    push(20);
    push(30);
    push(40);

    print_link_stack();
    // 将栈顶元素赋值给tmp并删除栈顶元素
    tmp = pop();
    printf("tmp = %d\n", tmp);
    print_link_stack();
    // 将栈顶元素赋值给tmp不删除栈顶元素
    tmp = peek();
    printf("tmp = %d\n", tmp);
    print_link_stack();


    destory_link_stack();
}