export module Character;
import std;
import gamelib;

export class Character {
private:
    int _health = 0;
    int _armor = 0;
    int _prob = 0;
    int _random_dodge = 2;
    int _damage = 0;
    int _add_armour = 0;
    int _reduce_damage = 0;
    int _cooldown = 0;
    int _duration = 0;
    int _skill = 0;
    int _skill_duration = 3;
public:
    Character(int health, int armor, int prob, int damage, int add_armour, int reduce_damage) :
        _health(health), _armor(armor), _prob(prob), _damage(damage), _add_armour(add_armour), _reduce_damage(reduce_damage) {}

    int input_damage(int damage) {
        int dmg = damage / (_armor + _random_dodge * prob_aprox(_prob));
        _health -= dmg;
        return dmg;
    }
    
    void proseed_with_skill() {
        if (_skill > 0) {
            _skill--;
            if (_skill == 0) {
                _armor -= _add_armour;
                _damage += _reduce_damage;
            }
        } else if (_skill < 0) {
            _skill++;
        }
    }

    bool activate_skill() {
        if (_skill == 0) {
            _armor += _add_armour;
            _damage -= _reduce_damage;
            _skill = _skill_duration;
            return true;
        } else {
            return false;
        }
    }
    
    bool is_alive() const {
        return _health > 0;
    }
    
    int get_damage() const {
        return _damage;
    }
    int get_health() const {
    	return _health;
    }
    int get_skill() const {
    	return _skill;
    }
};