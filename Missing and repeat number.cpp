#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int N,i;
    int missing, twotimes;
    cin >> N;
    int A[N];
    int B[N] = {0};
    cout<<B[0]<<endl;
    int actualsum, sum;
    actualsum = N*(N+1)/2;
    cout<<actualsum;
    for(i=0;i<N;i++){
        cin >> A[i];
        sum +=A[i];
        B[A[i]-1]++;
        if(B[A[i]-1] == 2){
            twotimes = A[i];
        }
    }

    missing = twotimes - sum + actualsum;
    cout << "[" << twotimes << "," << missing << "]";
    return 0;
}
