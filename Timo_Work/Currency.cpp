#include "Currency.h"



Currency::Currency()
{
}

Currency::Currency(std::string n, int w, int p, std::string f) : name(n), whole(w), part(p), fraction(f) {}

Currency::~Currency()
{
}

Currency operator+(const Currency& a, const Currency& b)
{
	int temp = a.whole + b.whole;

	if (a.part + b.part > 100)
		return Currency(a.name, a.whole + b.whole + 1, a.part + b.part - 100, a.fraction);
	else if ( a.part + b.part > 0 )
		return Currency(a.name, a.whole + b.whole, a.part + b.part, a.fraction);

	// allow adding negatives
	//if (a.part + b.part < 0)
	return Currency(a.name, a.whole + 1 + b.whole, a.part + 100 + b.part, a.fraction);
}

Currency operator-(const Currency& a, const Currency& b)
{
	int temp = a.whole + b.whole;
	if (a.part - b.part < 0)
		return Currency(a.name, a.whole - b.whole - 1, a.part - b.part + 100, a.fraction);
	else
		return Currency(a.name, a.whole - b.whole, a.part - b.part, a.fraction);
}

std::ostream & operator<<(std::ostream& stream, Currency& a)
{
	if (a.fraction == "") {
		if (a.name == "Dollar") {
			a.fraction = "cent";
		}
		else if (a.name == "Euro") {
			a.fraction = "cent";
		}
		else if (a.name == "Yen") {
			a.fraction = "sen";
		}
		else if (a.name == "Rupee") {
			a.fraction = "paise";
		}
		else if (a.name == "Yuan") {
			a.fraction = "fen";
		}
	}
	stream << a.name << ", " << a.whole << ", " << a.part << ", " << a.fraction << std::endl;
	return stream;
}

std::istream & operator>>(std::istream& stream, Currency& a)
{
	try {
		double input;
		stream >> input;
		if (std::cin.fail()) {
			std::cin.clear();	// clear error flag
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');	// remove any extra characters if user typed more than one

			throw std::string("Input is invalid. Please try again.\n");
		}

		a.setWhole( floor(input) );
		a.setPart( (input - floor(input))*100+.5 ); // adding .5 because compiler truncates

	} catch (std::string msg) {
		std::cout << "We broke :c " << msg << std::endl;
	}
	return stream;
}