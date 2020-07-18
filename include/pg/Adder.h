/*
 * Adder.h
 *
 *  Created on: 18.07.2020
 *      Author: andreas
 */

#ifndef INCLUDE_PG_ADDER_H_
#define INCLUDE_PG_ADDER_H_

#include "pg/IExpr.h"

namespace pg {

class Adder: public IExpr {
public:
	double execute();
	Adder(IExpr & a, IExpr & b);
private:
	IExpr & _a;
	IExpr & _b;
};

} /* namespace pg */

#endif /* INCLUDE_PG_ADDER_H_ */
