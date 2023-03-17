#include <iostream>

using namespace std;

int main()
{
    int n,m,i,c=0;
    cin>>n;
    int a[n];
    for( i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<"Enter a number that you want to search: ";
    cin>>m;
    for(i=0;i<n;i++){
        if(a[i]==m){
            c=i;
            cout<<"The index of the number is: "<<c<<endl;

        }
        
    }
    return 0;
}