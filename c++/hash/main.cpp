#include<iostream>
//#include<cstdlib>
#include"tabla.h"

using namespace std;

int main(){


	HashMap *table = new HashMap();

	// table->put(16,1500);
	// table->put(15,1300);
	// table->put(14,1200);
	// table->put(13,1100);
	// table->put(7,1000);
	// table->put(11,900);
	// table->put(10,800);
	// table->put(9,700);
	// table->put(8,600);
	// table->put(12,400);
	// table->put(6,100);
	// table->put(5,200);
	// table->put(4,2448);
	// table->put(3,800);
	// table->put(2,3200);
	// table->put(1,2400);
	// table->put(0,0);

	// table->put(0,0);
	// table->put(1,2400);
	// table->put(2,3200);
	// table->put(3,800);
	// table->put(4,2448);
	// table->put(5,200);
	// table->put(6,100);
	// table->put(12,400);
	// table->put(8,600);
	// table->put(9,700);
	// table->put(10,800);
	// table->put(11,900);
	// table->put(7,1000);
	// table->put(13,1100);
	// table->put(14,1200);
	// table->put(15,1300);
	// table->put(16,1500);
	int a;
	for(int e = 0 ;e < 100 ; e++){
		a = 1 + rand()% (101-1);
		cout << a << " ";
		table->put(a,10);
	}
	cout << endl << endl;
	table->print();


	delete table;
	return 0;
}
