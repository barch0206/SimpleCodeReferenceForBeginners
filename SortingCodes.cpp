#include <iostream>
#include<string>
#include<map>
#include<set>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

void bubblesort(vector<int>&arr){
    //bubble sort: n^2 time
    vector<int>bbs=arr;
    int n=bbs.size();
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(bbs[i]>bbs[j])swap(bbs[i],bbs[j]);
        }
    }
    for(int i=0;i<n;i++)cout<<bbs[i]<<" ";
    cout<<" bubble sort worked!\n";
}

void selectionsort(vector<int>&arr){
    //selection sort n^2 time
    int n=arr.size();
    vector<int>ss=arr;
    for(int i=0;i<n;i++){
        int mini=i;
        for(int j=i+1;j<n;j++){
            if(ss[j]<ss[mini])mini=j;
        }
        swap(ss[mini],ss[i]);
    }
    for(int i=0;i<n;i++)cout<<ss[i]<<" ";
    cout<<" selection sort worked!\n";
}


void insertionsort(vector<int>&arr){
    //insertion sort n^2 time
    int n=arr.size();
    vector<int>is=arr;
    for(int i=1;i<n;i++){
        int j=i-1;
        int key=is[i];
        while(j>=0 && is[j]>key){
            is[j+1]=is[j];j--;
        }
        is[j+1]=key;
    }
    for(int i=0;i<n;i++)cout<<is[i]<<" ";
    cout<<" insertion sort worked!\n";
}


void merge(vector<int>&msa,int st,int mid,int end){
    vector<int>merge;
    int lft=st,rt=mid+1;
    while(lft<=mid && rt<=end){
        if(msa[lft]<=msa[rt]){
            merge.push_back(msa[lft++]);
        }
        else merge.push_back(msa[rt++]);
    }
    while(lft<=mid){
        merge.push_back(msa[lft++]);
    }
    while(rt<=end){
        merge.push_back(msa[rt++]);
    }
    lft=0;
    for(int i=st;i<=end;i++)msa[i]=merge[lft++];
    return;
}


void mssort(vector<int>&msa,int st,int end){
    if(st>=end)return;
    int mid=st+(end-st)/2;
    mssort(msa,st,mid);
    mssort(msa,mid+1,end);
    merge(msa,st,mid,end);
}

void mergesort(vector<int>&arr){
    //merge sort nlogn time
    vector<int> msa=arr;
    int n=msa.size();
    int st=0,end=n-1;
    mssort(msa,st,end);
    if(st==0 && end==n-1){
        for(int i=0;i<n;i++)cout<<msa[i]<<" ";
    cout<<" merge sort worked!\n";
    }
}



int partition(vector<int>&qs,int st,int end){
    int pivot=qs[end];
    int lft=st,rt=end;
    while(lft<rt){
        while(qs[lft]<pivot)lft++;
        while(qs[rt]>pivot)rt--;
        if(lft<rt)swap(qs[lft],qs[rt]);
    }
    return lft;
}

void qssort(vector<int>&qs,int st,int end){
    if(st>=end)return;
    int pivot=partition(qs,st,end);
    qssort(qs,st,pivot-1);
    qssort(qs,pivot+1,end);
}

void quicksort(vector<int>&arr){
    // quick sort nlogn avg time, n^2 worst case time    
    vector<int>qs=arr;
    int n=qs.size();
    qssort(qs,0,n-1);
    for(int i=0;i<n;i++)cout<<qs[i]<<" ";
    cout<<" quick sort worked!\n";
}

int main() {
    
    vector<int>arr={1,9,3,2,5,4};
    for(int i=0;i<arr.size();i++)cout<<arr[i]<<" ";
    cout<<" -> original array\n";
    bubblesort(arr);
    selectionsort(arr);
    insertionsort(arr);
    mergesort(arr);
    quicksort(arr);
    
return 0;
}
