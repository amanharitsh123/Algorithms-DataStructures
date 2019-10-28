#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef vector<lli> vi;
bool bs(vi &arr,lli target)
{
    lli start,end;
    start=0;
    end=arr.size()-1;
    while(start <= end)
    {
        lli mid=(start+end)/2;
        if( arr[mid]==target)
            return true;
        else if(arr[mid]<target)
            start=mid+1;
        else
            end=mid-1;
    }
    return false;
}
int main()
{
    lli n,m;
    unordered_map<lli,lli> map;
    cin>>n;
    vi s(n);
    for(int i=0;i<n;i++)
    {
        cin>>s[i];
    }
    cin>>m;
    vi q(m);
    for(int i=0;i<m;i++)
    {
        cin>>q[i];
        map[q[i]]=true;
    }
    // Using Binary Search
    // for(int i=0;i<n;i++)
    // {
    //     if(bs(q,s[i])==false)
    //     {
    //         cout<<s[i]<<" ";
    //     }
    // }
    // Using unordered_map
    for(int i=0;i<n;i++)
    {
        if(map.find(s[i])==map.end())
        {
            cout<<s[i]<<" ";
        }
    }
    

    cout<<endl;
}
