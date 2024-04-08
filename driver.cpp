#include "driver.h"
//激励函数
void driver::prc_driver() {
	sc_uint<4> cnt1;
	sc_uint<4> cnt2;

	cnt1 = 0;
	cnt2 = 0;

	while (1) {
		d_a = cnt1; //systemc允许[]进行位选择
		d_b = cnt2;

		wait(5, SC_US); //systemc的时间枚举变量ns, 周期为5ns
		cnt1++;
		cnt2 = cnt2 + 2;
	}
}