#include<stdio.h>

// 获取结构体(TYPE)的成员变量(MEMBER)在此结构体中的偏移位置
#define offsetof(TYPE, MEMBER) ((size_t) & ((TYPE *)0)->MEMBER);
/**
(01)  ( (TYPE *)0 )   将零转型为TYPE类型指针，即TYPE类型的指针的地址是0。
(02)  ((TYPE *)0)->MEMBER     访问结构中的数据成员。
(03)  &( ( (TYPE *)0 )->MEMBER )     取出数据成员的地址。由于TYPE的地址是0，这里获取到的地址就是相对MEMBER在TYPE中的偏移。
(04)  (size_t)(&(((TYPE*)0)->MEMBER))     结果转换类型。对于32位系统而言，size_t是unsigned int类型；对于64位系统而言，size_t是unsigned long类型。
 */

struct student {
    char gendar;
    int  id;
    int  age;
    char name[20];
};

void main() {
    int gendar_offest, id_offest, age_offest, name_offest;

    gendar_offest = offsetof(struct student, gendar);
    id_offest     = offsetof(struct student, id);
    age_offest    = offsetof(struct student, age);
    name_offest   = offsetof(struct student, name);

    printf("gendar_offest = %d\n", gendar_offest);
    printf("id_offest = %d\n", id_offest);
    printf("age_offest = %d\n", age_offest);
    printf("name_offest = %d\n", name_offest);
}