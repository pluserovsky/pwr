scalling(x,n) =
{
	m1=2^n-1;
	m2=2^n;
	m3=2^n+1;
	m4=2^(n+1)-1;
	M=m1*m2*m3*m4;
	
	R1 = x%m1;
	R2 = x%m2;
	R3 = x%m3;
	R4 = x%m4;
	
	p1 = ((((2^(2*n-1)+2^(n-1))*R1)-(2^n*R2)+(2^(n-1)+2^(2*n)-1-2^(2*n-1))*R3)%(2^(2*n)-1))%2^n;   \\ podloga z R31 zmodulowana 2^n
	p2 = p1*2^n+R2; \\ R31

	temp=n;
	w=0;
	for(i=1,n, i++; w+=2^temp;
	temp=temp-2;
	if(temp==2,
	w+=2;
	break;)
	);
	
	S1=(R1-(R2%2^n))%(2^n-1);
	S3=(R2%2^n-R3)%(2^n+1);
	S2=(p1+(((R4-p2)*w)%(2^(n+1)-1))*(-1))%2^n;
	S4=(p1+((R4-p2)*w)*(2^(n-1)-1))%(2^(n+1)-1);

	print("\nSet reszt z CRT:\nR1:", R1, " R2:", R2, " R3:", R3, " R4:", R4);
	print("\nParametr S1 = ",S1);
	print("\nParametr S2 = ",S2);
	print("\nParametr S3 = ",S3);
	print("\nParametr S4 = ",S4);
}
