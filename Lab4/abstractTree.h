#ifndef ABSTRACTSYNTAX_H

#define ABSTRACTSYNTAX_H

#include "parser_tab.h"

struct AST {
    enum yytokentype type;
    union {
        struct {
                struct AST *const_vars;
                struct AST *vars;
                struct AST *funcProcDecl;
                struct AST *compoundstmt;
        } AST_PROGRAM;

        struct {
            char **ids;
        } AST_VARDECL;

        struct {
            char **ids;
            struct AST *vars;
            struct AST **statements;
        } AST_FUNCPROCDECL;

        struct {
            union {
                struct {
                    struct AST *lhs;
                    struct AST *arithexpr;
                } first;

                struct {

                } second;

                struct {

                } fourth;

                struct 
            } statetypes;
        } AST_COMPOUNTSTMT;
        struct {} AST_PARAMETERS;
        struct {} AST_STMT;
        struct {} AST_GUARD;
        struct {} AST_LHS;
        struct {} AST_PROCEDURECALL;
        struct {} AST_ARITHEXPRLIST;
        struct {} AST_ARITHEXPR;
    } nonterms
}

#endif
