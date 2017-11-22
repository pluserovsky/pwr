module s1(
inout [31:0] x,
inout [7:0] n,
output [31:0] S1);

wire [31:0] n1,m1,m2,R1,R2;
integer S1;

assign m1=2**n-1;
assign m2=2**n;
assign R1 = x%m1;
assign R2 = x%m2;


initial begin

S1=(R1-(R2%2**n)+(2**n-1))%(2**n-1);

$display("x=%d\n",x);
$display("n=2^%d\n",n);
$display("S1=%d\n",S1);

end
endmodule

module s3(
inout [31:0] x,
inout [7:0] n,
output [31:0] S3);

wire [31:0] m2,m3,R2,R3;

integer S3;

assign m2=2**n;
assign m3=2**n+1;
assign R2 = x%m2;
assign R3 = x%m3;

initial begin

S3=(R2%2**n-R3)%(2**n+1);

$display("S3=%d\n",S3);

end
endmodule

module s2(
inout [31:0] x,
inout [7:0] n,
output [31:0] S2);

wire [31:0] m1,m2,m3,m4,R1,R2,R3,R4;
wire [43:0] p1,p2;

integer S2,i,w,temp;

assign m1=2**n-1;
assign m2=2**n;
assign m3=2**n+1;
assign m4=2**(n+1)-1;
assign R1 = x%m1;
assign R2 = x%m2;
assign R3 = x%m3;
assign R4 = x%m4;

		
assign p1 = ((((2**(2*n-1)+2**(n-1))*R1)-(2**n*R2)+(2**(n-1)+2**(2*n)-1-2**(2*n-1))*R3)%(2**(2*n)-1))%2**n; 
assign p2 = p1*2**n+R2; 


initial begin
w=0;
temp=n;
begin : block
for(i=1;i<=n; i++ )
begin 
    w+=2**temp;
	temp=temp-2;
	if(temp==2)
		begin
		w+=2;
		disable block;
		end;
end
end

S2=(p1+(((R4-p2)*w)%(2**(n+1)-1))*(-1))%2**n;

$display("S2=%d\n",S2);


end
endmodule

module s4(
inout [31:0] x,
inout [7:0] n,
output [31:0] S4
);

wire [31:0] m1,m2,m3,m4,R1,R2,R3,R4;
wire [62:0] p1,p2;
integer S4,i,w,temp;

assign m1=2**n-1;
assign m2=2**n;
assign m3=2**n+1;
assign m4=2**(n+1)-1;
assign R1 = x%m1;
assign R2 = x%m2;
assign R3 = x%m3;
assign R4 = x%m4;
		
assign p1 = ((((2**(2*n-1)+2**(n-1))*R1)-(2**n*R2)+(2**(n-1)+2**(2*n)-1-2**(2*n-1))*R3)%(2**(2*n)-1))%(2**n);
assign p2 = (p1*(2**n))+R2; 


initial begin
w=0;
temp=n;
begin : block
for(i=1;i<=n; i++ )
begin 
    w+=2**temp;
	temp=temp-2;
	if(temp==2)
		begin
		w+=2;
		disable block;
		end;
end
end

S4 = (p1+((R4-p2)*w)*(2**(n-1)-1))%(2**(n+1)-1);

$display("S4=%d\n",S4);

end
endmodule

module test();


wire [31:0] x=31'd1073741823;
wire [7:0] y=8'd8;

s1 S1(.x(x),.n(y));
s2 S2(.x(x),.n(y));
s3 S3(.x(x),.n(y));
s4 S4(.x(x),.n(y));

endmodule