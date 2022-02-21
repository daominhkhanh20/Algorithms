#include<bits/stdc++.h>
using namespace std;
int n,r;
int sum;
void cal(vector<vector<pair<int,int>>>a,vector<bool>visit,vector<int>list,int start,int end,int count,int cost){
    visit[start]=true;

    for(int i=0;i<a[start].size();i++){
        int index=a[start][i].first;
        int w=a[start][i].second;
        if(index==end && count!=0) continue;
        else if(index==end && count==0){
            sum=min(sum,cost+w);
            break;
        }

        if(find(list.begin(),list.end(),index)!=list.end() && visit[index]==false){
            cost+=w;
            cal(a,visit,list,index,end,count-1,cost);
            if(count==1) break;
            cost-=w;
        }
    }
    visit[start]=false;
}
int main(){
    //freopen(".inp","r",stdin);
    cin>>n>>r;
    cin.ignore(1);
    vector<vector<pair<int,int>>>a(n+1);
    vector<bool>visit(n);
    for(int i=1;i<=n;i++){
        string s;
        getline(cin,s);
        stringstream str(s);
        string temp;
        int c=1;
        while(str>>temp){
            int k=stoi(temp);
            if(k!=0)a[i].push_back({c,k});
            c++;
        }
    }
    for(int i=0;i<r;i++){
        string s;
        fill(visit.begin(),visit.end(),false);
        getline(cin,s);
        sum=INT_MAX;
        int start,end;
        string temp;
        stringstream str(s);
        vector<int>list;
        while(str>>temp){
            list.push_back(stoi(temp));
        }
        if(list.size()==1){
            cout<<0<<endl;
            continue;
        }
        start=list[0];
        end=list[list.size()-1];
        if(list.size()==2){
            int j;
            for(j=0;j<a[start].size();j++){
                if(a[start][j].first==end){
                    cout<<a[start][j].second<<endl;
                    break;
                }
            }
            if(j==a[start].size())cout<<0<<endl;
            continue;
        }
        list.pop_back();
        list.erase(list.begin());
       cal(a,visit,list,start,end,list.size(),0);
        if(sum==INT_MAX)cout<<0<<endl;
       else cout<<sum<<endl;
    }
    return 0;
}