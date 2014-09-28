#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
const int maxn = 20;
#define mp(a, b) make_pair(a, b)
int n, k, num[maxn];
int sum[1<<20|1];
bool ispowof2(int n) {
	return !(n & (n-1));
}
int main() {
	cin>>n>>k;
	for(int i = 0; i < n; i++){
		cin>>num[i];
		sum[1<<i] = num[i];
	}
	int tmp = 1;
	for(int i = 1; i < (1<<n); i++){
		if(ispowof2(i)){
			tmp = i;
		} else {
			sum[i] = sum [tmp] + sum[i-tmp];
		}
		if(sum[i] == k) {
			cout<<i<<endl;
		}
	}
	return 0;
}
