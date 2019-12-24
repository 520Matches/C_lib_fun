#include <stdio.h>
#include "tree_avl.h"

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
