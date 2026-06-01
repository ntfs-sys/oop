import std;
int main(){
	float a;
	int n;
	std::cin >> a >> n;
	for(int i = 1; i <= n; i++){
		std::println("{}", std::pow(a,i));
	}
	return 0;
}
