#include<systemc.h>

SC_MODULE(flipflop) {

 sc_in<bool> clk;
 sc_in<bool> enable;
 sc_in< sc_uint<3> > din;
 sc_out< sc_uint<3> > dout;

 void ff_logic();
 
 SC_CTOR(flipflop){
    SC_METHOD(ff_logic);
    dont_initialize();
    sensitive << clk.pos();
 }

};


