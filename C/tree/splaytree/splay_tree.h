// Splay树头文件
#ifndef _SPLAY_TREE_H_
#define _SPLAY_TREE_H_

typedef int Type;

typedef struct SplayTreeNode {
    Type key; // 关键字
    struct SplayTreeNode *left; // 左孩子
    struct SplayTreeNode *right; // 右孩子
}Node, *SplayTree;

// 前序遍历"伸展树"
void preorder_splaytree(SplayTree tree);

// 中序遍历"伸展树"
void inorder_splaytree(SplayTree tree);

// 后续遍历"伸展树"
void postorder_splaytree(SplayTree tree);

// (递归实现)查找"伸展树tree"中建值为key的结点
Node* splaytree_search(SplayTree tree, Type key);

// (非递归)查找"伸展树tree"中建值为key的结点
Node* iterative_splaytree_search(SplayTree tree, Type key);

// 查找最小结点： 返回tree为根结点的伸展树的最小结点
Node* splaytree_minimum(SplayTree tree);

// 查找最大结点： 返回tree为根结点的伸展树的最大结点
Node* splaytree_maximum();

// 旋转key对应的结点为根结点
Node* splaytree_splay(SplayTree tree, Type key);

// 旋转两次，先旋转key的父结点为根结点，在旋转key对应的结点为跟结点
Node* splaytree_splay_twice(SplayTree tree, Type key);

// 将结点插入到伸展树，并返回根结点
Node* insert_splaytree(SplayTree tree, Type key);

// 删除结点(key为结点的值)，并返回根结点
Node* delete_splaytree(SplayTree tree, Type key);

// 销毁伸展树
void destory_splaytree(SplayTree tree);

// 打印伸展树
void print_splaytree(SplayTree tree, Type key, int direction);

#endif