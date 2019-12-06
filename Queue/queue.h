#ifndef _QUEUE_H
#define _QUEUE_H

#include <stddef.h>

#define Q_QUEUE_TYPE(type_name,type)\
                    struct q_node_##type_name\
                    {\
                       type* val;\
                       unsigned int val_size;\
                       struct q_node_##type_name* next;\
                    };\
                    \
                    struct q_queue_##type_name\
                    {\
                       struct q_node_##type_name* head;\
                       struct q_node_##type_name* tail;\
                       unsigned int length;\
                    };


#define Q_INIT_NODE(node_p,size) \
                        do{\
                            node_p->val = NULL;\
                            node_p->val_size = size;\
                            node_p->next = NULL;\
                        }while(0);


#define Q_INIT_QUEUE(queue_p) \
                        do{\
                            queue_p->head = NULL;\
                            queue_p->tail = NULL;\
                            queue_p->length = 0;\
                        }while(0);


#define Q_PUSH(queue_p,node_p) \
                        do{\
                            if(queue_p->length == 0)\
                            {\
                                queue_p->head = node_p;\
                                queue_p->tail = node_p;\
                            }\
                            else\
                            {\
                                queue_p->tail->next = node_p;\
                                queue_p->tail = node_p;\
                            }\
                            queue_p->length++;\
                        }while(0);


#define Q_POP(queue_p,node_p) \
                        do{\
                            if(queue_p->length != 0)\
                            {\
                                node_p = queue_p->head;\
                                if(queue_p->length != 1)\
                                {\
                                    queue_p->head = queue_p->head->next;\
                                }\
                                else\
                                {\
                                    queue_p->head = NULL;\
                                    queue_p->tail = NULL;\
                                }\
                                queue_p->length--;\
                            }\
                        }while(0);


#endif
