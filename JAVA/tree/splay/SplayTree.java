package tree.splay;

import tree.splay.SplayTree.SplayTreeNode;

/* * 
 * 伸展树实现
 * @Author: huanglin 
 * @Date: 2022-02-15 23:13:12 
 */ 
public class SplayTree<T extends Comparable<T>>{

    private SplayTreeNode<T> root;
    
    public class SplayTreeNode<T extends Comparable<T>> {
        T                key;   // 值
        SplayTreeNode<T> left;  // 左孩子
        SplayTreeNode<T> right; // 右孩子

        public SplayTreeNode() {
            this.left  = null;
            this.right = null;
        }

        public SplayTreeNode(T key, SplayTreeNode<T> left, SplayTreeNode<T> right) {
            this.key   = key;
            this.left  = left;
            this.right = right;
        }
    }

    public SplayTree() {
        root = null;
    }

    /**
     * 前序遍历
     * @param tree
     */
    private void preOrder(SplayTreeNode<T> tree) {
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
     * @param tree
     */
    private void inOrder(SplayTreeNode<T> tree) {
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
     * 后续遍历
     * @param tree
     */
    private void postOrder(SplayTreeNode<T> tree) {
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
     * 递归遍历查找
     * @param tree
     * @param key
     * @return
     */
    private SplayTreeNode<T> search(SplayTreeNode<T> tree, T key) {
        if(tree == null) {
            return tree;
        }

        int compareTo = key.compareTo(tree.key);
        if(compareTo < 0) {
            return search(tree.left, key);
        } else if(compareTo > 0) {
            return search(tree.right, key);
        } else {
            return tree;
        }
    }

    public SplayTreeNode<T> search(T key) {
        return search(root, key);
    }

    /**
     * 非递归实现查找
     * @param tree
     * @param key
     * @return
     */
    private SplayTreeNode<T> iteratorSearch(SplayTreeNode<T> tree, T key) {
        while(tree != null) {
            int compareTo = key.compareTo(tree.key);
            if(compareTo < 0) {
                tree = tree.left;
            }
            else if(compareTo > 0) {
                tree = tree.right;
            } else {
                return tree;
            }
        }

        return tree;
    }
    
    public SplayTreeNode<T> iteratorSearch(T key) {
    	return iteratorSearch(root, key);
    }
    
    /**
     * 查找伸展树中的最小值结点
     * @param tree
     * @return
     */
    private SplayTreeNode<T> minimum(SplayTreeNode<T> tree) {
    	if(tree == null) {
    		return null;
    	}
    	
    	while(tree.left != null) {
    		tree = tree.left;
    	}
    	
    	return tree;
    }
    
    public T minimum() {
    	SplayTreeNode<T> minimum = minimum(root);

    	return minimum != null ? minimum.key : null;
    }
    
    /**
     * 查找
     * @param tree
     * @return
     */
    private SplayTreeNode<T> maximum(SplayTreeNode<T> tree) {
    	if(tree == null) {
    		return null;
    	}
    	
    	while(tree.right != null) {
    		tree = tree.right;
    	}
    	
    	return tree;
    }
    
    public T maximum() {
    	SplayTreeNode<T> maximum = maximum(root);
    	
    	return maximum != null ? maximum.key : null;
    }
    
    /**
     * 旋转key对应的结点为根结点,并返回根结点.
     * 
     * 换转规则：
     *  1. 伸展树中存在"键值为key的结点",将"键值为key的结点"旋转为根结点
     *  2. 伸展树中不存在“键值为key的结点",并key < tree->key
     *      2-1. “键值为key的结点”的前驱存在的话,将"键值为key的前驱结点旋转为根结点".
     *      2-2. "键值为key的结点"的前驱结点不存在的话,则说明key比树中任何结点的值都小,那么此时需要将最小的结点旋转为根结点
     *  3. 伸展树中不存在”键值为key的结点“,并key > tree->key
     *      3-1. ”键值为key的结点“的后继结点存在的话,将”键值为key的结点“的后继结点旋转为根结点。
     *      3-2. ”键值为key的结点“的后继结点不存在的话,则说明key比树中任何结点的值都大,那么此时需要将最小的结点旋转为根结点
     * @param tree
     * @param key
     * @return
     */
    private SplayTreeNode<T> splay(SplayTreeNode<T> tree, T key) {
    	if(tree == null) {
    		return tree;
    	}
    	
    	SplayTreeNode<T> node  = new SplayTreeNode<>();
    	SplayTreeNode<T> left  = node;
    	SplayTreeNode<T> right = node;
    	SplayTreeNode<T> change;

        for(;;) {
            int compareTo = key.compareTo(tree.key);
            if(compareTo < 0) {
                if(tree.left == null) {
                    break;
                }

                if(key.compareTo(tree.left.key) < 0) {
                    change       = tree.left;
                    tree.left    = change.right;
                    change.right = tree;
                    tree = change;
                    if(tree.left == null) {
                        break;
                    }
                }

                right.left = tree;
                right      = tree;
                tree       = tree.left;
            } else if(compareTo > 0) {
                if(tree.right == null) {
                    break;
                }

                if(key.compareTo(tree.right.key) > 0) {
                    change      = tree.right;
                    tree.right  = change.left;
                    change.left = tree;
                    tree        = change;
                    if(tree.right == null) {
                        break;
                    }
                }

                left.right  = tree;
                left        = tree;
                tree        = tree.right;
            } else {
                break;
            } 
        }
        
        left.right = tree.left;
        right.left = tree.right;
        tree.right = node.left;
        tree.left  = node.right;

        return tree;
    }

    public void splay(T key) {
        root = splay(root, key);
    }

    /**
     * 将结点插入到伸展树中，并返回根结点
     * @param tree
     * @param z
     * @return
     */
    private SplayTreeNode<T> insert(SplayTreeNode<T> tree, SplayTreeNode<T> z) {
        int cmp;
        SplayTreeNode<T> y = null;
        SplayTreeNode<T> x = tree;

        while(x != null) {
            y   = x;
            cmp = z.key.compareTo(x.key);
            if(cmp < 0) {
                x = x.left;
            } else if(cmp > 0) {
                x = x.right;
            } else {
                System.out.println("不允许插入相同的结点值: " + z.key);
                z = null;
                return tree;
            }
        }

        if(y == null) {
            tree = z;
        } else {
            cmp = z.key.compareTo(y.key);
            if(cmp < 0) {
                y.left = z;
            } else {
                y.right = z;
            }
        }

        return tree;
    }

    public void insert(T key) {
        SplayTreeNode<T> z = new SplayTreeNode<T>(key, null, null);
        if(z == null) {
            System.out.println("新建结点失败");
            return;
        }

        // 插入结点
        root = insert(root, z);
        // 把刚刚插入的结点旋转为根结点
        root = splay(root, key);
    }

    /**
     * 删除结点
     * @param tree
     * @param key
     * @return
     */
    private SplayTreeNode<T> delete(SplayTreeNode<T> tree, T key) {
        SplayTreeNode<T> ret;

        if(tree == null) {
            return null;
        }

        // 查找key值结点
        if(search(tree, key) == null) {
            return tree;
        }

        // 将key值结点
        tree = splay(tree, key);
        if(tree.left != null) {
            // 将"tree的前驱节点"旋转为根节点
           ret = splay(tree.left, key);
           ret.right = tree.right;
        } else {
           ret = tree.right;
        }
        tree = null;

        return ret;
    }

    public void delete(T key) {
        root = delete(root, key);
    }

    /**
     * 摧毁伸展树
     * @param tree
     */
    private void destory(SplayTreeNode<T> tree) {
        if(tree == null) {
            return;
        }

        if(tree.left != null) {
            destory(tree.left);
        } else if(tree.right != null) {
            destory(tree.right);
        }

        tree = null;
    }

    public void clear() {
        destory(root);
    }

    /**
     * 打印“伸展树"
     * @param tree
     * @param key
     * @param direction
     */
    private void print(SplayTreeNode<T> tree, T key, int direction) {
        if(tree != null) {
            if(direction == 0) {
                System.out.printf("%2d is root\n", tree.key);
            } else {
                System.out.printf("%2d is %2d's %6s child\n", tree.key, key, direction == 1 ? "right" : "left");
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