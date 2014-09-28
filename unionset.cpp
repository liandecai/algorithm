#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 50000;
const int N = 101;

int set[maxn];
int n, m, size;

bool map[N][N];

void init() {
	for(int i = 0; i < size; i++) {
		set[i] = i;
	}
}

int find(int x) {
	int r = x;
	while(set[r] != r) {
		r = set[r];
	}
	return r;
}

void merge (int x, int y) {
	int i, j;
	i = find(x);
	j = find(y);
	if( i != j) {
		set[i] = j;
	}
}

void link(int x, int y) {
    int lfx = x - 1;
    int upy = y - 1;
    if(lfx >= 0 && map[lfx][y]) {
         merge(x * m + y, lfx * m + y);
    }
    if(upy >=0 && map[x][upy]) {
        merge(x * m + y, x * m  + upy);
    }
}
int main(){

	cin>>n>>m;
	size = n*m ;
	init();
    char c;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin>>c;
            if(c == '#') {
                map[i][j] = false;
                continue;
            }
            map[i][j] = true;
            link(i, j);
        }
    }
    int cnt = 0;
    for(int i = 0; i < size; i++){
        if(set[i] == i && map[i/m][i%m]){
            cnt++;
        }
    }
    cout<<cnt<<endl;
	return 0;
}
