#include<stdio.h>
#include<stdlib.h>
#include "bstree.h"

/**
 * 二叉查找树的具体实现
 */

// 前序遍历二叉树
void preorder_bstree(BSTree tree) {
    if(tree != NULL) {
        printf("%d", tree->key);
        preorder_bstree(tree->left);
        preorder_bstree(tree->right);
    }
}

// 中序遍历二叉树
void inorder_bstree(BSTree tree) {
    if(tree != NULL) {
        inorder_bstree(tree->left);
        printf("%d", tree->key);
        inorder_bstree(tree->right);
    }
}

// 后序遍历二叉树
void postorder_bstree(BSTree tree) {
    if(tree != NULL) {
        postorder_bstree(tree->left);
        postorder_bstree(tree->right);
        printf("%d", tree->key);
    }
}

// 递归实现查找二叉树中的键值为key的结点
Node* bstree_search(BSTree tree, Type key) {
    if(tree == NULL || tree->key == key) {
        return tree;
    }

    if(key < tree->key) {
        return bstree_search(tree->left, key);
    } else {
        return bstree_search(tree->right, key);
    }
}

// 非递归实现查找二叉树中的键值为key的结点
Node* iterative_bstree_search(BSTree tree, Type key) {
    while((tree != NULL) && (tree->key != key)) {
        if(key < tree->key) {
            tree = tree->left;
        } else {
            tree = tree->right;
        }
    }

    return tree;
}

// 查找最小结点,返回tree为根结点的二叉树的最小结点
Node* bstree_minimum(BSTree tree){
    if(tree == NULL) {
        return NULL;
    }

    while(tree->left != NULL) {
        tree = tree->left;
    }

    return tree;
}

// 查找最大结点,返回tree为根结点的二叉树的最大结点
Node* bstree_maximum(BSTree tree) {
    if(tree == NULL) {
        return NULL;
    }

    while(tree->right != NULL) {
        tree = tree->right;
    }

    return tree;
}

// 找结点node的后继结点,即，查找"二叉树中数据值大于该结点"的"最小结点"。
Node* bstree_successor(Node *node) {
    // 如果node存在右孩子,则node的后继结点就为以他右孩子为子树中的最小结点
    if(node->right != NULL) {
        return bstree_minimum(node->right);
    }
    // 如果node没有右孩子。则node有以下两种可能：
    // node是"一个左孩子"，则"x的后继结点"为 "它的父结点"。
    // node是"一个右孩子"，则查找"x的最低的父结点，并且该父结点要具有左孩子"，找到的这个"最低的父结点"就是"x的后继结点"。
    Node* parent = node->parent;
    while((parent != NULL) && (parent->right == node)) {
        node = parent;
        parent = parent->parent;
    }

    return parent;
}

// 找结点node的前驱结点,即，查找"二叉树中数据值小于该结点"的"最大结点"。
Node* bstree_predecessor(Node *node) {
    // 如果node存在左孩子,则node的前驱结点就是以他左孩子为子树中的最大结点
    if(node->left != NULL) {
        return bstree_maximum(node->left);
    }

    // 如果x没有左孩子。则x有以下两种可能：
    // (01) x是"一个右孩子"，则"x的前驱结点"为 "它的父结点"。
    // (01) x是"一个左孩子"，则查找"x的最低的父结点，并且该父结点要具有右孩子"，找到的这个"最低的父结点"就是"x的前驱结点"。
    Node *parent = node->parent;
    if((parent != NULL) && (parent->left == node)) {
        node = parent;
        parent = parent->parent;
    }

    return parent;
}

// 创建二叉树结点并返回:key 结点值,parent 结点的父结点, left 结点左孩子, right 结点的右孩子
static Node* create_bstree_node(Type key, Node *parent, Node *left, Node *right) {
    Node *node;

    if((node = (Node *)malloc(sizeof(Node))) == NULL) {
        return NULL;
    }

    node->key    = key;
    node->parent = parent;
    node->left   = parent;
    node->right  = right;

    return node;
}

// 将结点插入到二叉树中: tree 二叉树根结点, z插入的结点 ,返回根结点
static Node* bstree_insert(BSTree tree, Node *z) {
    Node *y = NULL;
    Node *x = tree;

    // 查找z的插入位置
    while( x != NULL) {
        y = x;
        if(z->key < x->key) {
            x = x->left;
        } else {
            x = x->right;
        }
    }

    z->parent = y;
    if(y == NULL) {
        tree = z;
    } else if (z->key < y->key) {
        y->left = z;
    } else {
        y->right = z;
    }

    return tree;
}

// 新建结点key,并将其插入到二叉树中; tree 二叉树根结点, key 插入结点的键值;返回 根结点
Node* insert_bstree(BSTree tree, Type key) {
    Node *node; // 新建结点

    // 如果新建结点失败,则返回.
    if((node = create_bstree_node(key, NULL, NULL, NULL)) == NULL) {
        return tree;
    }

    return bstree_insert(tree, node);
}

// 删除结点node,并返回根结点; tree 二叉树根结点, z 删除的结点; 返回根结点
static Node* bstree_delete(BSTree tree, Node *z) {
    Node *x = NULL;
    Node *y = NULL;

    if((z->left == NULL) || (z->right == NULL)) {
        y = z;
    } else {
        y = bstree_successor(z);
    }

    if(y->left != NULL) {
        x = y->left;
    } else {
        x = y->right;
    }

    if(x != NULL) {
        x->parent = y->parent;
    }

    if(y->parent ==NULL) {
        tree = x;
    } else if(y == y->parent->left) {
        y->parent->left = x;
    } else {
        y->parent->right = x;
    }

    if(y != z) {
        z->key = y->key;
    }

    if(y != NULL) {
        free(y);
    }

    return tree;
}

// 删除结点node,并返回根结点; tree 二叉树根结点, z 删除的结点; 返回根结点
Node* delete_bstree(BSTree tree, Type key) {
    Node *z;

    if((z = bstree_search(tree, key)) != NULL) {
        tree = bstree_delete(tree, z);
    }

    return tree;
}

// 摧毁二叉树
void destory_bstree(BSTree tree) {
    if(tree == NULL) {
        return ;
    }

    if(tree->left != NULL) {
        destory_bstree(tree->left);
    } else if(tree->right != NULL) {
        destory_bstree(tree->right);
    }

    free(tree);
}

/**
 * 打印 二叉树
 * 
 * tree       -- 二叉树的结点
 * key        -- 结点的键值 
 * direction  --  0，表示该结点是根结点;
 *               -1，表示该结点是它的父结点的左孩子;
 *                1，表示该结点是它的父结点的右孩子
 */
void print_bstree(BSTree tree, Type key, int direction) {
    if(tree != NULL) {
        if(direction == 0) {
            printf("%2d is root\n", tree->key);
        } else {
            printf("%2d is %2d's %6s child\n", tree->key, key, direction == 1 ? "right" : "left");
        }

        print_bstree(tree->left, tree->key, -1);
        print_bstree(tree->right, tree->key, 1);
    }
}