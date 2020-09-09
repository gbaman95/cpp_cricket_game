`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   10:55:07 09/08/2020
// Design Name:   traffic_light_control
// Module Name:   E:/xilinx project/traffic_light_control/traffic_light_control_tb.v
// Project Name:  traffic_light_control
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: traffic_light_control
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

`define clk_period 1000000000
module traffic_light_control_tb();

	// Inputs
	reg clk;
	reg rst;

	// Outputs
	wire [2:0] light_A;
	wire [2:0] light_B;

	// Instantiate the Unit Under Test (UUT)
	traffic_light_control uut (
		.clk(clk), 
		.rst(rst), 
		.light_A(light_A), 
		.light_B(light_B)
	);
	
	initial clk = 1;
	always #(`clk_period/ 2) clk = ~clk;

	initial begin
		// Initialize Inputs
		rst = 0;
		#`clk_period;
		
	   rst = 1;
		# `clk_period;
		
		rst = 0;
		#(`clk_period*200);
		
		$stop;

		// Wait 100 ns for global reset to finish
		//#100;
        
		// Add stimulus here

	end
      
endmodule

