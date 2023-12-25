`timescale 1ns / 1ps



module halfadd(
    input a,
    input b,
    output s,
    output c
    );
    assign s=a^b;
    assign c=a&b;
endmodule
