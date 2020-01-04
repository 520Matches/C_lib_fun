#include <stdio.h>
#include "tree_avl2.h"


int compare(int v1,int v2)
{
    int ret = 0;
    if(v1 > v2)
    {
        ret = 1;
    }
    else if(v1 < v2)
    {
        ret = -1;
    }
    else
    {
        ret = 0;
    }
    return ret;
}
TREE_INIT(int,int)

    void preorderTree(struct AVLNode_int* root)
    {
        if(root == NULL)
        {
            return;
        }
        else
        {
            printf("%d	",root->value);
            preorderTree(root->left);
            preorderTree(root->right);
        }
    }

    void inorderTree(struct AVLNode_int* root)
    {
        if(root == NULL)
        {
            return;
        }
        else
        {
            inorderTree(root->left);
            printf("%d	",root->value);
            inorderTree(root->right);
        }
    }

    void postorderTree(struct AVLNode_int* root)
    {
        if(root == NULL)
        {
            return;
        }
        else
        {
            postorderTree(root->left);
            postorderTree(root->right);
            printf("%d	",root->value);
        }
    }


void printTree(void)
{
    printf("preorder traversal tree\n");
	Tree_int.preorderTree(Tree_int.root);
	printf("\n");
    printf("inorder traversal tree\n");
	Tree_int.inorderTree(Tree_int.root);
	printf("\n");
    printf("postorder traversal tree\n");
	Tree_int.postorderTree(Tree_int.root);
	printf("\n");
}

int main(void)
{
	int arr[10] = {5,2,6,10,14,11,7,8,18,12};
    struct AVLNode_int root;
    Tree_int.root = &root;
	Tree_int.preorderTree = preorderTree;
	Tree_int.inorderTree = inorderTree;
	Tree_int.postorderTree = postorderTree;
    Tree_int.compare = compare;
	root.balance = 0;
	root.left = NULL;
	root.right = NULL;
	root.parent = NULL;
	root.value = 1;
	for(int i=0;i<10;i++)
	{
		insert_int(arr[i],Tree_int.root);
	}
    printf("root->value=%d\n",Tree_int.root->value);
    printTree();
    del_int(2,Tree_int.root);
    printTree();
    return 0;
}
