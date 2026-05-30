#include<iostream>
#include<queue>
using namespace std;
typedef  int DataType;
typedef struct Node
{
	struct Node* leftChild;
	struct Node* rightChild;
	DataType data;
}TreeNode;
class BinaryTree
{
private:
	TreeNode* root;
	TreeNode* recurGenTree(char* s, int& i);
	TreeNode* recurGenTree(char* sPreorder, char* sInorder, int istart, int iend, int& idx);
	void doPreorder(TreeNode* root);
	void doPostorder(TreeNode* root);
	void doInorder(TreeNode* root);
public:
	BinaryTree():root(nullptr){}
	TreeNode* buildTree(char* s);
	TreeNode* buildTree(char* sPreorder, char* sInorder);
	void preOrder();//前序遍历
	void postOrder();//后序遍历
	void inOrder();//中序遍历
	void lvOrder(TreeNode*root);//层序遍历
	void doThreadingPre(TreeNode* root);
	void doTraversePreThreadTree(TreeNode* root);
	int treeHeight(TreeNode* root);
	bool isBalanceTree(TreeNode* root);


};
void BinaryTree::preOrder()
{
	doPreorder(this->root);
}
void BinaryTree::doPreorder(TreeNode*root)
{
	if (root == NULL)return;
	cout << root->data<<" ";
	doPreorder(root->leftChild);
	doPreorder(root->rightChild);
}
void BinaryTree::inOrder()
{
	doInorder(this->root);
}
void BinaryTree::doInorder(TreeNode* root)
{
	if (root == NULL)return;
	doInorder(root->leftChild);
	cout << root->data<<" ";
	doInorder(root->rightChild);
}
void BinaryTree::postOrder()
{
	doPostorder(this->root);
}
void BinaryTree::doPostorder(TreeNode* root)
{
	if (root == NULL)return;
	doPostorder(root->leftChild);
	doPostorder(root->rightChild);
	cout << root->data << "";
}
void BinaryTree::lvOrder(TreeNode* root)
{
	if (root = nullptr)return;
	queue<TreeNode*>que;
	que.push(root);
	while (!que.empty())
	{
		TreeNode* node = que.front();
		que.pop();
		if (node == nullptr)continue;
		cout << node->data<<"";
		que.push(node->leftChild);
		que.push(node->rightChild);
	}
}
int main()
{
	return 0;
}