`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 10.08.2023 09:16:03
// Design Name: 
// Module Name: and_testb
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


module and_testb(

    );
    reg A,B;
    wire Z;
    project_2 U1(A,B,Z);
    initial begin
    A=0;
    B=0;
    #100;
    A=0;
    B=1;
    #100;
    A=1;
    B=0;
    #100;
    A=1;B=1; 
    end 
endmodule
