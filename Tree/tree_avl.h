#include <stdio.h>
#include <stddef.h>
#include <malloc.h>

#define TREE_INIT(type,type_name)\
    struct AVLNode_##type_name\
    {\
        type value;\
        int balance;\
        struct AVLNode_##type_name* left;\
        struct AVLNode_##type_name* right;\
        struct AVLNode_##type_name* parent;\
    };\
\
    struct AVLTree_##type_name\
    {\
        struct AVLNode_##type_name* root;\
        int (*compare)(type v1,type v2);\
        void (*preorderTree)(struct AVLNode_##type_name*);\
        void (*inorderTree)(struct AVLNode_##type_name*);\
        void (*postorderTree)(struct AVLNode_##type_name*);\
    }Tree_##type_name;\
\
    struct AVLNode_##type_name* select_##type_name(type value,struct AVLNode_##type_name* root)\
    {\
        if(root == NULL)\
        {\
            return NULL;\
        }\
        if(root->value == value)\
        {\
            return root;\
        }\
        if(root->value > value)\
        {\
            if(root->left != NULL)\
            {\
                return select_##type_name(value,root->left);\
            }\
            else\
            {\
                return root;\
            }\
        }\
        if(root->value < value)\
        {\
            if(root->right != NULL)\
            {\
                return select_##type_name(value,root->right);\
            }\
            else\
            {\
                return root;\
            }\
        }\
    }\
\
    void set_balance_##type_name(struct AVLNode_##type_name* a)\
    {\
        if(a != NULL)\
        {\
            a->balance = height_##type_name(a->right) - height_##type_name(a->left);\
        }\
    }\
\
    struct AVLNode_##type_name* turnRight_##type_name(struct AVLNode_##type_name* a)\
    {\
        struct AVLNode_##type_name* b = a->left;\
        if(a->parent != NULL)\
        {\
            if(a->parent->right == a)\
            {\
                a->parent->right = b;\
            }\
            else\
            {\
                a->parent->left = b;\
            }\
        }\
        b->parent = a->parent;\
        a->parent = b;\
        a->left = b->right;\
        if(a->left != NULL)\
        {\
            a->left->parent = a;\
        }\
        b->right = a;\
        set_balance_##type_name(a);\
        set_balance_##type_name(b);\
        return b;\
    }\
\
    struct AVLNode_##type_name* turnLeft_##type_name(struct AVLNode_##type_name* a)\
    {\
        struct AVLNode_##type_name* b = a->right;\
        if(a->parent != NULL)\
        {\
            if(a->parent->right == a)\
            {\
                a->parent->right = b;\
            }\
            else\
            {\
                a->parent->left = b;\
            }\
        }\
        b->parent = a->parent;\
        a->parent = b;\
        a->right = b->left;\
        b->left = a;\
        if(a->right != NULL)\
        {\
            a->right->parent = a;\
        }\
        set_balance_##type_name(a);\
        set_balance_##type_name(b);\
        return b;\
    }\
\
    struct AVLNode_##type_name* turnLeft_then_turnRight_##type_name(struct AVLNode_##type_name* a)\
    {\
        a->left = turnLeft_##type_name(a->left);\
        return turnRight_##type_name(a);\
    }\
\
    struct AVLNode_##type_name* turnRight_then_turnLeft_##type_name(struct AVLNode_##type_name* a)\
    {\
        a->right = turnRight_##type_name(a->right);\
        return turnLeft_##type_name(a);\
    }\
\
    void rebalance_##type_name(struct AVLNode_##type_name* a)\
    {\
        set_balance_##type_name(a);\
        if(a->balance == -2)\
        {\
            if(a->left->balance <= 0)\
            {\
                a = turnRight_##type_name(a);\
            }\
            else\
            {\
                a = turnLeft_then_turnRight_##type_name(a);\
            }\
        }\
        if(a->balance == 2)\
        {\
            if(a->right->balance >= 0)\
            {\
                a = turnLeft_##type_name(a);\
            }\
            else\
            {\
                a = turnRight_then_turnLeft_##type_name(a);\
            }\
        }\
        if(a->parent != NULL)\
        {\
            rebalance_##type_name(a->parent);\
        }\
        else\
        {\
            Tree_##type_name.root = a;\
        }\
    }\
\
    void insert_##type_name(type value,struct AVLNode_##type_name* root)\
    {\
        struct AVLNode_##type_name* node = select_##type_name(value,root);\
        if(node == NULL)\
        {\
            Tree_##type_name.root = (struct AVLNode_##type_name*)malloc(sizeof(struct AVLNode_##type_name));\
            Tree_##type_name.root->value = value;\
            Tree_##type_name.root->left = Tree_##type_name.root->right = NULL;\
            Tree_##type_name.root->parent = NULL;\
            Tree_##type_name.root->balance = 0;\
        }\
        else if(node->value != value)\
        {\
            if(node->value > value)\
            {\
                node->left = (struct AVLNode_##type_name*)malloc(sizeof(struct AVLNode_##type_name));\
                node->left->value = value;\
                node->left->left = node->left->right = NULL;\
                node->left->parent = node;\
                node->left->balance = 0;\
                rebalance_##type_name(node);\
            }\
            else if(node->value < value)\
            {\
                node->right = (struct AVLNode_##type_name*)malloc(sizeof(struct AVLNode_##type_name));\
                node->right->value = value;\
                node->right->left = node->right->right = NULL;\
                node->right->parent = node;\
                node->right->balance = 0;\
                rebalance_##type_name(node);\
            }\
        }\
    }\
\
    void del_node_has1child_or_not_##type_name(struct AVLNode_##type_name* a)\
    {\
        if(a->parent == NULL)\
        {\
            if(a->left != NULL)\
            {\
                Tree_##type_name.root = a->left;\
                a->left->parent = NULL;\
            }\
            else\
            {\
                Tree_##type_name.root = a->parent;\
                a->right->parent = NULL;\
            }\
        }\
        else\
        {\
            if(a->parent->left == a)\
            {\
                if(a->left != NULL)\
                {\
                    a->parent->left = a->left;\
                    a->left->parent = a->parent;\
                }\
                else\
                {\
                    a->parent->left = a->right;\
                    if(a->right != NULL)\
                    {\
                        a->right->parent = a->parent;\
                    }\
                }\
            }\
            else\
            {\
                if(a->left != NULL)\
                {\
                    a->parent->right = a->left;\
                    a->left->parent = a->parent;\
                }\
                else\
                {\
                    a->parent->right = a->right;\
                    if(a->right != NULL)\
                    {\
                        a->right->parent = a->parent;\
                    }\
                }\
            }\
            rebalance_##type_name(a->parent);\
        }\
    }\
\
    struct AVLNode_##type_name* getmin_##type_name(struct AVLNode_##type_name* a)\
    {\
        if(a->left != NULL)\
        {\
            getmin_##type_name(a->left);\
        }\
        else\
        {\
            return a;\
        }\
    }\
\
    void del_node_has2child_##type_name(struct AVLNode_##type_name* a)\
    {\
        struct AVLNode_##type_name* after = getmin_##type_name(a->right);\
        a->value = after->value;\
        del_node_has1child_or_not_##type_name(after);\
    }\
\
    void del_##type_name(type value,struct AVLNode_##type_name* root)\
    {\
        struct AVLNode_##type_name* node = select_##type_name(value,root);\
        if(node->value == value)\
        {\
            if((node->left != NULL) && (node->right))\
            {\
                del_node_has2child_##type_name(node);\
            }\
            else\
            {\
                del_node_has1child_or_not_##type_name(node);\
            }\
        }\
    }\
\
    int height_##type_name(struct AVLNode_##type_name* a)\
    {\
        if(a == NULL)\
        {\
            return 0;\
        }\
        int rightheight = height_##type_name(a->right);\
        int leftheight = height_##type_name(a->left);\
        return rightheight > leftheight ? (rightheight + 1) : (leftheight + 1);\
    }\
/*
\
    void preorderTree_##type_name(struct AVLNode_##type_name* root)\
    {\
        if(root == NULL)\
        {\
            return;\
        }\
        else\
        {\
            printf("%d	",root->value);\
            preorderTree_##type_name(root->left);\
            preorderTree_##type_name(root->right);\
        }\
    }\
\
    void inorderTree_##type_name(struct AVLNode_##type_name* root)\
    {\
        if(root == NULL)\
        {\
            return;\
        }\
        else\
        {\
            inorderTree_##type_name(root->left);\
            printf("%d	",root->value);\
            inorderTree_##type_name(root->right);\
        }\
    }\
\
    void postorderTree_##type_name(struct AVLNode_##type_name* root)\
    {\
        if(root == NULL)\
        {\
            return;\
        }\
        else\
        {\
            postorderTree_##type_name(root->left);\
            postorderTree_##type_name(root->right);\
            printf("%d	",root->value);\
        }\
    }\
\
*/
