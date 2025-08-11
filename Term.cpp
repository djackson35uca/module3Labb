#include "Term.h"

// Constructors
Term::Term() : coefficient(0), exponent(0), variable('x') {}
Term::Term(double coef, int exp, char var) : coefficient(coef), exponent(exp), variable(var) {}
Term::Term(const Term& term)
    : coefficient(term.coefficient), exponent(term.exponent), variable(term.variable) {
}

// Getters
double Term::getCoefficient() const { return coefficient; }
int Term::getExponent() const { return exponent; }
char Term::getVariable() const { return variable; }

// Setters
void Term::setCoefficient(double coef) { coefficient = coef; }
void Term::setExponent(int exp) { exponent = exp; }
void Term::setVariable(char var) { variable = var; }

// Assignment
Term& Term::operator=(const Term& right) {
    if (this != &right) {
        coefficient = right.coefficient;
        exponent = right.exponent;
        variable = right.variable;
    }
    return *this;
}

// Comparisons (by exponent)
bool Term::operator<=(const Term& right) const { return exponent <= right.exponent; }
bool Term::operator>=(const Term& right) const { return exponent >= right.exponent; }
bool Term::operator<(const Term& right)  const { return exponent < right.exponent; }
bool Term::operator>(const Term& right)  const { return exponent > right.exponent; }
bool Term::operator==(const Term& right) const { return exponent == right.exponent; }

// Compatibility (same variable and exponent)
bool Term::compatible(const Term& t) const { return variable == t.variable && exponent == t.exponent; }

// Output
ostream& operator<<(ostream& os, const Term& t) {
    // Simple readable form: a*x^n (no fancy formatting)
    os << t.getCoefficient();
    if (t.getExponent() != 0) {
        os << t.getVariable();
        if (t.getExponent() != 1) os << "^" << t.getExponent();
    }
    return os;
}
