import std;
import Character;
import gamelib;
import Earthmover;
import V_model;
import Angel;
import Something_wicked;


bool check_death(Character& ch){
    if (ch.get_health() <= 0) {
        std::println("{}{} defeated{}",
            color::red, ch.get_name(), color::reset);
    }
    return ch.get_health() <= 0;
}

void menu(Character& ch1, Character& ch2){
    std::println("{}{}{}:\n{}Health:{} {}  {}Armor:{} {}  {}CD:{} {}\n",
        color::red, ch2.get_name(), color::reset,
        color::yellow, color::reset, ch2.get_health(),
        color::cyan, color::reset, ch2.get_armor(),
        color::magenta, color::reset, ch2.get_use_skill());
    std::println("{}You ({}){}:\n{}Health:{} {}  {}Armor:{} {}  {}CD:{} {}\n",
        color::green, ch1.get_name(), color::reset,
        color::yellow, color::reset, ch1.get_health(),
        color::cyan, color::reset, ch1.get_armor(),
        color::magenta, color::reset, ch1.get_use_skill());
    std::println("{}========================================={}",
        color::blue, color::reset);
    std::println("{}1. Attack{}\n{}2. Use skill{} ({}{} to recharge{})\n",
        color::green, color::reset,
        color::yellow, color::reset,
        color::magenta, ch1.get_use_skill(), color::reset);
    int input = 0;
    input = input_int("Choose action (1-2):", 1, 2);
        switch (input) {
        case 1: {
            int dmg = ch1.deal_damage(ch2);

            std::println("{}{}{} hits {}{}{} for {}{}{} damage",
                color::green, ch1.get_name(), color::reset,
                color::red, ch2.get_name(), color::reset,
                color::yellow, dmg, color::reset);
            break;
        }
        case 2:
			if(ch1.activate_skill()){
				std::println("{}Skill activated{}",
					color::magenta, color::reset);
			}else{
				std::println("{}Wait for skill recharge, dummy, got your {} health {}",
					color::red, ch1.get_use_skill(), color::reset);
			}
            
            break;
        }
}


void play(Character& ch1, Character& ch2) {
	while (true){
		ch1.deactivate_skill();
		menu(ch1, ch2);
		if (check_death(ch2) || check_death(ch1)){
			break;
		}
		ch2.deactivate_skill();
		menu(ch2, ch1);
		if (check_death(ch2) || check_death(ch1)){
			break;
		}
	}


}

void menu_computer(Character& ch, Character& computer){
    if (computer.get_use_skill() > 0){
        computer.activate_skill();

        std::println("{}{}{} activated skill (armor {}{}, damage -{}{})",
            color::magenta, computer.get_name(), color::reset,
            color::cyan, computer.get_armor(), color::reset,
            color::yellow, computer.get_damage(), color::reset);
    } else {
        int dmg = computer.deal_damage(ch);

        std::println("{}{}{} hits you for {}{}{} damage (HP: {}{}{})",
            color::red, computer.get_name(), color::reset,
            color::yellow, dmg, color::reset,
            color::cyan, ch.get_health(), color::reset);
    }
}

void simulate(Character& ch, Character& computer){
	while (true){
		ch.deactivate_skill();
		menu(ch, computer);
		if (check_death(computer) || check_death(ch)){
			break;
		}
			computer.deactivate_skill();
		menu_computer(ch, computer);
		if (check_death(computer) || check_death(ch)){
			break;
		}
	}
}

std::unique_ptr<Character> create_custom_character() {
    std::string name = input_string("Enter name:");

    int hp       = input_int("Enter HP (1-1000):", 1, 1000);
    int armor    = input_int("Enter armor (0-100):", 0, 100);
    int damage   = input_int("Enter damage (0-100):", 0, 100);
    int skill    = input_int("Enter skill value (0-10):", 0, 10);
    int add_armor = input_int("Enter how much armor skill adds (0-10):", 0, 10);
	int recoil = input_int("Enter recoil of skill(0-10)", 0, 10);
	int user_class = input_int("Enter Your class(0-Earthmover, 1-Angel, 2-V_model, 3-Dont you dare)", 0, 3);
	    switch (user_class) {
        case 0:
            return  std::make_unique<Earthmover>(name, hp, armor, damage, skill, add_armor, recoil);
        case 1:
            return  std::make_unique<Angel>(name, hp, armor, damage, skill, add_armor, recoil);
        case 2:
            return  std::make_unique<V_model>(name, hp, armor, damage, skill, add_armor, recoil);
		default:
			throw std::runtime_error("Something wicked this way comes");
    }

}

std::unique_ptr<Character> create_character(int id) {
    switch (id) {
        case 0:
            return create_custom_character();

        case 1:
            return std::make_unique<Earthmover>(
                "Earthmover", 
                180, // hp
                10,  // armor
                13,  // damage
                2,   // dodge
                3,   // add armor
                6    // recoil
            );

        case 2:
            return std::make_unique<Angel>("Gabriel", 200,11,14,3,4,5);

        case 3:
            return std::make_unique<Angel>("King Minos",260,13,16,2,5,6);

        case 4:
            return std::make_unique<V_model>("V1", 170,8,14,3,3,5);

        case 5:
            return std::make_unique<V_model>("V2", 130,5,20,4,4,6);

        default:
            throw std::runtime_error("Something wicked this way comes");
    }
}



std::unique_ptr<Character> choose_character() {
    std::println("{}Choose character:{}",
        color::cyan, color::reset);
    std::println("{}0.{} Your own",
        color::yellow, color::reset);
    std::println("{}1.{} Earthmover",
        color::green, color::reset);
    std::println("{}2.{} Gabriel",
        color::green, color::reset);
    std::println("{}3.{} King Minos",
        color::green, color::reset);
    std::println("{}4.{} V1",
        color::blue, color::reset);
    std::println("{}5.{} V2",
        color::blue, color::reset);
	std::println("{}else.{} {}ꙮ Ḧ̵́͑̓...{}", 
		color::red, color::reset, color::red, color::reset);
	try{
		int choice = input_int("Enter choice:", -1000, 1000);
		return create_character(choice);
	}
	catch (const std::exception& e) {
		std::println("{}Error: {}{}",
			color::red, e.what(), color::reset);
		return std::make_unique<Something_wicked>("Something wicked👁️", 9999999, 20, 999999, 5, 1, 0);
	}
}

int main(){
	
	hello(4);
	std::unique_ptr<Character> ch1 = choose_character();

    int choose = input_int("Play with computer (0) or friend (1):", 0, 1);

    if (choose){
        std::unique_ptr<Character> ch2 = choose_character();
        play(*ch1, *ch2);
    } else {
        std::unique_ptr<Character> computer = choose_character();
        simulate(*ch1, *computer);
    }

    return 0;
}