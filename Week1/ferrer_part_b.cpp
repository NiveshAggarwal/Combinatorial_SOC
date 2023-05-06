#include<iostream>
using namespace std;

int Q(int n, int k){ //largest number k
int out=0;
if (n==0) return 1;
if (n<0) return 0;
for (int i=k; i>0; i--){
   out+=Q(n-i,i);
}
return out;
}

int R(int n, int k){// max k elements
int out=0;
if (n<0) return 0;
if (n==0) return 1;
if (k==0) return 0;

for (int i=0;i<n+1;i++){
    out+=R(n-i*k,k-1);
}
return out;
}

int main(){
int n,k;
cin>>n>>k;
cout<<Q(n,k)<<" "<<R(n,k);
}