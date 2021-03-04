#include<stdio.h>
#include<stdlib.h>

/**
 * 用简单向链表实现队列,只能存储int类型数据
 */

// 单向链表节点
struct node {
    int val;
    struct node *next;
};

// 队列头
static struct node *phead = NULL;

// 创建节点,val为节点值
static struct node* create_node(int val) {
    struct node *pnode = NULL;
    pnode = (struct node*)malloc(sizeof(struct node));
    if(!pnode) {
        printf("create node failed\n");
        return NULL;
    }

    pnode->val  = val;
    pnode->next = NULL;

    return pnode;
}
// 摧毁单向链表
static int destory_array_queue() {
    struct node *pnode = NULL;
    while(phead != NULL) {
        pnode = phead;
        phead = phead->next;
        free(pnode);
    }
    
    return 0;
}

// 将val插入到队列末尾
static void add(int val) {
    if(!phead) {
        phead = create_node(val);
        return ;
    }

    struct node *pnode = create_node(val);
    struct node *pend  = phead;
    while(pend->next) {
        pend = pend->next;
    }

    pend->next = pnode;
}

// 返回队列开头元素数据
static int front() {
    return phead->val;
}

// 返回列表开头并删除该数据
static int pop() {
    int ret = phead->val;
    struct node *pnode = phead;
    phead = phead->next;
    free(pnode);

    return ret;
}

//// 返回队列中大小
static int size() {
    int count = 0;
    struct node *pnode = phead;
    while(pnode) {
        pnode = pnode->next;
        count++;
    }

    return count;
}

// 判断链表是否为空
static int is_empty() {
    return size() == 0;
}

int main() {
    int tmp = 0;

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

    return 0;
}