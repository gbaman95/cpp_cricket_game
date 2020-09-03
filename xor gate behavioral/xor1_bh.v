`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    21:44:51 08/31/2020 
// Design Name: 
// Module Name:    xor1_bh 
// Project Name: 
// Target Devices: 
// Tool versions: 
// Description: 
//
// Dependencies: 
//
// Revision: 
// Revision 0.01 - File Created
// Additional Comments: 
//
//////////////////////////////////////////////////////////////////////////////////
module xor_bh(Y,A,B);
    input A;
    input B;
    output Y;
	 reg Y;
    
always @(A,B)

begin

if(A==0 & B==0)
Y = 0;
else if(A==1 & B==1)
Y=0;
else 
Y=1;

end

endmodule
