#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "bst.h"

struct node{
    item val;
    struct node *left;
    struct node *right;
};

static item GetItem(BST T);
static BST creaFoglia(item val);
static void setItem(BST T, item val);
static struct node * minValue(struct node* node);

BST newBST(void){
    return NULL;
}

int emptyBST(BST T){
    if(T==NULL){
        return 1;
    }
    else{
        return 0;
    }
}

BST figlioSX(BST T){
    if(!T){
        return NULL;
    }
    else{
        return T->left;
    }
}

BST figlioDX(BST T){
    if(!T){
        return NULL;
    }
    else{
        return T->right;
    }
}

static item GetItem(BST T){
    if (!T){
        return NULLITEM;
    }
    else{
        return T->val;
    }
}

int contains(BST T, item val){
    if(emptyBST(T)){
        return 0;
    }

    if(eq(GetItem(T), val)){
        return 1;
    }

    if(is_min(val, GetItem(T))){
        return contains(figlioSX(T), val);
    }
    else{
        return contains(figlioDX(T), val);
    }
}

BST insert(BST T, item val){
    //COSA SUCCEDE SE VAL è gia presente?

    if(emptyBST(T)){
        return creaFoglia(val);
    }
    
    if(is_min(val, GetItem(T))){
        return insert(figlioSX(T), val);
    }
    else if(is_min(GetItem(T), val)){
        return insert(figlioDX(T), val);
    }
    
    return T;
}

static BST creaFoglia(item val){
    struct node *new;
    new = malloc(sizeof(struct node));
    
    if(!new){
        printf("errore allocazione!\n");
        return NULL;
    }

    setItem(new, val);
    new->left = NULL;
    new->right = NULL;
    return new;
}

static void setItem(BST T, item val){
    T->val = val;
}

BST deleteNode(BST T, item val){
    if(emptyBST(T)){
        return T;
    }

    if(is_min(val, T->val)){
        T->left = deleteNode(T->left, val);
    }
    else if(is_min(T->val, val)){
        T->right = deleteNode(T->right, val);
    }

    else{
        if(T->left == NULL){
            struct node *tmp = T->right;
            free(T);
            return tmp;
        }
        else if(T->right == NULL){
            struct node *tmp = T->left;
            free(T);
            return tmp;
        }
        struct node *tmp = minValue(T->right);
        T->val = tmp->val;
        T->right = deleteNode(T->right, tmp->val);
    }
    return T;
}

static struct node * minValue(struct node* node){
    struct node * current = node;
    while(current->left != NULL){
        current = current->left;
    }
    return current;
}