#ifndef _TEMP_H_
#define _TEMP_H_

#include "fraction.h"
#include <vector>

std::vector<Fraction> gaussFraction(std::vector<std::vector<Fraction> >&, std::vector<Fraction>&);
std::vector<std::vector<Fraction> > grapeFraction(const std::vector<std::vector<Fraction> >& , const std::vector<std::vector<Fraction> >&);
#endif