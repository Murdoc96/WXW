#include<iostream>
using namespace std;




int main(){
	int valor = 9;
	int *iptr;
	int **iptrd;
	int ***iptrt;
	iptr = &valor ;
	iptrd = &iptr;
	iptrt = &iptrd;

	cout << *iptr << endl;
	std::cout << **iptrd << '\n';
	std::cout << ***iptrt << '\n';

	return 0;
}
