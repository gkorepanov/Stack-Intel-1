    scan
    call factorial
    push ecx
    print
    end


    proc factorial
        //pop argument from stack
        pop eax
        
        // if n == 0
        cmp eax 0
            je fact_end
        // else
            //save eax = n
            push eax

            //push argument for call
	    dec eax
            push eax
            call factorial

            //push (n-1)
            push ecx
            mul
            pop ecx
            jmp fact_ret

    fact_end:
            mov ecx 1   
    fact_ret:
    ret
    
