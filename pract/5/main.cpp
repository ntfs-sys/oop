import std;

class Fraction {
private:
	int _numerator;
	int _denominator;	
	void normalyse(){
		//I1
		if (_numerator == 0) {
			_denominator = 1;
			return;
		}
		//I3
		if ( _denominator < 0) {
			_denominator *= -1;
			_numerator *= -1;
		}
		//I2
		int gcd = std::gcd(_numerator, _denominator);
		_numerator = _numerator / gcd;
		_denominator = _denominator / gcd;
		
	}
public:
	Fraction( int numerator, int denominator) : 
		_numerator(numerator),
		_denominator(denominator) {
			normalyse();
		}


	Fraction(int numerator) :
		_numerator(numerator),
		_denominator(1) {
			normalyse();
		}
		int get_numerator() const {
			return _numerator;
		}
		int get_denominator() const {
			return _denominator;
		}

	Fraction& operator+=(const Fraction& other){
		_numerator = _denominator * other.get_numerator() + _numerator * other.get_denominator();
		_denominator = _denominator * other.get_denominator();
		normalyse();
		return *this;
	}

	Fraction& operator-=(const Fraction& other){
		_numerator = _numerator * other.get_denominator() - _denominator * other.get_numerator();
		_denominator = _denominator * other.get_denominator();
		normalyse();
		return *this;
	}

	Fraction& operator*=(const Fraction& other){
		_numerator*=other.get_numerator();
		_denominator*=other.get_denominator();
		normalyse();
		return *this;
	}

	Fraction& operator++(){
		*this += Fraction(1);
		return *this;
	}

	Fraction operator++(int){
		Fraction old = *this;
		++(*this);
		return old;
	}	


};

Fraction operator+(const Fraction& lf, const Fraction& rf) {
	Fraction result = lf;
	result+=rf;
	return result;
}

Fraction operator-(const Fraction& lf, const Fraction& rf) {
	Fraction result = lf;
	result-=rf;
	return result;
}

Fraction operator*(const Fraction& lf, const Fraction& rf) {
	Fraction result = lf;
	result*=rf;
	return result;
}

std::string frstr(const Fraction& fr) {
	std::stringstream str;
	str << fr;
	return str.str();
}

std::ostream& operator<<(std::ostream& os, const Fraction& fr){
	os << fr.get_numerator() << '/' << fr.get_denominator();
	return os;
}

void frfile(std::string path, const Fraction& fr){
	std::ofstream out(path);
	if(out.is_open()){
		out << fr;
	}
	out.close();
}

int main() {
	return 0;
}
