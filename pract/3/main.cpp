import std;

std::size_t invert_digits(std::size_t n){
	std::size_t result = 0;

	while (n > 0) {
		result *= 10;
		result += n % 10;
		n /= 10;
	}
	return result;
}

std::size_t add_right_digit(std::size_t n, std::size_t d) {
	return 10 * n + d;	
}

bool is_prime(std::size_t n){
	for(int i = 2; i < n; i++) {
		if (n % i == 0) {
			return 0;
		}
	}
	return 1;
}

std::size_t fact(std::size_t n) {
	if(n <= 1) {
		return 1;
	}
	return n * fact(n-1);
}
std::size_t gcd(std::size_t a, std::size_t b) {
	if ( b != 0 ) {
		return gcd(b, a % b);
	}
	return a;
}

std::size_t digit_summ(std::size_t number) {
	if (number == 0) {
		return 0;
	}
	return number % 10 + digit_summ(number / 10);
}