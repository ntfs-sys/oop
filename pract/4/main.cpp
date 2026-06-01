import std;

class Fraction {
private:
	int _numerator;
	int _denominator;	
	void normalyse(){
		//I1
		if (_numerator == 0) {
			_denominator = 1;
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

};

Fraction operator+(const Fraction& lf, const Fraction& rf) {
	int summ_numerator = lf.get_denominator() * rf.get_numerator() + lf.get_numerator() * rf.get_denominator();
	int summ_denominator = lf.get_denominator() * rf.get_denominator();
	return Fraction(summ_numerator, summ_denominator);
}
Fraction operator-(const Fraction& lf, const Fraction& rf) {
	Fraction frm( - rf.get_numerator(), rf.get_denominator());
	return lf+frm;
}
Fraction operator*(const Fraction& lf, const Fraction& rf) {
	int mult_numerator = lf.get_numerator() * rf.get_numerator();
	int mult_denominator = lf.get_denominator() * rf.get_denominator();
	return Fraction(mult_numerator, mult_denominator);
}
std::string frstr(const Fraction& fr) {
	return std::to_string(fr.get_numerator()) + "/" + std::to_string(fr.get_denominator());
}
int main() {
	Fraction fr1(67), fr2(-52, -14);
	std::println("first: {}, second: {}", frstr(fr1), frstr(fr2));
	std::println("+: {}, -: {}, *: {}", frstr(fr1+fr2), frstr	(fr1-fr2), frstr(fr1*fr2)); 
	return 0;
}