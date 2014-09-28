#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 1000001;
int s[maxn], e[maxn], index[maxn], n;

bool cmp(int a, int b) {
    return e[a] <  e[b];
}
int main() {
    cin>>n;
    for(int i = 0; i < n; i++) {
        index[i] = i;
        cin>>s[i]>>e[i];
    }
    sort(index, index + n, cmp);
    int now = 0;
    int cnt = 1;
    for(int i = 0; i< n; i++) {
        if(s[index[i]] > e[index[now]]) {
            cnt++, now = i;
        }
    }
    cout<<cnt<<endl;
}
