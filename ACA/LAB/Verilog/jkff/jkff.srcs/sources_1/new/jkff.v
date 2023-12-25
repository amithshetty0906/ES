module jkff(q,qb,j,k,rst,clk);
output reg q;
output qb;
input j,k,rst,clk;
always @ (posedge clk)
begin
if(rst)
q=0;
else
if(j==0 && k==0)
q=q;
else
if(j==0 && k==1)
q=0;
else
if(j==1 && k==0)
q=1;
else
if(j==1 && k==1)
q=~q;
end
assign qb=~q;

endmodule