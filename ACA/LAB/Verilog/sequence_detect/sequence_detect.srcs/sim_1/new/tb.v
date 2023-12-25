`timescale 1ns / 1ps

module tb(
    );
reg in,reset,clk;
wire[1:0]present_state,next_state;
wire y;

sequence_detect uut(.in(in),.clk(clk),.reset(reset),.present_state(present_state),.next_state(next_state),.y(y));
initial
begin
clk=1'b0;
end

always #5 clk=~clk;

initial
begin
reset=1;
#6;
reset=0;
in=1'b0;
#6
in=1'b1;
#7;
in=1'b0;
#7;
in=1'b1;
#4;
in=1'b0;
#4;
in=1'b1;
#7;
in=1'b0;
#7;
end
endmodule



