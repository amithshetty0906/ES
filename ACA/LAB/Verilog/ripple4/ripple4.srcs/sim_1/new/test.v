
module test( );
    reg  [3:0]a,b;
    reg cin;
    wire cout;
    wire  [3:0]sum;
    ripple4 r1(a,b,cin,sum,cout);
    initial begin
    $monitor($time,"cout=%b,sum=%b,a=%b,b=%b,cin=%b",cout,sum,a,b,cin); 
    a=4'b1101;
    b=4'b0011;
    cin=0;
    #50;
    a=4'b1100;
    b=4'b0111;
    cin=0;
    #50;
    a=4'b1111;
    b=4'b1111;
    cin=0;
    #50;
    
    end
endmodule
