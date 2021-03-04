package stack;

import java.util.Stack;

public class StackTest {

    public static void main(String[] args) {
        int tmp = 0;
        Stack<Integer> istack = new Stack<Integer>();
        istack.push(10);
        istack.push(20);
        istack.push(30);
        istack.push(40);

        // 取出栈顶元素赋值给tmp,并删除栈顶元素
        tmp = istack.pop();
        System.out.println("tmp = " + tmp);
        // 取出栈顶元素赋值给tmp
        tmp = istack.peek();
        System.out.println("tmp = " + tmp);
        // 打印全部数据
        while(!istack.empty()) {
            tmp = istack.pop();
            System.out.println(tmp);
        }
    }
}