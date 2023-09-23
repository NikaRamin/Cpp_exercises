#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* right;
    Node* left;
};

Node* createNode(int data){
    Node* newNode = new Node();
    newNode -> data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void preOrder(Node* root){
    if(!root) return;
    cout << root->data <<endl;
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node* root){
    if(!root) return;
    inOrder(root->left);
    cout << root->data <<endl;
    inOrder(root->right);
}

void postOrder(Node* root){
    if(!root) return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << endl;
}

int main(){
    int choice;

    //Level 1
    Node* root = createNode(30);
    //Level 2
    root->left = createNode(6);
    root->right = createNode(1);
    //Level 3
    root->right->left = createNode(50);
    root->left->right = createNode(3);
    root->left->left = createNode(4);
    //Level 4
    root->right->left->left = createNode(36);
    root->left->left->left = createNode(100);

    while(1){
        cout<<"1.Pre order algorithm\n2.In order algorithm\n3.Post order algorithm \n4.Exit\n";
        cin >> choice;
        if(choice == 4){
            cout<<"Thanks for using this program."<<endl;
            break;
        }
        switch(choice){
            case 1: preOrder(root); break;
            case 2: inOrder(root); break;
            case 3: postOrder(root); break;
            default: cout<<"Enter a valid choice:"<<endl;
        }
    }

    return 0;
}