import std;
int main(){
	int start = 0;
	std::cin >> start;
	int days = 0;
	std::cin >> days;
	days += start;
	std::string day = {0};
	switch (days / 7 % 7) {
	case 0:
		day += "monday";
		break;
	case 1:
		day += "tuesday";
		break;
	case 2:
		day += "wednesday";
		break;
	case 3:
		day += "thursday";
		break;
	case 4:
		day += "friday";
		break;
	case 5:
		day += "saturday";
		break;
	case 6:
		day += "sunday";
		break;
	}
	std::println("{}", day);
	return 0;
}
