#include <iostream>
#include <queue>

using namespace std;

struct BstNode {
	int data;
	BstNode* left;
	BstNode* right;
};

BstNode* GetNewNode(int data) {
	BstNode* newNode = new BstNode();
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode; 
}

BstNode* Insert(BstNode* root, int data) {
	if(root == NULL) {
		root = GetNewNode(data);
	}
	else if(data <= root->data){
		root->left = Insert(root->left, data);
	}
	else {
		root->right = Insert(root->right, data);
	}
	return root;
}

bool Search(BstNode* root, int data){
	if(root == NULL) return false;
	if(root->data == data) return true;
	else if(data <= root->data) return Search(root->left, data);
	else return Search(root->right, data);
}

int FindMinIterative(BstNode* root) {
	if(root == NULL) {
		cout << "Error: Tree is empty\n";
		return -1;
	}
	while(root->left != NULL) {
		root = root->left;
	}
	return root->data;
}

int FindMinRecursive(BstNode* root) {
	if(root == NULL) {
		cout << "Error: Tree is empty\n";
		return -1;
	}
	else if(root->left == NULL){
		return root->data;
	}
	return FindMinRecursive(root->left);
}
int max(int x, int y) {
	if(x > y) return x;
	else return y;
}
int FindHeight(BstNode* root) {
	if(root == NULL) {
		return -1;
	}
	return max(FindHeight(root->left), FindHeight(root->right))+1;
}

void LevelOrder(BstNode* root) {
	if(root == NULL) return;
	queue<BstNode*> Q;	// Define Queue to store addresses
	
}
int main() {
	BstNode* root = NULL; // Creating an empty tree
	root = Insert(root, 15);
	root = Insert(root, 10);
	root = Insert(root, 20);
	root = Insert(root, 25);
	root = Insert(root, 8);
	root = Insert(root, 12);
	cout << FindHeight(root) << endl;
}

