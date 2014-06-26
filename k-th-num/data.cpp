#include<iostream>
#include<ctime>
#include<cstdlib>
#include<cstdio>
using namespace std;
const int size = 100000;

const int k = size / 2;
int main() {
	freopen("in","w",stdout);
	cout<<size<<endl;
	srand((unsigned)time(NULL));
	for(int i = 0; i < size; i++) {
		cout<<rand()%200<<" ";
	}
	cout<<endl;
	cout<<k<<endl;
	return 0;
}
