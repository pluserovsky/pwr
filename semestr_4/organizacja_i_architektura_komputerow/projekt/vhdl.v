module scalling;
input [7:0] m;
input [7:0] n;
output [31:0] S1;
output [31:0] S2;
output [31:0] S3;
output [31:0] S4;

wire [7:0] m=8'b00011110; //30
wire [7:0] n=8'b00001000; //8

wire [31:0] x,
		n1,	//liczba 2^n
		R1, R2, R3, R4, //reszty wejsciowe
		M, //iloczyn m1-m4
		m1, m2, m3, m4, //moduly crt
		R31;

integer R31f,rx,S1,S2,S3,S4,w=0,temp,i;
//WPROWADZANIE DZIELNEJ DO PAMIECI 2^x-1		
assign x=(2**m)-1;
//WPROWADZANIE DZIELNIKA
assign n1=2**n;
//liczenie modulow wjesciowych
assign m1=(2**n)-1;
assign m2=(2**n);
assign m3=(2**n)+1;
assign m4=(2**(n+1)-1);
//liczenie reszt
assign	R1 = x%m1;
assign	R2 = x%m2;
assign	R3 = x%m3;
assign	R4 = x%m4;

assign R31 = R1*n1 + R2;

initial begin

R31f = $floor(R31 / n1);
rx = $floor(x / n1);
S1 = rx % m1;
S3 = rx % m3;
//obliczanie wideł
temp=n;
for (i = 1; i < n / 2; i=i+1)
	begin
		w = w + 2**temp;
		temp = temp - 2;
		if (temp == 2) 
		begin		
		w = w + 2;
		end
	end

	S2 = ($floor((x)/m2)) % n1;
	S4 =($floor((x)/m2)) %  m4;

$display("x=%d\n",x);
$display("n=%d\n",n1);
$display("m1=%d\n",m1);
$display("m2=%d\n",m2);
$display("m3=%d\n",m3);
$display("m4=%d\n",m4);
$display("R1=%d\n",R1);
$display("R2=%d\n",R2);
$display("R3=%d\n",R3);
$display("R4=%d\n",R4);
$display("R31=%d\n",R31);
$display("R31f=%d\n",R31f);
$display("rx=%d\n",rx);
$display("w=%d\n",w);
$display("S1=%d\n",S1);
$display("S2=%d\n",S2);
$display("S2=%d\n",S3);
$display("S4=%d\n",S4);
end
endmodule