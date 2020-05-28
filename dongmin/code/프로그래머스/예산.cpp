/*
 * 예산.cpp
 * 
 * input: 
 * budgets= 각 지방에서 요청하는 예산이 담긴 배열 
 * M= 총 예산
 * ( 3 <= budgets 배열의 size <= 100000
 *   1 <= 각 지방에서 요청하는 예산 <= 100000
 *   budgets의 size <= 총 예산 M <= 1000000000 )
 * 
 * output: 정해진 총액 이하에서 가능한 한 최대의 총 예산을 만드는 상한액
 * 
 * [상한액을 어떻게 정할 것인가?] 
 * budgets 배열을 순환하며 => 무조건 해야하는 과정
 * 상한액 key 값에 대해 총 예산이 넘는지 확인한다.
 * 
 * Q1.[상한액 key 값을 어떤 값에서부터 시작할 것인가?]
 * Q2.[상한액을 어떤 방식으로 결정할 것인가?]
 */

#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

/*
 * solution1) brute-force <- Q2
 * key 값을 budgets의 max 값부터 시작해서 하나씩 줄여가며 탐색한다. <- Q1
 * 
 * Analysis
 * Basic Operation: 각 budget 값과 key 값을 비교하는 연산
 * input size: budgets의 크기 n, 각 지방에서 요청하는 예산의 최대값 b
 * 
 * Worst-case time complexity W(n)
 * - key 값이 1이어야만 하는 경우 worst case가 발생한다.
 * - W(n) = n * b  -> non-linear (pseudo-linear)
 * - input 범위에 의해 n * b <= 10000000000
 *   최대 100억의 basic operation을 계산해야한다. --> inefficient
 */
int bruteForce(vector<int> budgets, int M) {
    int n = budgets.size();

    // 총 예산 M의 범위가 100억까지 이므로 21억까지 표현 가능한 int는 overflow가 발생한다.
    long long sum = 0;
    int key = budgets[0];
    // 모든 요청이 배정될 수 있는 경우에는 요청한 금액을 그대로 배정한다.
    for (auto budget: budgets) {
        if(key < budget) 
            key = budget;
        sum += budget;
    }
    if (sum <= M) {
        return key;
    }

    // sum > M인 경우 특정 지방의 예산들이 허용할 수 없는 범위이므로 max에서 상한액을 줄여나가야 한다.
    key--;
    while(true) {
        sum = 0;
        for (auto budget: budgets) {
            if (budget > key)
                sum += key;
            else 
                sum += budget;
        }
        if (sum <= M) {
            break;
        }
        key--;
    }
    return key;
}

/*
 * solution2) Divide and Conquer <- Q2
 * 비슷한 더 작은 형태의 문제로 나눌 수 있는가?
 * input size를 줄여야 하는데 budgets의 크기를 줄일 수는 없다.
 * 예산값의 범위가 대상이 되는데
 * 
 * 상한값을 탐색하는 범위를 줄여가며 탐색하는 접근법
 * Analysis
 * Basic Operation: 각 budget 값과 key 값을 비교하는 연산
 * input size: budgets의 크기 n, 탐색하는 범위의 크기 b
 * T(n,b) = n * log(b)
 */
int divideConquer(vector<int> budgets, int M) {
    int key = 0;
    int n = budgets.size();
    long long sum = 0;

    sort(budgets.begin(), budgets.end());

    for(auto budget:budgets){
        sum+=budget;
    }
    if(sum <= M) return budgets[n-1];
  
    int left = 1;
    int right = budgets[n-1];
    int k = (left+right)/2;
    // Binary Search
    while(true) {
        sum = 0;
        for (auto budget:budgets) {
            budget >= k?(sum+=k):(sum+=budget);
        }
    
        if (sum < M) {
            // 오른쪽 탐색
            left = k;
        }
        else if (sum > M){
            // 왼쪽 탐색
            right = k;
        }
        else {
            // 정확히 일치하면 반환
            key = k;
            break;
        }
        
        k=(left+right)/2;
        if(right-left == 1)
            return left;
    }
    
    return key;
}

/*
 * solution3) Dynamic Programming (bottom-up approach)
 * look-up table을 만든다.
 * 몇 차원 array?
 * -> 1-dimensional array
 * key 값이 k일 때, 예산 총액 : dp[k]
 * => 의미있는가?
 * => look-up table을 참조할 필요가 없는 탐색 절차다. 의미 없음
 */
