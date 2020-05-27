def partition(arr, l, h):
    i = l-1
    piv = arr[h]

    for j in range(l, h):
        if arr[j]<piv:
            i+=1
            arr[i],arr[j]=arr[j],arr[i]
            print(arr)

    arr[i+1],arr[h] = arr[h], arr[i+1]
    print(arr)
    print("pt end")
    print(i+1)
    return i+1

def quickSort(arr, l, h):
    if l<h:
        pi = partition(arr, l, h)
        quickSort(arr, l, pi-1)
        quickSort(arr, pi+1, h)
        print("qs end")

arr = [10, 7, 1, 8]
n = len(arr)
print("given arr: {}".format(arr))
quickSort(arr,0,n-1)
print("Sorted arr: {}".format(arr))
