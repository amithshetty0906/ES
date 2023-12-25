`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 17.08.2023 18:03:13
// Design Name: 
// Module Name: dtb
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


module dtb(

    );
   reg clk,rst,d;
   wire q,qb;
   dff d1(q,qb,d,clk,rst);
   initial clk=0;
   always
   #5 clk=~clk;
   initial
   begin
   rst=1;d=0;
   #10 rst=0;
   #10 d=1;
   #10 rst=1;
   end  
endmodule
