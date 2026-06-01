import std;
int main(){
	int number = 0;
	std::cin >> number;
	std::string result;
	if(number % 2 == 0){
		result +="odd ";
	}else{
		result += "nodd ";
	}
	if(number / 100 > 0){
		result += "three";
	}else{
		if(number / 10 > 0){
			result += "two";
		}else{
			result += "one";
		}
	}
	result += "-digit number";
	std::println("{}", result);
	return 0;
}
