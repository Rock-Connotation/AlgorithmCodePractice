//
//  main.c
//  构造一颗二叉树
//
//  Created by 石子涵 on 2022/2/8.
//

#include <stdio.h>
#include <stdlib.h>
typedef struct{
    int Value;  //数据域
    struct TreeNode *left;
    struct TreeNode *right;
    
} TreeNode;

typedef struct tree {
  struct tree   *lchild;    //左孩子节点
  struct tree *rchild;    //右孩子节点
  char data;//数据域
}Tree,*Bitree;

//先序遍历一棵树
TreeNode *preCreatTree(int *ary, int arySize);
int main(int argc, const char * argv[]) {
    // insert code here...
//    printf("Hello, World!\n");
    TreeNode *head = (TreeNode *)malloc(sizeof(TreeNode));
    head->left = (TreeNode *)malloc(sizeof(TreeNode));
    head->Value = 10;
    
//   Bitree T = (Bitree)malloc(sizeof(Tree)); //分配存贮空间
//    T->data = 'a';
    
    return 0;
}
//TreeNode *preCreatTree(TreeNode *head){
//
//}
