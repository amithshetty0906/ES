`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 09.10.2023 13:54:21
// Design Name: 
// Module Name: siso
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


module siso(
    input clk,si,
    output so
    );
    reg[3:0]q=0;
    always@(posedge clk)
    begin
    q[3]=si;
    q[2]=q[3];
    q[1]=q[2];
    q[0]=q[1];
    end
    assign so=q[0];
    
    
endmodule
