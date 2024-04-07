#include "half_adder.h"

void half_adder::proc_half_adder() {
	sum = a ^ b;
	carry = a & b;
}