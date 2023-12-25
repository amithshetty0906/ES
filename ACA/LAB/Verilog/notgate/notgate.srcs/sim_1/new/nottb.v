`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 17.08.2023 15:17:42
// Design Name: 
// Module Name: nottb
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


module nottb(

    );
    reg a;
    wire b;
     notgate uut(.x(a),.y(b));
     initial begin
     a=0;#10;
     a=1;
     
     end
endmodule
