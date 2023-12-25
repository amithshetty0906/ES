`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 28.09.2023 15:30:26
// Design Name: 
// Module Name: shift_operator
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


module shift_operator(input [7:0]a,output reg[7:0]y1,reg[7:0]y2);

//parameter b=3;
always @(*)
begin 
y1=a<<4;//left shift
y2=a>>4;//right sift
end
endmodule
