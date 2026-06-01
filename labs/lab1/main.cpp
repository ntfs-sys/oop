import std;

int main(){
	
	std::println("--------------------\n\
      LW: 1\n\
   Group: 6112\n\
  Author: Kirill Rezepkin\n\
  Option: 21\n\
--------------------");

	std::println("Check whether all the elements of the sequence are odd.");
	std::print("Enter the number of sequence elements:");
	int amount = 0;
	while(true){
		std::cin >> amount;
		if(amount>0){
			break;
		}
		std::println("You cant enter that amount of numbers");
	}
	std::println("Enter the sequence elements:");
	bool is_div2 = 1;
	for(int i = 0; i < amount; i++){
		int argument = 0;
		std::cin >> argument;
		is_div2 *= argument%2==1;
	}

	std::println("Inputed integers is odd?\n {}", is_div2);

  return 0;
	
}