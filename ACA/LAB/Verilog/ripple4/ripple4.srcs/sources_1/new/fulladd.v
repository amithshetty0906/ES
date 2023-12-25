module fulladd(input a,b,c,output sum,carry);
wire w;
   assign sum=(a^b^c);
   assign carry=((a&b)|(c &(a^b)));
endmodule