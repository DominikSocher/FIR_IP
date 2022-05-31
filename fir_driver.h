/*
 * fir_driver.h
 *
 *  Created on: 01.02.2022
 *      Author: Dominik
 */

#ifndef FIR_DRIVER_H_
#define FIR_DRIVER_H_

#include "sample_buffer_csr.h"

//read and write to component
#define fir_write(offset,data)   IOWR_32DIRECT(BUFFER_0_SAMPLE_BUFFER_INTERNAL_INST_AVS_CRA_BASE, offset, data)
#define fir_read(offset)         IORD_32DIRECT(BUFFER_0_SAMPLE_BUFFER_INTERNAL_INST_AVS_CRA_BASE, offset)
//register macros
#define fir_enable_interrupt()   fir_write(SAMPLE_BUFFER_CSR_INTERRUPT_ENABLE_REG, SAMPLE_BUFFER_CSR_INTERRUPT_ENABLE_MASK & 0x1)
#define fir_disable_interrupt()  fir_write(SAMPLE_BUFFER_CSR_INTERRUPT_ENABLE_REG, SAMPLE_BUFFER_CSR_INTERRUPT_ENABLE_MASK & 0x0)
#define fir_clear_done_status()  fir_write(SAMPLE_BUFFER_CSR_INTERRUPT_STATUS_REG, SAMPLE_BUFFER_CSR_INTERRUPT_ENABLE_MASK & 0x1)
#define fir_start()              fir_write(SAMPLE_BUFFER_CSR_START_REG, SAMPLE_BUFFER_CSR_START_MASK & 0x1)
#define fir_busy()               fir_read(SAMPLE_BUFFER_CSR_BUSY_REG) & SAMPLE_BUFFER_CSR_BUSY_MASK
#define fir_done()               fir_read(SAMPLE_BUFFER_CSR_INTERRUPT_STATUS_REG) & SAMPLE_BUFFER_CSR_INTERRUPT_STATUS_MASK
//write data to fir
#define fir_arg_n(data)          fir_write(SAMPLE_BUFFER_CSR_ARG_N_REG, SAMPLE_BUFFER_CSR_ARG_N_MASK & data)

#define sample_memory_write(offset, data) IOWR_32DIRECT(BUFFER_0_SAMPLE_BUFFER_INTERNAL_INST_AVS_SAMPLE_BUFFER_BASE, offset, data)
#define sample_memory_read(offset)        IORD_32DIRECT(BUFFER_1_RESULT_BUFFER_INTERNAL_INST_BASE, offset)



#endif /* FIR_DRIVER_H_ */
