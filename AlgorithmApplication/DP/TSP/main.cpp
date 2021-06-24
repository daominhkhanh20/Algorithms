#include<bits/stdc++.h>
using namespace std;
#define ui unsigned int
#define N 100000
int n;
int c[N][N];
int f[N][N];
ui addElement(ui S,int i){
    return S|(1<<i);
}

ui removeElement(ui S, int i){
    return S|(~(1<<i));
}
/*
 *P(i,S) tim hanh trinh ngan nhat tu dinh i tham tat 
 ca cac dinh trong tap S
 F(i,S):do dai hanh trinh ngan nhat

F(i,S)=min(F[j,S/{j}]+c[i][j]) j thuoc S
 * 
 * */

bool constain(ui S,int i){
    if(S&(1<<i))return true;
    return false;
}
int TSP(int i, ui S){
    if(S==0){
        f[i][S]=c[i][S];
    }
    else{
        if(f[i][S]==-1){
            f[i][S]=INT_MAX;
            for(int j=1;j<n;j++){
                if(constain(S,j)){
                    ui Sj=removeElement(S,j);
                    f[i][S]=min(f[i][S],c[i][j]+TSP(j,Sj));
                }
            }
        }
    }
    return f[i][S];
}
