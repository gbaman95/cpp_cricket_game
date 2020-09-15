`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    15:58:09 09/15/2020 
// Design Name: 
// Module Name:    sram1 
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
module sram1( addr, din, dout,clk, we,);
input clk;

input we;

input [3:0] din;  // input
input [4:0] addr;



output [3:0] dout;    //output 

reg [3:0] ram [31:0];

reg [3:0] dout;

always @(clk)

begin

if (we)

ram[addr] = din;

else

dout = ram[addr];

end


endmodule
