export module V_model;
import std;
import Character;

export class V_model : public Character {
public:
	using Character::Character;
	
	int input_damage(int damage) {
		if( damage - _armor < 0){
			return 0;
		}
		_health -= damage -_armor;
		return damage -_armor;
	}
	
	int deal_damage(Character& enemy) {
		int dmg = enemy.input_damage(get_damage()* ( 1 + take_less_damage()*_add_armor));
		if(_skill_active){
			_health += dmg;
		}
		return dmg;
	}
	
	void deactivate_skill() {
		if (_skill_active == true && _use_skill == 0) {
			_skill_active = false;
			_damage -= _default_health;
		} else {
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
		if (_use_skill != 0) {
			_use_skill = _health;
			_health = 0;
			return false;
		} else {
			_skill_active = 1;
			_use_skill -=_recoil;
			_default_health = _health;
			_damage = _health;
			_health -= _health / 2;
			return true;
		}
	}
};
