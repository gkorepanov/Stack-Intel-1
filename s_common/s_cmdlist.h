// Template: CMD_(number, word, number of arguments, code)

CMD_(0, end, 0, "", {})

CMD_(1, push, 1, "n", {
    stack_push(This->stack, *(int*)(This->cmds+This->pos+1));
})

CMD_(2, push, 1, "r", {
    int reg_number = *(int*)(This->cmds+This->pos+1);
    stack_push(This->stack, reg_get(*(int*)(This->cmds+This->pos+1), This->regs));
})

CMD_(3, pop, 0, "", { 
    stack_pop(This->stack);
})

CMD_(4, pop, 1, "r", {
    reg_put(*(int*)(This->cmds+This->pos+1), stack_pop(This->stack), This->regs);
})

CMD_(5, add, 0, "", { 
    int a = stack_pop(This->stack);
    int b = stack_pop(This->stack);
    stack_push(This->stack, a+b);
})

CMD_(6, sub, 0, "", { 
    int a = stack_pop(This->stack);
    int b = stack_pop(This->stack);
    stack_push(This->stack, a-b);
})

CMD_(7, mul, 0, "", { 
    int a = stack_pop(This->stack);
    int b = stack_pop(This->stack);
    stack_push(This->stack, a*b);
})

CMD_(8, print, 0, "", { 
    printf("OUT: %d\n", stack_top(This->stack));
})

CMD_(9, scan, 0, "", {
    printf("IN: ");
    int num = 0;
    scanf("%d", &num);
    stack_push(This->stack, num);
})

CMD_(10, dump, 0, "", {
    stack_dump(This->stack);
})

CMD_(11, mov, 2, "rn", {
    reg_put(*(int*)(This->cmds+This->pos+1), *(int*)(This->cmds+This->pos+5), This->regs);
})

CMD_(12, mov, 2, "rr", {
    reg_put(*(int*)(This->cmds+This->pos+1), reg_get(*(int*)(This->cmds+This->pos+5), This->regs), This->regs);
})

CMD_(13, cmp, 2, "rn", {
   int a = reg_get(*(int*)(This->cmds+This->pos+1), This->regs);
   int b = *(int*)(This->cmds+This->pos+5);
   This->regs->flags[ZF] = !(a-b);
   This->regs->flags[SF] = ((a-b) < 0) ? 1 : 0;
})

CMD_(14, cmp, 2, "rr", {
   int a = reg_get(*(int*)(This->cmds+This->pos+1), This->regs);
   int b = reg_get(*(int*)(This->cmds+This->pos+5), This->regs);

   This->regs->flags[ZF] = !(a-b);
   This->regs->flags[SF] = ((a-b) < 0) ? 1 : 0;
   DBGPRINT("ZF: %d, SF: %d\n", This->regs->flags[ZF], This->regs->flags[SF]); 
})

CMD_(15, jmp, 1, "l", {
    (This->pos) += (*(int*)(This->cmds+This->pos+1)-5);
})

CMD_(16, je, 1, "l", {
    if (This->regs->flags[ZF])
        (This->pos) += (*(int*)(This->cmds+This->pos+1)-5);
})

CMD_(17, jne, 1, "l", {
    if (!(This->regs->flags[ZF]))
        (This->pos) += (*(int*)(This->cmds+This->pos+1)-5);
})

CMD_(18, ja, 1, "l", {
    DBGPRINT("ZF: %d, SF: %d\n", This->regs->flags[ZF], This->regs->flags[SF]); 
    if (!(This->regs->flags[ZF]) && !(This->regs->flags[SF])) 
        (This->pos) += (*(int*)(This->cmds+This->pos+1)-5);
})

CMD_(19, jb, 1, "l", {
    if (!(This->regs->flags[ZF]) && (This->regs->flags[SF])) 
        (This->pos) += (*(int*)(This->cmds+This->pos+1)-5);
})

CMD_(20, jae, 1, "l", {
    if (!(This->regs->flags[SF]))
        (This->pos) += (*(int*)(This->cmds+This->pos+1)-5);
})

CMD_(21, jbe, 1, "l", {
    if (!(This->regs->flags[ZF]) || (This->regs->flags[SF])) 
        (This->pos) += (*(int*)(This->cmds+This->pos+1)-5);
})

CMD_(22, call, 1, "f", {
    stack_push(This->stack_ret, This->pos+5);
    (This->pos) += (*(int*)(This->cmds+This->pos+1)-5);
})

CMD_(23, ret, 0, "", {
    This->pos = stack_pop(This->stack_ret) - 1;
})

CMD_(24, inc, 1, "r", {
    int reg_number = *(int*)(This->cmds+This->pos+1);
    reg_put(reg_number, reg_get(reg_number, This->regs) + 1, This->regs);
})

CMD_(25, dec, 1, "r", {
    int reg_number = *(int*)(This->cmds+This->pos+1);
    reg_put(reg_number, reg_get(reg_number, This->regs) - 1, This->regs);
})
