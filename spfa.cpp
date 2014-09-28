#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
const int maxn = 101;
#define inf 0x3f3f3f3f

int k, n, m;

struct node {
    int to;
    int next;
}e[maxn*maxn*4];
int head[maxn*maxn*4];
bool map[maxn][maxn];

bool inq[maxn*maxn];
int dis[maxn*maxn];

void init(){
    k = 0;
    memset(head, -1, sizeof head);
    memset(dis, inf, sizeof dis);
    memset(inq, false, sizeof inq);
}
void addedge(int from, int to){
    k++;
    e[k].to = to;
    e[k].next = head[from];
    head[from] = k++;
}

void link(int x, int y) {
    int lfx = x - 1;
    int upy = y - 1;
    if(lfx >= 0 && map[lfx][y]) {
        addedge(x * m + y, lfx * m + y);
        addedge(lfx * m + y, x * m + y);
    }   
    if(upy >=0 && map[x][upy]) {
        addedge(x * m + y, x * m  + upy);
        addedge(x * m  + upy, x * m + y);
   }

}

void spfa(int point) {

    queue<int> q;
    q.push(point);
    dis[point] = 0;
    inq[point] = true;
    while(!q.empty()){
        int now = q.front();
        q.pop();
        inq[now] = false;
        for(int i = head[now]; i > -1; i = e[i].next) {
            if(dis[e[i].to] > dis[now] + 1){
                dis[e[i].to] = dis[now] + 1;
                if(!inq[e[i].to]){
                    q.push(e[i].to);
                }
            }
        }
        
    }

}
int main() {

    init();
    cin>>n>>m;
    char c;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) {
           cin>>c;
           if(c=='#'){
               map[i][j]=false;
               continue;
           }
           map[i][j]=true;
           link(i, j);
        }
    }
    int sx, sy, ex, ey;
    cin>>sx>>sy>>ex>>ey;
    spfa(sx*m+sy);
    cout<<dis[ex*m+ey];
    return 0;
}
