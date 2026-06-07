export module gamelib;
import std;

export bool prob_aprox(int prob) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<int> dis(0, 10);
    return dis(gen) < prob;
}

export int int_input() {
    int result = 0;
    std::string buffer;
    while(std::getline(std::cin, buffer)) {
        std::stringstream ss(buffer);
        if (ss >> result && ss.eof()) {
            break;
        }
    }
    return result;
}
export void hello(int num){
		std::println("--------------------\n\
      LW: {}\n\
   Group: 6112\n\
  Author: Kirill Rezepkin\n\
  Option: 18\n\
--------------------", num);
}


export void menu_pl(Character& p1, Character& p2) {
    int how_to_act = int_input();
    std::println("1 for skill, other for atack");
    switch(how_to_act) {
    case 1:
        if(p1.activate_skill()){
        	std::println("skill activated");
        }
        break;
    default:
        p2.input_damage(p1.get_damage());
        std::println("dealed {} damage", p1.get_damage())
        break;
    }
}

export void menu_pc(Character& p1, Character& p2) {
    int how_to_act = prob_aprox(5);
    switch(how_to_act) {
    case 0:
        if(p1.activate_skill()){
        	std::println("pc activated skill");
	        }
        break;
    default:
        p2.input_damage(p1.get_damage());
        std::println("pc atacked: {} damage", p1.get_damage());
        break;
    }
}

export void play_pc(Character& p1, Character& p2) {
    while(1) {
    	std::println("player: hp:{}, skill(negative value for activated, 0 for ready to use):{}",p1.get_health(), p1.get_skill());
    	std::println("pc: hp:{}, skill(negative value for activated, 0 for ready to use):{}",p2.get_health(), p2.get_skill());
        menu_pl(p1, p2);
        if (!p2.is_alive()) {
        	std::println("pc defeated");
        	break;
        }
        menu_pc(p2, p1);
        if (!p1.is_alive()) {
        	std::println("human defeated");
        	break;
        }
    }
}

export void play(Character& p1, Character& p2) {
    while(1) {
    	std::println("p1: hp:{}, skill(negative value for activated, 0 for ready to use):{}",p1.get_health(), p1.get_skill());
    	std::println("p2: hp:{}, skill(negative value for activated, 0 for ready to use):{}",p2.get_health(), p2.get_skill());
        menu_pl(p1, p2);
        if (!p2.is_alive()) {
        	std::println("p2 defeated");
        	break;
        }
        menu_pl(p2, p1);
        if (!p1.is_alive()) {
        	std::println("p1 defeated");
        	break;
        }
    }
}