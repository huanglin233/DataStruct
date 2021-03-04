package tree.bstree;

/**
 * 二叉查找树的测试类
 */
public class BSTreeTest {
    private static final int arr[] = {1, 5, 4, 3, 2, 6};

    public static void main(String[] args) {
        int i,ilen;
        BSTree<Integer> tree = new BSTree<Integer>();

        System.out.println("-----依次添加数据");
        ilen = arr.length;
        for(i = 0; i < ilen; i++) {
            System.out.println(arr[i] + " ");
            tree.insert(arr[i]);
        }

        System.out.println("-----前序遍历");
        tree.preOrder();
        System.out.println("-----中序遍历");
        tree.inOrder();
        System.out.println("-----后序遍历");
        tree.postOrder();

        System.out.println("-----最小值" + tree.minimum());
        System.out.println("-----最大值" + tree.maximum());
        System.out.println("-----树的详细信息");
        tree.print();

        System.out.println("-----删除结点 : " + arr[3]);
        tree.remove(arr[3]);
        System.out.println("-----前序遍历");
        tree.preOrder();
        System.out.println("-----中序遍历");
        tree.inOrder();
        System.out.println("-----后序遍历");
        tree.postOrder();

        System.out.println("-----最小值" + tree.minimum());
        System.out.println("-----最大值" + tree.maximum());
        System.out.println("-----树的详细信息");
        tree.print();

        // 摧毁二叉树
        tree.clear();
    }
}