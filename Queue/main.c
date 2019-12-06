#include <stddef.h>
#include "queue.h"
#include <stdio.h>

Q_QUEUE_TYPE(int,int)

int main(void)
{
	int num = 1;
	int num2 = 2;
    struct q_node_int node; 
    struct q_node_int node2;
    struct q_queue_int queue; 
    struct q_node_int* node_p = &node;
    struct q_node_int* node_p2 = &node2;
    struct q_queue_int* queue_p = &queue;
    Q_INIT_NODE(node_p,sizeof(int));
    Q_INIT_NODE(node_p2,sizeof(int));
    node.val = &num;
    node2.val = &num2;
    node.val_size = 4;
    node2.val_size = 4;
    Q_INIT_QUEUE(queue_p);
    Q_PUSH(queue_p,node_p);
    Q_PUSH(queue_p,node_p2);
    printf("length=%d\n",queue_p->length);
    printf("size=%d\n",queue_p->head->val_size);
    printf("node_p->val=%d\n",*node_p->val);
    Q_POP(queue_p,node_p);
    printf("node_p->val=%d\n",*node_p->val);
    printf("length=%d\n",queue_p->length);
	Q_POP(queue_p,node_p);
    printf("node_p->val=%d\n",*node_p->val);
    printf("length=%d\n",queue_p->length);
    return 0;
}
