#include "driver.h"
//��������
void driver::prc_driver() {
	sc_uint<4> cnt1;
	sc_uint<4> cnt2;

	cnt1 = 0;
	cnt2 = 0;

	while (1) {
		d_a = cnt1; //systemc����[]����λѡ��
		d_b = cnt2;

		wait(5, SC_US); //systemc��ʱ��ö�ٱ���ns, ����Ϊ5ns
		cnt1++;
		cnt2 = cnt2 + 2;
	}
}