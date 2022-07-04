#include <iostream> 
using namespace std; 
int arr[10]={3,4,5,2,4,2,3,6,8,10};

void MergeSort(int l, int r){
    
    if(l==r) return; 

    int m = (l+r)/2;

    MergeSort(l,m);
    MergeSort(m+1,r);

    int i=l; 
    int j=m+1; 
    int idx=0; 
    
    int * tmp = (int * )malloc(sizeof(int)* (r-l+1));

    while( (i<=m) &&(j<=r) ){
        if(arr[i]<arr[j]){
            tmp[idx]=arr[i];    
            ++i;
        }
        else{
            tmp[idx]=arr[j];
            ++j;
        }
        ++idx;         
    }

    if(i>m){
        for(; j<=r; ++j) {
            tmp[idx++]=arr[j];
        }
    }
    else if(j>r){
        for(; i<=m; ++i) {
            tmp[idx++]=arr[i];
        }
    }
    
    for(int k=l; k<=r; ++k) arr[k] = tmp[k-l];
    return; 
}


int main(){
    MergeSort(0,9);
    for(int i=0; i<10; ++i){
        cout<<arr[i]<<' ';
    }
    cout<<endl;
    return 0;
}