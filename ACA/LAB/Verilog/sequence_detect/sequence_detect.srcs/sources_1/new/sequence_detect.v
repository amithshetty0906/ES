`timescale 1ns / 1ps

module sequence_detect(input wire in,reset,clk,output reg[1:0]present_state,reg[1:0]next_state,wire y);

parameter s0=2'b00;                             
parameter s1=2'b01;
parameter s2=2'b10;
parameter s3=2'b11;

always@(posedge clk)
begin
if(reset==1)
begin
present_state=s0;
end
else 
begin
present_state=next_state;
end
end

always@(in,present_state)
begin
case(present_state)
s0:begin
if(in==0)
next_state=s1;
else
next_state=s0;
end
s1:begin
if(in==0)
next_state=s2;
else
next_state=s1;
end
s2:begin
if(in==0)
next_state=s0;
else
next_state= s3;
end
s3:begin
if(in==1)
next_state=s1;
else
begin
next_state=s2;
end

end
default:next_state=s0;
endcase
end

assign y=(present_state==3 && in==0)?1:0;

endmodule
