# Extra matching tips for the local LLM loop (tools/match/llm_iterate.py appends them to its
# system prompt). One tip per line; lines starting with # are ignored. Add a line whenever a
# new trick matches a function.
- A global accessed as lui+addiu into a register and then fixed offsets (lh 0x106(a3)) is a struct: declare a small typedef with named fields and an alias of the global, `extern SFoo D_800DAF20_q asm("D_800DAF20");`, then use D_800DAF20_q.h106. A u8[] array or a cast folds the offset into %lo instead.
- An existing extern with the wrong type: declare your own alias under a new C name with asm("D_xxx") rather than changing the shared one; the same works for functions (`void f_q(u8 *) asm("func_X");`).
- Scratchpad addresses: `lui v1,0x1f80` followed by loads at offset 0x10 come from a struct at 0x1F800000 (`((S *)0x1F800000)->h10`); writing `*(s16 *)0x1F800010` instead gives lui+ori or a different base.
- s16 struct fields read into s32 locals keep `lh`; reading them into u16/s16 locals can turn into lhu plus sll/sra pairs.
- A product stored into a u16 field gets narrowed (lhu instead of lh before the mult): compute it into an s32 local first (`d = p->vx * n; p->x += d;`).
- When loads of two base addresses (lui/addiu pairs) come in the other order, try writing the index expression inline in the subscript (`A[b][k = h * 10 + i]`) or moving where the pointer is first used.
- A function-local variable reused for a second, unrelated purpose (same s register in both places) is one C variable in the original: reuse it.
- `x = i;` where i is known to be 0 at that point gives `move sN,sM` instead of `move sN,zero`.
- Each case of a switch repeating its own tail (`n++; break;`) reproduces cross-jumped tails; a switch with cases 0 and 1-2 gives a beqz/bltz/slti compare tree.
- A jump table followed by a zero word in the original's rodata needs `const s32 X_pad = 0;` after the function.
- A 2-arm clamp where both arms store to the same place may come from `if (v < -A) v = -A; else if (v > A) v = A;` on an s32 local, then a separate use.
- Struct copies (`*(T *)(p + 0x94) = v;`) of 16-byte vectors give the lw/lw/lw/lw then sw x4 pattern; an 8-byte copy of a struct of s16s gives lwl/lwr pairs.
- Reassign a variable instead of nesting the expression when the original keeps an intermediate in the same register (`z = 0x1FFF - z; y = (z * 96 >> 13) + 0x20;`).
