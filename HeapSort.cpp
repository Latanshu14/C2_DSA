#include<bits/stdc++.h>
using namespace std;

vector<int> heapify(vector<int> &a){
    vector<int> b;
    int n = a.size();
    for(int i=0; i<n; i++){
        b.push_back(a[i]);
        int j=i;
        while(j>0){
            int par = (j-1)/2;
            if(b[par]<b[j]) swap(b[par], b[j]);
            else break;
            j = par;
        }
    }
    return b;
}
void heapsort(vector<int> &a){
    int n = a.size();
    a = heapify(a);
    int free = n-1;
    while(free>=0){
        swap(a[0], a[free]);
        free--;
        int i = 0, end = free;
        while(true){
            int left_child = 2*i+1, right_child = 2*i+2;
            if(left_child>end && right_child>end) break;
            if(left_child<=end && right_child>end){
                if(a[i]<a[left_child]){
                    swap(a[i], a[left_child]);
                    i = left_child;
                }
                else break;
            }
            else if(left_child>end && right_child<=end){
                if(a[i]<a[right_child]){
                    swap(a[i], a[right_child]);
                    i = right_child;
                }
                else break;
            }
            else{
                int mx_child = max(a[left_child], a[right_child]);
                if(mx_child>a[i]){
                    if(a[left_child]==mx_child){
                        swap(a[i], a[left_child]);
                        i = left_child;
                    }
                    else{
                        swap(a[i], a[right_child]);
                        i = right_child;
                    }
                }
                else break;
            }
        }
    }
}

int main(){
    int n; cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    heapsort(a);
    for(auto &x: a){
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}
