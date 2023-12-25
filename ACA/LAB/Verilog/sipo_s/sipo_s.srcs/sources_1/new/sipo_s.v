`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 09.10.2023 13:34:07
// Design Name: 
// Module Name: sipo_s
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


module sipo_s(
    input clk,s,
    output reg[3:0]q
    );
    always @(posedge clk)
    begin 
    q[3]=s;
    q[2]=q[3];
    q[1]=q[2];
    q[0]=q[1];
    end
endmodule
