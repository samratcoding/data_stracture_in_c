def merge(arr, left, mid, right):
    n1 = mid - left + 1  # Size of left sub-array
    n2 = right - mid     # Size of right sub-array

    leftArr = [0] * n1
    rightArr = [0] * n2

    # Copying the left half into leftArr[]
    for i in range(0, n1):
        leftArr[i] = arr[left + i]

    # Copying the right half into rightArr[]
    for i in range(0, n2):
        rightArr[i] = arr[mid + 1 + i]

    # Merge the temp arrays back into arr[left..right]
    i = 0     # Initial index of first sub-array
    j = 0     # Initial index of second sub-array
    k = left  # Initial index of merged sub-array

    while i < n1 and j < n2:
        if leftArr[i] <= rightArr[j]:
            arr[k] = leftArr[i]
            i += 1
        else:
            arr[k] = rightArr[j]
            j += 1
        k += 1

    # Copy the remaining elements of leftArr[], if any
    while i < n1:
        arr[k] = leftArr[i]
        i += 1
        k += 1

    # Copy the remaining elements of rightArr[], if any
    while j < n2:
        arr[k] = rightArr[j]
        j += 1
        k += 1

def mergeSort(arr, left, right):
    if left < right:
        mid = (left + right) // 2

        # Recursively sort the first and second halves
        mergeSort(arr, left, mid)
        mergeSort(arr, mid + 1, right)

        # Merge the sorted halves
        merge(arr, left, mid, right)

def printArray(arr):
    for i in arr:
        print(i, end=" ")
    print()

if __name__ == "__main__":
    arr = [12, 11, 13, 5, 6, 7]
    arr_size = len(arr)

    print("Given array is")
    printArray(arr)

    mergeSort(arr, 0, arr_size - 1)

    print("\nSorted array is")
    printArray(arr)
