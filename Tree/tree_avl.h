#ifndef _TREE_AVL_H
#define _TREE_AVL_H

#include <stddef.h>

#define T_TREE_TYPE(type_name,type)\
    typedef struct t_node_##type_name\
    {\
        type* val;\
        unsigned int val_size;\
        struct t_node_##type_name* parent;\
        struct t_node_##type_name* left;\
        struct t_node_##type_name* right;\
    }node_##type_name;\
    \
    struct t_tree_avl_##type_name\
    {\
        struct t_node_##type_name* root;\
        int t_node_compare(struct t_node_##type_name*,struct t_node_##type_name*);\
    };
    \
    void t_LL(struct t_node_##type_name** t)\
    {\
        if(t != NULL)\
        {\
            struct t_node_##type_name* parent = (*t)->parent;\
            struct t_node_##type_name* tmpPtr = (*t)->left;\
            (*t)->left = tmpPtr->right;\
            tmpPtr->right = *t;\
            if(parent->left == *t)\
            {\
                patent->left = tmpPtr;\
            }\
            else if(parent->right == *t)\
            {\
                parent->right = *t;\
            }\
            *t = tmpPtr;\
        }\
    }\
    \
    void t_RR(struct t_node_##type_name** t)\
    {\
        if(t != NULL)\
        {\
            struct t_node_##type_name* parent = (*t)->parent;\
            struct t_node_##type_name* tmpPtr = (*t)->right;\
            (*t)->right = tmpPtr->left;\
            tmpPtr->left = *t;\
            if(parent->left == *t)\
            {\
                patent->left = tmpPtr;\
            }\
            else if(parent->right == *t)\
            {\
                parent->right = *t;\
            }\
            *t = tmpPtr;\
        }\
    }\
    \
    void t_LR(struct t_node_##type_name** t)\
    {\
        t_RR(&(*t)->left);\
        t_LL(t);\
    }\
    \
    void t_RL(struct t_node_##type_name** t)\
    {\
        t_LL(&(*t)->right);\
        t_RR(t);\
    }\
    \
    int get_node_height(struct t_node_##type_name* t)\
    {\
        int left_height,right_height;\
        if(t != NULL)\
        {\
            left_height = get_node_height(t->left);\
            right_height = get_node_height(t->right);\
            return (left_height > right_height) ? (left_height + 1) : (right_height + 1);\
        }\
        else\
        {\
            return 0;\
        }\
    }\
    \
    void t_insert_node(struct t_tree_avl_##type_name* tree,struct t_node_##type_name** node,struct t_node_##type_name* t)\
    {\
        if(tree->compare((*node),t) < 0)\
        {\
            if((*node)->left != NULL)\
            {\
                t_insert_node(tree,&((*node)->left),t);\
            }\
            else\
            {\
                (*node)->left = t;\
                struct t_node_##type_name* parent = (*node)->parent;\
                if(tree->compare(*node,parent) < 0)\
                {\
                    t_LL(&parent);\
                }\
                else if(tree->compare(*node,parent) > 0)\
                {\
                    t_RL(&parent);\
                }\
            }\
        }\
        else if(tree->compare((*node),t) > 0)\
        {\
            if((*node)->right != NULL)\
            {\
                t_insert_node(tree,&((*node)->right),t);\
            }\
            else\
            {\
                (*node)->right = t;\
                struct t_node_##type_name* parent = (*node)->parent;\
                if(tree->compare(*node,parent) < 0)\
                {\
                    t_LR(&parent);\
                }\
                else if(tree->compare(*node,parent) > 0)\
                {\
                    t_RR(&parent);\
                }\
            }\
        }\
    }\
    \
    struct t_node_##type_name* find_max_node(struct t_node_##type_name* node)\
    {\
        if(node->right != NULL)\
        {\
            return find_max_node(node->right);\
        }\
        else\
        {\
            return node;\
        }\
    }\
    \
    struct t_node_##type_name* find_min_node(struct t_node_##type_name* node)\
    {\
        if(node->left != NULL)\
        {\
            return find_min_node(node->left);\
        }\
        else\
        {\
            return node;\
        }\
    }\
    \
    struct t_node_##type_name* t_delete_node(struct t_tree_avl_##type_name* tree,struct t_node_##type_name** node,struct t_node_##type_name* t)\
    {\
        if(tree->compare(*node,t) < 0)\
        {\
            t_delete_node(tree,&((*node)->right),t);\
        }\
        else if(tree->compare(*node,t) > 0)\
        {\
            t_delete_node(tree,&((*node)->left),t);\
        }\
        else\
        {\
            if((*node)->left == (*node)->right == NULL)\
            {\
                struct t_node_##type_name* parent = (*node)->parent;\
                if(tree->compare(*node,parent) < 0)\
                {\
                    parent->left = NULL;\
                    if(get_node_height(parent) > 1)\
                    {\
                        if(parent->right->right != NULL)\
                        {\
                            t_RR(&parent);\
                        }\
                        else\
                        {\
                            t_RL(&parent);\
                        }\                      
                    }\
                }\
                else if(tree->compare(*node,parent) > 0)\
                {\
                    parent->right = NULL;\
                    if(get_node_height(parent) > 1)\
                    {\
                        if(parent->left->left != NULL)\
                        {\
                            t_LL(&parent);\
                        }\
                        else\
                        {\
                            t_LR(&parent);\
                        }\                     
                    }\
                }\
                return (*node);\
            }\
            else if((*node)->left == NULL && (*node)->right != NULL)\
            {\
            \
            }\
            else if((*node)->right == NULL && (*node)->left != NULL)\
            {\
            \
            }\
        }\
    }\

#define T_TREE_INIT(tree_p,int (*compare)(struct t_node_##type_name*,struct t_node_##type_name*))\
    do{\
        tree_p->root = NULL;\
        tree_p->t_node_compare = compare;\
    }while(0);

#define T_NODE_INIT(node_p,size)\
    do{\
        node_p->val = NULL;\
        node_p->val_size = size;\
        node_p->parent = NULL;\
        node_p->left = NULL;\
        node_p->right = NULL;\
    }while(0);

#endif
