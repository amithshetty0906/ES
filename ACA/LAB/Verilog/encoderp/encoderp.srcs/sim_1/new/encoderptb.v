
module encoderptb( );
    reg en;
    reg [7:0]i;
    wire [3:0]y;
    encoderp dut(.en(en),.i(i),.y(y));
    initial 
    begin
    en=1'b0;
    i=0;
    #100;
    en=1'b1;
    i=2'd14;
    end
endmodule
