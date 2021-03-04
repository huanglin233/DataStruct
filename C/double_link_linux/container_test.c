#include<stdio.h>
#include<string.h>

// 获取结构体(TYPE)的成员变量(MEMBER)在此结构体中的偏移位置
#define offsetof(TYPE, MEMBER) ((size_t) & ((TYPE *)0)->MEMBER)

// 根据结构体(type)变量中的域成员变量(member)的指针(ptr)来获取指向整个结构体变量的指针
#define container_of(ptr, type, member) ({            \
    const typeof( ((type *)0)->member) *_mptr = (ptr); \
    (type *)( (char *) _mptr - offsetof(type, member) );  \
})
/**
(01) typeof( ( (type *)0)->member )     取出member成员的变量类型。
(02) const typeof( ((type *)0)->member ) *__mptr = (ptr)    定义变量__mptr指针，并将ptr赋值给__mptr。经过这一步，__mptr为member数据类型的常量指针，其指向ptr所指向的地址。
(04) (char *)__mptr    将__mptr转换为字节型指针。
(05) offsetof(type,member))    就是获取"member成员"在"结构体type"中的位置偏移。
(06) (char *)__mptr - offsetof(type,member))    就是用来获取"结构体type"的指针的起始地址（为char *型指针）。
(07) (type *)( (char *)__mptr - offsetof(type,member) )    就是将"char *类型的结构体type的指针"转换为"type *类型的结构体type的指针"。
 */

struct student {
    char gendar;
    int  id;
    int  age;
    char name[20];
};

void main () {
    struct student stu;
    struct student *pstu;
    stu.gendar = '99';
    stu.id     = 1;
    stu.age    = 18;
    strcpy(stu.name, "Tom");

    // 根据id地址, 获取结构体地址
    pstu = container_of(&stu.id, struct student, id);

    // 根据获取到的结构体student的地址,访问其他成员
    printf("gender = %c\n", pstu->gendar);
    printf("age = %d\n", pstu->age);
    printf("name = %s\n", pstu->name);

    return 0;
};