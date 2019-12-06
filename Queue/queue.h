#ifndef _QUEUE_H
#define _QUEUE_H

#include <stddef.h>

#define Q_QUEUE_TYPE(type_name,type)\
                    struct q_node_##type_name\
                    {\
                       type* val;\
                       unsigned int val_size;\
                       struct q_node_s* next;\
                    };\
                    \
                    struct q_queue_##type_name\
                    {\
                       struct q_node_##type_name* head;\
                       struct q_node_##type_name* tail;\
                       unsigned int length;\
                    };


#define Q_INIT_NODE(node,size) \
                        do{\
                            node->val = NULL;\
                            node->val_size = size;\
                            node->next = NULL;\
                        }while(0);


#define Q_INIT_QUEUE(queue) \
                        do{\
                            queue->head = NULL;\
                            queue->tail = NULL;\
                            queue->length = 0;\
                        }while(0);


#define Q_PUSH(queue,node) \
                        do{\
                            if(queue->length == 0)\
                            {\
                                queue->head = node;\
                                queue->tail = node;\
                            }\
                            else\
                            {\
                                queue->tail->next = node;\
                                queue->tail = node;\
                            }\
                            queue->length++;\
                        }while(0);


#define Q_POP(queue,node) \
                        do{\
                            if(queue->length != 0)\
                            {\
                                node = queue->head;\ 
                                if(queue->length != 1)\
                                {\
                                    queue->head = queue->head->next;\
                                }\
                                else\
                                {\
                                    queue->head = NULL;\
                                    queue->tail = NULL;\
                                }\
                                queue->length--;\
                            }\
                        }while(0);


#endif
