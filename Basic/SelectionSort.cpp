#include <iostream> 
using namespace std; 

int arr[10]={3,4,5,2,4,2,3,6,8,10};



void SelctionSort(){
    int idx=0; 
    while(idx<10){
        int min_val_idx=idx; 

        for(int i=idx+1; i<10; ++i){
            if(arr[min_val_idx]>arr[i]) min_val_idx=i; 
        }
        
        int tmp= arr[min_val_idx];
        arr[min_val_idx]=arr[idx];
        arr[idx]=tmp; 
        
        ++idx; 
    }

}

int main(){
    SelctionSort();
    for(int i=0; i<10; ++i) cout<<arr[i]<<' ';
    return 0; 

}