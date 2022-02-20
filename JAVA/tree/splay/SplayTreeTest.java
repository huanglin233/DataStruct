package tree.splay;

/* * 
 * 伸展树测试
 * @Author: huanglin 
 * @Date: 2022-02-20 16:01:17 
 */ 
public class SplayTreeTest {
    
    private static final int ARR[] = {10, 50, 40, 30, 20, 60};

    public static void main(String[] args) {
        int i, len;
        SplayTree<Integer> tree = new SplayTree<Integer>();

        System.out.print("一次添加: ");
        len = ARR.length;
        for(i = 0; i < len; i++) {
            System.out.print(ARR[i] + " ");
            tree.insert(ARR[i]);
        }

        System.out.print("\n前序遍历： ");
        tree.preOrder();
        System.out.print("\n中序遍历： ");
        tree.inOrder();
        System.out.print("\n后序遍历： ");
        tree.postOrder();
        System.out.println();

        System.out.println("最大值: " + tree.maximum());
        System.out.println("最小值: " + tree.minimum());
        System.out.println("打印伸展树结构");
        tree.print();

        i = 30;
        System.out.printf("旋转转结点(%d)为根结点\n", i);
        tree.splay(i);
        System.out.println("打印伸展树结构");
        tree.print();

        // 摧毁二叉树
        tree.clear();
    }
}
