`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 09.10.2023 13:47:50
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
    reg [3:0]d;
    wire [3:0]q;
    pipo uut(.clk(clk),.q(q),.d(d));
    initial 
    begin
    clk=0;
    d=0;
    #50
    d=4'b1001;
    end
    always #5 clk=~clk;
endmodule
