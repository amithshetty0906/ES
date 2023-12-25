module srtb;
reg s,r,clk,rst;
wire q,qb;
srff s1(q,qb,s,r,rst,clk);
initial
clk=0;
always #10 clk=~clk;
initial
begin
rst=1;rst=1;r=0;
#10;rst=0;
#10;s=0;r=0;
#10;s=0;r=1;
#10;s=1;r=0;
#10;s=1;r=1;
#10;rst=1;
end
endmodule
