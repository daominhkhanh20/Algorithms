#include<bits/stdc++.h>
using namespace std;
#define N 32
int w,h;
int n;
int wi[N],hi[N];
bool result=false;
int arr[N][N];

void input(){
    cin>>h>>w>>n;
    for(int i=0;i<n;i++){
        cin>>hi[i]>>wi[i];
    }
}

void TRY(int index){
    if(result)return ;
    if(index==n){
        result=true;
        return ;
    }
    int exist=1;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(arr[i][j]==0){
                exist=1;
                for(int m=i;m<i+hi[index];m++){
                    if(m>=h){
                        exist=0;
                        break;
                    }

                    for(int n=j;n<j+wi[index];n++){
                        if(n>=w|| arr[m][n]==1){
                            exist=0;
                            break;
                        }
                    }
                    if(!exist) break;
                }

                if(exist){
                    for(int m=i;m<i+hi[index];m++){
                        for(int n=j;n<j+wi[index];n++){
                            arr[m][n]=1;
                        }
                    }
                    TRY(index+1);
                    for(int m=i;m<i+hi[index];m++){
                        for(int n=j;n<j+wi[index];n++){
                            arr[m][n]=0;
                        }
                    }

                }
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    TRY(0);
    if(result)cout<<1<<endl;
    else cout<<0<<endl;
    return 0;

}
