#ifndef _LIST_HEAD_H
#define _LIST_HEAD_H

// 双向链表结点
struct list_head {
    struct list_head *next, *prev;
};

// 初始化结点,设置name结点的前继结点和后继结点指向name自己
#define LIST_HEAD_INIT(name) {&(name), &(name)};

// 定义表头结点,新建双向链表表头name,并设置初始化结点,设置name结点的前继结点和后继结点指向name自己
#define LIST_HEAD(name) struct list_head name = LIST_HEAD_INT(name);

// 初始化结点,将list结点的前继结点和后继结点都指向list自己
static inline void INIT_LIST_HEAD(struct list_head *list) {
    list->next = list;
    list->prev = list;
};

// 添加结点,将value插入pre和next之间
static inline void _list_add(struct list_head *value, struct list_head *prev, struct list_head *next) {
    next->prev  = value;
    value->next = next;
    value->prev = prev;
    prev->next  = value;
};

// 添加结点,将value插入到head后面,及head的后继结点
static inline void list_add(struct list_head *value, struct list_head *head) {
    _list_add(value, head, head->next);
};

// 添加结点,将value插入到head之间,及head的前继结点
static inline void list_add_tail(struct list_head *value, struct list_head * head) {
    _list_add(value, head->prev, head);
};

// 从双向链表中删除prev和next之间的结点
static inline void _list_del(struct list_head *prev, struct list_head *next) {
    prev->next = next;
    next->prev = prev;
};

// 从链表中删除value结点
static inline void list_del(struct list_head *value) {
    _list_del(value->prev, value->next);
};

// 从链表中删除value结点,并让value结点的的前继和后继都指向自己
static inline void list_del_init(struct list_head *value) {
    _list_del(value->prev, value->next);
    INIT_LIST_HEAD(value);
};

// 用value结点取代oldvalue结点
static inline void list_replace(struct list_head *value, struct list_head *old_value) {
    value->next           = old_value->next;
    value->prev           = old_value->prev;
    old_value->next->prev = value;
    old_value->prev->next = value;
};

// 判断链表是否空
static inline int list_empty(const struct list_head *head) {
    return head->next == head;
}

// 获取"MEMBER成员"在结构体中的偏移位置
#define offsetof(TYPE, MEMBER) ((size_t) & ((TYPE *)0)->MEMBER)

// 根据结构体(type)变量中的域成员变量(member)的指针(ptr)来获取指向整个结构体变量的指针
#define container_of(ptr, type, member) ({            \
    const typeof(((type *)0)->member) *_mptr = (ptr); \
    (type *)((char *)_mptr - offsetof(type, member));});

// 遍历双向链表
#define list_for_each(pos, head)                             \
    for (pos = (head)->next; pos != (head); pos = pos->next)

#define list_for_each_safe(pos, n, head)                   \
    for (pos = (head)->next, n = pos->next; pos != (head); \
         pos = n, n = pos->next)

#define list_value(ptr, type, name) \
    container_of(ptr, type, name);

#endif