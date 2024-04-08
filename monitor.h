#include "systemc.h"

SC_MODULE(monitor) {
	sc_in<sc_uint<4> > m_a, m_b, m_sum;
	sc_in<bool> m_cout;

	void prc_monitor();

	SC_CTOR(monitor) {
		SC_METHOD(prc_monitor);
		sensitive << m_a << m_b << m_cout << m_sum;
	}
};
