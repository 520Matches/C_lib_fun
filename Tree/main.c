#include <stdio.h>
//#include "tree_avl.h"
#include "tree_avl2.h"

/*
T_TREE_TYPE(int,int)
int compare(struct t_node_int* node1,struct t_node_int* node2)
{
	int num = node1->val - node2->val;
	if(num > 0)
	{
		return 1;
	}
	else if(num < 0)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

int main(void)
{
	struct t_tree_avl_int tree;
	struct t_tree_avl_int* tree_p = &tree;
	struct t_node_int node1;
	struct t_node_int* node1_p = &node1;
	T_TREE_INIT(tree_p,compare);
	T_NODE_INIT(node1_p,sizeof(int))
	tree.root = node1_p;	
	return 0;
}
*/

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
//		printf("%d\n",arr[i]);
		insert_int(arr[i],Tree_int.root);
	}
	preorderTree_int(&root);
	printf("\n");
	inorderTree_int(&root);
	printf("\n");
	postorderTree_int(&root);
	printf("\n");
    return 0;
}
