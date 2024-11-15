/* DO NOT EDIT.
 * Generated by ../bin/vtkEncodeString
 * 
 * Define the vtkHAVSVolumeMapper_k2BeginFP string.
 *
 * Generated from file: /home/adelelakour/CLionProjects/An_effi_Ransac_RealSense-master/vtk-5.10.0/VolumeRendering/vtkHAVSVolumeMapper_k2BeginFP.asm
 */
#include "vtkHAVSVolumeMapper_k2BeginFP.h"
const char *vtkHAVSVolumeMapper_k2BeginFP =
"!!ARBfp1.0\n"
"#------------------------------------------------------------------------------\n"
"# Copyright 2005 by University of Utah\n"
"#\n"
"# Hardware-Assisted Visibility Sorting\n"
"#\n"
"# The program consists of the following steps:\n"
"#\n"
"# 1. Clear k-buffers entries 1 and 2 to -1.0\n"
"# \n"
"# The following textures are used:\n"
"# \n"
"#   Tex 1: k-buffer entries 1 and 2 (same)\n"
"#\n"
"\n"
"# -----------------------------------------------------------------------------\n"
"# use the ATI_draw_buffers extension\n"
"OPTION ATI_draw_buffers;\n"
"# this does not matter now, but will matter on future hardware\n"
"OPTION ARB_precision_hint_nicest;\n"
"\n"
"MOV result.color[0], 0.0;\n"
"MOV result.color[1], -1.0;\n"
"\n"
"END\n"
"\n";

