#include<iostream>
#include<cmath>
using namespace std;
void update(int pos[], int *weight, int n, int m,int p){
    while(m>0){
    int b[n];
    for (int i= 0;i<n;i++){
        b[i]=pos[i]*-1;
    }
    for (int i=0;i<n;i++){
        int max=-2000000;
        for (int x=0;x<n;x++){
            if (weight[x*n+i]-pos[x]>max)max=weight[x*n+i]-pos[x];
        }
        b[i]=max;
    }
    m-=p/2;
    if (p==2)p=1;
    else p=2;
    for (int i= 0;i<n;i++){
        pos[i]=b[i];
    }
}
bool flag=0;
for (int i= 0;i<n;i++){
        pos[i]=-pos[i]+weight[0+i*n];
        if (pos[i]>0){flag=1;}
    }
    if (flag)cout<<1;
    else cout<<2;
}
void check(){}

int main(){
    int n,m;
    cin>>n>>m;
    int weight[n*n];
    int pos[n];
    for (int i;i<n;i++){
        pos[i]=0;
        for (int x=0;x<n;x++){
            if (x!=i)cin>>weight[i*n+x];
            else weight[i*n+x]=-2000000;
        }
    }
    int p=2;
    update(pos,weight,n,m,p);
}