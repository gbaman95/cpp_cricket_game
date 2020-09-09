`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   23:31:28 09/08/2020
// Design Name:   sram
// Module Name:   E:/xilinx project/sram/sram_tb.v
// Project Name:  sram
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: sram
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module sram_tb;

	// Inputs
	reg [7:0] Addr;
	reg CS;
	reg WE;
	reg RD;
	reg Clk;
	reg [7:0] dataIn;

	// Outputs
	wire [7:0] dataOut;

	// Instantiate the Unit Under Test (UUT)
	sram uut (
		.Addr(Addr), 
		.CS(CS), 
		.WE(WE), 
		.RD(RD), 
		.Clk(Clk), 
		.dataIn(dataIn), 
		.dataOut(dataOut)
	);

	 initial begin

  // Initialize Inputs

  dataIn  = 8'h0;

  Addr  = 8'h0;

  CS  = 1'b0;

  WE  = 1'b0;

  RD  = 1'b0;

  Clk  = 1'b0;


  // Wait 100 ns for global reset to finish

  #100;

       

  // Add stimulus here

  dataIn  = 8'h0;

  Addr  = 8'h0;

  CS  = 1'b1;

  WE  = 1'b1;

  RD  = 1'b0;

  #20;

  dataIn  = 8'h0;

  Addr  = 8'h0;

  #20;

  dataIn  = 8'h1;

  Addr  = 8'h1;

  #20;

  dataIn  = 8'h10;

  Addr  = 8'h2;

  #20;

  dataIn  = 8'h6;

  Addr  = 8'h3;

  #20;

  dataIn  = 8'h12;

  Addr  = 8'h4;

  #40;

  Addr  = 8'h0;

  WE  = 1'b0;

  RD  = 1'b1;

  #20;

  Addr   = 8'h1;

  #20;

  Addr   = 8'h2;

  #20;

  Addr   = 8'h3;

  #20;

  Addr   = 8'h4;

 end

  always #10 Clk = ~Clk;

 

endmodule