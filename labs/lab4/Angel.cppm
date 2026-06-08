export module Angel;
import std;
import Character;

export class Angel : public Character {
public:
	using Character::Character;
	
	int deal_damage(Character& enemy) {
		return enemy.input_damage(_damage);
	}
	

	int input_damage(int damage) {
		if(damage - _armor < 0 ){
			return 0;
		}
		int real_damage = (damage - _armor) / (1 + prob_aprox(_dodge_prob)*_random_dodge);
		_health -= real_damage;
		return real_damage;
	}
	
	void deactivate_skill() {
		if (_skill_active) {
			_skill_active = 0;
			_armor -= _add_armor;
			_damage += _add_armor;
		}
		else {
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
	}

	bool activate_skill() {
		if (_use_skill) {
			_health -= _use_skill;
			return 0;
		}
		else {
			_skill_active = 1;
			_armor += _add_armor;
			_damage -= _add_armor;
			_use_skill -= _recoil;
			return 1;
		}
	}
};
