package tree.avltree;

/**
 * 平衡树测试
 */
public class AvlTreeTest {
    private static final int[] arr = {3,2,1,4,5,6,7,16,15,14,13,12,11,10,8,9};

   public static void main(String[] args) {
       AvlTree<Integer> tree = new AvlTree<Integer>();
       System.out.printf("以此添加:");
       for(int i : arr) {
           System.out.printf("%d ", i);
           tree.insert(i);
       }

       System.out.println();
       System.out.println("前序遍历");
       tree.preOrder();
       System.out.println("中序遍历");
       tree.inOrder();
       System.out.println("后序遍历");
       tree.postOrder();

       System.out.printf("== 高度: %d\n", tree.height());
       System.out.printf("== 最小值: %d\n", tree.minimum());
       System.out.printf("== 最大值: %d\n", tree.maximum());
       System.out.printf("== 树的详细信息: \n");
       tree.print();

       int i = 8;
       System.out.println("待删除结点值为: " + i);
       tree.remove(i);
       System.out.printf("== 高度: %d\n", tree.height());
       System.out.printf("== 最小值: %d\n", tree.minimum());
       System.out.printf("== 最大值: %d\n", tree.maximum());
       System.out.printf("== 树的详细信息: \n");
       tree.print();

       tree.destory();
   } 
}