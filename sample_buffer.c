#include "HLS/hls.h"
#include "HLS/ac_fixed.h"
#include "fir.h"

hls_avalon_slave_component component 
void sample_buffer(hls_avalon_slave_memory_argument(SAMPLE_SIZE*sizeof(float)) float* sample_buffer,
                                                    hls_stable_argument hls_avalon_slave_register_argument int N,
                                                    ihc::stream_out<ac_16_2_f>& sample_out) {
   for (int i = 0; i < N; ++i){
      sample_out.write(sample_buffer[i]);
   }
}