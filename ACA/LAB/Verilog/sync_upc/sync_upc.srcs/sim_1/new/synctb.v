
 module synctb(

    );
    reg clk,rst;
    wire [2:0]count;
    sync_upc s1(.clk(clk),.rst(rst),.count(count));
    initial begin
    clk=0;
    rst=0;
    #10;
    rst=1;
    #10;
    rst=0;
    end
   always #10 clk=~clk; 
endmodule
