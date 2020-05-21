def cmm(i, j):
    if i==j:
        return 0
    else:
        return min(cmm(i,k)+cmm(k+1,j)+R[i]*R[k]*R[j])

# 'i'th matrix size = R[i-1]*R[i]
