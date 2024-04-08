// main_sim.cpp : 此文件包含 "sc_main" 函数。程序执行将在此处开始并结束。

#include "full_adder.h"
#include "driver.h"
#include "monitor.h"

int sc_main(int argc, char* argv[])
{
	/*创建信号连接所有模块*/
	sc_signal<bool> t_a, t_b, t_sum, t_cin, t_cout;

	/*gtkwave查看波形指令*/
	const char* command = "gtkwave wave.vcd";

	/*全加器模块实例化*/
	full_adder f1("fulladder_with_halfadder");
	f1 << t_a << t_b << t_cin << t_sum << t_cout; //位置关联

	/*信号驱动*/
	driver dri("signal_drive");
	dri.d_a(t_a); //名字关联
	dri.d_b(t_b);
	dri.d_cin(t_cin);

	/*监视器*/
	monitor mtor("signal_monitor");
	mtor << t_a << t_b << t_cin << t_sum << t_cout;

	/*打开vcd记录波形*/
	sc_trace_file* tf = sc_create_vcd_trace_file("wave");
	sc_trace(tf, t_a, "a");
	sc_trace(tf, t_b, "b");
	sc_trace(tf, t_cin, "cin");
	sc_trace(tf, t_sum, "sum");
	sc_trace(tf, t_cout, "cout");

	/*开始仿真，运行100ns*/
	sc_start(100, SC_US);

	/*关闭vcd文件*/
	sc_close_vcd_trace_file(tf);
	// 使用 system 函数执行命令
	int result = system(command);
	if (result != 0) {
		std::cerr << "Error occurred while opening gtkwave." << std::endl;
		return 1;
	}

	return 0;
}

