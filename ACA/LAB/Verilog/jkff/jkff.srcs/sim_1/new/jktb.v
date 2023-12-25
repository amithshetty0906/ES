`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 17.08.2023 17:51:11
// Design Name: 
// Module Name: jktb
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


module jktb(

    );
    reg clk;
    reg rst;
    reg j; reg k;
    wire q,qb;
    jkff uut(.clk(clk),.rst(rst),.j(j),.k(k),.q(q),.qb(qb));
    initial clk=1'b0;
    always #10 clk=~clk;
    initial begin
    rst=1;j=1;k=0;
    #10; rst=0;
    #10;j=0;k=0;
    #10;j=0;k=1;
    #10;j=1;k=0;
    #10;j=1;k=1;
     #10; rst=1;
     end 
endmodule
