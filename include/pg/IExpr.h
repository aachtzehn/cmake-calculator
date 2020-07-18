/*
 * IExpr.h
 *
 *  Created on: 18.07.2020
 *      Author: andreas
 */

#ifndef PG_IEXPR_H_
#define PG_IEXPR_H_

namespace pg {

class IExpr {
public:
	virtual ~IExpr() {};
	virtual double execute() = 0;
};

} /* namespace pg */
#endif /* INCLUDE_PG_IEXPR_H_ */

