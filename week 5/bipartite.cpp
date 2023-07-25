#include<iostream>
#include<math.h>
using namespace std;


bool check(int n, int m, int arr[]){
    bool flag=1;
    for (int i=0;i<pow(2,n);i++){
        int sum=0;
        int num=0;
        for (int x=1;x<m+1;x++){
            bool pre=0;
            for (int c=0;c<n;c++){
                int pos=pow(2,c);
                pre=pre||(bool(pos & i)&&bool(arr[(c+1)*(m+1)+x]));
                if (x==1){
                    num+=bool(pos & i);
                }
            }
            pre=pre&&!(bool(arr[x]));
            sum+=pre;
        }
        flag=flag&&(sum>=num);
        if (flag==0) return 0;
    }
    return flag;
}

int main(){
    int n,m;
    cin>>n>>m;
    int arr[(n+1)*(m+1)];
    for (int i=0;i<n+1;i++){
        for (int k=0;k<m+1;k++){
            arr[i*(m+1)+k]=0;
        }}
        for (int i=0;i<n;i++){
        int x;
        cin>>x;
        for (int j=0 ;j<x;j++){
            int k;
            cin>>k;
            arr[(i+1)*(m+1)+k]=1;
        }
    }
//     cout<<endl;
// for (int i=0;i<n+1;i++){
//         for (int k=0;k<m+1;k++){
//             cout<<arr[i*(m+1)+k]<<" ";
//         }
//         cout<<endl;}
    if (check(n,m,arr)){
        for (int i=n+1;i>0;i--){
            for (int j=1;j<m+1;j++){
                if (arr[j]==0){
                    arr[j]=1;
                    if (check(i-1,m,arr)){
                        arr[i*(m+1)]=j;
                        break;
                    }
                    else arr[j]=0;
                }
            }
        }
        cout<<endl;
        for (int i=1;i<n+1;i++){
        cout<<i<<" "<<arr[i*(m+1)]<<endl;
    }
    }
    else cout<<-1;

return 0;

}
