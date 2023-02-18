
#ifndef Hash_H
#define Hash_H


#include "binartree.h"
#include "Data.h"

template <class T>
class Hash
{
private:
	BinarTree<T>* tree;
	int capacity;

public:

	Hash(int V);
	void insert(Data<T,T> a);
	void delit(Data<T,T> a);
	void print();

	int chekprime(int n)
	{
		int i = 0;
		if (n == 1 || n == 0)
		{
			return 0;
		}

		for (i = 2; i < n / 2; i++)
		{
			if (n % i == 0)
			{
				return 0;
			}
		}
		return 1;
	}

	int getprime(int n)
	{
		if (n % 2 == 0)
		{
			n++;
		}

		while (!chekprime(n))
		{
			n = n + 2;
		}
		return n;
	}

	int HashFun(T key)
	{
		return (key % capacity);
	}

};

template <class T>
Hash<T>::Hash(int V)
{
	int size = getprime(V);
	this->capacity = size;

	tree = new BinarTree<T>[capacity]();
}

template <class T>
void Hash<T>::insert(Data<T,T> a)
{
	int index = HashFun(a.key);
	tree[index].addtree(&tree[index], a.data);
}

template <class T>
void Hash<T>::delit(Data<T,T> a)
{
	int index = HashFun(a.key);
	tree[index].del(&tree[index], a.data, &tree[index]);
}

template <class T>
void Hash<T>::print()
{
	for (int i = 0; i < capacity; i++)
	{
		cout << endl;

		tree[i].print(&tree[i]);
	}
}

#endif // !Hash_H
