#include<iostream>
using namespace std;
int main(){
    int a,c=1;
    cin>>a;
    for(int i=1;i<=a;i++){
        for(int j=1;j<=i;j++){
            cout<<c<<" ";
            c++;
           
        }
        cout<<endl;
    }
}