package queue;

/**
 * 使用数组实现,队列
 */
public class ArrayQueue {
    private int[] arr;
    private int   count;

    public ArrayQueue(int size) {
        arr   = new int[size];
        count = 0;
    }

    // 将得到的val放到队列的末尾
    public void add(int val) {
        arr[count++] = val;
    }

    // 返回队列的头元素
    public int fornt() {
        return arr[0];
    }

    // 返回队列的栈顶元素,并删除栈顶元素
    public int pop() {
        int tmp = arr[0];
        count --;
        for(int i = 1; i <= count; i++) {
            arr[i -1] = arr[i];
        }

        return tmp;
    }

    // 返回栈的大小
    public int size() {
        return count;
    }

    // 判断栈是否为空
    public boolean isEmpty() {
        return size() == 0;
    }

    public static void main(String[] args) {
        int tmp = 0;
        ArrayQueue arrayQueue = new ArrayQueue(12);
        arrayQueue.add(10);
        arrayQueue.add(11);
        arrayQueue.add(12);
        arrayQueue.add(13);

        //打印队列的大小
        System.out.println("queue is size = " + arrayQueue.size());
        // 将队列头元素赋值给tmp,并删除队列头元素
        tmp = arrayQueue.pop();
        System.out.println("tmp = " + tmp);
        System.out.println("queue is size = " + arrayQueue.size());
        // 将队列头元素赋值给tmp
        tmp = arrayQueue.fornt();
        System.out.println("tmp = " + tmp);
        System.out.println("queue is size = " + arrayQueue.size());
        // 打印队列数据
        while(!arrayQueue.isEmpty()) {
            System.out.println(arrayQueue.pop());
        }
    }
}