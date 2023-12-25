
module ringtb(

    );
    reg clk;
    reg load;
    wire [3:0]q;
    ringc c1(.clk(clk),.q(q),.load(load));
    initial
    begin 
    clk =1'b0;
    end
    always #5 clk=~clk;
    initial
    begin
    load=1'b0;
    #30;
    load=1'b1;
    
    #500;
    load=1'b0;
    end
endmodule
