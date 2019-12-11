#include <stddef.h>
#include "stack.h"
#include <stdio.h>

S_STACK_TYPE(int,int)

int main(void)
{
	int num = 1;
	int num2 = 2;
    struct s_node_int node; 
    struct s_node_int node2;
    struct s_stack_int stack; 
    struct s_node_int* node_p = &node;
    struct s_node_int* node_p2 = &node2;
    struct s_stack_int* stack_p = &stack;
    S_INIT_NODE(node_p,sizeof(int));
    S_INIT_NODE(node_p2,sizeof(int));
    node.val = &num;
    node2.val = &num2;
    node.val_size = 4;
    node2.val_size = 4;
    S_INIT_STACK(stack_p);
    S_PUSH(stack_p,node_p);
    S_PUSH(stack_p,node_p2);
    printf("length=%d\n",stack_p->length);
    printf("size=%d\n",stack_p->head->val_size);
//    printf("node_p->val=%d\n",*node_p->val);
    S_POP(stack_p,node_p);
    printf("node_p->val=%d\n",*node_p->val);
    printf("length=%d\n",stack_p->length);
	S_POP(stack_p,node_p);
    printf("node_p->val=%d\n",*node_p->val);
    printf("length=%d\n",stack_p->length);
    return 0;
}
