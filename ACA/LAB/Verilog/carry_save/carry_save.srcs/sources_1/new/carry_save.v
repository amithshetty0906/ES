`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 12.10.2023 15:18:09
// Design Name: 
// Module Name: carry_save
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


module carry_save(input [3:0]a,b,c,d, 
output [4:0] sum, 
output cout
);
wire [3:0] s0,s1;
wire [3:0] c0,c1;

//1st stage
fulladd f0(.a(a[0]),.b(b[0]),.cin(c[0]),.sum(s0[0]),.cout(c0[0]));
fulladd f1(.a(a[1]),.b(b[1]),.cin(c[1]),.sum(s0[1]),.cout(c0[1]));
fulladd f2(.a(a[2]),.b(b[2]),.cin(c[2]),.sum(s0[2]),.cout(c0[2]));
fulladd f3(.a(a[3]),.b(b[3]),.cin(c[3]),.sum(s0[3]),.cout(c0[3]));


//2nd stage

fulladd f4(.a(d[0]),.b(s0[0]),.cin(1'b0),.sum(sum[0]),.cout(c1[0]));
fulladd f5(.a(d[1]),.b(s0[1]),.cin(c[0]),.sum(s1[0]),.cout(c1[1]));
fulladd f6(.a(d[2]),.b(s0[2]),.cin(c[1]),.sum(s1[1]),.cout(c1[2]));
fulladd f7(.a(d[3]),.b(s0[3]),.cin(c[2]),.sum(s1[2]),.cout(c1[3]));

//to manage carry us ripple adder
ripple4add r1(.a(c1[3:0]),.b({c0[3],s1[2:0]}),.cin(1'b0),.sum(sum[4:1]),.cout(cout));

endmodule
