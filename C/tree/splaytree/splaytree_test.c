/**
 * @file splaytree_test.c
 * @author huanglin 
 * @brief 伸展树测试程序
 * @version 0.1
 * @date 2022-01-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>
#include "splay_tree.h"

static int arr[] = {10, 50, 40, 30, 20, 60};
#define TBL_SIZE(a) ( (sizeof(a)) / (sizeof(a[0])) );

void main() {

    int i, len;
    SplayTree root = NULL;

    len = TBL_SIZE(arr);
    for(i = 0; i <len; i++) {
        printf("%d ", arr[i]);
        root = insert_splaytree(root, arr[i]);
    }

    printf("\n前序遍历=> ");
    preorder_splaytree(root);
    printf("\n中序遍历=> ");
    inorder_splaytree(root);
    printf("\n后序遍历=> ");
    postorder_splaytree(root);
    printf("\n");

    printf("最小值: %d\n", splaytree_minimum(root)->key);
    printf("最大值: %d\n", splaytree_maximum(root)->key);
    printf("树的详细信息=> \n");
    print_splaytree(root, root->key, 0);

    i = 30;
    printf("\n旋转结点(%d)为根结点\n", i);
    root = splaytree_splay(root, i);
    printf("\n旋转后树详细信息=> \n");
    print_splaytree(root, root->key, 0);

    // 摧毁伸展树
    destory_splaytree(root);
}
