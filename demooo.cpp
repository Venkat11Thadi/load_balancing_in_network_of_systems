#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
void solve()
{
    ll n,m;
    cin>>n>>m;
    ll k=m;
    vector<int> vis(n,0);
    map<int,pair<int,int>> mp;
    while(n--){
        ll a,b,c;
        cin>>a>>b>>c;
        mp[a]={b,c};
    }
    map<int,vector<int>> mp1;
    while(m--){
        ll a,b;
        cin>>a>>b;
        mp1[a].push_back(b);
        mp1[b].push_back(a);
    }
    priority_queue<pair<int,int>> pq;
    int l;
    cin>>l;
    while(l--){
        ll a;
        cin>>a;
        vis[a-1]=1;
        pq.push({mp[a].first,a});
    }
    ll val;
    cin>>val;
    vector<int> ans_path;
    while(val>0){
        ans_path.push_back(pq.top().second);
        pair<int,int> p=pq.top();
        pq.pop();
        if(val-mp[p.second].second>0)
            cout<<"Node - "<<p.second<<" No. of Jobs allocated - "<<mp[p.second].second<<endl;
        else
            cout<<"Node - "<<p.second<<" No. of Jobs allocated - "<<mp[p.second].second<<endl;
        val-=mp[p.second].second;
        for(auto i:mp1[p.second])
            if(vis[i-1]==0){
                pq.push({mp[i].first,i});
                vis[i-1]=1;
            }
    }
    cout<<endl;
    cout<<"Path : ";
    for(auto i:ans_path)
        cout<<i<<" ";

}
 
 
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ll t;
    cin>>t;
    while(t--)
    {
        solve();
        cout<<endl;
    }
}