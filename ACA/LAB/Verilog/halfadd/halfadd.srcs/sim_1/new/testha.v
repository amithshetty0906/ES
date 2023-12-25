`timescale 1ns / 1ps



module testha(

    );
    reg t_a,t_b;
    wire s,c;
    halfadd ha(.a(t_a),.b(t_b),.s(s),.c(c));
    initial begin
    t_a=0;t_b=0;
    #100;
    t_a=1;t_b=0;
    #100;
    t_a=0;t_b=1;
    #100;
    t_a=1;t_b=1;
    #100;
    
    
    
    end
endmodule
