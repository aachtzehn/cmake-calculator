/*
 * Terminal.cpp
 *
 *  Created on: 18.07.2020
 *      Author: andreas
 */

#include "pg/Terminal.h"
namespace pg {

Terminal::Terminal(double d) {
	_v = d;
}

double Terminal::execute() {
	return _v;
}

}
