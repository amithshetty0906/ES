`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 17.08.2023 15:31:37
// Design Name: 
// Module Name: nortb
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


module nortb(

    );
    reg a,b;
    wire y;
    norg uut(.a(a),.b(b),.y(y));
    initial begin
    a=0;b=0;#5
    a=0;b=1;#5
    a=1;b=0;#5
    a=0;b=1;
    end
endmodule
