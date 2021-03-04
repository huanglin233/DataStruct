package stack;

import java.lang.reflect.Array;

/**
 * 数组实现堆,能存储任意数据
 */
public class ArrayStack<T> {

    private static final int DEFAULT_SIZE = 12;
    private T[] arr;
    private int count;

    public ArrayStack(Class<T> type) {
        this(type, DEFAULT_SIZE);
    }

    public ArrayStack(Class<T> type, int size) {
        // 不能直接使用mArray = new T[DEFAULT_SIZE];
        arr   = (T[]) Array.newInstance(type, size);
        count = 0;
    }

    // 将val添加到栈中
    public void push(T val) {
        arr[count] = val;
        count++;
    }

    // 返回栈顶元素
    public T peek() {
        return arr[count -1];
    }

    // 返回栈顶元素,并删除栈顶元素
    public T pop() {
        T t = arr[count -1];
        count --;

        return t;
    }

    // 返回栈的大小
    public int size() {
        return count;
    }

    // 判断栈是否空
    public boolean isEmpty() {
        return size() == 0;
    }

    // 打印栈数据
    public void printArrayStack() {
        if(isEmpty()) {
            System.out.println("stack is null");

            return ;
        }

        System.out.println("stack size = " + size());

        int i  = size() -1;
        while(i >= 0) {
            System.out.println(arr[i]);
            i--;
        }
    }

    public static void main(String[] args) {
        String tmp;

        ArrayStack<String> sArrayStack = new ArrayStack<String>(String.class);

        // 将10,20,30,40依次存入栈中
        sArrayStack.push("10");
        sArrayStack.push("20");
        sArrayStack.push("30");
        sArrayStack.push("40");

        // 打印栈的数据
        sArrayStack.printArrayStack();
        // 将栈顶元素赋值给tmp,并删除栈顶元素
        tmp = sArrayStack.pop();
        System.out.println("tmp = " + tmp);
        // 将栈顶元素赋值给tmp
        tmp = sArrayStack.peek();
        System.out.println("tmp = " + tmp);
        // 打印栈的数据
        sArrayStack.printArrayStack();
    }
}