#include <stdio.h>
//#include "tree_avl.h"
#include "tree_avl2.h"

TREE_INIT(int,int)

int main(void)
{
	int arr[10] = {5,2,6,10,14,11,7,8,18,12};
    struct AVLNode_int root;
    Tree_int.root = &root;
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
	preorderTree_int(Tree_int.root);
	printf("\n");
	inorderTree_int(Tree_int.root);
	printf("\n");
	postorderTree_int(Tree_int.root);
	printf("\n");
    return 0;
}
