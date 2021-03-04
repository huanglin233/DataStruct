package doublelink; 

/**
 * 双向链表 java实现
 * @param <T>
 */
public class DoubleLink<T> {

    // 表头
    private DNode mHead;

    // 节点个数
    private int mCount;

    // 双向链表节点结构
    private class DNode<T> {
        public DNode prev;
        public DNode next;
        public T     value;

        public DNode(DNode prev, DNode next, T value) {
            this.prev  = prev;
            this.next  = next;
            this.value = value;
        }
    }

    // 构造函数,初始化双向链表
    public DoubleLink() {
        // 创建表头,表头默认没有存储数据
        mHead      = new DNode<T>(null, null, null);
        mHead.prev = mHead.next = mHead;
        // 初始化节点个数
        mCount = 0;
    }

    // 返回节点数据
    public int size() {
        return this.mCount;
    }

    // 判断链表是否为空
    public boolean isEmpty() {
        return mCount == 0;
    }

    // 查找第index位置的节点
    private DNode<T> getNode(int index) {
        if(index < 0 || index > mCount) {
            throw new IndexOutOfBoundsException();
        }

        DNode<T> dNode = mHead.next;
        if(index < mCount / 2) {
            // 正向查找
            for(int i = 0; i < index; i++) {
                dNode = dNode.next;
            }
        } else {
            // 反向查找
            dNode = mHead.prev;
            for(int i = 0; i < mCount - index -1 ; i++) {
                dNode = dNode.prev;
            }
        }

        return dNode;
    }

    // 根据index位置获取节点位置的数据
    public T get(int index) {
        return getNode(index).value;
    }

    // 获取链表一个节点
    public T getFirst() {
        return getNode(0).value;
    }

    // 获取链表最后一个节点
    public T getLast() {
        return getNode(mCount -1).value;
    }

    // 将节点插入到index位置
    public void insert(int index, T value) {
        if(index == 0) {
            DNode<T> dNode = new DNode<T>(mHead, mHead.next, value);
            mHead.next.prev = dNode;
            mHead.next = dNode;
            // 节点数加1
            mCount++;

            return ;
        }

        DNode<T> dNode  = getNode(index);
        DNode<T> iDNode = new DNode<T>(dNode.prev, dNode, value);
        dNode.prev.next = iDNode;
        dNode.prev = iDNode;
        // 节点数加1
        mCount++;

        return ;
    }

    // 将值插入到第一个节点位置
    public void insertFirst(T value) {
        insert(0, value);
    }

    // 将值链表插入到链表尾的位置
    public void appendLast(T value) {
        DNode<T> dNode  = new DNode<T>(mHead.prev, mHead, value);
        mHead.prev.next = dNode;
        mHead.prev      = dNode;
        // 节点数加1
        mCount++;
    }

    // 删除index位置的节点
    public void delete(int index) {
        DNode<T> dNode  = getNode(index);
        dNode.prev.next = dNode.next;
        dNode.next.prev = dNode.prev;
        dNode           = null;
        // 节点数减1
        mCount--;
    }

    // 删除第一个节点
    public void deleteFirst() {
        delete(0);
    }

    // 删除最后一个节点
    public void deleteLast() {
        delete(mCount - 1);
    }
}