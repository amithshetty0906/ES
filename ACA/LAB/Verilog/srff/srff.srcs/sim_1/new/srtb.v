`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 17.08.2023 17:34:18
// Design Name: 
// Module Name: srtb
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


module srff1(
    input clk,s,r,reset,
    output reg q,qb
    );
    always @(posedge clk)
    begin
    if(reset==1)
    begin
    q=1'b0;
    qb=1'b1;
    end
    else
    begin
    case({s,r})
    2'b00:q=q;
    2'b01:q=1'b0;
    2'b10:q=1'b1;
    2'b11:q=1'bz;
    endcase
    qb=~q;
    end
    end
endmodule
