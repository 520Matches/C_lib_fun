#ifndef _STACK_H
#define _STACK_H

#include <stddef.h>
					
#define S_STACK_TYPE(type_name,type)\
                    struct s_node_##type_name\
                    {\
                       type* val;\
                       unsigned int val_size;\
                       struct s_node_##type_name* next;\
                    };\
                    \
                    struct s_stack_##type_name\
                    {\
                       struct s_node_##type_name* head;\
                       struct s_node_##type_name* tail;\
                       unsigned int length;\
                    };					


#define S_INIT_NODE(node_p,size) \
                        do{\
                            node_p->val = NULL;\
                            node_p->val_size = size;\
                            node_p->next = NULL;\
                        }while(0);


#define S_INIT_STACK(stack_p) \
                        do{\
                            stack_p->head = NULL;\
                            stack_p->tail = NULL;\
                            stack_p->length = 0;\
                        }while(0);


#define S_PUSH(stack_p,node_p) \
                        do{\
                            if(stack_p->length == 0)\
                            {\
                                stack_p->head = node_p;\
                                stack_p->tail = node_p;\
                            }\
                            else\
                            {\
								node_p->next = stack_p->head;\
                                stack_p->head = node_p;\
                            }\
                            stack_p->length++;\
                        }while(0);


#define S_POP(stack_p,node_p) \
                        do{\
                            if(stack_p->length != 0)\
                            {\
                                node_p = stack_p->head;\
                                if(stack_p->length != 1)\
                                {\
                                    stack_p->head = stack_p->head->next;\
                                }\
                                else\
                                {\
                                    stack_p->head = NULL;\
                                    stack_p->tail = NULL;\
                                }\
                                stack_p->length--;\
                            }\
                        }while(0);


#endif
