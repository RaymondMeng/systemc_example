// main_sim.cpp : ���ļ����� "sc_main" ����������ִ�н��ڴ˴���ʼ��������

#include "full_adder.h"
#include "driver.h"
#include "monitor.h"

int sc_main(int argc, char* argv[])
{
	/*�����ź���������ģ��*/
	sc_signal<bool> t_a, t_b, t_sum, t_cin, t_cout;

	/*gtkwave�鿴����ָ��*/
	const char* command = "gtkwave wave.vcd";

	/*ȫ����ģ��ʵ����*/
	full_adder f1("fulladder_with_halfadder");
	f1 << t_a << t_b << t_cin << t_sum << t_cout; //λ�ù���

	/*�ź�����*/
	driver dri("signal_drive");
	dri.d_a(t_a); //���ֹ���
	dri.d_b(t_b);
	dri.d_cin(t_cin);

	/*������*/
	monitor mtor("signal_monitor");
	mtor << t_a << t_b << t_cin << t_sum << t_cout;

	/*��vcd��¼����*/
	sc_trace_file* tf = sc_create_vcd_trace_file("wave");
	sc_trace(tf, t_a, "a");
	sc_trace(tf, t_b, "b");
	sc_trace(tf, t_cin, "cin");
	sc_trace(tf, t_sum, "sum");
	sc_trace(tf, t_cout, "cout");

	/*��ʼ���棬����100ns*/
	sc_start(100, SC_US);

	/*�ر�vcd�ļ�*/
	sc_close_vcd_trace_file(tf);
	// ʹ�� system ����ִ������
	int result = system(command);
	if (result != 0) {
		std::cerr << "Error occurred while opening gtkwave." << std::endl;
		return 1;
	}

	return 0;
}

