`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   16:00:23 09/15/2020
// Design Name:   sram1
// Module Name:   E:/xilinx project/sram1/sram1_tb.v
// Project Name:  sram1
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: sram1
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module sram1_tb;

	// Inputs
	reg clk;
	reg we;
	reg [4:0] addr;
	reg [3:0] din;

	// Outputs
	wire [3:0] dout;

	// Instantiate the Unit Under Test (UUT)
	sram1 uut (
		.clk(clk), 
		.we(we), 
		.addr(addr), 
		.din(din), 
		.dout(dout)
	);

	initial begin
		// Initialize Inputs
		clk = 0;
		we = 0;
		addr = 0;
		din = 0;

		
        #20 we=1'b1;

#20 addr=5'b00001;din=4'b0001;

#20 addr=5'b00010;din=4'b0010;

#20 addr=5'b00011;din=4'b0011;

#20 addr=5'b00100;din=4'b0100;

#20 addr=5'b00101;din=4'b0101;

#20 addr=5'bxxxxx;din=4'bxxxx;

#20 we=1'b0;

#20 addr=5'b00001;

#20 addr=5'b00010;

#20 addr=5'b00011;

#20 addr=5'b00100;

#20 addr=5'b00101;

end

always #20 clk = ~clk;

initial #300 $stop;
		


      
endmodule

