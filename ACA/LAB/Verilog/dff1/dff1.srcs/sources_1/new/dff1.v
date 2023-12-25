`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 17.08.2023 18:18:42
// Design Name: 
// Module Name: dff1
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


module dff1(
    input d,
    input rst,
    input clk,
    output reg q,
    output reg qb
    );
    always@(posedge clk)
    begin
    if(rst==1'b1)
    begin
    q=1'b0; 
    qb=1'b1;
    end  
    else
    begin
    q=d; 
    qb=~q;
    end
    end
endmodule
