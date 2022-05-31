#include "HLS/hls.h"
#include "HLS/ac_fixed.h"
#include "fir.h"

component
void result_buffer(hls_avalon_slave_memory_argument(SAMPLE_SIZE*sizeof(float)) float* result_buffer,
                   ihc::stream_in<ac_32_3_f>& result_in) {
   static int count;
   ac_32_3_f temp = result_in.read();
   result_buffer[count++] = temp.to_double();
}