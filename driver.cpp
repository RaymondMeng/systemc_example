#include "driver.h"
//��������
void driver::prc_driver() {
	sc_uint<3> cnt;

	cnt = 0;

	while (1) {
		d_a = cnt[0]; //systemc����[]����λѡ��
		d_b = cnt[1];
		d_cin = cnt[2];

		wait(5, SC_NS); //systemc��ʱ��ö�ٱ���ns, ����Ϊ5ns
		cnt++;
	}
}