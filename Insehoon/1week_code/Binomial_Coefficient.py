def Bino(n, k):
    DP = [[0 for x in range(k+1)] for x in range(n+1)]

    for i in range(1, n+1):
        for j in range(min(i,k)+1):  # important!!! -> min down time complexity
            if j == 0 or i == j:     # side
                DP[i][j] = 1

            else:
                DP[i][j] = DP[i-1][j-1] + DP[i-1][j]

    return DP[n][k]

print(Bino(7,3))    # Time complexity O(n*k)
