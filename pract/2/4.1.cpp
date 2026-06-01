import std;
int main(){
	int a = 1, b = 5;
	std::cin >> a >> b;
	for(int i = a; i <= b; i++){
		std::println("{}", i);
	}
	std::println("{}", b-a+1);
	return 0;
}
