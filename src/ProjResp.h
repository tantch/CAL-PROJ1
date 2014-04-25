/*
 * ProjResp.h
 *
 *  Created on: Apr 25, 2014
 *      Author: pim
 */

#ifndef PROJRESP_H_
#define PROJRESP_H_

#include "People.h"

namespace std {

class ProjResp: public People {
	string projName;
public:
	ProjResp(int id, string name,string projName);
	virtual ~ProjResp();
};

} /* namespace std */

#endif /* PROJRESP_H_ */
