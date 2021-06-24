#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,k;
ll result=0;
bool sort_asc(pair<ll,ll>&a,pair<ll,ll>&b){
    return a.first<b.first;
}

bool sort_desc(pair<ll,ll>&a,pair<ll,ll>&b){
    return a.first>b.first;
}

void cal(vector<pair<ll,ll>>list_pair){
    ll mem=0,count=0;
    int i=0;
    while(i<list_pair.size()){
        if(mem==0){
            count=list_pair[i].second/k;
            result+=2*count*abs(list_pair[i].first);
            if(list_pair[i].second%k!=0){
                result+=2*abs(list_pair[i].first);
                mem=k-(list_pair[i].second-count*k);
            }
            i++;
        }
        else{
            if(list_pair[i].second<=mem){
                mem-=list_pair[i].second;
                i++;
            }
            else{
                list_pair[i].second-=mem;
                mem=0;
            }
        }
    }
}
int main(){
    cin>>n>>k;
    ll x,y;
    vector<pair<ll,ll>>coo_neg,coo_pos;
    for(ll i=0;i<n;i++){
        cin>>x>>y;
        if(x<0){
            coo_neg.push_back({x,y});
        }
        else if(x>0)coo_pos.push_back({x,y});
    }
    sort(coo_neg.begin(),coo_neg.end(),sort_asc);
    sort(coo_pos.begin(),coo_pos.end(),sort_desc);
    cal(coo_pos);
    cal(coo_neg);
    cout<<result;
    return 0;
}
