#include <iostream>
 using namespace std;
 struct Node {
int data;
Node* left;
Node* right;
 
Node(int data) {
this->data=data;
left=nullptr;
right=nullptr;
}
};
 
Node* newNode(int data) {
return new Node(data);
}
 
Node* insertIterative(Node* root, int data) {
Node* new_node=newNode(data);
 
if (root==nullptr) {
return new_node;
}
 
Node* current=root;
Node* parent=nullptr;
 
while (current!=nullptr) {
parent=current;
if (data<current->data) {
current=current->left;
} else if (data>current->data) {
current=current->right;
} else {
return root;
}
}
if (data<parent->data) {
parent->left=new_node;
} else {
parent->right=new_node;
}
 
return root;
}
 
Node* inorderSuccessor(Node* root) {
Node* current = root;
while (current && current->left != nullptr) {
current=current->left;
}
return current;
}
 
Node* deleteNodeIterative(Node* root, int data) {
if (root == nullptr) {
return root;
}
 
Node* current = root;
Node* parent = nullptr;
 
while (current != nullptr && current->data != data) {
parent = current;
if (data < current->data) {
current = current->left;
} else {
current = current->right;
}
}
 
if (current == nullptr) {
return root;
}
 
if (current->left == nullptr && current->right == nullptr) {
if (current == root) {
return nullptr;
}
if (parent->left == current) {
parent->left = nullptr;
} else {
parent->right = nullptr;
}
}
 
else if (current->left == nullptr) {
if (current == root) {
return current->right;
}
if (parent->left == current) {
parent->left = current->right;
} else {
parent->right = current->right;
}
}
 
else if (current->right == nullptr) {
if (current == root) {
return current->left;
}
if (parent->left == current) {
parent->left = current->left;
} else {
parent->right = current->left;
}
}
 
else {
Node* successor = inorderSuccessor(current->right);
current->data = successor->data;
current->right = deleteNodeIterative(current->right, successor->data);
}
 
return root;
}
 
int height(Node* node) {
if (node == nullptr) {
return 0;
}
return 1 + max(height(node->left), height(node->right));
}
 
void inorder(Node* root) {
if (root != nullptr) {
inorder(root->left);
cout << root->data << " ";
inorder(root->right);
}
}
 
int main() {
Node* root = nullptr;
 
root=insertIterative(root, 50);
root=insertIterative(root, 30);
root=insertIterative(root, 20);
root=insertIterative(root, 40);
root=insertIterative(root, 70);
root=insertIterative(root, 60);
root=insertIterative(root, 80);
 
cout<<"Inorder Traversal: ";
inorder(root);
cout<< endl;
 
root=deleteNodeIterative(root, 30);
 
cout<< "Inorder Traversal after deletion: ";
inorder(root);
cout<<endl;
 
int leftHeight=height(root->left);
int rightHeight=height(root->right);
int treeHeight=abs(leftHeight - rightHeight);
cout<< "Height of the BST: " <<treeHeight<<endl;
 
return 0;
}