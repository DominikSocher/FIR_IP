#ifndef _H_FIR_H_
#define _H_FIR_H_

#define COEFFICIENTS 16
#define SAMPLE_SIZE 320

#include "HLS/hls.h"
#include "HLS/ac_fixed.h"

// Declaration of data types
typedef ac_fixed<16,2,false> ac_16_2_f;
typedef ac_fixed<32,3,false> ac_32_3_f;

// Declaration of functions
// Sample buffer
hls_avalon_slave_component component 
void sample_buffer(hls_avalon_slave_memory_argument(SAMPLE_SIZE*sizeof(float)) float* sample_buffer,
                   hls_stable_argument hls_avalon_slave_register_argument int N,
                   ihc::stream_out<ac_16_2_f>& sample_out);
                   
// FIR filter
component 
void fir_filter(ihc::stream_in<ac_16_2_f>& fir_in,
                ihc::stream_out<ac_32_3_f>& fir_out);

// Result buffer
component 
void result_buffer(hls_avalon_slave_memory_argument(SAMPLE_SIZE*sizeof(float)) float* result_buffer,
                   ihc::stream_in<ac_32_3_f>& result_in);

#endif // _H_FIR_H_
