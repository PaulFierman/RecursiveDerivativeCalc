* Paul Fierman */

.file "getB.s"
.section .rodata

.data

.globl getB
#required directive for every function 
        .type getB, @function
.text

         getB:
                pushq %rbp
                movq %rsp, %rbp

                movq $0, %rax           #rax have the new value of B
                movq %rdi, %rdx         #copy of first param 'B' to empty 3rd param slot        
                cmpq $0, %rdi           #compare B to 0
                JE end                  #if 'B' is 0 there is no adjustment to make

                decq %rdx
                movq %rdx, %rax


                end:
                        leave                   #return stack to original values
                        ret                     #return
