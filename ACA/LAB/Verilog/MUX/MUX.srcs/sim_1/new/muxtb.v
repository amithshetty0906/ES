`timescale 1ns / 1ps


module muxtb(

    );
    reg[7:0]i;
    reg[2:0]s;
    wire y;
    mux81 uut(.i(i),.s(s),.y(y));
    initial begin
    i=8'b01010101;s=0;
    #100;s=1;
     #100;s=2;
      #100;s=3;
       #100;s=4;
        #100;s=5;
         #100;s=6;
          #100;s=7;
          end
endmodule
