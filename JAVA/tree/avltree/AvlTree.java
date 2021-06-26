package tree.avltree;

/**
 * AVL树Java实现
 */

public class AvlTree<T extends Comparable<T>> {
    AvlTreeNode<T> root;

    class AvlTreeNode<T extends Comparable<T>> {
        T   key;    // 结点值
        int height; // 高度
        
        AvlTreeNode<T> left; // 左孩子
        AvlTreeNode<T> right; // 右孩子

        public AvlTreeNode(final T key, final AvlTreeNode<T> left, final AvlTreeNode<T> right) {
            this.key    = key;
            this.left   = left;
            this.right  = right;
            this.height = 0;
        }
    }

    public AvlTree() {
        this.root = null;
    }

    /**
     * 获取树的高度
     */
    private int height(final AvlTreeNode<T> node) {
        return node != null ? node.height : 0;
    }

    /**
     * 树的高度
     */
    public int height() {
        return height(root);
    }

    /**
     * 比较两个值的大小
     */
    private int max(final int a, final int b) {
        return a > b ? a : b;
    }

    /**
     * 前序遍历
     */
    private void preOrder(final AvlTreeNode<T> tree) {
        if(tree != null) {
            System.out.print(tree.key + " ");
            preOrder(tree.left);
            preOrder(tree.right);
        }
    }

    public void preOrder() {
        preOrder(root);
    }

    /**
     * 中序遍历
     */
    private void inOrder(final AvlTreeNode<T> tree) {
        if(tree != null) {
            inOrder(tree.left);
            System.out.print(tree.key + " ");
            inOrder(tree.right);
        }
    }

    public void inOrder() {
        inOrder(root);
    }

    /**
     * 后序遍历
     */
    private void postOrder(final AvlTreeNode<T> tree) {
        if(tree != null) {
            postOrder(tree.left);
            postOrder(tree.right);
            System.out.print(tree.key + " ");
        }
    }

    public void postOrder() {
        postOrder(root);
    }

    /**
     * 查找tree 树中值为key的结点(递归实现)
     * 
     * @param  tree avl树根结点
     * @param  key  查找的值
     * @return
     */
    private AvlTreeNode<T> search(final AvlTreeNode<T> tree, final T key) {
        if(tree == null) return null;

        if(key.compareTo(tree.key) < 0) {
            return search(tree.left, key);
        } else if(key.compareTo(tree.key) > 0) {
            return search(tree.right, key);
        } else {
            return tree;
        }
    }

    public AvlTreeNode<T> search(final T key) {
        return search(root, key);
    }

    /**
     * 查找tree 树中值为key的结点(递归实现
     * 
     * @param  tree avl树根结点
     * @param  key  查找的值
     * @return
     */
    private AvlTreeNode<T> iteratorSearch(AvlTreeNode<T> tree, final T key) {
        while(tree != null) {
            if(key.compareTo(tree.key) > 0) {
                tree = tree.right;
            } else if(key.compareTo(tree.key) < 0) {
                tree =tree.left;
            } else {
                return tree;
            }
        }
        
        return tree;
    }

    public AvlTreeNode<T> iteratorSearch(final T key) {
        return iteratorSearch(root, key);
    }

    /**
     * 查找tree树中的最小值
     * 
     * @param  tree 查找最小树的值
     * @return
     */
    private AvlTreeNode<T> minimum(AvlTreeNode<T> tree) {
        if(tree == null) return null;
        
        while(tree.left != null) {
            tree = tree.left;
        }

        return tree;
    }

    public T minimum() {
        AvlTreeNode<T> min = minimum(root);
        return min != null ? min.key : null;
    }

    /**
     * 查找tree树中的最大值
     * 
     * @param   tree 查找最大树的值
     * @return
     */
    private AvlTreeNode<T> maximum(AvlTreeNode<T> tree) {
        if(tree == null) return null;

        while(tree.right != null) {
            tree = tree.right;
        }

        return tree;
    }

    public T maximum() {
        AvlTreeNode<T> max = maximum(root);
        return max != null ? max.key : null;
    }

    /**
     * LL: 左左对应的情况(左单旋转)
     * 
     * @param  tree 进行旋转的tree
     * @return
     */
    private AvlTreeNode<T> leftLeftRotation(final AvlTreeNode<T> tree) {
        AvlTreeNode<T> tmp = tree.left;

        tree.left = tmp.right;
        tmp.right = tree;

        tree.height = max(height(tree.left), height(tree.right)) + 1;
        tmp.height  = max(height(tmp.left), height(tmp.right)) + 1;

        return tmp;
    }

    /**
     * RR: 右右对应的情况(右单旋转)
     * 
     * @param  tree 进行旋转的tree
     * @return
     */
    private AvlTreeNode<T> rightRightRotation(final AvlTreeNode<T> tree) {
        AvlTreeNode<T> tmp = tree.right;

        tree.right = tmp.left;
        tmp.left   = tree;

        tree.height = max(height(tree.left), height(tree.right)) + 1;
        tmp.height  = max(height(tmp.left), height(tree.right)) + 1;

        return tmp;
    }

    /**
     * LR: 左右对应的情况(左双旋转)
     * 
     * @param  tree 进行旋转的tree
     * @return
     */
    private AvlTreeNode<T> leftRightRotation(final AvlTreeNode<T> tree) {
        tree.left = rightRightRotation(tree.left);

        return leftLeftRotation(tree);
    }

    /**
     * RL: 右左对应的情况(右双旋转)
     * 
     * @param  tree 进行旋转的tree
     * @return
     */
    private AvlTreeNode<T> rightLeftRotation(final AvlTreeNode<T> tree) {
        tree.right = leftLeftRotation(tree.right);

        return rightRightRotation(tree);
    }    

    /**
     * 向AVL树中插入一个新值Key
     * 
     * @param  tree 插入的值的树
     * @param  key  插入的值
     * @return
     */
    private AvlTreeNode<T> insert(AvlTreeNode<T> tree, T key) {
        if(tree == null) {
            tree = new AvlTreeNode<T>(key, null, null);
        } else if(key.compareTo(tree.key) < 0) {
            // 插入值应该在tree的左孩子中
            tree.left = insert(tree.left, key);
            // 插入值如果影响tree的平衡就需要进行恢复平衡操作
            if(height(tree.left) - height(tree.right) == 2) {
                if(key.compareTo(tree.left.key) > 0) {
                    tree = leftRightRotation(tree);
                } else {
                    tree = leftLeftRotation(tree);
                }
            }
        } else if(key.compareTo(tree.key) > 0) {
            // 插入值应该在tree的右孩子中
            tree.right = insert(tree.right, key);
            // 插入值如果影响tree的平衡就需要进行恢复平衡操作
            if(height(tree.right) - height(tree.left) == 2) {
                if(key.compareTo(tree.right.key) > 0) {
                    tree = rightRightRotation(tree);
                } else {
                    tree = rightLeftRotation(tree);
                }
            }
        } else {
            System.out.println("插入新元素错误，不能存在相同的数");
        }

        tree.height = max(height(tree.left), height(tree.right)) + 1;

        return tree;
    }

    public void insert(T key) {
        root = insert(root, key);
    }

    /**
     * 从平衡树中删除结点key
     * 
     * @param  tree 删除的平衡树
     * @param  key  删除的结点
     * @return
     */
    private AvlTreeNode<T> remove(AvlTreeNode<T> tree, final AvlTreeNode<T> key) {
        if(tree == null || key == null) return null;

        if(key.key.compareTo(tree.key) < 0) {
            // 删除值应该发生在左孩子中
            tree.left = remove(tree.left, key);
            // 删除值如果影响tree的平衡就需要进行恢复平衡操作
            if(height(tree.right) - height(tree.left) == 2) {
                if(key.key.compareTo(tree.left.key) < 0) {
                    final AvlTreeNode<T> right = tree.right;
                    if(height(right.left) > height(right.right)) {
                        tree = rightLeftRotation(tree);
                    } else {
                        tree = rightRightRotation(tree);
                    }
                }
            }
        } else if(key.key.compareTo(tree.key) > 0){
            // 删除的值应该发生在右孩子的中
            tree.right = remove(tree.right, key);
            // 删除值如果影响tree的平衡就需要进项恢复平衡操作
            if(height(tree.left) - height(tree.right) == 2) {
                final AvlTreeNode<T> left = tree.left;
                if(height(left.left) > height(left.right)) {
                    tree = leftLeftRotation(tree);
                } else {
                    tree = leftRightRotation(tree);
                }
            }
        } else {
            // 要删除的key结点就是tree
            if(tree.left != null && tree.right != null) {
                if(height(tree.left) > height(tree.right)) {
                    // 如果tree的左子树比右子树高；
                    // 则(01)找出tree的左子树中的最大节点
                    //   (02)将该最大节点的值赋值给tree。
                    //   (03)删除该最大节点。
                    // 这类似于用"tree的左子树中最大节点"做"tree"的替身；
                    // 采用这种方式的好处是：删除"tree的左子树中最大节点"之后，AVL树仍然是平衡的
                    final AvlTreeNode<T> maximum = maximum(tree.left);
                    tree.key = maximum.key;
                    tree.left = remove(tree.left, maximum);
                } else {
                    // 如果tree的左子树不比右子树高(即它们相等，或右子树比左子树高1)
                    // 则(01)找出tree的右子树中的最小节点
                    //   (02)将该最小节点的值赋值给tree。
                    //   (03)删除该最小节点。
                    // 这类似于用"tree的右子树中最小节点"做"tree"的替身；
                    // 采用这种方式的好处是：删除"tree的右子树中最小节点"之后，AVL树仍然是平衡的
                    final AvlTreeNode<T> minimum = minimum(tree.right);
                    tree.key = minimum.key;
                    tree.right = remove(tree.right, minimum);
                }
            } else {
                AvlTreeNode<T> tmp = tree;
                tree = tree.left != null ? tree.left : tree.right;
                tmp  = null;
            }
        }

        if(tree != null) {
            tree.height = max(height(tree.left), height(tree.right)) + 1;
        }

        return tree;
    }

    public void remove(final T key) {
        final AvlTreeNode<T> node = search(key);
        if(node != null){
            remove(root, node);
        }
    }

    /**
     * 摧毁avl平衡树
     * 
     * @param tree
     */
    private void destory(AvlTreeNode<T> tree) {
        if(tree == null) return;

        if(tree.left != null) {
            destory(tree.left);
        }
        if(tree.right != null) {
            destory(tree.right);
        }

        tree = null;
    }

    public void destory() {
        destory(root);
    }

    /**
     * 打印 AVL树
     *  
     * @param tree        树
     * @param key         父结点值
     * @param direction   0表示根/-1表示左孩子/1表示右孩子
     */
    private void print(final AvlTreeNode<T> tree, final T key, final int direction) {
        if(tree != null) {
            if(direction == 0) {
                System.out.printf("%2d is root\n", tree.key);
            } else {
                System.out.printf("%2d is %2d's %6s child\n", tree.key, key, direction == 1 ? "left" : "right");
            }

            print(tree.left, tree.key, -1);
            print(tree.right, tree.key, 1);
        }
    }

    public void print() {
        if(root != null) {
            print(root, root.key, 0);
        }
    }
}