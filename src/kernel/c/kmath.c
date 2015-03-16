
int32_t fastpow(int32_t base, uint32_t exp) {
	
	int32_t res = 1;
	
	for (uint32_t i = 0; i < exp; i++) {
		res *= base;
	}
	
	return res;
	
}

uint16_t signum(int32_t num) {
	
	if (num > 0) {
		return 1;
	} else if (num < 0) {
		return -1;
	}
	
	return 0;
	
}

