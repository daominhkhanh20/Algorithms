#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
string s;
map<char,int>a;
#define N 10005
int x[N];
int k=0;
long long result;
vector<int>l;
int total=0;

bool check(int index_string,int index_list,int value){
    if(index_list==l.size()-1)return (total+value)==-k;
    int t=value;
    int cnt=0;
    for(int i=1;i<index_string;i++){
        t+=x[i];
        if(x[i]=1)cnt++;
    }
    if(t<0 || cnt>l.size()/2) return false;
    return true;
}


void TRY(int index){
    for(int i=-1;i<=1;i+=2){
        if(check(l[index],index,i)){
            x[l[index]]=i;
            total+=i;
            if(index+1==l.size()){
                result++;
                result=result%MOD;
                //show();
            }
            else if(index+1<l.size()){
                if(l.size()-1-index>=abs(-k-total))TRY(index+1);
            }
            total-=i;
            x[l[index]]=0;
        }
    }
}

int main(){
    cin>>s;
    a['(']=1;
    a[')']=-1;
    cin>>s;
    if(s.length()==0 || s.length()%2==1){
        cout<<0;
        return 0;
    }
    for(int i=0;i<s.length();i++){
        if(s[i]!='?'){
            k+=a[s[i]];
            x[i+1]=a[s[i]];
        }
        else l.push_back(i+1);
    }
    if(x[1]!=1 || x[s.length()]!=-1){
        cout<<0;
        return 0;
    }
    TRY(0);
    cout<<result;

}