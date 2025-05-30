.global _start
/*
Steps
1. set cpu mode to svc
2. set stack pointer
3. jump to main
*/

_start:
    // 1. set cpu mode to svc 
    // cpu mode is set in cpsr (current program status register)
    // mov are not allowed to read from cpsr. Only use mrs to read cpsr and msr to write cpsr
    mrs r0, cpsr          // read current cpsr and store in r0
    bic r0, r0, #0x1F    // clear mode bits (bits 0-4)
    orr r0, r0, #0x13    // set mode to SVC
    msr cpsr, r0         // write back to cpsr

    // 2. set stack pointer
    ldr sp, =0x 80200000  // set stack pointer to 0x80200000

    // 3. jump to main
    j main              // jump to main function
