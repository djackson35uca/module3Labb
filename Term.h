#ifndef TERM_H
#define TERM_H

#include <iostream>
using namespace std;

class Term {
private:
    double coefficient;
    int exponent;
    char variable;

public:
    Term();
    Term(double coef, int exp, char var);
    Term(const Term& term);

    double getCoefficient() const;
    int getExponent() const;
    char getVariable() const;

    void setCoefficient(double coef);
    void setExponent(int exp);
    void setVariable(char var);

    Term& operator=(const Term& right);

    // Compare by exponent
    bool operator<=(const Term& right) const;
    bool operator>=(const Term& right) const;
    bool operator<(const Term& right) const;
    bool operator>(const Term& right) const;
    bool operator==(const Term& right) const;

    // Same var and same exponent
    bool compatible(const Term& term) const;

    friend ostream& operator<<(ostream& os, const Term& t);
};

#endif

