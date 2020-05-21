# 단순 for문을 이용하여 Fibonacci수 구하기
# 시간복잡도는 for문이 한번 반복하기에 O(n)

# def fibo(n):    
#     first_num, second_num = 0, 1
#     if n < 2:
#         return n

    
#     for i in range(n-1):
#         first_num, second_num = second_num ,first_num + second_num
         
#     return second_num


# for n in range(1, 20):
#     print(n, fibo(n))





#Memoization - data in Array
# Look like DP, 낭비 최소화


# def fibo(index):
#     fib = [1,1]
#     if index == 1 or index ==2:
#         return 1
#     else :
#         for i in range(2, index):
#             fib.append(fib[i-1] + fib[i-2])

#         return fib

# print(fibo(10))




# Matrix Operation
# time complexity = O(log n) -> but need a some part

# import numpy as np # why use np???? -> for Matrix operation

# Fibo = np.matrix([1,1][1,0])
# (Fibo**5)[0,1]

# | Fibo(n+1) Fibo(n)   |
# | Fibo(n)   Fibo(n-1) |