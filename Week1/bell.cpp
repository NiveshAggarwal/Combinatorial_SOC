#include<iostream>
using namespace std;
#define niv 7
int fac(int n){
     int a =1;
     for (int i=1;i<n+1;i++) a*=i;
     return a;
}

int c(int n, int r){
return (1.0*fac(n)/(fac(r)*fac(n-r)));
}

void find(int n, int k, int*d,int *res,int &q){
    //border case
    if (k==1){

        for (int t=0;n>0;t++){
            if (res[t]==0){
                res[t]=++q;
                n--;
            }
        }
        return;
    }
    //if k!=0
    q++;
    int sum=0;
    int i=n-1;

    while(1){
        sum+=c(n-1,i)*d[i];

        if (sum>=k){
            sum-=c(n-1,i)*d[i];
            break;
        }
        i--;
    }
    //now we know how many in this partition


    sum=k-sum;
    k=(sum-1)%(d[i])+1;
    sum=(sum-k)/d[i]+1;
    // new values to call again

    int x=0;
    int f=n-i;
    int r=0;
    while (f>0){
        if (res[x++]==0){
            r++;
            if (sum-c(n-r,f-1)<=0){
                res[x-1]=q;
                f--;
            }
            else sum-=c(n-r,f-1);
        }
    }
    for (int i=0;i<niv;i++){

}
    find(i,k,d,res,q);
    }



int main(){
    int n,k;
    cin>>n>>k;
    int d[n],res[n];
    d[0]=1;
    res[0]=0;
    for (int i =1 ;i<n;i++){
        d[i]=res[i]=0;
        for (int x=0;x<i;x++){
            d[i]+=c(i-1,x)*d[x];

        }

    }
    int m=0;
    find(n,k,d,res,m);

for (int i=1;i<=m;i++){
    for (int x=0;x<n;x++){
if (res[x]==i) cout<<x+1<<" ";
}
cout<<endl;

}
cout<<d[9];
}