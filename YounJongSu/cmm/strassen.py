# 곱 순서 최적화가 아니라 행렬 곱 자체를 최적화
# 모든 입력 행렬을 정사각행렬 형태로 통일 시킨다.
# 각 행렬들을 네개의 정사각행렬로 나눈다.
# 총 8번의 곱셈
# 행렬 곱을 다르게 표현 -> 7번의 곱셈과 10번의 덧셈



def mkMatrix(x):  # 생성 (각 요소의 value는 행번호+열번호 값)
    for i in range(0, n):
        row = []
        for j in range(0, n):
            row.append(i + j)
        x += [row]

def printMatrix(mat):  # 출력
    for i in range(len(mat)):
        print(mat[i])
    print('')

def sumMatrix(A, B):  # 덧셈
    answer = [[] for j in range(len(A))]
    for i in range(len(A)):
        for x in range(len(A[i])):
            answer[i].append(A[i][x] + B[i][x])
    return answer

def subMatrix(A, B):  # 뺄셈
    answer = [[] for j in range(len(A))]
    for i in range(len(A)):
        for x in range(len(A[i])):
            answer[i].append(A[i][x] - B[i][x])
    return answer

def mulMatrix(A, B):  # 곱셈
    row = []
    for i in range(len(A)):
        col = []
        row.append(col)
        for j in range(len(A[0])):
            tmp = 0
            for k in range(len(A[0])):
                tmp += A[i][k] * B[k][j]
            col.append(tmp)
    return row

def divMatrix(M):  # 행렬 4분할
    num = int(len(M[0])/2)
    M11 = [[0]*num for i in range(num)]
    M12 = [[0]*num for i in range(num)]
    M21 = [[0]*num for i in range(num)]
    M22 = [[0]*num for i in range(num)]
    for i in range(0,num):
        for j in range(0,num):
            M11[i][j] = M[i][j]  # 좌 상단행렬
            M12[i][j] = M[i][j + num]  # 우 상단행렬
            M21[i][j] = M[i + num][j]  # 좌 하단행렬
            M22[i][j] = M[i + num][j + num]  # 우 하단행렬
    return M11, M12, M21, M22

def merMatrix(M11, M12, M21, M22):  # 행렬 통합
    num = int(len(M11[0]))
    M=[[0]*(num*2) for i in range(num*2)]
    for i in range(num):
        for j in range(num):
            M[i][j] = M11[i][j]  # 좌 상단행렬
            M[i][j + num] = M12[i][j]  # 우 상단행렬
            M[i + num][j] = M21[i][j]  # 좌 하단행렬
            M[i + num][j + num] = M22[i][j]  # 우 하단행렬
    return M

def strassen(n, A, B):
    newRow = n / 2
    if n <= 2:
        C = mulMatrix(A, B)
        return C
    else:
        A11 = []
        A12 = []
        A21 = []
        A22 = []
        B11 = []
        B12 = []
        B21 = []
        B22 = []
        C11 = []
        C12 = []
        C21 = []
        C22 = []
        M1 = []
        M2 = []
        M3 = []
        M4 = []
        M5 = []
        M6 = []
        M7 = []
        tempA = []
        tempB = []
        A11, A12, A21, A22 = divMatrix(A)
        B11, B12, B21, B22 = divMatrix(B)
        tempA = sumMatrix(A11, A22)
        tempB = sumMatrix(B11, B22)
        M1 = strassen(newRow, tempA, tempB)
        tempA = sumMatrix(A21, A22)
        M2 = strassen(newRow, tempA, B11)
        tempB = subMatrix(B12, B22)
        M3 = strassen(newRow, A11, tempB)
        tempB = subMatrix(B21, B11)
        M4 = strassen(newRow, A22, tempB)
        tempA = sumMatrix(A11, A12)
        M5 = strassen(newRow, tempA, B22)
        tempA = subMatrix(A21, A11)
        tempB = sumMatrix(B11, B12)
        M6 = strassen(newRow, tempA, tempB)
        tempA = subMatrix(A12, A22)
        tempB = sumMatrix(B21, B22)
        M7 = strassen(newRow, tempA, tempB)
        tempA = sumMatrix(M1, M4)
        tempB = sumMatrix(tempA, M7)
        C11 = subMatrix(tempB, M5)
        C12 = sumMatrix(M3, M5)
        C21 = sumMatrix(M2, M4)
        tempA = sumMatrix(M1, M3)
        tempB = sumMatrix(tempA, M6)
        C22 = subMatrix(tempB, M2)
        C = merMatrix(C11, C12, C21, C22)
        return C

n = int(input("정사각 행렬의 크기를 입력하시오:"))
a = []  # 피연산 행렬1
b = []  # 피연산 행렬2
c = []  # 결과 행렬
mkMatrix(a)
mkMatrix(b)
printMatrix(a)
printMatrix(b)
c = strassen(n, a, b)
printMatrix(c)

