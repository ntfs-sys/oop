import std;
int main(){
	int number = 0;
	std::cin >> number;
	bool increase = ((number / 100) < (number /10 % 10)) * ((number /10 %10) < (number %10));
	std::println("{}`s numbers increase: {}", number,  increase);
	return 0;
}
