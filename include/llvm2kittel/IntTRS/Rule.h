// This file is part of llvm2KITTeL
//
// Copyright 2010-2014 Stephan Falke
//
// Licensed under the University of Illinois/NCSA Open Source License.
// See LICENSE for details.

#ifndef RULE_H
#define RULE_H

#include "llvm2kittel/Util/Ref.h"

// C++ includes
#include <set>
#include <string>

class Constraint;
class Term;

class Rule
{
public:
  unsigned int refCount;

protected:
    Rule(ref<Term> lhs, ref<Term> rhs, ref<Constraint> c);

public:
    static ref<Rule> create(ref<Term> lhs, ref<Term> rhs, ref<Constraint> c);
    ~Rule();

    std::string toString();
    std::string toKittelString();

    ref<Term> getLeft();
    ref<Term> getRight();
    ref<Constraint> getConstraint();
    std::set<std::string> *getVariables();

    ref<Rule> dropArgs(std::set<unsigned int> drop);

private:
    Rule(const Rule&);
    Rule &operator=(const Rule&);

    ref<Term> m_lhs;
    ref<Term> m_rhs;
    ref<Constraint> m_c;

};

#endif // RULE_H