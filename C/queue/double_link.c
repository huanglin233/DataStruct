#include<stdio.h>
#include<malloc.h>

/**
 * 双向链表头实现
 */

// 双向链表结点
typedef struct tag_node
{
    struct tag_node *prev;
    struct tag_node *next;
    void *p;
}node;

// 表头.注意,表头不存放元素值
static node *phead=NULL;
// 结点个数
static int  count=0;

// 新键结点.成功返回结点指针,否则返回NULL
static node* create_node(void *pval) {
    node *pnode = NULL;
    pnode = (node *)malloc(sizeof(node));
    if(!pnode) {
        printf("create node error!\n");
        return NULL;
    }
    // 默认的,pnode的前一个结点和后一个结点都指向它自身
    pnode->prev = pnode->next= pnode;
    // 结点的值为pval
    pnode->p = pval;

    return pnode;
};

// 新建 双向链表,成功返回0;否则返回-1
int create_dlink() {
    //创建表头
    phead = create_node(NULL);
    if(!phead) {
        return -1;
    }
    // 设置结点个数为0
    count = 0;

    return 0;
};

// 双向链表是否为空
int dlink_is_empty() {
    return count == 0;
};

//获取双向链表为大小
int dlink_size() {
    return count;
};

//获取双向链表中第index位置的结点
static node* get_node(int index){
    if(index < 0 || index >= count) {
        printf("%s failed! index out of bound", __func__);
        return NULL;
    };

    // 正向查找
    if(index <= (count / 2)) {
        int i = 0;
        node *pnode = phead->next;
        while((i++) < index) {
            pnode = pnode->next;
        }

        return pnode;
    };

    // 反向查找
    int j = 0;
    int rindex = count - index -1;
    node *rnode = phead -> prev;
    while((j++) < rindex) {
        rnode = rnode->prev;
    };

    return rnode;
};

// 获取第一个结点
static node* get_first_node() {
    return get_node(0);
};
// 获取最后一个结点
static node* get_last_node() {
    return get_node(count - 1);
};

// 获取双向链表中第index位置的元素,成功返回结点值,否则返回-1
void* dlink_get(int index) {
    node *pindex = get_node(index);
    if(!pindex) {
        printf("%s failed!\n", __func__);
        return NULL;
    };

    return pindex->p;
};

// 获取双向链表中第1个元素的值
void* dlink_get_first() {
    return dlink_get(0);
};

//获取双向链表中最后一个元素的值
void* dlink_get_last() {
    return dlink_get(count -1);
};

// 将pval插入到index位置,成功,返回0,否则返回-1
int dlink_insert(int index, void* pval) {
    //插入表头
    if(index == 0) {
        return dlink_insert_first(pval);
    };

    // 获取插入的位置对的结点
    node *pindex = get_node(index);
    if(!pindex) {
        return -1;
    };

    // 创建结点
    node *pnode = create_node(pval);
    if(!pnode) {
        return -1;
    };

    pnode->prev        = pindex->prev;
    pnode->next        = pindex;
    pindex->prev->next = pnode;
    pindex->prev       = pnode;
    // 结点个数+1
    count++;

    return 0;
};

// 将pval插入到表头位置
int dlink_insert_first(void *pval) {
    node *pnode = create_node(pval);
    if(!pnode) {
        return -1;
    };

    pnode->prev       = phead;
    pnode->next       = phead->next;
    phead->next->prev = pnode;
    phead->next       = pnode;
    // 结点个数+1
    count++;

    return 0;
};

// 将pval插入到末尾位置
int dlink_append_last(void *pval) {
    node *pnode = create_node(pval);
    if(!pnode) {
        return -1;
    };

    pnode->next       = phead;
    pnode->prev       = phead->prev;
    phead->prev->next = pnode;
    phead->prev       = pnode;
    // 结点个数+1
    count++;

    return 0;
};

// 删除双向链表中index位置的结点,成功返回0,否则返回-1;
int dlink_delete(int index) {
    node *pindex = get_node(index);
    if(!pindex) {
        printf("%s failed! the index in out of bound!\n", __func__);
        return -1;
    };

    pindex->prev->next = pindex->next;
    pindex->next->prev = pindex->prev;
    free(pindex);
    // 结点数减1
    count--;

    return 0;
};

// 删除第一个结点
int dlink_delete_first() {
    return dlink_delete(0);
};

// 删除最后一个结点
int dlink_delete_last() {
    return dlink_delete(count - 1);
};

// 撤销 双向链表,成功返回0;否则返回-1
int destroy_dlink() {
    if(!phead) {
        printf("%s failed! dlink is null!\n", __func__);
        return -1;
    }

    node *pnode = phead->next;
    node *ptmp  = NULL;

    while(pnode != phead) {
        ptmp = pnode;
        pnode = pnode->next;
        free(ptmp);
    };

    free(phead);
    phead = NULL;
    count = 0;

    return 0;
}

