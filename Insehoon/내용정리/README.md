# Algorithm time Complexity

## binary search
T(n) = logn

## merge sort
T(n) = divide complexity + conquer complexity + combine
      = ? + T(n/2) + T(n/2) + combine
      = ? + 2*T(n/2) + n/2 + n/2 -1
      = 0 + 2T(n/2) + (n-1)
      = 2T(n/2) + n-1 <= 2T(n/2) + n
      = 2(2T(n/4) + n/2) + n = 4T(n/4) + 2n
      = 8T(n/8) + 3n ...... recurrence
      = 2^k * T(n/2^k) + k*n   (n = 2^k)
      = n * T(n/n) + logn*n
      = n* T(1) + nlog(n)
      = nlog(n)


## quick sort
* Best-case 
T(n) = Divide + Conq. +Combine
      = (n-1) + T(n/2) + T(n/2) + 0 
      = (n-1) + 2*T(n/2)
      = 2*T(n/2) +n
      = 2^k * T(n/2^k) + kn   (2^k = n)
      = nT(1) + logn*n = nlogn

* Worst-case 
T(n) = Divide + Conq. +Combine
      = (n-1) + T(left) + T(right) + 0 
      = (n-1) + T(n-1)
      = T(n-2) + (n-2) + (n-1)  계속 반복
      = T(n-3) + (n-3) + (n-2) + (n-1)
      = n(n-1)/2 <= O(n^2)

## 참고 사이트
* 이분탐색(Binary Search) 예시문제
<https://programmers.co.kr/learn/courses/30/lessons/43237>

* Dynamic programming 피보나치 예시문제
<https://www.acmicpc.net/problem/2748>

* 이항계수 예시문제
<https://www.acmicpc.net/problem/11051> 
dp로도 풀어보고 재귀로도 풀어보기 
ex) 파스칼 삼각형

* Dynamic programming 예시문제1 정수삼각형
<https://programmers.co.kr/learn/courses/30/lessons/43105>
