module s1(
input [7:0] R1,
input [7:0] R2,
input [7:0] n,
output [7:0] S1);

assign S1=(R1-(R2%2**n)+(2**n-1))%(2**n-1);

endmodule

module s3(
input [7:0] R2,
input [8:0] R3,
input [7:0] n,
output [8:0] S3);

assign S3=(R2%2**n-R3)%(2**n+1);

endmodule

module p(
input [7:0] R1,
input [7:0] R2,
input [8:0] R3,
input [7:0] n,
output [15:0] p1,
output [24:0] p2
);

assign p1 = ((((2**(2*n-1)+2**(n-1))*R1)-(2**n*R2)+(2**(n-1)+2**(2*n)-1-2**(2*n-1))*R3)%(2**(2*n)-1))%2**n;
assign p2 = p1*2**n+R2;  

endmodule

module s2(
input [15:0] p1,
input [24:0] p2,
input [8:0] R4,
input [7:0] n,
output [7:0] S2);

integer i,temp,w;
		
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
end

assign S2=(p1+(((R4-p2)*w)%(2**(n+1)-1))*(-1))%2**n;


endmodule

module s4(
input [15:0] p1,
input [24:0] p2,
input [8:0] R4,
input [7:0] n,
output [8:0] S4);

integer i,temp,w;	

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
end
assign S4 = (p1+((R4-p2)*w)*(2**(n-1)-1))%(2**(n+1)-1);

endmodule

module test();

reg [7:0] r1;
reg [7:0] r2;
reg [8:0] r3;
reg [8:0] r4;

wire [15:0] p1;
wire [24:0] p2;

wire [7:0] ss1;
wire [7:0] ss2;
wire [8:0] ss3;
wire [8:0] ss4;

wire [7:0] n= 8'd8;

s1 S1(
.R1(r1),
.R2(r2),
.n(n),
.S1(ss1)
);

s3 S3(
.R2(r2),
.R3(r3),
.n(n),
.S3(ss3)
);

p P(
.R1(r1),
.R2(r2),
.R3(r3),
.n(n),
.p1(p1),
.p2(p2)
);

s2 S2(
.p1(p1),
.p2(p2),
.R4(r4),
.n(n),
.S2(ss2)
);

s4 S4(
.p1(p1),
.p2(p2),
.R4(r4),
.n(n),
.S4(ss4)
);

initial
 begin
 r1 = 8'd63;
 r2 = 8'd255;
 r3 = 9'd192;
 r4 = 9'd7;
  $monitor ("S1: %d\nS2: %d\nS3: %d\nS4: %d", ss1, ss2, ss3, ss4);
 end

endmodule