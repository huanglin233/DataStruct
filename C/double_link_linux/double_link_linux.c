#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "double_link_linux.h"

struct person {
    int age;
    char name[20];
    struct list_head list;
};

void main(int argc, char *argv[]) {
    struct person *pperson;
    struct person person_head;
    struct list_head *pos, *next;
    int i;

    // 初始化双向链表的头部
    INIT_LIST_HEAD(&person_head.list);

    // 添加结点
    for (i = 0; i < 5; i++) {
        pperson = (struct person*) malloc(sizeof(struct person));
        pperson->age = 10 + i;
        sprintf(pperson->name, "%d", 10 + i);
        // 把结点添加到链表的尾部
        list_add_tail(&(pperson->list), &(person_head.list));
    };

    // 遍历链表
    printf("-----list_for_each------\n");
    list_for_each(pos, &person_head.list) {
        pperson = list_value(pos, struct person, list);
        printf("name%-2s, age:%d\n", pperson->name, pperson->age);
    };

    // 删除age为11的结点
    list_for_each_safe(pos, next, &person_head.list) {
        pperson = list_value(pos, struct person, list);
        if(pperson->age == 11) {
            list_del_init(pos);
            free(pperson);
        };
    };

    // 再次循环链表
    printf("-----list_for_each(age is 11 not exist)------\n");
    list_for_each(pos, &person_head.list) {
        pperson = list_value(pos, struct person, list);
        printf("name:%s, age:%d\n", pperson->name, pperson->age);
    };

    // 释放资源
    list_for_each_safe(pos, next, &person_head.list) {
        pperson = list_value(pos, struct person, list);
        list_del_init(pos);
        free(pperson);
    };
};