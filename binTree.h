/*
CS 302 Assignment 5

Name: Keith Beauvais, 5005338658, CS 302 Assignment 5
*/
#include <iostream>
#include <vector>

class binTree{
    public:
        struct binTreeNode{
            bool apple;
            binTreeNode * left;
            binTreeNode * right;
        };

    binTree();
    binTree(std::vector<bool>);
    ~binTree();
    int minTime();

    private:

    void destroyTree(binTreeNode*);
    void buildTree(binTreeNode * r, std::vector<bool>,int);
    int minTime(binTreeNode * r, int);
    binTreeNode * root; 
    
};
/* 
binTree() - default constructor that sets the root with NULL

return value - n/a
*/
binTree::binTree(){
    root = NULL;
}
/* 
binTree(std::vector<bool> apples) - constructor that takes in a vector of apples, each
element is true or false denoting a red or non red apple,

return value - n/a
*/
binTree::binTree(std::vector<bool> apples){

    root = new binTreeNode;
    root -> apple = apples[0];
    root->left = NULL;
    root->right = NULL;
    buildTree(root, apples, 0);


}
/* 
~binTree() - deallocates the binary tree, this would call destroyTree(root)

return value - n/a
*/
binTree::~binTree(){
    destroyTree(root);
}
/* 
destroyTree(binTreeNode * r) - function that deallocates a binary tree rooted at
node r, deallocates the left subtree, then the right subtree, then deallocates r

return value - n/a
*/
void binTree::destroyTree(binTreeNode* r){

    if(r==NULL){
        return;
    }

    destroyTree(r->left);
    destroyTree(r->right);

    delete r;

}
/* 
buildTree(binTreeNode * r, std::vector<bool> apples, int i) - this function builds the tree from the array given, this 
function computes the left index and right index given index i, and then builds a left and right child, 
assign the value from apples vector to the left and right child node, and the recursively build the left and right
side.

return value - n/a
*/
void binTree::buildTree(binTreeNode * r, std::vector<bool> apples, int i){
    //base case
    if(2*i+1 >= apples.size()){
        return;
    }
    // creates new node, sets in value from 2*i+1, sets left and right to NULL and recursively calls the left
    else{
        r -> left = new binTreeNode;
        r ->left-> apple = apples[2*i+1];
        r->left->right = NULL;
        r->left->left = NULL;
        buildTree(r->left, apples, 2*i+1);
    }
    //base case
    if(2*i+2 >= apples.size()){
        return;
    }
    // creates new node, sets in value from 2*i+2, sets left and right to NULL and recursively calls the right
    else{
        r -> right = new binTreeNode;
        r ->right-> apple = apples[2*i+2];
        r->right->right = NULL;
        r->right->left = NULL;
        buildTree(r->right, apples, 2*i+2);
    }

    return;

}
/* 
buildTree(binTreeNode * r, std::vector<bool> apples, int i) - minTime() - function that simply contains return minTime(root, 0)

return value - n/a
*/
int binTree::minTime(){
    return minTime(root,0);

}
/* 
buildTree(binTreeNode * r, std::vector<bool> apples, int i) - minTime() - minTime(binTreeNode * r, int time) - function 
that counts the minimal amount of moves needed to retrieve all the red apples in the binary tree staring from the root. 
Every forward move to a child causes the time to increment by 1, every movement back to its parent also increments
time by 1,  if a path leads to a leaf where no red apples where found along the way, then you do not want 
to maintain those time counts.

return value - int for the current count
*/
int binTree::minTime(binTreeNode * r, int time){
    //base case
    if(r == NULL){
        return 0;
    }

    // increasing time counter on the way down. 
    if(r==root){
        time = 0;
    }
    else{
        time++;
    }
    
    //left side
    int left = minTime(r->left, time);

    //transferring time counter inbetween left and right
    if(r==root){
        time = left;
    }
    
    if(left > 0){
        time=left;
    }
    
    //right side
    int right = minTime(r->right, time);

    // case for if node IS pointing to a NULL  
    if(r->left == NULL && r->right == NULL){
        if(r->apple == 0){
            return 0;
        }
        if(r->apple == 1){
            return time+1;
        }
    }
    
  
    // case for if node is not pointing to a NULL  
    if(r->right!=NULL && r->left!=NULL){
        if(left==0 && right ==0){
            if(r->apple ==1){
                return time+1;
            }
            else{
                return 0;
            }
            
        }
        else{
            if(right > left){
                if(r==root){
                    return right;
                }
                else{
                    time = right;
                    return time+1;
                }
                
            }
            else{
                if(r==root){
                    return time;
                }
                return time+1;
            }
            
        }
    }
    
    //if left is NULL and right is not NULL
    if(r->right!=NULL && r->left==NULL){
        if(left==0 && right ==0){
            if(r->apple ==1){
                return time+1;
            }
            else{
                return 0;
            }
            
        }
        else{
            if(right > left){
                if(r==root){
                    return right;
                }
                else{
                    time = right;
                    return time+1;
                }
                
            }
            else{
                return time+1;
            }
            
        }
    }
     //if left is not NULL and right is NULL
    if(r->right==NULL && r->left!=NULL){
        if(left==0 && right ==0){
            if(r->apple ==1){
                return time+1;
            }
            else{
                return 0;
            }
            
        }
        else{
            if(right > left){
                if(r==root){
                    return right;
                }
                else{
                    time = right;
                    return time+1;
                }
                
            }
            else{
                return time+1;
            }
            
        }
    }
   
    return time;

}
