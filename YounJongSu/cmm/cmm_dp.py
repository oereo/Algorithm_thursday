import sys

d = [10,30,5,60]
M = [[0 for x in range(4)] for y in range(4)]

for diag in range(1,4):
    for i in range(1, 4-diag):
        j = i + diag
        M[i][j] = sys.maxsize
        for k in range(i,j):
            M[i][j]=min(M[i][j], M[i][k]+M[k+1][j]+d[i-1]*d[k]*d[j])

print(M[1][3])
