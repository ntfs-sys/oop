import std;
int main(){
	int sec = 0;
	std::cin >> sec;
	std::println("минут с последнего часа: {}\n", sec / 60 % 60);
	return 0;
}
