

module encoderp(
    input en,
    input [7:0]i,
    output reg [2:0]y
    );
    always @(en,i)
    begin
    if(en==1'b1)
    begin
    if(i[7]==1'b1)
    y=3'b111;
    else if(i[6]==1'b1)
    y=6;
     else if(i[5]==1'b1)
    y=5;
     else if(i[4]==1'b1)
    y=4;
     else if(i[3]==1'b1)
    y=3;
     else if(i[2]==1'b1)
    y=2;
     else if(i[1]==1'b1)
    y=1;
     else if(i[0]==1'b1)
    y=0;
  end
  end
endmodule
