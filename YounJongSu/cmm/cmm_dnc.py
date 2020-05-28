
# 행렬 곱 연산이 최소가 되는 곱 순서
# k: 괄호 위치(divide)

def cmm(i, j):
    if i==j:
        return 0
    else:
        return min(cmm(i,k)+cmm(k+1,j)+R[i]*R[k]*R[j])

# 'i'th matrix size = R[i-1]*R[i]
