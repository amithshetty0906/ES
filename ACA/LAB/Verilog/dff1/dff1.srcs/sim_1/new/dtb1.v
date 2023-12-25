`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 17.08.2023 18:22:42
// Design Name: 
// Module Name: dtb1
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


module dtb1(

    );
    wire q,qb;
    reg clk,d,rst;
    dff1 uut(.clk(clk),.rst(rst),.d(d),.q(q),.qb(qb));
    initial begin
     
     clk=1'b0;
     rst=1'b0;
     d=1'b0;
     end
     always#5 clk=~clk;
     always#10 d=~d;
     always#100 rst=~rst;
endmodule
