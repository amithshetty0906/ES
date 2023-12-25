
module ringc(
    input clk,load,
    output reg [3:0]q
    );
       integer i;
    initial
    begin
    q = 4'b0001;
    end
    always @(posedge clk)
    begin
    if(load==1'b1)
    begin
    if(q==4'b1000)
    begin
    for(i=1;i<=3;i=i+1)
    begin
    q=q/4'b0010;
    #5;
    end
    end
    q=q+q;
    end
    end
    
endmodule






