#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;

int arr[N];
int st[4*N], mit[4*N], mat[4*N];

void build(int node,int l,int r){
    if(l==r){
        st[node]=mit[node]=mat[node]=arr[l];
        return;
    }
    int mid=(l+r)/2;
    build(2*node,l,mid);
    build(2*node+1,mid+1,r);
    st[node]=st[2*node]+st[2*node+1];
    mit[node]=min(mit[2*node],mit[2*node+1]);
    mat[node]=max(mat[2*node],mat[2*node+1]);
}

int qs(int node,int l,int r,int ql,int qr){
    if(qr<l || ql>r) return 0;
    if(ql<=l && r<=qr) return st[node];
    int mid=(l+r)/2;
    return qs(2*node,l,mid,ql,qr)+qs(2*node+1,mid+1,r,ql,qr);
}

int qmi(int node,int l,int r,int ql,int qr){
    if(qr<l || ql>r) return INT_MAX;
    if(ql<=l && r<=qr) return mit[node];
    int mid=(l+r)/2;
    return min(qmi(2*node,l,mid,ql,qr),qmi(2*node+1,mid+1,r,ql,qr));
}

int qma(int node,int l,int r,int ql,int qr){
    if(qr<l || ql>r) return INT_MIN;
    if(ql<=l && r<=qr) return mat[node];
    int mid=(l+r)/2;
    return max(qma(2*node,l,mid,ql,qr),qma(2*node+1,mid+1,r,ql,qr));
}

int main(){
    int n = 6;
    int a[] = {1,3,5,7,9,11};
    for(int i=0;i<n;i++) arr[i]=a[i];
    build(1,0,n-1);
    cout<<"sum: "<<qs(1,0,n-1,2,4)<<endl;
    cout<<"max: "<<qmi(1,0,n-1,2,4)<<endl;
    cout<<"min: "<<qma(1,0,n-1,2,4)<<endl;
}