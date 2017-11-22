module inXn(
input [63:0] X,
input [7:0] n,
output [7:0] R1,
output [7:0] R2,
output [7:0] R3,
output [7:0] R4,
);

assign R1 = x%m1;
assign R2 = x%m2;
assign R3 = x%m3;
assign R4 = x%m4;

endmodule

module p1(
input [7:0] n,
input [7:0] R1,
input [7:0] R2,
input [7:0] R3,
output [15:0] p1
);

assign p1 = ((((2^(2*n-1)+2^(n-1))*R1)-(2^n*R2)+(2^(n-1)+2^(2*n)-1-2^(2*n-1))*R3)%(2^(2*n)-1))%2^n;

endmodule

module p2(
input [7:0] R2,
input [7:0] n,
input [15:0] p1,
output [24:0] p2
);

assign p2 = p1*2^n+R2;

endmodule

module p3(
input [7:0] n,
input [7:0] R1,
input [7:0] R2,
input [7:0] R3,
output [15:0] p3
);

assign p3 = ((((2^(2*n-1)+2^(n-1))*R1)-(2^n*R2)+(2^(n-1)+2^(2*n)-1-2^(2*n-1))*R3)%(2^(2*n)-1));

endmodule

module countW(
input [7:0] n,
output [7:0] w
);

wire [15:0] temp;
assign temp=n;
assign w=0;
integer i;

for(i=1,n, i++; w+=2^temp)
begin
	temp=temp-2;
	if(temp==2)
		begin
		w+=2;
		break;
		end;
end


endmodule

module S1(
input [7:0] R1,
input [7:0] R2,
input [7:0] n,
output [7:0] S1
);

assign S1=(R1-(R2%2^n))%(2^n-1); 

endmodule

module S2(
input [8:0] R4,
input [15:0] w,
input [15:0] p1,
input [24:0] p2,
input [7:0] n,
output [7:0] S2
);		

assign S2=(p1+(((R4-p2)*w)%(2^(n+1)-1))*(-1))%2^n;

endmodule

module S3(
input [7:0] R2,
input [8:0] R3,
input [7:0] n,
output [8:0] S3
);

assign S3=(R2%2^n-R3)%(2^n+1);

endmodule

module S4(
input [8:0] R4,
input [15:0] Q0,
input [24:0] Q2,
output [8:0] S4
);

assign S4 = (Q0+(R4+ 511-Q2%511)*338*127 )%511;

endmodule



/* ---------------------------- Test bench ----------------------------  */ 
module Main_tb();

reg [7:0] r1;
reg [7:0] r2;
reg [8:0] r3;
reg [8:0] r4;

wire [15:0] q0;
wire [24:0] q2;

wire [7:0] s1;
wire [7:0] s2;
wire [8:0] s3;
wire [8:0] s4;

S1 mod_s1(
.R1(r1),
.R2(r2),
.S1(s1)
);

S3 mod_s3(
.R2(r2),
.R3(r3),
.S3(s3)
);

Q0 mod_q0(
.R1(r1),
.R2(r2),
.R3(r3),
.Q0(q0)
);

Q2 mod_q2(
.R2(r2),
.Q0(q0),
.Q2(q2)
);

S2 mod_s2(
.R4(r4),
.Q0(q0),
.Q2(q2),
.S2(s2)
);

S4 mod_s4(
.R4(r4),
.Q0(q0),
.Q2(q2),
.S4(s4)
);

initial
 begin
 r1 = 8'b00000011;
 r2 = 8'b11111111;
 r3 = 9'b011111100;
 r4 = 9'b011111111;
 end

initial
 begin
 $monitor ("S1: %d\nS2: %d\nS3: %d\nS4: %d", s1, s2, s3, s4);
 end
endmodule


