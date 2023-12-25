`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 09.10.2023 13:36:25
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


module tb(

    );
    reg clk;
    reg s;
    wire [3:0]q;
    sipo_s uut(.clk(clk),.s(s),.q(q));
    initial
    begin
    clk=0;
    s=1;
    #50;
    s=0;
    #50
    s=1;
    #50
    s=0;
    end
    always #5 clk=~clk;
    
endmodule
