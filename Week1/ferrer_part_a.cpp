#include <iostream>
#include<cstring>
#include<sstream>
using namespace std;
int main(){
    string x;
    cin>>x;
    stringstream ss(x);
char ch;
int i=0,n=0;
while (x[i]!=0){
    if (x[i++]==',') n++;
}
n++;

int a[n];
ss>>ch;
for (int i=0;i<n;i++){
    ss>>a[i]>>ch;
    for (int q=0;q<a[i];q++) cout<<"*";
    cout<<endl;
}

}