#include<iostream>
using namespace std;

class binary_search_tree{
    private:
        class node{
            public:
                int data;
                node* right;
                node* left;

                node(int data){
                    this->data=data;
                    right=left=NULL;
                }
        };
        node* root=NULL;
    
    public:
        void add_element(int element){
            node* n=new node(element);
            
            if(root==NULL){
               root=n;
               return;
            }

            node* temp=root;
            while(temp != n){   
                if(element>temp->data ){
                    if(temp->right==NULL)temp->right=n;
                    temp=temp->right;
                }

                else{
                    if(temp->left==NULL) temp->left= n;
                    temp=temp->left;
                }
            }

        }
        bool search(int key){
            node* temp= root;
            
            while(temp != NULL){
                if(key==(temp->data))return 1;
                else if(key>(temp->data)) temp=temp->right;
                else temp=temp->left;
            }
            return 0;
        }
};


int main(){
    binary_search_tree BST;
    BST.add_element(15);
    BST.add_element(10);
    BST.add_element(20);
    BST.add_element(8);
    BST.add_element(12);
    BST.add_element(17);
    BST.add_element(25);
    BST.add_element(2);

    cout<<BST.search(2);
    return 0;
}