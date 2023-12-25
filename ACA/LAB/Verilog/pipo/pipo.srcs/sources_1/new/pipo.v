`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 09.10.2023 13:45:36
// Design Name: 
// Module Name: pipo
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


module pipo(
    input clk,[3:0]d,
    output reg [3:0]q
    );
    always@(posedge clk)
    begin
    q[3]=d[3];  
     q[2]=d[2]; 
      q[1]=d[1]; 
       q[0]=d[0];  
       end 
endmodule
