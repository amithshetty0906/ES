`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 19.10.2023 14:29:54
// Design Name: 
// Module Name: fulladd
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
//1bit full adder

module fulladd(
    input a,b,cin,
    output sum,cout
    );
    wire x,y,z;
    halfadd h1(.a(a),.b(b),.sum(x),.cout(y));
    halfadd h2(.a(a),.b(b),.sum(sum),.cout(z));
    assign cout= y|z;
    
endmodule
