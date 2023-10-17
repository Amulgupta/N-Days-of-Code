#include <iostream>
using namespace std;
int main() {
	// your code goes here
	int jacketCost, sockCost, money;
	cin>>jacketCost>>sockCost>>money;
	int rem = money - jacketCost;
	if((rem /sockCost) % 2 != 0)
	cout<<"Unlucky Chef"<<endl;
	else cout<<"Lucky Chef"<<endl;
	return 0;
}
