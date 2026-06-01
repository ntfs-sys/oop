import std;
int main(){
	int number = 0;
	std::cin >> number;
	std::string result;
	int digit3 = number /100, digit2 = number /10 % 10, digit1 = number %10 ;
	switch(digit3){
		case 0:
			break;
		case 1:
			result += "1";
			break;
		case 2:
			result += "2";
			break;
		case 3:
			result += "3";
			break;
		case 4:
			result += "4";
			break;
		case 5:
			result += "5";
			break;
		case 6:
			result += "6";
			break;
		case 7:
			result += "7";
			break;
		case 8:
			result += "8";
			break;
		case 9:
			result += "9";
			break;
	} //too bored to write it in nano
	std::println("{}", result);
	return 0;	
}
