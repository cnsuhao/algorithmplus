#ifndef ___BINARYTREE_H____ 
#define ___BINARYTREE_H____


#include <stack>
#include <queue>
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
	void inorderTraversal(void (*visit)(elemType&))

	void preorderTraversal();
	void preorderTraversal(void (*visit)(elemType&));

	void postorderTraversal();

	void deeporderTraversal();

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
	void inorder(nodeType<elemType> *p,void (*visit)(elemType&));
	void preorder(nodeType<elemType> *p);
	void preorder(nodeType<elemType> *p, void (*visit)(elemType&))
	void postorder(nodeType<elemType> *p);

	void deeporder(nodeType<elemType> *p);

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
void binaryTreeType<elemType>::inorderTraversal(void (*visit)(elemType& item)) {
	inorder(root,*visit);
}

template<class elemType>
void binaryTreeType<elemType>::preorderTraversal(void (*visit)(elemType&)) {
	preorder(root,*visit);
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
void binaryTreeType<elemType>::inorder(nodeType<elemType> *p,void (*visit)(elemType& item)) {
	if (p != NULL)
	{
		inorder(p->llink,*visit);
		(*visit)(p->info);
		inorder(p->rlink,*visit);
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
void binaryTreeType<elemType>::preorder(nodeType<elemType> *p,void (*visit)(elemType& item)) {
	if (p != NULL)
	{
		(*visit)(p->info);
		preorder(p->llink, *visit);
		preorder(p->rlink, *visit);
	}
}

template<class elemType>
void binaryTreeType<elemType>::deeporder(nodeType<elemType> *p) {
	if (p != NULL)
	{
		queue<nodeType<elemType>*> dqueue;
		nodeType<elemType> * current;

		current = p;

		while(!dqueue.empty() || current!= NULL) {
			dqueue.pop(current);

			cout << current->info <<" ";

			dqueue.push(current->llink);
			dqueue.push(current->rlink);
		}
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
void binaryTreeType<elemType>::nonRecursivePreTraversal() {
	stack<nodeType<elemType> *> tstack;
	nodeType<elemType> *current;
	current = root;

	while((current != NULL) || (!tstack.empty())) {
		if (current != NULL)
		{
			cout << current->info << " ";
			tstack.push(current);
			current = current->llink;
		} else {
			tstack.pop(current);
			current = current->rlink;
		}
	}

	cout << endl;
}

template<class elemType>
void binaryTreeType<elemType>::nonRecursivePostTraversal() {
	stack<nodeType<elemType>*> tstack;
	stack<int> istack;
	nodeType<elemType> *current = root;

	int v = 0;

	if (current == NULL) 
	{
		cout <<"The binary tree is empty" << endl;
	} else {
		tstack.push(current);
		istack.push(1);
		current = current->llink;

		while(!tstack.empty() && !istack.empty()) {
			if (current != NULL && v == 0)
			{
				tstack.push(current);
				istack.push(1);
				current = current->llink;
			} else {
				tstack.pop(current);
				istack.pop(v);

				if (v == 1)
				{
					tstack.push(current);
					istack.push(2);
					current = current->rlink;
					v = 0;
				} else {
					cout << current->info << " ";
				}
			}
		}
	}
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
	if (p == NULL)
	{
		return 0;
	} else {
		return 1 + nodeCount(p->llink) + nodeCount(p->rlink);
	}
}

template<class elemType>
int binaryTreeType<elemType>::leavesCount(nodeType<elemType> *p) {
	if (p == NULL)
	{
		return 0;
	} else if ((p->llink == NULL && p->rlink == NULL)){
		return 1;
	} else {
		return 1 + leavesCount(p->llink) + leavesCount(p->rlink);
	}
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