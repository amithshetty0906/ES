`timescale 1ns / 1ps


module ortest( );
reg x,y;
wire z;
ORGATE dut(.A(x),.B(y),.Y(z));

initial begin
x=0;y=0;
#1
x=0;y=1;
#1
x=1;y=0;
#1
x=1;y=1;

end
endmodule
