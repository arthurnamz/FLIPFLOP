#include "ff.h"

int sc_main(int argc, char* argv[])
{

 flipflop dut("flipflop");

 //signal declaration
 sc_signal<bool> clk;
 sc_signal<bool> enable;
 sc_signal< sc_uint<3> > din, dout;

 sc_time t1(1, SC_PS);

 dut.clk(clk);
 dut.enable(enable);
 dut.din(din);
 dut.dout(dout);
 
 //waveform declaration 
 sc_trace_file *wf = sc_create_vcd_trace_file("flipflop");

 //Adding waveform signals
 sc_trace(wf, clk, "clk");
 sc_trace(wf, enable, "enable");
 sc_trace(wf, din, "din");
 sc_trace(wf, dout, "dout");

 //PROVIDING INPUTS to the dut
 clk.write(1);
 sc_start(t1);
 clk.write(0);
 sc_start(t1);

 enable.write(1);
 din.write(4);

 clk.write(1);
 sc_start(t1);
 clk.write(0);
 sc_start(t1); 

 enable.write(0);

 clk.write(1);
 sc_start(t1);
 clk.write(0);
 sc_start(t1);

 enable.write(1);
 din.write(2);

 clk.write(1);
 sc_start(t1);
 clk.write(0);
 sc_start(t1);
 

 sc_close_vcd_trace_file(wf);
 
 return 0;

}
