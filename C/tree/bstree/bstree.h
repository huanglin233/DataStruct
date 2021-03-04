// 二叉查找数据头文件
#ifndef _BINARY_SEARCH_TREE_H_
#define _BINARY_SEARCH_TREE_H_

typedef int Type;
typedef struct BSTreeNode {
    Type   key;
    struct BSTreeNode *left;
    struct BSTreeNode *right;
    struct BSTreeNode *parent;
}Node, *BSTree;

// 前序遍历二叉树
void preorder_bstree(BSTree tree);
// 中序遍历二叉树
void inorder_bstree(BSTree tree);
// 后序遍历二叉树
void postorder_bstree(BSTree tree);

//(递归实现)查找二叉树x中的键为key的结点
Node* bstree_search(BSTree x, Type Key);
//(非递归实现)查找二叉树x中的键为key的结点
Node* iterative_bstree_search(BSTree x, Type key);

// 查找最小结点:返回tree为根节点的二叉树的最小结点
Node* bstree_minimum(BSTree tree);
// 查找最大结点:返回tree为根节点的二叉树的最大结点
Node* bstree_maximum(BSTree tree);


//找结点x的后继结点,即，查找"二叉树中数据值大于该结点"的"最小结点"。
Node* bstree_successor(Node *x);
// 找结点x的前驱结点,即，查找"二叉树中数据值小于该结点"的"最大结点"。
Node* bstree_predecessor(Node *x);

// 将结点插入到二叉树中(key为结点值),并返回根结点
Node* insert_bstree(BSTree tree, Type key);
// 删除结点(key为结点的值),并返回根结点
Node* delete_bstree(BSTree tree, Type key);
// 摧毁二叉树
void destory_bstree(BSTree tree);

// 打印二叉树
void print_bstree(BSTree tree, Type key, int direction);

#endif