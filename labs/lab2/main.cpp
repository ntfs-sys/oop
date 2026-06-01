import std;
import odd_vector;
int main(){
	std::println("--------------------\n\
      LW: 2\n\
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
	std::println("Input 0 for random input, or 1, for manual input:");
	int input = 0;
	std::cin >> input;
	std::vector<int> v;
	if(!input){
		std::println("==random==");
		v = input_rand_vector(amount);
		print_vector(v);
		std::println("==========");
	}else{	
		std::println("==manual==");
		std::println("Enter the sequence elements:");
		v = input_vector(amount);		
		std::println("==========");
		print_vector(v);
	}
	std::println("Inputed integers is odd?\n {}", v_odd(v));
  return 0;	
}