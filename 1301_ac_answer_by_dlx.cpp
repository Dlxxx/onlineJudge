#include <bits/stdc++.h>
#include <vector>
#include <random>
//与助教讨论过怎么不超时捏
using namespace std;

int n;
int a[1000005];
int result[1000005];
int counter[1000005] = {0};




void merge(int low, int middle, int high) {
    int i = low, j = middle+1, k = low;
    int flag=0;
    // int n1 = middle - low + 1;
    // int L[n1], 
    while (i <= middle && j <= high) {
        if (a[i] < a[j]) {
            counter[a[i]] += j - middle - 1;
            
            result[k++] = a[i++];
        } else {
            counter[a[j]] += middle - i + 1;
            result[k++] = a[j++];
        }
    }
    while (i <= middle){
        counter[a[i]] += j- middle-1;
        flag = i;
        result[k++] = a[i++];
    }
    // if(flag){    
    //     for(int p = middle+1; p<=high; p++){

    //         counter[a[p]] += middle - flag + 1;
    //         cout<<a[p]<<" WILL add :"<<(middle - flag + 1)<<endl;
    //     }
    // }

    while (j <= high){
        result[k++] = a[j++];
    }
    for(int _=low; _<=high; _++){
        a[_] = result[_];
    }
    return ;
}

void mergeSort(int left, int right) {
    if (left >= right) return;
    int middle = left + (right - left) / 2;
    mergeSort(left, middle);
    mergeSort(middle + 1, right);
    merge(left, middle, right);
}


int main()
{
    cin>>n;
    for(int _=0; _<n; _++){
        cin>>a[_];
    }
    // cout<<"before"<<endl;
    // for (int _=0; _<n; _++){
    //     cout<<counter[a[_]]<<" ";
    // }
    // bubble_sort(a, n);
    // cout<<endl<<"*******MERGE*********"<<endl;

    mergeSort(0, n-1);

    // cout<<endl<<"*******MERGE*********"<<endl;

    for (int _=0; _<n; _++){
        // cout<<" the "<<a[_]<<"th is ";
        cout<<counter[a[_]]<<" ";
    }
    cout<<endl;
    return 0;
}