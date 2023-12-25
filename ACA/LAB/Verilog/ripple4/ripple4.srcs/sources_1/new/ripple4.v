module ripple4(a,b,cin,sum,carry);
 output carry;
 output [3:0]sum;
 input [3:0]a,b;
 input cin;
wire c0,c1,c2;
 //instantiate
 fulladd FA0(a[0], b[0],cin,sum[0],c0); 
  fulladd FA1(a[1],b[1],c0,sum[1],c1); 
   fulladd FA2(a[2],b[2],c1,sum[2],c2); 
    fulladd FA3(a[3],b[3],c2,sum[3],carry); 
endmodule