def get_longest_equal_sum_substring_len(s):
    n = len(s)
    sum = [[0 if i != j else int(s[i]) for j in xrange(n)] for i in xrange(n)]
    max_len = 0
    for substr_len in xrange(2, n+1):
        for i in xrange(0, n - substr_len + 1):
            right_end = i +  substr_len - 1
            left_end = right_end - substr_len/2
            sum[i][right_end] = sum[i][left_end] + sum[left_end + 1][right_end]
            if substr_len % 2 == 0 and sum[i][left_end] == sum[left_end + 1][right_end] \
                                   and substr_len > max_len:
                max_len = substr_len
    return max_len


print get_longest_equal_sum_substring_len('12345')
print get_longest_equal_sum_substring_len('123123')
print get_longest_equal_sum_substring_len('981812')
