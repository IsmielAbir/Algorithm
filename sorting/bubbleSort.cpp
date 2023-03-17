#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    int c=1;
    while(c<n-1){
        for(int i=0;i<n-c;i++){
            if(a[i]>a[i+1])
            {int temp=a[i];a[i]=a[i+1];a[i+1]=temp;}
        }
        c++;
    }
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
}