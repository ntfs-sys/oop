import std;
int main(){
	int number = 321;
	std::cin >> number;
	int multiply =1;
	multiply *= number / 100;
	multiply *= number / 10 % 10;
	multiply *= number % 10;

	int summ = 0;
	summ += number / 100;
	summ += (number / 10) % 10;
	summ += number % 10;
	std::println("{}: mult:{}, summ:{}\n",number,  multiply, summ);
	return 0;
}
