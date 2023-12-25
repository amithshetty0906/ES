module sipo(
    input clk,b,
    output [3:0]q
    );
    dff1 d1(.clk(clk),.d(b),.q(q[3]),.rst(rst));
    dff1 d2(.clk(clk),.d(q[3]),.q(q[2]),.rst(rst));
    dff1 d3(.clk(clk),.d(q[2]),.q(q[1]),.rst(rst));
    dff1 d4(.clk(clk),.d(q[1]),.q(q[0]),.rst(rst));
    
endmodule