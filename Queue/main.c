#include <stddef.h>
#include "queue.h"
#include <stdio.h>

//Q_NODE(int);
//Q_QUEUE(struct q_node_int,int);
Q_QUEUE_TYPE(int,int)

int main(void)
{
    struct q_node_int node; 
    struct q_queue_int queue; 
    struct q_node_int* node_p = &node;
    struct q_queue_int* queue_p = &queue;
    Q_INIT_NODE(node_p,sizeof(int));
    Q_INIT_QUEUE(queue_p);
    Q_PUSH(queue_p,node_p);
    printf("length=%d\n",queue_p->length);
    printf("size=%d\n",queue_p->head->val_size);
    Q_POP(queue_p,node_p);
    printf("length=%d\n",queue_p->length);
    return 0;
}
