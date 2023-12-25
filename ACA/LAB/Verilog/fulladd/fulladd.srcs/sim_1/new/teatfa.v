`timescale 1ns / 1ps



module teatfa(

    );
    reg ta,tb,tc;
    wire su,ca;
    fulladd fa(.a(ta),.b(tb),.c(tc),.s(su),.ca(ca));
    initial begin
    ta=0;tb=0;tc=0; #10
    ta=0;tb=0;tc=1; #10
    ta=0;tb=1;tc=0; #10
    ta=1;tb=0;tc=0; #10
    ta=1;tb=0;tc=1; #10
    ta=1;tb=1;tc=1;
    
    end
endmodule
