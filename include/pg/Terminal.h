/*
 * Terminal.h
 *
 *  Created on: 18.07.2020
 *      Author: andreas
 */

#ifndef PG_TERMINAL_H_
#define PG_TERMINAL_H_

#include "pg/IExpr.h"

namespace pg {

class Terminal: public IExpr {
public:
	Terminal(double);
	double execute();
private:
	double _v;
};

} /* namespace pg */

#endif /* SRC_PG_TERMINAL_H_ */
