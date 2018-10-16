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

void bfs(BstNode* root) {
	if(root == NULL) return;
	queue<BstNode*> Q;	// Define Queue to store addresses
	Q.push(root);
	while(!Q.empty()) {
		BstNode* current = Q.front();
		cout << current->data << " ";
		if(current->left != NULL) Q.push(current->left);
		if(current->right != NULL) Q.push(current->right);
		Q.pop(); // Removing the element at front
	}
}

void dfs_preorder(BstNode* root) {
	if(root == NULL) return;
	cout << root->data << " ";
	dfs_preorder(root->left);
	dfs_preorder(root->right);
}
void dfs_sort(BstNode* root) {
	if(root == NULL) return;
	dfs_sort(root->left);
	cout << root-> data << " ";
	dfs_sort(root->right);
}

// Method 1 to check if BT is BST (highly inefficient)

bool isSubtreeLesser(BstNode* root, int value) {
	if(root == NULL) return true;
	if(root->data <= value && isSubtreeLesser(root->left, value) && isSubtreeLesser(root->right, value)) return true;
	else return false;
}
bool isSubtreeGreater(BstNode* root, int value) {
	if(root == NULL) return true;
	if(root->data > value && isSubtreeGreater(root->left, value) && isSubtreeGreater(root->right, value)) return true;
	else return false;
}

bool IsBinarySearchTree(BstNode* root) {
	if(root == NULL) return true;
	if(isSubtreeLesser(root->left, root->data) && isSubtreeGreater(root->right, root->data) && IsBinarySearchTree(root->left) && IsBinarySearchTree(root->right)) return true;
	else return false;
}

// Efficient method

bool isBSTUtil(BstNode* root, int minVal, int maxVal) {
	if(root == NULL) return true;
	if(root->data > minVal && root->data < maxVal && isBSTUtil(root->left, minVal, root->data) && isBSTUtil(root->right, root->data, maxVal)) return true;
	else return false;
}

bool efficient_IBST(BstNode* root) {
	return isBSTUtil(root, INT_MIN, INT_MAX);
}

// Deletion of node from BST
BstNode* Delete(BstNode* root, int data) {
	if(root == NULL) return root;
	else if(data < root->data) root->left = Delete(root->left, data);
	else if(data > root->data) root->right = Delete(root->right, data);
	else {
		if(root->left == NULL && root-right == NULL); // No child case
		{
			delete root; //Deallocate memory
			root = NULL;
		}
		else if(root->left == NULL) {
			BstNode* temp = root;
			root = root->right;
			delete temp;
		}
		else if(root->right == NULL) {
			BstNode* temp = root;
			root = root->left;
		}
		else {
			BstNode *temp = FindMinRecursive(root->right);
			root->data = temp->data;
			root->right = Delete(root->right, temp->data);
		}
	}
	return root;
}

// Inorder Successor
struct BstNode* getSuccessor(struct BstNode* root, int data) {
	BstNode* current = Search(root, data);
	if(current == NULL) return NULL;
	if(current->right != NULL);
	//Case 1: Node has right subtree
	if(current->right != NULL) {
		return FindMinRecursive(current->right);
	}
	else { 
		struct BstNode* successor = NULL;
		struct BstNode* ancestor = NULL;
		while(ancestor != current) {
			if(current->data < ancestor->data) {
				successor = ancestor;
				ancestor = ancestor->left;
			}
			else {
				ancestor = ancestor->right;
			}
		}
		return successor;
	}
}

int main() {
	BstNode* root = NULL; // Creating an empty tree
	root = Insert(root, 12);
	root = Insert(root, 5);
	root = Insert(root, 15);
	root = Insert(root, 3);
	root = Insert(root, 7);
	root = Insert(root, 13);
	root = Insert(root, 17);
	root = Insert(root, 1);
	root = Insert(root, 9);
	cout << FindHeight(root) << endl;
	bfs(root);
	cout << endl;
	dfs_preorder(root);
	cout << endl;
	dfs_sort(root);
	cout << endl;
	Delete(root, 5);
	bfs(root);
	cout << endl;
}

