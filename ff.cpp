#include "ff.h"

sc_int<3> data;
void flipflop::ff_logic()
{
  std::cout<< " Enable = " << enable.read()<<" output = ";

 if(enable.read() == 1){
    data = din.read();
    dout.write(din.read() ); 

 std::cout<< data.to_string(SC_BIN) <<" \n";
}

}
