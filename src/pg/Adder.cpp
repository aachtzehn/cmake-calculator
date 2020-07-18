/*
 * Adder.cpp
 *
 *  Created on: 18.07.2020
 *      Author: andreas
 */

#include "pg/Adder.h"

namespace pg {

double Adder::execute() {
	return _a.execute() + _b.execute();
}

Adder::Adder(IExpr &a, IExpr &b) : _a(a),_b(b) { }

} /* namespace pg */
