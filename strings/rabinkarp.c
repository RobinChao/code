#include <stdio.h>
#include <math.h>

#define ROLL_HASH 		1
#define NO_ROLL_HASH	0
#define PRIME_MOD		67108859

int hash(const char* string, int lo, int hi);

// hash(s) = s[0]*31^(n-1) + s[1]*31^(n-2) + ... + s[n-1]
int hash(const char* string, int lo, int hi) {
	int hash = 0;
	int i = lo;
	while (i <= hi) {
		hash = ((hash << 5) - hash + string[i]) % PRIME_MOD;
		++i;
	}
	return hash;
}


int rhash(const char* string, int lo, int hi, int roll, int prev_hash) {
	int h = 0;
	int i;

	if (roll == NO_ROLL_HASH) {	
		h = hash(string, lo, hi);
	}
	else {
		h = prev_hash;

		int term_1 = string[lo-1];
		for(i = lo+1; i <= hi-lo; ++i)
			term_1 = ((term_1 << 5) - term_1) % PRIME_MOD;

		printf("term_1 = %d\n", term_1);

		h = (h - term_1) % PRIME_MOD;

		h = ((h << 5) - h + string[hi]) % PRIME_MOD;
	}
	
	return h;
}

int main(void) {
	char str[] = "abcabababcdef";
	int lo = 0, hi = 0, roll = NO_ROLL_HASH, prev_hash = 0;
	// printf("hash('%s', %d, %d, %s, %d) = %d\n", str, 
	// 											lo, 
	// 											hi, 
	// 											roll ? "ROLL_HASH" : "NO_ROLL_HASH", 
	// 											prev_hash, 
	// 											hash(str, lo, hi, roll, prev_hash));
	// lo = 2; hi = 2; roll = NO_ROLL_HASH; prev_hash = 0;
	// printf("hash('%s', %d, %d, %s, %d) = %d\n", str, 
	// 											lo, 
	// 											hi, 
	// 											roll ? "ROLL_HASH" : "NO_ROLL_HASH", 
	// 											prev_hash, 
	// 											hash(str, lo, hi, roll, prev_hash));
	// lo = 0; hi = 1; roll = NO_ROLL_HASH; prev_hash = 0;
	// printf("hash('%s', %d, %d, %s, %d) = %d\n", str, 
	// 											lo, 
	// 											hi, 
	// 											roll ? "ROLL_HASH" : "NO_ROLL_HASH", 
	// 											prev_hash, 
	// 											hash(str, lo, hi, roll, prev_hash));
	// lo = 3; hi = 4; roll = NO_ROLL_HASH; prev_hash = 0;
	// printf("hash('%s', %d, %d, %s, %d) = %d\n", str, 
	// 											lo, 
	// 											hi, 
	// 											roll ? "ROLL_HASH" : "NO_ROLL_HASH", 
	// 											prev_hash, 
	// 											hash(str, lo, hi, roll, prev_hash));
	// lo = 1; hi = 1; roll = NO_ROLL_HASH; prev_hash = 0;
	// printf("hash('%s', %d, %d, %s, %d) = %d\n", str, 
	// 											lo, 
	// 											hi, 
	// 											roll ? "ROLL_HASH" : "NO_ROLL_HASH", 
	// 											prev_hash, 
	//											hash(str, lo, hi, roll, prev_hash));
	lo = 0; hi = 4; roll = NO_ROLL_HASH; prev_hash = rhash(str, lo, hi, roll, 0);
	lo = 1; hi = 5; roll = ROLL_HASH;
	printf("rhash('%s', %d, %d, %s, %d) = %d\n", str, 
												lo, 
												hi, 
												roll ? "ROLL_HASH" : "NO_ROLL_HASH", 
												prev_hash, 
												rhash(str, lo, hi, roll, prev_hash));
	lo = 1; hi = 5; roll = NO_ROLL_HASH; prev_hash = 0;
	printf("rhash('%s', %d, %d, %s, %d) = %d\n", str, 
												lo, 
												hi, 
												roll ? "ROLL_HASH" : "NO_ROLL_HASH", 
												prev_hash, 
												rhash(str, lo, hi, roll, prev_hash));
	
	lo = 2; hi = 5; roll = NO_ROLL_HASH; prev_hash = rhash(str, lo, hi, roll, prev_hash);
	lo = 3; hi = 6; roll = ROLL_HASH;
	printf("rhash('%s', %d, %d, %s, %d) = %d\n", str, 
												lo, 
												hi, 
												roll ? "ROLL_HASH" : "NO_ROLL_HASH", 
												prev_hash, 
												rhash(str, lo, hi, roll, prev_hash));
	lo = 3; hi = 6; roll = NO_ROLL_HASH; prev_hash = 0;
	printf("rhash('%s', %d, %d, %s, %d) = %d\n", str, 
												lo, 
												hi, 
												roll ? "ROLL_HASH" : "NO_ROLL_HASH", 
												prev_hash, 
												rhash(str, lo, hi, roll, prev_hash));
	// printf("\n\nhash = %d\n\n", hash("abababababab", 0, 11));
	return 0;
}