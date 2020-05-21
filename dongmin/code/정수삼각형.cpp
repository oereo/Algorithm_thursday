/*
 * 정수삼각형.cpp
 * 
 * input: 
 * triangle= 삼각형의 정보를 이차원 배열로.
 * (1 <= 삼각형의 높이 <= 500, 0 <= 삼각형의 각 정수 <= 9999)
 * 
 * output: 거쳐간 숫자의 최댓값
 * 
 * [어떻게 지나갈 것인가] 
 * root에서부터 대각선 방향으로 내려오며 합을 누적해나간다.
 * 그리고 leaf 노드에 다다르면 합을 비교한다.
 * 
 */

#include <string>
#include <vector>
#include <algorithm>

using namespace std;
/*
 * solution1)  brute force
 * root에서부터 dfs로 모든 경우를 탐색하며 합을 비교한다.
 * 물론 visited로 방문 여부를 체크할 필요가 없다.
 * 
 * Analysis
 * Basic Operation: 각 경로의 누적합을 비교하는 연산
 * Input size: 삼격형의 높이 h
 * Time Complexity:
 * leaf 노드를 제외한 모든 노드에서 2가지 경우가 발생한다.
 * T(h) = 2^((h-1)(h-2)/2) < O(2^(h^2)) ===> too bad
 * 노드를 담을 스택 배열의 공간 복잡도도 좋지 않다.
 */

void BFgetMax(vector<vector<int> >& triangle, int row, int col, int& sum, int& max) {
    sum += triangle[row][col];
    if(max < sum) {
        max = sum;
    }
    if(row < triangle.size()-1) {
        BFgetMax(triangle, row+1, col, sum, max);
        sum -= triangle[row+1][col];
        BFgetMax(triangle, row+1, col+1, sum, max);
        sum -= triangle[row+1][col+1];
    }
}

int bruteForce(vector<vector<int> > triangle) {
    int sum = 0;
    int max = 0;
    BFgetMax(triangle, 0, 0, sum, max);
    return max;
}

/* [WORNG] 각 삼각형을 떼어서 생각할 수 없다.
 * solution2) Divide and Conquer
 * 비슷한 더 작은 형태의 문제로 나눌 수 있는가?
 * input size 삼각형의 높이를 더 작은 형태로 나눠야한다.
 * 삼각형을 반으로 나누어 각 삼각형의 최대값을 구하여 합한다.
 * 
 * Analysis
 * Basic Operation: 각 경로의 누적합을 비교하는 연산
 * Input size: 삼격형의 높이 h
 * 삼각형을 반으로 나누면 절반 크기의 삼각형 하나와 절반 높이를 갖는 밑둥 하나가 생긴다.
 * 밑둥은 그 절반 크기의 삼각형이 h/2 개만큼으로 이루어져있다.
 * T(h) = divide + conquer + combine
 * T(h) = [divide]theta(0) + [conquer]T(h/2) + (h/2+1) * T(h/2) + [combine](h/2) <= h*T(h/2)
 * T(h) = O(h^log(h))
 */
void DCgetMax(vector<vector<int> >& triangle, int row, int col, int endh, int& sum, int& max) {
    sum += triangle[row][col];
    if(max < sum) {
        max = sum;
    }
    if(row < endh-1) {
        DCgetMax(triangle, row+1, col, endh, sum, max);
        sum -= triangle[row+1][col];
        DCgetMax(triangle, row+1, col+1, endh, sum, max);
        sum -= triangle[row+1][col+1];
    }
}

int divideConquer(vector<vector<int> > triangle) {
    int h = triangle.size(), sum;
    int topmax = 0;
    vector<int> bottommax;

    sum = 0;
    DCgetMax(triangle, 0, 0, h/2, sum, topmax);
    for(int i = 0; i < h/2+1; i++) {
        sum = 0;
        int bmax = 0;
        DCgetMax(triangle, h/2+1, i, h, sum, bmax);
        bottommax.push_back(bmax);
    }
    return topmax + *max_element(bottommax.begin(), bottommax.end());
}

/*
 * solution3) Dynamic Programming (bottom-up approach)
 * 중복되는 연산이 너무 많다. 
 * 임의의 노드에서의 누적합의 최대는 최대가 보장된 그 인접 부모 노드, 둘 중 큰 부모 노드에 그 노드의 값을 더한 값이 된다.
 * 
 * Analysis
 * T(h) = O(h^2)
 */
int dynamicProgramming(vector<vector<int> > triangle) {
    int h = triangle.size();
    vector<vector<int> > dp;
    dp.assign(h, vector<int>());
    for(int i = 0; i<h; i++) {
        dp[i].assign(triangle[i].size(), 0);
    }

    dp[0][0] = triangle[0][0];
    dp[1][0] = dp[0][0] + triangle[1][0];
    dp[1][1] = dp[0][0] + triangle[1][1];
    for(int i = 2; i<h; i++) {
        dp[i][0] = dp[i-1][0] + triangle[i][0];
        dp[i][i] = dp[i-1][i-1] + triangle[i][i];
        for(int j = 1; j<i; j++) {
            dp[i][j] = triangle[i][j] + (dp[i-1][j-1]>dp[i-1][j]?dp[i-1][j-1]:dp[i-1][j]);
        }
    }
    return *max_element(dp[h-1].begin(), dp[h-1].end());
}

/*
 * 최적화 가능?
 */