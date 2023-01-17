#include <bits/stdc++.h>
using namespace std;

string int_to_binary(int decimal){
    if(decimal==0)
    return "0";
    if(decimal==1)
    return "1";
    if(decimal%2==0)
    return int_to_binary(decimal/2)+"0";
    else
    return int_to_binary(decimal/2)+"1";
}

int main()
{
    int n;
    cin>>n;
    cout<<int_to_binary(n)<<endl;

    return 0;
}