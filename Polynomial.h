#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>
#include "Term.h"

class Polynomial {
private:
    Term* terms;
    int numTerms;

    void simplify(); // combine compatible terms

public:
    Polynomial();
    Polynomial(Term* t, int n);
    Polynomial(const Polynomial& poly);
    ~Polynomial();

    Term* getTerms() const;
    int getNumTerms() const;

    void setTerms(Term* t, int n);

    Polynomial& operator=(const Polynomial& right);

    Polynomial operator+(const Polynomial& right) const;
    Polynomial operator-(const Polynomial& right) const;
    Polynomial operator*(const Polynomial& right) const;

    friend std::ostream& operator<<(std::ostream& os, const Polynomial& p);
};

#endif
