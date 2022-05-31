//#include "HLS/hls.h"
//#include "HLS/ac_fixed.h"
#include "fir.h"

component 
void fir_filter(ihc::stream_in<ac_16_2_f>& fir_in,
                ihc::stream_out<ac_32_3_f>& fir_out){

  static const ac_16_2_f coeffs[COEFFICIENTS] = {0.180603,0.045044,0.723145,0.347412,
                                                 0.660522,0.383850,0.627319,0.021606,
                                                 0.910522,0.800537,0.745789,0.813110,
                                                 0.383301,0.617249,0.575439,0.530029};

  static ac_16_2_f taps[COEFFICIENTS];

  ac_32_3_f y = 0.0;

  // shift in input data
  #pragma unroll
  for(int i = (COEFFICIENTS - 1); i > 0; --i) {
    taps[i] = taps[i-1];
  }
  taps[0] = fir_in.read();

  // accumulate over all taps
  #pragma unroll
  for(int i = (COEFFICIENTS - 1); i >= 0; --i) {
    y += taps[i] * coeffs[i];
  }

  fir_out.write(y);
}