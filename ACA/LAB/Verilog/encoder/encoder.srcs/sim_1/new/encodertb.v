`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 17.08.2023 15:52:15
// Design Name: 
// Module Name: encodertb
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


module encodertb(

    );
    reg [7:0]i;
    reg en;
    wire [2:0]y;
    encoder uut(.i(i),.en(en),.y(y));
    initial begin
    en=0;i=0;#100
     en=1;i=1;#100
      en=1;i=2;#100
       en=1;i=4;#100
        en=1;i=8;#100
         en=1;i=16;#100
          en=1;i=32;#100
           en=1;i=64;#100
           en=1;i=128;
           end
endmodule
