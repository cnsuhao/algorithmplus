#ifndef ___BINARYTREE_H____ 
#define ___BINARYTREE_H____


#include <stack>
using namespace std;

// 二叉树节点定义
template <class elemType>
struct nodeType {
	elemType info;
	nodeType<elemType> *llink;
	nodeType<elemType> *rlink;
};

template <class elemType>
class binaryTreeType {
public:
	const binaryTreeType<type>& operator=(const binaryTreeType<type>&);

	bool isEmpty();

	void inorderTraversal();
	void preorderTraversal();
	void postorderTraversal();

	void nonRecursiveInTraversal();
	void nonRecursivePreTraversal();
	void nonRecursivePostTraversal();

	int treeHeight();
	int treeNodeCount();
	int treeLeavesCount();

	void destroyTree();

	binaryTreeType(const binaryTreeType<elemType>& otherTree);
	binaryTreeType();

	~binaryTreeType();

protected:
	const nodeType<elemType> * const root;

private:
	void copyTree(nodeType<elemType>* &copiedTreeRoot,nodeType<elemType>* otherTreeRoot);

	void destroy(nodeType<elemType>* &p);

	void inorder(nodeType<elemType> *p);
	void preorder(nodeType<elemType> *p);
	void postorder(nodeType<elemType> *p);

	int height(nodeType<elemType> *p);
	int nodeCount(nodeType<elemType> *p);
	int leavesCount(nodeType<elemType> *p);
};

template<class elemType>
bool binaryTreeType<elemType>::isEmpty(){
	return (root == NULL);
}

template<class elemType>
binaryTreeType<elemType>::binaryTreeType(){
	root = NULL;
}

template<class elemType>
void binaryTreeType<elemType>::inorderTraversal() {
	inorder(root);
}

template<class elemType>
void binaryTreeType<elemType>::preorderTraversal() {
	preorder(root);
}

template<class elemType>
void binaryTreeType<elemType>::postorderTraversal() {
	postorder(root);
}

template<class elemType>
int binaryTreeType<elemType>::treeHeight() {
	return height(root);
}

template<class elemType>
int binaryTreeType<elemType>::treeNodeCount() {
	return nodeCount(root);
}

template<class elemType>
int binaryTreeType<elemType>::treeLeavesCount() {
	return leavesCount(root);
}


template<class elemType>
void binaryTreeType<elemType>::inorder(nodeType<elemType> *p) {
	if (p != NULL)
	{
		inorder(p->llink);
		cout << p->info << " ";
		inorder(p->rlink);
	}
}

template<class elemType>
void binaryTreeType<elemType>::preorder(nodeType<elemType> *p) {
	if (p != NULL)
	{
		cout << p->info << " ";
		preorder(p->llink);
		preorder(p->rlink);
	}
}

template<class elemType>
void binaryTreeType<elemType>::postorder(nodeType<elemType> *p) {
	if (p != NULL)
	{
		postorder(p->llink);
		postorder(p->rlink);
		cout << p->info << " ";
	}
}

template<class elemType>
void binaryTreeType<elemType>::nonRecursiveInTraversal() {
	stack<nodeType<elemType> *> tstack;
	nodeType<elemType> *current;
	current = root;

	while((current != NULL) || (!tstack.empty())) {
		if (current != NULL)
		{
			tstack.push(current);
			current = current->llink;
		} else {
			tstack.pop(current);
			cout << current->info << " ";
			current = current->rlink;
		}
	}

	cout << endl;
}

template<class elemType>
int binaryTreeType<elemType>::height(nodeType<elemType> *p) {
	if (p == NULL)
	{
		return 0;
	} else {
		return 1 + std::max(height(p->llink),height(p->rlink));
	}
}

template<class elemType>
int binaryTreeType<elemType>::nodeCount(nodeType<elemType> *p) {
	int ic = 0;
	if (p == NULL)
	{
		return ic;
	} else {
		// todo
	}

	return ic;
}

template<class elemType>
int binaryTreeType<elemType>::leavesCount(nodeType<elemType> *p) {
	int ic = 0;
	if (p == NULL)
	{
		return ic;
	} else {
		// todo
	} 

	return ic;
}

template<class elemType>
void binaryTreeType<elemType>::copyTree(nodeType<elemType>* &copiedTreeRoot,nodeType<elemType>* otherTreeRoot) {
	if (otherTreeRoot == NULL)
	{
		copiedTreeRoot = NULL;
	} else {
		copiedTreeRoot = new nodeType<elemType>;
		copiedTreeRoot->info = otherTreeRoot->info;
		copyTree(copiedTreeRoot->llink,otherTreeRoot->llink);
		copyTree(copiedTreeRoot->rlink,otherTreeRoot->rlink);
	}
}

template<class elemType>
void binaryTreeType<elemType>::destroy(nodeType<elemType>* &p) {
	if (p != NULL)
	{
		destroy(p->llink);
		destroy(p->rlink);
		delete p;
		p = NULL;
	}
}

template<class elemType>
void binaryTreeType<elemType>::destroyTree() {
	destroy(root);
}

template<class elemType>
void binaryTreeType<elemType>::binaryTreeType(const binaryTreeType<elemType>& otherTree) {
	if (otherTree.root == NULL)
	{
		root = NULL;
	} else {
		copyTree(root,otherTree.root);
	}
}

template<class elemType>
void binaryTreeType<elemType>::~binaryTreeType() {
	destroy(root);
}

template<class elemType>
const binaryTreeType<type>& binaryTreeType<elemType>::operator=(const binaryTreeType<type>& otherTree) {
	if (this != &otherTree)
	{
		if (root != NULL)
		{
			destroy(root);
		}

		if (otherTree.root == NULL)
		{
			root == NULL;
		} else {
			copyTree(root,otherTree.root);
		}
	}

	return *this;
}

#endif // end of ___BINARYTREE_H____