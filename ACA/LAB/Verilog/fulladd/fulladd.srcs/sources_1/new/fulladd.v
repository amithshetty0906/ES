`timescale 1ns / 1ps



module fulladd(
    input a,
    input b,
    input c,
    output s,
    output ca
    );
    assign s=a^b^c;
    assign ca=(a&b)|c&(a^b);
endmodule
