`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    23:16:46 09/08/2020 
// Design Name: 
// Module Name:    sram 
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
module sram( Addr, CS, WE, RD, Clk, dataIn, dataOut );

input   [7:0]  dataIn;
input   [7:0]  Addr;
output reg [7:0]  dataOut;
input CS, WE, RD, Clk;
reg [7:0] SRAM [7:0];

always @ (posedge Clk)

begin

 if (CS == 1'b1) 
 begin

  if (WE == 1'b1 && RD == 1'b0) 
  begin

   SRAM [Addr] = dataIn;
	end 
	
	  else if (RD == 1'b1 && WE == 1'b0) begin

   dataOut = SRAM [Addr]; 

  end

  else;

 end

 else;

end

 
endmodule
