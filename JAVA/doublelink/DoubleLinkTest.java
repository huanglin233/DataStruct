package doublelink;

/**
 * 双向链表结构测试
 */
public class DoubleLinkTest {

    // 操作双向链表的int数据
    private static void intTest() {
        int iarr[] = {10, 20, 30, 40};

        System.out.println("\n-----int_test-----\n");

        //创建双向链表
        DoubleLink<Integer> doubleLink = new DoubleLink<Integer>();
        doubleLink.insert(0, iarr[0]);   // 在0索引位置插入一个值
        doubleLink.insertFirst(iarr[1]); // 在表头插入一个值
        doubleLink.appendLast(iarr[2]);  // 在表尾插入一个值

        // 判断链表是否为空
        System.out.println("\n doubleLink is null = " + doubleLink.isEmpty() + "\n");
        // 输出链表的大小
        System.out.println("\n doubleLink is size = " + doubleLink.size() + "\n");

        // 打印链表全部数据
        for(int i = 0; i < doubleLink.size(); i++) {
            System.out.println("\n doubleLink(" + i + ") = " + doubleLink.get(i) + "\n");
        }
    }

    // 操作双向俩表的string数据
    private static void stringTest() {
        String sarr[] = {"10", "20", "30", "40"};

        System.out.println("\n-----string_test-----\n");

        //创建双向链表
        DoubleLink<String> doubleLink = new DoubleLink<String>();
        doubleLink.insert(0, sarr[0]);   // 在0索引位置插入一个值
        doubleLink.insertFirst(sarr[1]); // 在表头插入一个值
        doubleLink.appendLast(sarr[2]);  // 在表尾插入一个值

        // 判断链表是否为空
        System.out.println("\n doubleLink is null = " + doubleLink.isEmpty() + "\n");
        // 输出链表的大小
        System.out.println("\n doubleLink is size = " + doubleLink.size() + "\n");

        // 打印链表全部数据
        for(int i = 0; i < doubleLink.size(); i++) {
            System.out.println("\n doubleLink(" + i + ") = " + doubleLink.get(i) + "\n");
        }
    }

    // 内部类
    private static class Student {
        private int    age;
        private String name;
        
        public Student(int age, String name) {
            this.age  = age;
            this.name = name;
        }
        
        @Override
        public String toString() {
            return "[" + this.age + "," + this.name + "]";
        }
    }
    // 操作类双向链表的数据
    private static void objTest() {
        Student[] students = new Student[]{
            new Student(18, "Tom"),
            new Student(19, "Jack"),
            new Student(20, "Marry")
        };

        System.out.println("\n-----object_test-----\n");

        //创建双向链表
        DoubleLink<Student> doubleLink = new DoubleLink<Student>();
        doubleLink.insert(0, students[0]);   // 在0索引位置插入一个值
        doubleLink.insertFirst(students[1]); // 在表头插入一个值
        doubleLink.appendLast(students[2]);  // 在表尾插入一个值

        // 判断链表是否为空
        System.out.println("\n doubleLink is null = " + doubleLink.isEmpty() + "\n");
        // 输出链表的大小
        System.out.println("\n doubleLink is size = " + doubleLink.size() + "\n");

        // 打印链表全部数据
        for(int i = 0; i < doubleLink.size(); i++) {
            System.out.println("\n doubleLink(" + i + ") = " + doubleLink.get(i).toString() + "\n");
        }
    }

    public static void main(String[] args) {
        intTest();
        stringTest();
        objTest();
    }
}