`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   16:16:52 09/03/2020
// Design Name:   xor_bh
// Module Name:   E:/xilinx project/xor1_bh/xor1_bh_tb.v
// Project Name:  xor1_bh
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: xor_bh
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module xor1_bh_tb;

	// Inputs
	reg A;
	reg B;

	// Outputs
	wire Y;

	// Instantiate the Unit Under Test (UUT)
	xor_bh uut (
		.Y(Y), 
		.A(A), 
		.B(B)
	);

	initial begin
		// Initialize Inputs
		A = 0;
		B = 0;

		// Wait 100 ns for global reset to finish
		#100;
        
		// Add stimulus here

A = 0;
B=1;
#100;

A=1;
B=0;
#100;

A=1;
B=1;
#100;
	end
      
endmodule

