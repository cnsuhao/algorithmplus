#ifndef ___BSEARCHTREETYPE_H___
#define ___BSEARCHTREETYPE_H___


#include "binaryTree.hpp"

template<class elemType>
class bSearchTreeType : public binaryTreeType<elemType> {

public:
	bool search(const elemType& searchItem);

	bool insert(const elemType& insertItem);

	bool deleteNode(const elemType& deleteItem);

private:
	void deleteFromTree(nodeType<elemType>* &p);
};

template<class elemType>
bool bSearchTreeType<elemType>::search(const elemType& searchItem){
	nodeType<elemType> *current;
	bool found = false;

	if(root == NULL) {
		cout << "Cannot search the empty tree." << endl;
	} else {
		current == root;

		while(current != NULL && !found) {
			if (current->info == searchItem)
			{
				found = true;
			} else {
				if (current->info > searchItem)
				{
					current = current->llink;
				} else {
					current = current->rlink
				}
			}
		}
	}

	return found;
}

template<class elemType>
void bSearchTreeType<elemType>::insert(const elemType& insertItem) {
	nodeType<elemType> *current;
	nodeType<elemType> *trailCurrent;
	nodeType<elemType> *newNode;

	newNode = new nodeType<elemType>;
	newNode->info = insertItem;
	newNode->llink = NULL;
	newNode->rlink = NULL;

	if (root == NULL)
	{
		root = newNode;
	} else {
		current = root;

		while(current != NULL) 
		{
			trailCurrent = current;

			if (current->info == insertItem)
			{
				cout << "the insert item already is in the list";
				cout << "duplicates are not allowed." << insertItem << endl;
				return;
			} else {
				if (current->info > insertItem)
				{
					current = current->llink;
				} else {
					current = current->rlink;
				}
			}
		}

		if (trailCurrent->info > insertItem)
		{
			trailCurrent->llink = newNode;
		} else {
			trailCurrent->rlink = newNode;
		}
	}
}

template<class elemType>
void bSearchTreeType<elemType>::deleteFromTree(nodeType<elemType>* &p) {
	nodeType<elemType> *current;
	nodeType<elemType> *trailCurrent;
	nodeType<elemType> *temp;

	if (p == NULL)
	{
		cout << "Error: The node to be delete is NULL" << endl;
	} else if (p->llink == NULL && p->rlink)
	{
		temp = p;
		p = NULL;
		delete temp;
	} else if (p->llink == NULL)
	{
		temp = p;
		p = temp->rlink;
		delete temp;
	} else if (p->rlink == NULL) {
		temp = p;
		p = temp->llink;
		
		delete temp;
	} else {
		current = p->llink;
		trailCurrent = NULL;

		while(current->rlink != NULL) {
			trailCurrent = current;
			current = current->rlink;
		}

		p->info = current->info;

		if (trailCurrent == NULL)
		{
			p->llink = current->llink;
		} else {
			trailCurrent->rlink = current->llink;
		}

		delete current;
	}// end else
}

template<class elemType>
void bSearchTreeType<elemType>::deleteNode(const elemType& deleteItem) {
	nodeType<elemType> *current;
	nodeType<elemType> *trailCurrent;
	bool found = false;

	if(root == NULL) {
		cout <<"Cannot delete from the empty tree." << endl;
	} else {
		current = root;

		while(current != NULL && !found) {
			if(current->info == deleteItem) {
				found = true;
			} else {
				trailCurrent = current;
				if (current->info > deleteItem)
				{
					current = current->llink;
				} else {
					current = current->rlink;
				}
			}
		}

		if (current == NULL)
		{
			cout << "The delete item is not in the list." << endl;
		} else if(found) {
			if (current == root)
			{
				deleteFromTree(root);
			} else if (trailCurrent->info > deleteItem)
			{
				deleteFromTree(trailCurrent->llink);
			} else {
				deleteFromTree(trailCurrent->rlink);
			}
		} // end else if
		
	}
}

#endif // end of ___BSEARCHTREETYPE_H___
