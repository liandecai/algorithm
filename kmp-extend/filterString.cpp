#include <iostream>
#include <cstring>
#include<cstdio>
#include<stack>
using namespace std;
typedef pair<int,char> pii;
const int size =2048;
stack<pii> s;
string source,target;
int next[size];
int pos[size];
int lenSource,lenTarget;


void getNext()
{
    next[1]=0;
    int j=0;
    int i;
    for(i=2;i<=lenTarget;i++)
    {
        while(j>0&&target[j+1]!=target[i])
            j=next[j];
        if(target[j+1]==target[i])
            j++;
        next[i]=j;
    }
}

void kmp(){
    int j=0;
    for(int i=0;i<lenSource;i++)
    {
        while(j>0&&target[j+1]!=source[i])
            j=next[j];
        if(target[j+1]==source[i])
            j++;
        pos[i]=j;
        s.push(make_pair(i,source[i]));
        if(j==lenTarget)
        {
            for(int k=0;k<lenTarget;k++){
                s.pop();
            }
            if(!s.empty()){
                pii p = s.top();
                j=pos[p.first];
            }
        }
    }
}

void print(){
    if(s.empty())
        return;
    pii tmp = s.top();
    s.pop();
    print();
    cout<<tmp.second;

}
int main()
{
    freopen("in","r",stdin);
    cin>>source>>target;
    target=" "+target;
    lenSource=source.size();
    lenTarget=target.size()-1;
    getNext();
    kmp();
    cout<<"answer:"<<endl;
    print();
    return 0;
}
