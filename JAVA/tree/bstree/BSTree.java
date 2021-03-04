package tree.bstree;

/**
 * 二叉查找树的实现
 */
public class BSTree<T extends Comparable<T>> {

    private BSTNode<T> root;  // 根结点

    public class BSTNode<T extends Comparable<T>> {
        T          key;    // 结点值
        BSTNode<T> left;   // 左孩子
        BSTNode<T> right;  // 右孩子
        BSTNode<T> parent; // 父结点

        public BSTNode(T key, BSTNode<T> parent, BSTNode<T> left, BSTNode<T> right) {
            this.key    = key;
            this.parent = parent;
            this.left   = left;
            this.right  = right;
        }

        public T getKey() {
            return key;
        }

        public String toString() {
            return "key : " + key;
        }
    }

    public BSTree() {
        root = null;
    }

    /**
     * 前序遍历二叉树
     * @param node 遍历二叉树的根结点
     */
    private void preOrder(BSTNode<T> node) {
        if(node != null) {
            System.out.printf("%2d ", node.key);
            preOrder(node.left);
            preOrder(node.right);
        }
    }

    public void preOrder() {
        preOrder(root);
    }

    /**
     * 中序遍历二叉树
     * @param tree 遍历二叉树的根结点
     */
    private void inOrder(BSTNode<T> node) {
        if(node != null) {
            inOrder(node.left);
            System.out.printf("%2d ", node.key);
            inOrder(node.right);
        }
    }

    public void inOrder() {
        inOrder(root);
    }

    /**
     * 后序遍历 
     * @param tree 遍历二叉树的根结点
     */
    private void postOrder(BSTNode<T> node) {
        if(node != null) {
            postOrder(node.left);
            postOrder(node.right);
            System.out.printf("%2d ", node.key);
        }
    }

    public void postOrder() {
        postOrder(root);
    }

    /**
     * (递归实现) 查找二叉树数中值为key的结点
     * @param  node 查找的二叉树根结点
     * @param  key  查找的key值
     * @return
     */
    private BSTNode<T> search(BSTNode<T> node, T key) {
        if(node == null) {
            return node;
        }

        int cmp = key.compareTo(node.key);
        if(cmp < 0) {
            return search(node.left, key);
        } else if(cmp > 0) {
            return search(node.right, key);
        } else {
            return node;
        }
    }

    public BSTNode<T> search(T key) {
        return search(root, key);
    }

    /**
     * (非递归实现) 查找二叉树数中值为key的结点
     * @param  node 查找的二叉树根结点
     * @param  key  查找的结点key值
     * @return
     */
    private BSTNode<T> iterativeSearch(BSTNode<T> node, T key) {
        while(node != null) {
            int cmp = key.compareTo(node.key);
            if(cmp < 0) {
                node = node.left;
            } else if(cmp > 0) {
                node = node.right;
            } else {
                return node;
            }
        }

        return node;
    }

    public BSTNode<T> iterativeSearch(T key) {
        return iterativeSearch(root, key);
    }

    /**
     * 查找最大结点
     * @param  tree 查找最大结点的二叉树
     * @return
     */
    private BSTNode<T> maximum(BSTNode<T> tree) {
        if(tree == null) {
            return null;
        }

        while(tree.right != null) {
            tree = tree.right;
        }

        return tree;
    }

    public BSTNode<T> maximum() {
        return maximum(root);
    }

    /**
     * 查找最小结点
     * @param  tree 查找最小结点的二叉树
     * @return
     */
    private BSTNode<T> minimum(BSTNode<T> tree) {
        if(tree == null) {
            return null;
        }

        while(tree.left != null) {
            tree = tree.left;
        }

        return tree;
    }

    public BSTNode<T> minimum() {
        return minimum(root);
    }

    /**
     * 查找结点的后继结点,即，查找"二叉树中数据值大于该结点"的"最小结点"。
     * @param  node 找后继结点的结点
     * @return
     */
    public BSTNode<T> successor(BSTNode<T> node) {
        // 如果node存在右孩子，则"x的后继结点"为 "以其右孩子为根的子树的最小结点"。
        if(node.right != null) {
            return minimum(node.right);
        }

        // 如果node没有右孩子。则x有以下两种可能：
        // node是"一个左孩子"，则"node的后继结点"为 "它的父结点"。
        // node是"一个右孩子"，则查找"node的最低的父结点，并且该父结点要具有左孩子"，找到的这个"最低的父结点"就是"node的后继结点"。
        BSTNode<T> parent = node.parent;
        while((parent != null) && (node != parent.right)) {
            node   = parent;
            parent = parent.parent;
        }

        return parent;
    }

    /**
     *  找结点node的前驱结点。即，查找"二叉树中数据值小于该结点"的"最大结点"。
     * @param  node 找前驱结点的结点
     * @return
     */
    public BSTNode<T> predecessor(BSTNode<T> node) {
        // 如果node存在左孩子，则"x的前驱结点"为 "以其左孩子为根的子树的最大结点"。
        if(node.left != null) {
            return maximum(node.left);
        }

        // 如果node没有左孩子。则x有以下两种可能：
        // node是"一个右孩子"，则"node的前驱结点"为 "它的父结点"。
        // node是"一个左孩子"，则查找"node的最低的父结点，并且该父结点要具有右孩子"，找到的这个"最低的父结点"就是"node的前驱结点"。
        BSTNode<T> parent = node.parent;
        while((parent != null) && (node != parent.left)) {
            node   = parent;
            parent = parent.parent;
        }

        return parent;
    }

    /**
     * 将结点插入到二叉树中
     * @param tree 二叉树
     * @param node 插入结点
     */
    private void insert(BSTree<T> tree, BSTNode<T> node) {
        int cmp;
        BSTNode<T> y = null;
        BSTNode<T> x = tree.root;

        // 查找node的位置
        while(x != null) {
            y = x;
            cmp = node.key.compareTo(x.key);
            if(cmp < 0) {
                x = x.left;
            } else {
                x = x.right;
            }
        }

        node.parent = y;
        if(y == null) {
            tree.root = node;
        } else {
            cmp = node.key.compareTo(y.key);
            if(cmp < 0) {
                y.left = node;
            } else {
                y.right = node;
            }
        }
    }

    public void insert(T key) {
        BSTNode<T> node =new BSTNode<T>(key, null, null, null);
        if(node != null) {
            insert(this, node);
        }
    }

    /**
     * 删除tree二叉树中的结点node,并返回删除结点
     * @param  tree 二叉树
     * @param  node 删除结点
     * @return
     */
    private BSTNode<T> remove(BSTree<T> tree, BSTNode<T> node) {
        BSTNode<T> x = null;
        BSTNode<T> y = null;

        if((node.left == null) || (node.right == null)) {
            y = node;
        } else {
            // 如果node有左右孩子,就把node的后继结点赋值给y
            y = successor(node);
        }

        if(y.left != null) {
            x = y.left;
        } else {
            x = y.right;
        }

        // 如果node或者node后继结点的左右子树有不等于空时,就让改结点父结点指向node
        if( x != null) {
            x.parent = y.parent;
        }

        if(y.parent == null) {
            // 如果node或者node的后继结点的父节点会null,说明node就是根结点且没有左右子树
            tree.root = node;
        } else if(y == y.parent.left) {
            y.parent.left = x;
        } else {
            y.parent.right = x;
        }

        if(y != node) {
            node.key = y.key;
        }

        return y;
    }

    public void remove(T key) {
        BSTNode<T> node;
        if((node = search(root, key)) != null) {
            remove(this, node);
        }
    }

    /**
     * 摧毁二叉树
     * @param node 摧毁二叉树的根结点
     */
    private void destory(BSTNode<T> node) {
        if(node == null) {
            return ;
        }

        if(node.left != null) {
            destory(node.left);
        }
        if(node.right != null) {
            destory(node.right);
        }

        node = null;
    }

    public void clear() {
        destory(root);
    }

    private void print(BSTNode<T> node, T key, int direction) {
        if(node != null) {
            if(direction == 0) {
                System.out.println(node.key + " is root \n");
            } else {
                System.out.println(node.key + " is " + key + "'s" + (direction == 1 ? " right" : " left") + " child");
            }

            print(node.left, node.key, -1);
            print(node.right, node.key, 1);
        }
    }

    public void print() {
        if(root != null) {
            print(root, root.key, 0);
        }
    }
}