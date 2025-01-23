
#include <iostream>
using namespace std;

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val):value(val),left(nullptr),right(nullptr) {}
};

TreeNode* buildBalancedTree(int arr[],int start,int end) {
    if (start>end) {
        return nullptr;
    }

    int mid=(start+end) / 2;
    TreeNode* root=new TreeNode(arr[mid]);

    root->left=buildBalancedTree(arr,start,mid-1);
    root->right=buildBalancedTree(arr,mid+1,end);

    return root;
}

void inOrderTraversal(TreeNode* root) {
    if (root==nullptr) {
        return;
    }
    inOrderTraversal(root->left);
    cout<<root->value << " ";
    inOrderTraversal(root->right);
}

int height(TreeNode* root) {
    if (root==nullptr) {
        return 0;
    }
    int leftHeight=height(root->left);
    int rightHeight=height(root->right);
    if (leftHeight>rightHeight) {
        return 1+leftHeight;
    } else {
        return 1+rightHeight;
    }
}

bool isBalanced(TreeNode* root) {
    if (root==nullptr) {
        return true;
    }

    int leftHeight=height(root->left);
    int rightHeight=height(root->right);

    if ((leftHeight-rightHeight>1) || (rightHeight-leftHeight>1)) {
        return false;
    }

    return isBalanced(root->left) && isBalanced(root->right);
}

int main() {
    int nodes[]={10, 20, 30, 40, 50, 60};
    int n=sizeof(nodes)/sizeof(nodes[0]);

    TreeNode* root=buildBalancedTree(nodes, 0,n-1);

    cout<<"In-order Traversal of Balanced Binary Tree: ";
    inOrderTraversal(root);
    cout<<endl;

    cout<< "Height of the Tree: "<< height(root)<<endl;

    if (isBalanced(root)){
        cout<< "The tree is balanced"<<endl;
    } else {
        cout<<"The tree is not balanced"<<endl;
    }

    return 0;
}
