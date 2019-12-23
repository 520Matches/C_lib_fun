#include <stdio.h>
#include "tree_avl.h"

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

T_TREE_TYPE(int,int)

int main(void)
{
	struct t_tree_avl_int tree;
	struct t_node_int node1;
	T_TREE_INIT(&tree,compare);
	T_NODE_INIT(&node1,sizeof(int))
	tree.root = &node1;	
	return 0;
}
