#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<unordered_map>
#include<map>
#include<string>
using namespace std;
typedef long long int lli;
#define For(i,n) for(lli I=i;I<n;I++)
lli *tree;
vector<lli> arr;

void update(lli t,lli val, lli n) {
    lli i=t;
    while(t<=n)
    {
        tree[t] -= arr[i];
        tree[t] += val;
        t += t & (-t);
    }
    arr[i]=val;
}

lli query(lli t) {
    lli sum = 0;
    while(t>0) {
        sum += tree[t];
        t -= t & (-t);
    }
}


void construct() {
    lli n=arr.size();
    tree = new lli[n+1]();
    for(lli i=0;i<n;i++) {
        update(i,arr[i],n);
    }
}
int main() {
    lli n,temp;
    for(lli i=0;i<n;i++) cin>>temp, arr.push_back(temp);
    construct();
    
}