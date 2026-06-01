export module Earthmover;
import std;
import Character;

export class Earthmover : public Character {
public:
	using Character::Character;
	
	int deal_damage(Character& enemy) {
		int dmg = enemy.input_damage(_damage * (1 + take_less_damage()*_random_dodge));
		return dmg;
	}
	
	int input_damage(int damage) {
		if(damage - _armor < 0 || _use_skill < 0){
			return 0;
		}
		int real_damage = damage - _armor;
		_health -= real_damage;
		return real_damage;
	}

	bool activate_skill() {
		if (_use_skill) {
			_health -= _recoil;
			return 0;
		}
		else {
			_skill_active = 1;
			_use_skill -= _recoil;
			
			return 1;
		}
	}
	
	void deactivate_skill() {
		if (_use_skill > 0) {
			_use_skill--;
		}
		if (_use_skill < 0) {
			_use_skill++;
			if(_use_skill == 0){
				_use_skill += _recoil;
			}
		}
	}
	
};
