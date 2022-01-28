/**
 * 伸展树的实现(C)
 */

#include<stdio.h>
#include<stdlib.h>
#include"splay_tree.h"

/**
 * 前序遍历"伸展树"
 */
void preorder_splaytree(SplayTree tree) {
    if(tree != NULL) {
        printf("%d ", tree->key);
        preorder_splaytree(tree->left);
        preorder_splaytree(tree->right);
    }
}

/**
 * 中序遍历"伸展树"
 */
void inorder_splaytree(SplayTree tree) {
    if(tree != NULL) {
        inorder_splaytree(tree->left);
        printf("%d ", tree->key);
        inorder_splaytree(tree->right);
    }
}

/**
 * 后序遍历"伸展树"
 */
void postorder_splaytree(SplayTree tree) {
    if(tree != NULL) {
        postorder_splaytree(tree->left);
        postorder_splaytree(tree->right);
        printf("%d ", tree->key);
    }
}

/**
 * 递归查找
 */
Node* splaytree_search(SplayTree tree, Type key) {
    if(key == NULL || key == tree->key) return tree;

    if(key < tree->key) {
       return splaytree_search(tree->left, key);
    } else {
       return splaytree_search(tree->right, key);
    }
}

/**
 * 非递归查找
 */
Node* iterative_splaytree_search(SplayTree tree, Type key) {
    while(key != NULL && tree->key != key) {
        if(key < tree->key) {
            tree = tree->left;
        } else {
            tree = tree->right;
        }
    }

    return tree;
}

/**
 * 查找最小结点
 */
Node* splaytree_minimum(SplayTree tree) {
    if(tree == NULL) return NULL;

    while(tree->left != NULL) {
        tree = tree->left;
    }

    return tree;
}

/**
 * 查找最大结点
 */
Node* splaytree_maximum(SplayTree tree) {
    if(tree == NULL) return NULL;

    while(tree->right != NULL) {
        tree = tree->right;
    }

    return tree;
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
 */
Node* splaytree_splay(SplayTree tree, Type key) {
    Node N, *l, *r, *c;

    if(tree == NULL) return NULL;

    N.left = N.right = NULL;
    l = r = &N;

    for(;;) {
        if(key < tree->key) {
            // 如果当前key值小于根结点值，并且根结点不存在左子树，则说明当前的tree不需要进行旋转
            if(tree->left == NULL) {
                break;
            }
            if(key < tree->left->key) {
                c = tree->left;
                tree->left = c->right;
                c->right = tree;
                tree = c;
                // 旋转后检查旋转后的tree的左子树是否存在,则为2-2规则结束循环
                if(tree->left == NULL) {
                    break;
                }
            }
            r->left = tree;
            r = tree;
            tree = tree->left;
        } else if(key > tree->key) {
            // 如果当前key的值小于跟结点值，并且根结点不存在右子树，则说明当前的tree不需要进行旋转
            if(tree->right == NULL) {
                break;
            }
            if(key > tree->right->key) {
                c = tree->right;
                tree->right = c->left;
                c->left = tree;
                tree = c;
                // 旋转后检查旋转后的tree的右子树是否还存在右子树，则说明当前的tree不需要进行旋转
                if(tree->right == NULL) {
                    break;
                }
            }
            l->right = tree;
            l = tree;
            tree = tree->right;
        } else {
            break;
        }
    }

    l->right    = tree->left;
    r->left     = tree->right;
    tree->left  = N.right;
    tree->right = N.left;

    return tree;
}

/**
 * @brief 将结点插入到伸展树中(不旋转)
 * 
 * @param tree   伸展数据根结点
 * @param z      插入的结点
 * @return Node* 返回根结点
 */
static Node* splaytree_insert(SplayTree tree, Node *z) {
    Node *y = NULL;
    Node *x = tree;

    // 查找到z插入的位置
    while(x != NULL) {
        y = x;
        if(z->key < x->key) {
            x = x->left;
        } else if(z->key > x->key) {
            x = x->right;
        } else {
            printf("不允许插入相同节点(%d)!\n", z->key);
            free(z);
            return tree;
        }
    }

    if(y == NULL) {
        tree = z;
    } else if (z->key < y->key) {
        y->left = z;
    } else {
        y->right = z;
    }

    return tree;
}

/**
 * @brief 创建并返回伸展树结点
 * 
 * @param key    键值
 * @param left   左孩子
 * @param right  右孩子
 * @return Node* 伸展结点
 */
static Node* create_splaytree_node(Type key, Node *left, Node *right) {
    Node *n;

    if((n = (Node *)malloc(sizeof(Node))) == NULL) {
        return NULL;
    }

    n->key   = key;
    n->left  = left;
    n->right = right;

    return n;
}

/**
 * @brief 新建结点(key),然后插入到伸展树中，最后将插入的结点旋转为根结点
 * 
 * @param tree   伸展树
 * @param key    键值
 * @return Node* 返回根结点
 */
Node* insert_splaytree(SplayTree tree, Type key) {
    Node* n; // 新建结点

    // 创建结点失败,则直接返回
    if((n = create_splaytree_node(key, NULL, NULL)) == NULL) {
        return tree;
    }

    // 插入节点
    tree = splaytree_insert(tree, n);
    // 将节点旋转为根
    tree = splaytree_splay(tree, key);

    return tree;
}

/**
 * @brief 删除结点（key为结点的键值），并返回根结点（为删除结点的前驱结点）
 * 
 * @param  tree 伸展树的根结点 
 * @param  key  删除结点的键值
 * @return Node* 
 */
Node* delete_splaytree(SplayTree tree, Type key) {
    Node *n;

    if(tree == NULL) {
        return NULL;
    }

    // 如果键值为key的结点没有找到直接返回
    if(splaytree_search(tree, key) == NULL) {
        return tree;
    }

    // 将key对应的结点旋转为根结点
    tree = splaytree_splay(tree, key);
    if(tree->left != NULL) {
        n = splaytree_splay(tree->left, key);
        // 移除tree的根结点
        n->right = tree->right;
    } else {
        n = tree->right;
    }

    free(tree);

    return n;
}

/**
 * @brief 摧毁伸展树 
 * 
 * @param tree 
 */
void destory_splaytree(SplayTree tree) {

    if(tree == NULL) return;

    if(tree->left != NULL) {
        destory_splaytree(tree->left);
    }
    if(tree->right != NULL) {
        destory_splaytree(tree->right);
    }

    free(tree);
}

/**
 * @brief 打印伸展树
 * 
 * @param tree       伸展树根结点
 * @param key        结点键值
 * @param direction  0,表示该结点是根结点
 *                   -1,表示该结点是它父结点的左孩子
 *                   1,表示该结点是它父结点的右孩子
 */
void print_splaytree(SplayTree tree, Type key, int direction) {

    if(tree != NULL) {
        if(direction == 0) {
            printf("%2d is root\n", tree->key);
        } else {
            printf("%2d is %2d's %6s child\n", tree->key, key, direction == 1 ? "right" : "left");
        }

        print_splaytree(tree->left, tree->key, -1);
        print_splaytree(tree->right, tree->key, 1);
    }
}