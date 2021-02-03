//
// Created by ddraco on 03.02.2021.
//

#include "Cast.hpp"

bool Cast::floatIsValue(void) const
{
	return (!(std::isnan(float_vl) || std::isinf(float_vl)));
}

bool Cast::doubleIsValue(void) const
{
	return (!(std::isnan(double_vl) || std::isinf(double_vl)));
}

bool Cast::isIntImpossible() const {
	return int_impossible;
}

bool Cast::isCharImpossible() const {
	return char_impossible;
}

bool Cast::isCharNonPrintable() const {
	return char_nonPrintable;
}

bool Cast::isIncorrectInput() const {
	return incorrect_input;
}

char Cast::getCharVl() const {
	return char_vl;
}

int Cast::getIntVl() const {
	return int_vl;
}

float Cast::getFloatVl() const {
	return float_vl;
}

double Cast::getDoubleVl() const {
	return double_vl;
}

Cast::Cast(const std::string &val) : val(val), type(INVALID_TYPE) {
	parse(val);
	overflow_check();
	get_values();
	non_printable_ch();
}

void Cast::parse(const std::string &val) {
	unsigned long i = 0;
	if (val.length() == 1 && !std::isdigit(val[0]))
		type = CHAR_TYPE;
	else
	{
		type = INT_TYPE;
		if (val[i] == '+' || val[i] == '-')
			i++;
		for ( ; i < val.length(); ++i) {
			if (val[i] == '.') {
				if (type != FLOAT_TYPE && type != DOUBLE_TYPE)
					type = DOUBLE_TYPE;
				else {
					type = INVALID_TYPE;
					break;
				}
			}
			else if (val[i] == 'f' && i == val.length() - 1 && type == DOUBLE_TYPE)
				type = FLOAT_TYPE;
			else if (!std::isdigit(val[i])) {
				type = INVALID_TYPE;
				break;
			}
		}
	}
}

void Cast::get_values() {
	if (type == CHAR_TYPE) {
		char_vl = val[0];
		int_vl = static_cast<int>(char_vl);
		float_vl = static_cast<float>(char_vl);
		double_vl = static_cast<double>(char_vl);
	}
	else if (type == INT_TYPE) {
		float_vl = static_cast<float>(val_double);
		double_vl = static_cast<double>(val_double);
		char_vl = static_cast<char>(val_double);
	}
	else if (type == FLOAT_TYPE) {
		float_vl = atof(val.c_str());
		int_vl = static_cast<int>(this->float_vl);
		double_vl = static_cast<double>(this->float_vl);
		char_vl = static_cast<char>(this->float_vl);
		if (!this->floatIsValue() || float_vl > std::numeric_limits<int>::max()
			|| float_vl < std::numeric_limits<int>::min())
			int_impossible = true;
	}
	else if (type == DOUBLE_TYPE) {
		double_vl = atof(val.c_str());
		int_vl = static_cast<int>(double_vl);
		float_vl = static_cast<float>(double_vl);
		char_vl = static_cast<char>(double_vl);
		if (!this->doubleIsValue() || double_vl > std::numeric_limits<int>::max()
			|| double_vl < std::numeric_limits<int>::min())
			int_impossible = true;
	}
}

void Cast::overflow_check() {
	buf << val;
	if (type == INT_TYPE) {
		buf >> val_double;
		int_vl = static_cast<int>(val_double);
		if (buf.fail())
			type = INVALID_TYPE;
		if (val_double > std::numeric_limits<int>::max()
			|| val_double < std::numeric_limits<int>::min())
			int_impossible = true;
	}
	else if (type == INVALID_TYPE)
	{
		if (val == "inff" || val == "-inff" || val == "+inff"
			|| val == "nanf")
			this->type = FLOAT_TYPE;
		else if (val == "inf" ||  val == "-inf" || val == "+inf"
				 || val == "nan")
			this->type = DOUBLE_TYPE;
	}
}

void Cast::non_printable_ch() {
	if (type != INVALID_TYPE) {
		if (int_impossible || int_vl > 127 || int_vl < 0)
			char_impossible = true;
		if (!std::isprint(char_vl))
			char_nonPrintable = true;
	}
	else
		incorrect_input = true;
}

std::ostream &operator<<(std::ostream &out, Cast const &cast)
{
	std::string tmp;
	std::stringstream strstream;

	if (cast.isCharImpossible() || cast.isIncorrectInput())
		strstream << "char: impossible" << '\n';
	else if (cast.isCharNonPrintable())
		strstream << "char: Non printable" << '\n';
	else
		strstream << "char: '" << cast.getCharVl() << "'\n";

	if (cast.isIntImpossible() || cast.isIncorrectInput())
		strstream << "int: impossible" << '\n';
	else
		strstream << "int: " << cast.getIntVl() << '\n';

	if (cast.isIncorrectInput())
		strstream << "float: impossible" << '\n';
	else
	{
		strstream << "float: " << cast.getFloatVl();
		tmp = strstream.str();
		if (cast.floatIsValue() && tmp.find('.') == std::string::npos)
			strstream << ".0";
		strstream << "f\n";
	}

	if (cast.isIncorrectInput())
		strstream << "double: impossible";
	else
	{
		strstream << "double: " << cast.getDoubleVl();
		tmp = strstream.str();
		if (cast.doubleIsValue() && tmp.find('.') == std::string::npos)
			strstream << ".0";
	}
	out << strstream.str() << std::endl;
	return (out);
}
