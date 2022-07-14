#include <bits/stdc++.h>
using namespace std;
void printarray(int *a, int n){
    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
void Bubblesort(int *a, int n){
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(a[i]>a[j]){
                int temp = a[j];
                a[j] = a[i];
                a[i] = temp;
            }
        }
    }
}
void Insertionsort(int *a, int n){
    for(int i=1; i<n; i++){
        int x = a[i];
        int j = i-1;
        while(j>=0 && a[j]>x){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = x;
    }
}
void merge(int *a, int l, int mid, int r){
    int left_size = mid - l + 1;
    int right_size = r - (mid+1) + 1;
    int L[left_size], R[right_size];
    for(int i=0; i<left_size; i++){
        L[i] = a[i+l];
    }
    for(int i=0; i<right_size; i++){
        R[i] = a[i+mid+1];
    }
    int left_index = 0, right_index = 0;
    int i=l;
    while(left_index<left_size && right_index<right_size){
        if(L[left_index]<R[right_index]){
            a[i++] = L[left_index++];
        }
        else{
            a[i++] = R[right_index++];
        }
    }
    while(left_index<left_size){
        a[i++] = L[left_index++];
    }
    while(right_index<right_size){
        a[i++] = R[right_index++];
    }
}
void Mergesort(int *a, int l, int r){
    if(l==r){
        return;
    }
    int mid = (l+r)/2;
    Mergesort(a, l, mid);
    Mergesort(a, mid+1, r);
    merge(a, l, mid, r);
}
void LinearSearch(int *a, int n, int x){
    int ans = -1;
    for(int i=0; i<n; i++){
        if(a[i]==x){
            ans = i;
        }
    }
    if(ans==-1){
        cout<<"Value not found."<<endl;
    }
    else{
        cout<<"Value "<<x<<" is present at index "<<ans<<"."<<endl;
    }
}
void BinarySearch(int *a, int n, int x){
    int low = 0, high = n-1;
    int ans = -1;
    while(low<=high){
        int mid = (low+high)/2;
        if(a[mid]==x){
            ans = mid;
            low = 1;
            high = 0;
        }
        if(a[mid]>x){
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    if(ans==-1){
        cout<<"Value not found."<<endl;
    }
    else{
        cout<<"Value "<<x<<" is present at index "<<ans<<"."<<endl;
    }
}
int partitionindex(int *a, int start, int end){
    int partition_index = 0;
    int pivot = a[end];
    for(int i=0; i<end; i++){
        if(a[i]<=pivot){
            swap(a[i], a[partition_index]);
            partition_index++;
        }
    }
    swap(a[partition_index], a[end]);
    return partition_index;
}
void QuickSort(int *a, int start, int end){
    if(start<end){
        int partition_index = partitionindex(a, start, end);
        QuickSort(a, start, partition_index-1);
        QuickSort(a, partition_index+1, end);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    //Bubblesort(a, n);
    //Insertionsort(a, n);
    //Mergesort(a, 0, n-1);
    QuickSort(a, 0, n-1);
    printarray(a, n);
    //LinearSearch(a, n, 7);
    BinarySearch(a, n, 100);
    return 0;
}