export module Character;
import std;
import gamelib;

export class Character {

protected:

	
	std::string _name;

	int _health = 1;
	int _default_health = _health;
	int _armor = 1;
	int _damage = 1;

	int _dodge_prob = 1;

	const int _random_dodge = 2;

	int _add_armor = 1;
	int _recoil = 5;
	int	_use_skill = 0;
	bool _skill_active = 0;
		
public:

	Character() = delete;
	virtual ~Character() = default;
	
	explicit Character(std::string name, int health, int armor, int damage, int dodge_prob, int add_armor, int recoil) :

		_name(name),
		_health(health),
		_armor(armor),
		_damage(damage),
		_dodge_prob(dodge_prob),
		_add_armor(add_armor), 
		_recoil(recoil) {}


	int get_health() const {
		return _health;
	}

	int get_armor() const {
		return _armor;
	}

	int get_damage() const {
		return _damage;
	}
	
	int get_use_skill() const {
		return _use_skill;
	}
	std::string get_name() const {
		return _name;
	}
	
	virtual int input_damage(int damage) = 0;
	virtual void deactivate_skill() = 0;
	virtual bool activate_skill() = 0;
	virtual int deal_damage(Character& enemy) = 0;
};
