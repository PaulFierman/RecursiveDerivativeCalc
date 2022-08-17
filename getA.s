/* Paul Fierman */

.file "getA.s"        #optional directive 
.section .rodata        #required directives for rodata 

.data
#required for file scope data: read-write program data
#of static storage class 

.globl getA
#required directive for every function 
        .type getA, @function       #required directive  
        .text
        #required directive - code begins here 

        getA:
                pushq %rbp
                movq %rsp, %rbp

                movq $0, %rax           #rax have the new value of A

                cmpq $0, %rsi           #compare B to 0
                JE end                  #if second param 'B' AKA the exponent is 0 then derivative is 0

                movq %rdi, %rdx         #copy of first param 'A' to empty 3rd param slot
                movq %rsi, %rcx         #copy of second param 'B' to empty 4th param slot

                movq $0, %r8            #count starting at 1
                loop:
                        cmpq %r8, %rdx
                        JE end
                        addq %rcx, %rax         #multiply exponent 'B' by prefix 'A'... move result of multiply to rax to be returned
                        incq %r8
                        JMP loop

                end:
                        leave                   #return stack to original values
                        ret                     #return
