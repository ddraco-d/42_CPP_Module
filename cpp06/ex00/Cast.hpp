//
// Created by ddraco on 03.02.2021.
//

#ifndef CAST_HPP
# define CAST_HPP
# include <string>
# include <iostream>
# include <sstream>
# include <iomanip>
# include <cctype>
# include <cmath>
# include <limits>
# define CHAR_TYPE 0
# define INT_TYPE 1
# define FLOAT_TYPE 2
# define DOUBLE_TYPE 3
# define INVALID_TYPE 4

class Cast {
private:
	Cast();
	std::stringstream buf;
	std::string val;
	double val_double;
	int type;
	char char_vl;
	int int_vl;
	float float_vl;
	double double_vl;
	bool int_impossible;
	bool char_impossible;
	bool char_nonPrintable;
	bool incorrect_input;
	void parse(std::string const &val);
	void get_values();
	void overflow_check();
	void non_printable_ch();
public:
	bool floatIsValue(void) const;
	bool doubleIsValue(void) const;
	Cast(const std::string &str);
	bool isIntImpossible() const;
	bool isCharImpossible() const;
	bool isCharNonPrintable() const;
	bool isIncorrectInput() const;
	char getCharVl() const;
	int getIntVl() const;
	float getFloatVl() const;
	double getDoubleVl() const;

};

std::ostream &operator<<(std::ostream &out, Cast const &pr);


#endif
