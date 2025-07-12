.global _start
.global _bss_start
_bss_start:
    .word __bss_start
.global _bss_end
_bss_end:
    .word __bss_end

/*
Steps
1. set cpu mode to svc
2. clear bss section
3. set stack pointer
4. jump to main
*/

_start:
    // 1. set cpu mode to svc 
    // cpu mode is set in cpsr (current program status register)
    // mov are not allowed to read from cpsr. Only use mrs to read cpsr and msr to write cpsr
    mrs r0, cpsr          // read current cpsr and store in r0
    bic r0, r0, #0x1F    // clear mode bits (bits 0-4)
    orr r0, r0, #0x13    // set mode to SVC
    msr cpsr, r0         // write back to cpsr
    
    // 2. clear bss section
    ldr r0, _bss_start
    ldr r1, _bss_end
    mov r2, #0
bss_clear_loop:
    stmia r0, {r2}  // store 0 to current address in r0 and increment r0
    cmp r0, r1  // compare current address with end address
    ble bss_clear_loop  // loop until r0 reaches r1

    // 3. set stack pointer
    ldr sp, =0x80200000  // set stack pointer to 0x80200000

    // 4. jump to main
    b main              // jump to main function
