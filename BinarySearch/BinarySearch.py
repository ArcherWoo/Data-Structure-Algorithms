def BinarySearch(arr, data):

	start = 0
	end = len(arr) - 1

	while start <= end:
		mid = start + ((end - start)>>1)
		if arr[mid] > data:
			end = mid - 1
		elif arr[mid] < data:
			start = mid + 1
		else:
			return mid

	return -1


if __name__ == '__main__':
	
	arr = [1,2,3,4,5,6]

	# print(len(arr))

	data = 6

	print(BinarySearch(arr,data))
