#include "Polynomial.h"


void Polynomial::simplify() {
    // combine compatible terms (same var & exponent)
    for (int i = 0; i < numTerms; ++i) {
        for (int j = i + 1; j < numTerms; ++j) {
            if (terms[i].compatible(terms[j])) {
                terms[i].setCoefficient(terms[i].getCoefficient() + terms[j].getCoefficient());
                // shift left from j
                for (int k = j; k < numTerms - 1; ++k) terms[k] = terms[k + 1];
                --numTerms;
                --j; // re-check new item at j
            }
        }
    }
}


Polynomial::Polynomial() : terms(nullptr), numTerms(0) {}

Polynomial::Polynomial(Term* t, int n) : terms(nullptr), numTerms(0) {
    if (n > 0) {
        numTerms = n;
        terms = new Term[numTerms];
        for (int i = 0; i < numTerms; ++i) terms[i] = t[i];
        simplify();
    }
}

Polynomial::Polynomial(const Polynomial& poly) : terms(nullptr), numTerms(0) {
    if (poly.numTerms > 0) {
        numTerms = poly.numTerms;
        terms = new Term[numTerms];
        for (int i = 0; i < numTerms; ++i) terms[i] = poly.terms[i];
    }
}

Polynomial::~Polynomial() {
    delete[] terms;
}


Term* Polynomial::getTerms() const { return terms; }
int   Polynomial::getNumTerms() const { return numTerms; }

void Polynomial::setTerms(Term* t, int n) {
    delete[] terms;
    terms = nullptr;
    numTerms = 0;
    if (n > 0) {
        numTerms = n;
        terms = new Term[numTerms];
        for (int i = 0; i < numTerms; ++i) terms[i] = t[i];
        simplify();
    }
}


Polynomial& Polynomial::operator=(const Polynomial& right) {
    if (this != &right) {
        delete[] terms;
        terms = nullptr;
        numTerms = 0;
        if (right.numTerms > 0) {
            numTerms = right.numTerms;
            terms = new Term[numTerms];
            for (int i = 0; i < numTerms; ++i) terms[i] = right.terms[i];
        }
    }
    return *this;
}


Polynomial Polynomial::operator+(const Polynomial& right) const {
    int newSize = numTerms + right.numTerms;
    Term* combined = new Term[newSize];
    for (int i = 0; i < numTerms; ++i) combined[i] = terms[i];
    for (int i = 0; i < right.numTerms; ++i) combined[numTerms + i] = right.terms[i];

    Polynomial result(combined, newSize);
    delete[] combined;
    return result;
}


Polynomial Polynomial::operator-(const Polynomial& right) const {
    int newSize = numTerms + right.numTerms;
    Term* combined = new Term[newSize];
    for (int i = 0; i < numTerms; ++i) combined[i] = terms[i];
    for (int i = 0; i < right.numTerms; ++i) {
        Term neg = right.terms[i];
        neg.setCoefficient(-neg.getCoefficient());
        combined[numTerms + i] = neg;
    }

    Polynomial result(combined, newSize);
    delete[] combined;
    return result;
}


Polynomial Polynomial::operator*(const Polynomial& right) const {
    if (numTerms == 0 || right.numTerms == 0) return Polynomial();

    int newSize = numTerms * right.numTerms;
    Term* product = new Term[newSize];
    int idx = 0;

    for (int i = 0; i < numTerms; ++i) {
        for (int j = 0; j < right.numTerms; ++j) {
            // assumes same variable symbol
            product[idx++] = Term(
                terms[i].getCoefficient() * right.terms[j].getCoefficient(),
                terms[i].getExponent() + right.terms[j].getExponent(),
                terms[i].getVariable()
            );
        }
    }

    Polynomial result(product, newSize);
    delete[] product;
    return result;
}


std::ostream& operator<<(std::ostream& os, const Polynomial& p) {
    if (p.numTerms == 0) { os << "0"; return os; }

    for (int i = 0; i < p.numTerms; ++i) {
        const double c = p.terms[i].getCoefficient();
        if (i > 0) os << (c >= 0 ? " + " : " - ");
        double mag = (c >= 0 ? c : -c);
        // print the term without repeating the sign
        os << mag;
        if (p.terms[i].getExponent() != 0) {
            os << p.terms[i].getVariable();
            if (p.terms[i].getExponent() != 1) os << "^" << p.terms[i].getExponent();
        }
    }
    return os;
}
