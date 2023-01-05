`timescale 1ns/1ps

module kendall_rank(kendall, i0_x, i0_y, i1_x, i1_y, i2_x, i2_y, i3_x, i3_y);
//DO NOT CHANGE!
    input  [3:0] i0_x, i0_y, i1_x, i1_y, i2_x, i2_y, i3_x, i3_y;
    output [3:0] kendall;
//-------------------------------------------------
    
    wire[5:0] comp_res;
    wire[2:0] result_count;
    wire[6:0] true_result;
   // wire[1:0] temp_rs1,temp_rs2;
    COMP comp0(.is_discordant(comp_res[0]),.inx0(i0_x[3:0]),.inx1(i1_x[3:0]),.iny0(i0_y[3:0]),.iny1(i1_y[3:0]));
    COMP comp1(.is_discordant(comp_res[1]),.inx0(i0_x[3:0]),.inx1(i2_x[3:0]),.iny0(i0_y[3:0]),.iny1(i2_y[3:0]));
    COMP comp2(.is_discordant(comp_res[2]),.inx0(i0_x[3:0]),.inx1(i3_x[3:0]),.iny0(i0_y[3:0]),.iny1(i3_y[3:0]));
    COMP comp3(.is_discordant(comp_res[3]),.inx0(i1_x[3:0]),.inx1(i2_x[3:0]),.iny0(i1_y[3:0]),.iny1(i2_y[3:0]));
    COMP comp4(.is_discordant(comp_res[4]),.inx0(i1_x[3:0]),.inx1(i3_x[3:0]),.iny0(i1_y[3:0]),.iny1(i3_y[3:0]));
    COMP comp5(.is_discordant(comp_res[5]),.inx0(i2_x[3:0]),.inx1(i3_x[3:0]),.iny0(i2_y[3:0]),.iny1(i3_y[3:0]));
    
    //DISADD discordcount(.DISRESLT(result_count),.INP(comp_res[5:0]));
     //CALKENDALL calculate(.kdl(kendall),.num(result_count));
    ADDCOUNT addcnt(.TRERESLT(true_result[6:0]),.INP(comp_res[5:0]));
    ADDKANDALL addkdl(.kdl(kendall[3:0]),.inpx(true_result[6:0]));
    
   
   

endmodule
module COMP(is_discordant ,inx0,inx1,iny0,iny1);
   input [3:0] inx0,inx1,iny0,iny1;
   output is_discordant;
    wire rst1,rst2;
    SPCOM compx(.reslt(rst1),.in_one(inx0[3:0]),.in_two(inx1[3:0]));
    SPCOM compy(.reslt(rst2),.in_one(iny0[3:0]),.in_two(iny1[3:0]));

    EO the_xor(is_discordant,rst1,rst2);
   
endmodule 
module  SPCOM(reslt,in_one,in_two);//1==in0>in1 , 0==in0<=in1
    input [3:0] in_one,in_two;
    output  reslt;
    wire [3:0] xors ;
    wire [2:0] zeros;
    //EO xor_0(xors[0],in_zero[0],in_one[0]);//MUX21H(Z,A,B,CTRL);
    //MUX21H mx21H_0(zeros[0],1'b0,in_one[0],xors[0]);
    IV invrt(xors[0],in_two[0]);
    AN2 ands(zeros[0],in_one[0],xors[0]);
    EO xor_1(xors[1],in_one[1],in_two[1]);//assign w=(CTRL)?B:A;	buf g1(Z,w);
    MUX21H mx21H_1(zeros[1],zeros[0],in_one[1],xors[1]);
    EO xor_2(xors[2],in_one[2],in_two[2]);
    MUX21H mx21H_2(zeros[2],zeros[1],in_one[2],xors[2]);
    EO xor_3(xors[3],in_one[3],in_two[3]);
    MUX21H mx21H_3(reslt,zeros[2],in_one[3],xors[3]);
   // AN2 final(reslt,zeros[3],1'b1);
endmodule
/*
module  CALKENDALL(kdl, num);
  //num[2]=a ,num[1]=b,num[0]=c;
  input [2:0] num;
  output [3:0] kdl;
  wire  inv_b;
  wire [3:0] sigwire;
// IV invert1(inv_num[2],num[2]); 
  IV invert2(inv_b,num[1]);
 // IV invert3(inv_num[0],num[0]);
  AN2 and2_1(kdl[3],num[2],num[2]);//first

  NR2 nor_1(sigwire[0],num[1],num[0]);
  OR2 or_1(kdl[2],num[2],sigwire[0]);//second

  EO xor_1(sigwire[1],num[2],num[0]);
  AN2 and2_2(kdl[1],sigwire[1],inv_b); 
  //thrid

  EO3 xor3_1(sigwire[2],num[2],num[1],num[0]);
  AN3 and3_1(sigwire[3],num[2],inv_b,num[0]);
  OR2 or_3(kdl[0],sigwire[2],sigwire[3]);



  
  //debugger*
endmodule
module DISADD(DISRESLT ,INP);
input [5:0] INP;
output [2:0] DISRESLT;
wire [1:0] resa,resb;//FA1(CO,S,A,B,CI);
wire karry;
FA1 faofa(resa[1],resa[0],INP[0],INP[1],INP[2]);
FA1 faofb(resb[1],resb[0],INP[3],INP[4],INP[5]);
//FA1 cnt0(karry,DISRESLT[0],resa[0],resb[0],1'b0);
HA1 cnt0(karry,DISRESLT[0],resa[0],resb[0]);
FA1 cnt1(DISRESLT[2],DISRESLT[1],resa[1],resb[1],karry);
endmodule
*/
module ADDCOUNT(TRERESLT ,INP);
input [5:0] INP;
output [6:0] TRERESLT;
wire [1:0] resa,resb,inv_resa,inv_resb;//FA1(CO,S,A,B,CI);
wire karry[13:0];
FA1 faofa(resa[1],resa[0],INP[0],INP[1],INP[2]);
FA1 faofb(resb[1],resb[0],INP[3],INP[4],INP[5]);
IV ivr1(inv_resa[1],resa[1]); 
IV ivr2(inv_resa[0],resa[0]);
IV ivr3(inv_resb[1],resb[1]); 
IV ivr4(inv_resb[0],resb[0]);
NR4 and4_6(TRERESLT[6],inv_resa[1],inv_resa[0],inv_resb[1],inv_resb[0]);

NR4 and4_5_1(karry[0],inv_resa[1],resa[0],inv_resb[1],inv_resb[0]);//10+11
NR4 and4_5_2(karry[1],inv_resa[1],inv_resa[0],inv_resb[1],resb[0]);//11+10
OR2 or2_5(TRERESLT[5],karry[0],karry[1]);

NR4 and4_4_1(karry[2],inv_resa[1],resa[0],inv_resb[1],resb[0]);//10+10
NR4 and4_4_2(karry[3],resa[1],inv_resa[0],inv_resb[1],inv_resb[0]);//01+11
NR4 and4_4_3(karry[4],inv_resa[1],inv_resa[0],resb[1],inv_resb[0]);//11+01
OR3 or3_4(TRERESLT[4],karry[2],karry[3],karry[4]);

NR4 and4_3_1(karry[5],inv_resa[1],inv_resa[0],resb[1],resb[0]);//11+00
NR4 and4_3_2(karry[6],inv_resa[1],resa[0],resb[1],inv_resb[0]);//10+01
NR4 and4_3_3(karry[7],resa[1],inv_resa[0],inv_resb[1],resb[0]);
NR4 and4_3_4(karry[8],resa[1],resa[0],inv_resb[1],inv_resb[0]);
OR4 or4_3(TRERESLT[3],karry[5],karry[6],karry[7],karry[8]);

NR4 and4_2_1(karry[9],resa[1],resa[0],inv_resb[1],resb[0]);
NR4 and4_2_2(karry[10],resa[1],inv_resa[0],resb[1],inv_resb[0]);
NR4 and4_2_3(karry[11],inv_resa[1],resa[0],resb[1],resb[0]);
OR3 or3_2(TRERESLT[2],karry[9],karry[10],karry[11]);

NR4 and4_1_1(karry[12],resa[1],resa[0],resb[1],inv_resb[0]);
NR4 and4_1_2(karry[13],resa[1],inv_resa[0],resb[1],resb[0]);
OR2 or2_1(TRERESLT[1],karry[12],karry[13]);

NR4 and4_0(TRERESLT[0],resa[1],resa[0],resb[1],resb[0]);//00+00


endmodule
module ADDKANDALL(kdl,inpx);
input [6:0] inpx;
output [3:0] kdl;
OR3 g1(kdl[3],inpx[6],inpx[5],inpx[4]);
OR4 g2(kdl[2],inpx[6],inpx[5],inpx[4],inpx[0]);
OR2 g3(kdl[1],inpx[4],inpx[1]);
OR4 g4(kdl[0],inpx[5],inpx[4],inpx[2],inpx[1]);

endmodule