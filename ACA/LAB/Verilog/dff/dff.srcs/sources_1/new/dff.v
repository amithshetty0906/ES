`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 17.08.2023 17:59:45
// Design Name: 
// Module Name: dff
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


module dff(q,qb,d,clk,rst);
output reg q;
output  qb;
input d,clk,rst;
always@(posedge clk)
begin
if(rst)
q=0;
else
q=d;
end
assign 
qb=~q;
endmodule
    
