#include "Hash.h"
#include "Data.h"
using namespace std;

int main()
{
	int v[] = {7,5,12,14,3 };
	BinarTree<int> a = BinarTree<int>(v,5);
	
	Data<int, int> kata[10];
	for (int i = 0; i < 100; i++)
	{
		kata[i].key = i;
		kata[i].data = i * 10;
	}

	Data<int, int> gopa;
	gopa.key = 22;
	gopa.data = 301;

	Data<int,int> gopa1;
	gopa1.key = 20;
	gopa1.data = 12;

	Hash<int> b(100);
	for(int i = 0; i < 10; i++)
	b.insert(kata[i]);
	b.insert(gopa);
	b.insert(gopa1);
//	b.delit(kata[3]);
	b.print();
	
	return 0;
}