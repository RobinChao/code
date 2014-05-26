def get_primes(lo, hi):
  arr = range(0, hi+1)
  delta = p = 2
  while p < hi:
    while p + delta <= hi:
      p += delta
      arr[p] = -1
    p = delta + 1
    
    while p <= hi and arr[p] == -1:
      p += 1
    delta = p

  primes = []
  for i in xrange(lo, hi+1):
    if arr[i] != -1:
      primes.append(arr[i])
      # print arr[i]
  return primes

if __name__ == '__main__':
  N = input()
  for x in xrange(N):
    values = raw_input().split()
    lo = int(values[0])
    hi = int(values[1])
    print get_primes(lo, hi)
  
