#include "monitor.h"

void monitor::prc_monitor() {
	cout << "At time " << sc_time_stamp() << "::";
	cout << "(a, b): ";
	cout << m_a << m_b;
	cout << "(sum, carry_out): " <<m_sum <<m_cout <<endl;
}