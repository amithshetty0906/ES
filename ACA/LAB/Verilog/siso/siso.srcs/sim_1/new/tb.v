`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 09.10.2023 13:56:46
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
    reg si,clk;
    wire so;
    siso uut(.clk(clk),.si(si),.so(s0));
    initial
    begin
    clk=0;
    si=1;
    #10
    si=0;
    #10
    si=1;
    #10;
    si=0;
    end 
    always #5 clk=~clk;
    
endmodule
