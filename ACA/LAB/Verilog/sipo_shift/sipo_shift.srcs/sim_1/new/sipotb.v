`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 09.10.2023 12:59:02
// Design Name: 
// Module Name: sipotb
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


module sipotb(

    );
    reg clk,b;
    wire [3:0]q;
    sipo_shift uut(.clk(clk),.b(b),.q(q));
    initial
    begin
    clk=1'b0;
    forever #5 clk=~clk;
    end
    initial
    begin
    b=1; #10;
       b=0; #10;
          b=1; #10;
             b=0;
        
end
        

    
endmodule
