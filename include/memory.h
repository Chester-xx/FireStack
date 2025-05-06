/* ---------------- Linker Map ---------------- */
#ifndef MEM_H
#define MEM_H

/* ---------------- Defines ---------------- */


/* ---------------- Function Prototype Signatures ---------------- */


/* ---------------- Class Definitions + Function Prototype Signatures ---------------- */
class memory
{
    private:
        /* data */
    public:
        // constr and destr
        memory();
        ~memory();
        
        // returns the memory address of given data
        template<typename t>
        static t* pAddress(t& data) {
            return &data;
        }
        // returns the memory address of given const data
        template<typename t>
        static const t* pAddress(const t& data) {
            return &data;
        }

    protected:
        /*  */
};

#endif