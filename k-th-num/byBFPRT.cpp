#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1024*10000;
int n,k;
int arr[N]; 
int midina(int nums[], int l, int r){
    sort(nums+l,nums+(r+1));
    return (r+l)/2;
}

int medianOfMedians(int nums[], int l, int r) {
    for(int i = 0; i < (r -l+1) /5 ; i++){
        int sl = l + i * 5;
        int idx = midina(nums, sl, sl+4);
        swap(nums[l+i], nums[idx]);
    }
    return midina(nums, l, l-1+(r-l+1)/5);
}
int partition(int nums[],int l, int r, int pivot){
    while(l < r) {
        //这边相等放高位的
        while(l<r && nums[r] >= pivot) r--;
        while(l<r && nums[l] < pivot) l++;
        swap(nums[l], nums[r]);
    }
    return l;
}
void selectK(int nums[], int l, int r, int k){
    if(r-l+1 < 5){
        midina(nums,l, r);
        return ;
    }
    int x = medianOfMedians(nums, l, r);
    int pivot = nums[x];
    int pos = partition(nums, l, r, pivot);
    int size = pos -l +1;
    if(k-1 < pos){
         selectK(nums, l, pos, k);
    }else if(k-1 > pos) {
         selectK(nums, pos+1, r, k);
    }
}


int main()
{
    freopen("in","r",stdin);
    freopen("Cout","w",stdout);
	cin>>n;	
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
	cin>>k;
	clock_t start, end;
	start = clock();
    selectK(arr, 0, n-1, k);
	end = clock();
	printf( "%.6f seconds\n", (double)(end-start)/ CLOCKS_PER_SEC );
    return 0;
}
