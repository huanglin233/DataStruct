package queue;

import java.util.Stack;

/**
 * 用栈来实现队列
 */
public class StackQueue<T> {
    // 向队列添加数据:1.将已有的全部数据都移动到mInz中,2.将新添加的数据添加到mIn.
    private Stack<T> mIn = null;
    // 从队列中获取元素时:1.将已有的全部数据都移动到mOut中,2.并返回删除mOut的栈顶元素
    private Stack<T> mOut = null;
    // 队列数
    int count;

    public StackQueue() {
        mIn   = new Stack<T>();
        mOut  = new Stack<T>();
        count = 0;
    }

    // 向队列添加数据
    private void add(T val) {
        // 将已有的全部数据都移动到mIn中
        while(!mOut.empty()) {
            mIn.push(mOut.pop());
        }
        // 将新添加的数据添加到mIn中
        mIn.push(val);
        count++;
    }

    // 获取队列中的数据
    private T pop() {
        // 将已有的全部数据移动到mOut中
        while(!mIn.empty()) {
            mOut.push(mIn.pop());
        }
        count--;

        return mOut.pop();
    }

    // 获取队列的大小
    private int size() {
        return count;
    }

    // 队列是否为空
    private boolean isEmpty() {
        return count == 0;
    }

    public static void main(String[] args) {
        StackQueue<String> stackQueue = new StackQueue<String>();

        stackQueue.add("10");
        stackQueue.add("11");
        stackQueue.add("12");
        System.out.println("queue size = " + stackQueue.size());
        while(!stackQueue.isEmpty()) {
            System.out.println(stackQueue.pop());
        }
    }
}