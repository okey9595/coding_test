//큰수의 법칙(greedy 사용)

#include <iostream>
using namespace std;

struct value{        //제일 큰수와 그 다음 수 저장
    int first;
    int second;
};
value pick_fisrt_second(int *arr, int n);      //구조체를 사용하여 제일 큰 수와 그 다음 수 찾기
int add(int a, int b, int M, int K);           // 더하기 구하기

int main(){
    int N, M, K;
    value v;
    cin >> N >> M >> K;
    cout << endl;
    int *arr = new int[N];
    for(int i=0;i<N;i++)
        cin>>arr[i];
    v = pick_fisrt_second(arr, N);
    int ret = add(v.first,v.second,M, K);   
    cout<<ret;

}

value pick_fisrt_second(int *arr, int n){      //구조체를 사용하여 제일 큰 수와 그 다음 수 찾기
    value v;
    v.first = arr[0];
    v.second = arr[0];
    for(int i =1;i<n;i++)    //제일 큰 수 찾기
        if(v.first < arr[i])
            v.first = arr[i];

    for(int i =1; i<n;i++)  //두번 째 수 찾기
        if(v.second <arr[i]  &&  v.second<v.first )
            v.second = arr[i];

    return v;
}

int add(int first, int second, int M, int K){
    int sum =0;
    int tmp = K;
    if(M-K==0)
        sum+=first*K;
    else{
        for(int i=1;M-i*K-i > 0;i++){
            if(M-i*K-i < K)
                sum+=first*(M-i*K-i);
            sum += first*K;
            sum += second;
        }
        
    }
    
     return sum;
}


/*
#include <bits/stdc++.h>

using namespace std;

int n, m, k;
vector<int> v;

int main() {
    // N, M, K를 공백을 기준으로 구분하여 입력 받기
    cin >> n >> m >> k;

    // N개의 수를 공백을 기준으로 구분하여 입력 받기
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }

    sort(v.begin(), v.end()); // 입력 받은 수들 정렬하기
    int first = v[n - 1]; // 가장 큰 수
    int second = v[n - 2]; // 두 번째로 큰 수

    // 가장 큰 수가 더해지는 횟수 계산
    int cnt = (m / (k + 1)) * k;
    cnt += m % (k + 1);

    int result = 0;
    result += cnt * first; // 가장 큰 수 더하기
    result += (m - cnt) * second; // 두 번째로 큰 수 더하기

    cout << result << '\n'; // 최종 답안 출력
}*/