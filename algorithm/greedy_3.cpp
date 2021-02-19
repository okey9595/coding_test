#include <bits/stdc++.h>
using namespace std;

int calculate(int &a, int &b,int &c);

int main(){
    int N,K;
    int count =0;
    cin >> N >> K;

   int tmp = calculate(N, K, count); 
   cout <<count;
}

int calculate(int &a, int &b,int &c){ //a = N, b = K, c = count

    if(a > b){
        while(a% b != 0){
            a--;
            c++;
        }
        a = a/b;
        c++;        
    }
    else{
        while(a !=1){
            a--;
            c++;
            return 0;
        }
    }

    int tmp =calculate(a, b , c);
    
}