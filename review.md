# Review
- Concept of lvalues and rvalues
- Return and failure states of std functions
- Error handling in C++, throw, catch and exceptions
- STD Move
- How to get more familiar with std library functions
- Member initializations
- STD::String, stringview and char interoperability
- Unique ptr, shared ptr
- endl flushing
- 

# To remember
ClassName() = default;	Calls the default constructor
ClassName() = delete;	Forbids this constructor
std::move, std::array, std::vector

# To do
- Split FT_UTILS in C and C++

# To Learn
- gotos, function caching (instruction cache misses, code memory)
- batch rendering
- your old matlab functions from linear systems
- Asserts, constexpr, exceptions and trycatch, NDEBUG ifdefs
- look up dual-issue, superscalar, and CPU pipelines if you want a REAL deep dive
- constructing floats in hardware registers, why do compilers load from memory
- 
  
  
# Style guidelines
- Member variables with trailing underscore (e.g. name_)
- Constants with k prefix (kConstant)
- 


# Delivery
- Check makefile for name
- Check makefile for -Werror
- Include guards


static __attribute__((always_inline)) __attribute__((const)) float cf(const float f)
{
    u32 r;
    float f_out;

    u32 i = *(u32 *) (&f);

    if (!__builtin_constant_p(i)) {
        return *(float *) (&i);
    }

    u32 upper = (i >> 16);
    u32 lower = (i >> 0) & 0xFFFF;

    if ((i & 0xFFFF) == 0)
	{
        __asm__("lui %0, %1" : "=r"(r) : "K"(upper));
	}
    else if ((i & 0xFFFF0000) == 0)
	{
        __asm__("addiu %0, $0, %1" : "+r"(r) : "K"(lower));
	}
    else
    {
        __asm__("lui %0, %1" : "=r"(r) : "K"(upper));
        __asm__("addiu %0, %0, %1" : "+r"(r) : "K"(lower));
    }

    __asm__("mtc1 %1, %0" : "=f"(f_out) : "r"(r));
    return f_out;
}