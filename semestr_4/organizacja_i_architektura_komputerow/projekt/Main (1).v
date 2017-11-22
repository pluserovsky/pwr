module Q0(
input [7:0] R1,
input [7:0] R2,
input [8:0] R3,
output [15:0] Q0
);

assign Q0 = ( ( 32896 * R1 - 256 * R2 + 32895 * R3 + 65535 ) % 65535 ) % 256;

endmodule

module Q2(
input [7:0] R2,
input [15:0] Q0,
output [24:0] Q2
);

assign Q2 = Q0 * 256 + R2;

endmodule

module S1(
input [7:0] R1,
input [7:0] R2,
output [7:0] S1
);

assign S1 = (R1 - (R2 % 256)+255)%255; 

endmodule

module S2(
input [8:0] R4,
input [15:0] Q0,
input [24:0] Q2,
output [7:0] S2
);		

			
wire [7:0] q1;
wire [7:0] q3;
wire [8:0] q2m511;
wire [33:0] x;
wire [8:0] xm511;

assign q3 = 338;
assign q1 = Q0 & 255;
assign q2m511 = Q2 - (Q2 / 511) * 511;
assign x = (R4 + 511 - q2m511 ) * 338;
assign xm511 = x - (x / 511) * 511;

assign S2 = (q1 - xm511) & 255;

endmodule

module S3(
input [7:0] R2,
input [8:0] R3,
output [8:0] S3
);

assign S3 =  ((R2 % 256) - R3)%257;

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


