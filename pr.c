#include<stdio.h>
#include<stdlib.h>
struct bt{
    int data;
    struct bt *left;
    struct bt *right;
};

struct bt *insert(struct bt *root,int data){

if(root == NULL){

root = (struct bt *)malloc(sizeof(struct bt));

root->data=data;
root->left=root->right=NULL;

}

else{

if(root->data > data){
root->left=insert(root->left,data);
}
else{
root->right=insert(root->right,data);
}
}
return root;
}

void inorder(struct bt *root){

if(root){
inorder(root->left);
printf("%d ",root->data);
inorder(root->right);
}
}
struct bt *maxi(struct bt *root){

if(root->right == NULL){
    return root;
}
maxi(root->right);
}
struct bt *delete(struct bt *root,int data){
struct bt *temp;

if(root == NULL){
    printf("element is not present");
}
else if(data < root->data){
    root->left = delete(root->left,data);
}
else if(data > root->data){
    root->right = delete(root->right,data);
}
else{
if(root->left && root->right){
    temp=maxi(root->left);
    root->data =temp->data;
    root->left=delete(root->left,root->data);
}
else{
     temp=root;
     if(root->left == NULL){
     root=root->right;
     }
     if(root->right == NULL){
        root=root->left;
     }
     free(temp);
}

}
return root;
}
int main(){

struct bt *root;

root=insert(NULL,4);
root=insert(root,2);
root=insert(root,8);
root=insert(root,5);
root=insert(root,7);
root=insert(root,6);
root=insert(root,9);
inorder(root);
root=delete(root,8);
printf("\n");
inorder(root);
    return 0;
}