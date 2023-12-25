`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 28.09.2023 15:38:48
// Design Name: 
// Module Name: test_shift
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


module test_shift( );
    reg [7:0]a;
    wire [7:0]y1,y2;
       reg clk;
   shift_operator uut(.a(a),.y1(y1),.y2(y2));
   initial
   begin
   clk=1'b0;
   end

   always #10 clk=~clk;
   initial
    begin 
   a=8'b10110110;
   #50
   a=8'b11110000;
   
   end
endmodule       