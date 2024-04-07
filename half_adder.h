#ifndef _HALF_ADDER_H_
#define _HALF_ADDER_H_

#include "systemc.h"

SC_MODULE(half_adder) {
	sc_in<bool> a, b;
	sc_out<bool> sum, carry;

	void proc_half_adder();

	SC_CTOR(half_adder) {
		SC_METHOD(proc_half_adder);
		sensitive << a << b; //敏感信号列表
	}
};

#endif // !_HALF_ADDER_H_
