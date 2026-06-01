export module Something_wicked;
import std;
import gamelib;
import Character;

export class Something_wicked : public Character{
public:
	using Character::Character;
	int input_damage(int damage){
		return 0;
	}
	void deactivate_skill(){
		std::println("{}IT IS IMPOSSIBLE TO DEACTIVATE MY SKILL{}", color::red, color::reset);
	}
	bool activate_skill(){
		_health = std::numeric_limits<int>::max();
		return 1;
	}
	int deal_damage(Character& DEAD) {
		return DEAD.input_damage(std::numeric_limits<int>::max());
	}
};