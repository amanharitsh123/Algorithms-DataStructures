#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
#include <vector>
#define ll long long int
#define mp make_pair
#define pb push_back
#define vi vector<int>
using namespace std;
struct matrix{
    vector<vector<ll>> mat;
    matrix(int n, int m){
        mat.resize(n,vector<ll>(m));
    }
    matrix operator*(const matrix &a){
        assert(mat[0].size()==a.mat.size());
        matrix ans(this->mat.size(),a.mat[0].size());
        for(int i=0;i<this->mat.size();i++){
            for(int j=0;j<a.mat[0].size();j++){
                for(int k=0;k<a.mat.size();k++){
                    ans.mat[i][j]+=(mat[i][k]*a.mat[k][j]);
                }

                ans.mat[i][j]%=2;
            }
        }
        return ans;
    }
    vector<ll>& operator[](int val){
        return mat[val];
    }
};


matrix matpower(matrix base, ll power){
    matrix ans=base;
    --power;
    while(power){
        if(power & 1){
            ans=ans*base;
        }
        base=base*base;
        power>>=1;
    }
    return ans;
}

matrix mul(matrix x, matrix a) {
        matrix ans(x.mat.size(),a.mat[0].size());
        for(int i=0;i<x.mat.size();i++){
            for(int j=0;j<a.mat[0].size();j++){
                for(int k=0;k<a.mat.size();k++){
                    ans.mat[i][j]^=(x.mat[i][k]*a.mat[k][j]);
                }
            }
        }
        return ans;
}

void solve(){
    //Main code
    int n, k;
    cin>>n>>k;
    --k;
    matrix init(1, n);
    for(int i=0;i<n;i++){
        cin>>init[0][i];
    }
    matrix convolution(n, n);
    for(int i=0;i<n;i++){
        int l,r;
        cin>>l>>r;
        --l;--r;
        for(int j=l;j<=r;j++){
            convolution[j][i]=1;
        }
    }
    convolution=matpower(convolution, k);
    matrix ans=mul(init,convolution);
    for(int i=0;i<n;i++){
        cout<<ans[0][i]<<" ";
    }
    cout<<'\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
