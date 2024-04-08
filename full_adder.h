#ifndef _FULL_ADDER_H_
#define _FULL_ADDER_H_

#include "half_adder.h"

SC_MODULE(full_adder) {
	sc_in<bool> a, b, cin; //������һ����Ա����
	sc_out<bool> sum, carry;
	sc_signal<bool> c1, s1, c2;

	void proc_or(); //��������
	half_adder* half1, * half2; //�����������������

	SC_CTOR(full_adder) {
		half1 = new half_adder("hal1"); //���󿪱ٶѿռ�
		half2 = new half_adder("hal2");
		//���ֹ���
		half1->a(a);
		half1->b(b);
		half1->sum(sum);
		half1->carry(c1);
		//λ�ù���
		(*half2)(s1, cin, sum, c2); //�ϸ��ն����˳��

		SC_METHOD(proc_or);
		sensitive << c1 << c2; //�����ź�������߳���˵��
	}
	 
	//full_adder��������������ڶ����������ڽ���ʱ�Զ����ã���ֹ�ڴ�й©
	~full_adder() {
		delete half1;
		delete half2;
	}

};

#endif // !_FULL_ADDER_H_
