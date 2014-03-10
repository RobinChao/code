def dutch_national_flag(arr):
	'''
	takes a string containg 3 type of chars, 'r', 'b', 'w'
	and sorts it in 'r* b* w*' order using one comparision 
	per element.
	'''
	arr = list(arr)
	lo = 0
	hi = len(arr) - 1
	curr = 0

	while(curr <= hi):
		if arr[curr] == 'r':
			arr[lo], arr[curr] = arr[curr], arr[lo]
			lo += 1
			curr += 1
		elif arr[curr] == 'b':
			arr[hi], arr[curr] = arr[curr], arr[hi]
			hi -= 1
		else:
			curr += 1

	return ''.join(arr)


arr = 'brrrrbbbbwbbbwrrrwwwwwbr'
print arr
print dutch_national_flag(arr)