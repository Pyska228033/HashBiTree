#ifndef Binartree_H
#define Binsrtree_H

#include <iostream>

using namespace std;

template <class T>
class BinarTree
{
private:
	T data;
	BinarTree<T>* left;
	BinarTree<T>* right;

public:

	BinarTree();
	BinarTree(T elem);
	BinarTree(T* v, int n);
	void addtree(BinarTree<T>* tree, T a);
	BinarTree<T>* find(BinarTree<T>* tree, T a);
	BinarTree<T>* getmin(BinarTree<T>* tree, BinarTree<T>*& tree1);
	void del(BinarTree<T>* tree, T a, BinarTree<T>* tree1);
	void print(BinarTree<T>* tree);

};


template <class T>
BinarTree<T> :: BinarTree()
{
	data = 0;
	left = NULL;
	right = NULL;
}

template <class T>
BinarTree<T> ::BinarTree(T elem)
{
	data = elem;
	left = NULL;
	right = NULL;
}

template<class T>
BinarTree<T> :: BinarTree(T* v, int n)
{
	*this = BinarTree<T>(v[0]);
	for (int i = 1; i < n; i++)
	{
		this->addtree(this, v[i]);
	}
}

template <class T>
void BinarTree<T> ::addtree(BinarTree<T>* tree, T a)
{
	if (tree == NULL)
	{
		tree = new BinarTree<T>;
		tree->data = a;
		tree->left = tree->right = NULL;
		return;
	}

	else
		if (a < tree->data)
		{
			if (tree->left != NULL)
				addtree(tree->left, a);
			else
			{
				tree->left = new BinarTree<T>;
				tree->left->left = tree->left->right = NULL;
				tree->left->data = a;
			}
		}
	else
		if (a > tree->data)
		{
			if (tree->right != NULL) addtree(tree->right, a);
			else
			{
				tree->right = new BinarTree<T>;
				tree->right->left = tree->right->right = NULL;
				tree->right->data = a;
			}
		}
}

template <class T>
BinarTree<T>* BinarTree<T> ::find(BinarTree<T>* tree, T a)
{
	if (tree != NULL)
	{
		if (tree->data == a)
		{
			return tree;
		}
		else
			if (a > tree->data)
			{
				return find(tree->right, a);
			}
			else
				if (a < tree->data)
				{
					return find(tree->left, a);
				}
	}
	else
		return NULL;
}

template < class T>
BinarTree<T>* BinarTree<T>::getmin(BinarTree<T>* tree, BinarTree<T>*& tree1)
{
	if (tree == NULL)
		return NULL;
	if (tree->left != NULL)
	{
		BinarTree<T>* tree2 = getmin(tree->left, tree);
		tree1 = tree;
		return tree2;
	}
	else
		return tree;
}



template <class T>
void BinarTree<T> ::del(BinarTree<T>* tree, T a, BinarTree<T>* tree1)
{
	if (tree != NULL)
	{
		if (a == tree->data)
		{
			if ((tree->left == NULL) && (tree->right == NULL))
			{
				if (tree1 != NULL && tree1->data <= tree->data)
					tree1->right = NULL;
				else
					tree1->left = NULL;
				delete tree;
			}

			else if (tree->left == NULL && tree->right != NULL)
			{
				if (tree1 != NULL && tree1->data <= tree->data)
					tree1->right = tree->right;
				else
					tree1->left = tree->right;
				delete tree;

			}
			else if (tree->left != NULL && tree->right == NULL)
			{
				if (tree1 != NULL && tree1->data <= tree->data)
					tree1->right = tree->left;
				else
					tree1->left = tree->left;
				delete tree;
			}
			else if (tree->left != NULL && tree->right != NULL)
			{
				BinarTree<T>* tree1 = NULL;
				BinarTree<T>* tree2 = getmin(tree -> right, tree1);

				if (tree2->right == NULL)
				{
					if (tree1 != NULL)
						tree1->left = NULL;
				}
				else
				{
					if (tree1 != NULL)
						tree1->left = tree2->right;
				}
				tree->data = tree2->data;
				tree->right = tree2->right;
				delete tree2;
			}
		}
		else if (a < tree->data)
		{
			del(tree->left, a, tree);
		}
		else if (a > tree->data)
		{
			del(tree->right, a, tree);
		}

	}
	else cout << "elements net" << endl;
}

template <class T>
void BinarTree<T> :: print(BinarTree<T>* tree)
{
	if (tree != NULL)
	{
		print(tree->left);
		cout << tree->data << "__";
		print(tree->right);
		cout << endl;
	}
}

#endif // !Binartree_H



