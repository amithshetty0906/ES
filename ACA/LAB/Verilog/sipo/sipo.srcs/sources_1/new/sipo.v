`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 09.10.2023 12:44:23
// Design Name: 
// Module Name: sipo
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


module sipo(
    input clk,b,
    output [3:0]q
    );
    dff d1(.clk(clk),.d(b),.q(q[3]),.rst(rst));
    dff d2(.clk(clk),.d(q[3]),.q(q[2]),.rst(rst));
    dff d3(.clk(clk),.d(q[2]),.q(q[1]),.rst(rst));
    dff d4(.clk(clk),.d(q[1]),.q(q[0]),.rst(rst));
    
endmodule
