#include<stdio.h>
#include<stdlib.h>

struct tnode{
    int info;
    struct tnode *rc,*lc;
};

typedef struct tnode node;

node *getTnode(){
    return((node*)malloc(sizeof(node)));
}

node* create_tree(node *root,int item){
    node *temp;
    if(root == NULL){
        temp = getTnode();
        temp->info = item;
        temp->lc = NULL;
        temp->rc = NULL;
        return temp;
    }
    else{
        temp = root;
        if(item < temp->info){
            temp->lc = create_tree(temp->lc,item);
        }
        else{
            temp->rc = create_tree(temp->rc,item);
        }
        return root;
    }
}

int Inorder(node *root){
    if(root == NULL){return;}
    printf("%d\t",root->info);
    Inorder(root->lc);
    Inorder(root->rc);
    return;
}

int Preorder(node *root){
    if(root == NULL){return;}
    Preorder(root->lc);
    printf("%d\t",root->info);
    Preorder(root->rc);
    return;
}

int Postorder(node *root){
    if(root == NULL){return;}
    Postorder(root->lc);
    Postorder(root->rc);
    printf("%d\t",root->info);
    return;
}

int main(){
    node *root;
    root = create_tree(root,21);root = create_tree(root,22);
    root = create_tree(root,23);root = create_tree(root,24);
    root = create_tree(root,45);root = create_tree(root,10);
    root = create_tree(root,5);root = create_tree(root,3);
    Inorder(root);printf("\n");
    Postorder(root);printf("\n");
    Preorder(root);
}
