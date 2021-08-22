#include<bits/stdc++.h>
using namespace std;
const int N=25,M=30;
double laplacian[N][N];
int n,m;
void input(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    int x,y;
    memset(laplacian,0,sizeof(laplacian));
    for(int i=1;i<=m;i++){
        cin>>x>>y;
        x-=1;y-=1;
        laplacian[x][x]+=1;//degree of x
        laplacian[y][y]+=1;//degree of y
        laplacian[x][y]=-1; 
        laplacian[y][x]=-1;        
    }
}

// int determinate(int matrix[N][N],int n){
//     if(n==2)return matrix[0][0]*matrix[1][1]-matrix[0][1]*matrix[1][0];
//     int submatrix[N][N];
//     int det=0;

//     for(int x=0;x<n;x++){
//         int sub_i=0;
//         for(int i=1;i<n;i++){
//             int sub_j=0;
//             for(int j=0;j<n;j++){
//                 if(j==x)continue;
//                 submatrix[sub_i][sub_j]=matrix[i][j];
//                 sub_j++;
//             }
//             sub_i++;
//         }
//         det+=pow(-1,x)*matrix[0][x]*determinate(submatrix,n-1);
//     }
//     return det;
// }
void show(double a[N][N]){
    cout<<"---------------"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<a[i][j]<<"   ";
        }
        cout<<"\n\n";
    }
}

int det(double a[N][N]){
    double result=1;
    n-=1;
    for(int x=0;x<n-1;x++){
        if(a[x][x]==0){
            int temp=INT_MIN;
            for(int k=x+1;k<n;k++){
                if(a[k][x]){
                    temp=k;
                    break;
                }
            }
            if(temp!=INT_MIN)swap(a[temp],a[x]);
            else continue;
        }
        for(int i=x+1;i<n;i++){
            double temp=a[i][x]/a[x][x];
            for(int j=x;j<n;j++){
                a[i][j]=a[i][j]-temp*a[x][j];
            }
        }
    }
    for(int i=0;i<n;i++)result*=a[i][i];
    return round(result);
}
int main(){
    input();
    int result=det(laplacian);
    cout<<result;
    return 0;
}

