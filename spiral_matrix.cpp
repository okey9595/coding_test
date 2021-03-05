//spiral matrix 구현

#include <bits/stdc++.h>
using namespace std;

int dx[]={1,0,-1,0};          // 회전하는 방향을 좌표로 나타냄
int dy[]={0,1,0,-1};     

int main(){
    int n;
    int count = 1;   //배열 안에 들어가는 수
    cin>> n;
    cout<<"Input : n = "<<n <<endl;
    int value[n][n]={0};   //방문 여부 확인하는 2차배열 초기화
    int spiral[n][n] = {0}; //matrix 초기화
    int a =0,b=0;           //a : 행 , b: 열 
    int i =0;               //회전 방향;

    //if(n==1)cout<<"Ouput : 1";

    //처음 규칙 없는 3가지를 위해 추가
    for(int f = 0;f<3;f++){             //규칙 없는 처음 3번 실행 
        for(int j =0;j<n;j++){
            spiral[a][b] = count;
            value[a][b] = 1;
            b += dx[i];
            a += dy[i];
            count++; 
        }
        count --; b -= dx[i]; a -= dy[i]; i++;
    }
    count++;
    while(count <= (n*n)){             //규칙 있는 것 실행
                
        b += dx[i];  a += dy[i]; 
        while(value[a][b] == 0){
            spiral[a][b] = count;
            value[a][b] = 1;
            b += dx[i];
            a += dy[i];

            count++;                
        }
        b -=dx[i];             
        a -= dy[i];
        i++;
        if(i%4==0) i =0;
    }
    
    cout<< "output  " <<endl;
    for(int r =0;r<n;r++){
        for(int c=0;c<n;c++){
            cout<<spiral[r][c] <<", "<<"\t";
        }
        cout<<endl;
    }
}