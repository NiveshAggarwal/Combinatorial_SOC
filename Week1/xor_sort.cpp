#include<iostream>
using namespace std;

void non(int *a,int*c, int *d, int &n){
    int res[n];
    for (int i=0;i<n;i++){
        res[i]=0;
    }
    for (int i=0;i<n;i++){
        for (int x=0;x<n;x++){
            if (a[x]<a[i] || (a[i]==a[x] && i>=x)) res[i]++;
    }
    }
    int i=n,k=0;
    n=0;
    while(k<i){
        if (res[k]==k+1)k++;
        else{

            c[n]=k+1;
            d[n]=res[k];
            d[n+1]=k+1;
            c[n+1]=res[k];
            c[n+2]=k+1;
            d[n+2]=res[k];
            swap(res[k],res[res[k]-1]);
            n+=3;
    }
} 
cout<<n<<endl;
for (int x=0;x<n;x++){
    cout<<c[x]<<" "<<d[x]<<endl;
}
}
int main(){
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        int h;
        cin>>h;
        int a[h];
        for (int q=0;q<h;q++){
            cin>>a[q];
        }
        int c[h*4],d[h*4];
        non(a,c,d,h);
    }
}