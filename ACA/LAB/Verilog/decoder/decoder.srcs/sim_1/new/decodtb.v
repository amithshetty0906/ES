
module decodtb(

    );
    reg en,a,b;
    wire [3:0]y;
    decod d1(en,a,b,y);
    initial
    begin
    en=1;a=1'bx;b=1'bx;
    #10;en=0;a=0;b=0;
    #10;en=0;a=0;b=1;
    #10;en=0;a=1;b=0;
    #10;en=0;a=1;b=1;
    end
    
endmodule
