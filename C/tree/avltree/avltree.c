/**
 * AVL树 C语言版本
 */
#include <stdio.h>
#include <stdlib.h>
#include "avltree.h"

#define HEIGHT(p) ( (p == NULL) ? -1 : ((Node *)(p))->height )
#define MAX(a, b) ( (a) > (b) ? (a) : (b))

/**
 * 获取AVL树高度
 */
int avltree_height(AVLTree tree) {
    return HEIGHT(tree);
}

/**
 * 前序遍历AVL
 */
void preorder_avltree(AVLTree tree) {
    if(tree != NULL) {
        printf("%d ", tree->key);
        preorder_avltree(tree->left);
        preorder_avltree(tree->right);
    }
}

/**
 * 中序遍历AVL
 */
void inorder_avltree(AVLTree tree) {
    if(tree != NULL) {
        inorder_avltree(tree->left);
        printf("%d ", tree->key);
        inorder_avltree(tree->right);
    }
}

/**
 * 后序遍历AVL
 */
void postorder_avltree(AVLTree tree) {
    if(tree != NULL) {
        postorder_avltree(tree->left);
        postorder_avltree(tree->right);
        printf("%d ", tree->key);
    }
}

/**
 * (递归实现)查找“AVL树x"中键值为key的结点
 */ 
Node* avltree_search(AVLTree tree, TYPE key) {
    if(tree == NULL || tree->key == key) return tree;

    if(key < tree->key) {
        return avltree_search(tree->left, key);
    } else {
        return avltree_search(tree->right, key);
    }
}

/**
 * (非递归实现)查找”AVL树x“中键值为key的结点
 */
Node* iterative_avltree_search(AVLTree tree, TYPE key) {
    while(tree != NULL && tree->key != key) {
        if(key < tree->key) {
            tree = tree->left;
        } else {
            tree = tree->right;
        }
    }

    return tree;
}

/**
 * 查找最小结点： 返回tree为根结点的AVL树的最小结点
 */
Node* avltree_minimum(AVLTree tree) {
    if(tree == NULL) return NULL;

    while(tree->left != NULL) {
        tree = tree->left;
    }

    return tree;
}

/**
 * 查找最大结点：返回tree为根结点的AVL树的最大结点
 */
Node* avltree_maximum(AVLTree tree) {
    if(tree == NULL) return NULL;

    while(tree->right != NULL) {
        tree = tree->right;
    }

    return tree;
}

/**
 * LL : 左左对应的情况(左单旋转)
 * 返回值：旋转后的根结点
 */
static Node* left_left_rotation(AVLTree tree) {
    AVLTree retTree;

    retTree        = tree->left;
    tree->left     = retTree->right;
    retTree->right = tree;

    retTree->height = MAX(HEIGHT(retTree->left), HEIGHT(retTree->right)) + 1;
    tree->height    = MAX(HEIGHT(tree->left), HEIGHT(tree->right)) + 1;

    return retTree;
}

/**
 * RR : 右右对应的情况(右单旋转)
 * 返回值：旋转后的根结点
 */
static Node* right_right_rotation(AVLTree tree) {
    AVLTree retTree;

    retTree       = tree->right;
    tree->right   = retTree->left;
    retTree->left = tree;

    retTree->height = MAX(HEIGHT(retTree->left), HEIGHT(retTree->right)) + 1;
    tree->height    = MAX(HEIGHT(tree->left), HEIGHT(tree->right)) + 1;

    return retTree;
}

/**
 * LR ： 左右对应的情况(左双旋)
 * 返回值：旋转后的根结点
 */
static Node* left_right_rotation(AVLTree tree) {
    tree->left = right_right_rotation(tree->left);

    return left_left_rotation(tree);
}

/**
 * RL : 右左对应的情况(右双旋)
 * 返回值：旋转后的根结点
 */
static Node* right_left_rotation(AVLTree tree) {
    tree->right = left_left_rotation(tree->right);

    return right_right_rotation(tree);
}


/**
 * 创建AVL结点
 * 
 * --key   键值
 * --left  左孩子
 * --right 友孩子
 * 
 * 返回创建的结点
 */
static Node* avltree_create_node(TYPE key, Node* left, Node* right) {
    Node* p;

    if((p = (Node*)malloc(sizeof(Node))) == NULL) return NULL;

    p->key    = key;
    p->left   = left;
    p->right  = right;
    p->height = 0;

    return p;
};

/**
 * 将结点插入到树中，并返回根结点
 * 
 * -- tree AVL树根结点
 * -- key  插入结点的值
 * 
 * 返回插入后的树的根结点
 */
Node* avltree_insert(AVLTree tree, TYPE key) {
    if(tree == NULL) {
        // 创建新结点
        tree = avltree_create_node(key, NULL, NULL);
        if(tree == NULL) {
            printf("ERROR: create avltree node failed!\n");

            return NULL;
        }
    } else if(key < tree->key){
        // 将key插入到tree的左子树
        tree->left = avltree_insert(tree->left, key);
        // 插入接点后，若AVL树失去平衡,则进行相应的的调节
        if(HEIGHT(tree->left) - HEIGHT(tree->right) == 2) {
            if(key < tree->left->key) {
                tree = left_left_rotation(tree);
            } else {
                tree = left_right_rotation(tree);
            }
        }
    } else if(key > tree->key) {
        // 将key插入到tree的右子树
        tree->right = avltree_insert(tree->right, key);
        // 插入接点后，若AVL树失去平衡,则进行相应的的调节
        if(HEIGHT(tree->right) - HEIGHT(tree->left) == 2) {
            if(key < tree->right->key) {
                tree = right_left_rotation(tree);
            } else {
                tree = right_right_rotation(tree);
            }
        }
    } else {
        printf("添加失败: 不允许添加相同的结点!\n");
    }

    tree->height = MAX(HEIGHT(tree->left), HEIGHT(tree->right)) + 1;

    return tree;
}

/**
 * 删除结点node, 返回根结点
 * 
 * -- tree AVL树根结点
 * -- node 待删除的结点
 * 
 * 返回删除后的根结点
 */
static Node* delete_node(AVLTree tree, Node* node){
    // 如果根为或没有待删除的结点，直接返回
    if (tree == NULL || node == NULL) return NULL;

    if(node->key < tree->key) {
        // 待删除的结点在左子树中
        tree->left = delete_node(tree->left, node);
        // 删除结点后，AVL树失去平衡，则进相应的调节
        if(HEIGHT(tree->right) - HEIGHT(tree->left) == 2) {
            Node* right = tree->right;
            if(HEIGHT(right->left) > HEIGHT(right->right)) {
                tree = right_left_rotation(tree);
            } else {
                tree = right_right_rotation(tree);
        }
    } else if(node->key > tree->key) {
        // 待删除的结点在右子树中
        tree->right = delete_node(tree->right, node);
        // 删除结点后，AVL树失去平衡，则进相应的调节
        if(HEIGHT(tree->left) - HEIGHT(tree->right) == 2) {
            Node* left = tree->left;
            if(HEIGHT(left->left) > HEIGHT(left->right)) {
                tree = left_left_rotation(tree);
            } else {
                tree = left_right_rotation(tree);
            }
        }
    } else {
        // tree是对应要删除的结点
        if((tree->left) && (tree->right)) {
            if(HEIGHT(tree->left) > HEIGHT(tree->right)) {
                // 如果tree的左子树比右子树高；
                // 则(01)找出tree的左子树中的最大节点
                //   (02)将该最大节点的值赋值给tree。
                //   (03)删除该最大节点。
                // 这类似于用"tree的左子树中最大节点"做"tree"的替身；
                // 采用这种方式的好处是：删除"tree的左子树中最大节点"之后，AVL树仍然是平衡的
                Node* max  = avltree_maximum(tree->left);
                tree->key  = max->key;
                tree->left = delete_node(tree->left, max);
            } else {
                // 如果tree的左子树不比右子树高(即它们相等，或右子树比左子树高1)
                // 则(01)找出tree的右子树中的最小节点
                //   (02)将该最小节点的值赋值给tree。
                //   (03)删除该最小节点。
                // 这类似于用"tree的右子树中最小节点"做"tree"的替身；
                // 采用这种方式的好处是：删除"tree的右子树中最小节点"之后，AVL树仍然是平衡的。
                Node* min   = avltree_minimum(tree->right);
                tree->key   = min->key;
                tree->right = delete_node(tree->right, min);
            }
        } else {
            Node* temp = tree;
            tree = tree->left ? tree->left : tree->right;
            free(temp);
            }
        }
    }

    if(tree != NULL) {
        tree->height = MAX(HEIGHT(tree->left), HEIGHT(tree->right)) + 1;
    }

    return tree;
}

/**
 * 删除值为key的结点，返回根结点
 * 
 * -- tree AVL树的根结点
 * -- key  删除结点的值
 * 
 * 返回删除后的根结点
 */
Node* avltree_delete(AVLTree tree, TYPE key) {
    Node* node;

    if((node = avltree_search(tree, key)) != NULL) tree = delete_node(tree, node);

    return tree;
}

/**
 * 摧毁AVL树
 */
void destroy_avltree(AVLTree tree) {
    if(tree == NULL) return;

    if(tree->left != NULL) {
        destroy_avltree(tree->left);
    }

    if(tree->right != NULL) {
        destroy_avltree(tree->right);
    }

    free(tree);
}

/**
 * 打印AVL树
 * 
 * -- tree       树的根结点
 * -- key        结点值
 * -- direction  0: 表示该结点是根
 *              -1：表示该结点是它父结点的左孩子
 *               1：表示该结点是它父结点的右孩子
 */
void print_avltree(AVLTree tree, TYPE key, int direction) {
    if(tree != NULL) {
        if(direction == 0) {
            printf("%2d is root\n", key);
        } else {
            printf("%2d is %2d's %6s child\n", tree->key, key, direction == 1 ? "right" : "left");
        }

        print_avltree(tree->left, tree->key, -1);
        print_avltree(tree->right, tree->key, 1);
    }
}