import sys

d = [10,30,5,60]
# [10, 30][30 5][5 60]인데 중첩되는 부분을 생략합니다.
M = [[0 for x in range(4)] for y in range(4)]
# dp를 위한 2차원 배열을 만듭니다.
# 이 때, d의 size만큼 만들어 줍니다.

# 자기자신이랑 곱은 생각할 필요가 없어서
# 안쪽 loop에서 diag를 빼주고, 그 뒤(j)부터 처리해줍니다..
for diag in range(1,len(d)):
    for i in range(1, len(d)-diag):
        j = i + diag
        M[i][j] = sys.maxsize
        for k in range(i,j):
            M[i][j]=min(M[i][j], M[i][k] + M[k+1][j] + d[i-1]*d[k]*d[j])
            # 가장 우측 d의 곱은 끊은 부분과 첫 행 끝열을 곱해주는 것(공통적으로 계산해야할 부분)
            # k의 범위를 i에서 j까지 순회시키면서
            # 최소가 되는 k가 결국 M[i][j]에 들어가게 됩니다.
print(M[1][3])
# M[1][3] = M[1][k] + M[k+1][3] 이런식으로...
