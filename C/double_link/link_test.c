#include<stdio.h>
#include "double_link.h"

/**
 * 双向链表测试
 */

// 双向链表操作int类型数据
void int_test() {
    int iarr[4] = {10, 20, 30, 40};

    printf("\n---%s---\n", __func__);
    create_dlink(); //创建双向链表

    dlink_insert(0, &iarr[0]);    // 0索引位置插入数据
    dlink_insert_first(&iarr[1]); // 头部插入数据
    dlink_append_last(&iarr[2]);  // 表尾最加数据

    printf("dlink_is_empty() = %d \n", dlink_is_empty()); // 判断链表是否为空
    printf("dlink_size() = %d \n", dlink_size()); // 判断链表的大小

    //打印双向链表中的数据
    int i;
    int *p;
    int sz = dlink_size();
    for(i = 0; i < sz; i++) {
        p = (int *)dlink_get(i);
        printf("dlink_get(%d) = %d\n", i, *p);
    }

    destroy_dlink();
};

// 双向链表操作char类型数据
void string_test() {
    char* sarr[4] = {"one", "two", "three", "four"};

    printf("\n---%s---\n", __func__);
    create_dlink(); //创建双向链表

    dlink_insert(0, &sarr[0]);    // 0索引位置插入数据
    dlink_insert_first(&sarr[1]); // 头部插入数据
    dlink_append_last(&sarr[2]);  // 表尾最加数据

    printf("dlink_is_empty() = %d", dlink_is_empty()); // 判断链表是否为空
    printf("dlink_size() = %d", dlink_size()); // 判断链表的大小

    //打印双向链表中的数据
    int i;
    char *p;
    int sz = dlink_size();
    for(i = 0; i < sz; i++) {
        p = (char *)dlink_get(i);
        printf("dlink_get(%d) = %s\n", i, p);
    };

    destroy_dlink();
};

// 双向链表操作结构体数据
typedef struct tag_stu {
    int  id;
    char name[20];
}stu;

static stu arr_stu[] = {
    {10, "tom"},
    {11, "jack"},
    {12, "jreey"},
    {13, "him"}
};

#define ARR_STU_SIZE ((sizeof(arr_stu)) / (sizeof(arr_stu[0])));

void struct_test() {
    printf("\n---%s---\n", __func__);
    create_dlink(); // 创建双向链表

    dlink_insert(0, &arr_stu[0]);    // 在指定的索引处插入数据
    dlink_insert_first(&arr_stu[1]); // 在头部添加数据
    dlink_append_last(&arr_stu[2]);  // 在双向链表尾部添加数据

    printf("dlink_is_empty() = %d", dlink_is_empty()); // 判断链表是否为空
    printf("dlink_size() = %d", dlink_size()); // 判断链表的大

    // 打印双向链表中的全部数据
    int i;
    int sz = dlink_size();
    stu *p;
    for(i = 0; i < sz; i++) {
        p = (stu *)dlink_get(i);
        printf("dlink_get(%d)=(%d, %s)", i, p->id, p->name);
    }

    destroy_dlink();
};

int main() {
    int_test();
    string_test();
    string_test();

    return 0;
}
