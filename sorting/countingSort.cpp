#include <bits/stdc++.h>

using namespace std;
void printarray(int array[], int size){
      //print the array
    for(int i=0;i<size;i++){
        cout<<array[i]<<" ";
    }
}

int main()
{
    int size;
    cin>>size;
    int arr[size];
    for(int i=0;i<size;i++){
        cin>>arr[i];
        
    }
    //before sort count 
    cout<<"Before Sort: ";
    printarray(arr, size);
    //step-1 Finding the maximum
    int max = INT_MIN;
    for(int i=0;i<size;i++){
        if(arr[i]>max){
            max = arr[i];
        }
    }
    //step-2: initialize the count array
    int count[max+1];
    for(int i=0;i<=max;i++){
        count[i]=0;
    }
    //step-3: Frequentcy Calculation 
    for(int i=0;i<size;i++){
        count[arr[i]]++;
    }
    //step-4: Cumolative sum
    for(int i= 1;i<=max;i++){
        count[i]+=count[i-1];
        
    }
    //step-5: final arry --> Backword travarsal (reverse array)
    int final[size];
    for(int i=size-1;i>=0;i--){
        count[arr[i]]--;
        int k=count[arr[i]];
        final[k] = arr[i];
    }
    //cout<<"\n"<<endl;
    cout<<"\nAfter Counting Sort: ";
  
    printarray(final, size);
    return 0;
}