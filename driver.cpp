#include "driver.h"
//激励函数
void driver::prc_driver() {
	sc_uint<3> cnt;

	cnt = 0;

	while (1) {
		d_a = cnt[0]; //systemc允许[]进行位选择
		d_b = cnt[1];
		d_cin = cnt[2];

		wait(5, SC_NS); //systemc的时间枚举变量ns, 周期为5ns
		cnt++;
	}
}