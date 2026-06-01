import std;
int main(){
	int x1, y1, x2, y2;
	x1 = y1 = x2 = y2 = 0;
	std::cin >> x1 >> y1 >> x2 >> y2;
	bool allow_move = (x1 == x2)(y1 != y2) + (x1 != x2)(y1 == y2);
	std::println("{}", allow_move);
	return 0;
}
