#include<iostream>
using namespace std;
int main(){
    int a;
    cin>>a;
    for(int i=1;i<=a;i++){
        for(int j=1;j<=i;j++){
            if(j<=a-i)
            cout<<" ";
            else 
            cout<<"*";
        }
        cout<<endl;
    }
}