#include <iostream>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <cstdio>
using namespace std;
const int size = 1024 * 1000;

priority_queue<int> pq;
int num[size];
int m,k;

int getTheKNums(int k){

    for(int i=0;i<m;i++){
        if(pq.size() < k) {
            pq.push(num[i]);
        } else {
            if(pq.top() > num[i]) {
                pq.pop();
                pq.push(num[i]);
            }

        }

    }
}
//从小到大打印
void print(){
	if(pq.empty()) return;
	int tmp = pq.top();
	pq.pop();
	print();
	cout<<tmp<<" ";

}

int main()
{
    freopen("in","r",stdin);
    freopen("Aout","w",stdout);
    cin>>m;
    for(int i=0;i<m;i++) {
        cin>>num[i];
    }
    cin>>k;
	clock_t start, end;
	start= clock();
    getTheKNums(k);
	end=clock();
	printf( "%.6f seconds\n", (double)(end-start)/ CLOCKS_PER_SEC );
//	print();
	/*
    while(!pq.empty()) {
        cout<<pq.top()<<" ";
		tmp[]
        pq.pop();
    }
	*/
    return 0;
}
