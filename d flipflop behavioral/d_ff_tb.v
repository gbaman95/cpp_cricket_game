`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   21:29:18 09/03/2020
// Design Name:   d_ff
// Module Name:   E:/xilinx project/d_ff/d_ff_tb.v
// Project Name:  d_ff
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: d_ff
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module d_ff_tb;

	// Inputs
	reg clk;
	reg d;

	// Outputs
	wire q;

	// Instantiate the Unit Under Test (UUT)
	d_ff uut (
		.q(q), 
		.clk(clk), 
		.d(d)
	);

	initial begin
		// Initialize Inputs
		clk = 0;
		d = 0;

	end 
	always #4 clk=~clk;
	always #8 d=~d;
	
	initial #50 $stop;
		  
	
      
endmodule

