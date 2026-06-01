import std;
int main(){
	int year = 0;
	std::cin >> year;
	if((year % 4 == 0) * ((year % 100 !=0) + (year % 400 == 0))){
		std::println("366");
	}else{
		std::println("365");
	}
	return 0;
}
