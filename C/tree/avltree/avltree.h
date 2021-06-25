// AVL树头文件
#ifndef _AVL_TREE_H_
#define _AVL_TREE_H_

typedef int TYPE;

typedef struct AVLTreeNode {
    TYPE key;
    int height;
    struct AVLTreeNode *left;
    struct AVLTreeNode *right;
}Node, *AVLTree;

// 获取AVL树的高度
int avltree_height(AVLTree tree);

// 前序遍历AVL树
void preorder_avltree(AVLTree tree);

// 中序遍历AVL树
void inorder_avltree(AVLTree tree);

// 后续遍历AVL树
void postorder_avltree(AVLTree tree);

// 打印AVL树
void print_avltree(AVLTree tree, TYPE key, int direction);

// (递归实现)查找AVL树中键为key的值
Node* avltree_search(AVLTree tree, TYPE key);

// (非递归实现)查找AVL树中为key的值
Node* iterative_avltree_search(AVLTree tree, TYPE key);

// 查找最小结点：返回tree为根结点的avl树的最小结点
Node* avltree_minimum(AVLTree tree);

// 查找最大结点：返回tree为跟节点的avl树的最大节点
Node* avltree_maximum(AVLTree tree);

// 将结点插入到AVL树中，返回根结点
Node* avltree_insert(AVLTree tree, TYPE key);

// 删除key值结点，返回根结点
Node* avltree_delete(AVLTree tree, TYPE key);

// 摧毁AVL树
void destroy_avltree(AVLTree tree);

#endif