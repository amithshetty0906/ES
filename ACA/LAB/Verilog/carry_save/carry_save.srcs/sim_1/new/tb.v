`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 19.10.2023 15:34:21
// Design Name: 
// Module Name: tb
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module tb();
wire [4:0] sum;
wire cout;
reg [3:0]a,b,c,d;

carry_save uut(.a(a),.b(b),.c(c),.d(d),.sum(sum),.cout(cout));

initial
begin
a=0;b=0;c=0;d=0;
#100 a=10;b=0;c=0;d=0;
#100 a=10;b=10;c=0;d=0; 
#100 a=4;b=6;c=12;d=0;
#100 a=11;b=2;c=4;d=7;
end
initial
$monitor("a=%d,b=%d,c=%d,d=%d,sum=%d,cout=%d",a,b,c,d,sum,cout);



endmodule
