
def binarySearch(arr,l,r,x):
    while l<=r:
        mid = l+(r-1)//2
        print("l: ", l)
        print("r: ", r)
        print(mid)
        if arr[mid]==x:
            return mid
        elif arr[mid]<x:
            l = mid + 1
        else:
            r = mid - 1
    
    return -1

arr = [2, 3, 4, 10, 40,90,110]
x = 2

result = binarySearch(arr, 0, len(arr)-1, x)

if result != -1:
    print("exists at {}".format(result))
else:
    print("not exists")
