#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int size = 1024 * 10000;
int m,k,num[size];

int partition(int l, int h) {
    int id = l + rand()%(h-l+1);
    swap(num[l], num[id]);
    int tmp = num[l];
    while(l!=h){
        while(l < h && num[h] >= tmp) {
            h--;
        }
        num[l]=num[h];
        while(l < h && num[l] <= tmp) {
            l++;
        }
        num[h]=num[l];
    }
    num[l]=tmp;
    return l;
}

void Qsort(int l, int h, int k){
    if(l < h) {
        int pos = partition(l,h);
        //1-k不排序，如需要排序注释即可
//        if(pos == k-1)
//            return;
        Qsort(l, pos-1, k);
        if(pos < k-1) {
            Qsort(pos+1,h, k);
        }
    }
}

int main()
{
    freopen("in","r",stdin);
    freopen("Bout","w",stdout);

    srand((unsigned)time(NULL));
    cin>>m;
    for(int i=0;i<m;i++) {
        cin>>num[i];
    }
    cin>>k;
    clock_t start, end;
    start = clock();
    Qsort(0, m -1,k);
    end = clock();
    printf( "%.6f seconds\n", (double)(end-start)/ CLOCKS_PER_SEC );
//    for(int i=0;i<k;i++){
//        cout<<num[i]<<" ";
//    }
    return 0;
}
