#ifndef _BIT4_ADDER_H_
#define _BIT4_ADDER_H_

#include "systemc.h"
#include "full_adder.h"

SC_MODULE(bit4_adder) {
	sc_in<sc_uint<4> > a, b;
	sc_out<sc_uint<4> > sum;
	sc_out<bool> cout;
	sc_signal<bool> c1, c2, c3, a1, a2, a3, a4, b1, b2, b3, b4, s1, s2, s3, s4;
	/*sc_signal<sc_uint<4> > t_a, t_b;*/
	full_adder* full1, * full2, * full3;
	half_adder* half1;
	sc_uint<4> t_a, t_b, t_sum;

	SC_CTOR(bit4_adder):
		a("a"), //命名端口,为了更好的debug
		b("b"),
		sum("sum"),
		cout("cout")
	{
		
		t_a = this->a.read();
		t_b = this->b.read();
		a1 = t_a[0];
		a2 = t_a[1];
		a3 = t_a[2];
		a4 = t_a[3];
		
		b1 = t_b[0];
		b2 = t_b[1];
		b3 = t_b[2];
		b4 = t_b[3];

		//端口和信号不能位选择
		/*a1 = a[1];
		a2 = a[1];
		a3 = a[2];
		a4 = a[3];

		b1 = b[0];
		b2 = b[1];
		b3 = b[2];
		b4 = b[3];*/
		
		s1 = t_sum[0];

		//t_a.range(0, 0)
		half1 = new half_adder("half1");
		half1->a(a1);
		half1->b(b1);
		half1->sum(s1);
		half1->carry(c1);
		t_sum[0] = s1;

		full1 = new full_adder("full1");
		full1->a(a2);
		full1->b(b2);
		full1->cin(c1);
		full1->sum(s2);
		full1->carry(c2);
		t_sum[1] = s2;

		full2 = new full_adder("full2");
		full2->a(a3);
		full2->b(b3);
		full2->cin(c2);
		full2->sum(s3);
		full2->carry(c3);
		t_sum[2] = s3;

		full3 = new full_adder("full3");
		full3->a(a4);
		full3->b(b4);
		full3->cin(c3);
		full3->sum(s4);
		full3->carry(this->cout);
		t_sum[3] = s4;

		this->sum.write(t_sum);
	}
};

#endif // !_BIT4_ADDER_H_

