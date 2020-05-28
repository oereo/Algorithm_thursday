# optimized DP(pascal triangle)

def binoCoef(n, k):

    C = [0 for i in range(k+1)]
    C[0] = 1

    for i in range(1, n+1):
        j = min(i, k)
        while j>0:
            C[j] = C[j] + C[j-1]
            print(i, j, C)
            j-=1
        print()
    return C[k]

print(binoCoef(5, 2))