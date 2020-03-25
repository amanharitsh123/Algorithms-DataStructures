#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<unordered_map>
#include<map>
using namespace std;
typedef long long int lli;
#define For(i,n) for(lli I=i;I<n;I++)

lli *tree;
vector<lli> arr;

void up(lli t,lli val) {
    lli i=t;
    lli n=arr.size();
    while(t<=n)
    {
        tree[t] -= arr[i-1];
        tree[t] += val;
        t += t & (-t);
    }
    arr[i-1]=val;
}

lli query(lli t) {
    lli sum = 0;
    while(t>0) {
        sum += tree[t];
        t -= t & (-t);
    }
    return sum;
}


void construct() {
    lli n=arr.size();
    delete[] tree;
    tree = new lli[n+1]();
    for(lli i=0;i<n;i++) {
        lli temp=arr[i];
        arr[i]=0;
        up(i+1,temp);
    }
}

int main() {

}
