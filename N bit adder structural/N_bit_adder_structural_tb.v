`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   23:32:42 09/05/2020
// Design Name:   N_bit_adder
// Module Name:   E:/xilinx project/N_bit_adder_structural/N_bit_adder_structural_tb.v
// Project Name:  N_bit_adder_structural
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: N_bit_adder
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module N_bit_adder_structural_tb;

	// Inputs
	reg [31:0] input1;
	reg [31:0] input2;

	// Outputs
	wire [31:0] answer;

	// Instantiate the Unit Under Test (UUT)
	N_bit_adder uut (
		.input1(input1), 
		.input2(input2), 
		.answer(answer)
	);

	initial begin
		// Initialize Inputs
		input1 = 120;
		input2 = 340;

		// Wait 100 ns for global reset to finish
		#100;
        
		// Add stimulus here

	end
	//initial begin
	//$monitor("answer=%b, input1=%b, input2=%b \n", answer,input1,input2);
	//end
      
endmodule

