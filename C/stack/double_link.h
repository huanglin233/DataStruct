#ifndef _DOUBLE_LINKE_H
#define _DOUBLE_LINKE_H

/**
 * 双向链表头文件
 */

// 新建"双向链表",成功返回表头;否则,返回NULL
extern int create_dlink();
// 撤销双向链表是否空,成功返回1,否则,返回-1
extern int destroy_dlink();

// "双向链表是否为空".为空的话返回1;否则返回0.
extern int dlink_is_empty();
// 返回链表的大小
extern int dlink_size();

// 获取 双向链表中第index位置的元素,成功.返回结点指针;否则返回NULL
extern void* dlink_get(int index);
// 获取 双向链表中的第一个元素, 成功返回结点指针,否则,返回NULL
extern void* dlink_get_first();
// 获取 双向链表中的最后一个元素,成功,返回结点指针,否则返回NULl
extern void* dlink_get_last();

// 将value插入到index位置,成功,返回0,否则返回-1;
extern int dlink_insert(int index, void *pval);
// 将value插入到表头位置,成功返回0,否则,返回-1;
extern int dlink_insert_first(void *pval);
// 将value插入到表末尾位置,成功返回0,否则,返回-1;
extern int dlink_append_last(void *pval);

// 删除 双向链表中index位置的结点,成功返回0;否则返回-1
extern int dlink_delete(int index);
// 删除第一个结点,成功,返回0,否则返回-1;
extern int dlink_delete_first();
// 删除最后一个结点,成功,返回0,否则,返回-1
extern int dlink_delete_last();

#endif