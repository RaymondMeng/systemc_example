#ifndef _FULL_ADDER_H_
#define _FULL_ADDER_H_

#include "half_adder.h"

SC_MODULE(full_adder) {
	sc_in<bool> a, b, cin; //构造了一个成员函数
	sc_out<bool> sum, carry;
	sc_signal<bool> c1, s1, c2;

	void proc_or(); //函数声明
	half_adder* half1, * half2; //定义两个半加器对象

	SC_CTOR(full_adder) {
		half1 = new half_adder("hal1"); //请求开辟堆空间
		half2 = new half_adder("hal2");
		//名字关联
		half1->a(a);
		half1->b(b);
		half1->sum(sum);
		half1->carry(c1);
		//位置关联
		(*half2)(s1, cin, sum, c2); //严格按照定义的顺序

		SC_METHOD(proc_or);
		sensitive << c1 << c2; //敏感信号是针对线程来说的
	}
	 
	//full_adder类的析构函数，在对象生命周期结束时自动调用，防止内存泄漏
	~full_adder() {
		delete half1;
		delete half2;
	}

};

#endif // !_FULL_ADDER_H_
