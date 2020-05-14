#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    vector<int> result;
    int length = triangle.size();
    
    int dp[1001][1001] = {0};
    dp[0][0] = triangle[0][0];
    
    for(int i = 1; i<triangle.size(); i++){
        for(int j = 0; j<=i; j++){
            dp[i][j] = max(dp[i-1][j],dp[i-1][j-1] )+ triangle[i][j];
        }
    }
    for(int i = 0; i<length; i++){
        result.push_back(dp[length-1][i]);
    }
    
    sort(result.begin(), result.end());
    
    //answer = length;
    answer = result[length-1];
    return answer;
}