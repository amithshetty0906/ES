`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 17.08.2023 15:45:45
// Design Name: 
// Module Name: encoder
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


module encoder(

   
    input [7:0]i,
    input en,
    output reg [2:0]y );
    always @(en,i)
    if(en==1)
    begin
    case(i)
    8'b00000001:y=0;
     8'b00000010:y=1;
      8'b00000100:y=2;
       8'b00001000:y=3;
        8'b00010000:y=4;
         8'b00100000:y=5;
          8'b01000000:y=6;
           8'b10000000:y=7;
           default: y=3'bzzz;
         endcase
         end
         else
         y=3'bzzz;
         
    
endmodule
