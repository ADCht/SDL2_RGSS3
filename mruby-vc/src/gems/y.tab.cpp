/* A Bison parser, made by GNU Bison 2.7.  */

#pragma warning(disable : 4996)

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 7 "D:\\Desktop\\parse.y"

#undef PARSER_DEBUG
#ifdef PARSER_DEBUG
# define YYDEBUG 1
#endif
#define YYERROR_VERBOSE 1
#define YYSTACK_USE_ALLOCA 1

#include <ctype.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <mruby.h>
#include <mruby/compile.h>
#include <mruby/proc.h>
#include <mruby/error.h>
#include <mruby/throw.h>
#include <mruby/string.h>
#include "node.h"

#define YYLEX_PARAM p

typedef mrb_ast_node node;
typedef struct mrb_parser_state parser_state;
typedef struct mrb_parser_heredoc_info parser_heredoc_info;

static int yyparse(parser_state *p);
static int yylex(void *lval, parser_state *p);
static void yyerror(parser_state *p, const char *s);
static void yywarn(parser_state *p, const char *s);
static void yywarning(parser_state *p, const char *s);
static void backref_error(parser_state *p, node *n);
static void void_expr_error(parser_state *p, node *n);
static void tokadd(parser_state *p, int32_t c);

#define identchar(c) (ISALNUM(c) || (c) == '_' || !ISASCII(c))

typedef unsigned int stack_type;

#define BITSTACK_PUSH(stack, n) ((stack) = ((stack)<<1)|((n)&1))
#define BITSTACK_POP(stack)     ((stack) = (stack) >> 1)
#define BITSTACK_LEXPOP(stack)  ((stack) = ((stack) >> 1) | ((stack) & 1))
#define BITSTACK_SET_P(stack)   ((stack)&1)

#define COND_PUSH(n)    BITSTACK_PUSH(p->cond_stack, (n))
#define COND_POP()      BITSTACK_POP(p->cond_stack)
#define COND_LEXPOP()   BITSTACK_LEXPOP(p->cond_stack)
#define COND_P()        BITSTACK_SET_P(p->cond_stack)

#define CMDARG_PUSH(n)  BITSTACK_PUSH(p->cmdarg_stack, (n))
#define CMDARG_POP()    BITSTACK_POP(p->cmdarg_stack)
#define CMDARG_LEXPOP() BITSTACK_LEXPOP(p->cmdarg_stack)
#define CMDARG_P()      BITSTACK_SET_P(p->cmdarg_stack)

#define SET_LINENO(c,n) ((c)->lineno = (n))
#define NODE_LINENO(c,n) do {\
  if (n) {\
     (c)->filename_index = (n)->filename_index;\
     (c)->lineno = (n)->lineno;\
  }\
} while (0)

#define sym(x) ((mrb_sym)(intptr_t)(x))
#define nsym(x) ((node*)(intptr_t)(x))
#define nint(x) ((node*)(intptr_t)(x))
#define intn(x) ((int)(intptr_t)(x))

#if defined(MRB_COMPLEX_NUMBERS) || defined(MRB_RATIONAL_NUMBERS)
  #define MRB_SUFFIX_SUPPORT

  #ifdef MRB_RATIONAL_NUMBERS
    #define NUM_SUFFIX_R   (1<<0)
  #else
    #define NUM_SUFFIX_R   0
  #endif

  #ifdef MRB_COMPLEX_NUMBERS
    #define NUM_SUFFIX_I   (1<<1)
  #else
    #define NUM_SUFFIX_I   0
  #endif

  #define NUM_SUFFIX_ALL (NUM_SUFFIX_R | NUM_SUFFIX_I)
#endif

static inline mrb_sym
intern_cstr_gen(parser_state *p, const char *s)
{
  return mrb_intern_cstr(p->mrb, s);
}
#define intern_cstr(s) intern_cstr_gen(p,(s))

static inline mrb_sym
intern_gen(parser_state *p, const char *s, size_t len)
{
  return mrb_intern(p->mrb, s, len);
}
#define intern(s,len) intern_gen(p,(s),(len))

static inline mrb_sym
intern_gen_c(parser_state *p, const char c)
{
  return mrb_intern(p->mrb, &c, 1);
}
#define intern_c(c) intern_gen_c(p,(c))

static void
cons_free_gen(parser_state *p, node *cons)
{
  cons->cdr = p->cells;
  p->cells = cons;
}
#define cons_free(c) cons_free_gen(p, (c))

static void*
parser_palloc(parser_state *p, size_t size)
{
  void *m = mrb_pool_alloc(p->pool, size);

  if (!m) {
    MRB_THROW(p->jmp);
  }
  return m;
}

static node*
cons_gen(parser_state *p, node *car, node *cdr)
{
  node *c;

  if (p->cells) {
    c = p->cells;
    p->cells = p->cells->cdr;
  }
  else {
    c = (node *)parser_palloc(p, sizeof(mrb_ast_node));
  }

  c->car = car;
  c->cdr = cdr;
  c->lineno = p->lineno;
  c->filename_index = p->current_filename_index;
  /* beginning of next partial file; need to point the previous file */
  if (p->lineno == 0 && p->current_filename_index > 0) {
    c->filename_index-- ;
  }
  return c;
}
#define cons(a,b) cons_gen(p,(a),(b))

static node*
list1_gen(parser_state *p, node *a)
{
  return cons(a, 0);
}
#define list1(a) list1_gen(p, (a))

static node*
list2_gen(parser_state *p, node *a, node *b)
{
  return cons(a, cons(b,0));
}
#define list2(a,b) list2_gen(p, (a),(b))

static node*
list3_gen(parser_state *p, node *a, node *b, node *c)
{
  return cons(a, cons(b, cons(c,0)));
}
#define list3(a,b,c) list3_gen(p, (a),(b),(c))

static node*
list4_gen(parser_state *p, node *a, node *b, node *c, node *d)
{
  return cons(a, cons(b, cons(c, cons(d, 0))));
}
#define list4(a,b,c,d) list4_gen(p, (a),(b),(c),(d))

static node*
list5_gen(parser_state *p, node *a, node *b, node *c, node *d, node *e)
{
  return cons(a, cons(b, cons(c, cons(d, cons(e, 0)))));
}
#define list5(a,b,c,d,e) list5_gen(p, (a),(b),(c),(d),(e))

static node*
list6_gen(parser_state *p, node *a, node *b, node *c, node *d, node *e, node *f)
{
  return cons(a, cons(b, cons(c, cons(d, cons(e, cons(f, 0))))));
}
#define list6(a,b,c,d,e,f) list6_gen(p, (a),(b),(c),(d),(e),(f))

static node*
append_gen(parser_state *p, node *a, node *b)
{
  node *c = a;

  if (!a) return b;
  if (!b) return a;
  while (c->cdr) {
    c = c->cdr;
  }
  c->cdr = b;
  return a;
}
#define append(a,b) append_gen(p,(a),(b))
#define push(a,b) append_gen(p,(a),list1(b))

static char*
parser_strndup(parser_state *p, const char *s, size_t len)
{
  char *b = (char *)parser_palloc(p, len+1);

  memcpy(b, s, len);
  b[len] = '\0';
  return b;
}
#undef strndup
#define strndup(s,len) parser_strndup(p, s, len)

static char*
parser_strdup(parser_state *p, const char *s)
{
  return parser_strndup(p, s, strlen(s));
}
#undef strdup
#define strdup(s) parser_strdup(p, s)

static void
dump_int(uint16_t i, char *s)
{
  char *p = s;
  char *t = s;

  while (i > 0) {
    *p++ = (i % 10)+'0';
    i /= 10;
  }
  if (p == s) *p++ = '0';
  *p = 0;
  p--;  /* point the last char */
  while (t < p) {
    char c = *t;
    *t++ = *p;
    *p-- = c;
  }
}

/* xxx ----------------------------- */

static node*
local_switch(parser_state *p)
{
  node *prev = p->locals;

  p->locals = cons(0, 0);
  return prev;
}

static void
local_resume(parser_state *p, node *prev)
{
  p->locals = prev;
}

static void
local_nest(parser_state *p)
{
  p->locals = cons(0, p->locals);
}

static void
local_unnest(parser_state *p)
{
  if (p->locals) {
    p->locals = p->locals->cdr;
  }
}

static mrb_bool
local_var_p(parser_state *p, mrb_sym sym)
{
  node *l = p->locals;

  while (l) {
    node *n = l->car;
    while (n) {
      if (sym(n->car) == sym) return TRUE;
      n = n->cdr;
    }
    l = l->cdr;
  }
  return FALSE;
}

static void
local_add_f(parser_state *p, mrb_sym sym)
{
  if (p->locals) {
    p->locals->car = push(p->locals->car, nsym(sym));
  }
}

static void
local_add(parser_state *p, mrb_sym sym)
{
  if (!local_var_p(p, sym)) {
    local_add_f(p, sym);
  }
}

static void
local_add_blk(parser_state *p, mrb_sym blk)
{
  /* allocate register for block */
  local_add_f(p, blk ? blk : mrb_intern_lit(p->mrb, "&"));
}

static void
local_add_kw(parser_state *p, mrb_sym kwd)
{
  /* allocate register for keywords hash */
  local_add_f(p, kwd ? kwd : mrb_intern_lit(p->mrb, "**"));
}

static node*
locals_node(parser_state *p)
{
  return p->locals ? p->locals->car : NULL;
}

/* (:scope (vars..) (prog...)) */
static node*
new_scope(parser_state *p, node *body)
{
  return cons((node*)NODE_SCOPE, cons(locals_node(p), body));
}

/* (:begin prog...) */
static node*
new_begin(parser_state *p, node *body)
{
  if (body) {
    return list2((node*)NODE_BEGIN, body);
  }
  return cons((node*)NODE_BEGIN, 0);
}

#define newline_node(n) (n)

/* (:rescue body rescue else) */
static node*
new_rescue(parser_state *p, node *body, node *resq, node *els)
{
  return list4((node*)NODE_RESCUE, body, resq, els);
}

static node*
new_mod_rescue(parser_state *p, node *body, node *resq)
{
  return new_rescue(p, body, list1(list3(0, 0, resq)), 0);
}

/* (:ensure body ensure) */
static node*
new_ensure(parser_state *p, node *a, node *b)
{
  return cons((node*)NODE_ENSURE, cons(a, cons(0, b)));
}

/* (:nil) */
static node*
new_nil(parser_state *p)
{
  return list1((node*)NODE_NIL);
}

/* (:true) */
static node*
new_true(parser_state *p)
{
  return list1((node*)NODE_TRUE);
}

/* (:false) */
static node*
new_false(parser_state *p)
{
  return list1((node*)NODE_FALSE);
}

/* (:alias new old) */
static node*
new_alias(parser_state *p, mrb_sym a, mrb_sym b)
{
  return cons((node*)NODE_ALIAS, cons(nsym(a), nsym(b)));
}

/* (:if cond then else) */
static node*
new_if(parser_state *p, node *a, node *b, node *c)
{
  void_expr_error(p, a);
  return list4((node*)NODE_IF, a, b, c);
}

/* (:unless cond then else) */
static node*
new_unless(parser_state *p, node *a, node *b, node *c)
{
  void_expr_error(p, a);
  return list4((node*)NODE_IF, a, c, b);
}

/* (:while cond body) */
static node*
new_while(parser_state *p, node *a, node *b)
{
  void_expr_error(p, a);
  return cons((node*)NODE_WHILE, cons(a, b));
}

/* (:until cond body) */
static node*
new_until(parser_state *p, node *a, node *b)
{
  void_expr_error(p, a);
  return cons((node*)NODE_UNTIL, cons(a, b));
}

/* (:for var obj body) */
static node*
new_for(parser_state *p, node *v, node *o, node *b)
{
  void_expr_error(p, o);
  return list4((node*)NODE_FOR, v, o, b);
}

/* (:case a ((when ...) body) ((when...) body)) */
static node*
new_case(parser_state *p, node *a, node *b)
{
  node *n = list2((node*)NODE_CASE, a);
  node *n2 = n;

  void_expr_error(p, a);
  while (n2->cdr) {
    n2 = n2->cdr;
  }
  n2->cdr = b;
  return n;
}

/* (:postexe a) */
static node*
new_postexe(parser_state *p, node *a)
{
  return cons((node*)NODE_POSTEXE, a);
}

/* (:self) */
static node*
new_self(parser_state *p)
{
  return list1((node*)NODE_SELF);
}

/* (:call a b c) */
static node*
new_call(parser_state *p, node *a, mrb_sym b, node *c, int pass)
{
  node *n = list4(nint(pass?NODE_CALL:NODE_SCALL), a, nsym(b), c);
  void_expr_error(p, a);
  NODE_LINENO(n, a);
  return n;
}

/* (:fcall self mid args) */
static node*
new_fcall(parser_state *p, mrb_sym b, node *c)
{
  node *n = new_self(p);
  NODE_LINENO(n, c);
  n = list4((node*)NODE_FCALL, n, nsym(b), c);
  NODE_LINENO(n, c);
  return n;
}

/* (:super . c) */
static node*
new_super(parser_state *p, node *c)
{
  return cons((node*)NODE_SUPER, c);
}

/* (:zsuper) */
static node*
new_zsuper(parser_state *p)
{
  return list1((node*)NODE_ZSUPER);
}

/* (:yield . c) */
static node*
new_yield(parser_state *p, node *c)
{
  if (c) {
    if (c->cdr) {
      yyerror(p, "both block arg and actual block given");
    }
    return cons((node*)NODE_YIELD, c->car);
  }
  return cons((node*)NODE_YIELD, 0);
}

/* (:return . c) */
static node*
new_return(parser_state *p, node *c)
{
  return cons((node*)NODE_RETURN, c);
}

/* (:break . c) */
static node*
new_break(parser_state *p, node *c)
{
  return cons((node*)NODE_BREAK, c);
}

/* (:next . c) */
static node*
new_next(parser_state *p, node *c)
{
  return cons((node*)NODE_NEXT, c);
}

/* (:redo) */
static node*
new_redo(parser_state *p)
{
  return list1((node*)NODE_REDO);
}

/* (:retry) */
static node*
new_retry(parser_state *p)
{
  return list1((node*)NODE_RETRY);
}

/* (:dot2 a b) */
static node*
new_dot2(parser_state *p, node *a, node *b)
{
  return cons((node*)NODE_DOT2, cons(a, b));
}

/* (:dot3 a b) */
static node*
new_dot3(parser_state *p, node *a, node *b)
{
  return cons((node*)NODE_DOT3, cons(a, b));
}

/* (:colon2 b c) */
static node*
new_colon2(parser_state *p, node *b, mrb_sym c)
{
  void_expr_error(p, b);
  return cons((node*)NODE_COLON2, cons(b, nsym(c)));
}

/* (:colon3 . c) */
static node*
new_colon3(parser_state *p, mrb_sym c)
{
  return cons((node*)NODE_COLON3, nsym(c));
}

/* (:and a b) */
static node*
new_and(parser_state *p, node *a, node *b)
{
  return cons((node*)NODE_AND, cons(a, b));
}

/* (:or a b) */
static node*
new_or(parser_state *p, node *a, node *b)
{
  return cons((node*)NODE_OR, cons(a, b));
}

/* (:array a...) */
static node*
new_array(parser_state *p, node *a)
{
  return cons((node*)NODE_ARRAY, a);
}

/* (:splat . a) */
static node*
new_splat(parser_state *p, node *a)
{
  return cons((node*)NODE_SPLAT, a);
}

/* (:hash (k . v) (k . v)...) */
static node*
new_hash(parser_state *p, node *a)
{
  return cons((node*)NODE_HASH, a);
}

/* (:kw_hash (k . v) (k . v)...) */
static node*
new_kw_hash(parser_state *p, node *a)
{
  return cons((node*)NODE_KW_HASH, a);
}

/* (:sym . a) */
static node*
new_sym(parser_state *p, mrb_sym sym)
{
  return cons((node*)NODE_SYM, nsym(sym));
}

static mrb_sym
new_strsym(parser_state *p, node* str)
{
  const char *s = (const char*)str->cdr->car;
  size_t len = (size_t)str->cdr->cdr;

  return mrb_intern(p->mrb, s, len);
}

/* (:lvar . a) */
static node*
new_lvar(parser_state *p, mrb_sym sym)
{
  return cons((node*)NODE_LVAR, nsym(sym));
}

/* (:gvar . a) */
static node*
new_gvar(parser_state *p, mrb_sym sym)
{
  return cons((node*)NODE_GVAR, nsym(sym));
}

/* (:ivar . a) */
static node*
new_ivar(parser_state *p, mrb_sym sym)
{
  return cons((node*)NODE_IVAR, nsym(sym));
}

/* (:cvar . a) */
static node*
new_cvar(parser_state *p, mrb_sym sym)
{
  return cons((node*)NODE_CVAR, nsym(sym));
}

/* (:const . a) */
static node*
new_const(parser_state *p, mrb_sym sym)
{
  return cons((node*)NODE_CONST, nsym(sym));
}

/* (:undef a...) */
static node*
new_undef(parser_state *p, mrb_sym sym)
{
  return list2((node*)NODE_UNDEF, nsym(sym));
}

/* (:class class super body) */
static node*
new_class(parser_state *p, node *c, node *s, node *b)
{
  void_expr_error(p, s);
  return list4((node*)NODE_CLASS, c, s, cons(locals_node(p), b));
}

/* (:sclass obj body) */
static node*
new_sclass(parser_state *p, node *o, node *b)
{
  void_expr_error(p, o);
  return list3((node*)NODE_SCLASS, o, cons(locals_node(p), b));
}

/* (:module module body) */
static node*
new_module(parser_state *p, node *m, node *b)
{
  return list3((node*)NODE_MODULE, m, cons(locals_node(p), b));
}

/* (:def m lv (arg . body)) */
static node*
new_def(parser_state *p, mrb_sym m, node *a, node *b)
{
  return list5((node*)NODE_DEF, nsym(m), locals_node(p), a, b);
}

/* (:sdef obj m lv (arg . body)) */
static node*
new_sdef(parser_state *p, node *o, mrb_sym m, node *a, node *b)
{
  void_expr_error(p, o);
  return list6((node*)NODE_SDEF, o, nsym(m), locals_node(p), a, b);
}

/* (:arg . sym) */
static node*
new_arg(parser_state *p, mrb_sym sym)
{
  return cons((node*)NODE_ARG, nsym(sym));
}

static void
local_add_margs(parser_state *p, node *n)
{
  while (n) {
    if (n->car->car == (node*)NODE_MASGN) {
      node *t = n->car->cdr->cdr;

      n->car->cdr->cdr = NULL;
      while (t) {
        local_add_f(p, sym(t->car));
        t = t->cdr;
      }
      local_add_margs(p, n->car->cdr->car->car);
      local_add_margs(p, n->car->cdr->car->cdr->cdr->car);
    }
    n = n->cdr;
  }
}

static void
local_add_lv(parser_state *p, node *lv)
{
  while (lv) {
    local_add_f(p, sym(lv->car));
    lv = lv->cdr;
  }
}

/* (m o r m2 tail) */
/* m: (a b c) */
/* o: ((a . e1) (b . e2)) */
/* r: a */
/* m2: (a b c) */
/* b: a */
static node*
new_args(parser_state *p, node *m, node *opt, mrb_sym rest, node *m2, node *tail)
{
  node *n;

  local_add_margs(p, m);
  local_add_margs(p, m2);
  n = cons(m2, tail);
  n = cons(nsym(rest), n);
  n = cons(opt, n);
  while (opt) {
    /* opt: (sym . (opt . lv)) -> (sym . opt) */
    local_add_lv(p, opt->car->cdr->cdr);
    opt->car->cdr = opt->car->cdr->car;
    opt = opt->cdr;
  }
  return cons(m, n);
}

/* (:args_tail keywords rest_keywords_sym block_sym) */
static node*
new_args_tail(parser_state *p, node *kws, node *kwrest, mrb_sym blk)
{
  node *k;

  if (kws || kwrest) {
    local_add_kw(p, (kwrest && kwrest->cdr)? sym(kwrest->cdr) : 0);
  }

  local_add_blk(p, blk);

  // allocate register for keywords arguments
  // order is for Proc#parameters
  for (k = kws; k; k = k->cdr) {
    if (!k->car->cdr->cdr->car) { // allocate required keywords
      local_add_f(p, sym(k->car->cdr->car));
    }
  }
  for (k = kws; k; k = k->cdr) {
    if (k->car->cdr->cdr->car) { // allocate keywords with default
      local_add_lv(p, k->car->cdr->cdr->car->cdr);
      k->car->cdr->cdr->car = k->car->cdr->cdr->car->car;
      local_add_f(p, sym(k->car->cdr->car));
    }
  }

  return list4((node*)NODE_ARGS_TAIL, kws, kwrest, nsym(blk));
}

/* (:kw_arg kw_sym def_arg) */
static node*
new_kw_arg(parser_state *p, mrb_sym kw, node *def_arg)
{
  mrb_assert(kw);
  return list3((node*)NODE_KW_ARG, nsym(kw), def_arg);
}

/* (:block_arg . a) */
static node*
new_block_arg(parser_state *p, node *a)
{
  return cons((node*)NODE_BLOCK_ARG, a);
}

/* (:block arg body) */
static node*
new_block(parser_state *p, node *a, node *b)
{
  return list4((node*)NODE_BLOCK, locals_node(p), a, b);
}

/* (:lambda arg body) */
static node*
new_lambda(parser_state *p, node *a, node *b)
{
  return list4((node*)NODE_LAMBDA, locals_node(p), a, b);
}

/* (:asgn lhs rhs) */
static node*
new_asgn(parser_state *p, node *a, node *b)
{
  void_expr_error(p, b);
  return cons((node*)NODE_ASGN, cons(a, b));
}

/* (:masgn mlhs=(pre rest post)  mrhs) */
static node*
new_masgn(parser_state *p, node *a, node *b)
{
  void_expr_error(p, b);
  return cons((node*)NODE_MASGN, cons(a, b));
}

/* (:masgn mlhs mrhs) no check */
static node*
new_masgn_param(parser_state *p, node *a, node *b)
{
  return cons((node*)NODE_MASGN, cons(a, b));
}

/* (:asgn lhs rhs) */
static node*
new_op_asgn(parser_state *p, node *a, mrb_sym op, node *b)
{
  void_expr_error(p, b);
  return list4((node*)NODE_OP_ASGN, a, nsym(op), b);
}

#ifdef MRB_COMPLEX_NUMBERS
static node*
new_imaginary(parser_state *p, node *imaginary)
{
  return new_call(p, new_const(p, intern_cstr("Kernel")), intern_cstr("Complex"), list1(list2(list3((node*)NODE_INT, (node*)strdup("0"), nint(10)), imaginary)), 1);
}
#endif

#ifdef MRB_RATIONAL_NUMBERS
static node*
new_rational(parser_state *p, node *rational)
{
  return new_call(p, new_const(p, intern_cstr("Kernel")), intern_cstr("Rational"), list1(list1(rational)), 1);
}
#endif

/* (:int . i) */
static node*
new_int(parser_state *p, const char *s, int base, int suffix)
{
  node* result = list3((node*)NODE_INT, (node*)strdup(s), nint(base));
#ifdef MRB_RATIONAL_NUMBERS
  if (suffix & NUM_SUFFIX_R) {
    result = new_rational(p, result);
  }
#endif
#ifdef MRB_COMPLEX_NUMBERS
  if (suffix & NUM_SUFFIX_I) {
    result = new_imaginary(p, result);
  }
#endif
  return result;
}

#ifndef MRB_WITHOUT_FLOAT
/* (:float . i) */
static node*
new_float(parser_state *p, const char *s, int suffix)
{
  node* result = cons((node*)NODE_FLOAT, (node*)strdup(s));
#ifdef MRB_RATIONAL_NUMBERS
  if (suffix & NUM_SUFFIX_R) {
    result = new_rational(p, result);
  }
#endif
#ifdef MRB_COMPLEX_NUMBERS
  if (suffix & NUM_SUFFIX_I) {
    result = new_imaginary(p, result);
  }
#endif
  return result;
}
#endif

/* (:str . (s . len)) */
static node*
new_str(parser_state *p, const char *s, size_t len)
{
  return cons((node*)NODE_STR, cons((node*)strndup(s, len), nint(len)));
}

/* (:dstr . a) */
static node*
new_dstr(parser_state *p, node *a)
{
  return cons((node*)NODE_DSTR, a);
}

static int
string_node_p(node *n)
{
  return (int)((enum node_type)(intptr_t)n->car == NODE_STR);
}

static node*
composite_string_node(parser_state *p, node *a, node *b)
{
  size_t newlen = (size_t)a->cdr + (size_t)b->cdr;
  char *str = (char*)mrb_pool_realloc(p->pool, a->car, (size_t)a->cdr + 1, newlen + 1);
  memcpy(str + (size_t)a->cdr, b->car, (size_t)b->cdr);
  str[newlen] = '\0';
  a->car = (node*)str;
  a->cdr = (node*)newlen;
  cons_free(b);
  return a;
}

static node*
concat_string(parser_state *p, node *a, node *b)
{
  if (string_node_p(a)) {
    if (string_node_p(b)) {
      /* a == NODE_STR && b == NODE_STR */
      composite_string_node(p, a->cdr, b->cdr);
      cons_free(b);
      return a;
    }
    else {
      /* a == NODE_STR && b == NODE_DSTR */

      if (string_node_p(b->cdr->car)) {
        /* a == NODE_STR && b->[NODE_STR, ...] */
        composite_string_node(p, a->cdr, b->cdr->car->cdr);
        cons_free(b->cdr->car);
        b->cdr->car = a;
        return b;
      }
    }
  }
  else {
    node *c; /* last node of a */
    for (c = a; c->cdr != NULL; c = c->cdr) ;

    if (string_node_p(b)) {
      /* a == NODE_DSTR && b == NODE_STR */
      if (string_node_p(c->car)) {
        /* a->[..., NODE_STR] && b == NODE_STR */
        composite_string_node(p, c->car->cdr, b->cdr);
        cons_free(b);
        return a;
      }

      push(a, b);
      return a;
    }
    else {
      /* a == NODE_DSTR && b == NODE_DSTR */
      if (string_node_p(c->car) && string_node_p(b->cdr->car)) {
        /* a->[..., NODE_STR] && b->[NODE_STR, ...] */
        node *d = b->cdr;
        cons_free(b);
        composite_string_node(p, c->car->cdr, d->car->cdr);
        cons_free(d->car);
        c->cdr = d->cdr;
        cons_free(d);
        return a;
      }
      else {
        c->cdr = b->cdr;
        cons_free(b);
        return a;
      }
    }
  }

  return new_dstr(p, list2(a, b));
}

/* (:str . (s . len)) */
static node*
new_xstr(parser_state *p, const char *s, int len)
{
  return cons((node*)NODE_XSTR, cons((node*)strndup(s, len), nint(len)));
}

/* (:xstr . a) */
static node*
new_dxstr(parser_state *p, node *a)
{
  return cons((node*)NODE_DXSTR, a);
}

/* (:dsym . a) */
static node*
new_dsym(parser_state *p, node *a)
{
  return cons((node*)NODE_DSYM, a);
}

/* (:regx . (s . (opt . enc))) */
static node*
new_regx(parser_state *p, const char *p1, const char* p2, const char* p3)
{
  return cons((node*)NODE_REGX, cons((node*)p1, cons((node*)p2, (node*)p3)));
}

/* (:dregx . (a . b)) */
static node*
new_dregx(parser_state *p, node *a, node *b)
{
  return cons((node*)NODE_DREGX, cons(a, b));
}

/* (:backref . n) */
static node*
new_back_ref(parser_state *p, int n)
{
  return cons((node*)NODE_BACK_REF, nint(n));
}

/* (:nthref . n) */
static node*
new_nth_ref(parser_state *p, int n)
{
  return cons((node*)NODE_NTH_REF, nint(n));
}

/* (:heredoc . a) */
static node*
new_heredoc(parser_state *p)
{
  parser_heredoc_info *inf = (parser_heredoc_info *)parser_palloc(p, sizeof(parser_heredoc_info));
  return cons((node*)NODE_HEREDOC, (node*)inf);
}

static void
new_bv(parser_state *p, mrb_sym id)
{
}

static node*
new_literal_delim(parser_state *p)
{
  return cons((node*)NODE_LITERAL_DELIM, 0);
}

/* (:words . a) */
static node*
new_words(parser_state *p, node *a)
{
  return cons((node*)NODE_WORDS, a);
}

/* (:symbols . a) */
static node*
new_symbols(parser_state *p, node *a)
{
  return cons((node*)NODE_SYMBOLS, a);
}

/* xxx ----------------------------- */

/* (:call a op) */
static node*
call_uni_op(parser_state *p, node *recv, const char *m)
{
  void_expr_error(p, recv);
  return new_call(p, recv, intern_cstr(m), 0, 1);
}

/* (:call a op b) */
static node*
call_bin_op(parser_state *p, node *recv, const char *m, node *arg1)
{
  return new_call(p, recv, intern_cstr(m), list1(list1(arg1)), 1);
}

static void
args_with_block(parser_state *p, node *a, node *b)
{
  if (b) {
    if (a->cdr) {
      yyerror(p, "both block arg and actual block given");
    }
    a->cdr = b;
  }
}

static void
call_with_block(parser_state *p, node *a, node *b)
{
  node *n;

  switch ((enum node_type)intn(a->car)) {
  case NODE_SUPER:
  case NODE_ZSUPER:
    if (!a->cdr) a->cdr = cons(0, b);
    else {
      args_with_block(p, a->cdr, b);
    }
    break;
  case NODE_CALL:
  case NODE_FCALL:
  case NODE_SCALL:
    n = a->cdr->cdr->cdr;
    if (!n->car) n->car = cons(0, b);
    else {
      args_with_block(p, n->car, b);
    }
    break;
  default:
    break;
  }
}

static node*
negate_lit(parser_state *p, node *n)
{
  return cons((node*)NODE_NEGATE, n);
}

static node*
cond(node *n)
{
  return n;
}

static node*
ret_args(parser_state *p, node *n)
{
  if (n->cdr) {
    yyerror(p, "block argument should not be given");
    return NULL;
  }
  if (!n->car->cdr) return n->car->car;
  return new_array(p, n->car);
}

static void
assignable(parser_state *p, node *lhs)
{
  if (intn(lhs->car) == NODE_LVAR) {
    local_add(p, sym(lhs->cdr));
  }
}

static node*
var_reference(parser_state *p, node *lhs)
{
  node *n;

  if (intn(lhs->car) == NODE_LVAR) {
    if (!local_var_p(p, sym(lhs->cdr))) {
      n = new_fcall(p, sym(lhs->cdr), 0);
      cons_free(lhs);
      return n;
    }
  }

  return lhs;
}

typedef enum mrb_string_type  string_type;

static node*
new_strterm(parser_state *p, string_type type, int term, int paren)
{
  return cons(nint(type), cons((node*)0, cons(nint(paren), nint(term))));
}

static void
end_strterm(parser_state *p)
{
  cons_free(p->lex_strterm->cdr->cdr);
  cons_free(p->lex_strterm->cdr);
  cons_free(p->lex_strterm);
  p->lex_strterm = NULL;
}

static parser_heredoc_info *
parsing_heredoc_inf(parser_state *p)
{
  node *nd = p->parsing_heredoc;
  if (nd == NULL)
    return NULL;
  /* mrb_assert(nd->car->car == NODE_HEREDOC); */
  return (parser_heredoc_info*)nd->car->cdr;
}

static void
heredoc_treat_nextline(parser_state *p)
{
  if (p->heredocs_from_nextline == NULL)
    return;
  if (p->parsing_heredoc == NULL) {
    node *n;
    p->parsing_heredoc = p->heredocs_from_nextline;
    p->lex_strterm_before_heredoc = p->lex_strterm;
    p->lex_strterm = new_strterm(p, parsing_heredoc_inf(p)->type, 0, 0);
    n = p->all_heredocs;
    if (n) {
      while (n->cdr)
        n = n->cdr;
      n->cdr = p->parsing_heredoc;
    }
    else {
      p->all_heredocs = p->parsing_heredoc;
    }
  }
  else {
    node *n, *m;
    m = p->heredocs_from_nextline;
    while (m->cdr)
      m = m->cdr;
    n = p->all_heredocs;
    mrb_assert(n != NULL);
    if (n == p->parsing_heredoc) {
      m->cdr = n;
      p->all_heredocs = p->heredocs_from_nextline;
      p->parsing_heredoc = p->heredocs_from_nextline;
    }
    else {
      while (n->cdr != p->parsing_heredoc) {
        n = n->cdr;
        mrb_assert(n != NULL);
      }
      m->cdr = n->cdr;
      n->cdr = p->heredocs_from_nextline;
      p->parsing_heredoc = p->heredocs_from_nextline;
    }
  }
  p->heredocs_from_nextline = NULL;
}

static void
heredoc_end(parser_state *p)
{
  p->parsing_heredoc = p->parsing_heredoc->cdr;
  if (p->parsing_heredoc == NULL) {
    p->lstate = EXPR_BEG;
    p->cmd_start = TRUE;
    end_strterm(p);
    p->lex_strterm = p->lex_strterm_before_heredoc;
    p->lex_strterm_before_heredoc = NULL;
  }
  else {
    /* next heredoc */
    p->lex_strterm->car = nint(parsing_heredoc_inf(p)->type);
  }
}
#define is_strterm_type(p,str_func) (intn((p)->lex_strterm->car) & (str_func))

/* xxx ----------------------------- */


/* Line 371 of yacc.c  */
#line 1361 "D:\\Desktop\\y.tab.c"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     keyword_class = 258,
     keyword_module = 259,
     keyword_def = 260,
     keyword_begin = 261,
     keyword_if = 262,
     keyword_unless = 263,
     keyword_while = 264,
     keyword_until = 265,
     keyword_for = 266,
     keyword_undef = 267,
     keyword_rescue = 268,
     keyword_ensure = 269,
     keyword_end = 270,
     keyword_then = 271,
     keyword_elsif = 272,
     keyword_else = 273,
     keyword_case = 274,
     keyword_when = 275,
     keyword_break = 276,
     keyword_next = 277,
     keyword_redo = 278,
     keyword_retry = 279,
     keyword_in = 280,
     keyword_do = 281,
     keyword_do_cond = 282,
     keyword_do_block = 283,
     keyword_do_LAMBDA = 284,
     keyword_return = 285,
     keyword_yield = 286,
     keyword_super = 287,
     keyword_self = 288,
     keyword_nil = 289,
     keyword_true = 290,
     keyword_false = 291,
     keyword_and = 292,
     keyword_or = 293,
     keyword_not = 294,
     modifier_if = 295,
     modifier_unless = 296,
     modifier_while = 297,
     modifier_until = 298,
     modifier_rescue = 299,
     keyword_alias = 300,
     keyword_BEGIN = 301,
     keyword_END = 302,
     keyword__LINE__ = 303,
     keyword__FILE__ = 304,
     keyword__ENCODING__ = 305,
     tIDENTIFIER = 306,
     tFID = 307,
     tGVAR = 308,
     tIVAR = 309,
     tCONSTANT = 310,
     tCVAR = 311,
     tLABEL_TAG = 312,
     tINTEGER = 313,
     tFLOAT = 314,
     tCHAR = 315,
     tXSTRING = 316,
     tREGEXP = 317,
     tSTRING = 318,
     tSTRING_PART = 319,
     tSTRING_MID = 320,
     tNTH_REF = 321,
     tBACK_REF = 322,
     tREGEXP_END = 323,
     tUPLUS = 324,
     tUMINUS = 325,
     tPOW = 326,
     tCMP = 327,
     tEQ = 328,
     tEQQ = 329,
     tNEQ = 330,
     tGEQ = 331,
     tLEQ = 332,
     tANDOP = 333,
     tOROP = 334,
     tMATCH = 335,
     tNMATCH = 336,
     tDOT2 = 337,
     tDOT3 = 338,
     tAREF = 339,
     tASET = 340,
     tLSHFT = 341,
     tRSHFT = 342,
     tCOLON2 = 343,
     tCOLON3 = 344,
     tOP_ASGN = 345,
     tASSOC = 346,
     tLPAREN = 347,
     tLPAREN_ARG = 348,
     tRPAREN = 349,
     tLBRACK = 350,
     tLBRACE = 351,
     tLBRACE_ARG = 352,
     tSTAR = 353,
     tDSTAR = 354,
     tAMPER = 355,
     tLAMBDA = 356,
     tANDDOT = 357,
     tSYMBEG = 358,
     tREGEXP_BEG = 359,
     tWORDS_BEG = 360,
     tSYMBOLS_BEG = 361,
     tSTRING_BEG = 362,
     tXSTRING_BEG = 363,
     tSTRING_DVAR = 364,
     tLAMBEG = 365,
     tHEREDOC_BEG = 366,
     tHEREDOC_END = 367,
     tLITERAL_DELIM = 368,
     tHD_LITERAL_DELIM = 369,
     tHD_STRING_PART = 370,
     tHD_STRING_MID = 371,
     tLOWEST = 372,
     tUMINUS_NUM = 373,
     tLAST_TOKEN = 374
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 1304 "D:\\Desktop\\parse.y"

    node *nd;
    mrb_sym id;
    int num;
    stack_type stack;
    const struct vtable *vars;


/* Line 387 of yacc.c  */
#line 1529 "D:\\Desktop\\y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (parser_state *p);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 1556 "D:\\Desktop\\y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   11645

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  146
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  176
/* YYNRULES -- Number of rules.  */
#define YYNRULES  587
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1026

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   374

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     145,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   132,     2,     2,     2,   130,   125,     2,
     140,   141,   128,   126,   138,   127,   144,   129,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   120,   143,
     122,   118,   121,   119,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   137,     2,   142,   124,     2,   139,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   135,   123,   136,   133,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   131,   134
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     7,    10,    12,    14,    18,    21,
      23,    24,    30,    35,    38,    40,    42,    46,    49,    50,
      55,    58,    62,    66,    70,    74,    78,    83,    85,    89,
      93,    97,   101,   103,   107,   111,   118,   124,   130,   136,
     142,   146,   148,   152,   154,   156,   160,   164,   168,   171,
     173,   175,   177,   179,   181,   186,   187,   193,   196,   200,
     205,   211,   216,   222,   225,   228,   231,   234,   237,   239,
     243,   245,   249,   251,   254,   258,   264,   267,   272,   275,
     280,   282,   286,   288,   292,   295,   299,   301,   304,   306,
     311,   315,   319,   323,   327,   330,   332,   334,   339,   343,
     347,   351,   355,   358,   360,   362,   364,   367,   369,   373,
     375,   377,   379,   381,   383,   385,   387,   389,   390,   395,
     397,   399,   401,   403,   405,   407,   409,   411,   413,   415,
     417,   419,   421,   423,   425,   427,   429,   431,   433,   435,
     437,   439,   441,   443,   445,   447,   449,   451,   453,   455,
     457,   459,   461,   463,   465,   467,   469,   471,   473,   475,
     477,   479,   481,   483,   485,   487,   489,   491,   493,   495,
     497,   499,   501,   503,   505,   507,   509,   511,   513,   515,
     517,   519,   521,   523,   525,   527,   529,   531,   533,   535,
     539,   543,   550,   556,   562,   568,   574,   579,   583,   587,
     591,   595,   599,   603,   607,   611,   615,   620,   625,   628,
     631,   635,   639,   643,   647,   651,   655,   659,   663,   667,
     671,   675,   679,   683,   686,   689,   693,   697,   701,   705,
     712,   719,   721,   723,   726,   731,   734,   736,   740,   744,
     746,   748,   750,   752,   755,   760,   763,   765,   768,   771,
     776,   778,   779,   782,   785,   788,   790,   792,   795,   797,
     800,   804,   809,   813,   818,   821,   823,   825,   827,   829,
     831,   833,   835,   837,   838,   843,   844,   845,   851,   852,
     856,   860,   864,   867,   871,   875,   877,   880,   885,   889,
     892,   894,   897,   898,   899,   905,   912,   919,   920,   921,
     929,   930,   931,   939,   945,   950,   951,   952,   962,   963,
     970,   971,   972,   981,   982,   988,   989,   990,   998,   999,
    1000,  1010,  1012,  1014,  1016,  1018,  1020,  1022,  1024,  1027,
    1029,  1031,  1033,  1039,  1041,  1044,  1046,  1048,  1050,  1055,
    1062,  1066,  1072,  1075,  1080,  1082,  1083,  1088,  1093,  1096,
    1099,  1101,  1104,  1105,  1112,  1121,  1126,  1133,  1138,  1142,
    1149,  1152,  1157,  1164,  1167,  1172,  1175,  1180,  1182,  1184,
    1186,  1187,  1192,  1194,  1199,  1201,  1206,  1208,  1212,  1214,
    1216,  1221,  1223,  1227,  1231,  1232,  1238,  1241,  1246,  1252,
    1258,  1261,  1266,  1271,  1275,  1279,  1283,  1286,  1288,  1293,
    1294,  1300,  1301,  1307,  1313,  1315,  1317,  1324,  1326,  1328,
    1330,  1332,  1335,  1337,  1340,  1342,  1344,  1346,  1348,  1350,
    1352,  1355,  1357,  1359,  1362,  1366,  1368,  1371,  1373,  1374,
    1379,  1381,  1384,  1387,  1391,  1394,  1398,  1400,  1402,  1405,
    1407,  1410,  1412,  1415,  1417,  1418,  1423,  1426,  1430,  1432,
    1437,  1440,  1442,  1444,  1446,  1448,  1450,  1453,  1456,  1460,
    1462,  1464,  1467,  1470,  1472,  1474,  1476,  1478,  1480,  1482,
    1484,  1486,  1488,  1490,  1492,  1494,  1496,  1498,  1500,  1502,
    1503,  1504,  1509,  1513,  1516,  1519,  1522,  1524,  1527,  1529,
    1531,  1535,  1537,  1541,  1543,  1545,  1548,  1550,  1555,  1558,
    1561,  1563,  1566,  1567,  1574,  1583,  1588,  1595,  1600,  1607,
    1610,  1615,  1622,  1625,  1630,  1633,  1638,  1640,  1641,  1643,
    1645,  1647,  1649,  1651,  1653,  1655,  1656,  1661,  1663,  1667,
    1670,  1673,  1676,  1678,  1682,  1684,  1688,  1690,  1692,  1695,
    1697,  1699,  1701,  1704,  1707,  1709,  1711,  1712,  1717,  1719,
    1722,  1724,  1728,  1732,  1736,  1740,  1743,  1745,  1747,  1749,
    1751,  1753,  1755,  1757,  1759,  1761,  1763,  1765,  1767,  1769,
    1771,  1773,  1775,  1776,  1778,  1779,  1781,  1784,  1787,  1788,
    1790,  1792,  1794,  1796,  1798,  1800,  1802,  1805
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     147,     0,    -1,    -1,   148,   149,    -1,   150,   313,    -1,
     321,    -1,   151,    -1,   150,   320,   151,    -1,     1,   151,
      -1,   156,    -1,    -1,    46,   152,   135,   149,   136,    -1,
     154,   246,   222,   249,    -1,   155,   313,    -1,   321,    -1,
     156,    -1,   155,   320,   156,    -1,     1,   156,    -1,    -1,
      45,   178,   157,   178,    -1,    12,   179,    -1,   156,    40,
     161,    -1,   156,    41,   161,    -1,   156,    42,   161,    -1,
     156,    43,   161,    -1,   156,    44,   156,    -1,    47,   135,
     154,   136,    -1,   158,    -1,   167,   118,   162,    -1,   174,
     118,   196,    -1,   167,   118,   183,    -1,   167,   118,   196,
      -1,   160,    -1,   174,   118,   159,    -1,   271,    90,   159,
      -1,   218,   137,   188,   316,    90,   159,    -1,   218,   311,
      51,    90,   159,    -1,   218,   311,    55,    90,   159,    -1,
     218,    88,    55,    90,   162,    -1,   218,    88,    51,    90,
     159,    -1,   273,    90,   159,    -1,   162,    -1,   162,    44,
     156,    -1,   158,    -1,   162,    -1,   160,    37,   160,    -1,
     160,    38,   160,    -1,    39,   314,   160,    -1,   132,   162,
      -1,   183,    -1,   160,    -1,   166,    -1,   163,    -1,   239,
      -1,   239,   312,   308,   190,    -1,    -1,    97,   165,   229,
     154,   136,    -1,   307,   190,    -1,   307,   190,   164,    -1,
     218,   311,   308,   190,    -1,   218,   311,   308,   190,   164,
      -1,   218,    88,   308,   190,    -1,   218,    88,   308,   190,
     164,    -1,    32,   190,    -1,    31,   190,    -1,    30,   189,
      -1,    21,   189,    -1,    22,   189,    -1,   169,    -1,    92,
     168,   315,    -1,   169,    -1,    92,   168,   315,    -1,   171,
      -1,   171,   170,    -1,   171,    98,   173,    -1,   171,    98,
     173,   138,   172,    -1,   171,    98,    -1,   171,    98,   138,
     172,    -1,    98,   173,    -1,    98,   173,   138,   172,    -1,
      98,    -1,    98,   138,   172,    -1,   173,    -1,    92,   168,
     315,    -1,   170,   138,    -1,   171,   170,   138,    -1,   170,
      -1,   171,   170,    -1,   270,    -1,   218,   137,   188,   316,
      -1,   218,   311,    51,    -1,   218,    88,    51,    -1,   218,
     311,    55,    -1,   218,    88,    55,    -1,    89,    55,    -1,
     273,    -1,   270,    -1,   218,   137,   188,   316,    -1,   218,
     311,    51,    -1,   218,    88,    51,    -1,   218,   311,    55,
      -1,   218,    88,    55,    -1,    89,    55,    -1,   273,    -1,
      51,    -1,    55,    -1,    89,   175,    -1,   175,    -1,   218,
      88,   175,    -1,    51,    -1,    55,    -1,    52,    -1,   181,
      -1,   182,    -1,   177,    -1,   266,    -1,   178,    -1,    -1,
     179,   138,   180,   178,    -1,   123,    -1,   124,    -1,   125,
      -1,    72,    -1,    73,    -1,    74,    -1,    80,    -1,    81,
      -1,   121,    -1,    76,    -1,   122,    -1,    77,    -1,    75,
      -1,    86,    -1,    87,    -1,   126,    -1,   127,    -1,   128,
      -1,    98,    -1,   129,    -1,   130,    -1,    71,    -1,    99,
      -1,   132,    -1,   133,    -1,    69,    -1,    70,    -1,    84,
      -1,    85,    -1,   139,    -1,    48,    -1,    49,    -1,    50,
      -1,    46,    -1,    47,    -1,    45,    -1,    37,    -1,     6,
      -1,    21,    -1,    19,    -1,     3,    -1,     5,    -1,    26,
      -1,    18,    -1,    17,    -1,    15,    -1,    14,    -1,    36,
      -1,    11,    -1,    25,    -1,     4,    -1,    22,    -1,    34,
      -1,    39,    -1,    38,    -1,    23,    -1,    13,    -1,    24,
      -1,    30,    -1,    33,    -1,    32,    -1,    16,    -1,    35,
      -1,    12,    -1,    20,    -1,    31,    -1,     7,    -1,     8,
      -1,     9,    -1,    10,    -1,   174,   118,   185,    -1,   271,
      90,   185,    -1,   218,   137,   188,   316,    90,   185,    -1,
     218,   311,    51,    90,   185,    -1,   218,   311,    55,    90,
     185,    -1,   218,    88,    51,    90,   185,    -1,   218,    88,
      55,    90,   185,    -1,    89,    55,    90,   185,    -1,   273,
      90,   185,    -1,   183,    82,   183,    -1,   183,    83,   183,
      -1,   183,   126,   183,    -1,   183,   127,   183,    -1,   183,
     128,   183,    -1,   183,   129,   183,    -1,   183,   130,   183,
      -1,   183,    71,   183,    -1,   131,    58,    71,   183,    -1,
     131,    59,    71,   183,    -1,    69,   183,    -1,    70,   183,
      -1,   183,   123,   183,    -1,   183,   124,   183,    -1,   183,
     125,   183,    -1,   183,    72,   183,    -1,   183,   121,   183,
      -1,   183,    76,   183,    -1,   183,   122,   183,    -1,   183,
      77,   183,    -1,   183,    73,   183,    -1,   183,    74,   183,
      -1,   183,    75,   183,    -1,   183,    80,   183,    -1,   183,
      81,   183,    -1,   132,   183,    -1,   133,   183,    -1,   183,
      86,   183,    -1,   183,    87,   183,    -1,   183,    78,   183,
      -1,   183,    79,   183,    -1,   183,   119,   183,   314,   120,
     183,    -1,   183,   119,   183,   314,    57,   183,    -1,   197,
      -1,   321,    -1,   195,   317,    -1,   195,   194,   305,   317,
      -1,   305,   317,    -1,   183,    -1,   183,    44,   183,    -1,
     140,   188,   315,    -1,   321,    -1,   186,    -1,   321,    -1,
     189,    -1,   195,   138,    -1,   195,   194,   305,   138,    -1,
     305,   138,    -1,   166,    -1,   195,   193,    -1,   305,   193,
      -1,   195,   194,   305,   193,    -1,   192,    -1,    -1,   191,
     189,    -1,   100,   183,    -1,   194,   192,    -1,   321,    -1,
     138,    -1,   138,   259,    -1,   183,    -1,    98,   183,    -1,
     195,   194,   183,    -1,   195,   194,    98,   183,    -1,   195,
     194,   183,    -1,   195,   194,    98,   183,    -1,    98,   183,
      -1,   250,    -1,   251,    -1,   256,    -1,   257,    -1,   258,
      -1,   272,    -1,   273,    -1,    52,    -1,    -1,     6,   198,
     153,    15,    -1,    -1,    -1,    93,   199,   156,   200,   315,
      -1,    -1,    93,   201,   315,    -1,    92,   154,   141,    -1,
     218,    88,    55,    -1,    89,    55,    -1,    95,   184,   142,
      -1,    96,   304,   136,    -1,    30,    -1,    31,   187,    -1,
      39,   140,   160,   315,    -1,    39,   140,   315,    -1,   307,
     241,    -1,   240,    -1,   240,   241,    -1,    -1,    -1,   101,
     202,   235,   203,   236,    -1,     7,   161,   219,   154,   221,
      15,    -1,     8,   161,   219,   154,   222,    15,    -1,    -1,
      -1,     9,   204,   161,   220,   205,   154,    15,    -1,    -1,
      -1,    10,   206,   161,   220,   207,   154,    15,    -1,    19,
     161,   313,   244,    15,    -1,    19,   313,   244,    15,    -1,
      -1,    -1,    11,   223,    25,   208,   161,   220,   209,   154,
      15,    -1,    -1,     3,   176,   274,   210,   153,    15,    -1,
      -1,    -1,     3,    86,   160,   211,   318,   212,   153,    15,
      -1,    -1,     4,   176,   213,   153,    15,    -1,    -1,    -1,
       5,   177,   214,   215,   276,   153,    15,    -1,    -1,    -1,
       5,   302,   310,   216,   177,   217,   276,   153,    15,    -1,
      21,    -1,    22,    -1,    23,    -1,    24,    -1,   197,    -1,
     318,    -1,    16,    -1,   318,    16,    -1,   318,    -1,    27,
      -1,   222,    -1,    17,   161,   219,   154,   221,    -1,   321,
      -1,    18,   154,    -1,   174,    -1,   167,    -1,   291,    -1,
     291,   138,    98,   288,    -1,   291,   138,    98,   288,   138,
     291,    -1,   291,   138,    98,    -1,   291,   138,    98,   138,
     291,    -1,    98,   288,    -1,    98,   288,   138,   291,    -1,
      98,    -1,    -1,    98,   138,   225,   291,    -1,   280,   138,
     283,   301,    -1,   280,   301,    -1,   283,   301,    -1,   300,
      -1,   138,   226,    -1,    -1,   291,   138,   295,   138,   298,
     227,    -1,   291,   138,   295,   138,   298,   138,   291,   227,
      -1,   291,   138,   295,   227,    -1,   291,   138,   295,   138,
     291,   227,    -1,   291,   138,   298,   227,    -1,   291,   138,
     227,    -1,   291,   138,   298,   138,   291,   227,    -1,   291,
     227,    -1,   295,   138,   298,   227,    -1,   295,   138,   298,
     138,   291,   227,    -1,   295,   227,    -1,   295,   138,   291,
     227,    -1,   298,   227,    -1,   298,   138,   291,   227,    -1,
     226,    -1,   321,    -1,   230,    -1,    -1,   123,   231,   232,
     123,    -1,    79,    -1,   123,   228,   232,   123,    -1,   314,
      -1,   314,   143,   233,   314,    -1,   234,    -1,   233,   138,
     234,    -1,    51,    -1,   287,    -1,   140,   286,   232,   141,
      -1,   286,    -1,   110,   154,   136,    -1,    29,   153,    15,
      -1,    -1,    28,   238,   229,   153,    15,    -1,   166,   237,
      -1,   239,   312,   308,   187,    -1,   239,   312,   308,   187,
     241,    -1,   239,   312,   308,   190,   237,    -1,   307,   186,
      -1,   218,   311,   308,   187,    -1,   218,    88,   308,   186,
      -1,   218,    88,   309,    -1,   218,   311,   186,    -1,   218,
      88,   186,    -1,    32,   186,    -1,    32,    -1,   218,   137,
     188,   316,    -1,    -1,   135,   242,   229,   154,   136,    -1,
      -1,    26,   243,   229,   153,    15,    -1,    20,   195,   219,
     154,   245,    -1,   222,    -1,   244,    -1,    13,   247,   248,
     219,   154,   246,    -1,   321,    -1,   183,    -1,   196,    -1,
     321,    -1,    91,   174,    -1,   321,    -1,    14,   154,    -1,
     321,    -1,   269,    -1,   265,    -1,   264,    -1,   268,    -1,
     252,    -1,   251,   252,    -1,    60,    -1,    63,    -1,   107,
      63,    -1,   107,   253,    63,    -1,   254,    -1,   253,   254,
      -1,    65,    -1,    -1,    64,   255,   154,   136,    -1,   113,
      -1,   114,   259,    -1,   108,    61,    -1,   108,   253,    61,
      -1,   104,    62,    -1,   104,   253,    62,    -1,   111,    -1,
     260,    -1,   259,   260,    -1,   112,    -1,   261,   112,    -1,
     262,    -1,   261,   262,    -1,   116,    -1,    -1,   115,   263,
     154,   136,    -1,   105,    63,    -1,   105,   253,    63,    -1,
     266,    -1,   103,   107,   253,    63,    -1,   103,   267,    -1,
     177,    -1,    54,    -1,    53,    -1,    56,    -1,    63,    -1,
     107,    63,    -1,   106,    63,    -1,   106,   253,    63,    -1,
      58,    -1,    59,    -1,   131,    58,    -1,   131,    59,    -1,
      51,    -1,    54,    -1,    53,    -1,    56,    -1,    55,    -1,
     270,    -1,   270,    -1,    34,    -1,    33,    -1,    35,    -1,
      36,    -1,    49,    -1,    48,    -1,    50,    -1,    66,    -1,
      67,    -1,    -1,    -1,   122,   275,   161,   318,    -1,   140,
     286,   315,    -1,   286,   318,    -1,    51,    57,    -1,   277,
     183,    -1,   277,    -1,   277,   218,    -1,   277,    -1,   279,
      -1,   280,   138,   279,    -1,   278,    -1,   281,   138,   278,
      -1,    71,    -1,    99,    -1,   282,    51,    -1,   282,    -1,
     281,   138,   283,   301,    -1,   281,   301,    -1,   283,   301,
      -1,   300,    -1,   138,   284,    -1,    -1,   291,   138,   296,
     138,   298,   285,    -1,   291,   138,   296,   138,   298,   138,
     291,   285,    -1,   291,   138,   296,   285,    -1,   291,   138,
     296,   138,   291,   285,    -1,   291,   138,   298,   285,    -1,
     291,   138,   298,   138,   291,   285,    -1,   291,   285,    -1,
     296,   138,   298,   285,    -1,   296,   138,   298,   138,   291,
     285,    -1,   296,   285,    -1,   296,   138,   291,   285,    -1,
     298,   285,    -1,   298,   138,   291,   285,    -1,   284,    -1,
      -1,    55,    -1,    54,    -1,    53,    -1,    56,    -1,   287,
      -1,    51,    -1,   288,    -1,    -1,    92,   290,   224,   315,
      -1,   289,    -1,   291,   138,   289,    -1,    51,   118,    -1,
     292,   183,    -1,   292,   218,    -1,   294,    -1,   295,   138,
     294,    -1,   293,    -1,   296,   138,   293,    -1,   128,    -1,
      98,    -1,   297,    51,    -1,   297,    -1,   125,    -1,   100,
      -1,   299,    51,    -1,   138,   300,    -1,   321,    -1,   272,
      -1,    -1,   140,   303,   160,   315,    -1,   321,    -1,   305,
     317,    -1,   306,    -1,   305,   138,   306,    -1,   183,    91,
     183,    -1,    51,    57,   183,    -1,   252,    57,   183,    -1,
      99,   183,    -1,    51,    -1,    55,    -1,    52,    -1,    51,
      -1,    55,    -1,    52,    -1,   181,    -1,    51,    -1,    52,
      -1,   181,    -1,   144,    -1,    88,    -1,   144,    -1,   102,
      -1,   311,    -1,    88,    -1,    -1,   320,    -1,    -1,   319,
      -1,   314,   141,    -1,   314,   142,    -1,    -1,   319,    -1,
     194,    -1,   143,    -1,   319,    -1,   260,    -1,   145,    -1,
     318,    -1,   320,   318,    -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,  1461,  1461,  1461,  1472,  1478,  1482,  1487,  1491,  1497,
    1499,  1498,  1510,  1537,  1543,  1547,  1552,  1556,  1562,  1562,
    1566,  1570,  1574,  1578,  1582,  1586,  1590,  1595,  1596,  1600,
    1604,  1608,  1612,  1615,  1619,  1623,  1627,  1631,  1635,  1640,
    1644,  1651,  1652,  1656,  1660,  1661,  1665,  1669,  1673,  1677,
    1680,  1689,  1690,  1693,  1694,  1701,  1700,  1713,  1717,  1722,
    1726,  1731,  1735,  1740,  1744,  1748,  1752,  1756,  1762,  1766,
    1772,  1773,  1779,  1783,  1787,  1791,  1795,  1799,  1803,  1807,
    1811,  1815,  1821,  1822,  1828,  1832,  1838,  1842,  1848,  1852,
    1856,  1860,  1864,  1868,  1874,  1880,  1887,  1891,  1895,  1899,
    1903,  1907,  1913,  1919,  1926,  1930,  1933,  1937,  1941,  1948,
    1949,  1950,  1951,  1956,  1963,  1964,  1967,  1971,  1971,  1977,
    1978,  1979,  1980,  1981,  1982,  1983,  1984,  1985,  1986,  1987,
    1988,  1989,  1990,  1991,  1992,  1993,  1994,  1995,  1996,  1997,
    1998,  1999,  2000,  2001,  2002,  2003,  2004,  2005,  2006,  2009,
    2009,  2009,  2010,  2010,  2011,  2011,  2011,  2012,  2012,  2012,
    2012,  2013,  2013,  2013,  2014,  2014,  2014,  2015,  2015,  2015,
    2015,  2016,  2016,  2016,  2016,  2017,  2017,  2017,  2017,  2018,
    2018,  2018,  2018,  2019,  2019,  2019,  2019,  2020,  2020,  2023,
    2027,  2031,  2035,  2039,  2043,  2047,  2052,  2057,  2062,  2066,
    2070,  2074,  2078,  2082,  2086,  2090,  2094,  2098,  2102,  2106,
    2110,  2114,  2118,  2122,  2126,  2130,  2134,  2138,  2142,  2146,
    2150,  2154,  2158,  2162,  2166,  2170,  2174,  2178,  2182,  2186,
    2190,  2194,  2200,  2201,  2206,  2210,  2217,  2221,  2229,  2235,
    2236,  2239,  2240,  2241,  2246,  2251,  2258,  2264,  2269,  2274,
    2279,  2286,  2286,  2297,  2303,  2307,  2313,  2314,  2317,  2323,
    2329,  2334,  2341,  2346,  2351,  2358,  2359,  2360,  2361,  2362,
    2363,  2364,  2365,  2370,  2369,  2381,  2385,  2380,  2390,  2390,
    2394,  2398,  2402,  2406,  2411,  2416,  2420,  2424,  2428,  2432,
    2436,  2437,  2443,  2449,  2442,  2461,  2469,  2477,  2477,  2477,
    2484,  2484,  2484,  2491,  2497,  2502,  2504,  2501,  2513,  2511,
    2527,  2532,  2525,  2547,  2545,  2560,  2564,  2559,  2579,  2585,
    2578,  2600,  2604,  2608,  2612,  2618,  2625,  2626,  2627,  2630,
    2631,  2634,  2635,  2643,  2644,  2650,  2654,  2657,  2661,  2665,
    2669,  2674,  2678,  2682,  2686,  2692,  2691,  2701,  2705,  2709,
    2713,  2719,  2724,  2729,  2733,  2737,  2741,  2745,  2749,  2753,
    2757,  2761,  2765,  2769,  2773,  2777,  2781,  2785,  2791,  2796,
    2803,  2803,  2807,  2812,  2819,  2823,  2829,  2830,  2833,  2838,
    2841,  2845,  2851,  2855,  2862,  2861,  2874,  2884,  2888,  2893,
    2900,  2904,  2908,  2912,  2916,  2920,  2924,  2928,  2932,  2939,
    2938,  2951,  2950,  2964,  2972,  2981,  2984,  2991,  2994,  2998,
    2999,  3002,  3006,  3009,  3013,  3016,  3017,  3018,  3019,  3022,
    3023,  3029,  3030,  3031,  3035,  3041,  3042,  3048,  3053,  3052,
    3063,  3067,  3073,  3077,  3083,  3087,  3093,  3096,  3097,  3100,
    3106,  3112,  3113,  3116,  3123,  3122,  3136,  3140,  3147,  3152,
    3159,  3165,  3166,  3167,  3168,  3169,  3173,  3179,  3183,  3189,
    3190,  3191,  3195,  3201,  3205,  3209,  3213,  3217,  3223,  3229,
    3233,  3237,  3241,  3245,  3249,  3257,  3264,  3275,  3276,  3280,
    3284,  3283,  3299,  3305,  3311,  3317,  3323,  3330,  3334,  3340,
    3344,  3350,  3354,  3360,  3361,  3364,  3368,  3374,  3378,  3382,
    3386,  3392,  3397,  3402,  3406,  3410,  3414,  3418,  3422,  3426,
    3430,  3434,  3438,  3442,  3446,  3450,  3454,  3459,  3465,  3470,
    3475,  3480,  3487,  3491,  3498,  3503,  3502,  3514,  3518,  3524,
    3532,  3540,  3548,  3552,  3558,  3562,  3568,  3569,  3572,  3577,
    3584,  3585,  3588,  3594,  3598,  3604,  3609,  3609,  3634,  3635,
    3641,  3646,  3652,  3658,  3663,  3673,  3680,  3681,  3682,  3685,
    3686,  3687,  3688,  3691,  3692,  3693,  3696,  3697,  3700,  3704,
    3710,  3711,  3717,  3718,  3721,  3722,  3725,  3728,  3731,  3732,
    3733,  3736,  3737,  3738,  3741,  3748,  3749,  3753
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "keyword_class", "keyword_module",
  "keyword_def", "keyword_begin", "keyword_if", "keyword_unless",
  "keyword_while", "keyword_until", "keyword_for", "keyword_undef",
  "keyword_rescue", "keyword_ensure", "keyword_end", "keyword_then",
  "keyword_elsif", "keyword_else", "keyword_case", "keyword_when",
  "keyword_break", "keyword_next", "keyword_redo", "keyword_retry",
  "keyword_in", "keyword_do", "keyword_do_cond", "keyword_do_block",
  "keyword_do_LAMBDA", "keyword_return", "keyword_yield", "keyword_super",
  "keyword_self", "keyword_nil", "keyword_true", "keyword_false",
  "keyword_and", "keyword_or", "keyword_not", "modifier_if",
  "modifier_unless", "modifier_while", "modifier_until", "modifier_rescue",
  "keyword_alias", "keyword_BEGIN", "keyword_END", "keyword__LINE__",
  "keyword__FILE__", "keyword__ENCODING__", "tIDENTIFIER", "tFID", "tGVAR",
  "tIVAR", "tCONSTANT", "tCVAR", "tLABEL_TAG", "tINTEGER", "tFLOAT",
  "tCHAR", "tXSTRING", "tREGEXP", "tSTRING", "tSTRING_PART", "tSTRING_MID",
  "tNTH_REF", "tBACK_REF", "tREGEXP_END", "tUPLUS", "tUMINUS", "tPOW",
  "tCMP", "tEQ", "tEQQ", "tNEQ", "tGEQ", "tLEQ", "tANDOP", "tOROP",
  "tMATCH", "tNMATCH", "tDOT2", "tDOT3", "tAREF", "tASET", "tLSHFT",
  "tRSHFT", "tCOLON2", "tCOLON3", "tOP_ASGN", "tASSOC", "tLPAREN",
  "tLPAREN_ARG", "tRPAREN", "tLBRACK", "tLBRACE", "tLBRACE_ARG", "tSTAR",
  "tDSTAR", "tAMPER", "tLAMBDA", "tANDDOT", "tSYMBEG", "tREGEXP_BEG",
  "tWORDS_BEG", "tSYMBOLS_BEG", "tSTRING_BEG", "tXSTRING_BEG",
  "tSTRING_DVAR", "tLAMBEG", "tHEREDOC_BEG", "tHEREDOC_END",
  "tLITERAL_DELIM", "tHD_LITERAL_DELIM", "tHD_STRING_PART",
  "tHD_STRING_MID", "tLOWEST", "'='", "'?'", "':'", "'>'", "'<'", "'|'",
  "'^'", "'&'", "'+'", "'-'", "'*'", "'/'", "'%'", "tUMINUS_NUM", "'!'",
  "'~'", "tLAST_TOKEN", "'{'", "'}'", "'['", "','", "'`'", "'('", "')'",
  "']'", "';'", "'.'", "'\\n'", "$accept", "program", "$@1",
  "top_compstmt", "top_stmts", "top_stmt", "@2", "bodystmt", "compstmt",
  "stmts", "stmt", "$@3", "command_asgn", "command_rhs", "expr",
  "expr_value", "command_call", "block_command", "cmd_brace_block", "$@4",
  "command", "mlhs", "mlhs_inner", "mlhs_basic", "mlhs_item", "mlhs_list",
  "mlhs_post", "mlhs_node", "lhs", "cname", "cpath", "fname", "fsym",
  "undef_list", "$@5", "op", "reswords", "arg", "aref_args", "arg_rhs",
  "paren_args", "opt_paren_args", "opt_call_args", "call_args",
  "command_args", "@6", "block_arg", "opt_block_arg", "comma", "args",
  "mrhs", "primary", "@7", "@8", "$@9", "$@10", "@11", "@12", "$@13",
  "$@14", "$@15", "$@16", "$@17", "$@18", "@19", "@20", "@21", "@22",
  "@23", "@24", "@25", "@26", "primary_value", "then", "do", "if_tail",
  "opt_else", "for_var", "f_margs", "$@27", "block_args_tail",
  "opt_block_args_tail", "block_param", "opt_block_param",
  "block_param_def", "$@28", "opt_bv_decl", "bv_decls", "bvar",
  "f_larglist", "lambda_body", "do_block", "$@29", "block_call",
  "method_call", "brace_block", "@30", "@31", "case_body", "cases",
  "opt_rescue", "exc_list", "exc_var", "opt_ensure", "literal", "string",
  "string_fragment", "string_rep", "string_interp", "@32", "xstring",
  "regexp", "heredoc", "heredoc_bodies", "heredoc_body",
  "heredoc_string_rep", "heredoc_string_interp", "@33", "words", "symbol",
  "basic_symbol", "sym", "symbols", "numeric", "variable", "var_lhs",
  "var_ref", "backref", "superclass", "$@34", "f_arglist", "f_label",
  "f_kw", "f_block_kw", "f_block_kwarg", "f_kwarg", "kwrest_mark",
  "f_kwrest", "args_tail", "opt_args_tail", "f_args", "f_bad_arg",
  "f_norm_arg", "f_arg_item", "@35", "f_arg", "f_opt_asgn", "f_opt",
  "f_block_opt", "f_block_optarg", "f_optarg", "restarg_mark",
  "f_rest_arg", "blkarg_mark", "f_block_arg", "opt_f_block_arg",
  "singleton", "$@36", "assoc_list", "assocs", "assoc", "operation",
  "operation2", "operation3", "dot_or_colon", "call_op", "call_op2",
  "opt_terms", "opt_nl", "rparen", "rbracket", "trailer", "term", "nl",
  "terms", "none", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,    61,    63,
      58,    62,    60,   124,    94,    38,    43,    45,    42,    47,
      37,   373,    33,   126,   374,   123,   125,    91,    44,    96,
      40,    41,    93,    59,    46,    10
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   146,   148,   147,   149,   150,   150,   150,   150,   151,
     152,   151,   153,   154,   155,   155,   155,   155,   157,   156,
     156,   156,   156,   156,   156,   156,   156,   156,   156,   156,
     156,   156,   156,   158,   158,   158,   158,   158,   158,   158,
     158,   159,   159,   159,   160,   160,   160,   160,   160,   160,
     161,   162,   162,   163,   163,   165,   164,   166,   166,   166,
     166,   166,   166,   166,   166,   166,   166,   166,   167,   167,
     168,   168,   169,   169,   169,   169,   169,   169,   169,   169,
     169,   169,   170,   170,   171,   171,   172,   172,   173,   173,
     173,   173,   173,   173,   173,   173,   174,   174,   174,   174,
     174,   174,   174,   174,   175,   175,   176,   176,   176,   177,
     177,   177,   177,   177,   178,   178,   179,   180,   179,   181,
     181,   181,   181,   181,   181,   181,   181,   181,   181,   181,
     181,   181,   181,   181,   181,   181,   181,   181,   181,   181,
     181,   181,   181,   181,   181,   181,   181,   181,   181,   182,
     182,   182,   182,   182,   182,   182,   182,   182,   182,   182,
     182,   182,   182,   182,   182,   182,   182,   182,   182,   182,
     182,   182,   182,   182,   182,   182,   182,   182,   182,   182,
     182,   182,   182,   182,   182,   182,   182,   182,   182,   183,
     183,   183,   183,   183,   183,   183,   183,   183,   183,   183,
     183,   183,   183,   183,   183,   183,   183,   183,   183,   183,
     183,   183,   183,   183,   183,   183,   183,   183,   183,   183,
     183,   183,   183,   183,   183,   183,   183,   183,   183,   183,
     183,   183,   184,   184,   184,   184,   185,   185,   186,   187,
     187,   188,   188,   188,   188,   188,   189,   189,   189,   189,
     189,   191,   190,   192,   193,   193,   194,   194,   195,   195,
     195,   195,   196,   196,   196,   197,   197,   197,   197,   197,
     197,   197,   197,   198,   197,   199,   200,   197,   201,   197,
     197,   197,   197,   197,   197,   197,   197,   197,   197,   197,
     197,   197,   202,   203,   197,   197,   197,   204,   205,   197,
     206,   207,   197,   197,   197,   208,   209,   197,   210,   197,
     211,   212,   197,   213,   197,   214,   215,   197,   216,   217,
     197,   197,   197,   197,   197,   218,   219,   219,   219,   220,
     220,   221,   221,   222,   222,   223,   223,   224,   224,   224,
     224,   224,   224,   224,   224,   225,   224,   226,   226,   226,
     226,   227,   227,   228,   228,   228,   228,   228,   228,   228,
     228,   228,   228,   228,   228,   228,   228,   228,   229,   229,
     231,   230,   230,   230,   232,   232,   233,   233,   234,   234,
     235,   235,   236,   236,   238,   237,   239,   239,   239,   239,
     240,   240,   240,   240,   240,   240,   240,   240,   240,   242,
     241,   243,   241,   244,   245,   245,   246,   246,   247,   247,
     247,   248,   248,   249,   249,   250,   250,   250,   250,   251,
     251,   252,   252,   252,   252,   253,   253,   254,   255,   254,
     254,   254,   256,   256,   257,   257,   258,   259,   259,   260,
     260,   261,   261,   262,   263,   262,   264,   264,   265,   265,
     266,   267,   267,   267,   267,   267,   267,   268,   268,   269,
     269,   269,   269,   270,   270,   270,   270,   270,   271,   272,
     272,   272,   272,   272,   272,   272,   272,   273,   273,   274,
     275,   274,   276,   276,   277,   278,   278,   279,   279,   280,
     280,   281,   281,   282,   282,   283,   283,   284,   284,   284,
     284,   285,   285,   286,   286,   286,   286,   286,   286,   286,
     286,   286,   286,   286,   286,   286,   286,   286,   287,   287,
     287,   287,   288,   288,   289,   290,   289,   291,   291,   292,
     293,   294,   295,   295,   296,   296,   297,   297,   298,   298,
     299,   299,   300,   301,   301,   302,   303,   302,   304,   304,
     305,   305,   306,   306,   306,   306,   307,   307,   307,   308,
     308,   308,   308,   309,   309,   309,   310,   310,   311,   311,
     312,   312,   313,   313,   314,   314,   315,   316,   317,   317,
     317,   318,   318,   318,   319,   320,   320,   321
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     2,     1,     1,     3,     2,     1,
       0,     5,     4,     2,     1,     1,     3,     2,     0,     4,
       2,     3,     3,     3,     3,     3,     4,     1,     3,     3,
       3,     3,     1,     3,     3,     6,     5,     5,     5,     5,
       3,     1,     3,     1,     1,     3,     3,     3,     2,     1,
       1,     1,     1,     1,     4,     0,     5,     2,     3,     4,
       5,     4,     5,     2,     2,     2,     2,     2,     1,     3,
       1,     3,     1,     2,     3,     5,     2,     4,     2,     4,
       1,     3,     1,     3,     2,     3,     1,     2,     1,     4,
       3,     3,     3,     3,     2,     1,     1,     4,     3,     3,
       3,     3,     2,     1,     1,     1,     2,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     4,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       3,     6,     5,     5,     5,     5,     4,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     4,     4,     2,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     2,     3,     3,     3,     3,     6,
       6,     1,     1,     2,     4,     2,     1,     3,     3,     1,
       1,     1,     1,     2,     4,     2,     1,     2,     2,     4,
       1,     0,     2,     2,     2,     1,     1,     2,     1,     2,
       3,     4,     3,     4,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     4,     0,     0,     5,     0,     3,
       3,     3,     2,     3,     3,     1,     2,     4,     3,     2,
       1,     2,     0,     0,     5,     6,     6,     0,     0,     7,
       0,     0,     7,     5,     4,     0,     0,     9,     0,     6,
       0,     0,     8,     0,     5,     0,     0,     7,     0,     0,
       9,     1,     1,     1,     1,     1,     1,     1,     2,     1,
       1,     1,     5,     1,     2,     1,     1,     1,     4,     6,
       3,     5,     2,     4,     1,     0,     4,     4,     2,     2,
       1,     2,     0,     6,     8,     4,     6,     4,     3,     6,
       2,     4,     6,     2,     4,     2,     4,     1,     1,     1,
       0,     4,     1,     4,     1,     4,     1,     3,     1,     1,
       4,     1,     3,     3,     0,     5,     2,     4,     5,     5,
       2,     4,     4,     3,     3,     3,     2,     1,     4,     0,
       5,     0,     5,     5,     1,     1,     6,     1,     1,     1,
       1,     2,     1,     2,     1,     1,     1,     1,     1,     1,
       2,     1,     1,     2,     3,     1,     2,     1,     0,     4,
       1,     2,     2,     3,     2,     3,     1,     1,     2,     1,
       2,     1,     2,     1,     0,     4,     2,     3,     1,     4,
       2,     1,     1,     1,     1,     1,     2,     2,     3,     1,
       1,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       0,     4,     3,     2,     2,     2,     1,     2,     1,     1,
       3,     1,     3,     1,     1,     2,     1,     4,     2,     2,
       1,     2,     0,     6,     8,     4,     6,     4,     6,     2,
       4,     6,     2,     4,     2,     4,     1,     0,     1,     1,
       1,     1,     1,     1,     1,     0,     4,     1,     3,     2,
       2,     2,     1,     3,     1,     3,     1,     1,     2,     1,
       1,     1,     2,     2,     1,     1,     0,     4,     1,     2,
       1,     3,     3,     3,     3,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     1,     0,     1,     2,     2,     0,     1,
       1,     1,     1,     1,     1,     1,     2,     0
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       2,     0,     0,     1,     0,     0,     0,     0,   273,     0,
       0,   297,   300,     0,     0,   572,   321,   322,   323,   324,
     285,   251,   397,   471,   470,   472,   473,   574,     0,    10,
       0,   475,   474,   476,   463,   272,   465,   464,   467,   466,
     459,   460,   421,   422,   477,   478,     0,     0,     0,     0,
     275,   587,   587,    80,   292,     0,     0,     0,     0,     0,
       0,   436,     0,     0,     0,     3,   572,     6,     9,    27,
      32,    44,    52,    51,     0,    68,     0,    72,    82,     0,
      49,   231,     0,    53,   290,   265,   266,   419,   267,   268,
     269,   417,   416,   448,   418,   415,   469,     0,   270,   271,
     251,     5,     8,   321,   322,   285,   587,   397,     0,   104,
     105,     0,     0,     0,     0,   107,   479,   325,     0,   469,
     271,     0,   313,   159,   169,   160,   156,   185,   186,   187,
     188,   167,   182,   175,   165,   164,   180,   163,   162,   158,
     183,   157,   170,   174,   176,   168,   161,   177,   184,   179,
     178,   171,   181,   166,   155,   173,   172,   154,   152,   153,
     149,   150,   151,   109,   111,   110,   144,   145,   140,   122,
     123,   124,   131,   128,   130,   125,   126,   146,   147,   132,
     133,   137,   141,   127,   129,   119,   120,   121,   134,   135,
     136,   138,   139,   142,   143,   148,   546,   315,   112,   113,
     545,     0,     0,     0,    50,     0,     0,     0,   469,     0,
     271,     0,     0,     0,     0,   336,   335,     0,     0,   469,
     271,   178,   171,   181,   166,   149,   150,   151,   109,   110,
       0,   114,   116,    20,   115,   439,   444,   443,   581,   584,
     572,   583,     0,   441,     0,   585,   582,   573,   556,     0,
       0,     0,     0,   246,   258,    66,   250,   587,   419,   587,
     550,    67,    65,   587,   240,   286,    64,     0,   239,   396,
      63,   574,     0,   575,    18,     0,     0,   208,     0,   209,
     282,     0,     0,     0,   572,    15,   574,    70,    14,     0,
     574,     0,   578,   578,   232,     0,     0,   578,   548,     0,
       0,    78,     0,    88,    95,   517,   453,   452,   454,   455,
       0,   451,   450,   434,   428,   427,   430,     0,     0,   425,
     446,     0,   457,     0,   423,     0,   432,     0,   461,   462,
      48,   223,   224,     4,   573,     0,     0,     0,     0,     0,
       0,     0,   384,   386,     0,    84,     0,    76,    73,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   569,   587,   568,
       0,   571,   570,     0,   401,   399,   291,   420,     0,     0,
     390,    57,   289,   310,   104,   105,   106,   461,   462,   480,
     308,     0,   587,     0,     0,     0,   316,   567,   566,   318,
       0,   587,   282,   327,     0,   326,     0,     0,   587,     0,
       0,     0,     0,     0,     0,   282,     0,   587,     0,   305,
       0,   117,     0,     0,   440,   442,     0,     0,   586,     0,
     259,   555,   253,     0,   256,   247,     0,   255,     0,   256,
     248,     0,   574,   242,   587,   587,   241,   252,   574,     0,
     288,    47,     0,     0,     0,     0,     0,     0,    17,   574,
     280,    13,   573,    69,   276,   279,   283,   580,   233,   579,
     580,   235,   284,   549,    94,    86,     0,    81,     0,     0,
     587,     0,   523,   520,   519,   518,   521,   493,   525,   537,
     494,   541,   540,   536,   517,   293,   486,   491,   587,   496,
     587,   516,   381,   522,   524,   527,   502,     0,   534,   502,
     539,   502,     0,   500,   456,     0,     0,   431,   437,   435,
     426,   447,   458,   424,   433,     0,     0,     7,    21,    22,
      23,    24,    25,    45,    46,   587,     0,    28,    30,     0,
      31,   574,     0,    74,    85,    43,    33,    41,     0,   236,
     189,    29,     0,   271,   205,   213,   218,   219,   220,   215,
     217,   227,   228,   221,   222,   198,   199,   225,   226,   574,
     214,   216,   210,   211,   212,   200,   201,   202,   203,   204,
     559,   564,   560,   565,   395,   251,   393,   574,   559,   561,
     560,   562,   394,   587,   559,   560,   251,   587,   587,    34,
     236,   190,    40,   197,    55,    58,     0,     0,     0,   104,
     105,   108,     0,   574,   587,     0,   574,   517,     0,   274,
     587,   587,   407,   587,   328,   563,   281,   574,   559,   560,
     587,   330,   298,   329,   301,   563,   281,   574,   559,   560,
       0,     0,     0,     0,   258,     0,   304,   553,   552,   257,
       0,   260,   254,   587,   554,   551,   238,   256,     0,   245,
     287,   576,    19,     0,    26,   196,    71,    16,   574,   578,
      87,    79,   563,    93,   574,   559,   560,   484,   529,     0,
     574,     0,   485,     0,   498,   544,   495,     0,   499,     0,
     509,   530,     0,   512,   538,     0,   514,   542,   449,     0,
     438,   206,   207,   372,   370,     0,   369,   368,   264,     0,
      83,    77,     0,     0,     0,     0,     0,   587,     0,     0,
       0,     0,   392,    61,     0,   398,     0,     0,   391,    59,
     387,    54,     0,     0,   587,   311,     0,     0,   398,   314,
     547,   517,     0,     0,   319,   408,   409,   587,   410,     0,
     587,   333,     0,     0,   331,     0,     0,   398,     0,     0,
       0,     0,     0,   398,     0,   118,   445,   303,     0,     0,
     261,   249,   587,    11,   277,   234,   398,   523,   344,   574,
     337,     0,   374,     0,     0,   294,     0,   492,   587,   543,
     501,   528,   502,   502,   502,   535,   502,   523,   502,   429,
     367,   574,   574,   488,   489,   587,   587,   352,     0,   532,
     352,   352,   350,     0,     0,   262,    75,    42,   237,   559,
     560,   574,   559,   560,     0,     0,    39,   194,    38,   195,
      62,   577,     0,    36,   192,    37,   193,    60,   388,   389,
       0,     0,     0,     0,   481,   309,   574,     0,   483,   517,
       0,     0,   412,   334,     0,    12,   414,     0,   295,     0,
     296,     0,     0,   306,   260,   587,   244,   345,   342,   526,
       0,   380,     0,     0,     0,   497,     0,   505,     0,   507,
       0,   513,     0,   510,   515,     0,     0,     0,   487,     0,
     348,   349,   352,   360,   531,     0,   363,     0,   365,   385,
     263,   398,   230,   229,    35,   191,   402,   400,     0,     0,
     482,   317,     0,     0,   411,     0,    96,   103,     0,   413,
       0,   299,   302,     0,   404,   405,   403,     0,     0,   340,
     378,   574,   376,   379,   383,   382,   502,   502,   502,   502,
     373,   371,   282,     0,   490,   587,     0,   351,   358,   352,
     352,   352,   533,   352,   352,    56,   312,     0,   102,     0,
     587,     0,   587,   587,     0,   346,   343,     0,   338,     0,
     375,   506,     0,   503,   508,   511,   563,   281,   347,     0,
     355,     0,   357,     0,   364,     0,   361,   366,   320,    99,
     101,   574,   559,   560,   406,   332,   307,     0,   341,     0,
     377,   502,   352,   352,   352,   352,    97,   339,   504,   356,
       0,   353,   359,   362,   352,   354
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    65,    66,    67,   275,   410,   411,   284,
     285,   462,    69,   556,    70,   205,    71,    72,   615,   744,
      73,    74,   286,    75,    76,    77,   487,    78,   206,   115,
     116,   231,   232,   233,   651,   593,   199,    80,   291,   560,
     594,   265,   452,   453,   266,   267,   256,   445,   451,   454,
     550,    81,   202,   289,   678,   290,   305,   691,   212,   771,
     213,   772,   650,   933,   618,   616,   853,   404,   406,   627,
     628,   859,   278,   414,   642,   763,   764,   218,   789,   937,
     957,   903,   811,   715,   716,   812,   791,   941,   942,   505,
     795,   343,   545,    83,    84,   392,   608,   607,   437,   936,
     631,   757,   861,   865,    85,    86,    87,   318,   319,   526,
      88,    89,    90,   659,   241,   242,   243,   432,    91,    92,
      93,   312,    94,    95,   208,   209,    98,   210,   400,   617,
     752,   506,   507,   814,   815,   508,   509,   510,   800,   700,
     753,   513,   514,   515,   689,   516,   517,   518,   819,   820,
     519,   520,   521,   522,   523,   694,   201,   405,   296,   455,
     260,   121,   622,   596,   409,   403,   383,   244,   459,   460,
     735,   478,   415,   273,   247,   288
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -826
static const yytype_int16 yypact[] =
{
    -826,    98,  2785,  -826,  7387,  9342,  9675,  5490,  -826,  8997,
    8997,  -826,  -826,  9453,  6891,  5231,  7847,  7847,  -826,  -826,
    7847,  3027,  6249,  -826,  -826,  -826,  -826,   230,  6891,  -826,
      -2,  -826,  -826,  -826,  5628,  5743,  -826,  -826,  5858,  -826,
    -826,  -826,  -826,  -826,  -826,  -826,  9112,  9112,   118,  4508,
     335,  8077,  8307,  7165,  -826,  6617,   485,  1106,  1173,  1250,
     726,  -826,   354,  9227,  9112,  -826,   947,  -826,  1248,  -826,
     381,  -826,  -826,   216,   112,  -826,   121,  9564,  -826,   143,
   10006,   434,   467,    87,    39,  -826,   106,  -826,  -826,  -826,
    -826,  -826,  -826,  -826,  -826,  -826,   361,   184,  -826,   455,
      37,  -826,  -826,  -826,  -826,  -826,   136,   136,   142,   833,
     843,  8997,   465,  4624,   373,  -826,   168,  -826,   557,  -826,
    -826,    37,  -826,  -826,  -826,  -826,  -826,  -826,  -826,  -826,
    -826,  -826,  -826,  -826,  -826,  -826,  -826,  -826,  -826,  -826,
    -826,  -826,  -826,  -826,  -826,  -826,  -826,  -826,  -826,  -826,
      53,   102,   126,   135,  -826,  -826,  -826,  -826,  -826,  -826,
     175,   179,   187,   205,  -826,   213,  -826,  -826,  -826,  -826,
    -826,  -826,  -826,  -826,  -826,  -826,  -826,  -826,  -826,  -826,
    -826,  -826,  -826,  -826,  -826,  -826,  -826,  -826,  -826,  -826,
    -826,  -826,  -826,  -826,  -826,  -826,  -826,  -826,  -826,  -826,
    -826,   214,  3704,   241,   381,   202,   180,   664,    63,   232,
      66,   202,  8997,  8997,   265,  -826,  -826,   750,   303,    61,
      86,  -826,  -826,  -826,  -826,  -826,  -826,  -826,  -826,  -826,
    6754,  -826,  -826,   229,  -826,  -826,  -826,  -826,  -826,  -826,
     947,  -826,   366,  -826,   323,  -826,  -826,   947,  2894,  9112,
    9112,  9112,  9112,  -826, 11494,  -826,  -826,   242,   363,   287,
    -826,  -826,  -826,  7847,  -826,  -826,  -826,  7847,  -826,  -826,
    -826,  5347,  8997,  -826,  -826,   302,  4740,  -826,   775,   368,
     531,  7617,  4508,   311,   947,  1248,   299,   337,  -826,  7617,
     299,   328,    14,   150,  -826, 11494,   339,   150,  -826,   429,
    9786,   376,   779,   783,   811,   966,  -826,  -826,  -826,  -826,
    1304,  -826,  -826,  -826,  -826,  -826,  -826,   389,   693,  -826,
    -826,  1332,  -826,  1349,  -826,  1403,  -826,  1010,   446,   456,
    -826,  -826,  -826,  -826,  4999,  8997,  8997,  8997,  8997,  7617,
    8997,  8997,  -826,  -826,  8422,  -826,  4508,  7276,   413,  8422,
    9112,  9112,  9112,  9112,  9112,  9112,  9112,  9112,  9112,  9112,
    9112,  9112,  9112,  9112,  9112,  9112,  9112,  9112,  9112,  9112,
    9112,  9112,  9112,  9112,  9112,  9112,  2263,  -826,  7847,  -826,
   10071,  -826,  -826, 11233,  -826,  -826,  -826,  -826,  9227,  9227,
    -826,   457,  -826,   381,  -826,   838,  -826,  -826,  -826,  -826,
    -826, 10154,  7847, 10237,  3704,  8997,  -826,  -826,  -826,  -826,
     541,   544,   181,  -826,  3847,   550,  9112, 10320,  7847, 10403,
    9112,  9112,  4133,   846,   846,    94, 10486,  7847, 10569,  -826,
     497,  -826,  4740,   323,  -826,  -826,  8537,   562,  -826,  9112,
   10006, 10006, 10006,  9112,   389,  -826,  7962,  -826,  9112,  7732,
    -826,   479,   299,  -826,   443,   444,  -826,  -826,    84,   442,
    -826,  -826,  6891,  4249,   449, 10320, 10403,  9112,  1248,   299,
    -826,  -826,  5115,   470,  1248,  -826,  -826,  8192,  -826,  -826,
    -826,  -826,  -826,  -826,   838,   121,  9786,  -826,  9786, 10652,
    7847, 10735,    17,  -826,  -826,  -826,  -826,  -826,  -826,  -826,
    -826,  -826,  -826,  -826,  1336,  -826,  9112,  -826,   474,   536,
     476,  -826,  -826,  -826,  -826,  -826,   498,  9112,  -826,   500,
     552,   503,   592,  -826,  -826,  1407,  4740,   389,  -826,  -826,
    -826,  -826,  -826,  -826,  -826,  9112,  9112,  -826,  -826,  -826,
    -826,  -826,  -826,  -826,  -826,   115,  9112,  -826, 11322,   242,
    -826,   299,  9786,   506,  -826,  -826,  -826,   604,   535,  1962,
    -826,  -826,   913,   194,   368, 10091, 10091, 10091, 10091,  1170,
    1170, 10174, 11515, 10091, 10091,  2587,  2587,   700,   700, 11262,
    1170,  1170,   879,   879,  1178,   401,   401,   368,   368,   368,
    3160,  6364,  3426,  6479,  -826,   136,  -826,   299,   623,  -826,
     631,  -826,  -826,  6249,  -826,  -826,  1848,   115,   115,  -826,
    2333,  -826,  -826,  -826,  -826,  -826,   947,  8997,  3704,   858,
     451,  -826,   136,   299,   136,   639,    84,  1569,  7028,  -826,
    8652,   637,  -826,   477,  -826,  5973,  6111,   299,   195,   218,
     637,  -826,  -826,  -826,  -826,    64,    99,   299,   111,   113,
    8997,  6891,   524,   650, 10006,   584,  -826, 10006, 10006,   389,
    9112, 11494,  -826,   287, 10006,  -826,  -826,  1080,  7962,  7502,
    -826,  -826,  -826,   532,  -826,  -826,    47,  1248,   299,   150,
     413,  -826,    42,   451,   299,    50,    74,  -826,  -826,  1227,
     299,    83, 10006,   169,  -826,  -826,  -826,    32,  -826,  1336,
    -826, 10006,  1336,  -826,  -826,  1091,  -826,  -826,  -826,   537,
    -826,   368,   368,  -826,  1336,  3704,  -826,  -826, 11340,  8767,
    -826,  -826,  9786,  7617,  9227,  9112, 10818,  7847, 10901,    58,
    9227,  9227,  -826,   457,   525,   675,  9227,  9227,  -826,   457,
      39,   216,  3704,  4740,   115,  -826,   947,   656,  -826,  -826,
    -826,  1336,  3704,   947,  -826, 11322,  -826,   583,  -826,  4392,
     662,  -826,  8997,   683,  -826,  9112,  9112,   219,  9112,  9112,
     687,  4883,  4883,   117,   846,  -826,  -826,  -826,  8882,  3990,
   10006,  -826,   574,  -826,  -826,  -826,   197,  -826,   437,   299,
     577,   579,   575,  3704,  4740,  -826,   666,  -826,   476,  -826,
    -826,  -826,   587,   590,   598,  -826,   600,   666,   598,  -826,
    -826,   299,   299,  9897,  -826,   602,   476,   607,  9897,  -826,
     608,   615,  -826,   715,  9112, 11408,  -826,  -826, 10006,  3293,
    3559,   299,   221,   235,  9112,  9112,  -826,  -826,  -826,  -826,
    -826,  -826,  9227,  -826,  -826,  -826,  -826,  -826,  -826,  -826,
     748,   640,  4740,  3704,  -826,  -826,   299,   752,  -826,  1569,
   10008,   202,  -826,  -826,  4883,  -826,  -826,   202,  -826,  9112,
    -826,   773,   780,  -826, 10006,   131,  7502,  -826,   658,  -826,
    1451,  -826,   985,   784,   667,  -826,  1336,  -826,  1091,  -826,
    1091,  -826,  1091,  -826,  -826,   679,   688,   743,   923,   169,
    -826,  -826,  1102,  -826,   923,  1336,  -826,  1091,  -826,  -826,
   11426,   325, 10006, 10006,  -826,  -826,  -826,  -826,   680,   802,
    -826,  -826,  3704,   764,  -826,   943,   783,   811,  3704,  -826,
    3847,  -826,  -826,  4883,  -826,  -826,  -826,  1046,  1046,   487,
    -826,   255,  -826,  -826,  -826,  -826,   598,   682,   598,   598,
    -826,  -826,  -826, 10984,  -826,   476,   169,  -826,  -826,   685,
     695,   697,  -826,   699,   697,  -826,  -826,   806,   838, 11067,
    7847, 11150,   544,   477,   810,   703,   703,  1046,   707,   985,
    -826,  -826,  1091,  -826,  -826,  -826,   706,   711,  -826,  1336,
    -826,  1091,  -826,  1091,  -826,  1091,  -826,  -826,  -826,   858,
     451,   299,   789,   794,  -826,  -826,  -826,  1046,   703,  1046,
    -826,   598,   697,   709,   697,   697,   108,   703,  -826,  -826,
    1091,  -826,  -826,  -826,   697,  -826
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -826,  -826,  -826,   398,  -826,    30,  -826,  -178,   -40,  -826,
      52,  -826,  -218,  -340,  1039,    92,   -20,  -826,  -619,  -826,
     -13,   849,  -192,   -25,   -52,  -261,  -436,   -21,  1830,   -74,
     859,     3,   -17,  -826,  -826,     5,  -826,   983,  -826,   745,
      55,    13,  -323,   127,    -9,  -826,  -338,  -257,  -147,    67,
    -314,    40,  -826,  -826,  -826,  -826,  -826,  -826,  -826,  -826,
    -826,  -826,  -826,  -826,  -826,  -826,  -826,  -826,  -826,  -826,
    -826,  -826,   346,  -195,  -396,   -98,  -572,  -826,  -826,  -826,
     165,   634,  -826,  -538,  -826,  -826,  -278,  -826,   -96,  -826,
    -826,   145,  -826,  -826,  -826,   -76,  -826,  -826,  -410,  -826,
     -81,  -826,  -826,  -826,  -826,  -826,    20,    69,  -118,  -826,
    -826,  -826,  -826,   580,  -286,  -826,   660,  -826,  -826,  -826,
       1,  -826,  -826,  -826,  1723,  1854,   885,  1435,  -826,  -826,
      49,    23,   222,    12,  -826,  -826,  -826,  -113,  -283,  -241,
    -287,  -800,  -731,  -367,  -826,   851,  -613,  -658,  -825,    15,
     225,  -826,  -605,  -826,  -125,  -444,  -826,  -826,  -826,    10,
    -435,   840,  -280,  -826,  -826,   -77,  -826,   -24,   -27,  -205,
    -559,  -276,    26,  1254,   -19,    -1
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -588
static const yytype_int16 yytable[] =
{
     272,   101,   450,   253,   253,   380,   382,   253,   386,   283,
     197,   274,   198,   270,   665,   234,   422,   481,   512,   198,
     268,   483,   511,   653,   287,   348,   259,   259,   644,   234,
     259,   528,   301,   198,   102,   561,   258,   258,   396,   486,
     258,   245,   333,   330,   805,   117,   117,   334,   609,   612,
     294,   298,   681,   117,    68,   597,    68,   878,   311,   760,
     198,   293,   297,   384,   748,   384,   698,   -91,   770,   742,
     743,   258,   258,   283,   687,   -90,   264,   269,   767,   623,
     962,   473,   943,   257,   257,   475,   -96,   257,   773,   -99,
     469,   391,   245,   117,   803,   637,   595,   806,     3,   -92,
     603,   818,   211,   606,   647,   268,   387,   240,   662,   821,
     446,  -103,   793,   662,   840,   834,   721,   117,   292,  -102,
     847,   340,   341,   624,  -101,   786,   321,   323,   325,   327,
     419,   555,   501,   276,  -398,   688,   -98,   595,  -100,   603,
     428,  -471,   -97,   255,   261,   477,   480,   262,   624,   759,
     480,   436,   444,  -468,   551,   390,   421,   502,   528,   239,
     -91,   264,   269,   528,   962,   -69,    42,   684,   -90,    43,
     555,   555,   385,   280,   385,   381,   390,   263,   835,   943,
     -91,   -96,  -559,   -91,  -103,   -83,   624,   -91,   -90,   377,
    -470,   -90,   -92,   794,   713,   -90,  -398,  -471,   450,   -88,
     530,   466,   -91,   530,  -559,   530,   852,   530,   978,   530,
    -398,   624,   -92,    59,  -472,   -92,   433,   690,   413,   -92,
     796,   511,   -89,  -473,   -95,   491,   625,   486,   805,   239,
     344,   379,   -94,   311,   665,   198,   464,   -93,   714,  -560,
     497,   710,   283,  -398,   342,  -398,  -470,   666,   485,   -90,
     253,   -92,  -398,   670,   253,   -89,   447,   287,   447,   345,
     471,   349,   456,  -475,   676,   472,   245,  -474,   500,   501,
    -472,   467,   911,   438,   388,  -476,   263,   259,   703,  -473,
     706,   947,   271,   258,   389,   768,   826,   258,   449,   818,
     399,   486,   818,  -463,   502,   239,   412,   960,   416,  -102,
     963,  -467,   407,   934,   423,   424,   283,   668,   769,   869,
     245,   736,  -103,   -98,   235,   -89,   756,   236,   237,  -475,
     425,   287,   420,  -474,   547,   737,   553,   621,   429,   557,
     662,  -476,   801,   468,   257,   -89,  -100,   -97,   -89,   -98,
     117,   474,   -89,   436,   511,   238,   720,   239,    82,  -463,
      82,   118,   118,  -100,   885,   207,   207,  -467,   408,   217,
     438,   207,   207,   207,   537,   253,   207,   431,   557,   557,
     271,   900,   901,   710,   633,   239,   818,   456,   873,   525,
     444,   528,   640,   528,  1013,   601,    68,   117,   601,   253,
     836,   542,   652,   979,   457,    82,   843,   845,   258,   302,
     239,   456,   719,   785,   831,   253,   781,   530,   601,   207,
     632,   549,   328,   329,   253,   842,   549,   456,   340,   341,
     448,   750,   258,   302,   601,   449,   456,   538,   539,   540,
     541,   397,   398,   601,   680,   602,   485,   463,   258,   350,
     747,   665,  1016,   -97,   239,   672,   595,   258,   603,   643,
     643,  -468,   470,   447,   447,   -68,   663,   207,   602,    82,
     779,   486,   101,   234,   856,   935,   258,   198,   511,   258,
     476,   601,   350,   784,   602,   482,  -278,   253,   434,   -96,
    -278,   236,   237,   602,   484,   728,   709,   679,   787,   456,
     493,   494,   495,   496,   762,   759,   601,   258,   438,   -88,
     485,   235,   914,   655,   236,   237,   555,   695,   778,   695,
     258,   988,   555,   801,   488,    68,   394,   535,   555,   555,
     395,   602,  -325,   801,   677,   781,   117,   536,   117,   373,
     374,   375,   480,   895,   896,   801,  -325,   823,   787,  -281,
     493,   494,   495,   496,   717,   389,   602,   313,    82,   314,
     315,   554,   729,  -281,   614,   376,   629,   630,   207,   207,
     524,   887,   889,   891,   850,   893,   634,   894,   799,   377,
     734,  -325,   799,  -103,   857,   877,   511,   656,  -325,   251,
     798,   667,   669,   671,   879,   674,   733,   696,  -281,   822,
     528,  -560,   117,   -95,   739,  -281,   734,   741,   316,   317,
     413,   816,   268,   704,   378,   268,   717,   717,   -83,   207,
     734,   379,   693,   207,   697,   883,   738,   207,   207,   740,
     734,   467,    82,   268,   555,   977,   801,    82,    82,   758,
     761,   754,   761,   198,   775,    82,   699,   738,   702,   761,
     801,   705,   745,   707,   722,   401,   302,  1001,   723,  -102,
     732,   920,   234,   724,   749,   759,   198,   734,   264,   377,
     776,   264,   447,   792,   848,   777,   928,   841,   783,   -94,
     485,   855,   930,   809,   860,   919,   864,   732,   782,   264,
      82,   207,   207,   207,   207,    82,   207,   207,   258,   258,
     207,   624,    82,   302,   402,   562,   235,   549,   868,   236,
     237,   379,   870,   851,   557,   981,   983,   984,   985,   746,
     557,   838,   876,   736,   253,   880,   557,   557,   882,   863,
     881,   737,   444,   687,   207,   886,   456,   238,   888,   239,
     909,   871,   872,   601,   562,   562,   890,   813,   892,   875,
     899,   -98,   774,   717,   967,   902,   905,   258,   207,  -100,
      82,   207,   417,   907,   884,   529,   862,   314,   315,   866,
      82,   -90,   117,   916,   207,   842,   377,   921,    82,   -92,
    1018,   350,   854,   207,   799,   827,   917,   822,    82,   858,
     822,   447,   822,   602,   792,   792,   955,   326,   931,   816,
     314,   315,   816,   -97,   816,   932,   938,   695,   952,   944,
     643,   418,   950,   945,   734,   -98,   316,   317,   379,    82,
    -100,   951,   918,   -89,   695,   695,   965,   966,    82,   968,
     982,   998,   557,   989,   929,  1006,   371,   372,   373,   374,
     375,   822,   302,   991,   302,   993,   207,   995,   426,   316,
     317,  1007,   100,   816,   100,  1009,  -559,  1020,   971,   100,
     100,  -560,   377,   117,   867,   100,   100,   100,   117,  -556,
     100,   673,   215,   465,   822,   122,   822,   489,   822,  -557,
     822,  -469,    82,   641,   761,  1005,   816,   377,   816,   810,
     816,   377,   816,  1010,  -563,  -469,   849,   427,   972,   100,
     973,  1004,   200,   974,   379,   822,   258,   527,   302,  -271,
     117,   -98,   435,   100,   -98,   -98,  -100,   816,   922,  -100,
    -100,   954,   418,  -271,   980,   797,   490,   959,     0,   379,
    -469,  -463,   813,   379,   802,   813,  -282,  -469,   813,     0,
     813,  -467,   -98,     0,   -98,  -463,     0,  -100,     0,  -100,
    -282,     0,     0,     0,     0,  -467,  -563,     0,  -271,     0,
     350,   100,     0,   100,   695,  -271,     0,   253,   235,     0,
    -563,   236,   237,   207,    82,   363,   364,     0,  -556,   456,
    -463,   632,   761,  -556,   734,  -282,   601,  -463,  -557,   813,
    -467,     0,  -282,  -557,     0,     0,     0,  -467,     0,   238,
     258,   239,     0,  -563,     0,  -563,   207,     0,  -559,   254,
     254,   726,  -563,   254,   370,   371,   372,   373,   374,   375,
       0,   953,   813,     0,   813,   377,   813,   492,   813,   493,
     494,   495,   496,     0,     0,   377,   602,     0,     0,   277,
     279,   969,     0,     0,   254,   295,   940,   497,   493,   494,
     495,   496,   100,   813,     0,   377,   331,   332,   204,   204,
     727,     0,   100,   100,   204,     0,     0,   379,   498,   235,
     402,    82,   236,   237,   499,   500,   501,   379,   302,    82,
     562,   534,     0,   207,   314,   315,   562,   207,     0,     0,
     970,     0,   562,   562,     0,     0,     0,   379,    82,    82,
     238,   502,   239,     0,   503,     0,     0,   787,    82,   493,
     494,   495,   496,   100,     0,    82,   504,   100,   207,     0,
       0,   100,   100,     0,     0,     0,   100,    82,    82,     0,
       0,   100,   100,   316,   317,    82,     0,     0,     0,   100,
       0,     0,     0,   611,   613,     0,     0,     0,   498,    82,
      82,     0,   807,     0,   493,   494,   495,   496,     0,     0,
     393,     0,     0,   492,     0,   493,   494,   495,   496,   898,
       0,     0,   497,     0,   904,   611,   613,     0,     0,   320,
     314,   315,     0,   497,   100,   100,   100,   100,   100,   100,
     100,   100,     0,   498,   100,     0,   100,     0,   562,   100,
     500,   501,   235,     0,   498,   236,   237,     0,    82,    82,
     499,   500,   501,     0,     0,     0,   925,     0,     0,     0,
      82,     0,   675,     0,     0,     0,   502,     0,   100,   316,
     317,  -243,  -243,     0,     0,  -243,     0,   502,   100,   100,
     503,     0,   440,   441,   442,   331,   322,   314,   315,     0,
     956,   350,   100,     0,   100,   100,   254,     0,     0,   350,
     254,   204,   204,     0,   100,     0,   363,   364,   100,     0,
       0,     0,   100,     0,   363,   364,     0,   100,    82,   246,
       0,     0,   100,     0,    82,     0,    82,     0,   787,    82,
     493,   494,   495,   496,     0,     0,   316,   317,   335,   336,
     337,   338,   339,   368,   369,   370,   371,   372,   373,   374,
     375,     0,     0,   100,   371,   372,   373,   374,   375,     0,
     458,   461,   100,   324,   314,   315,   207,     0,     0,   498,
     246,     0,     0,     0,     0,   788,     0,   548,     0,     0,
     100,     0,   559,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   582,   583,   584,   585,   586,   587,   588,   589,     0,
       0,   254,     0,   316,   317,     0,   100,   524,   314,   315,
       0,   610,   610,     0,   204,   204,   204,   204,     0,   543,
     544,     0,     0,     0,     0,   254,     0,   492,     0,   493,
     494,   495,   496,     0,     0,   531,   314,   315,     0,   610,
       0,   254,     0,   610,   610,     0,     0,   497,     0,     0,
     254,     0,   532,   314,   315,     0,     0,   316,   317,   654,
       0,     0,   657,     0,     0,     0,   658,     0,   498,   661,
       0,   664,   295,     0,   499,   500,   501,    99,     0,    99,
     120,   120,     0,     0,   626,   316,   317,     0,   220,     0,
     610,     0,     0,     0,   906,   908,     0,   100,   100,   246,
     661,   502,   316,   317,   503,   246,   533,   314,   315,     0,
     708,   314,   315,   254,     0,   837,   839,     0,     0,     0,
       0,   844,   846,     0,    99,     0,     0,     0,   304,   692,
     100,     0,     0,     0,   246,     0,     0,     0,     0,     0,
     701,   246,   787,     0,   493,   494,   495,   496,     0,     0,
     837,   839,   304,   844,   846,     0,   316,   317,   711,   712,
     316,   317,     0,     0,     0,     0,     0,     0,     0,   718,
       0,     0,     0,     0,     0,     0,   958,     0,   246,     0,
     790,     0,     0,   498,     0,     0,   479,   479,    99,   939,
       0,   479,     0,   804,     0,   100,   808,     0,     0,     0,
       0,     0,     0,   100,   100,   817,     0,   100,     0,     0,
     100,   100,     0,     0,     0,     0,   100,   100,     0,     0,
       0,     0,   100,   100,     0,     0,     0,   915,   246,     0,
       0,     0,   100,   990,   992,   994,     0,   996,   997,   100,
       0,     0,   100,     0,     0,     0,     0,     0,     0,     0,
       0,   100,   100,   755,   915,     0,     0,     0,     0,   100,
     492,     0,   493,   494,   495,   496,     0,     0,     0,     0,
       0,     0,     0,   100,   100,     0,     0,    99,     0,     0,
     497,     0,     0,   780,     0,     0,  1019,  1021,  1022,  1023,
       0,   661,   295,     0,     0,     0,   204,     0,  1025,     0,
       0,   498,     0,     0,     0,     0,     0,   499,   500,   501,
       0,     0,     0,     0,     0,     0,     0,   246,   246,     0,
       0,     0,   100,     0,     0,     0,     0,     0,     0,   204,
       0,     0,   100,   100,   502,     0,     0,   503,     0,     0,
       0,     0,   825,     0,   100,     0,     0,   610,   828,   751,
     254,    99,     0,   610,   610,     0,    99,    99,     0,   610,
     610,     0,     0,     0,    99,    96,   246,    96,   119,   119,
     119,     0,     0,     0,     0,   304,   219,   946,     0,   948,
       0,     0,     0,   949,     0,     0,     0,     0,   610,   610,
       0,   610,   610,     0,     0,     0,   961,     0,   964,     0,
       0,   874,   100,     0,     0,     0,     0,     0,   100,    99,
     100,     0,    96,   100,    99,     0,   303,     0,     0,     0,
       0,    99,   304,     0,   563,     0,     0,     0,   975,   976,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     303,   204,     0,     0,     0,     0,     0,   910,     0,     0,
     100,     0,     0,     0,     0,     0,     0,   912,   913,     0,
       0,     0,     0,   563,   563,   610,     0,     0,  1008,     0,
       0,     0,    79,  1011,    79,     0,    96,     0,     0,    99,
    1012,     0,  1014,   216,     0,     0,  1015,     0,  -587,    99,
       0,     0,   610,     0,     0,     0,    97,    99,    97,   295,
    1017,  -587,  -587,  -587,  -587,  -587,  -587,    99,  -587,     0,
     246,  1024,     0,     0,  -587,  -587,     0,     0,     0,    79,
       0,     0,     0,     0,     0,  -587,  -587,     0,  -587,  -587,
    -587,  -587,  -587,     0,     0,     0,     0,     0,    99,     0,
       0,     0,     0,    97,     0,     0,     0,    99,     0,   246,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   304,     0,   304,     0,    96,     0,     0,     0,     0,
       0,     0,     0,   479,     0,     0,  -587,     0,     0,     0,
       0,     0,     0,    79,     0,     0,     0,     0,     0,     0,
    -587,     0,     0,   254,     0,     0,     0,     0,     0,     0,
    -587,    99,     0,  -587,  -587,     0,     0,    97,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  -587,  -587,     0,     0,   304,   263,  -587,
       0,  -587,  -587,  -587,     0,     0,     0,     0,     0,    96,
     246,     0,     0,     0,    96,    96,   725,   246,     0,     0,
       0,     0,    96,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   303,     0,     0,     0,     0,   246,     0,
       0,     0,    79,   350,   351,   352,   353,   354,   355,   356,
     357,   358,   359,   360,   361,   362,     0,     0,   363,   364,
       0,     0,     0,    99,     0,     0,    97,    96,     0,     0,
       0,     0,    96,     0,     0,     0,     0,     0,     0,    96,
     303,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   365,     0,   366,   367,   368,   369,   370,   371,   372,
     373,   374,   375,     0,     0,     0,     0,     0,     0,     0,
    -258,     0,     0,     0,     0,     0,    79,     0,     0,     0,
       0,    79,    79,     0,     0,   246,     0,     0,     0,    79,
       0,   246,     0,     0,     0,     0,     0,    96,     0,     0,
      97,     0,     0,     0,     0,    97,    97,    96,     0,     0,
       0,     0,     0,    97,     0,    96,     0,     0,     0,     0,
      99,     0,     0,     0,     0,    96,     0,   304,    99,   563,
       0,     0,     0,     0,    79,   563,     0,     0,     0,    79,
       0,   563,   563,     0,     0,     0,    79,    99,    99,   558,
       0,     0,     0,     0,     0,     0,    96,    99,    97,     0,
       0,     0,     0,    97,    99,    96,     0,     0,     0,     0,
      97,     0,     0,    97,     0,     0,    99,    99,     0,   303,
       0,   303,     0,     0,    99,     0,     0,     0,   558,   558,
       0,     0,     0,     0,     0,     0,     0,     0,    99,    99,
       0,     0,     0,     0,    79,     0,     0,     0,     0,     0,
       0,     0,    97,    97,    79,     0,     0,     0,   120,    96,
       0,     0,    79,   120,     0,     0,     0,     0,    97,     0,
       0,     0,    79,     0,     0,     0,     0,     0,    97,     0,
       0,     0,     0,     0,     0,   303,    97,   563,     0,     0,
       0,     0,     0,     0,     0,     0,    97,    99,    99,     0,
       0,     0,     0,    79,     0,   927,     0,     0,     0,    99,
       0,     0,    79,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   590,   591,     0,    97,   592,     0,
       0,     0,     0,     0,     0,     0,    97,     0,     0,     0,
       0,     0,   166,   167,   168,   169,   170,   171,   172,   173,
     174,    96,     0,   175,   176,     0,     0,   177,   178,   179,
     180,     0,     0,     0,     0,     0,    79,    99,     0,     0,
       0,   181,   182,    99,     0,    99,     0,     0,    99,     0,
       0,     0,     0,     0,     0,     0,     0,   725,     0,     0,
      97,     0,     0,     0,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,     0,   193,   194,     0,     0,     0,
       0,     0,   195,   263,   350,   351,   352,   353,   354,   355,
     356,   357,   358,   359,   360,   361,   362,     0,     0,   363,
     364,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    96,     0,
       0,     0,     0,     0,     0,   303,    96,     0,    79,     0,
       0,     0,   365,     0,   366,   367,   368,   369,   370,   371,
     372,   373,   374,   375,     0,    96,    96,     0,     0,     0,
       0,     0,    97,     0,     0,    96,     0,     0,     0,     0,
       0,     0,    96,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    96,    96,     0,     0,     0,     0,
       0,     0,    96,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    96,    96,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   119,     0,     0,     0,
       0,   119,     0,     0,     0,    79,     0,     0,     0,     0,
       0,     0,     0,    79,   558,     0,     0,     0,     0,     0,
     558,     0,     0,     0,     0,     0,   558,   558,     0,    97,
       0,     0,    79,    79,     0,    96,    96,    97,    97,     0,
       0,     0,    79,   926,    97,     0,     0,    96,     0,    79,
      97,    97,     0,     0,     0,     0,    97,    97,     0,     0,
       0,    79,    79,     0,     0,     0,    97,     0,     0,    79,
       0,     0,     0,    97,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    79,    79,    97,    97,     0,     0,     0,
       0,     0,     0,    97,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    96,     0,    97,    97,     0,
       0,    96,     0,    96,     0,     0,    96,     0,   350,   351,
     352,   353,   354,   355,   356,   357,   358,   359,   360,  -588,
    -588,     0,   558,   363,   364,     0,     0,     0,     0,     0,
       0,     0,    79,    79,     0,     0,     0,     0,     0,     0,
     924,     0,     0,     0,    79,     0,    97,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    97,    97,   366,   367,
     368,   369,   370,   371,   372,   373,   374,   375,    97,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    79,     0,     0,     0,     0,     0,    79,     0,
      79,     0,     0,    79,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    97,     0,     0,     0,
       0,     0,    97,     0,    97,  -587,     4,    97,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,     0,     0,
       0,     0,     0,     0,    15,     0,    16,    17,    18,    19,
       0,     0,     0,     0,     0,    20,    21,    22,    23,    24,
      25,    26,     0,     0,    27,     0,     0,     0,     0,     0,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,     0,    40,    41,    42,     0,     0,    43,     0,
       0,    44,    45,     0,    46,    47,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    48,     0,     0,    49,    50,     0,
      51,    52,     0,    53,     0,     0,    54,     0,    55,    56,
      57,    58,    59,    60,  -463,     0,    61,  -587,     0,     0,
    -587,  -587,     0,     0,     0,     0,     0,  -463,  -463,  -463,
    -463,  -463,  -463,     0,  -463,     0,    62,    63,    64,     0,
       0,  -463,  -463,     0,     0,     0,     0,     0,  -587,     0,
    -587,  -463,  -463,     0,  -463,  -463,  -463,  -463,  -463,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   439,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  -463,  -463,  -463,  -463,  -463,
    -463,  -463,  -463,  -463,  -463,  -463,  -463,  -463,     0,     0,
    -463,  -463,  -463,     0,  -463,  -463,     0,     0,     0,     0,
       0,  -463,     0,     0,     0,     0,  -463,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  -463,     0,     0,  -463,
    -463,     0,  -463,  -463,     0,  -463,  -463,  -463,  -463,  -463,
    -463,  -463,  -463,  -463,  -463,     0,     0,  -587,     0,     0,
    -463,  -463,  -463,     0,     0,  -463,  -463,  -463,  -463,  -463,
    -587,  -587,  -587,  -587,  -587,  -587,     0,  -587,     0,     0,
       0,     0,     0,     0,  -587,  -587,     0,     0,     0,     0,
       0,     0,     0,     0,  -587,  -587,     0,  -587,  -587,  -587,
    -587,  -587,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  -587,  -587,
    -587,  -587,  -587,  -587,  -587,  -587,  -587,  -587,  -587,  -587,
    -587,     0,     0,  -587,  -587,  -587,     0,     0,  -587,     0,
       0,     0,     0,     0,  -587,     0,     0,     0,     0,  -587,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  -587,
       0,     0,  -587,  -587,     0,     0,  -587,     0,  -587,  -587,
    -587,  -587,  -587,  -587,  -587,  -587,  -587,  -587,     0,     0,
    -563,     0,     0,  -587,  -587,  -587,     0,   263,  -587,  -587,
    -587,  -587,  -587,  -563,  -563,  -563,     0,  -563,  -563,     0,
    -563,     0,     0,     0,     0,     0,  -563,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  -563,  -563,     0,
    -563,  -563,  -563,  -563,  -563,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  -563,  -563,  -563,  -563,  -563,  -563,  -563,  -563,  -563,
    -563,  -563,  -563,  -563,     0,     0,  -563,  -563,  -563,     0,
     730,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -563,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -563,     0,     0,  -563,  -563,     0,   -99,  -563,
       0,  -563,  -563,  -563,  -563,  -563,  -563,  -563,  -563,  -563,
    -563,     0,     0,  -563,     0,  -563,  -563,  -563,   -91,     0,
       0,  -563,     0,  -563,  -563,  -563,  -563,  -563,  -563,     0,
    -563,  -563,     0,  -563,     0,     0,     0,     0,     0,  -563,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    -563,  -563,     0,  -563,  -563,  -563,  -563,  -563,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  -563,  -563,  -563,  -563,  -563,  -563,
    -563,  -563,  -563,  -563,  -563,  -563,  -563,     0,     0,  -563,
    -563,  -563,     0,   730,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  -563,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  -563,     0,     0,  -563,  -563,
       0,   -99,  -563,     0,  -563,  -563,  -563,  -563,  -563,  -563,
    -563,  -563,  -563,  -563,     0,     0,  -281,     0,  -563,  -563,
    -563,  -563,     0,     0,  -563,     0,  -563,  -563,  -563,  -281,
    -281,  -281,     0,  -281,  -281,     0,  -281,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  -281,  -281,     0,  -281,  -281,  -281,  -281,
    -281,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  -281,  -281,  -281,
    -281,  -281,  -281,  -281,  -281,  -281,  -281,  -281,  -281,  -281,
       0,     0,  -281,  -281,  -281,     0,   731,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  -281,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  -281,     0,
       0,  -281,  -281,     0,  -101,  -281,     0,  -281,  -281,  -281,
    -281,  -281,  -281,  -281,  -281,  -281,  -281,     0,     0,  -281,
       0,     0,  -281,  -281,   -93,     0,     0,  -281,     0,  -281,
    -281,  -281,  -281,  -281,  -281,     0,  -281,  -281,     0,  -281,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  -281,  -281,     0,  -281,
    -281,  -281,  -281,  -281,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    -281,  -281,  -281,  -281,  -281,  -281,  -281,  -281,  -281,  -281,
    -281,  -281,  -281,     0,     0,  -281,  -281,  -281,     0,   731,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  -281,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  -281,     0,     0,  -281,  -281,     0,  -101,  -281,     0,
    -281,  -281,  -281,  -281,  -281,  -281,  -281,  -281,  -281,  -281,
       0,     0,     0,     0,     0,  -281,  -281,  -281,     0,     0,
    -281,     0,  -281,  -281,  -281,   281,     0,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,  -587,  -587,  -587,
       0,     0,  -587,    15,     0,    16,    17,    18,    19,     0,
       0,     0,     0,     0,    20,    21,    22,    23,    24,    25,
      26,     0,     0,    27,     0,     0,     0,     0,     0,    28,
       0,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,     0,    40,    41,    42,     0,     0,    43,     0,     0,
      44,    45,     0,    46,    47,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    48,     0,     0,    49,    50,     0,    51,
      52,     0,    53,     0,     0,    54,     0,    55,    56,    57,
      58,    59,    60,     0,     0,    61,  -587,     0,     0,  -587,
    -587,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    62,    63,    64,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  -587,   281,  -587,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
       0,     0,  -587,     0,  -587,  -587,    15,     0,    16,    17,
      18,    19,     0,     0,     0,     0,     0,    20,    21,    22,
      23,    24,    25,    26,     0,     0,    27,     0,     0,     0,
       0,     0,    28,     0,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,     0,    40,    41,    42,     0,     0,
      43,     0,     0,    44,    45,     0,    46,    47,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    48,     0,     0,    49,
      50,     0,    51,    52,     0,    53,     0,     0,    54,     0,
      55,    56,    57,    58,    59,    60,     0,     0,    61,  -587,
       0,     0,  -587,  -587,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    62,    63,
      64,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    -587,   281,  -587,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,     0,     0,  -587,     0,     0,  -587,    15,
    -587,    16,    17,    18,    19,     0,     0,     0,     0,     0,
      20,    21,    22,    23,    24,    25,    26,     0,     0,    27,
       0,     0,     0,     0,     0,    28,     0,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,     0,    40,    41,
      42,     0,     0,    43,     0,     0,    44,    45,     0,    46,
      47,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    48,
       0,     0,    49,    50,     0,    51,    52,     0,    53,     0,
       0,    54,     0,    55,    56,    57,    58,    59,    60,     0,
       0,    61,  -587,     0,     0,  -587,  -587,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    62,    63,    64,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  -587,   281,  -587,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,     0,     0,  -587,     0,
       0,  -587,    15,     0,    16,    17,    18,    19,     0,     0,
       0,     0,     0,    20,    21,    22,    23,    24,    25,    26,
       0,     0,    27,     0,     0,     0,     0,     0,    28,     0,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
       0,    40,    41,    42,     0,     0,    43,     0,     0,    44,
      45,     0,    46,    47,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    48,     0,     0,    49,    50,     0,    51,    52,
       0,    53,     0,     0,    54,     0,    55,    56,    57,    58,
      59,    60,     0,     0,    61,  -587,     0,     0,  -587,  -587,
       4,     0,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,     0,     0,    62,    63,    64,     0,    15,     0,
      16,    17,    18,    19,     0,     0,  -587,     0,  -587,    20,
      21,    22,    23,    24,    25,    26,     0,     0,    27,     0,
       0,     0,     0,     0,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,     0,    40,    41,    42,
       0,     0,    43,     0,     0,    44,    45,     0,    46,    47,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    48,     0,
       0,    49,    50,     0,    51,    52,     0,    53,     0,     0,
      54,     0,    55,    56,    57,    58,    59,    60,     0,     0,
      61,  -587,     0,     0,  -587,  -587,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      62,    63,    64,     0,     0,  -587,     0,     0,     0,     0,
       0,     0,  -587,   281,  -587,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,     0,  -587,  -587,     0,     0,
       0,    15,     0,    16,    17,    18,    19,     0,     0,     0,
       0,     0,    20,    21,    22,    23,    24,    25,    26,     0,
       0,    27,     0,     0,     0,     0,     0,    28,     0,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,     0,
      40,    41,    42,     0,     0,    43,     0,     0,    44,    45,
       0,    46,    47,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    48,     0,     0,    49,    50,     0,    51,    52,     0,
      53,     0,     0,    54,     0,    55,    56,    57,    58,    59,
      60,     0,     0,    61,  -587,     0,     0,  -587,  -587,   281,
       0,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,     0,     0,    62,    63,    64,     0,    15,     0,    16,
      17,    18,    19,     0,     0,  -587,     0,  -587,    20,    21,
      22,    23,    24,    25,    26,     0,     0,    27,     0,     0,
       0,     0,     0,    28,     0,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,     0,    40,    41,    42,     0,
       0,    43,     0,     0,    44,    45,     0,    46,    47,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    48,     0,     0,
     282,    50,     0,    51,    52,     0,    53,     0,     0,    54,
       0,    55,    56,    57,    58,    59,    60,     0,     0,    61,
    -587,     0,     0,  -587,  -587,   281,     0,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,     0,     0,    62,
      63,    64,     0,    15,     0,    16,    17,    18,    19,  -587,
       0,  -587,     0,  -587,    20,    21,    22,    23,    24,    25,
      26,     0,     0,    27,     0,     0,     0,     0,     0,    28,
       0,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,     0,    40,    41,    42,     0,     0,    43,     0,     0,
      44,    45,     0,    46,    47,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    48,     0,     0,    49,    50,     0,    51,
      52,     0,    53,     0,     0,    54,     0,    55,    56,    57,
      58,    59,    60,     0,     0,    61,  -587,     0,     0,  -587,
    -587,   281,     0,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,     0,     0,    62,    63,    64,     0,    15,
       0,    16,    17,    18,    19,  -587,     0,  -587,     0,  -587,
      20,    21,    22,    23,    24,    25,    26,     0,     0,    27,
       0,     0,     0,     0,     0,    28,     0,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,     0,    40,    41,
      42,     0,     0,    43,     0,     0,    44,    45,     0,    46,
      47,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    48,
       0,     0,    49,    50,     0,    51,    52,     0,    53,     0,
       0,    54,     0,    55,    56,    57,    58,    59,    60,     0,
       0,    61,  -587,     0,     0,  -587,  -587,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    62,    63,    64,     0,     0,  -587,     0,     0,     0,
       0,     0,     0,  -587,   281,  -587,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,     0,     0,  -587,     0,
       0,     0,    15,     0,    16,    17,    18,    19,     0,     0,
       0,     0,     0,    20,    21,    22,    23,    24,    25,    26,
       0,     0,    27,     0,     0,     0,     0,     0,    28,     0,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
       0,    40,    41,    42,     0,     0,    43,     0,     0,    44,
      45,     0,    46,    47,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    48,     0,     0,    49,    50,     0,    51,    52,
       0,    53,     0,     0,    54,     0,    55,    56,    57,    58,
      59,    60,     0,     0,    61,  -587,     0,     0,  -587,  -587,
       0,     0,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,     0,     0,    62,    63,    64,     0,    15,     0,
      16,    17,    18,    19,     0,     0,  -587,     0,  -587,    20,
      21,    22,    23,    24,    25,    26,     0,     0,    27,     0,
       0,     0,     0,     0,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,     0,    40,    41,    42,
       0,     0,    43,     0,     0,    44,    45,     0,    46,    47,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    48,     0,
       0,    49,    50,     0,    51,    52,     0,    53,     0,     0,
      54,     0,    55,    56,    57,    58,    59,    60,     0,     0,
      61,   235,     0,     0,   236,   237,     0,     0,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,     0,     0,
      62,    63,    64,     0,    15,     0,    16,    17,    18,    19,
       0,     0,   238,     0,   239,    20,    21,    22,    23,    24,
      25,    26,     0,     0,    27,     0,     0,     0,     0,     0,
      28,     0,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,     0,    40,    41,    42,     0,     0,    43,     0,
       0,    44,    45,     0,    46,    47,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    48,     0,     0,    49,    50,     0,
      51,    52,     0,    53,     0,     0,    54,     0,    55,    56,
      57,    58,    59,    60,     0,     0,    61,   235,     0,     0,
     236,   237,     0,     0,     5,     6,     7,     8,     9,    10,
      11,    12,    13,     0,     0,     0,    62,    63,    64,     0,
      15,     0,    16,    17,    18,    19,     0,     0,   238,     0,
     239,    20,    21,    22,    23,    24,    25,    26,     0,     0,
      27,     0,     0,     0,     0,     0,     0,     0,     0,    31,
      32,    33,    34,    35,    36,    37,    38,    39,     0,    40,
      41,    42,     0,     0,    43,     0,     0,    44,    45,     0,
      46,    47,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     203,     0,     0,   113,    50,     0,    51,    52,     0,     0,
       0,     0,    54,     0,    55,    56,    57,    58,    59,    60,
       0,     0,    61,   235,     0,     0,   236,   237,     0,     0,
       5,     6,     7,     8,     9,    10,    11,    12,    13,     0,
       0,     0,    62,    63,    64,     0,    15,     0,    16,    17,
      18,    19,     0,     0,   238,     0,   239,    20,    21,    22,
      23,    24,    25,    26,     0,     0,    27,     0,     0,     0,
       0,     0,     0,     0,     0,    31,    32,    33,    34,    35,
      36,    37,    38,    39,     0,    40,    41,    42,     0,     0,
      43,     0,     0,    44,    45,     0,    46,    47,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   203,     0,     0,   113,
      50,     0,    51,    52,     0,     0,     0,     0,    54,     0,
      55,    56,    57,    58,    59,    60,     0,     0,    61,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    62,    63,
      64,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   239,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,     0,     0,     0,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
       0,     0,     0,     0,     0,   157,   158,   159,   160,   161,
     162,   163,   164,    36,    37,   165,    39,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   166,
     167,   168,   169,   170,   171,   172,   173,   174,     0,     0,
     175,   176,     0,     0,   177,   178,   179,   180,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   181,   182,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,     0,   193,   194,     0,     0,     0,     0,     0,   195,
     196,  -556,  -556,  -556,  -556,  -556,  -556,  -556,  -556,  -556,
       0,     0,     0,     0,     0,     0,     0,  -556,     0,  -556,
    -556,  -556,  -556,     0,  -556,     0,     0,     0,  -556,  -556,
    -556,  -556,  -556,  -556,  -556,     0,     0,  -556,     0,     0,
       0,     0,     0,     0,     0,     0,  -556,  -556,  -556,  -556,
    -556,  -556,  -556,  -556,  -556,     0,  -556,  -556,  -556,     0,
       0,  -556,     0,     0,  -556,  -556,     0,  -556,  -556,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  -556,     0,     0,
    -556,  -556,     0,  -556,  -556,     0,  -556,  -556,  -556,  -556,
       0,  -556,  -556,  -556,  -556,  -556,  -556,     0,     0,  -556,
       0,     0,     0,     0,     0,     0,  -558,  -558,  -558,  -558,
    -558,  -558,  -558,  -558,  -558,     0,     0,     0,     0,  -556,
    -556,  -556,  -558,  -556,  -558,  -558,  -558,  -558,  -556,  -558,
       0,     0,     0,  -558,  -558,  -558,  -558,  -558,  -558,  -558,
       0,     0,  -558,     0,     0,     0,     0,     0,     0,     0,
       0,  -558,  -558,  -558,  -558,  -558,  -558,  -558,  -558,  -558,
       0,  -558,  -558,  -558,     0,     0,  -558,     0,     0,  -558,
    -558,     0,  -558,  -558,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -558,     0,     0,  -558,  -558,     0,  -558,  -558,
       0,  -558,  -558,  -558,  -558,     0,  -558,  -558,  -558,  -558,
    -558,  -558,     0,     0,  -558,     0,     0,     0,     0,     0,
       0,  -557,  -557,  -557,  -557,  -557,  -557,  -557,  -557,  -557,
       0,     0,     0,     0,  -558,  -558,  -558,  -557,  -558,  -557,
    -557,  -557,  -557,  -558,  -557,     0,     0,     0,  -557,  -557,
    -557,  -557,  -557,  -557,  -557,     0,     0,  -557,     0,     0,
       0,     0,     0,     0,     0,     0,  -557,  -557,  -557,  -557,
    -557,  -557,  -557,  -557,  -557,     0,  -557,  -557,  -557,     0,
       0,  -557,     0,     0,  -557,  -557,     0,  -557,  -557,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  -557,     0,     0,
    -557,  -557,     0,  -557,  -557,     0,  -557,  -557,  -557,  -557,
       0,  -557,  -557,  -557,  -557,  -557,  -557,     0,     0,  -557,
       0,     0,     0,     0,     0,     0,  -559,  -559,  -559,  -559,
    -559,  -559,  -559,  -559,  -559,     0,     0,     0,     0,  -557,
    -557,  -557,  -559,  -557,  -559,  -559,  -559,  -559,  -557,     0,
       0,     0,     0,  -559,  -559,  -559,  -559,  -559,  -559,  -559,
       0,     0,  -559,     0,     0,     0,     0,     0,     0,     0,
       0,  -559,  -559,  -559,  -559,  -559,  -559,  -559,  -559,  -559,
       0,  -559,  -559,  -559,     0,     0,  -559,     0,     0,  -559,
    -559,     0,  -559,  -559,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -559,   765,     0,  -559,  -559,     0,  -559,  -559,
       0,  -559,  -559,  -559,  -559,     0,  -559,  -559,  -559,  -559,
    -559,  -559,     0,     0,  -559,     0,     0,     0,     0,     0,
       0,   -99,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  -559,  -559,  -559,     0,     0,     0,
       0,     0,     0,  -559,  -560,  -560,  -560,  -560,  -560,  -560,
    -560,  -560,  -560,     0,     0,     0,     0,     0,     0,     0,
    -560,     0,  -560,  -560,  -560,  -560,     0,     0,     0,     0,
       0,  -560,  -560,  -560,  -560,  -560,  -560,  -560,     0,     0,
    -560,     0,     0,     0,     0,     0,     0,     0,     0,  -560,
    -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,     0,  -560,
    -560,  -560,     0,     0,  -560,     0,     0,  -560,  -560,     0,
    -560,  -560,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    -560,   766,     0,  -560,  -560,     0,  -560,  -560,     0,  -560,
    -560,  -560,  -560,     0,  -560,  -560,  -560,  -560,  -560,  -560,
       0,     0,  -560,     0,     0,     0,     0,     0,     0,  -101,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -560,  -560,  -560,     0,     0,     0,     0,     0,
       0,  -560,  -251,  -251,  -251,  -251,  -251,  -251,  -251,  -251,
    -251,     0,     0,     0,     0,     0,     0,     0,  -251,     0,
    -251,  -251,  -251,  -251,     0,     0,     0,     0,     0,  -251,
    -251,  -251,  -251,  -251,  -251,  -251,     0,     0,  -251,     0,
       0,     0,     0,     0,     0,     0,     0,  -251,  -251,  -251,
    -251,  -251,  -251,  -251,  -251,  -251,     0,  -251,  -251,  -251,
       0,     0,  -251,     0,     0,  -251,  -251,     0,  -251,  -251,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  -251,     0,
       0,  -251,  -251,     0,  -251,  -251,     0,  -251,  -251,  -251,
    -251,     0,  -251,  -251,  -251,  -251,  -251,  -251,     0,     0,
    -251,     0,     0,     0,     0,     0,     0,  -561,  -561,  -561,
    -561,  -561,  -561,  -561,  -561,  -561,     0,     0,     0,     0,
    -251,  -251,  -251,  -561,     0,  -561,  -561,  -561,  -561,   263,
       0,     0,     0,     0,  -561,  -561,  -561,  -561,  -561,  -561,
    -561,     0,     0,  -561,     0,     0,     0,     0,     0,     0,
       0,     0,  -561,  -561,  -561,  -561,  -561,  -561,  -561,  -561,
    -561,     0,  -561,  -561,  -561,     0,     0,  -561,     0,     0,
    -561,  -561,     0,  -561,  -561,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  -561,     0,     0,  -561,  -561,     0,  -561,
    -561,     0,  -561,  -561,  -561,  -561,     0,  -561,  -561,  -561,
    -561,  -561,  -561,     0,     0,  -561,     0,     0,     0,     0,
       0,     0,  -562,  -562,  -562,  -562,  -562,  -562,  -562,  -562,
    -562,     0,     0,     0,     0,  -561,  -561,  -561,  -562,     0,
    -562,  -562,  -562,  -562,  -561,     0,     0,     0,     0,  -562,
    -562,  -562,  -562,  -562,  -562,  -562,     0,     0,  -562,     0,
       0,     0,     0,     0,     0,     0,     0,  -562,  -562,  -562,
    -562,  -562,  -562,  -562,  -562,  -562,     0,  -562,  -562,  -562,
       0,     0,  -562,     0,     0,  -562,  -562,     0,  -562,  -562,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  -562,     0,
       0,  -562,  -562,     0,  -562,  -562,     0,  -562,  -562,  -562,
    -562,     0,  -562,  -562,  -562,  -562,  -562,  -562,     0,     0,
    -562,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    -562,  -562,  -562,     0,     0,     0,     0,     0,     0,  -562,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,     0,     0,     0,   147,   148,   149,
     221,   222,   223,   224,   154,   155,   156,     0,     0,     0,
       0,     0,   157,   158,   159,   225,   226,   227,   228,   164,
     306,   307,   229,   308,     0,     0,     0,     0,     0,     0,
     309,     0,     0,     0,     0,     0,   166,   167,   168,   169,
     170,   171,   172,   173,   174,     0,     0,   175,   176,     0,
       0,   177,   178,   179,   180,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   181,   182,     0,     0,     0,
       0,     0,     0,     0,   310,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,     0,   193,
     194,     0,     0,     0,     0,     0,   195,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,     0,     0,     0,   147,   148,   149,   221,   222,   223,
     224,   154,   155,   156,     0,     0,     0,     0,     0,   157,
     158,   159,   225,   226,   227,   228,   164,   306,   307,   229,
     308,     0,     0,     0,     0,     0,     0,   309,     0,     0,
       0,     0,     0,   166,   167,   168,   169,   170,   171,   172,
     173,   174,     0,     0,   175,   176,     0,     0,   177,   178,
     179,   180,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   181,   182,     0,     0,     0,     0,     0,     0,
       0,   430,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,     0,   193,   194,     0,     0,
       0,     0,     0,   195,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,     0,     0,
       0,   147,   148,   149,   221,   222,   223,   224,   154,   155,
     156,     0,     0,     0,     0,     0,   157,   158,   159,   225,
     226,   227,   228,   164,     0,     0,   229,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     166,   167,   168,   169,   170,   171,   172,   173,   174,     0,
       0,   175,   176,     0,     0,   177,   178,   179,   180,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   181,
     182,     0,     0,     0,   230,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,     0,   193,   194,     0,     0,     0,     0,     0,
     195,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,     0,     0,     0,   147,   148,
     149,   221,   222,   223,   224,   154,   155,   156,     0,     0,
       0,     0,     0,   157,   158,   159,   225,   226,   227,   228,
     164,     0,     0,   229,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   166,   167,   168,
     169,   170,   171,   172,   173,   174,     0,     0,   175,   176,
       0,     0,   177,   178,   179,   180,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   181,   182,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,     0,
     193,   194,     0,     0,     0,     0,     0,   195,     5,     6,
       7,     8,     9,    10,    11,    12,    13,     0,     0,     0,
       0,     0,     0,     0,    15,     0,   103,   104,    18,    19,
       0,     0,     0,     0,     0,   105,   106,   107,    23,    24,
      25,    26,     0,     0,   108,     0,     0,     0,     0,     0,
       0,     0,     0,    31,    32,    33,    34,    35,    36,    37,
      38,    39,     0,    40,    41,    42,     0,     0,    43,     0,
       0,    44,    45,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   299,     0,     0,   113,    50,     0,
      51,    52,     0,     0,     0,     0,    54,     0,    55,    56,
      57,    58,    59,    60,     0,     0,    61,     0,     0,     5,
       6,     7,     8,     9,    10,    11,    12,    13,     0,     0,
       0,     0,     0,     0,     0,    15,   114,   103,   104,    18,
      19,     0,     0,   300,     0,     0,   105,   106,   107,    23,
      24,    25,    26,     0,     0,   108,     0,     0,     0,     0,
       0,     0,     0,     0,    31,    32,    33,    34,    35,    36,
      37,    38,    39,     0,    40,    41,    42,     0,     0,    43,
       0,     0,    44,    45,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   299,     0,     0,   113,    50,
       0,    51,    52,     0,     0,     0,     0,    54,     0,    55,
      56,    57,    58,    59,    60,     0,     0,    61,     0,     0,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
       0,     0,     0,     0,     0,     0,    15,   114,    16,    17,
      18,    19,     0,     0,   552,     0,     0,    20,    21,    22,
      23,    24,    25,    26,     0,     0,    27,     0,     0,     0,
       0,     0,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,     0,    40,    41,    42,     0,     0,
      43,     0,     0,    44,    45,     0,    46,    47,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    48,     0,     0,    49,
      50,     0,    51,    52,     0,    53,     0,     0,    54,     0,
      55,    56,    57,    58,    59,    60,     0,     0,    61,     0,
       0,     0,     0,     0,     0,     5,     6,     7,     8,     9,
      10,    11,    12,    13,     0,     0,     0,     0,    62,    63,
      64,    15,     0,   103,   104,    18,    19,     0,     0,     0,
       0,     0,   105,   106,   107,    23,    24,    25,    26,     0,
       0,   108,     0,     0,     0,     0,     0,     0,     0,     0,
      31,    32,    33,   248,    35,    36,    37,    38,    39,     0,
      40,    41,    42,     0,     0,    43,     0,     0,    44,    45,
       0,    46,    47,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   203,     0,     0,   113,    50,     0,    51,    52,     0,
       0,   250,  -256,    54,     0,    55,    56,    57,    58,    59,
      60,     0,     0,    61,   235,     0,     0,   236,   237,     0,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
       0,     0,     0,    62,   252,    64,    15,     0,    16,    17,
      18,    19,     0,     0,     0,     0,     0,    20,    21,    22,
      23,    24,    25,    26,     0,     0,    27,     0,     0,     0,
       0,     0,    28,     0,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,     0,    40,    41,    42,     0,     0,
      43,     0,     0,    44,    45,     0,    46,    47,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    48,     0,     0,    49,
      50,     0,    51,    52,     0,    53,     0,     0,    54,     0,
      55,    56,    57,    58,    59,    60,     0,     0,    61,     0,
       0,     0,     0,     0,     0,     5,     6,     7,     8,     9,
      10,    11,    12,    13,     0,     0,     0,     0,    62,    63,
      64,    15,     0,   103,   104,    18,    19,     0,     0,     0,
       0,     0,   105,   106,   107,    23,    24,    25,    26,     0,
       0,   108,     0,     0,     0,     0,     0,     0,     0,     0,
      31,    32,    33,   248,    35,    36,    37,    38,    39,     0,
      40,    41,    42,     0,     0,    43,     0,     0,    44,    45,
       0,    46,    47,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   203,     0,     0,   113,    50,     0,    51,    52,     0,
       0,   250,     0,    54,     0,    55,    56,    57,    58,    59,
      60,     0,     0,    61,   235,     0,     0,   236,   237,     0,
       5,     6,     7,     8,     9,    10,    11,    12,    13,     0,
       0,     0,     0,    62,   252,    64,    15,     0,    16,    17,
      18,    19,     0,     0,     0,     0,     0,    20,    21,    22,
      23,    24,    25,    26,     0,     0,   108,     0,     0,     0,
       0,     0,     0,     0,     0,    31,    32,    33,   248,    35,
      36,    37,    38,    39,     0,    40,    41,    42,     0,     0,
      43,     0,     0,    44,    45,     0,    46,    47,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   203,     0,     0,   113,
      50,     0,    51,    52,     0,   249,   250,   251,    54,     0,
      55,    56,    57,    58,    59,    60,     0,     0,    61,     0,
       0,     0,     0,     0,     0,     5,     6,     7,     8,     9,
      10,    11,    12,    13,     0,     0,     0,     0,    62,   252,
      64,    15,     0,   103,   104,    18,    19,     0,     0,     0,
       0,     0,   105,   106,   107,    23,    24,    25,    26,     0,
       0,   108,     0,     0,     0,     0,     0,     0,     0,     0,
      31,    32,    33,   248,    35,    36,    37,    38,    39,     0,
      40,    41,    42,     0,     0,    43,     0,     0,    44,    45,
       0,    46,    47,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   203,     0,     0,   113,    50,     0,    51,    52,     0,
     660,   250,   251,    54,     0,    55,    56,    57,    58,    59,
      60,     0,     0,    61,     0,     0,     0,     0,     0,     0,
       5,     6,     7,     8,     9,    10,    11,    12,    13,     0,
       0,     0,     0,    62,   252,    64,    15,     0,   103,   104,
      18,    19,     0,     0,     0,     0,     0,   105,   106,   107,
      23,    24,    25,    26,     0,     0,   108,     0,     0,     0,
       0,     0,     0,     0,     0,    31,    32,    33,   248,    35,
      36,    37,    38,    39,     0,    40,    41,    42,     0,     0,
      43,     0,     0,    44,    45,     0,    46,    47,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   203,     0,     0,   113,
      50,     0,    51,    52,     0,   249,   250,     0,    54,     0,
      55,    56,    57,    58,    59,    60,     0,     0,    61,     0,
       0,     0,     0,     0,     0,     5,     6,     7,     8,     9,
      10,    11,    12,    13,     0,     0,     0,     0,    62,   252,
      64,    15,     0,   103,   104,    18,    19,     0,     0,     0,
       0,     0,   105,   106,   107,    23,    24,    25,    26,     0,
       0,   108,     0,     0,     0,     0,     0,     0,     0,     0,
      31,    32,    33,   248,    35,    36,    37,    38,    39,     0,
      40,    41,    42,     0,     0,    43,     0,     0,    44,    45,
       0,    46,    47,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   203,     0,     0,   113,    50,     0,    51,    52,     0,
     660,   250,     0,    54,     0,    55,    56,    57,    58,    59,
      60,     0,     0,    61,     0,     0,     0,     0,     0,     0,
       5,     6,     7,     8,     9,    10,    11,    12,    13,     0,
       0,     0,     0,    62,   252,    64,    15,     0,   103,   104,
      18,    19,     0,     0,     0,     0,     0,   105,   106,   107,
      23,    24,    25,    26,     0,     0,   108,     0,     0,     0,
       0,     0,     0,     0,     0,    31,    32,    33,   248,    35,
      36,    37,    38,    39,     0,    40,    41,    42,     0,     0,
      43,     0,     0,    44,    45,     0,    46,    47,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   203,     0,     0,   113,
      50,     0,    51,    52,     0,     0,   250,     0,    54,     0,
      55,    56,    57,    58,    59,    60,     0,     0,    61,     0,
       0,     0,     0,     0,     0,     5,     6,     7,     8,     9,
      10,    11,    12,    13,     0,     0,     0,     0,    62,   252,
      64,    15,     0,    16,    17,    18,    19,     0,     0,     0,
       0,     0,    20,    21,    22,    23,    24,    25,    26,     0,
       0,   108,     0,     0,     0,     0,     0,     0,     0,     0,
      31,    32,    33,    34,    35,    36,    37,    38,    39,     0,
      40,    41,    42,     0,     0,    43,     0,     0,    44,    45,
       0,    46,    47,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   203,     0,     0,   113,    50,     0,    51,    52,     0,
     546,     0,     0,    54,     0,    55,    56,    57,    58,    59,
      60,     0,     0,    61,     0,     0,     0,     0,     0,     0,
       5,     6,     7,     8,     9,    10,    11,    12,    13,     0,
       0,     0,     0,    62,   252,    64,    15,     0,   103,   104,
      18,    19,     0,     0,     0,     0,     0,   105,   106,   107,
      23,    24,    25,    26,     0,     0,   108,     0,     0,     0,
       0,     0,     0,     0,     0,    31,    32,    33,    34,    35,
      36,    37,    38,    39,     0,    40,    41,    42,     0,     0,
      43,     0,     0,    44,    45,     0,    46,    47,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   203,     0,     0,   113,
      50,     0,    51,    52,     0,   249,     0,     0,    54,     0,
      55,    56,    57,    58,    59,    60,     0,     0,    61,     0,
       0,     0,     0,     0,     0,     5,     6,     7,     8,     9,
      10,    11,    12,    13,     0,     0,     0,     0,    62,   252,
      64,    15,     0,   103,   104,    18,    19,     0,     0,     0,
       0,     0,   105,   106,   107,    23,    24,    25,    26,     0,
       0,   108,     0,     0,     0,     0,     0,     0,     0,     0,
      31,    32,    33,    34,    35,    36,    37,    38,    39,     0,
      40,    41,    42,     0,     0,    43,     0,     0,    44,    45,
       0,    46,    47,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   203,     0,     0,   113,    50,     0,    51,    52,     0,
     546,     0,     0,    54,     0,    55,    56,    57,    58,    59,
      60,     0,     0,    61,     0,     0,     0,     0,     0,     0,
       5,     6,     7,     8,     9,    10,    11,    12,    13,     0,
       0,     0,     0,    62,   252,    64,    15,     0,   103,   104,
      18,    19,     0,     0,     0,     0,     0,   105,   106,   107,
      23,    24,    25,    26,     0,     0,   108,     0,     0,     0,
       0,     0,     0,     0,     0,    31,    32,    33,    34,    35,
      36,    37,    38,    39,     0,    40,    41,    42,     0,     0,
      43,     0,     0,    44,    45,     0,    46,    47,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   203,     0,     0,   113,
      50,     0,    51,    52,     0,   824,     0,     0,    54,     0,
      55,    56,    57,    58,    59,    60,     0,     0,    61,     0,
       0,     0,     0,     0,     0,     5,     6,     7,     8,     9,
      10,    11,    12,    13,     0,     0,     0,     0,    62,   252,
      64,    15,     0,   103,   104,    18,    19,     0,     0,     0,
       0,     0,   105,   106,   107,    23,    24,    25,    26,     0,
       0,   108,     0,     0,     0,     0,     0,     0,     0,     0,
      31,    32,    33,    34,    35,    36,    37,    38,    39,     0,
      40,    41,    42,     0,     0,    43,     0,     0,    44,    45,
       0,    46,    47,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   203,     0,     0,   113,    50,     0,    51,    52,     0,
     660,     0,     0,    54,     0,    55,    56,    57,    58,    59,
      60,     0,     0,    61,     0,     0,     0,     0,     0,     0,
       5,     6,     7,     8,     9,    10,    11,    12,    13,     0,
       0,     0,     0,    62,   252,    64,    15,     0,    16,    17,
      18,    19,     0,     0,     0,     0,     0,    20,    21,    22,
      23,    24,    25,    26,     0,     0,    27,     0,     0,     0,
       0,     0,     0,     0,     0,    31,    32,    33,    34,    35,
      36,    37,    38,    39,     0,    40,    41,    42,     0,     0,
      43,     0,     0,    44,    45,     0,    46,    47,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   203,     0,     0,   113,
      50,     0,    51,    52,     0,     0,     0,     0,    54,     0,
      55,    56,    57,    58,    59,    60,     0,     0,    61,     0,
       0,     0,     0,     0,     0,     5,     6,     7,     8,     9,
      10,    11,    12,    13,     0,     0,     0,     0,    62,    63,
      64,    15,     0,   103,   104,    18,    19,     0,     0,     0,
       0,     0,   105,   106,   107,    23,    24,    25,    26,     0,
       0,   108,     0,     0,     0,     0,     0,     0,     0,     0,
      31,    32,    33,    34,    35,    36,    37,    38,    39,     0,
      40,    41,    42,     0,     0,    43,     0,     0,    44,    45,
       0,    46,    47,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   203,     0,     0,   113,    50,     0,    51,    52,     0,
       0,     0,     0,    54,     0,    55,    56,    57,    58,    59,
      60,     0,     0,    61,     0,     0,     0,     0,     0,     0,
       5,     6,     7,     8,     9,    10,    11,    12,    13,     0,
       0,     0,     0,    62,   252,    64,    15,     0,    16,    17,
      18,    19,     0,     0,     0,     0,     0,    20,    21,    22,
      23,    24,    25,    26,     0,     0,   108,     0,     0,     0,
       0,     0,     0,     0,     0,    31,    32,    33,    34,    35,
      36,    37,    38,    39,     0,    40,    41,    42,     0,     0,
      43,     0,     0,    44,    45,     0,    46,    47,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   203,     0,     0,   113,
      50,     0,    51,    52,     0,     0,     0,     0,    54,     0,
      55,    56,    57,    58,    59,    60,     0,     0,    61,     0,
       0,     0,     0,     0,     0,     5,     6,     7,     8,     9,
      10,    11,    12,    13,     0,     0,     0,     0,    62,   252,
      64,    15,     0,   103,   104,    18,    19,     0,     0,     0,
       0,     0,   105,   106,   107,    23,    24,    25,    26,     0,
       0,   108,     0,     0,     0,     0,     0,     0,     0,     0,
      31,    32,    33,   109,    35,    36,    37,   110,    39,     0,
      40,    41,    42,     0,     0,    43,     0,     0,    44,    45,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   111,     0,
       0,   112,     0,     0,   113,    50,     0,    51,    52,     0,
       0,     0,     0,    54,     0,    55,    56,    57,    58,    59,
      60,     0,     0,    61,     0,     0,     5,     6,     7,     8,
       9,    10,    11,    12,    13,     0,     0,     0,     0,     0,
       0,     0,    15,   114,   103,   104,    18,    19,     0,     0,
       0,     0,     0,   105,   106,   107,    23,    24,    25,    26,
       0,     0,   108,     0,     0,     0,     0,     0,     0,     0,
       0,    31,    32,    33,    34,    35,    36,    37,    38,    39,
       0,    40,    41,    42,     0,     0,    43,     0,     0,    44,
      45,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   214,     0,     0,    49,    50,     0,    51,    52,
       0,    53,     0,     0,    54,     0,    55,    56,    57,    58,
      59,    60,     0,     0,    61,     0,     0,     5,     6,     7,
       8,     9,    10,    11,    12,    13,     0,     0,     0,     0,
       0,     0,     0,    15,   114,   103,   104,    18,    19,     0,
       0,     0,     0,     0,   105,   106,   107,    23,    24,    25,
      26,     0,     0,   108,     0,     0,     0,     0,     0,     0,
       0,     0,    31,    32,    33,    34,    35,    36,    37,    38,
      39,     0,    40,    41,    42,     0,     0,    43,     0,     0,
      44,    45,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   299,     0,     0,   346,    50,     0,    51,
      52,     0,   347,     0,     0,    54,     0,    55,    56,    57,
      58,    59,    60,     0,     0,    61,     0,     0,     5,     6,
       7,     8,     9,    10,    11,    12,    13,     0,     0,     0,
       0,     0,     0,     0,    15,   114,   103,   104,    18,    19,
       0,     0,     0,     0,     0,   105,   106,   107,    23,    24,
      25,    26,     0,     0,   108,     0,     0,     0,     0,     0,
       0,     0,     0,    31,    32,    33,   109,    35,    36,    37,
     110,    39,     0,    40,    41,    42,     0,     0,    43,     0,
       0,    44,    45,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   112,     0,     0,   113,    50,     0,
      51,    52,     0,     0,     0,     0,    54,     0,    55,    56,
      57,    58,    59,    60,     0,     0,    61,     0,     0,     5,
       6,     7,     8,     9,    10,    11,    12,    13,     0,     0,
       0,     0,     0,     0,     0,    15,   114,   103,   104,    18,
      19,     0,     0,     0,     0,     0,   105,   106,   107,    23,
      24,    25,    26,     0,     0,   108,     0,     0,     0,     0,
       0,     0,     0,     0,    31,    32,    33,    34,    35,    36,
      37,    38,    39,     0,    40,    41,    42,     0,     0,    43,
       0,     0,    44,    45,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   299,     0,     0,   346,    50,
       0,    51,    52,     0,     0,     0,     0,    54,     0,    55,
      56,    57,    58,    59,    60,     0,     0,    61,     0,     0,
       5,     6,     7,     8,     9,    10,    11,    12,    13,     0,
       0,     0,     0,     0,     0,     0,    15,   114,   103,   104,
      18,    19,     0,     0,     0,     0,     0,   105,   106,   107,
      23,    24,    25,    26,     0,     0,   108,     0,     0,     0,
       0,     0,     0,     0,     0,    31,    32,    33,    34,    35,
      36,    37,    38,    39,     0,    40,    41,    42,     0,     0,
      43,     0,     0,    44,    45,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   897,     0,     0,   113,
      50,     0,    51,    52,     0,     0,     0,     0,    54,     0,
      55,    56,    57,    58,    59,    60,     0,     0,    61,     0,
       0,     5,     6,     7,     8,     9,    10,    11,    12,    13,
       0,     0,     0,     0,     0,     0,     0,    15,   114,   103,
     104,    18,    19,     0,     0,     0,     0,     0,   105,   106,
     107,    23,    24,    25,    26,     0,     0,   108,     0,     0,
       0,     0,     0,     0,     0,     0,    31,    32,    33,    34,
      35,    36,    37,    38,    39,     0,    40,    41,    42,     0,
       0,    43,     0,     0,    44,    45,     0,   350,   351,   352,
     353,   354,   355,   356,   357,   358,   359,   360,   361,   362,
       0,     0,   363,   364,     0,     0,     0,   923,     0,     0,
     113,    50,     0,    51,    52,     0,     0,     0,     0,    54,
       0,    55,    56,    57,    58,    59,    60,     0,     0,    61,
       0,     0,   598,   599,     0,   365,   600,   366,   367,   368,
     369,   370,   371,   372,   373,   374,   375,     0,     0,   114,
     166,   167,   168,   169,   170,   171,   172,   173,   174,     0,
       0,   175,   176,     0,     0,   177,   178,   179,   180,     0,
       0,     0,   350,  -588,  -588,  -588,  -588,   355,   356,   181,
     182,  -588,  -588,     0,     0,     0,     0,   363,   364,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,     0,   193,   194,   619,   591,     0,     0,   620,
     195,   263,   366,   367,   368,   369,   370,   371,   372,   373,
     374,   375,     0,   166,   167,   168,   169,   170,   171,   172,
     173,   174,     0,     0,   175,   176,     0,     0,   177,   178,
     179,   180,     0,     0,     0,   350,   351,   352,   353,   354,
     355,   356,   181,   182,   359,   360,     0,     0,     0,     0,
     363,   364,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,     0,   193,   194,   604,   599,
       0,     0,   605,   195,   263,   366,   367,   368,   369,   370,
     371,   372,   373,   374,   375,     0,   166,   167,   168,   169,
     170,   171,   172,   173,   174,     0,     0,   175,   176,     0,
       0,   177,   178,   179,   180,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   181,   182,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,     0,   193,
     194,   635,   591,     0,     0,   636,   195,   263,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   166,
     167,   168,   169,   170,   171,   172,   173,   174,     0,     0,
     175,   176,     0,     0,   177,   178,   179,   180,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   181,   182,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,     0,   193,   194,   638,   599,     0,     0,   639,   195,
     263,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   166,   167,   168,   169,   170,   171,   172,   173,
     174,     0,     0,   175,   176,     0,     0,   177,   178,   179,
     180,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   181,   182,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,     0,   193,   194,   645,   591,     0,
       0,   646,   195,   263,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   166,   167,   168,   169,   170,
     171,   172,   173,   174,     0,     0,   175,   176,     0,     0,
     177,   178,   179,   180,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   181,   182,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,     0,   193,   194,
     648,   599,     0,     0,   649,   195,   263,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   166,   167,
     168,   169,   170,   171,   172,   173,   174,     0,     0,   175,
     176,     0,     0,   177,   178,   179,   180,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   181,   182,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
       0,   193,   194,   682,   591,     0,     0,   683,   195,   263,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   166,   167,   168,   169,   170,   171,   172,   173,   174,
       0,     0,   175,   176,     0,     0,   177,   178,   179,   180,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     181,   182,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,     0,   193,   194,   685,   599,     0,     0,
     686,   195,   263,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   166,   167,   168,   169,   170,   171,
     172,   173,   174,     0,     0,   175,   176,     0,     0,   177,
     178,   179,   180,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   181,   182,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     0,   193,   194,   829,
     591,     0,     0,   830,   195,   263,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   166,   167,   168,
     169,   170,   171,   172,   173,   174,     0,     0,   175,   176,
       0,     0,   177,   178,   179,   180,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   181,   182,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,     0,
     193,   194,   832,   599,     0,     0,   833,   195,   263,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     166,   167,   168,   169,   170,   171,   172,   173,   174,     0,
       0,   175,   176,     0,     0,   177,   178,   179,   180,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   181,
     182,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,     0,   193,   194,   986,   591,     0,     0,   987,
     195,   263,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   166,   167,   168,   169,   170,   171,   172,
     173,   174,     0,     0,   175,   176,     0,     0,   177,   178,
     179,   180,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   181,   182,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,     0,   193,   194,   999,   591,
       0,     0,  1000,   195,   263,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   166,   167,   168,   169,
     170,   171,   172,   173,   174,     0,     0,   175,   176,     0,
       0,   177,   178,   179,   180,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   181,   182,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,     0,   193,
     194,  1002,   599,     0,     0,  1003,   195,   263,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   166,
     167,   168,   169,   170,   171,   172,   173,   174,     0,     0,
     175,   176,     0,     0,   177,   178,   179,   180,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   181,   182,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,     0,   193,   194,   604,   599,     0,     0,   605,   195,
     263,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   166,   167,   168,   169,   170,   171,   172,   173,
     174,     0,     0,   175,   176,     0,     0,   177,   178,   179,
     180,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   181,   182,   350,   351,   352,   353,   354,   355,   356,
     357,   358,   359,   360,   361,   362,     0,     0,   363,   364,
       0,     0,     0,     0,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,     0,   193,   194,     0,     0,     0,
       0,     0,   195,     0,     0,     0,     0,     0,     0,     0,
       0,   365,     0,   366,   367,   368,   369,   370,   371,   372,
     373,   374,   375,   350,   351,   352,   353,   354,   355,   356,
     357,   358,   359,   360,   361,   362,     0,   239,   363,   364,
       0,   350,   351,   352,   353,   354,   355,   356,   357,   358,
     359,   360,   361,   362,     0,     0,   363,   364,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   365,     0,   366,   367,   368,   369,   370,   371,   372,
     373,   374,   375,     0,     0,     0,     0,     0,     0,   365,
    -258,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,     0,     0,     0,     0,     0,     0,     0,  -259,   350,
     351,   352,   353,   354,   355,   356,   357,   358,   359,   360,
     361,   362,     0,     0,   363,   364,     0,   350,   351,   352,
     353,   354,   355,   356,   357,   358,   359,   360,   361,   362,
       0,     0,   363,   364,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   365,     0,   366,
     367,   368,   369,   370,   371,   372,   373,   374,   375,     0,
       0,     0,     0,     0,     0,   365,  -260,   366,   367,   368,
     369,   370,   371,   372,   373,   374,   375,     0,     0,     0,
       0,     0,     0,     0,  -261,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,     0,     0,
     363,   364,     0,     0,     0,   443,   350,   351,   352,   353,
     354,   355,   356,   357,     0,   359,   360,     0,     0,     0,
       0,   363,   364,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   365,     0,   366,   367,   368,   369,   370,
     371,   372,   373,   374,   375,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   366,   367,   368,   369,
     370,   371,   372,   373,   374,   375
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-826)))

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-588)))

static const yytype_int16 yycheck[] =
{
      27,     2,   259,    16,    17,    82,    83,    20,    84,    49,
       7,    28,     7,    22,   449,    14,   211,   293,   305,    14,
      21,   297,   305,   433,    49,    77,    16,    17,   424,    28,
      20,   317,    53,    28,     4,   349,    16,    17,   112,   300,
      20,    15,    66,    63,   702,     5,     6,    66,   388,   389,
      51,    52,   488,    13,     2,   378,     4,   788,    55,   631,
      55,    51,    52,    26,   623,    26,   510,    25,   640,   607,
     608,    51,    52,   113,    57,    25,    21,    22,   637,   402,
     905,   286,   882,    16,    17,   290,    25,    20,   647,    25,
     282,   100,    66,    53,   699,   418,   376,   702,     0,    25,
     380,   714,    10,   383,   427,   106,    86,    15,   446,   714,
     257,    25,    29,   451,   733,    57,   552,    77,    51,    25,
     739,    37,    38,   403,    25,   684,    57,    58,    59,    60,
     207,   349,   100,   135,    26,   118,    25,   417,    25,   419,
     217,    88,    25,    16,    17,   292,   293,    20,   428,    18,
     297,    20,   138,    90,   346,   100,    90,   125,   444,   145,
     118,   106,   107,   449,   989,   118,    60,   490,   118,    63,
     388,   389,   135,    55,   135,    88,   121,   140,   120,   979,
     138,   118,   140,   141,   118,   138,   466,   145,   138,   102,
      88,   141,   118,   110,    79,   145,    88,   144,   455,   138,
     318,   278,   138,   321,   140,   323,   744,   325,   939,   327,
     102,   491,   138,   107,    88,   141,   240,   504,    16,   145,
      51,   504,    25,    88,   138,   302,   404,   488,   886,   145,
     118,   144,   138,   230,   669,   230,   276,   138,   123,   140,
      71,   527,   282,   135,    28,   137,   144,   452,   300,   138,
     263,   138,   144,   458,   267,   138,   257,   282,   259,   138,
     284,   118,   263,    88,   469,   284,   240,    88,    99,   100,
     144,    90,   831,   247,    90,    88,   140,   267,   519,   144,
     521,   886,   140,   263,    90,    90,   722,   267,   138,   902,
     122,   552,   905,    88,   125,   145,    55,   902,   118,   118,
     905,    88,    88,   875,   212,   213,   346,   454,    90,    90,
     284,    90,   118,   118,   112,   118,   630,   115,   116,   144,
      55,   346,    90,   144,   344,    90,   347,   401,    25,   349,
     668,   144,   699,   281,   267,   138,   118,   118,   141,   118,
     300,   289,   145,    20,   627,   143,   551,   145,     2,   144,
       4,     5,     6,   118,   798,     9,    10,   144,   144,    13,
     334,    15,    16,    17,   334,   378,    20,   138,   388,   389,
     140,   815,   816,   659,   414,   145,   989,   378,   774,   310,
     138,   667,   422,   669,   989,   380,   334,   347,   383,   402,
     730,   339,   432,   138,   267,    49,   736,   737,   378,    53,
     145,   402,   549,   679,   727,   418,   663,   525,   403,    63,
     411,   344,    58,    59,   427,    90,   349,   418,    37,    38,
      57,   626,   402,    77,   419,   138,   427,   335,   336,   337,
     338,    58,    59,   428,   486,   380,   488,   135,   418,    71,
     618,   876,  1001,   118,   145,   462,   726,   427,   728,   423,
     424,    90,   141,   454,   455,   118,   446,   111,   403,   113,
     655,   722,   463,   462,   751,   875,   446,   462,   751,   449,
     142,   466,    71,   678,   419,   136,   141,   490,   112,   118,
     145,   115,   116,   428,    55,   562,   526,   477,    51,   490,
      53,    54,    55,    56,    17,    18,   491,   477,   472,   138,
     552,   112,   842,   436,   115,   116,   724,   508,   655,   510,
     490,   955,   730,   880,   138,   463,    51,    71,   736,   737,
      55,   466,    88,   890,   472,   782,   486,    71,   488,   128,
     129,   130,   679,   811,   812,   902,   102,   715,    51,    88,
      53,    54,    55,    56,   545,    90,   491,    62,   202,    64,
      65,   138,   579,   102,    97,    88,    15,    13,   212,   213,
      63,   802,   803,   804,   742,   806,    16,   808,   693,   102,
     597,   137,   697,   118,   752,   138,   859,    15,   144,   100,
     693,   138,   138,   141,   789,   136,   595,    51,   137,   714,
     876,   140,   552,   138,   603,   144,   623,   606,   113,   114,
      16,   714,   603,    51,   137,   606,   607,   608,   138,   263,
     637,   144,   138,   267,   138,   793,   603,   271,   272,   606,
     647,    90,   276,   624,   842,   138,   993,   281,   282,   630,
     631,   628,   633,   628,   651,   289,   138,   624,   138,   640,
    1007,   138,   616,    51,   138,    88,   300,   970,    44,   118,
     595,   856,   651,   118,    15,    18,   651,   684,   603,   102,
     136,   606,   663,   690,   740,    15,   861,   142,   136,   138,
     722,    15,   867,   136,    91,   853,    14,   622,   668,   624,
     334,   335,   336,   337,   338,   339,   340,   341,   668,   669,
     344,   971,   346,   347,   137,   349,   112,   630,    15,   115,
     116,   144,    15,   743,   724,   946,   947,   948,   949,   617,
     730,   731,   138,    90,   727,   138,   736,   737,   143,   759,
     141,    90,   138,    57,   378,   138,   727,   143,   138,   145,
      15,   771,   772,   728,   388,   389,   138,   714,   138,   779,
     138,   118,   650,   744,   922,   138,   138,   727,   402,   118,
     404,   405,    88,   138,   794,    62,   757,    64,    65,   760,
     414,   138,   722,    15,   418,    90,   102,    15,   422,   138,
    1011,    71,   746,   427,   899,   723,   136,   902,   432,   753,
     905,   782,   907,   728,   811,   812,   899,    61,    15,   902,
      64,    65,   905,   118,   907,    15,   138,   798,    55,    15,
     774,   137,   123,   136,   831,    16,   113,   114,   144,   463,
      16,   123,   852,   138,   815,   816,   136,    15,   472,    55,
     138,    15,   842,   138,   864,    15,   126,   127,   128,   129,
     130,   956,   486,   138,   488,   138,   490,   138,    88,   113,
     114,   138,     2,   956,     4,   138,   140,   138,   925,     9,
      10,   140,   102,   813,   762,    15,    16,    17,   818,    26,
      20,   463,    13,    88,   989,     6,   991,    88,   993,    26,
     995,    88,   526,    27,   875,   973,   989,   102,   991,   714,
     993,   102,   995,   979,    26,   102,   741,   137,   928,    49,
     930,   972,     7,   933,   144,  1020,   876,   317,   552,    88,
     860,   112,   242,    63,   115,   116,   112,  1020,   859,   115,
     116,   899,   137,   102,   941,   693,   137,   902,    -1,   144,
     137,    88,   899,   144,   699,   902,    88,   144,   905,    -1,
     907,    88,   143,    -1,   145,   102,    -1,   143,    -1,   145,
     102,    -1,    -1,    -1,    -1,   102,    88,    -1,   137,    -1,
      71,   111,    -1,   113,   955,   144,    -1,   970,   112,    -1,
     102,   115,   116,   617,   618,    86,    87,    -1,   135,   970,
     137,   972,   973,   140,  1001,   137,   971,   144,   135,   956,
     137,    -1,   144,   140,    -1,    -1,    -1,   144,    -1,   143,
     970,   145,    -1,   135,    -1,   137,   650,    -1,   140,    16,
      17,    88,   144,    20,   125,   126,   127,   128,   129,   130,
      -1,    88,   989,    -1,   991,   102,   993,    51,   995,    53,
      54,    55,    56,    -1,    -1,   102,   971,    -1,    -1,    46,
      47,    88,    -1,    -1,    51,    52,    51,    71,    53,    54,
      55,    56,   202,  1020,    -1,   102,    63,    64,     9,    10,
     137,    -1,   212,   213,    15,    -1,    -1,   144,    92,   112,
     137,   715,   115,   116,    98,    99,   100,   144,   722,   723,
     724,    61,    -1,   727,    64,    65,   730,   731,    -1,    -1,
     137,    -1,   736,   737,    -1,    -1,    -1,   144,   742,   743,
     143,   125,   145,    -1,   128,    -1,    -1,    51,   752,    53,
      54,    55,    56,   263,    -1,   759,   140,   267,   762,    -1,
      -1,   271,   272,    -1,    -1,    -1,   276,   771,   772,    -1,
      -1,   281,   282,   113,   114,   779,    -1,    -1,    -1,   289,
      -1,    -1,    -1,   388,   389,    -1,    -1,    -1,    92,   793,
     794,    -1,    51,    -1,    53,    54,    55,    56,    -1,    -1,
     111,    -1,    -1,    51,    -1,    53,    54,    55,    56,   813,
      -1,    -1,    71,    -1,   818,   420,   421,    -1,    -1,    63,
      64,    65,    -1,    71,   334,   335,   336,   337,   338,   339,
     340,   341,    -1,    92,   344,    -1,   346,    -1,   842,   349,
      99,   100,   112,    -1,    92,   115,   116,    -1,   852,   853,
      98,    99,   100,    -1,    -1,    -1,   860,    -1,    -1,    -1,
     864,    -1,   467,    -1,    -1,    -1,   125,    -1,   378,   113,
     114,   141,   142,    -1,    -1,   145,    -1,   125,   388,   389,
     128,    -1,   249,   250,   251,   252,    63,    64,    65,    -1,
     138,    71,   402,    -1,   404,   405,   263,    -1,    -1,    71,
     267,   212,   213,    -1,   414,    -1,    86,    87,   418,    -1,
      -1,    -1,   422,    -1,    86,    87,    -1,   427,   922,    15,
      -1,    -1,   432,    -1,   928,    -1,   930,    -1,    51,   933,
      53,    54,    55,    56,    -1,    -1,   113,   114,    40,    41,
      42,    43,    44,   123,   124,   125,   126,   127,   128,   129,
     130,    -1,    -1,   463,   126,   127,   128,   129,   130,    -1,
     271,   272,   472,    63,    64,    65,   970,    -1,    -1,    92,
      66,    -1,    -1,    -1,    -1,    98,    -1,   344,    -1,    -1,
     490,    -1,   349,   350,   351,   352,   353,   354,   355,   356,
     357,   358,   359,   360,   361,   362,   363,   364,   365,   366,
     367,   368,   369,   370,   371,   372,   373,   374,   375,    -1,
      -1,   378,    -1,   113,   114,    -1,   526,    63,    64,    65,
      -1,   388,   389,    -1,   335,   336,   337,   338,    -1,   340,
     341,    -1,    -1,    -1,    -1,   402,    -1,    51,    -1,    53,
      54,    55,    56,    -1,    -1,    63,    64,    65,    -1,   416,
      -1,   418,    -1,   420,   421,    -1,    -1,    71,    -1,    -1,
     427,    -1,    63,    64,    65,    -1,    -1,   113,   114,   436,
      -1,    -1,   439,    -1,    -1,    -1,   443,    -1,    92,   446,
      -1,   448,   449,    -1,    98,    99,   100,     2,    -1,     4,
       5,     6,    -1,    -1,   405,   113,   114,    -1,    13,    -1,
     467,    -1,    -1,    -1,   820,   821,    -1,   617,   618,   205,
     477,   125,   113,   114,   128,   211,    63,    64,    65,    -1,
      63,    64,    65,   490,    -1,   730,   731,    -1,    -1,    -1,
      -1,   736,   737,    -1,    49,    -1,    -1,    -1,    53,   506,
     650,    -1,    -1,    -1,   240,    -1,    -1,    -1,    -1,    -1,
     517,   247,    51,    -1,    53,    54,    55,    56,    -1,    -1,
     765,   766,    77,   768,   769,    -1,   113,   114,   535,   536,
     113,   114,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   546,
      -1,    -1,    -1,    -1,    -1,    -1,   902,    -1,   284,    -1,
     689,    -1,    -1,    92,    -1,    -1,   292,   293,   113,    98,
      -1,   297,    -1,   702,    -1,   715,   705,    -1,    -1,    -1,
      -1,    -1,    -1,   723,   724,   714,    -1,   727,    -1,    -1,
     730,   731,    -1,    -1,    -1,    -1,   736,   737,    -1,    -1,
      -1,    -1,   742,   743,    -1,    -1,    -1,   842,   334,    -1,
      -1,    -1,   752,   959,   960,   961,    -1,   963,   964,   759,
      -1,    -1,   762,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   771,   772,   630,   869,    -1,    -1,    -1,    -1,   779,
      51,    -1,    53,    54,    55,    56,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   793,   794,    -1,    -1,   202,    -1,    -1,
      71,    -1,    -1,   660,    -1,    -1,  1012,  1013,  1014,  1015,
      -1,   668,   669,    -1,    -1,    -1,   617,    -1,  1024,    -1,
      -1,    92,    -1,    -1,    -1,    -1,    -1,    98,    99,   100,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   423,   424,    -1,
      -1,    -1,   842,    -1,    -1,    -1,    -1,    -1,    -1,   650,
      -1,    -1,   852,   853,   125,    -1,    -1,   128,    -1,    -1,
      -1,    -1,   719,    -1,   864,    -1,    -1,   724,   725,   140,
     727,   276,    -1,   730,   731,    -1,   281,   282,    -1,   736,
     737,    -1,    -1,    -1,   289,     2,   472,     4,     5,     6,
       7,    -1,    -1,    -1,    -1,   300,    13,   886,    -1,   888,
      -1,    -1,    -1,   892,    -1,    -1,    -1,    -1,   765,   766,
      -1,   768,   769,    -1,    -1,    -1,   905,    -1,   907,    -1,
      -1,   778,   922,    -1,    -1,    -1,    -1,    -1,   928,   334,
     930,    -1,    49,   933,   339,    -1,    53,    -1,    -1,    -1,
      -1,   346,   347,    -1,   349,    -1,    -1,    -1,   937,   938,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      77,   762,    -1,    -1,    -1,    -1,    -1,   824,    -1,    -1,
     970,    -1,    -1,    -1,    -1,    -1,    -1,   834,   835,    -1,
      -1,    -1,    -1,   388,   389,   842,    -1,    -1,   977,    -1,
      -1,    -1,     2,   982,     4,    -1,   113,    -1,    -1,   404,
     989,    -1,   991,    13,    -1,    -1,   995,    -1,     0,   414,
      -1,    -1,   869,    -1,    -1,    -1,     2,   422,     4,   876,
    1009,    13,    14,    15,    16,    17,    18,   432,    20,    -1,
     616,  1020,    -1,    -1,    26,    27,    -1,    -1,    -1,    49,
      -1,    -1,    -1,    -1,    -1,    37,    38,    -1,    40,    41,
      42,    43,    44,    -1,    -1,    -1,    -1,    -1,   463,    -1,
      -1,    -1,    -1,    49,    -1,    -1,    -1,   472,    -1,   655,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   486,    -1,   488,    -1,   202,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   679,    -1,    -1,    88,    -1,    -1,    -1,
      -1,    -1,    -1,   113,    -1,    -1,    -1,    -1,    -1,    -1,
     102,    -1,    -1,   970,    -1,    -1,    -1,    -1,    -1,    -1,
     112,   526,    -1,   115,   116,    -1,    -1,   113,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   135,   136,    -1,    -1,   552,   140,   141,
      -1,   143,   144,   145,    -1,    -1,    -1,    -1,    -1,   276,
     746,    -1,    -1,    -1,   281,   282,    44,   753,    -1,    -1,
      -1,    -1,   289,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   300,    -1,    -1,    -1,    -1,   774,    -1,
      -1,    -1,   202,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    -1,    -1,    86,    87,
      -1,    -1,    -1,   618,    -1,    -1,   202,   334,    -1,    -1,
      -1,    -1,   339,    -1,    -1,    -1,    -1,    -1,    -1,   346,
     347,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   119,    -1,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     138,    -1,    -1,    -1,    -1,    -1,   276,    -1,    -1,    -1,
      -1,   281,   282,    -1,    -1,   861,    -1,    -1,    -1,   289,
      -1,   867,    -1,    -1,    -1,    -1,    -1,   404,    -1,    -1,
     276,    -1,    -1,    -1,    -1,   281,   282,   414,    -1,    -1,
      -1,    -1,    -1,   289,    -1,   422,    -1,    -1,    -1,    -1,
     715,    -1,    -1,    -1,    -1,   432,    -1,   722,   723,   724,
      -1,    -1,    -1,    -1,   334,   730,    -1,    -1,    -1,   339,
      -1,   736,   737,    -1,    -1,    -1,   346,   742,   743,   349,
      -1,    -1,    -1,    -1,    -1,    -1,   463,   752,   334,    -1,
      -1,    -1,    -1,   339,   759,   472,    -1,    -1,    -1,    -1,
     346,    -1,    -1,   349,    -1,    -1,   771,   772,    -1,   486,
      -1,   488,    -1,    -1,   779,    -1,    -1,    -1,   388,   389,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   793,   794,
      -1,    -1,    -1,    -1,   404,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   388,   389,   414,    -1,    -1,    -1,   813,   526,
      -1,    -1,   422,   818,    -1,    -1,    -1,    -1,   404,    -1,
      -1,    -1,   432,    -1,    -1,    -1,    -1,    -1,   414,    -1,
      -1,    -1,    -1,    -1,    -1,   552,   422,   842,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   432,   852,   853,    -1,
      -1,    -1,    -1,   463,    -1,   860,    -1,    -1,    -1,   864,
      -1,    -1,   472,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    51,    52,    -1,   463,    55,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   472,    -1,    -1,    -1,
      -1,    -1,    69,    70,    71,    72,    73,    74,    75,    76,
      77,   618,    -1,    80,    81,    -1,    -1,    84,    85,    86,
      87,    -1,    -1,    -1,    -1,    -1,   526,   922,    -1,    -1,
      -1,    98,    99,   928,    -1,   930,    -1,    -1,   933,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    -1,    -1,
     526,    -1,    -1,    -1,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,    -1,   132,   133,    -1,    -1,    -1,
      -1,    -1,   139,   140,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    -1,    -1,    86,
      87,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   715,    -1,
      -1,    -1,    -1,    -1,    -1,   722,   723,    -1,   618,    -1,
      -1,    -1,   119,    -1,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,    -1,   742,   743,    -1,    -1,    -1,
      -1,    -1,   618,    -1,    -1,   752,    -1,    -1,    -1,    -1,
      -1,    -1,   759,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   771,   772,    -1,    -1,    -1,    -1,
      -1,    -1,   779,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   793,   794,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   813,    -1,    -1,    -1,
      -1,   818,    -1,    -1,    -1,   715,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   723,   724,    -1,    -1,    -1,    -1,    -1,
     730,    -1,    -1,    -1,    -1,    -1,   736,   737,    -1,   715,
      -1,    -1,   742,   743,    -1,   852,   853,   723,   724,    -1,
      -1,    -1,   752,   860,   730,    -1,    -1,   864,    -1,   759,
     736,   737,    -1,    -1,    -1,    -1,   742,   743,    -1,    -1,
      -1,   771,   772,    -1,    -1,    -1,   752,    -1,    -1,   779,
      -1,    -1,    -1,   759,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   793,   794,   771,   772,    -1,    -1,    -1,
      -1,    -1,    -1,   779,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   922,    -1,   793,   794,    -1,
      -1,   928,    -1,   930,    -1,    -1,   933,    -1,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    -1,   842,    86,    87,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   852,   853,    -1,    -1,    -1,    -1,    -1,    -1,
     860,    -1,    -1,    -1,   864,    -1,   842,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   852,   853,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   864,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   922,    -1,    -1,    -1,    -1,    -1,   928,    -1,
     930,    -1,    -1,   933,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   922,    -1,    -1,    -1,
      -1,    -1,   928,    -1,   930,     0,     1,   933,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    -1,    -1,
      -1,    -1,    -1,    -1,    19,    -1,    21,    22,    23,    24,
      -1,    -1,    -1,    -1,    -1,    30,    31,    32,    33,    34,
      35,    36,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    -1,    58,    59,    60,    -1,    -1,    63,    -1,
      -1,    66,    67,    -1,    69,    70,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    89,    -1,    -1,    92,    93,    -1,
      95,    96,    -1,    98,    -1,    -1,   101,    -1,   103,   104,
     105,   106,   107,   108,     0,    -1,   111,   112,    -1,    -1,
     115,   116,    -1,    -1,    -1,    -1,    -1,    13,    14,    15,
      16,    17,    18,    -1,    20,    -1,   131,   132,   133,    -1,
      -1,    27,    28,    -1,    -1,    -1,    -1,    -1,   143,    -1,
     145,    37,    38,    -1,    40,    41,    42,    43,    44,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    57,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    -1,    -1,
      86,    87,    88,    -1,    90,    91,    -1,    -1,    -1,    -1,
      -1,    97,    -1,    -1,    -1,    -1,   102,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   112,    -1,    -1,   115,
     116,    -1,   118,   119,    -1,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,    -1,    -1,     0,    -1,    -1,
     136,   137,   138,    -1,    -1,   141,   142,   143,   144,   145,
      13,    14,    15,    16,    17,    18,    -1,    20,    -1,    -1,
      -1,    -1,    -1,    -1,    27,    28,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    37,    38,    -1,    40,    41,    42,
      43,    44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    -1,    -1,    86,    87,    88,    -1,    -1,    91,    -1,
      -1,    -1,    -1,    -1,    97,    -1,    -1,    -1,    -1,   102,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   112,
      -1,    -1,   115,   116,    -1,    -1,   119,    -1,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,    -1,    -1,
       0,    -1,    -1,   136,   137,   138,    -1,   140,   141,   142,
     143,   144,   145,    13,    14,    15,    -1,    17,    18,    -1,
      20,    -1,    -1,    -1,    -1,    -1,    26,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,    38,    -1,
      40,    41,    42,    43,    44,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    -1,    -1,    86,    87,    88,    -1,
      90,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   102,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   112,    -1,    -1,   115,   116,    -1,   118,   119,
      -1,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,    -1,    -1,     0,    -1,   135,   136,   137,   138,    -1,
      -1,   141,    -1,   143,   144,   145,    13,    14,    15,    -1,
      17,    18,    -1,    20,    -1,    -1,    -1,    -1,    -1,    26,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      37,    38,    -1,    40,    41,    42,    43,    44,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    -1,    -1,    86,
      87,    88,    -1,    90,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   102,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   112,    -1,    -1,   115,   116,
      -1,   118,   119,    -1,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,    -1,    -1,     0,    -1,   135,   136,
     137,   138,    -1,    -1,   141,    -1,   143,   144,   145,    13,
      14,    15,    -1,    17,    18,    -1,    20,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    37,    38,    -1,    40,    41,    42,    43,
      44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      -1,    -1,    86,    87,    88,    -1,    90,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   102,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   112,    -1,
      -1,   115,   116,    -1,   118,   119,    -1,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,    -1,    -1,     0,
      -1,    -1,   136,   137,   138,    -1,    -1,   141,    -1,   143,
     144,   145,    13,    14,    15,    -1,    17,    18,    -1,    20,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    37,    38,    -1,    40,
      41,    42,    43,    44,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    -1,    -1,    86,    87,    88,    -1,    90,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   102,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   112,    -1,    -1,   115,   116,    -1,   118,   119,    -1,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
      -1,    -1,    -1,    -1,    -1,   136,   137,   138,    -1,    -1,
     141,    -1,   143,   144,   145,     1,    -1,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      -1,    -1,    18,    19,    -1,    21,    22,    23,    24,    -1,
      -1,    -1,    -1,    -1,    30,    31,    32,    33,    34,    35,
      36,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    45,
      -1,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    -1,    58,    59,    60,    -1,    -1,    63,    -1,    -1,
      66,    67,    -1,    69,    70,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    89,    -1,    -1,    92,    93,    -1,    95,
      96,    -1,    98,    -1,    -1,   101,    -1,   103,   104,   105,
     106,   107,   108,    -1,    -1,   111,   112,    -1,    -1,   115,
     116,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   131,   132,   133,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   143,     1,   145,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      -1,    -1,    15,    -1,    17,    18,    19,    -1,    21,    22,
      23,    24,    -1,    -1,    -1,    -1,    -1,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,    39,    -1,    -1,    -1,
      -1,    -1,    45,    -1,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    -1,    58,    59,    60,    -1,    -1,
      63,    -1,    -1,    66,    67,    -1,    69,    70,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    89,    -1,    -1,    92,
      93,    -1,    95,    96,    -1,    98,    -1,    -1,   101,    -1,
     103,   104,   105,   106,   107,   108,    -1,    -1,   111,   112,
      -1,    -1,   115,   116,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   131,   132,
     133,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     143,     1,   145,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    -1,    -1,    15,    -1,    -1,    18,    19,
      20,    21,    22,    23,    24,    -1,    -1,    -1,    -1,    -1,
      30,    31,    32,    33,    34,    35,    36,    -1,    -1,    39,
      -1,    -1,    -1,    -1,    -1,    45,    -1,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    -1,    58,    59,
      60,    -1,    -1,    63,    -1,    -1,    66,    67,    -1,    69,
      70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,
      -1,    -1,    92,    93,    -1,    95,    96,    -1,    98,    -1,
      -1,   101,    -1,   103,   104,   105,   106,   107,   108,    -1,
      -1,   111,   112,    -1,    -1,   115,   116,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   131,   132,   133,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   143,     1,   145,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    -1,    -1,    15,    -1,
      -1,    18,    19,    -1,    21,    22,    23,    24,    -1,    -1,
      -1,    -1,    -1,    30,    31,    32,    33,    34,    35,    36,
      -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    45,    -1,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      -1,    58,    59,    60,    -1,    -1,    63,    -1,    -1,    66,
      67,    -1,    69,    70,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    89,    -1,    -1,    92,    93,    -1,    95,    96,
      -1,    98,    -1,    -1,   101,    -1,   103,   104,   105,   106,
     107,   108,    -1,    -1,   111,   112,    -1,    -1,   115,   116,
       1,    -1,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    -1,    -1,   131,   132,   133,    -1,    19,    -1,
      21,    22,    23,    24,    -1,    -1,   143,    -1,   145,    30,
      31,    32,    33,    34,    35,    36,    -1,    -1,    39,    -1,
      -1,    -1,    -1,    -1,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    -1,    58,    59,    60,
      -1,    -1,    63,    -1,    -1,    66,    67,    -1,    69,    70,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,    -1,
      -1,    92,    93,    -1,    95,    96,    -1,    98,    -1,    -1,
     101,    -1,   103,   104,   105,   106,   107,   108,    -1,    -1,
     111,   112,    -1,    -1,   115,   116,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     131,   132,   133,    -1,    -1,   136,    -1,    -1,    -1,    -1,
      -1,    -1,   143,     1,   145,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    -1,    14,    15,    -1,    -1,
      -1,    19,    -1,    21,    22,    23,    24,    -1,    -1,    -1,
      -1,    -1,    30,    31,    32,    33,    34,    35,    36,    -1,
      -1,    39,    -1,    -1,    -1,    -1,    -1,    45,    -1,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    -1,
      58,    59,    60,    -1,    -1,    63,    -1,    -1,    66,    67,
      -1,    69,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    89,    -1,    -1,    92,    93,    -1,    95,    96,    -1,
      98,    -1,    -1,   101,    -1,   103,   104,   105,   106,   107,
     108,    -1,    -1,   111,   112,    -1,    -1,   115,   116,     1,
      -1,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    -1,    -1,   131,   132,   133,    -1,    19,    -1,    21,
      22,    23,    24,    -1,    -1,   143,    -1,   145,    30,    31,
      32,    33,    34,    35,    36,    -1,    -1,    39,    -1,    -1,
      -1,    -1,    -1,    45,    -1,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    -1,    58,    59,    60,    -1,
      -1,    63,    -1,    -1,    66,    67,    -1,    69,    70,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,    -1,    -1,
      92,    93,    -1,    95,    96,    -1,    98,    -1,    -1,   101,
      -1,   103,   104,   105,   106,   107,   108,    -1,    -1,   111,
     112,    -1,    -1,   115,   116,     1,    -1,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    -1,    -1,   131,
     132,   133,    -1,    19,    -1,    21,    22,    23,    24,   141,
      -1,   143,    -1,   145,    30,    31,    32,    33,    34,    35,
      36,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    45,
      -1,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    -1,    58,    59,    60,    -1,    -1,    63,    -1,    -1,
      66,    67,    -1,    69,    70,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    89,    -1,    -1,    92,    93,    -1,    95,
      96,    -1,    98,    -1,    -1,   101,    -1,   103,   104,   105,
     106,   107,   108,    -1,    -1,   111,   112,    -1,    -1,   115,
     116,     1,    -1,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    -1,    -1,   131,   132,   133,    -1,    19,
      -1,    21,    22,    23,    24,   141,    -1,   143,    -1,   145,
      30,    31,    32,    33,    34,    35,    36,    -1,    -1,    39,
      -1,    -1,    -1,    -1,    -1,    45,    -1,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    -1,    58,    59,
      60,    -1,    -1,    63,    -1,    -1,    66,    67,    -1,    69,
      70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,
      -1,    -1,    92,    93,    -1,    95,    96,    -1,    98,    -1,
      -1,   101,    -1,   103,   104,   105,   106,   107,   108,    -1,
      -1,   111,   112,    -1,    -1,   115,   116,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   131,   132,   133,    -1,    -1,   136,    -1,    -1,    -1,
      -1,    -1,    -1,   143,     1,   145,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    -1,    -1,    15,    -1,
      -1,    -1,    19,    -1,    21,    22,    23,    24,    -1,    -1,
      -1,    -1,    -1,    30,    31,    32,    33,    34,    35,    36,
      -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    45,    -1,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      -1,    58,    59,    60,    -1,    -1,    63,    -1,    -1,    66,
      67,    -1,    69,    70,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    89,    -1,    -1,    92,    93,    -1,    95,    96,
      -1,    98,    -1,    -1,   101,    -1,   103,   104,   105,   106,
     107,   108,    -1,    -1,   111,   112,    -1,    -1,   115,   116,
      -1,    -1,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    -1,    -1,   131,   132,   133,    -1,    19,    -1,
      21,    22,    23,    24,    -1,    -1,   143,    -1,   145,    30,
      31,    32,    33,    34,    35,    36,    -1,    -1,    39,    -1,
      -1,    -1,    -1,    -1,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    -1,    58,    59,    60,
      -1,    -1,    63,    -1,    -1,    66,    67,    -1,    69,    70,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,    -1,
      -1,    92,    93,    -1,    95,    96,    -1,    98,    -1,    -1,
     101,    -1,   103,   104,   105,   106,   107,   108,    -1,    -1,
     111,   112,    -1,    -1,   115,   116,    -1,    -1,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    -1,    -1,
     131,   132,   133,    -1,    19,    -1,    21,    22,    23,    24,
      -1,    -1,   143,    -1,   145,    30,    31,    32,    33,    34,
      35,    36,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,
      45,    -1,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    -1,    58,    59,    60,    -1,    -1,    63,    -1,
      -1,    66,    67,    -1,    69,    70,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    89,    -1,    -1,    92,    93,    -1,
      95,    96,    -1,    98,    -1,    -1,   101,    -1,   103,   104,
     105,   106,   107,   108,    -1,    -1,   111,   112,    -1,    -1,
     115,   116,    -1,    -1,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    -1,    -1,    -1,   131,   132,   133,    -1,
      19,    -1,    21,    22,    23,    24,    -1,    -1,   143,    -1,
     145,    30,    31,    32,    33,    34,    35,    36,    -1,    -1,
      39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    -1,    58,
      59,    60,    -1,    -1,    63,    -1,    -1,    66,    67,    -1,
      69,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      89,    -1,    -1,    92,    93,    -1,    95,    96,    -1,    -1,
      -1,    -1,   101,    -1,   103,   104,   105,   106,   107,   108,
      -1,    -1,   111,   112,    -1,    -1,   115,   116,    -1,    -1,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    -1,
      -1,    -1,   131,   132,   133,    -1,    19,    -1,    21,    22,
      23,    24,    -1,    -1,   143,    -1,   145,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,    39,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    -1,    58,    59,    60,    -1,    -1,
      63,    -1,    -1,    66,    67,    -1,    69,    70,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    89,    -1,    -1,    92,
      93,    -1,    95,    96,    -1,    -1,    -1,    -1,   101,    -1,
     103,   104,   105,   106,   107,   108,    -1,    -1,   111,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   131,   132,
     133,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   145,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    -1,    -1,    -1,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      -1,    -1,    -1,    -1,    -1,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
      80,    81,    -1,    -1,    84,    85,    86,    87,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    98,    99,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,    -1,   132,   133,    -1,    -1,    -1,    -1,    -1,   139,
     140,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,    -1,    21,
      22,    23,    24,    -1,    26,    -1,    -1,    -1,    30,    31,
      32,    33,    34,    35,    36,    -1,    -1,    39,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    -1,    58,    59,    60,    -1,
      -1,    63,    -1,    -1,    66,    67,    -1,    69,    70,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,    -1,    -1,
      92,    93,    -1,    95,    96,    -1,    98,    99,   100,   101,
      -1,   103,   104,   105,   106,   107,   108,    -1,    -1,   111,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,   131,
     132,   133,    19,   135,    21,    22,    23,    24,   140,    26,
      -1,    -1,    -1,    30,    31,    32,    33,    34,    35,    36,
      -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      -1,    58,    59,    60,    -1,    -1,    63,    -1,    -1,    66,
      67,    -1,    69,    70,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    89,    -1,    -1,    92,    93,    -1,    95,    96,
      -1,    98,    99,   100,   101,    -1,   103,   104,   105,   106,
     107,   108,    -1,    -1,   111,    -1,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      -1,    -1,    -1,    -1,   131,   132,   133,    19,   135,    21,
      22,    23,    24,   140,    26,    -1,    -1,    -1,    30,    31,
      32,    33,    34,    35,    36,    -1,    -1,    39,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    -1,    58,    59,    60,    -1,
      -1,    63,    -1,    -1,    66,    67,    -1,    69,    70,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,    -1,    -1,
      92,    93,    -1,    95,    96,    -1,    98,    99,   100,   101,
      -1,   103,   104,   105,   106,   107,   108,    -1,    -1,   111,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,   131,
     132,   133,    19,   135,    21,    22,    23,    24,   140,    -1,
      -1,    -1,    -1,    30,    31,    32,    33,    34,    35,    36,
      -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      -1,    58,    59,    60,    -1,    -1,    63,    -1,    -1,    66,
      67,    -1,    69,    70,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    89,    90,    -1,    92,    93,    -1,    95,    96,
      -1,    98,    99,   100,   101,    -1,   103,   104,   105,   106,
     107,   108,    -1,    -1,   111,    -1,    -1,    -1,    -1,    -1,
      -1,   118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   131,   132,   133,    -1,    -1,    -1,
      -1,    -1,    -1,   140,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      19,    -1,    21,    22,    23,    24,    -1,    -1,    -1,    -1,
      -1,    30,    31,    32,    33,    34,    35,    36,    -1,    -1,
      39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    -1,    58,
      59,    60,    -1,    -1,    63,    -1,    -1,    66,    67,    -1,
      69,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      89,    90,    -1,    92,    93,    -1,    95,    96,    -1,    98,
      99,   100,   101,    -1,   103,   104,   105,   106,   107,   108,
      -1,    -1,   111,    -1,    -1,    -1,    -1,    -1,    -1,   118,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   131,   132,   133,    -1,    -1,    -1,    -1,    -1,
      -1,   140,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,    -1,
      21,    22,    23,    24,    -1,    -1,    -1,    -1,    -1,    30,
      31,    32,    33,    34,    35,    36,    -1,    -1,    39,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    -1,    58,    59,    60,
      -1,    -1,    63,    -1,    -1,    66,    67,    -1,    69,    70,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,    -1,
      -1,    92,    93,    -1,    95,    96,    -1,    98,    99,   100,
     101,    -1,   103,   104,   105,   106,   107,   108,    -1,    -1,
     111,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,
     131,   132,   133,    19,    -1,    21,    22,    23,    24,   140,
      -1,    -1,    -1,    -1,    30,    31,    32,    33,    34,    35,
      36,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    -1,    58,    59,    60,    -1,    -1,    63,    -1,    -1,
      66,    67,    -1,    69,    70,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    89,    -1,    -1,    92,    93,    -1,    95,
      96,    -1,    98,    99,   100,   101,    -1,   103,   104,   105,
     106,   107,   108,    -1,    -1,   111,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    -1,    -1,    -1,    -1,   131,   132,   133,    19,    -1,
      21,    22,    23,    24,   140,    -1,    -1,    -1,    -1,    30,
      31,    32,    33,    34,    35,    36,    -1,    -1,    39,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    -1,    58,    59,    60,
      -1,    -1,    63,    -1,    -1,    66,    67,    -1,    69,    70,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,    -1,
      -1,    92,    93,    -1,    95,    96,    -1,    98,    99,   100,
     101,    -1,   103,   104,   105,   106,   107,   108,    -1,    -1,
     111,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     131,   132,   133,    -1,    -1,    -1,    -1,    -1,    -1,   140,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    -1,    -1,    -1,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    -1,    -1,    -1,
      -1,    -1,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    -1,    -1,    -1,    -1,    -1,    -1,
      63,    -1,    -1,    -1,    -1,    -1,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    80,    81,    -1,
      -1,    84,    85,    86,    87,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    98,    99,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   107,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,    -1,   132,
     133,    -1,    -1,    -1,    -1,    -1,   139,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    -1,    -1,    -1,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    -1,    -1,    -1,    -1,    -1,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    -1,    -1,    -1,    -1,    -1,    -1,    63,    -1,    -1,
      -1,    -1,    -1,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,    80,    81,    -1,    -1,    84,    85,
      86,    87,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    98,    99,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   107,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,    -1,   132,   133,    -1,    -1,
      -1,    -1,    -1,   139,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    -1,    -1,
      -1,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,    48,
      49,    50,    51,    52,    -1,    -1,    55,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    80,    81,    -1,    -1,    84,    85,    86,    87,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    98,
      99,    -1,    -1,    -1,   103,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,    -1,   132,   133,    -1,    -1,    -1,    -1,    -1,
     139,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    -1,    -1,    -1,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    -1,    -1,
      -1,    -1,    -1,    45,    46,    47,    48,    49,    50,    51,
      52,    -1,    -1,    55,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,    80,    81,
      -1,    -1,    84,    85,    86,    87,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    98,    99,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,    -1,
     132,   133,    -1,    -1,    -1,    -1,    -1,   139,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    19,    -1,    21,    22,    23,    24,
      -1,    -1,    -1,    -1,    -1,    30,    31,    32,    33,    34,
      35,    36,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    -1,    58,    59,    60,    -1,    -1,    63,    -1,
      -1,    66,    67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    89,    -1,    -1,    92,    93,    -1,
      95,    96,    -1,    -1,    -1,    -1,   101,    -1,   103,   104,
     105,   106,   107,   108,    -1,    -1,   111,    -1,    -1,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    19,   131,    21,    22,    23,
      24,    -1,    -1,   138,    -1,    -1,    30,    31,    32,    33,
      34,    35,    36,    -1,    -1,    39,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    -1,    58,    59,    60,    -1,    -1,    63,
      -1,    -1,    66,    67,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    89,    -1,    -1,    92,    93,
      -1,    95,    96,    -1,    -1,    -1,    -1,   101,    -1,   103,
     104,   105,   106,   107,   108,    -1,    -1,   111,    -1,    -1,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      -1,    -1,    -1,    -1,    -1,    -1,    19,   131,    21,    22,
      23,    24,    -1,    -1,   138,    -1,    -1,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,    39,    -1,    -1,    -1,
      -1,    -1,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    -1,    58,    59,    60,    -1,    -1,
      63,    -1,    -1,    66,    67,    -1,    69,    70,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    89,    -1,    -1,    92,
      93,    -1,    95,    96,    -1,    98,    -1,    -1,   101,    -1,
     103,   104,   105,   106,   107,   108,    -1,    -1,   111,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    -1,    -1,    -1,    -1,   131,   132,
     133,    19,    -1,    21,    22,    23,    24,    -1,    -1,    -1,
      -1,    -1,    30,    31,    32,    33,    34,    35,    36,    -1,
      -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    -1,
      58,    59,    60,    -1,    -1,    63,    -1,    -1,    66,    67,
      -1,    69,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    89,    -1,    -1,    92,    93,    -1,    95,    96,    -1,
      -1,    99,   100,   101,    -1,   103,   104,   105,   106,   107,
     108,    -1,    -1,   111,   112,    -1,    -1,   115,   116,    -1,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      -1,    -1,    -1,   131,   132,   133,    19,    -1,    21,    22,
      23,    24,    -1,    -1,    -1,    -1,    -1,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,    39,    -1,    -1,    -1,
      -1,    -1,    45,    -1,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    -1,    58,    59,    60,    -1,    -1,
      63,    -1,    -1,    66,    67,    -1,    69,    70,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    89,    -1,    -1,    92,
      93,    -1,    95,    96,    -1,    98,    -1,    -1,   101,    -1,
     103,   104,   105,   106,   107,   108,    -1,    -1,   111,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    -1,    -1,    -1,    -1,   131,   132,
     133,    19,    -1,    21,    22,    23,    24,    -1,    -1,    -1,
      -1,    -1,    30,    31,    32,    33,    34,    35,    36,    -1,
      -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    -1,
      58,    59,    60,    -1,    -1,    63,    -1,    -1,    66,    67,
      -1,    69,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    89,    -1,    -1,    92,    93,    -1,    95,    96,    -1,
      -1,    99,    -1,   101,    -1,   103,   104,   105,   106,   107,
     108,    -1,    -1,   111,   112,    -1,    -1,   115,   116,    -1,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    -1,
      -1,    -1,    -1,   131,   132,   133,    19,    -1,    21,    22,
      23,    24,    -1,    -1,    -1,    -1,    -1,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,    39,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    -1,    58,    59,    60,    -1,    -1,
      63,    -1,    -1,    66,    67,    -1,    69,    70,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    89,    -1,    -1,    92,
      93,    -1,    95,    96,    -1,    98,    99,   100,   101,    -1,
     103,   104,   105,   106,   107,   108,    -1,    -1,   111,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    -1,    -1,    -1,    -1,   131,   132,
     133,    19,    -1,    21,    22,    23,    24,    -1,    -1,    -1,
      -1,    -1,    30,    31,    32,    33,    34,    35,    36,    -1,
      -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    -1,
      58,    59,    60,    -1,    -1,    63,    -1,    -1,    66,    67,
      -1,    69,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    89,    -1,    -1,    92,    93,    -1,    95,    96,    -1,
      98,    99,   100,   101,    -1,   103,   104,   105,   106,   107,
     108,    -1,    -1,   111,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    -1,
      -1,    -1,    -1,   131,   132,   133,    19,    -1,    21,    22,
      23,    24,    -1,    -1,    -1,    -1,    -1,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,    39,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    -1,    58,    59,    60,    -1,    -1,
      63,    -1,    -1,    66,    67,    -1,    69,    70,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    89,    -1,    -1,    92,
      93,    -1,    95,    96,    -1,    98,    99,    -1,   101,    -1,
     103,   104,   105,   106,   107,   108,    -1,    -1,   111,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    -1,    -1,    -1,    -1,   131,   132,
     133,    19,    -1,    21,    22,    23,    24,    -1,    -1,    -1,
      -1,    -1,    30,    31,    32,    33,    34,    35,    36,    -1,
      -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    -1,
      58,    59,    60,    -1,    -1,    63,    -1,    -1,    66,    67,
      -1,    69,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    89,    -1,    -1,    92,    93,    -1,    95,    96,    -1,
      98,    99,    -1,   101,    -1,   103,   104,   105,   106,   107,
     108,    -1,    -1,   111,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    -1,
      -1,    -1,    -1,   131,   132,   133,    19,    -1,    21,    22,
      23,    24,    -1,    -1,    -1,    -1,    -1,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,    39,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    -1,    58,    59,    60,    -1,    -1,
      63,    -1,    -1,    66,    67,    -1,    69,    70,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    89,    -1,    -1,    92,
      93,    -1,    95,    96,    -1,    -1,    99,    -1,   101,    -1,
     103,   104,   105,   106,   107,   108,    -1,    -1,   111,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    -1,    -1,    -1,    -1,   131,   132,
     133,    19,    -1,    21,    22,    23,    24,    -1,    -1,    -1,
      -1,    -1,    30,    31,    32,    33,    34,    35,    36,    -1,
      -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    -1,
      58,    59,    60,    -1,    -1,    63,    -1,    -1,    66,    67,
      -1,    69,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    89,    -1,    -1,    92,    93,    -1,    95,    96,    -1,
      98,    -1,    -1,   101,    -1,   103,   104,   105,   106,   107,
     108,    -1,    -1,   111,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    -1,
      -1,    -1,    -1,   131,   132,   133,    19,    -1,    21,    22,
      23,    24,    -1,    -1,    -1,    -1,    -1,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,    39,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    -1,    58,    59,    60,    -1,    -1,
      63,    -1,    -1,    66,    67,    -1,    69,    70,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    89,    -1,    -1,    92,
      93,    -1,    95,    96,    -1,    98,    -1,    -1,   101,    -1,
     103,   104,   105,   106,   107,   108,    -1,    -1,   111,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    -1,    -1,    -1,    -1,   131,   132,
     133,    19,    -1,    21,    22,    23,    24,    -1,    -1,    -1,
      -1,    -1,    30,    31,    32,    33,    34,    35,    36,    -1,
      -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    -1,
      58,    59,    60,    -1,    -1,    63,    -1,    -1,    66,    67,
      -1,    69,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    89,    -1,    -1,    92,    93,    -1,    95,    96,    -1,
      98,    -1,    -1,   101,    -1,   103,   104,   105,   106,   107,
     108,    -1,    -1,   111,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    -1,
      -1,    -1,    -1,   131,   132,   133,    19,    -1,    21,    22,
      23,    24,    -1,    -1,    -1,    -1,    -1,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,    39,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    -1,    58,    59,    60,    -1,    -1,
      63,    -1,    -1,    66,    67,    -1,    69,    70,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    89,    -1,    -1,    92,
      93,    -1,    95,    96,    -1,    98,    -1,    -1,   101,    -1,
     103,   104,   105,   106,   107,   108,    -1,    -1,   111,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    -1,    -1,    -1,    -1,   131,   132,
     133,    19,    -1,    21,    22,    23,    24,    -1,    -1,    -1,
      -1,    -1,    30,    31,    32,    33,    34,    35,    36,    -1,
      -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    -1,
      58,    59,    60,    -1,    -1,    63,    -1,    -1,    66,    67,
      -1,    69,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    89,    -1,    -1,    92,    93,    -1,    95,    96,    -1,
      98,    -1,    -1,   101,    -1,   103,   104,   105,   106,   107,
     108,    -1,    -1,   111,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    -1,
      -1,    -1,    -1,   131,   132,   133,    19,    -1,    21,    22,
      23,    24,    -1,    -1,    -1,    -1,    -1,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,    39,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    -1,    58,    59,    60,    -1,    -1,
      63,    -1,    -1,    66,    67,    -1,    69,    70,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    89,    -1,    -1,    92,
      93,    -1,    95,    96,    -1,    -1,    -1,    -1,   101,    -1,
     103,   104,   105,   106,   107,   108,    -1,    -1,   111,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    -1,    -1,    -1,    -1,   131,   132,
     133,    19,    -1,    21,    22,    23,    24,    -1,    -1,    -1,
      -1,    -1,    30,    31,    32,    33,    34,    35,    36,    -1,
      -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    -1,
      58,    59,    60,    -1,    -1,    63,    -1,    -1,    66,    67,
      -1,    69,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    89,    -1,    -1,    92,    93,    -1,    95,    96,    -1,
      -1,    -1,    -1,   101,    -1,   103,   104,   105,   106,   107,
     108,    -1,    -1,   111,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    -1,
      -1,    -1,    -1,   131,   132,   133,    19,    -1,    21,    22,
      23,    24,    -1,    -1,    -1,    -1,    -1,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,    39,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    -1,    58,    59,    60,    -1,    -1,
      63,    -1,    -1,    66,    67,    -1,    69,    70,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    89,    -1,    -1,    92,
      93,    -1,    95,    96,    -1,    -1,    -1,    -1,   101,    -1,
     103,   104,   105,   106,   107,   108,    -1,    -1,   111,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    -1,    -1,    -1,    -1,   131,   132,
     133,    19,    -1,    21,    22,    23,    24,    -1,    -1,    -1,
      -1,    -1,    30,    31,    32,    33,    34,    35,    36,    -1,
      -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    -1,
      58,    59,    60,    -1,    -1,    63,    -1,    -1,    66,    67,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,    -1,
      -1,    89,    -1,    -1,    92,    93,    -1,    95,    96,    -1,
      -1,    -1,    -1,   101,    -1,   103,   104,   105,   106,   107,
     108,    -1,    -1,   111,    -1,    -1,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    19,   131,    21,    22,    23,    24,    -1,    -1,
      -1,    -1,    -1,    30,    31,    32,    33,    34,    35,    36,
      -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      -1,    58,    59,    60,    -1,    -1,    63,    -1,    -1,    66,
      67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    89,    -1,    -1,    92,    93,    -1,    95,    96,
      -1,    98,    -1,    -1,   101,    -1,   103,   104,   105,   106,
     107,   108,    -1,    -1,   111,    -1,    -1,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    19,   131,    21,    22,    23,    24,    -1,
      -1,    -1,    -1,    -1,    30,    31,    32,    33,    34,    35,
      36,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    -1,    58,    59,    60,    -1,    -1,    63,    -1,    -1,
      66,    67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    89,    -1,    -1,    92,    93,    -1,    95,
      96,    -1,    98,    -1,    -1,   101,    -1,   103,   104,   105,
     106,   107,   108,    -1,    -1,   111,    -1,    -1,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    19,   131,    21,    22,    23,    24,
      -1,    -1,    -1,    -1,    -1,    30,    31,    32,    33,    34,
      35,    36,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    -1,    58,    59,    60,    -1,    -1,    63,    -1,
      -1,    66,    67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    89,    -1,    -1,    92,    93,    -1,
      95,    96,    -1,    -1,    -1,    -1,   101,    -1,   103,   104,
     105,   106,   107,   108,    -1,    -1,   111,    -1,    -1,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    19,   131,    21,    22,    23,
      24,    -1,    -1,    -1,    -1,    -1,    30,    31,    32,    33,
      34,    35,    36,    -1,    -1,    39,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    -1,    58,    59,    60,    -1,    -1,    63,
      -1,    -1,    66,    67,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    89,    -1,    -1,    92,    93,
      -1,    95,    96,    -1,    -1,    -1,    -1,   101,    -1,   103,
     104,   105,   106,   107,   108,    -1,    -1,   111,    -1,    -1,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    19,   131,    21,    22,
      23,    24,    -1,    -1,    -1,    -1,    -1,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,    39,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    -1,    58,    59,    60,    -1,    -1,
      63,    -1,    -1,    66,    67,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    89,    -1,    -1,    92,
      93,    -1,    95,    96,    -1,    -1,    -1,    -1,   101,    -1,
     103,   104,   105,   106,   107,   108,    -1,    -1,   111,    -1,
      -1,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,   131,    21,
      22,    23,    24,    -1,    -1,    -1,    -1,    -1,    30,    31,
      32,    33,    34,    35,    36,    -1,    -1,    39,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    -1,    58,    59,    60,    -1,
      -1,    63,    -1,    -1,    66,    67,    -1,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      -1,    -1,    86,    87,    -1,    -1,    -1,    89,    -1,    -1,
      92,    93,    -1,    95,    96,    -1,    -1,    -1,    -1,   101,
      -1,   103,   104,   105,   106,   107,   108,    -1,    -1,   111,
      -1,    -1,    51,    52,    -1,   119,    55,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,    -1,    -1,   131,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    80,    81,    -1,    -1,    84,    85,    86,    87,    -1,
      -1,    -1,    71,    72,    73,    74,    75,    76,    77,    98,
      99,    80,    81,    -1,    -1,    -1,    -1,    86,    87,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,    -1,   132,   133,    51,    52,    -1,    -1,    55,
     139,   140,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,    -1,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,    80,    81,    -1,    -1,    84,    85,
      86,    87,    -1,    -1,    -1,    71,    72,    73,    74,    75,
      76,    77,    98,    99,    80,    81,    -1,    -1,    -1,    -1,
      86,    87,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,    -1,   132,   133,    51,    52,
      -1,    -1,    55,   139,   140,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,    -1,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    80,    81,    -1,
      -1,    84,    85,    86,    87,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    98,    99,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,    -1,   132,
     133,    51,    52,    -1,    -1,    55,   139,   140,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
      80,    81,    -1,    -1,    84,    85,    86,    87,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    98,    99,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,    -1,   132,   133,    51,    52,    -1,    -1,    55,   139,
     140,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,    -1,    80,    81,    -1,    -1,    84,    85,    86,
      87,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    98,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,    -1,   132,   133,    51,    52,    -1,
      -1,    55,   139,   140,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,    80,    81,    -1,    -1,
      84,    85,    86,    87,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    98,    99,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,    -1,   132,   133,
      51,    52,    -1,    -1,    55,   139,   140,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,    80,
      81,    -1,    -1,    84,    85,    86,    87,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    98,    99,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
      -1,   132,   133,    51,    52,    -1,    -1,    55,   139,   140,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,    80,    81,    -1,    -1,    84,    85,    86,    87,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      98,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,    -1,   132,   133,    51,    52,    -1,    -1,
      55,   139,   140,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,    80,    81,    -1,    -1,    84,
      85,    86,    87,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    98,    99,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,    -1,   132,   133,    51,
      52,    -1,    -1,    55,   139,   140,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,    80,    81,
      -1,    -1,    84,    85,    86,    87,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    98,    99,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,    -1,
     132,   133,    51,    52,    -1,    -1,    55,   139,   140,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    80,    81,    -1,    -1,    84,    85,    86,    87,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    98,
      99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,    -1,   132,   133,    51,    52,    -1,    -1,    55,
     139,   140,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,    80,    81,    -1,    -1,    84,    85,
      86,    87,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    98,    99,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,    -1,   132,   133,    51,    52,
      -1,    -1,    55,   139,   140,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    80,    81,    -1,
      -1,    84,    85,    86,    87,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    98,    99,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,    -1,   132,
     133,    51,    52,    -1,    -1,    55,   139,   140,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
      80,    81,    -1,    -1,    84,    85,    86,    87,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    98,    99,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,    -1,   132,   133,    51,    52,    -1,    -1,    55,   139,
     140,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,    -1,    80,    81,    -1,    -1,    84,    85,    86,
      87,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    98,    99,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    -1,    -1,    86,    87,
      -1,    -1,    -1,    -1,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,    -1,   132,   133,    -1,    -1,    -1,
      -1,    -1,   139,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   119,    -1,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    -1,   145,    86,    87,
      -1,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    -1,    -1,    86,    87,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   119,    -1,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,    -1,    -1,    -1,    -1,    -1,    -1,   119,
     138,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    -1,    -1,    86,    87,    -1,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      -1,    -1,    86,    87,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   119,    -1,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,    -1,
      -1,    -1,    -1,    -1,    -1,   119,   138,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   138,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    -1,    -1,
      86,    87,    -1,    -1,    -1,    91,    71,    72,    73,    74,
      75,    76,    77,    78,    -1,    80,    81,    -1,    -1,    -1,
      -1,    86,    87,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   119,    -1,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   147,   148,     0,     1,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    19,    21,    22,    23,    24,
      30,    31,    32,    33,    34,    35,    36,    39,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      58,    59,    60,    63,    66,    67,    69,    70,    89,    92,
      93,    95,    96,    98,   101,   103,   104,   105,   106,   107,
     108,   111,   131,   132,   133,   149,   150,   151,   156,   158,
     160,   162,   163,   166,   167,   169,   170,   171,   173,   174,
     183,   197,   218,   239,   240,   250,   251,   252,   256,   257,
     258,   264,   265,   266,   268,   269,   270,   271,   272,   273,
     307,   321,   151,    21,    22,    30,    31,    32,    39,    51,
      55,    86,    89,    92,   131,   175,   176,   197,   218,   270,
     273,   307,   176,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    45,    46,    47,
      48,    49,    50,    51,    52,    55,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    80,    81,    84,    85,    86,
      87,    98,    99,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   132,   133,   139,   140,   177,   181,   182,
     272,   302,   198,    89,   160,   161,   174,   218,   270,   271,
     273,   161,   204,   206,    89,   167,   174,   218,   223,   270,
     273,    33,    34,    35,    36,    48,    49,    50,    51,    55,
     103,   177,   178,   179,   266,   112,   115,   116,   143,   145,
     161,   260,   261,   262,   313,   318,   319,   320,    51,    98,
      99,   100,   132,   166,   183,   189,   192,   195,   252,   305,
     306,   189,   189,   140,   186,   187,   190,   191,   321,   186,
     190,   140,   314,   319,   178,   152,   135,   183,   218,   183,
      55,     1,    92,   154,   155,   156,   168,   169,   321,   199,
     201,   184,   195,   305,   321,   183,   304,   305,   321,    89,
     138,   173,   218,   270,   273,   202,    53,    54,    56,    63,
     107,   177,   267,    62,    64,    65,   113,   114,   253,   254,
      63,   253,    63,   253,    63,   253,    61,   253,    58,    59,
     162,   183,   183,   313,   320,    40,    41,    42,    43,    44,
      37,    38,    28,   237,   118,   138,    92,    98,   170,   118,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    86,    87,   119,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,    88,   102,   137,   144,
     311,    88,   311,   312,    26,   135,   241,   252,    90,    90,
     186,   190,   241,   160,    51,    55,   175,    58,    59,   122,
     274,    88,   137,   311,   213,   303,   214,    88,   144,   310,
     153,   154,    55,    16,   219,   318,   118,    88,   137,   311,
      90,    90,   219,   161,   161,    55,    88,   137,   311,    25,
     107,   138,   263,   313,   112,   262,    20,   244,   318,    57,
     183,   183,   183,    91,   138,   193,   194,   321,    57,   138,
     193,   194,   188,   189,   195,   305,   321,   189,   160,   314,
     315,   160,   157,   135,   154,    88,   311,    90,   156,   168,
     141,   313,   320,   315,   156,   315,   142,   194,   317,   319,
     194,   317,   136,   317,    55,   170,   171,   172,   138,    88,
     137,   311,    51,    53,    54,    55,    56,    71,    92,    98,
      99,   100,   125,   128,   140,   235,   277,   278,   281,   282,
     283,   284,   286,   287,   288,   289,   291,   292,   293,   296,
     297,   298,   299,   300,    63,   253,   255,   259,   260,    62,
     254,    63,    63,    63,    61,    71,    71,   151,   161,   161,
     161,   161,   156,   160,   160,   238,    98,   162,   183,   195,
     196,   168,   138,   173,   138,   158,   159,   162,   174,   183,
     185,   196,   218,   273,   183,   183,   183,   183,   183,   183,
     183,   183,   183,   183,   183,   183,   183,   183,   183,   183,
     183,   183,   183,   183,   183,   183,   183,   183,   183,   183,
      51,    52,    55,   181,   186,   308,   309,   188,    51,    52,
      55,   181,   186,   308,    51,    55,   308,   243,   242,   159,
     183,   185,   159,   185,    97,   164,   211,   275,   210,    51,
      55,   175,   308,   188,   308,   153,   160,   215,   216,    15,
      13,   246,   321,   154,    16,    51,    55,   188,    51,    55,
     154,    27,   220,   318,   220,    51,    55,   188,    51,    55,
     208,   180,   154,   244,   183,   195,    15,   183,   183,   259,
      98,   183,   192,   305,   183,   306,   315,   138,   194,   138,
     315,   141,   178,   149,   136,   185,   315,   156,   200,   305,
     170,   172,    51,    55,   188,    51,    55,    57,   118,   290,
     286,   203,   183,   138,   301,   321,    51,   138,   301,   138,
     285,   183,   138,   285,    51,   138,   285,    51,    63,   154,
     260,   183,   183,    79,   123,   229,   230,   321,   183,   194,
     315,   172,   138,    44,   118,    44,    88,   137,   311,   314,
      90,    90,   186,   190,   314,   316,    90,    90,   187,   190,
     187,   190,   229,   229,   165,   318,   161,   153,   316,    15,
     315,   140,   276,   286,   177,   183,   196,   247,   321,    18,
     222,   321,    17,   221,   222,    90,    90,   316,    90,    90,
     222,   205,   207,   316,   161,   178,   136,    15,   194,   219,
     183,   193,   305,   136,   315,   317,   316,    51,    98,   224,
     291,   232,   314,    29,   110,   236,    51,   278,   283,   300,
     284,   289,   296,   298,   291,   293,   298,    51,   291,   136,
     226,   228,   231,   277,   279,   280,   283,   291,   292,   294,
     295,   298,   300,   153,    98,   183,   172,   156,   183,    51,
      55,   188,    51,    55,    57,   120,   159,   185,   162,   185,
     164,   142,    90,   159,   185,   159,   185,   164,   241,   237,
     153,   154,   229,   212,   318,    15,   286,   153,   318,   217,
      91,   248,   321,   154,    14,   249,   321,   161,    15,    90,
      15,   154,   154,   220,   183,   154,   138,   138,   288,   315,
     138,   141,   143,   153,   154,   301,   138,   285,   138,   285,
     138,   285,   138,   285,   285,   232,   232,    89,   218,   138,
     301,   301,   138,   227,   218,   138,   227,   138,   227,    15,
     183,   316,   183,   183,   159,   185,    15,   136,   154,   153,
     315,    15,   276,    89,   174,   218,   270,   273,   219,   154,
     219,    15,    15,   209,   222,   244,   245,   225,   138,    98,
      51,   233,   234,   287,    15,   136,   291,   298,   291,   291,
     123,   123,    55,    88,   279,   283,   138,   226,   227,   295,
     298,   291,   294,   298,   291,   136,    15,   153,    55,    88,
     137,   311,   154,   154,   154,   291,   291,   138,   288,   138,
     314,   285,   138,   285,   285,   285,    51,    55,   301,   138,
     227,   138,   227,   138,   227,   138,   227,   227,    15,    51,
      55,   188,    51,    55,   246,   221,    15,   138,   291,   138,
     234,   291,   291,   298,   291,   291,   316,   291,   285,   227,
     138,   227,   227,   227,   291,   227
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (p, YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */
#ifdef YYLEX_PARAM
# define YYLEX yylex (&yylval, YYLEX_PARAM)
#else
# define YYLEX yylex (&yylval, p)
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value, p); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, parser_state *p)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, p)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    parser_state *p;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
  YYUSE (p);
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
        break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, parser_state *p)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, p)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    parser_state *p;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep, p);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule, parser_state *p)
#else
static void
yy_reduce_print (yyvsp, yyrule, p)
    YYSTYPE *yyvsp;
    int yyrule;
    parser_state *p;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       , p);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule, p); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, parser_state *p)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, p)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    parser_state *p;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (p);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
        break;
    }
}




/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (parser_state *p)
#else
int
yyparse (p)
    parser_state *p;
#endif
#endif
{
/* The lookahead symbol.  */
int yychar;


#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
static YYSTYPE yyval_default;
# define YY_INITIAL_VALUE(Value) = Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

    /* Number of syntax errors so far.  */
    int yynerrs;

    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
/* Line 1792 of yacc.c  */
#line 1461 "D:\\Desktop\\parse.y"
    {
                      p->lstate = EXPR_BEG;
                      if (!p->locals) p->locals = cons(0,0);
                    }
    break;

  case 3:
/* Line 1792 of yacc.c  */
#line 1466 "D:\\Desktop\\parse.y"
    {
                      p->tree = new_scope(p, (yyvsp[(2) - (2)].nd));
                      NODE_LINENO(p->tree, (yyvsp[(2) - (2)].nd));
                    }
    break;

  case 4:
/* Line 1792 of yacc.c  */
#line 1473 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = (yyvsp[(1) - (2)].nd);
                    }
    break;

  case 5:
/* Line 1792 of yacc.c  */
#line 1479 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_begin(p, 0);
                    }
    break;

  case 6:
/* Line 1792 of yacc.c  */
#line 1483 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_begin(p, (yyvsp[(1) - (1)].nd));
                      NODE_LINENO((yyval.nd), (yyvsp[(1) - (1)].nd));
                    }
    break;

  case 7:
/* Line 1792 of yacc.c  */
#line 1488 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = push((yyvsp[(1) - (3)].nd), newline_node((yyvsp[(3) - (3)].nd)));
                    }
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 1492 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_begin(p, 0);
                    }
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 1499 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = local_switch(p);
                    }
    break;

  case 11:
/* Line 1792 of yacc.c  */
#line 1503 "D:\\Desktop\\parse.y"
    {
                      yyerror(p, "BEGIN not supported");
                      local_resume(p, (yyvsp[(2) - (5)].nd));
                      (yyval.nd) = 0;
                    }
    break;

  case 12:
/* Line 1792 of yacc.c  */
#line 1514 "D:\\Desktop\\parse.y"
    {
                      if ((yyvsp[(2) - (4)].nd)) {
                        (yyval.nd) = new_rescue(p, (yyvsp[(1) - (4)].nd), (yyvsp[(2) - (4)].nd), (yyvsp[(3) - (4)].nd));
                        NODE_LINENO((yyval.nd), (yyvsp[(1) - (4)].nd));
                      }
                      else if ((yyvsp[(3) - (4)].nd)) {
                        yywarn(p, "else without rescue is useless");
                        (yyval.nd) = push((yyvsp[(1) - (4)].nd), (yyvsp[(3) - (4)].nd));
                      }
                      else {
                        (yyval.nd) = (yyvsp[(1) - (4)].nd);
                      }
                      if ((yyvsp[(4) - (4)].nd)) {
                        if ((yyval.nd)) {
                          (yyval.nd) = new_ensure(p, (yyval.nd), (yyvsp[(4) - (4)].nd));
                        }
                        else {
                          (yyval.nd) = push((yyvsp[(4) - (4)].nd), new_nil(p));
                        }
                      }
                    }
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 1538 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = (yyvsp[(1) - (2)].nd);
                    }
    break;

  case 14:
/* Line 1792 of yacc.c  */
#line 1544 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_begin(p, 0);
                    }
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 1548 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_begin(p, (yyvsp[(1) - (1)].nd));
                      NODE_LINENO((yyval.nd), (yyvsp[(1) - (1)].nd));
                    }
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 1553 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = push((yyvsp[(1) - (3)].nd), newline_node((yyvsp[(3) - (3)].nd)));
                    }
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 1557 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_begin(p, (yyvsp[(2) - (2)].nd));
                    }
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 1562 "D:\\Desktop\\parse.y"
    {p->lstate = EXPR_FNAME;}
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 1563 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_alias(p, (yyvsp[(2) - (4)].id), (yyvsp[(4) - (4)].id));
                    }
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 1567 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = (yyvsp[(2) - (2)].nd);
                    }
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 1571 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_if(p, cond((yyvsp[(3) - (3)].nd)), (yyvsp[(1) - (3)].nd), 0);
                    }
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 1575 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_unless(p, cond((yyvsp[(3) - (3)].nd)), (yyvsp[(1) - (3)].nd), 0);
                    }
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 1579 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_while(p, cond((yyvsp[(3) - (3)].nd)), (yyvsp[(1) - (3)].nd));
                    }
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 1583 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_until(p, cond((yyvsp[(3) - (3)].nd)), (yyvsp[(1) - (3)].nd));
                    }
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 1587 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_mod_rescue(p, (yyvsp[(1) - (3)].nd), (yyvsp[(3) - (3)].nd));
                    }
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 1591 "D:\\Desktop\\parse.y"
    {
                      yyerror(p, "END not supported");
                      (yyval.nd) = new_postexe(p, (yyvsp[(3) - (4)].nd));
                    }
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 1597 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_masgn(p, (yyvsp[(1) - (3)].nd), (yyvsp[(3) - (3)].nd));
                    }
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 1601 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_asgn(p, (yyvsp[(1) - (3)].nd), new_array(p, (yyvsp[(3) - (3)].nd)));
                    }
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 1605 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_masgn(p, (yyvsp[(1) - (3)].nd), (yyvsp[(3) - (3)].nd));
                    }
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 1609 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_masgn(p, (yyvsp[(1) - (3)].nd), new_array(p, (yyvsp[(3) - (3)].nd)));
                    }
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 1616 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_asgn(p, (yyvsp[(1) - (3)].nd), (yyvsp[(3) - (3)].nd));
                    }
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 1620 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_op_asgn(p, (yyvsp[(1) - (3)].nd), (yyvsp[(2) - (3)].id), (yyvsp[(3) - (3)].nd));
                    }
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 1624 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_op_asgn(p, new_call(p, (yyvsp[(1) - (6)].nd), intern("[]",2), (yyvsp[(3) - (6)].nd), '.'), (yyvsp[(5) - (6)].id), (yyvsp[(6) - (6)].nd));
                    }
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 1628 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_op_asgn(p, new_call(p, (yyvsp[(1) - (5)].nd), (yyvsp[(3) - (5)].id), 0, (yyvsp[(2) - (5)].num)), (yyvsp[(4) - (5)].id), (yyvsp[(5) - (5)].nd));
                    }
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 1632 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_op_asgn(p, new_call(p, (yyvsp[(1) - (5)].nd), (yyvsp[(3) - (5)].id), 0, (yyvsp[(2) - (5)].num)), (yyvsp[(4) - (5)].id), (yyvsp[(5) - (5)].nd));
                    }
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 1636 "D:\\Desktop\\parse.y"
    {
                      yyerror(p, "constant re-assignment");
                      (yyval.nd) = 0;
                    }
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 1641 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_op_asgn(p, new_call(p, (yyvsp[(1) - (5)].nd), (yyvsp[(3) - (5)].id), 0, tCOLON2), (yyvsp[(4) - (5)].id), (yyvsp[(5) - (5)].nd));
                    }
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 1645 "D:\\Desktop\\parse.y"
    {
                      backref_error(p, (yyvsp[(1) - (3)].nd));
                      (yyval.nd) = new_begin(p, 0);
                    }
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 1653 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_mod_rescue(p, (yyvsp[(1) - (3)].nd), (yyvsp[(3) - (3)].nd));
                    }
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 1662 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_and(p, (yyvsp[(1) - (3)].nd), (yyvsp[(3) - (3)].nd));
                    }
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 1666 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_or(p, (yyvsp[(1) - (3)].nd), (yyvsp[(3) - (3)].nd));
                    }
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 1670 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = call_uni_op(p, cond((yyvsp[(3) - (3)].nd)), "!");
                    }
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 1674 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = call_uni_op(p, cond((yyvsp[(2) - (2)].nd)), "!");
                    }
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 1681 "D:\\Desktop\\parse.y"
    {
                      if (!(yyvsp[(1) - (1)].nd)) (yyval.nd) = new_nil(p);
                      else {
                        (yyval.nd) = (yyvsp[(1) - (1)].nd);
                      }
                    }
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 1695 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_call(p, (yyvsp[(1) - (4)].nd), (yyvsp[(3) - (4)].id), (yyvsp[(4) - (4)].nd), (yyvsp[(2) - (4)].num));
                    }
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 1701 "D:\\Desktop\\parse.y"
    {
                      local_nest(p);
                    }
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 1707 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_block(p, (yyvsp[(3) - (5)].nd), (yyvsp[(4) - (5)].nd));
                      local_unnest(p);
                    }
    break;

  case 57:
/* Line 1792 of yacc.c  */
#line 1714 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_fcall(p, (yyvsp[(1) - (2)].id), (yyvsp[(2) - (2)].nd));
                    }
    break;

  case 58:
/* Line 1792 of yacc.c  */
#line 1718 "D:\\Desktop\\parse.y"
    {
                      args_with_block(p, (yyvsp[(2) - (3)].nd), (yyvsp[(3) - (3)].nd));
                      (yyval.nd) = new_fcall(p, (yyvsp[(1) - (3)].id), (yyvsp[(2) - (3)].nd));
                    }
    break;

  case 59:
/* Line 1792 of yacc.c  */
#line 1723 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_call(p, (yyvsp[(1) - (4)].nd), (yyvsp[(3) - (4)].id), (yyvsp[(4) - (4)].nd), (yyvsp[(2) - (4)].num));
                    }
    break;

  case 60:
/* Line 1792 of yacc.c  */
#line 1727 "D:\\Desktop\\parse.y"
    {
                      args_with_block(p, (yyvsp[(4) - (5)].nd), (yyvsp[(5) - (5)].nd));
                      (yyval.nd) = new_call(p, (yyvsp[(1) - (5)].nd), (yyvsp[(3) - (5)].id), (yyvsp[(4) - (5)].nd), (yyvsp[(2) - (5)].num));
                   }
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 1732 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_call(p, (yyvsp[(1) - (4)].nd), (yyvsp[(3) - (4)].id), (yyvsp[(4) - (4)].nd), tCOLON2);
                    }
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 1736 "D:\\Desktop\\parse.y"
    {
                      args_with_block(p, (yyvsp[(4) - (5)].nd), (yyvsp[(5) - (5)].nd));
                      (yyval.nd) = new_call(p, (yyvsp[(1) - (5)].nd), (yyvsp[(3) - (5)].id), (yyvsp[(4) - (5)].nd), tCOLON2);
                    }
    break;

  case 63:
/* Line 1792 of yacc.c  */
#line 1741 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_super(p, (yyvsp[(2) - (2)].nd));
                    }
    break;

  case 64:
/* Line 1792 of yacc.c  */
#line 1745 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_yield(p, (yyvsp[(2) - (2)].nd));
                    }
    break;

  case 65:
/* Line 1792 of yacc.c  */
#line 1749 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_return(p, ret_args(p, (yyvsp[(2) - (2)].nd)));
                    }
    break;

  case 66:
/* Line 1792 of yacc.c  */
#line 1753 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_break(p, ret_args(p, (yyvsp[(2) - (2)].nd)));
                    }
    break;

  case 67:
/* Line 1792 of yacc.c  */
#line 1757 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_next(p, ret_args(p, (yyvsp[(2) - (2)].nd)));
                    }
    break;

  case 68:
/* Line 1792 of yacc.c  */
#line 1763 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = (yyvsp[(1) - (1)].nd);
                    }
    break;

  case 69:
/* Line 1792 of yacc.c  */
#line 1767 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = (yyvsp[(2) - (3)].nd);
                    }
    break;

  case 71:
/* Line 1792 of yacc.c  */
#line 1774 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = (yyvsp[(2) - (3)].nd);
                    }
    break;

  case 72:
/* Line 1792 of yacc.c  */
#line 1780 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = list1((yyvsp[(1) - (1)].nd));
                    }
    break;

  case 73:
/* Line 1792 of yacc.c  */
#line 1784 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = list1(push((yyvsp[(1) - (2)].nd),(yyvsp[(2) - (2)].nd)));
                    }
    break;

  case 74:
/* Line 1792 of yacc.c  */
#line 1788 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = list2((yyvsp[(1) - (3)].nd), (yyvsp[(3) - (3)].nd));
                    }
    break;

  case 75:
/* Line 1792 of yacc.c  */
#line 1792 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = list3((yyvsp[(1) - (5)].nd), (yyvsp[(3) - (5)].nd), (yyvsp[(5) - (5)].nd));
                    }
    break;

  case 76:
/* Line 1792 of yacc.c  */
#line 1796 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = list2((yyvsp[(1) - (2)].nd), new_nil(p));
                    }
    break;

  case 77:
/* Line 1792 of yacc.c  */
#line 1800 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = list3((yyvsp[(1) - (4)].nd), new_nil(p), (yyvsp[(4) - (4)].nd));
                    }
    break;

  case 78:
/* Line 1792 of yacc.c  */
#line 1804 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = list2(0, (yyvsp[(2) - (2)].nd));
                    }
    break;

  case 79:
/* Line 1792 of yacc.c  */
#line 1808 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = list3(0, (yyvsp[(2) - (4)].nd), (yyvsp[(4) - (4)].nd));
                    }
    break;

  case 80:
/* Line 1792 of yacc.c  */
#line 1812 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = list2(0, new_nil(p));
                    }
    break;

  case 81:
/* Line 1792 of yacc.c  */
#line 1816 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = list3(0, new_nil(p), (yyvsp[(3) - (3)].nd));
                    }
    break;

  case 83:
/* Line 1792 of yacc.c  */
#line 1823 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_masgn(p, (yyvsp[(2) - (3)].nd), NULL);
                    }
    break;

  case 84:
/* Line 1792 of yacc.c  */
#line 1829 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = list1((yyvsp[(1) - (2)].nd));
                    }
    break;

  case 85:
/* Line 1792 of yacc.c  */
#line 1833 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = push((yyvsp[(1) - (3)].nd), (yyvsp[(2) - (3)].nd));
                    }
    break;

  case 86:
/* Line 1792 of yacc.c  */
#line 1839 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = list1((yyvsp[(1) - (1)].nd));
                    }
    break;

  case 87:
/* Line 1792 of yacc.c  */
#line 1843 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = push((yyvsp[(1) - (2)].nd), (yyvsp[(2) - (2)].nd));
                    }
    break;

  case 88:
/* Line 1792 of yacc.c  */
#line 1849 "D:\\Desktop\\parse.y"
    {
                      assignable(p, (yyvsp[(1) - (1)].nd));
                    }
    break;

  case 89:
/* Line 1792 of yacc.c  */
#line 1853 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_call(p, (yyvsp[(1) - (4)].nd), intern("[]",2), (yyvsp[(3) - (4)].nd), '.');
                    }
    break;

  case 90:
/* Line 1792 of yacc.c  */
#line 1857 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_call(p, (yyvsp[(1) - (3)].nd), (yyvsp[(3) - (3)].id), 0, (yyvsp[(2) - (3)].num));
                    }
    break;

  case 91:
/* Line 1792 of yacc.c  */
#line 1861 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_call(p, (yyvsp[(1) - (3)].nd), (yyvsp[(3) - (3)].id), 0, tCOLON2);
                    }
    break;

  case 92:
/* Line 1792 of yacc.c  */
#line 1865 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_call(p, (yyvsp[(1) - (3)].nd), (yyvsp[(3) - (3)].id), 0, (yyvsp[(2) - (3)].num));
                    }
    break;

  case 93:
/* Line 1792 of yacc.c  */
#line 1869 "D:\\Desktop\\parse.y"
    {
                      if (p->in_def || p->in_single)
                        yyerror(p, "dynamic constant assignment");
                      (yyval.nd) = new_colon2(p, (yyvsp[(1) - (3)].nd), (yyvsp[(3) - (3)].id));
                    }
    break;

  case 94:
/* Line 1792 of yacc.c  */
#line 1875 "D:\\Desktop\\parse.y"
    {
                      if (p->in_def || p->in_single)
                        yyerror(p, "dynamic constant assignment");
                      (yyval.nd) = new_colon3(p, (yyvsp[(2) - (2)].id));
                    }
    break;

  case 95:
/* Line 1792 of yacc.c  */
#line 1881 "D:\\Desktop\\parse.y"
    {
                      backref_error(p, (yyvsp[(1) - (1)].nd));
                      (yyval.nd) = 0;
                    }
    break;

  case 96:
/* Line 1792 of yacc.c  */
#line 1888 "D:\\Desktop\\parse.y"
    {
                      assignable(p, (yyvsp[(1) - (1)].nd));
                    }
    break;

  case 97:
/* Line 1792 of yacc.c  */
#line 1892 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_call(p, (yyvsp[(1) - (4)].nd), intern("[]",2), (yyvsp[(3) - (4)].nd), '.');
                    }
    break;

  case 98:
/* Line 1792 of yacc.c  */
#line 1896 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_call(p, (yyvsp[(1) - (3)].nd), (yyvsp[(3) - (3)].id), 0, (yyvsp[(2) - (3)].num));
                    }
    break;

  case 99:
/* Line 1792 of yacc.c  */
#line 1900 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_call(p, (yyvsp[(1) - (3)].nd), (yyvsp[(3) - (3)].id), 0, tCOLON2);
                    }
    break;

  case 100:
/* Line 1792 of yacc.c  */
#line 1904 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_call(p, (yyvsp[(1) - (3)].nd), (yyvsp[(3) - (3)].id), 0, (yyvsp[(2) - (3)].num));
                    }
    break;

  case 101:
/* Line 1792 of yacc.c  */
#line 1908 "D:\\Desktop\\parse.y"
    {
                      if (p->in_def || p->in_single)
                        yyerror(p, "dynamic constant assignment");
                      (yyval.nd) = new_colon2(p, (yyvsp[(1) - (3)].nd), (yyvsp[(3) - (3)].id));
                    }
    break;

  case 102:
/* Line 1792 of yacc.c  */
#line 1914 "D:\\Desktop\\parse.y"
    {
                      if (p->in_def || p->in_single)
                        yyerror(p, "dynamic constant assignment");
                      (yyval.nd) = new_colon3(p, (yyvsp[(2) - (2)].id));
                    }
    break;

  case 103:
/* Line 1792 of yacc.c  */
#line 1920 "D:\\Desktop\\parse.y"
    {
                      backref_error(p, (yyvsp[(1) - (1)].nd));
                      (yyval.nd) = 0;
                    }
    break;

  case 104:
/* Line 1792 of yacc.c  */
#line 1927 "D:\\Desktop\\parse.y"
    {
                      yyerror(p, "class/module name must be CONSTANT");
                    }
    break;

  case 106:
/* Line 1792 of yacc.c  */
#line 1934 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = cons((node*)1, nsym((yyvsp[(2) - (2)].id)));
                    }
    break;

  case 107:
/* Line 1792 of yacc.c  */
#line 1938 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = cons((node*)0, nsym((yyvsp[(1) - (1)].id)));
                    }
    break;

  case 108:
/* Line 1792 of yacc.c  */
#line 1942 "D:\\Desktop\\parse.y"
    {
                      void_expr_error(p, (yyvsp[(1) - (3)].nd));
                      (yyval.nd) = cons((yyvsp[(1) - (3)].nd), nsym((yyvsp[(3) - (3)].id)));
                    }
    break;

  case 112:
/* Line 1792 of yacc.c  */
#line 1952 "D:\\Desktop\\parse.y"
    {
                      p->lstate = EXPR_ENDFN;
                      (yyval.id) = (yyvsp[(1) - (1)].id);
                    }
    break;

  case 113:
/* Line 1792 of yacc.c  */
#line 1957 "D:\\Desktop\\parse.y"
    {
                      p->lstate = EXPR_ENDFN;
                      (yyval.id) = (yyvsp[(1) - (1)].id);
                    }
    break;

  case 116:
/* Line 1792 of yacc.c  */
#line 1968 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_undef(p, (yyvsp[(1) - (1)].id));
                    }
    break;

  case 117:
/* Line 1792 of yacc.c  */
#line 1971 "D:\\Desktop\\parse.y"
    {p->lstate = EXPR_FNAME;}
    break;

  case 118:
/* Line 1792 of yacc.c  */
#line 1972 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = push((yyvsp[(1) - (4)].nd), nsym((yyvsp[(4) - (4)].id)));
                    }
    break;

  case 119:
/* Line 1792 of yacc.c  */
#line 1977 "D:\\Desktop\\parse.y"
    { (yyval.id) = intern_c('|');   }
    break;

  case 120:
/* Line 1792 of yacc.c  */
#line 1978 "D:\\Desktop\\parse.y"
    { (yyval.id) = intern_c('^');   }
    break;

  case 121:
/* Line 1792 of yacc.c  */
#line 1979 "D:\\Desktop\\parse.y"
    { (yyval.id) = intern_c('&');   }
    break;

  case 122:
/* Line 1792 of yacc.c  */
#line 1980 "D:\\Desktop\\parse.y"
    { (yyval.id) = intern("<=>",3); }
    break;

  case 123:
/* Line 1792 of yacc.c  */
#line 1981 "D:\\Desktop\\parse.y"
    { (yyval.id) = intern("==",2);  }
    break;

  case 124:
/* Line 1792 of yacc.c  */
#line 1982 "D:\\Desktop\\parse.y"
    { (yyval.id) = intern("===",3); }
    break;

  case 125:
/* Line 1792 of yacc.c  */
#line 1983 "D:\\Desktop\\parse.y"
    { (yyval.id) = intern("=~",2);  }
    break;

  case 126:
/* Line 1792 of yacc.c  */
#line 1984 "D:\\Desktop\\parse.y"
    { (yyval.id) = intern("!~",2);  }
    break;

  case 127:
/* Line 1792 of yacc.c  */
#line 1985 "D:\\Desktop\\parse.y"
    { (yyval.id) = intern_c('>');   }
    break;

  case 128:
/* Line 1792 of yacc.c  */
#line 1986 "D:\\Desktop\\parse.y"
    { (yyval.id) = intern(">=",2);  }
    break;

  case 129:
/* Line 1792 of yacc.c  */
#line 1987 "D:\\Desktop\\parse.y"
    { (yyval.id) = intern_c('<');   }
    break;

  case 130:
/* Line 1792 of yacc.c  */
#line 1988 "D:\\Desktop\\parse.y"
    { (yyval.id) = intern("<=",2);  }
    break;

  case 131:
/* Line 1792 of yacc.c  */
#line 1989 "D:\\Desktop\\parse.y"
    { (yyval.id) = intern("!=",2);  }
    break;

  case 132:
/* Line 1792 of yacc.c  */
#line 1990 "D:\\Desktop\\parse.y"
    { (yyval.id) = intern("<<",2);  }
    break;

  case 133:
/* Line 1792 of yacc.c  */
#line 1991 "D:\\Desktop\\parse.y"
    { (yyval.id) = intern(">>",2);  }
    break;

  case 134:
/* Line 1792 of yacc.c  */
#line 1992 "D:\\Desktop\\parse.y"
    { (yyval.id) = intern_c('+');   }
    break;

  case 135:
/* Line 1792 of yacc.c  */
#line 1993 "D:\\Desktop\\parse.y"
    { (yyval.id) = intern_c('-');   }
    break;

  case 136:
/* Line 1792 of yacc.c  */
#line 1994 "D:\\Desktop\\parse.y"
    { (yyval.id) = intern_c('*');   }
    break;

  case 137:
/* Line 1792 of yacc.c  */
#line 1995 "D:\\Desktop\\parse.y"
    { (yyval.id) = intern_c('*');   }
    break;

  case 138:
/* Line 1792 of yacc.c  */
#line 1996 "D:\\Desktop\\parse.y"
    { (yyval.id) = intern_c('/');   }
    break;

  case 139:
/* Line 1792 of yacc.c  */
#line 1997 "D:\\Desktop\\parse.y"
    { (yyval.id) = intern_c('%');   }
    break;

  case 140:
/* Line 1792 of yacc.c  */
#line 1998 "D:\\Desktop\\parse.y"
    { (yyval.id) = intern("**",2);  }
    break;

  case 141:
/* Line 1792 of yacc.c  */
#line 1999 "D:\\Desktop\\parse.y"
    { (yyval.id) = intern("**",2);  }
    break;

  case 142:
/* Line 1792 of yacc.c  */
#line 2000 "D:\\Desktop\\parse.y"
    { (yyval.id) = intern_c('!');   }
    break;

  case 143:
/* Line 1792 of yacc.c  */
#line 2001 "D:\\Desktop\\parse.y"
    { (yyval.id) = intern_c('~');   }
    break;

  case 144:
/* Line 1792 of yacc.c  */
#line 2002 "D:\\Desktop\\parse.y"
    { (yyval.id) = intern("+@",2);  }
    break;

  case 145:
/* Line 1792 of yacc.c  */
#line 2003 "D:\\Desktop\\parse.y"
    { (yyval.id) = intern("-@",2);  }
    break;

  case 146:
/* Line 1792 of yacc.c  */
#line 2004 "D:\\Desktop\\parse.y"
    { (yyval.id) = intern("[]",2);  }
    break;

  case 147:
/* Line 1792 of yacc.c  */
#line 2005 "D:\\Desktop\\parse.y"
    { (yyval.id) = intern("[]=",3); }
    break;

  case 148:
/* Line 1792 of yacc.c  */
#line 2006 "D:\\Desktop\\parse.y"
    { (yyval.id) = intern_c('`');   }
    break;

  case 189:
/* Line 1792 of yacc.c  */
#line 2024 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_asgn(p, (yyvsp[(1) - (3)].nd), (yyvsp[(3) - (3)].nd));
                    }
    break;

  case 190:
/* Line 1792 of yacc.c  */
#line 2028 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_op_asgn(p, (yyvsp[(1) - (3)].nd), (yyvsp[(2) - (3)].id), (yyvsp[(3) - (3)].nd));
                    }
    break;

  case 191:
/* Line 1792 of yacc.c  */
#line 2032 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_op_asgn(p, new_call(p, (yyvsp[(1) - (6)].nd), intern("[]",2), (yyvsp[(3) - (6)].nd), '.'), (yyvsp[(5) - (6)].id), (yyvsp[(6) - (6)].nd));
                    }
    break;

  case 192:
/* Line 1792 of yacc.c  */
#line 2036 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_op_asgn(p, new_call(p, (yyvsp[(1) - (5)].nd), (yyvsp[(3) - (5)].id), 0, (yyvsp[(2) - (5)].num)), (yyvsp[(4) - (5)].id), (yyvsp[(5) - (5)].nd));
                    }
    break;

  case 193:
/* Line 1792 of yacc.c  */
#line 2040 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_op_asgn(p, new_call(p, (yyvsp[(1) - (5)].nd), (yyvsp[(3) - (5)].id), 0, (yyvsp[(2) - (5)].num)), (yyvsp[(4) - (5)].id), (yyvsp[(5) - (5)].nd));
                    }
    break;

  case 194:
/* Line 1792 of yacc.c  */
#line 2044 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_op_asgn(p, new_call(p, (yyvsp[(1) - (5)].nd), (yyvsp[(3) - (5)].id), 0, tCOLON2), (yyvsp[(4) - (5)].id), (yyvsp[(5) - (5)].nd));
                    }
    break;

  case 195:
/* Line 1792 of yacc.c  */
#line 2048 "D:\\Desktop\\parse.y"
    {
                      yyerror(p, "constant re-assignment");
                      (yyval.nd) = new_begin(p, 0);
                    }
    break;

  case 196:
/* Line 1792 of yacc.c  */
#line 2053 "D:\\Desktop\\parse.y"
    {
                      yyerror(p, "constant re-assignment");
                      (yyval.nd) = new_begin(p, 0);
                    }
    break;

  case 197:
/* Line 1792 of yacc.c  */
#line 2058 "D:\\Desktop\\parse.y"
    {
                      backref_error(p, (yyvsp[(1) - (3)].nd));
                      (yyval.nd) = new_begin(p, 0);
                    }
    break;

  case 198:
/* Line 1792 of yacc.c  */
#line 2063 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_dot2(p, (yyvsp[(1) - (3)].nd), (yyvsp[(3) - (3)].nd));
                    }
    break;

  case 199:
/* Line 1792 of yacc.c  */
#line 2067 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_dot3(p, (yyvsp[(1) - (3)].nd), (yyvsp[(3) - (3)].nd));
                    }
    break;

  case 200:
/* Line 1792 of yacc.c  */
#line 2071 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = call_bin_op(p, (yyvsp[(1) - (3)].nd), "+", (yyvsp[(3) - (3)].nd));
                    }
    break;

  case 201:
/* Line 1792 of yacc.c  */
#line 2075 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = call_bin_op(p, (yyvsp[(1) - (3)].nd), "-", (yyvsp[(3) - (3)].nd));
                    }
    break;

  case 202:
/* Line 1792 of yacc.c  */
#line 2079 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = call_bin_op(p, (yyvsp[(1) - (3)].nd), "*", (yyvsp[(3) - (3)].nd));
                    }
    break;

  case 203:
/* Line 1792 of yacc.c  */
#line 2083 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = call_bin_op(p, (yyvsp[(1) - (3)].nd), "/", (yyvsp[(3) - (3)].nd));
                    }
    break;

  case 204:
/* Line 1792 of yacc.c  */
#line 2087 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = call_bin_op(p, (yyvsp[(1) - (3)].nd), "%", (yyvsp[(3) - (3)].nd));
                    }
    break;

  case 205:
/* Line 1792 of yacc.c  */
#line 2091 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = call_bin_op(p, (yyvsp[(1) - (3)].nd), "**", (yyvsp[(3) - (3)].nd));
                    }
    break;

  case 206:
/* Line 1792 of yacc.c  */
#line 2095 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = call_uni_op(p, call_bin_op(p, (yyvsp[(2) - (4)].nd), "**", (yyvsp[(4) - (4)].nd)), "-@");
                    }
    break;

  case 207:
/* Line 1792 of yacc.c  */
#line 2099 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = call_uni_op(p, call_bin_op(p, (yyvsp[(2) - (4)].nd), "**", (yyvsp[(4) - (4)].nd)), "-@");
                    }
    break;

  case 208:
/* Line 1792 of yacc.c  */
#line 2103 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = call_uni_op(p, (yyvsp[(2) - (2)].nd), "+@");
                    }
    break;

  case 209:
/* Line 1792 of yacc.c  */
#line 2107 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = call_uni_op(p, (yyvsp[(2) - (2)].nd), "-@");
                    }
    break;

  case 210:
/* Line 1792 of yacc.c  */
#line 2111 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = call_bin_op(p, (yyvsp[(1) - (3)].nd), "|", (yyvsp[(3) - (3)].nd));
                    }
    break;

  case 211:
/* Line 1792 of yacc.c  */
#line 2115 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = call_bin_op(p, (yyvsp[(1) - (3)].nd), "^", (yyvsp[(3) - (3)].nd));
                    }
    break;

  case 212:
/* Line 1792 of yacc.c  */
#line 2119 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = call_bin_op(p, (yyvsp[(1) - (3)].nd), "&", (yyvsp[(3) - (3)].nd));
                    }
    break;

  case 213:
/* Line 1792 of yacc.c  */
#line 2123 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = call_bin_op(p, (yyvsp[(1) - (3)].nd), "<=>", (yyvsp[(3) - (3)].nd));
                    }
    break;

  case 214:
/* Line 1792 of yacc.c  */
#line 2127 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = call_bin_op(p, (yyvsp[(1) - (3)].nd), ">", (yyvsp[(3) - (3)].nd));
                    }
    break;

  case 215:
/* Line 1792 of yacc.c  */
#line 2131 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = call_bin_op(p, (yyvsp[(1) - (3)].nd), ">=", (yyvsp[(3) - (3)].nd));
                    }
    break;

  case 216:
/* Line 1792 of yacc.c  */
#line 2135 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = call_bin_op(p, (yyvsp[(1) - (3)].nd), "<", (yyvsp[(3) - (3)].nd));
                    }
    break;

  case 217:
/* Line 1792 of yacc.c  */
#line 2139 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = call_bin_op(p, (yyvsp[(1) - (3)].nd), "<=", (yyvsp[(3) - (3)].nd));
                    }
    break;

  case 218:
/* Line 1792 of yacc.c  */
#line 2143 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = call_bin_op(p, (yyvsp[(1) - (3)].nd), "==", (yyvsp[(3) - (3)].nd));
                    }
    break;

  case 219:
/* Line 1792 of yacc.c  */
#line 2147 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = call_bin_op(p, (yyvsp[(1) - (3)].nd), "===", (yyvsp[(3) - (3)].nd));
                    }
    break;

  case 220:
/* Line 1792 of yacc.c  */
#line 2151 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = call_bin_op(p, (yyvsp[(1) - (3)].nd), "!=", (yyvsp[(3) - (3)].nd));
                    }
    break;

  case 221:
/* Line 1792 of yacc.c  */
#line 2155 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = call_bin_op(p, (yyvsp[(1) - (3)].nd), "=~", (yyvsp[(3) - (3)].nd));
                    }
    break;

  case 222:
/* Line 1792 of yacc.c  */
#line 2159 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = call_bin_op(p, (yyvsp[(1) - (3)].nd), "!~", (yyvsp[(3) - (3)].nd));
                    }
    break;

  case 223:
/* Line 1792 of yacc.c  */
#line 2163 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = call_uni_op(p, cond((yyvsp[(2) - (2)].nd)), "!");
                    }
    break;

  case 224:
/* Line 1792 of yacc.c  */
#line 2167 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = call_uni_op(p, cond((yyvsp[(2) - (2)].nd)), "~");
                    }
    break;

  case 225:
/* Line 1792 of yacc.c  */
#line 2171 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = call_bin_op(p, (yyvsp[(1) - (3)].nd), "<<", (yyvsp[(3) - (3)].nd));
                    }
    break;

  case 226:
/* Line 1792 of yacc.c  */
#line 2175 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = call_bin_op(p, (yyvsp[(1) - (3)].nd), ">>", (yyvsp[(3) - (3)].nd));
                    }
    break;

  case 227:
/* Line 1792 of yacc.c  */
#line 2179 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_and(p, (yyvsp[(1) - (3)].nd), (yyvsp[(3) - (3)].nd));
                    }
    break;

  case 228:
/* Line 1792 of yacc.c  */
#line 2183 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_or(p, (yyvsp[(1) - (3)].nd), (yyvsp[(3) - (3)].nd));
                    }
    break;

  case 229:
/* Line 1792 of yacc.c  */
#line 2187 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_if(p, cond((yyvsp[(1) - (6)].nd)), (yyvsp[(3) - (6)].nd), (yyvsp[(6) - (6)].nd));
                    }
    break;

  case 230:
/* Line 1792 of yacc.c  */
#line 2191 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_if(p, cond((yyvsp[(1) - (6)].nd)), (yyvsp[(3) - (6)].nd), (yyvsp[(6) - (6)].nd));
                    }
    break;

  case 231:
/* Line 1792 of yacc.c  */
#line 2195 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = (yyvsp[(1) - (1)].nd);
                    }
    break;

  case 233:
/* Line 1792 of yacc.c  */
#line 2202 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = (yyvsp[(1) - (2)].nd);
                      NODE_LINENO((yyval.nd), (yyvsp[(1) - (2)].nd));
                    }
    break;

  case 234:
/* Line 1792 of yacc.c  */
#line 2207 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = push((yyvsp[(1) - (4)].nd), new_kw_hash(p, (yyvsp[(3) - (4)].nd)));
                    }
    break;

  case 235:
/* Line 1792 of yacc.c  */
#line 2211 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = cons(new_kw_hash(p, (yyvsp[(1) - (2)].nd)), 0);
                      NODE_LINENO((yyval.nd), (yyvsp[(1) - (2)].nd));
                    }
    break;

  case 236:
/* Line 1792 of yacc.c  */
#line 2218 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = (yyvsp[(1) - (1)].nd);
                    }
    break;

  case 237:
/* Line 1792 of yacc.c  */
#line 2222 "D:\\Desktop\\parse.y"
    {
                      void_expr_error(p, (yyvsp[(1) - (3)].nd));
                      void_expr_error(p, (yyvsp[(3) - (3)].nd));
                      (yyval.nd) = new_mod_rescue(p, (yyvsp[(1) - (3)].nd), (yyvsp[(3) - (3)].nd));
                    }
    break;

  case 238:
/* Line 1792 of yacc.c  */
#line 2230 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = (yyvsp[(2) - (3)].nd);
                    }
    break;

  case 243:
/* Line 1792 of yacc.c  */
#line 2242 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = cons((yyvsp[(1) - (2)].nd),0);
                      NODE_LINENO((yyval.nd), (yyvsp[(1) - (2)].nd));
                    }
    break;

  case 244:
/* Line 1792 of yacc.c  */
#line 2247 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = cons(push((yyvsp[(1) - (4)].nd), new_kw_hash(p, (yyvsp[(3) - (4)].nd))), 0);
                      NODE_LINENO((yyval.nd), (yyvsp[(1) - (4)].nd));
                    }
    break;

  case 245:
/* Line 1792 of yacc.c  */
#line 2252 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = cons(list1(new_kw_hash(p, (yyvsp[(1) - (2)].nd))), 0);
                      NODE_LINENO((yyval.nd), (yyvsp[(1) - (2)].nd));
                    }
    break;

  case 246:
/* Line 1792 of yacc.c  */
#line 2259 "D:\\Desktop\\parse.y"
    {
                      void_expr_error(p, (yyvsp[(1) - (1)].nd));
                      (yyval.nd) = cons(list1((yyvsp[(1) - (1)].nd)), 0);
                      NODE_LINENO((yyval.nd), (yyvsp[(1) - (1)].nd));
                    }
    break;

  case 247:
/* Line 1792 of yacc.c  */
#line 2265 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = cons((yyvsp[(1) - (2)].nd), (yyvsp[(2) - (2)].nd));
                      NODE_LINENO((yyval.nd), (yyvsp[(1) - (2)].nd));
                    }
    break;

  case 248:
/* Line 1792 of yacc.c  */
#line 2270 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = cons(list1(new_kw_hash(p, (yyvsp[(1) - (2)].nd))), (yyvsp[(2) - (2)].nd));
                      NODE_LINENO((yyval.nd), (yyvsp[(1) - (2)].nd));
                    }
    break;

  case 249:
/* Line 1792 of yacc.c  */
#line 2275 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = cons(push((yyvsp[(1) - (4)].nd), new_kw_hash(p, (yyvsp[(3) - (4)].nd))), (yyvsp[(4) - (4)].nd));
                      NODE_LINENO((yyval.nd), (yyvsp[(1) - (4)].nd));
                    }
    break;

  case 250:
/* Line 1792 of yacc.c  */
#line 2280 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = cons(0, (yyvsp[(1) - (1)].nd));
                      NODE_LINENO((yyval.nd), (yyvsp[(1) - (1)].nd));
                    }
    break;

  case 251:
/* Line 1792 of yacc.c  */
#line 2286 "D:\\Desktop\\parse.y"
    {
                      (yyval.stack) = p->cmdarg_stack;
                      CMDARG_PUSH(1);
                    }
    break;

  case 252:
/* Line 1792 of yacc.c  */
#line 2291 "D:\\Desktop\\parse.y"
    {
                      p->cmdarg_stack = (yyvsp[(1) - (2)].stack);
                      (yyval.nd) = (yyvsp[(2) - (2)].nd);
                    }
    break;

  case 253:
/* Line 1792 of yacc.c  */
#line 2298 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_block_arg(p, (yyvsp[(2) - (2)].nd));
                    }
    break;

  case 254:
/* Line 1792 of yacc.c  */
#line 2304 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = (yyvsp[(2) - (2)].nd);
                    }
    break;

  case 255:
/* Line 1792 of yacc.c  */
#line 2308 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = 0;
                    }
    break;

  case 258:
/* Line 1792 of yacc.c  */
#line 2318 "D:\\Desktop\\parse.y"
    {
                      void_expr_error(p, (yyvsp[(1) - (1)].nd));
                      (yyval.nd) = cons((yyvsp[(1) - (1)].nd), 0);
                      NODE_LINENO((yyval.nd), (yyvsp[(1) - (1)].nd));
                    }
    break;

  case 259:
/* Line 1792 of yacc.c  */
#line 2324 "D:\\Desktop\\parse.y"
    {
                      void_expr_error(p, (yyvsp[(2) - (2)].nd));
                      (yyval.nd) = cons(new_splat(p, (yyvsp[(2) - (2)].nd)), 0);
                      NODE_LINENO((yyval.nd), (yyvsp[(2) - (2)].nd));
                    }
    break;

  case 260:
/* Line 1792 of yacc.c  */
#line 2330 "D:\\Desktop\\parse.y"
    {
                      void_expr_error(p, (yyvsp[(3) - (3)].nd));
                      (yyval.nd) = push((yyvsp[(1) - (3)].nd), (yyvsp[(3) - (3)].nd));
                    }
    break;

  case 261:
/* Line 1792 of yacc.c  */
#line 2335 "D:\\Desktop\\parse.y"
    {
                      void_expr_error(p, (yyvsp[(4) - (4)].nd));
                      (yyval.nd) = push((yyvsp[(1) - (4)].nd), new_splat(p, (yyvsp[(4) - (4)].nd)));
                    }
    break;

  case 262:
/* Line 1792 of yacc.c  */
#line 2342 "D:\\Desktop\\parse.y"
    {
                      void_expr_error(p, (yyvsp[(3) - (3)].nd));
                      (yyval.nd) = push((yyvsp[(1) - (3)].nd), (yyvsp[(3) - (3)].nd));
                    }
    break;

  case 263:
/* Line 1792 of yacc.c  */
#line 2347 "D:\\Desktop\\parse.y"
    {
                      void_expr_error(p, (yyvsp[(4) - (4)].nd));
                      (yyval.nd) = push((yyvsp[(1) - (4)].nd), new_splat(p, (yyvsp[(4) - (4)].nd)));
                    }
    break;

  case 264:
/* Line 1792 of yacc.c  */
#line 2352 "D:\\Desktop\\parse.y"
    {
                      void_expr_error(p, (yyvsp[(2) - (2)].nd));
                      (yyval.nd) = list1(new_splat(p, (yyvsp[(2) - (2)].nd)));
                    }
    break;

  case 272:
/* Line 1792 of yacc.c  */
#line 2366 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_fcall(p, (yyvsp[(1) - (1)].id), 0);
                    }
    break;

  case 273:
/* Line 1792 of yacc.c  */
#line 2370 "D:\\Desktop\\parse.y"
    {
                      (yyval.stack) = p->cmdarg_stack;
                      p->cmdarg_stack = 0;
                    }
    break;

  case 274:
/* Line 1792 of yacc.c  */
#line 2376 "D:\\Desktop\\parse.y"
    {
                      p->cmdarg_stack = (yyvsp[(2) - (4)].stack);
                      (yyval.nd) = (yyvsp[(3) - (4)].nd);
                    }
    break;

  case 275:
/* Line 1792 of yacc.c  */
#line 2381 "D:\\Desktop\\parse.y"
    {
                      (yyval.stack) = p->cmdarg_stack;
                      p->cmdarg_stack = 0;
                    }
    break;

  case 276:
/* Line 1792 of yacc.c  */
#line 2385 "D:\\Desktop\\parse.y"
    {p->lstate = EXPR_ENDARG;}
    break;

  case 277:
/* Line 1792 of yacc.c  */
#line 2386 "D:\\Desktop\\parse.y"
    {
                      p->cmdarg_stack = (yyvsp[(2) - (5)].stack);
                      (yyval.nd) = (yyvsp[(3) - (5)].nd);
                    }
    break;

  case 278:
/* Line 1792 of yacc.c  */
#line 2390 "D:\\Desktop\\parse.y"
    {p->lstate = EXPR_ENDARG;}
    break;

  case 279:
/* Line 1792 of yacc.c  */
#line 2391 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_nil(p);
                    }
    break;

  case 280:
/* Line 1792 of yacc.c  */
#line 2395 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = (yyvsp[(2) - (3)].nd);
                    }
    break;

  case 281:
/* Line 1792 of yacc.c  */
#line 2399 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_colon2(p, (yyvsp[(1) - (3)].nd), (yyvsp[(3) - (3)].id));
                    }
    break;

  case 282:
/* Line 1792 of yacc.c  */
#line 2403 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_colon3(p, (yyvsp[(2) - (2)].id));
                    }
    break;

  case 283:
/* Line 1792 of yacc.c  */
#line 2407 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_array(p, (yyvsp[(2) - (3)].nd));
                      NODE_LINENO((yyval.nd), (yyvsp[(2) - (3)].nd));
                    }
    break;

  case 284:
/* Line 1792 of yacc.c  */
#line 2412 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_hash(p, (yyvsp[(2) - (3)].nd));
                      NODE_LINENO((yyval.nd), (yyvsp[(2) - (3)].nd));
                    }
    break;

  case 285:
/* Line 1792 of yacc.c  */
#line 2417 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_return(p, 0);
                    }
    break;

  case 286:
/* Line 1792 of yacc.c  */
#line 2421 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_yield(p, (yyvsp[(2) - (2)].nd));
                    }
    break;

  case 287:
/* Line 1792 of yacc.c  */
#line 2425 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = call_uni_op(p, cond((yyvsp[(3) - (4)].nd)), "!");
                    }
    break;

  case 288:
/* Line 1792 of yacc.c  */
#line 2429 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = call_uni_op(p, new_nil(p), "!");
                    }
    break;

  case 289:
/* Line 1792 of yacc.c  */
#line 2433 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_fcall(p, (yyvsp[(1) - (2)].id), cons(0, (yyvsp[(2) - (2)].nd)));
                    }
    break;

  case 291:
/* Line 1792 of yacc.c  */
#line 2438 "D:\\Desktop\\parse.y"
    {
                      call_with_block(p, (yyvsp[(1) - (2)].nd), (yyvsp[(2) - (2)].nd));
                      (yyval.nd) = (yyvsp[(1) - (2)].nd);
                    }
    break;

  case 292:
/* Line 1792 of yacc.c  */
#line 2443 "D:\\Desktop\\parse.y"
    {
                      local_nest(p);
                      (yyval.num) = p->lpar_beg;
                      p->lpar_beg = ++p->paren_nest;
                    }
    break;

  case 293:
/* Line 1792 of yacc.c  */
#line 2449 "D:\\Desktop\\parse.y"
    {
                      (yyval.stack) = p->cmdarg_stack;
                      p->cmdarg_stack = 0;
                    }
    break;

  case 294:
/* Line 1792 of yacc.c  */
#line 2454 "D:\\Desktop\\parse.y"
    {
                      p->lpar_beg = (yyvsp[(2) - (5)].num);
                      (yyval.nd) = new_lambda(p, (yyvsp[(3) - (5)].nd), (yyvsp[(5) - (5)].nd));
                      local_unnest(p);
                      p->cmdarg_stack = (yyvsp[(4) - (5)].stack);
                      CMDARG_LEXPOP();
                    }
    break;

  case 295:
/* Line 1792 of yacc.c  */
#line 2465 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_if(p, cond((yyvsp[(2) - (6)].nd)), (yyvsp[(4) - (6)].nd), (yyvsp[(5) - (6)].nd));
                      SET_LINENO((yyval.nd), (yyvsp[(1) - (6)].num));
                    }
    break;

  case 296:
/* Line 1792 of yacc.c  */
#line 2473 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_unless(p, cond((yyvsp[(2) - (6)].nd)), (yyvsp[(4) - (6)].nd), (yyvsp[(5) - (6)].nd));
                      SET_LINENO((yyval.nd), (yyvsp[(1) - (6)].num));
                    }
    break;

  case 297:
/* Line 1792 of yacc.c  */
#line 2477 "D:\\Desktop\\parse.y"
    {COND_PUSH(1);}
    break;

  case 298:
/* Line 1792 of yacc.c  */
#line 2477 "D:\\Desktop\\parse.y"
    {COND_POP();}
    break;

  case 299:
/* Line 1792 of yacc.c  */
#line 2480 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_while(p, cond((yyvsp[(3) - (7)].nd)), (yyvsp[(6) - (7)].nd));
                      SET_LINENO((yyval.nd), (yyvsp[(1) - (7)].num));
                    }
    break;

  case 300:
/* Line 1792 of yacc.c  */
#line 2484 "D:\\Desktop\\parse.y"
    {COND_PUSH(1);}
    break;

  case 301:
/* Line 1792 of yacc.c  */
#line 2484 "D:\\Desktop\\parse.y"
    {COND_POP();}
    break;

  case 302:
/* Line 1792 of yacc.c  */
#line 2487 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_until(p, cond((yyvsp[(3) - (7)].nd)), (yyvsp[(6) - (7)].nd));
                      SET_LINENO((yyval.nd), (yyvsp[(1) - (7)].num));
                    }
    break;

  case 303:
/* Line 1792 of yacc.c  */
#line 2494 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_case(p, (yyvsp[(2) - (5)].nd), (yyvsp[(4) - (5)].nd));
                    }
    break;

  case 304:
/* Line 1792 of yacc.c  */
#line 2498 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_case(p, 0, (yyvsp[(3) - (4)].nd));
                    }
    break;

  case 305:
/* Line 1792 of yacc.c  */
#line 2502 "D:\\Desktop\\parse.y"
    {COND_PUSH(1);}
    break;

  case 306:
/* Line 1792 of yacc.c  */
#line 2504 "D:\\Desktop\\parse.y"
    {COND_POP();}
    break;

  case 307:
/* Line 1792 of yacc.c  */
#line 2507 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_for(p, (yyvsp[(2) - (9)].nd), (yyvsp[(5) - (9)].nd), (yyvsp[(8) - (9)].nd));
                      SET_LINENO((yyval.nd), (yyvsp[(1) - (9)].num));
                    }
    break;

  case 308:
/* Line 1792 of yacc.c  */
#line 2513 "D:\\Desktop\\parse.y"
    {
                      if (p->in_def || p->in_single)
                        yyerror(p, "class definition in method body");
                      (yyval.nd) = local_switch(p);
                    }
    break;

  case 309:
/* Line 1792 of yacc.c  */
#line 2520 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_class(p, (yyvsp[(2) - (6)].nd), (yyvsp[(3) - (6)].nd), (yyvsp[(5) - (6)].nd));
                      SET_LINENO((yyval.nd), (yyvsp[(1) - (6)].num));
                      local_resume(p, (yyvsp[(4) - (6)].nd));
                    }
    break;

  case 310:
/* Line 1792 of yacc.c  */
#line 2527 "D:\\Desktop\\parse.y"
    {
                      (yyval.num) = p->in_def;
                      p->in_def = 0;
                    }
    break;

  case 311:
/* Line 1792 of yacc.c  */
#line 2532 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = cons(local_switch(p), nint(p->in_single));
                      p->in_single = 0;
                    }
    break;

  case 312:
/* Line 1792 of yacc.c  */
#line 2538 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_sclass(p, (yyvsp[(3) - (8)].nd), (yyvsp[(7) - (8)].nd));
                      SET_LINENO((yyval.nd), (yyvsp[(1) - (8)].num));
                      local_resume(p, (yyvsp[(6) - (8)].nd)->car);
                      p->in_def = (yyvsp[(4) - (8)].num);
                      p->in_single = intn((yyvsp[(6) - (8)].nd)->cdr);
                    }
    break;

  case 313:
/* Line 1792 of yacc.c  */
#line 2547 "D:\\Desktop\\parse.y"
    {
                      if (p->in_def || p->in_single)
                        yyerror(p, "module definition in method body");
                      (yyval.nd) = local_switch(p);
                    }
    break;

  case 314:
/* Line 1792 of yacc.c  */
#line 2554 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_module(p, (yyvsp[(2) - (5)].nd), (yyvsp[(4) - (5)].nd));
                      SET_LINENO((yyval.nd), (yyvsp[(1) - (5)].num));
                      local_resume(p, (yyvsp[(3) - (5)].nd));
                    }
    break;

  case 315:
/* Line 1792 of yacc.c  */
#line 2560 "D:\\Desktop\\parse.y"
    {
                      (yyval.stack) = p->cmdarg_stack;
                      p->cmdarg_stack = 0;
                    }
    break;

  case 316:
/* Line 1792 of yacc.c  */
#line 2564 "D:\\Desktop\\parse.y"
    {
                      p->in_def++;
                      (yyval.nd) = local_switch(p);
                    }
    break;

  case 317:
/* Line 1792 of yacc.c  */
#line 2571 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_def(p, (yyvsp[(2) - (7)].id), (yyvsp[(5) - (7)].nd), (yyvsp[(6) - (7)].nd));
                      SET_LINENO((yyval.nd), (yyvsp[(1) - (7)].num));
                      local_resume(p, (yyvsp[(4) - (7)].nd));
                      p->in_def--;
                      p->cmdarg_stack = (yyvsp[(3) - (7)].stack);
                    }
    break;

  case 318:
/* Line 1792 of yacc.c  */
#line 2579 "D:\\Desktop\\parse.y"
    {
                      p->lstate = EXPR_FNAME;
                      (yyval.stack) = p->cmdarg_stack;
                      p->cmdarg_stack = 0;
                    }
    break;

  case 319:
/* Line 1792 of yacc.c  */
#line 2585 "D:\\Desktop\\parse.y"
    {
                      p->in_single++;
                      p->lstate = EXPR_ENDFN; /* force for args */
                      (yyval.nd) = local_switch(p);
                    }
    break;

  case 320:
/* Line 1792 of yacc.c  */
#line 2593 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_sdef(p, (yyvsp[(2) - (9)].nd), (yyvsp[(5) - (9)].id), (yyvsp[(7) - (9)].nd), (yyvsp[(8) - (9)].nd));
                      SET_LINENO((yyval.nd), (yyvsp[(1) - (9)].num));
                      local_resume(p, (yyvsp[(6) - (9)].nd));
                      p->in_single--;
                      p->cmdarg_stack = (yyvsp[(4) - (9)].stack);
                    }
    break;

  case 321:
/* Line 1792 of yacc.c  */
#line 2601 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_break(p, 0);
                    }
    break;

  case 322:
/* Line 1792 of yacc.c  */
#line 2605 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_next(p, 0);
                    }
    break;

  case 323:
/* Line 1792 of yacc.c  */
#line 2609 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_redo(p);
                    }
    break;

  case 324:
/* Line 1792 of yacc.c  */
#line 2613 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_retry(p);
                    }
    break;

  case 325:
/* Line 1792 of yacc.c  */
#line 2619 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = (yyvsp[(1) - (1)].nd);
                      if (!(yyval.nd)) (yyval.nd) = new_nil(p);
                    }
    break;

  case 332:
/* Line 1792 of yacc.c  */
#line 2638 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_if(p, cond((yyvsp[(2) - (5)].nd)), (yyvsp[(4) - (5)].nd), (yyvsp[(5) - (5)].nd));
                    }
    break;

  case 334:
/* Line 1792 of yacc.c  */
#line 2645 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = (yyvsp[(2) - (2)].nd);
                    }
    break;

  case 335:
/* Line 1792 of yacc.c  */
#line 2651 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = list1(list1((yyvsp[(1) - (1)].nd)));
                    }
    break;

  case 337:
/* Line 1792 of yacc.c  */
#line 2658 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = list3((yyvsp[(1) - (1)].nd),0,0);
                    }
    break;

  case 338:
/* Line 1792 of yacc.c  */
#line 2662 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = list3((yyvsp[(1) - (4)].nd), new_arg(p, (yyvsp[(4) - (4)].id)), 0);
                    }
    break;

  case 339:
/* Line 1792 of yacc.c  */
#line 2666 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = list3((yyvsp[(1) - (6)].nd), new_arg(p, (yyvsp[(4) - (6)].id)), (yyvsp[(6) - (6)].nd));
                    }
    break;

  case 340:
/* Line 1792 of yacc.c  */
#line 2670 "D:\\Desktop\\parse.y"
    {
                      local_add_f(p, 0);
                      (yyval.nd) = list3((yyvsp[(1) - (3)].nd), (node*)-1, 0);
                    }
    break;

  case 341:
/* Line 1792 of yacc.c  */
#line 2675 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = list3((yyvsp[(1) - (5)].nd), (node*)-1, (yyvsp[(5) - (5)].nd));
                    }
    break;

  case 342:
/* Line 1792 of yacc.c  */
#line 2679 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = list3(0, new_arg(p, (yyvsp[(2) - (2)].id)), 0);
                    }
    break;

  case 343:
/* Line 1792 of yacc.c  */
#line 2683 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = list3(0, new_arg(p, (yyvsp[(2) - (4)].id)), (yyvsp[(4) - (4)].nd));
                    }
    break;

  case 344:
/* Line 1792 of yacc.c  */
#line 2687 "D:\\Desktop\\parse.y"
    {
                      local_add_f(p, 0);
                      (yyval.nd) = list3(0, (node*)-1, 0);
                    }
    break;

  case 345:
/* Line 1792 of yacc.c  */
#line 2692 "D:\\Desktop\\parse.y"
    {
                      local_add_f(p, 0);
                    }
    break;

  case 346:
/* Line 1792 of yacc.c  */
#line 2696 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = list3(0, (node*)-1, (yyvsp[(4) - (4)].nd));
                    }
    break;

  case 347:
/* Line 1792 of yacc.c  */
#line 2702 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_args_tail(p, (yyvsp[(1) - (4)].nd), (yyvsp[(3) - (4)].nd), (yyvsp[(4) - (4)].id));
                    }
    break;

  case 348:
/* Line 1792 of yacc.c  */
#line 2706 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_args_tail(p, (yyvsp[(1) - (2)].nd), 0, (yyvsp[(2) - (2)].id));
                    }
    break;

  case 349:
/* Line 1792 of yacc.c  */
#line 2710 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_args_tail(p, 0, (yyvsp[(1) - (2)].nd), (yyvsp[(2) - (2)].id));
                    }
    break;

  case 350:
/* Line 1792 of yacc.c  */
#line 2714 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_args_tail(p, 0, 0, (yyvsp[(1) - (1)].id));
                    }
    break;

  case 351:
/* Line 1792 of yacc.c  */
#line 2720 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = (yyvsp[(2) - (2)].nd);
                    }
    break;

  case 352:
/* Line 1792 of yacc.c  */
#line 2724 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_args_tail(p, 0, 0, 0);
                    }
    break;

  case 353:
/* Line 1792 of yacc.c  */
#line 2730 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_args(p, (yyvsp[(1) - (6)].nd), (yyvsp[(3) - (6)].nd), (yyvsp[(5) - (6)].id), 0, (yyvsp[(6) - (6)].nd));
                    }
    break;

  case 354:
/* Line 1792 of yacc.c  */
#line 2734 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_args(p, (yyvsp[(1) - (8)].nd), (yyvsp[(3) - (8)].nd), (yyvsp[(5) - (8)].id), (yyvsp[(7) - (8)].nd), (yyvsp[(8) - (8)].nd));
                    }
    break;

  case 355:
/* Line 1792 of yacc.c  */
#line 2738 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_args(p, (yyvsp[(1) - (4)].nd), (yyvsp[(3) - (4)].nd), 0, 0, (yyvsp[(4) - (4)].nd));
                    }
    break;

  case 356:
/* Line 1792 of yacc.c  */
#line 2742 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_args(p, (yyvsp[(1) - (6)].nd), (yyvsp[(3) - (6)].nd), 0, (yyvsp[(5) - (6)].nd), (yyvsp[(6) - (6)].nd));
                    }
    break;

  case 357:
/* Line 1792 of yacc.c  */
#line 2746 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_args(p, (yyvsp[(1) - (4)].nd), 0, (yyvsp[(3) - (4)].id), 0, (yyvsp[(4) - (4)].nd));
                    }
    break;

  case 358:
/* Line 1792 of yacc.c  */
#line 2750 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_args(p, (yyvsp[(1) - (3)].nd), 0, 0, 0, (yyvsp[(3) - (3)].nd));
                    }
    break;

  case 359:
/* Line 1792 of yacc.c  */
#line 2754 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_args(p, (yyvsp[(1) - (6)].nd), 0, (yyvsp[(3) - (6)].id), (yyvsp[(5) - (6)].nd), (yyvsp[(6) - (6)].nd));
                    }
    break;

  case 360:
/* Line 1792 of yacc.c  */
#line 2758 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_args(p, (yyvsp[(1) - (2)].nd), 0, 0, 0, (yyvsp[(2) - (2)].nd));
                    }
    break;

  case 361:
/* Line 1792 of yacc.c  */
#line 2762 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_args(p, 0, (yyvsp[(1) - (4)].nd), (yyvsp[(3) - (4)].id), 0, (yyvsp[(4) - (4)].nd));
                    }
    break;

  case 362:
/* Line 1792 of yacc.c  */
#line 2766 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_args(p, 0, (yyvsp[(1) - (6)].nd), (yyvsp[(3) - (6)].id), (yyvsp[(5) - (6)].nd), (yyvsp[(6) - (6)].nd));
                    }
    break;

  case 363:
/* Line 1792 of yacc.c  */
#line 2770 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_args(p, 0, (yyvsp[(1) - (2)].nd), 0, 0, (yyvsp[(2) - (2)].nd));
                    }
    break;

  case 364:
/* Line 1792 of yacc.c  */
#line 2774 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_args(p, 0, (yyvsp[(1) - (4)].nd), 0, (yyvsp[(3) - (4)].nd), (yyvsp[(4) - (4)].nd));
                    }
    break;

  case 365:
/* Line 1792 of yacc.c  */
#line 2778 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_args(p, 0, 0, (yyvsp[(1) - (2)].id), 0, (yyvsp[(2) - (2)].nd));
                    }
    break;

  case 366:
/* Line 1792 of yacc.c  */
#line 2782 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_args(p, 0, 0, (yyvsp[(1) - (4)].id), (yyvsp[(3) - (4)].nd), (yyvsp[(4) - (4)].nd));
                    }
    break;

  case 367:
/* Line 1792 of yacc.c  */
#line 2786 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_args(p, 0, 0, 0, 0, (yyvsp[(1) - (1)].nd));
                    }
    break;

  case 368:
/* Line 1792 of yacc.c  */
#line 2792 "D:\\Desktop\\parse.y"
    {
                      local_add_blk(p, 0);
                      (yyval.nd) = 0;
                    }
    break;

  case 369:
/* Line 1792 of yacc.c  */
#line 2797 "D:\\Desktop\\parse.y"
    {
                      p->cmd_start = TRUE;
                      (yyval.nd) = (yyvsp[(1) - (1)].nd);
                    }
    break;

  case 370:
/* Line 1792 of yacc.c  */
#line 2803 "D:\\Desktop\\parse.y"
    {local_add_blk(p, 0);}
    break;

  case 371:
/* Line 1792 of yacc.c  */
#line 2804 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = 0;
                    }
    break;

  case 372:
/* Line 1792 of yacc.c  */
#line 2808 "D:\\Desktop\\parse.y"
    {
                      local_add_blk(p, 0);
                      (yyval.nd) = 0;
                    }
    break;

  case 373:
/* Line 1792 of yacc.c  */
#line 2813 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = (yyvsp[(2) - (4)].nd);
                    }
    break;

  case 374:
/* Line 1792 of yacc.c  */
#line 2820 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = 0;
                    }
    break;

  case 375:
/* Line 1792 of yacc.c  */
#line 2824 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = 0;
                    }
    break;

  case 378:
/* Line 1792 of yacc.c  */
#line 2834 "D:\\Desktop\\parse.y"
    {
                      local_add_f(p, (yyvsp[(1) - (1)].id));
                      new_bv(p, (yyvsp[(1) - (1)].id));
                    }
    break;

  case 380:
/* Line 1792 of yacc.c  */
#line 2842 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = (yyvsp[(2) - (4)].nd);
                    }
    break;

  case 381:
/* Line 1792 of yacc.c  */
#line 2846 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = (yyvsp[(1) - (1)].nd);
                    }
    break;

  case 382:
/* Line 1792 of yacc.c  */
#line 2852 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = (yyvsp[(2) - (3)].nd);
                    }
    break;

  case 383:
/* Line 1792 of yacc.c  */
#line 2856 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = (yyvsp[(2) - (3)].nd);
                    }
    break;

  case 384:
/* Line 1792 of yacc.c  */
#line 2862 "D:\\Desktop\\parse.y"
    {
                      local_nest(p);
                    }
    break;

  case 385:
/* Line 1792 of yacc.c  */
#line 2868 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_block(p,(yyvsp[(3) - (5)].nd),(yyvsp[(4) - (5)].nd));
                      local_unnest(p);
                    }
    break;

  case 386:
/* Line 1792 of yacc.c  */
#line 2875 "D:\\Desktop\\parse.y"
    {
                      if ((yyvsp[(1) - (2)].nd)->car == (node*)NODE_YIELD) {
                        yyerror(p, "block given to yield");
                      }
                      else {
                        call_with_block(p, (yyvsp[(1) - (2)].nd), (yyvsp[(2) - (2)].nd));
                      }
                      (yyval.nd) = (yyvsp[(1) - (2)].nd);
                    }
    break;

  case 387:
/* Line 1792 of yacc.c  */
#line 2885 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_call(p, (yyvsp[(1) - (4)].nd), (yyvsp[(3) - (4)].id), (yyvsp[(4) - (4)].nd), (yyvsp[(2) - (4)].num));
                    }
    break;

  case 388:
/* Line 1792 of yacc.c  */
#line 2889 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_call(p, (yyvsp[(1) - (5)].nd), (yyvsp[(3) - (5)].id), (yyvsp[(4) - (5)].nd), (yyvsp[(2) - (5)].num));
                      call_with_block(p, (yyval.nd), (yyvsp[(5) - (5)].nd));
                    }
    break;

  case 389:
/* Line 1792 of yacc.c  */
#line 2894 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_call(p, (yyvsp[(1) - (5)].nd), (yyvsp[(3) - (5)].id), (yyvsp[(4) - (5)].nd), (yyvsp[(2) - (5)].num));
                      call_with_block(p, (yyval.nd), (yyvsp[(5) - (5)].nd));
                    }
    break;

  case 390:
/* Line 1792 of yacc.c  */
#line 2901 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_fcall(p, (yyvsp[(1) - (2)].id), (yyvsp[(2) - (2)].nd));
                    }
    break;

  case 391:
/* Line 1792 of yacc.c  */
#line 2905 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_call(p, (yyvsp[(1) - (4)].nd), (yyvsp[(3) - (4)].id), (yyvsp[(4) - (4)].nd), (yyvsp[(2) - (4)].num));
                    }
    break;

  case 392:
/* Line 1792 of yacc.c  */
#line 2909 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_call(p, (yyvsp[(1) - (4)].nd), (yyvsp[(3) - (4)].id), (yyvsp[(4) - (4)].nd), tCOLON2);
                    }
    break;

  case 393:
/* Line 1792 of yacc.c  */
#line 2913 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_call(p, (yyvsp[(1) - (3)].nd), (yyvsp[(3) - (3)].id), 0, tCOLON2);
                    }
    break;

  case 394:
/* Line 1792 of yacc.c  */
#line 2917 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_call(p, (yyvsp[(1) - (3)].nd), intern("call",4), (yyvsp[(3) - (3)].nd), (yyvsp[(2) - (3)].num));
                    }
    break;

  case 395:
/* Line 1792 of yacc.c  */
#line 2921 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_call(p, (yyvsp[(1) - (3)].nd), intern("call",4), (yyvsp[(3) - (3)].nd), tCOLON2);
                    }
    break;

  case 396:
/* Line 1792 of yacc.c  */
#line 2925 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_super(p, (yyvsp[(2) - (2)].nd));
                    }
    break;

  case 397:
/* Line 1792 of yacc.c  */
#line 2929 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_zsuper(p);
                    }
    break;

  case 398:
/* Line 1792 of yacc.c  */
#line 2933 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_call(p, (yyvsp[(1) - (4)].nd), intern("[]",2), (yyvsp[(3) - (4)].nd), '.');
                    }
    break;

  case 399:
/* Line 1792 of yacc.c  */
#line 2939 "D:\\Desktop\\parse.y"
    {
                      local_nest(p);
                      (yyval.num) = p->lineno;
                    }
    break;

  case 400:
/* Line 1792 of yacc.c  */
#line 2945 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_block(p,(yyvsp[(3) - (5)].nd),(yyvsp[(4) - (5)].nd));
                      SET_LINENO((yyval.nd), (yyvsp[(2) - (5)].num));
                      local_unnest(p);
                    }
    break;

  case 401:
/* Line 1792 of yacc.c  */
#line 2951 "D:\\Desktop\\parse.y"
    {
                      local_nest(p);
                      (yyval.num) = p->lineno;
                    }
    break;

  case 402:
/* Line 1792 of yacc.c  */
#line 2957 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_block(p,(yyvsp[(3) - (5)].nd),(yyvsp[(4) - (5)].nd));
                      SET_LINENO((yyval.nd), (yyvsp[(2) - (5)].num));
                      local_unnest(p);
                    }
    break;

  case 403:
/* Line 1792 of yacc.c  */
#line 2967 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = cons(cons((yyvsp[(2) - (5)].nd), (yyvsp[(4) - (5)].nd)), (yyvsp[(5) - (5)].nd));
                    }
    break;

  case 404:
/* Line 1792 of yacc.c  */
#line 2973 "D:\\Desktop\\parse.y"
    {
                      if ((yyvsp[(1) - (1)].nd)) {
                        (yyval.nd) = cons(cons(0, (yyvsp[(1) - (1)].nd)), 0);
                      }
                      else {
                        (yyval.nd) = 0;
                      }
                    }
    break;

  case 406:
/* Line 1792 of yacc.c  */
#line 2987 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = list1(list3((yyvsp[(2) - (6)].nd), (yyvsp[(3) - (6)].nd), (yyvsp[(5) - (6)].nd)));
                      if ((yyvsp[(6) - (6)].nd)) (yyval.nd) = append((yyval.nd), (yyvsp[(6) - (6)].nd));
                    }
    break;

  case 408:
/* Line 1792 of yacc.c  */
#line 2995 "D:\\Desktop\\parse.y"
    {
                        (yyval.nd) = list1((yyvsp[(1) - (1)].nd));
                    }
    break;

  case 411:
/* Line 1792 of yacc.c  */
#line 3003 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = (yyvsp[(2) - (2)].nd);
                    }
    break;

  case 413:
/* Line 1792 of yacc.c  */
#line 3010 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = (yyvsp[(2) - (2)].nd);
                    }
    break;

  case 420:
/* Line 1792 of yacc.c  */
#line 3024 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = concat_string(p, (yyvsp[(1) - (2)].nd), (yyvsp[(2) - (2)].nd));
                    }
    break;

  case 423:
/* Line 1792 of yacc.c  */
#line 3032 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = (yyvsp[(2) - (2)].nd);
                    }
    break;

  case 424:
/* Line 1792 of yacc.c  */
#line 3036 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_dstr(p, push((yyvsp[(2) - (3)].nd), (yyvsp[(3) - (3)].nd)));
                    }
    break;

  case 426:
/* Line 1792 of yacc.c  */
#line 3043 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = append((yyvsp[(1) - (2)].nd), (yyvsp[(2) - (2)].nd));
                    }
    break;

  case 427:
/* Line 1792 of yacc.c  */
#line 3049 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = list1((yyvsp[(1) - (1)].nd));
                    }
    break;

  case 428:
/* Line 1792 of yacc.c  */
#line 3053 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = p->lex_strterm;
                      p->lex_strterm = NULL;
                    }
    break;

  case 429:
/* Line 1792 of yacc.c  */
#line 3059 "D:\\Desktop\\parse.y"
    {
                      p->lex_strterm = (yyvsp[(2) - (4)].nd);
                      (yyval.nd) = list2((yyvsp[(1) - (4)].nd), (yyvsp[(3) - (4)].nd));
                    }
    break;

  case 430:
/* Line 1792 of yacc.c  */
#line 3064 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = list1(new_literal_delim(p));
                    }
    break;

  case 431:
/* Line 1792 of yacc.c  */
#line 3068 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = list1(new_literal_delim(p));
                    }
    break;

  case 432:
/* Line 1792 of yacc.c  */
#line 3074 "D:\\Desktop\\parse.y"
    {
                        (yyval.nd) = (yyvsp[(2) - (2)].nd);
                    }
    break;

  case 433:
/* Line 1792 of yacc.c  */
#line 3078 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_dxstr(p, push((yyvsp[(2) - (3)].nd), (yyvsp[(3) - (3)].nd)));
                    }
    break;

  case 434:
/* Line 1792 of yacc.c  */
#line 3084 "D:\\Desktop\\parse.y"
    {
                        (yyval.nd) = (yyvsp[(2) - (2)].nd);
                    }
    break;

  case 435:
/* Line 1792 of yacc.c  */
#line 3088 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_dregx(p, (yyvsp[(2) - (3)].nd), (yyvsp[(3) - (3)].nd));
                    }
    break;

  case 439:
/* Line 1792 of yacc.c  */
#line 3101 "D:\\Desktop\\parse.y"
    {
                      parser_heredoc_info * inf = parsing_heredoc_inf(p);
                      inf->doc = push(inf->doc, new_str(p, "", 0));
                      heredoc_end(p);
                    }
    break;

  case 440:
/* Line 1792 of yacc.c  */
#line 3107 "D:\\Desktop\\parse.y"
    {
                      heredoc_end(p);
                    }
    break;

  case 443:
/* Line 1792 of yacc.c  */
#line 3117 "D:\\Desktop\\parse.y"
    {
                      parser_heredoc_info * inf = parsing_heredoc_inf(p);
                      inf->doc = push(inf->doc, (yyvsp[(1) - (1)].nd));
                      heredoc_treat_nextline(p);
                    }
    break;

  case 444:
/* Line 1792 of yacc.c  */
#line 3123 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = p->lex_strterm;
                      p->lex_strterm = NULL;
                    }
    break;

  case 445:
/* Line 1792 of yacc.c  */
#line 3129 "D:\\Desktop\\parse.y"
    {
                      parser_heredoc_info * inf = parsing_heredoc_inf(p);
                      p->lex_strterm = (yyvsp[(2) - (4)].nd);
                      inf->doc = push(push(inf->doc, (yyvsp[(1) - (4)].nd)), (yyvsp[(3) - (4)].nd));
                    }
    break;

  case 446:
/* Line 1792 of yacc.c  */
#line 3137 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_words(p, list1((yyvsp[(2) - (2)].nd)));
                    }
    break;

  case 447:
/* Line 1792 of yacc.c  */
#line 3141 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_words(p, push((yyvsp[(2) - (3)].nd), (yyvsp[(3) - (3)].nd)));
                    }
    break;

  case 448:
/* Line 1792 of yacc.c  */
#line 3148 "D:\\Desktop\\parse.y"
    {
                      p->lstate = EXPR_ENDARG;
                      (yyval.nd) = new_sym(p, (yyvsp[(1) - (1)].id));
                    }
    break;

  case 449:
/* Line 1792 of yacc.c  */
#line 3153 "D:\\Desktop\\parse.y"
    {
                      p->lstate = EXPR_ENDARG;
                      (yyval.nd) = new_dsym(p, new_dstr(p, push((yyvsp[(3) - (4)].nd), (yyvsp[(4) - (4)].nd))));
                    }
    break;

  case 450:
/* Line 1792 of yacc.c  */
#line 3160 "D:\\Desktop\\parse.y"
    {
                      (yyval.id) = (yyvsp[(2) - (2)].id);
                    }
    break;

  case 455:
/* Line 1792 of yacc.c  */
#line 3170 "D:\\Desktop\\parse.y"
    {
                      (yyval.id) = new_strsym(p, (yyvsp[(1) - (1)].nd));
                    }
    break;

  case 456:
/* Line 1792 of yacc.c  */
#line 3174 "D:\\Desktop\\parse.y"
    {
                      (yyval.id) = new_strsym(p, (yyvsp[(2) - (2)].nd));
                    }
    break;

  case 457:
/* Line 1792 of yacc.c  */
#line 3180 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_symbols(p, list1((yyvsp[(2) - (2)].nd)));
                    }
    break;

  case 458:
/* Line 1792 of yacc.c  */
#line 3184 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_symbols(p, push((yyvsp[(2) - (3)].nd), (yyvsp[(3) - (3)].nd)));
                    }
    break;

  case 461:
/* Line 1792 of yacc.c  */
#line 3192 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = negate_lit(p, (yyvsp[(2) - (2)].nd));
                    }
    break;

  case 462:
/* Line 1792 of yacc.c  */
#line 3196 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = negate_lit(p, (yyvsp[(2) - (2)].nd));
                    }
    break;

  case 463:
/* Line 1792 of yacc.c  */
#line 3202 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_lvar(p, (yyvsp[(1) - (1)].id));
                    }
    break;

  case 464:
/* Line 1792 of yacc.c  */
#line 3206 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_ivar(p, (yyvsp[(1) - (1)].id));
                    }
    break;

  case 465:
/* Line 1792 of yacc.c  */
#line 3210 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_gvar(p, (yyvsp[(1) - (1)].id));
                    }
    break;

  case 466:
/* Line 1792 of yacc.c  */
#line 3214 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_cvar(p, (yyvsp[(1) - (1)].id));
                    }
    break;

  case 467:
/* Line 1792 of yacc.c  */
#line 3218 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_const(p, (yyvsp[(1) - (1)].id));
                    }
    break;

  case 468:
/* Line 1792 of yacc.c  */
#line 3224 "D:\\Desktop\\parse.y"
    {
                      assignable(p, (yyvsp[(1) - (1)].nd));
                    }
    break;

  case 469:
/* Line 1792 of yacc.c  */
#line 3230 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = var_reference(p, (yyvsp[(1) - (1)].nd));
                    }
    break;

  case 470:
/* Line 1792 of yacc.c  */
#line 3234 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_nil(p);
                    }
    break;

  case 471:
/* Line 1792 of yacc.c  */
#line 3238 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_self(p);
                    }
    break;

  case 472:
/* Line 1792 of yacc.c  */
#line 3242 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_true(p);
                    }
    break;

  case 473:
/* Line 1792 of yacc.c  */
#line 3246 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_false(p);
                    }
    break;

  case 474:
/* Line 1792 of yacc.c  */
#line 3250 "D:\\Desktop\\parse.y"
    {
                      const char *fn = mrb_sym_name_len(p->mrb, p->filename_sym, NULL);
                      if (!fn) {
                        fn = "(null)";
                      }
                      (yyval.nd) = new_str(p, fn, strlen(fn));
                    }
    break;

  case 475:
/* Line 1792 of yacc.c  */
#line 3258 "D:\\Desktop\\parse.y"
    {
                      char buf[16];

                      dump_int(p->lineno, buf);
                      (yyval.nd) = new_int(p, buf, 10, 0);
                    }
    break;

  case 476:
/* Line 1792 of yacc.c  */
#line 3265 "D:\\Desktop\\parse.y"
    {
#ifdef MRB_UTF8_STRING
                      const char *enc = "UTF-8";
#else
                      const char *enc = "ASCII-8BIT";
#endif
                      (yyval.nd) = new_str(p, enc, strlen(enc));
                    }
    break;

  case 479:
/* Line 1792 of yacc.c  */
#line 3280 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = 0;
                    }
    break;

  case 480:
/* Line 1792 of yacc.c  */
#line 3284 "D:\\Desktop\\parse.y"
    {
                      p->lstate = EXPR_BEG;
                      p->cmd_start = TRUE;
                    }
    break;

  case 481:
/* Line 1792 of yacc.c  */
#line 3289 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = (yyvsp[(3) - (4)].nd);
                    }
    break;

  case 482:
/* Line 1792 of yacc.c  */
#line 3300 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = (yyvsp[(2) - (3)].nd);
                      p->lstate = EXPR_BEG;
                      p->cmd_start = TRUE;
                    }
    break;

  case 483:
/* Line 1792 of yacc.c  */
#line 3306 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = (yyvsp[(1) - (2)].nd);
                    }
    break;

  case 484:
/* Line 1792 of yacc.c  */
#line 3312 "D:\\Desktop\\parse.y"
    {
                      local_nest(p);
                    }
    break;

  case 485:
/* Line 1792 of yacc.c  */
#line 3318 "D:\\Desktop\\parse.y"
    {
                      void_expr_error(p, (yyvsp[(2) - (2)].nd));
                      (yyval.nd) = new_kw_arg(p, (yyvsp[(1) - (2)].id), cons((yyvsp[(2) - (2)].nd), locals_node(p)));
                      local_unnest(p);
                    }
    break;

  case 486:
/* Line 1792 of yacc.c  */
#line 3324 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_kw_arg(p, (yyvsp[(1) - (1)].id), 0);
                      local_unnest(p);
                    }
    break;

  case 487:
/* Line 1792 of yacc.c  */
#line 3331 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_kw_arg(p, (yyvsp[(1) - (2)].id), (yyvsp[(2) - (2)].nd));
                    }
    break;

  case 488:
/* Line 1792 of yacc.c  */
#line 3335 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_kw_arg(p, (yyvsp[(1) - (1)].id), 0);
                    }
    break;

  case 489:
/* Line 1792 of yacc.c  */
#line 3341 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = list1((yyvsp[(1) - (1)].nd));
                    }
    break;

  case 490:
/* Line 1792 of yacc.c  */
#line 3345 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = push((yyvsp[(1) - (3)].nd), (yyvsp[(3) - (3)].nd));
                    }
    break;

  case 491:
/* Line 1792 of yacc.c  */
#line 3351 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = list1((yyvsp[(1) - (1)].nd));
                    }
    break;

  case 492:
/* Line 1792 of yacc.c  */
#line 3355 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = push((yyvsp[(1) - (3)].nd), (yyvsp[(3) - (3)].nd));
                    }
    break;

  case 495:
/* Line 1792 of yacc.c  */
#line 3365 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = cons((node*)NODE_KW_REST_ARGS, nsym((yyvsp[(2) - (2)].id)));
                    }
    break;

  case 496:
/* Line 1792 of yacc.c  */
#line 3369 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = cons((node*)NODE_KW_REST_ARGS, 0);
                    }
    break;

  case 497:
/* Line 1792 of yacc.c  */
#line 3375 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_args_tail(p, (yyvsp[(1) - (4)].nd), (yyvsp[(3) - (4)].nd), (yyvsp[(4) - (4)].id));
                    }
    break;

  case 498:
/* Line 1792 of yacc.c  */
#line 3379 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_args_tail(p, (yyvsp[(1) - (2)].nd), 0, (yyvsp[(2) - (2)].id));
                    }
    break;

  case 499:
/* Line 1792 of yacc.c  */
#line 3383 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_args_tail(p, 0, (yyvsp[(1) - (2)].nd), (yyvsp[(2) - (2)].id));
                    }
    break;

  case 500:
/* Line 1792 of yacc.c  */
#line 3387 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_args_tail(p, 0, 0, (yyvsp[(1) - (1)].id));
                    }
    break;

  case 501:
/* Line 1792 of yacc.c  */
#line 3393 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = (yyvsp[(2) - (2)].nd);
                    }
    break;

  case 502:
/* Line 1792 of yacc.c  */
#line 3397 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_args_tail(p, 0, 0, 0);
                    }
    break;

  case 503:
/* Line 1792 of yacc.c  */
#line 3403 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_args(p, (yyvsp[(1) - (6)].nd), (yyvsp[(3) - (6)].nd), (yyvsp[(5) - (6)].id), 0, (yyvsp[(6) - (6)].nd));
                    }
    break;

  case 504:
/* Line 1792 of yacc.c  */
#line 3407 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_args(p, (yyvsp[(1) - (8)].nd), (yyvsp[(3) - (8)].nd), (yyvsp[(5) - (8)].id), (yyvsp[(7) - (8)].nd), (yyvsp[(8) - (8)].nd));
                    }
    break;

  case 505:
/* Line 1792 of yacc.c  */
#line 3411 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_args(p, (yyvsp[(1) - (4)].nd), (yyvsp[(3) - (4)].nd), 0, 0, (yyvsp[(4) - (4)].nd));
                    }
    break;

  case 506:
/* Line 1792 of yacc.c  */
#line 3415 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_args(p, (yyvsp[(1) - (6)].nd), (yyvsp[(3) - (6)].nd), 0, (yyvsp[(5) - (6)].nd), (yyvsp[(6) - (6)].nd));
                    }
    break;

  case 507:
/* Line 1792 of yacc.c  */
#line 3419 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_args(p, (yyvsp[(1) - (4)].nd), 0, (yyvsp[(3) - (4)].id), 0, (yyvsp[(4) - (4)].nd));
                    }
    break;

  case 508:
/* Line 1792 of yacc.c  */
#line 3423 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_args(p, (yyvsp[(1) - (6)].nd), 0, (yyvsp[(3) - (6)].id), (yyvsp[(5) - (6)].nd), (yyvsp[(6) - (6)].nd));
                    }
    break;

  case 509:
/* Line 1792 of yacc.c  */
#line 3427 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_args(p, (yyvsp[(1) - (2)].nd), 0, 0, 0, (yyvsp[(2) - (2)].nd));
                    }
    break;

  case 510:
/* Line 1792 of yacc.c  */
#line 3431 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_args(p, 0, (yyvsp[(1) - (4)].nd), (yyvsp[(3) - (4)].id), 0, (yyvsp[(4) - (4)].nd));
                    }
    break;

  case 511:
/* Line 1792 of yacc.c  */
#line 3435 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_args(p, 0, (yyvsp[(1) - (6)].nd), (yyvsp[(3) - (6)].id), (yyvsp[(5) - (6)].nd), (yyvsp[(6) - (6)].nd));
                    }
    break;

  case 512:
/* Line 1792 of yacc.c  */
#line 3439 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_args(p, 0, (yyvsp[(1) - (2)].nd), 0, 0, (yyvsp[(2) - (2)].nd));
                    }
    break;

  case 513:
/* Line 1792 of yacc.c  */
#line 3443 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_args(p, 0, (yyvsp[(1) - (4)].nd), 0, (yyvsp[(3) - (4)].nd), (yyvsp[(4) - (4)].nd));
                    }
    break;

  case 514:
/* Line 1792 of yacc.c  */
#line 3447 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_args(p, 0, 0, (yyvsp[(1) - (2)].id), 0, (yyvsp[(2) - (2)].nd));
                    }
    break;

  case 515:
/* Line 1792 of yacc.c  */
#line 3451 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_args(p, 0, 0, (yyvsp[(1) - (4)].id), (yyvsp[(3) - (4)].nd), (yyvsp[(4) - (4)].nd));
                    }
    break;

  case 516:
/* Line 1792 of yacc.c  */
#line 3455 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_args(p, 0, 0, 0, 0, (yyvsp[(1) - (1)].nd));
                    }
    break;

  case 517:
/* Line 1792 of yacc.c  */
#line 3459 "D:\\Desktop\\parse.y"
    {
                      local_add_f(p, mrb_intern_lit(p->mrb, "&"));
                      (yyval.nd) = new_args(p, 0, 0, 0, 0, 0);
                    }
    break;

  case 518:
/* Line 1792 of yacc.c  */
#line 3466 "D:\\Desktop\\parse.y"
    {
                      yyerror(p, "formal argument cannot be a constant");
                      (yyval.nd) = 0;
                    }
    break;

  case 519:
/* Line 1792 of yacc.c  */
#line 3471 "D:\\Desktop\\parse.y"
    {
                      yyerror(p, "formal argument cannot be an instance variable");
                      (yyval.nd) = 0;
                    }
    break;

  case 520:
/* Line 1792 of yacc.c  */
#line 3476 "D:\\Desktop\\parse.y"
    {
                      yyerror(p, "formal argument cannot be a global variable");
                      (yyval.nd) = 0;
                    }
    break;

  case 521:
/* Line 1792 of yacc.c  */
#line 3481 "D:\\Desktop\\parse.y"
    {
                      yyerror(p, "formal argument cannot be a class variable");
                      (yyval.nd) = 0;
                    }
    break;

  case 522:
/* Line 1792 of yacc.c  */
#line 3488 "D:\\Desktop\\parse.y"
    {
                      (yyval.id) = 0;
                    }
    break;

  case 523:
/* Line 1792 of yacc.c  */
#line 3492 "D:\\Desktop\\parse.y"
    {
                      local_add_f(p, (yyvsp[(1) - (1)].id));
                      (yyval.id) = (yyvsp[(1) - (1)].id);
                    }
    break;

  case 524:
/* Line 1792 of yacc.c  */
#line 3499 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_arg(p, (yyvsp[(1) - (1)].id));
                    }
    break;

  case 525:
/* Line 1792 of yacc.c  */
#line 3503 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = local_switch(p);
                    }
    break;

  case 526:
/* Line 1792 of yacc.c  */
#line 3507 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = new_masgn_param(p, (yyvsp[(3) - (4)].nd), p->locals->car);
                      local_resume(p, (yyvsp[(2) - (4)].nd));
                      local_add_f(p, 0);
                    }
    break;

  case 527:
/* Line 1792 of yacc.c  */
#line 3515 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = list1((yyvsp[(1) - (1)].nd));
                    }
    break;

  case 528:
/* Line 1792 of yacc.c  */
#line 3519 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = push((yyvsp[(1) - (3)].nd), (yyvsp[(3) - (3)].nd));
                    }
    break;

  case 529:
/* Line 1792 of yacc.c  */
#line 3525 "D:\\Desktop\\parse.y"
    {
                      local_add_f(p, (yyvsp[(1) - (2)].id));
                      local_nest(p);
                      (yyval.id) = (yyvsp[(1) - (2)].id);
                    }
    break;

  case 530:
/* Line 1792 of yacc.c  */
#line 3533 "D:\\Desktop\\parse.y"
    {
                      void_expr_error(p, (yyvsp[(2) - (2)].nd));
                      (yyval.nd) = cons(nsym((yyvsp[(1) - (2)].id)), cons((yyvsp[(2) - (2)].nd), locals_node(p)));
                      local_unnest(p);
                    }
    break;

  case 531:
/* Line 1792 of yacc.c  */
#line 3541 "D:\\Desktop\\parse.y"
    {
                      void_expr_error(p, (yyvsp[(2) - (2)].nd));
                      (yyval.nd) = cons(nsym((yyvsp[(1) - (2)].id)), cons((yyvsp[(2) - (2)].nd), locals_node(p)));
                      local_unnest(p);
                    }
    break;

  case 532:
/* Line 1792 of yacc.c  */
#line 3549 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = list1((yyvsp[(1) - (1)].nd));
                    }
    break;

  case 533:
/* Line 1792 of yacc.c  */
#line 3553 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = push((yyvsp[(1) - (3)].nd), (yyvsp[(3) - (3)].nd));
                    }
    break;

  case 534:
/* Line 1792 of yacc.c  */
#line 3559 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = list1((yyvsp[(1) - (1)].nd));
                    }
    break;

  case 535:
/* Line 1792 of yacc.c  */
#line 3563 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = push((yyvsp[(1) - (3)].nd), (yyvsp[(3) - (3)].nd));
                    }
    break;

  case 538:
/* Line 1792 of yacc.c  */
#line 3573 "D:\\Desktop\\parse.y"
    {
                      local_add_f(p, (yyvsp[(2) - (2)].id));
                      (yyval.id) = (yyvsp[(2) - (2)].id);
                    }
    break;

  case 539:
/* Line 1792 of yacc.c  */
#line 3578 "D:\\Desktop\\parse.y"
    {
                      local_add_f(p, mrb_intern_lit(p->mrb, "*"));
                      (yyval.id) = -1;
                    }
    break;

  case 542:
/* Line 1792 of yacc.c  */
#line 3589 "D:\\Desktop\\parse.y"
    {
                      (yyval.id) = (yyvsp[(2) - (2)].id);
                    }
    break;

  case 543:
/* Line 1792 of yacc.c  */
#line 3595 "D:\\Desktop\\parse.y"
    {
                      (yyval.id) = (yyvsp[(2) - (2)].id);
                    }
    break;

  case 544:
/* Line 1792 of yacc.c  */
#line 3599 "D:\\Desktop\\parse.y"
    {
                      (yyval.id) = 0;
                    }
    break;

  case 545:
/* Line 1792 of yacc.c  */
#line 3605 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = (yyvsp[(1) - (1)].nd);
                      if (!(yyval.nd)) (yyval.nd) = new_nil(p);
                    }
    break;

  case 546:
/* Line 1792 of yacc.c  */
#line 3609 "D:\\Desktop\\parse.y"
    {p->lstate = EXPR_BEG;}
    break;

  case 547:
/* Line 1792 of yacc.c  */
#line 3610 "D:\\Desktop\\parse.y"
    {
                      if ((yyvsp[(3) - (4)].nd) == 0) {
                        yyerror(p, "can't define singleton method for ().");
                      }
                      else {
                        switch ((enum node_type)intn((yyvsp[(3) - (4)].nd)->car)) {
                        case NODE_STR:
                        case NODE_DSTR:
                        case NODE_XSTR:
                        case NODE_DXSTR:
                        case NODE_DREGX:
                        case NODE_MATCH:
                        case NODE_FLOAT:
                        case NODE_ARRAY:
                        case NODE_HEREDOC:
                          yyerror(p, "can't define singleton method for literals");
                        default:
                          break;
                        }
                      }
                      (yyval.nd) = (yyvsp[(3) - (4)].nd);
                    }
    break;

  case 549:
/* Line 1792 of yacc.c  */
#line 3636 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = (yyvsp[(1) - (2)].nd);
                    }
    break;

  case 550:
/* Line 1792 of yacc.c  */
#line 3642 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = list1((yyvsp[(1) - (1)].nd));
                      NODE_LINENO((yyval.nd), (yyvsp[(1) - (1)].nd));
                    }
    break;

  case 551:
/* Line 1792 of yacc.c  */
#line 3647 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = push((yyvsp[(1) - (3)].nd), (yyvsp[(3) - (3)].nd));
                    }
    break;

  case 552:
/* Line 1792 of yacc.c  */
#line 3653 "D:\\Desktop\\parse.y"
    {
                      void_expr_error(p, (yyvsp[(1) - (3)].nd));
                      void_expr_error(p, (yyvsp[(3) - (3)].nd));
                      (yyval.nd) = cons((yyvsp[(1) - (3)].nd), (yyvsp[(3) - (3)].nd));
                    }
    break;

  case 553:
/* Line 1792 of yacc.c  */
#line 3659 "D:\\Desktop\\parse.y"
    {
                      void_expr_error(p, (yyvsp[(3) - (3)].nd));
                      (yyval.nd) = cons(new_sym(p, (yyvsp[(1) - (3)].id)), (yyvsp[(3) - (3)].nd));
                    }
    break;

  case 554:
/* Line 1792 of yacc.c  */
#line 3664 "D:\\Desktop\\parse.y"
    {
                      void_expr_error(p, (yyvsp[(3) - (3)].nd));
                      if ((yyvsp[(1) - (3)].nd)->car == (node*)NODE_DSTR) {
                        (yyval.nd) = cons(new_dsym(p, (yyvsp[(1) - (3)].nd)), (yyvsp[(3) - (3)].nd));
                      }
                      else {
                        (yyval.nd) = cons(new_sym(p, new_strsym(p, (yyvsp[(1) - (3)].nd))), (yyvsp[(3) - (3)].nd));
                      }
                    }
    break;

  case 555:
/* Line 1792 of yacc.c  */
#line 3674 "D:\\Desktop\\parse.y"
    {
                      void_expr_error(p, (yyvsp[(2) - (2)].nd));
                      (yyval.nd) = cons(cons((node*)NODE_KW_REST_ARGS, 0), (yyvsp[(2) - (2)].nd));
                    }
    break;

  case 568:
/* Line 1792 of yacc.c  */
#line 3701 "D:\\Desktop\\parse.y"
    {
                      (yyval.num) = '.';
                    }
    break;

  case 569:
/* Line 1792 of yacc.c  */
#line 3705 "D:\\Desktop\\parse.y"
    {
                      (yyval.num) = 0;
                    }
    break;

  case 571:
/* Line 1792 of yacc.c  */
#line 3712 "D:\\Desktop\\parse.y"
    {
                      (yyval.num) = tCOLON2;
                    }
    break;

  case 581:
/* Line 1792 of yacc.c  */
#line 3736 "D:\\Desktop\\parse.y"
    {yyerrok;}
    break;

  case 584:
/* Line 1792 of yacc.c  */
#line 3742 "D:\\Desktop\\parse.y"
    {
                      p->lineno++;
                      p->column = 0;
                    }
    break;

  case 587:
/* Line 1792 of yacc.c  */
#line 3753 "D:\\Desktop\\parse.y"
    {
                      (yyval.nd) = 0;
                    }
    break;


/* Line 1792 of yacc.c  */
#line 9589 "D:\\Desktop\\y.tab.c"
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (p, YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (p, yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval, p);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, p);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (p, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, p);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, p);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


/* Line 2055 of yacc.c  */
#line 3757 "D:\\Desktop\\parse.y"

#define pylval  (*((YYSTYPE*)(p->ylval)))

static void
yyerror(parser_state *p, const char *s)
{
  char* c;
  size_t n;

  if (! p->capture_errors) {
#ifndef MRB_DISABLE_STDIO
    if (p->filename_sym) {
      const char *filename = mrb_sym_name_len(p->mrb, p->filename_sym, NULL);
      fprintf(stderr, "%s:%d:%d: %s\n", filename, p->lineno, p->column, s);
    }
    else {
      fprintf(stderr, "line %d:%d: %s\n", p->lineno, p->column, s);
    }
#endif
  }
  else if (p->nerr < sizeof(p->error_buffer) / sizeof(p->error_buffer[0])) {
    n = strlen(s);
    c = (char *)parser_palloc(p, n + 1);
    memcpy(c, s, n + 1);
    p->error_buffer[p->nerr].message = c;
    p->error_buffer[p->nerr].lineno = p->lineno;
    p->error_buffer[p->nerr].column = p->column;
  }
  p->nerr++;
}

static void
yyerror_c(parser_state *p, const char *msg, char c)
{
  char buf[256];

  strncpy(buf, msg, sizeof(buf) - 2);
  buf[sizeof(buf) - 2] = '\0';
  strncat(buf, &c, 1);
  yyerror(p, buf);
}

static void
yywarn(parser_state *p, const char *s)
{
  char* c;
  size_t n;

  if (! p->capture_errors) {
#ifndef MRB_DISABLE_STDIO
    if (p->filename_sym) {
      const char *filename = mrb_sym_name_len(p->mrb, p->filename_sym, NULL);
      fprintf(stderr, "%s:%d:%d: warning: %s\n", filename, p->lineno, p->column, s);
    }
    else {
      fprintf(stderr, "line %d:%d: warning: %s\n", p->lineno, p->column, s);
    }
#endif
  }
  else if (p->nwarn < sizeof(p->warn_buffer) / sizeof(p->warn_buffer[0])) {
    n = strlen(s);
    c = (char *)parser_palloc(p, n + 1);
    memcpy(c, s, n + 1);
    p->warn_buffer[p->nwarn].message = c;
    p->warn_buffer[p->nwarn].lineno = p->lineno;
    p->warn_buffer[p->nwarn].column = p->column;
  }
  p->nwarn++;
}

static void
yywarning(parser_state *p, const char *s)
{
  yywarn(p, s);
}

static void
yywarning_s(parser_state *p, const char *msg, const char *s)
{
  char buf[256];

  strncpy(buf, msg, sizeof(buf) - 1);
  buf[sizeof(buf) - 1] = '\0';
  strncat(buf, ": ", sizeof(buf) - strlen(buf) - 1);
  strncat(buf, s, sizeof(buf) - strlen(buf) - 1);
  yywarning(p, buf);
}

static void
backref_error(parser_state *p, node *n)
{
  int c;

  c = intn(n->car);

  if (c == NODE_NTH_REF) {
    yyerror_c(p, "can't set variable $", (char)intn(n->cdr)+'0');
  }
  else if (c == NODE_BACK_REF) {
    yyerror_c(p, "can't set variable $", (char)intn(n->cdr));
  }
  else {
    mrb_bug(p->mrb, "Internal error in backref_error() : n=>car == %d", c);
  }
}

static void
void_expr_error(parser_state *p, node *n)
{
  int c;

  if (n == NULL) return;
  c = intn(n->car);
  switch (c) {
  case NODE_BREAK:
  case NODE_RETURN:
  case NODE_NEXT:
  case NODE_REDO:
  case NODE_RETRY:
    yyerror(p, "void value expression");
    break;
  case NODE_AND:
  case NODE_OR:
    if (n->cdr) {
      void_expr_error(p, n->cdr->car);
      void_expr_error(p, n->cdr->cdr);
    }
    break;
  case NODE_BEGIN:
    if (n->cdr) {
      while (n->cdr) {
        n = n->cdr;
      }
      void_expr_error(p, n->car);
    }
    break;
  default:
    break;
  }
}

static void pushback(parser_state *p, int c);
static mrb_bool peeks(parser_state *p, const char *s);
static mrb_bool skips(parser_state *p, const char *s);

static inline int
nextc(parser_state *p)
{
  int c;

  if (p->pb) {
    node *tmp;

    c = intn(p->pb->car);
    tmp = p->pb;
    p->pb = p->pb->cdr;
    cons_free(tmp);
  }
  else {
#ifndef MRB_DISABLE_STDIO
    if (p->f) {
      if (feof(p->f)) goto eof;
      c = fgetc(p->f);
      if (c == EOF) goto eof;
    }
    else
#endif
      if (!p->s || p->s >= p->send) {
        goto eof;
      }
      else {
        c = (unsigned char)*p->s++;
      }
  }
  if (c >= 0) {
    p->column++;
  }
  return c;

  eof:
  if (!p->cxt) return -1;
  else {
    if (p->cxt->partial_hook(p) < 0)
      return -1;                /* end of program(s) */
    return -2;                  /* end of a file in the program files */
  }
}

static void
pushback(parser_state *p, int c)
{
  if (c >= 0) {
    p->column--;
  }
  p->pb = cons(nint(c), p->pb);
}

static void
skip(parser_state *p, char term)
{
  int c;

  for (;;) {
    c = nextc(p);
    if (c < 0) break;
    if (c == term) break;
  }
}

static int
peekc_n(parser_state *p, int n)
{
  node *list = 0;
  int c0;

  do {
    c0 = nextc(p);
    if (c0 == -1) return c0;    /* do not skip partial EOF */
    if (c0 >= 0) --p->column;
    list = push(list, nint(c0));
  } while(n--);
  if (p->pb) {
    p->pb = append((node*)list, p->pb);
  }
  else {
    p->pb = list;
  }
  return c0;
}

static mrb_bool
peek_n(parser_state *p, int c, int n)
{
  return peekc_n(p, n) == c && c >= 0;
}
#define peek(p,c) peek_n((p), (c), 0)

static mrb_bool
peeks(parser_state *p, const char *s)
{
  size_t len = strlen(s);

#ifndef MRB_DISABLE_STDIO
  if (p->f) {
    int n = 0;
    while (*s) {
      if (!peek_n(p, *s++, n++)) return FALSE;
    }
    return TRUE;
  }
  else
#endif
    if (p->s && p->s + len <= p->send) {
      if (memcmp(p->s, s, len) == 0) return TRUE;
    }
  return FALSE;
}

static mrb_bool
skips(parser_state *p, const char *s)
{
  int c;

  for (;;) {
    /* skip until first char */
    for (;;) {
      c = nextc(p);
      if (c < 0) return FALSE;
      if (c == '\n') {
        p->lineno++;
        p->column = 0;
      }
      if (c == *s) break;
    }
    s++;
    if (peeks(p, s)) {
      size_t len = strlen(s);

      while (len--) {
        if (nextc(p) == '\n') {
          p->lineno++;
          p->column = 0;
        }
      }
      return TRUE;
    }
    else{
      s--;
    }
  }
  return FALSE;
}


static int
newtok(parser_state *p)
{
  if (p->tokbuf != p->buf) {
    mrb_free(p->mrb, p->tokbuf);
    p->tokbuf = p->buf;
    p->tsiz = MRB_PARSER_TOKBUF_SIZE;
  }
  p->tidx = 0;
  return p->column - 1;
}

static void
tokadd(parser_state *p, int32_t c)
{
  char utf8[4];
  int i, len;

  /* mrb_assert(-0x10FFFF <= c && c <= 0xFF); */
  if (c >= 0) {
    /* Single byte from source or non-Unicode escape */
    utf8[0] = (char)c;
    len = 1;
  }
  else {
    /* Unicode character */
    c = -c;
    if (c < 0x80) {
      utf8[0] = (char)c;
      len = 1;
    }
    else if (c < 0x800) {
      utf8[0] = (char)(0xC0 | (c >> 6));
      utf8[1] = (char)(0x80 | (c & 0x3F));
      len = 2;
    }
    else if (c < 0x10000) {
      utf8[0] = (char)(0xE0 |  (c >> 12)        );
      utf8[1] = (char)(0x80 | ((c >>  6) & 0x3F));
      utf8[2] = (char)(0x80 | ( c        & 0x3F));
      len = 3;
    }
    else {
      utf8[0] = (char)(0xF0 |  (c >> 18)        );
      utf8[1] = (char)(0x80 | ((c >> 12) & 0x3F));
      utf8[2] = (char)(0x80 | ((c >>  6) & 0x3F));
      utf8[3] = (char)(0x80 | ( c        & 0x3F));
      len = 4;
    }
  }
  if (p->tidx+len >= p->tsiz) {
    if (p->tsiz >= MRB_PARSER_TOKBUF_MAX) {
      p->tidx += len;
      return;
    }
    p->tsiz *= 2;
    if (p->tokbuf == p->buf) {
      p->tokbuf = (char*)mrb_malloc(p->mrb, p->tsiz);
      memcpy(p->tokbuf, p->buf, MRB_PARSER_TOKBUF_SIZE);
    }
    else {
      p->tokbuf = (char*)mrb_realloc(p->mrb, p->tokbuf, p->tsiz);
    }
  }
  for (i = 0; i < len; i++) {
    p->tokbuf[p->tidx++] = utf8[i];
  }
}

static int
toklast(parser_state *p)
{
  return p->tokbuf[p->tidx-1];
}

static void
tokfix(parser_state *p)
{
  if (p->tidx >= MRB_PARSER_TOKBUF_MAX) {
    p->tidx = MRB_PARSER_TOKBUF_MAX-1;
    yyerror(p, "string too long (truncated)");
  }
  p->tokbuf[p->tidx] = '\0';
}

static const char*
tok(parser_state *p)
{
  return p->tokbuf;
}

static int
toklen(parser_state *p)
{
  return p->tidx;
}

#define IS_ARG() (p->lstate == EXPR_ARG || p->lstate == EXPR_CMDARG)
#define IS_END() (p->lstate == EXPR_END || p->lstate == EXPR_ENDARG || p->lstate == EXPR_ENDFN)
#define IS_BEG() (p->lstate == EXPR_BEG || p->lstate == EXPR_MID || p->lstate == EXPR_VALUE || p->lstate == EXPR_CLASS)
#define IS_SPCARG(c) (IS_ARG() && space_seen && !ISSPACE(c))
#define IS_LABEL_POSSIBLE() ((p->lstate == EXPR_BEG && !cmd_state) || IS_ARG())
#define IS_LABEL_SUFFIX(n) (peek_n(p, ':',(n)) && !peek_n(p, ':', (n)+1))

static int32_t
scan_oct(const int *start, int len, int *retlen)
{
  const int *s = start;
  int32_t retval = 0;

  /* mrb_assert(len <= 3) */
  while (len-- && *s >= '0' && *s <= '7') {
    retval <<= 3;
    retval |= *s++ - '0';
  }
  *retlen = (int)(s - start);

  return retval;
}

static int32_t
scan_hex(parser_state *p, const int *start, int len, int *retlen)
{
  static const char hexdigit[] = "0123456789abcdef0123456789ABCDEF";
  const int *s = start;
  uint32_t retval = 0;
  char *tmp;

  /* mrb_assert(len <= 8) */
  while (len-- && *s && (tmp = (char*)strchr(hexdigit, *s))) {
    retval <<= 4;
    retval |= (tmp - hexdigit) & 15;
    s++;
  }
  *retlen = (int)(s - start);

  return (int32_t)retval;
}

static int32_t
read_escape_unicode(parser_state *p, int limit)
{
  int buf[9];
  int i;
  int32_t hex;

  /* Look for opening brace */
  i = 0;
  buf[0] = nextc(p);
  if (buf[0] < 0) {
  eof:
    yyerror(p, "invalid escape character syntax");
    return -1;
  }
  if (ISXDIGIT(buf[0])) {
    /* \uxxxx form */
    for (i=1; i<limit; i++) {
      buf[i] = nextc(p);
      if (buf[i] < 0) goto eof;
      if (!ISXDIGIT(buf[i])) {
        pushback(p, buf[i]);
        break;
      }
    }
  }
  else {
    pushback(p, buf[0]);
  }
  hex = scan_hex(p, buf, i, &i);
  if (i == 0 || hex > 0x10FFFF || (hex & 0xFFFFF800) == 0xD800) {
    yyerror(p, "invalid Unicode code point");
    return -1;
  }
  return hex;
}

/* Return negative to indicate Unicode code point */
static int32_t
read_escape(parser_state *p)
{
  int32_t c;

  switch (c = nextc(p)) {
  case '\\':/* Backslash */
    return c;

  case 'n':/* newline */
    return '\n';

  case 't':/* horizontal tab */
    return '\t';

  case 'r':/* carriage-return */
    return '\r';

  case 'f':/* form-feed */
    return '\f';

  case 'v':/* vertical tab */
    return '\13';

  case 'a':/* alarm(bell) */
    return '\007';

  case 'e':/* escape */
    return 033;

  case '0': case '1': case '2': case '3': /* octal constant */
  case '4': case '5': case '6': case '7':
  {
    int buf[3];
    int i;

    buf[0] = c;
    for (i=1; i<3; i++) {
      buf[i] = nextc(p);
      if (buf[i] < 0) goto eof;
      if (buf[i] < '0' || '7' < buf[i]) {
        pushback(p, buf[i]);
        break;
      }
    }
    c = scan_oct(buf, i, &i);
  }
  return c;

  case 'x':     /* hex constant */
  {
    int buf[2];
    int i;

    for (i=0; i<2; i++) {
      buf[i] = nextc(p);
      if (buf[i] < 0) goto eof;
      if (!ISXDIGIT(buf[i])) {
        pushback(p, buf[i]);
        break;
      }
    }
    if (i == 0) {
      yyerror(p, "invalid hex escape");
      return -1;
    }
    return scan_hex(p, buf, i, &i);
  }

  case 'u':     /* Unicode */
    if (peek(p, '{')) {
      /* \u{xxxxxxxx} form */
      nextc(p);
      c = read_escape_unicode(p, 8);
      if (c < 0) return 0;
      if (nextc(p) != '}') goto eof;
    }
    else {
      c = read_escape_unicode(p, 4);
      if (c < 0) return 0;
    }
  return -c;

  case 'b':/* backspace */
    return '\010';

  case 's':/* space */
    return ' ';

  case 'M':
    if ((c = nextc(p)) != '-') {
      yyerror(p, "Invalid escape character syntax");
      pushback(p, c);
      return '\0';
    }
    if ((c = nextc(p)) == '\\') {
      return read_escape(p) | 0x80;
    }
    else if (c < 0) goto eof;
    else {
      return ((c & 0xff) | 0x80);
    }

  case 'C':
    if ((c = nextc(p)) != '-') {
      yyerror(p, "Invalid escape character syntax");
      pushback(p, c);
      return '\0';
    }
  case 'c':
    if ((c = nextc(p))== '\\') {
      c = read_escape(p);
    }
    else if (c == '?')
      return 0177;
    else if (c < 0) goto eof;
    return c & 0x9f;

    eof:
  case -1:
  case -2:                      /* end of a file */
    yyerror(p, "Invalid escape character syntax");
    return '\0';

  default:
    return c;
  }
}

static int
parse_string(parser_state *p)
{
  int c;
  string_type type = (string_type)(intptr_t)p->lex_strterm->car;
  int nest_level = intn(p->lex_strterm->cdr->car);
  int beg = intn(p->lex_strterm->cdr->cdr->car);
  int end = intn(p->lex_strterm->cdr->cdr->cdr);
  parser_heredoc_info *hinf = (type & STR_FUNC_HEREDOC) ? parsing_heredoc_inf(p) : NULL;

  if (beg == 0) beg = -3;       /* should never happen */
  if (end == 0) end = -3;
  newtok(p);
  while ((c = nextc(p)) != end || nest_level != 0) {
    if (hinf && (c == '\n' || c < 0)) {
      mrb_bool line_head;
      tokadd(p, '\n');
      tokfix(p);
      p->lineno++;
      p->column = 0;
      line_head = hinf->line_head;
      hinf->line_head = TRUE;
      if (line_head) {
        /* check whether end of heredoc */
        const char *s = tok(p);
        int len = toklen(p);
        if (hinf->allow_indent) {
          while (ISSPACE(*s) && len > 0) {
            ++s;
            --len;
          }
        }
        if ((len-1 == hinf->term_len) && (strncmp(s, hinf->term, len-1) == 0)) {
          if (c < 0) {
            p->parsing_heredoc = NULL;
          }
          else {
            return tHEREDOC_END;
          }
        }
      }
      if (c < 0) {
        char buf[256];
        const char s1[] = "can't find heredoc delimiter \"";
        const char s2[] = "\" anywhere before EOF";

        if (sizeof(s1)+sizeof(s2)+strlen(hinf->term)+1 >= sizeof(buf)) {
          yyerror(p, "can't find heredoc delimiter anywhere before EOF");
        } else {
          strcpy(buf, s1);
          strcat(buf, hinf->term);
          strcat(buf, s2);
          yyerror(p, buf);
        }
        return 0;
      }
      pylval.nd = new_str(p, tok(p), toklen(p));
      return tHD_STRING_MID;
    }
    if (c < 0) {
      yyerror(p, "unterminated string meets end of file");
      return 0;
    }
    else if (c == beg) {
      nest_level++;
      p->lex_strterm->cdr->car = nint(nest_level);
    }
    else if (c == end) {
      nest_level--;
      p->lex_strterm->cdr->car = nint(nest_level);
    }
    else if (c == '\\') {
      c = nextc(p);
      if (type & STR_FUNC_EXPAND) {
        if (c == end || c == beg) {
          tokadd(p, c);
        }
        else if (c == '\n') {
          p->lineno++;
          p->column = 0;
          if (type & STR_FUNC_ARRAY) {
            tokadd(p, '\n');
          }
        }
        else if (type & STR_FUNC_REGEXP) {
          tokadd(p, '\\');
          tokadd(p, c);
        }
        else if (c == 'u' && peek(p, '{')) {
          /* \u{xxxx xxxx xxxx} form */
          nextc(p);
          while (1) {
            do c = nextc(p); while (ISSPACE(c));
            if (c == '}') break;
            pushback(p, c);
            c = read_escape_unicode(p, 8);
            if (c < 0) break;
            tokadd(p, -c);
          }
          if (hinf)
            hinf->line_head = FALSE;
        }
        else {
          pushback(p, c);
          tokadd(p, read_escape(p));
          if (hinf)
            hinf->line_head = FALSE;
        }
      }
      else {
        if (c != beg && c != end) {
          if (c == '\n') {
            p->lineno++;
            p->column = 0;
          }
          if (!(c == '\\' || ((type & STR_FUNC_ARRAY) && ISSPACE(c)))) {
            tokadd(p, '\\');
          }
        }
        tokadd(p, c);
      }
      continue;
    }
    else if ((c == '#') && (type & STR_FUNC_EXPAND)) {
      c = nextc(p);
      if (c == '{') {
        tokfix(p);
        p->lstate = EXPR_BEG;
        p->cmd_start = TRUE;
        pylval.nd = new_str(p, tok(p), toklen(p));
        if (hinf) {
          hinf->line_head = FALSE;
          return tHD_STRING_PART;
        }
        return tSTRING_PART;
      }
      tokadd(p, '#');
      pushback(p, c);
      continue;
    }
    if ((type & STR_FUNC_ARRAY) && ISSPACE(c)) {
      if (toklen(p) == 0) {
        do {
          if (c == '\n') {
            p->lineno++;
            p->column = 0;
            heredoc_treat_nextline(p);
            if (p->parsing_heredoc != NULL) {
              return tHD_LITERAL_DELIM;
            }
          }
          c = nextc(p);
        } while (ISSPACE(c));
        pushback(p, c);
        return tLITERAL_DELIM;
      }
      else {
        pushback(p, c);
        tokfix(p);
        pylval.nd = new_str(p, tok(p), toklen(p));
        return tSTRING_MID;
      }
    }
    if (c == '\n') {
      p->lineno++;
      p->column = 0;
    }
    tokadd(p, c);
  }

  tokfix(p);
  p->lstate = EXPR_ENDARG;
  end_strterm(p);

  if (type & STR_FUNC_XQUOTE) {
    pylval.nd = new_xstr(p, tok(p), toklen(p));
    return tXSTRING;
  }

  if (type & STR_FUNC_REGEXP) {
    int f = 0;
    int re_opt;
    char *s = strndup(tok(p), toklen(p));
    char flags[3];
    char *flag = flags;
    char enc = '\0';
    char *encp;
    char *dup;

    newtok(p);
    while (re_opt = nextc(p), re_opt >= 0 && ISALPHA(re_opt)) {
      switch (re_opt) {
      case 'i': f |= 1; break;
      case 'x': f |= 2; break;
      case 'm': f |= 4; break;
      case 'u': f |= 16; break;
      case 'n': f |= 32; break;
      case 'o': break;
      default: tokadd(p, re_opt); break;
      }
    }
    pushback(p, re_opt);
    if (toklen(p)) {
      char msg[128];

      strcpy(msg, "unknown regexp option");
      tokfix(p);
      if (toklen(p) > 1) {
        strcat(msg, "s");
      }
      strcat(msg, " - ");
      strncat(msg, tok(p), sizeof(msg) - strlen(msg) - 1);
      yyerror(p, msg);
    }
    if (f != 0) {
      if (f & 1) *flag++ = 'i';
      if (f & 2) *flag++ = 'x';
      if (f & 4) *flag++ = 'm';
      if (f & 16) enc = 'u';
      if (f & 32) enc = 'n';
    }
    if (flag > flags) {
      dup = strndup(flags, (size_t)(flag - flags));
    }
    else {
      dup = NULL;
    }
    if (enc) {
      encp = strndup(&enc, 1);
    }
    else {
      encp = NULL;
    }
    pylval.nd = new_regx(p, s, dup, encp);

    return tREGEXP;
  }
  pylval.nd = new_str(p, tok(p), toklen(p));

  return tSTRING;
}

#ifdef MRB_SUFFIX_SUPPORT
static int
number_literal_suffix(parser_state *p, int mask)
{
  int c, result = 0;
  node *list = 0;
  int column = p->column;

  while ((c = nextc(p)) != -1) {
    list = push(list, (node*)(intptr_t)c);

    if ((mask & NUM_SUFFIX_I) && c == 'i') {
      result |= (mask & NUM_SUFFIX_I);
      mask &= ~NUM_SUFFIX_I;
      /* r after i, rational of complex is disallowed */
      mask &= ~NUM_SUFFIX_R;
      continue;
    }
    if ((mask & NUM_SUFFIX_R) && c == 'r') {
      result |= (mask & NUM_SUFFIX_R);
      mask &= ~NUM_SUFFIX_R;
      continue;
    }
    if (!ISASCII(c) || ISALPHA(c) || c == '_') {
      p->column = column;
      if (p->pb) {
        p->pb = append((node*)list, p->pb);
      }
      else {
        p->pb = list;
      }
      return 0;
    }
    pushback(p, c);
    break;
  }
  return result;
}
#endif

static int
heredoc_identifier(parser_state *p)
{
  int c;
  int type = str_heredoc;
  mrb_bool indent = FALSE;
  mrb_bool quote = FALSE;
  node *newnode;
  parser_heredoc_info *info;

  c = nextc(p);
  if (ISSPACE(c) || c == '=') {
    pushback(p, c);
    return 0;
  }
  if (c == '-') {
    indent = TRUE;
    c = nextc(p);
  }
  if (c == '\'' || c == '"') {
    int term = c;
    if (c == '\'')
      quote = TRUE;
    newtok(p);
    while ((c = nextc(p)) >= 0 && c != term) {
      if (c == '\n') {
        c = -1;
        break;
      }
      tokadd(p, c);
    }
    if (c < 0) {
      yyerror(p, "unterminated here document identifier");
      return 0;
    }
  }
  else {
    if (c < 0) {
      return 0;                 /* missing here document identifier */
    }
    if (! identchar(c)) {
      pushback(p, c);
      if (indent) pushback(p, '-');
      return 0;
    }
    newtok(p);
    do {
      tokadd(p, c);
    } while ((c = nextc(p)) >= 0 && identchar(c));
    pushback(p, c);
  }
  tokfix(p);
  newnode = new_heredoc(p);
  info = (parser_heredoc_info*)newnode->cdr;
  info->term = strndup(tok(p), toklen(p));
  info->term_len = toklen(p);
  if (! quote)
    type |= STR_FUNC_EXPAND;
  info->type = (string_type)type;
  info->allow_indent = indent;
  info->line_head = TRUE;
  info->doc = NULL;
  p->heredocs_from_nextline = push(p->heredocs_from_nextline, newnode);
  p->lstate = EXPR_END;

  pylval.nd = newnode;
  return tHEREDOC_BEG;
}

static int
arg_ambiguous(parser_state *p)
{
  yywarning(p, "ambiguous first argument; put parentheses or even spaces");
  return 1;
}

#include "lex.def"

static int
parser_yylex(parser_state *p)
{
  int32_t c;
  int space_seen = 0;
  int cmd_state;
  enum mrb_lex_state_enum last_state;
  int token_column;

  if (p->lex_strterm) {
    if (is_strterm_type(p, STR_FUNC_HEREDOC)) {
      if (p->parsing_heredoc != NULL)
        return parse_string(p);
    }
    else
      return parse_string(p);
  }
  cmd_state = p->cmd_start;
  p->cmd_start = FALSE;
  retry:
  last_state = p->lstate;
  switch (c = nextc(p)) {
  case '\004':  /* ^D */
  case '\032':  /* ^Z */
  case '\0':    /* NUL */
  case -1:      /* end of script. */
    if (p->heredocs_from_nextline)
      goto maybe_heredoc;
    return 0;

  /* white spaces */
  case ' ': case '\t': case '\f': case '\r':
  case '\13':   /* '\v' */
    space_seen = 1;
    goto retry;

  case '#':     /* it's a comment */
    skip(p, '\n');
    /* fall through */
  case -2:      /* end of a file */
  case '\n':
  maybe_heredoc:
    heredoc_treat_nextline(p);
    p->column = 0;
    switch (p->lstate) {
    case EXPR_BEG:
    case EXPR_FNAME:
    case EXPR_DOT:
    case EXPR_CLASS:
    case EXPR_VALUE:
      p->lineno++;
      if (p->parsing_heredoc != NULL) {
        if (p->lex_strterm) {
          return parse_string(p);
        }
      }
      goto retry;
    default:
      break;
    }
    if (p->parsing_heredoc != NULL) {
      return '\n';
    }
    while ((c = nextc(p))) {
      switch (c) {
      case ' ': case '\t': case '\f': case '\r':
      case '\13': /* '\v' */
        space_seen = 1;
        break;
      case '#': /* comment as a whitespace */
        pushback(p, '#');
        p->lineno++;
        goto retry;
      case '.':
        if (!peek(p, '.')) {
          pushback(p, '.');
          p->lineno++;
          goto retry;
        }
        pushback(p, c);
        goto normal_newline;
      case '&':
        if (peek(p, '.')) {
          pushback(p, '&');
          p->lineno++;
          goto retry;
        }
        pushback(p, c);
        goto normal_newline;
      case -1:                  /* EOF */
      case -2:                  /* end of a file */
        goto normal_newline;
      default:
        pushback(p, c);
        goto normal_newline;
      }
    }
  normal_newline:
    p->cmd_start = TRUE;
    p->lstate = EXPR_BEG;
    return '\n';

  case '*':
    if ((c = nextc(p)) == '*') {
      if ((c = nextc(p)) == '=') {
        pylval.id = intern("**",2);
        p->lstate = EXPR_BEG;
        return tOP_ASGN;
      }
      pushback(p, c);
      if (IS_SPCARG(c)) {
        yywarning(p, "'**' interpreted as argument prefix");
        c = tDSTAR;
      }
      else if (IS_BEG()) {
        c = tDSTAR;
      }
      else {
        c = tPOW; /* "**", "argument prefix" */
      }
    }
    else {
      if (c == '=') {
        pylval.id = intern_c('*');
        p->lstate = EXPR_BEG;
        return tOP_ASGN;
      }
      pushback(p, c);
      if (IS_SPCARG(c)) {
        yywarning(p, "'*' interpreted as argument prefix");
        c = tSTAR;
      }
      else if (IS_BEG()) {
        c = tSTAR;
      }
      else {
        c = '*';
      }
    }
    if (p->lstate == EXPR_FNAME || p->lstate == EXPR_DOT) {
      p->lstate = EXPR_ARG;
    }
    else {
      p->lstate = EXPR_BEG;
    }
    return c;

  case '!':
    c = nextc(p);
    if (p->lstate == EXPR_FNAME || p->lstate == EXPR_DOT) {
      p->lstate = EXPR_ARG;
      if (c == '@') {
        return '!';
      }
    }
    else {
      p->lstate = EXPR_BEG;
    }
    if (c == '=') {
      return tNEQ;
    }
    if (c == '~') {
      return tNMATCH;
    }
    pushback(p, c);
    return '!';

  case '=':
    if (p->column == 1) {
      static const char begin[] = "begin";
      static const char end[] = "\n=end";
      if (peeks(p, begin)) {
        c = peekc_n(p, sizeof(begin)-1);
        if (c < 0 || ISSPACE(c)) {
          do {
            if (!skips(p, end)) {
              yyerror(p, "embedded document meets end of file");
              return 0;
            }
            c = nextc(p);
          } while (!(c < 0 || ISSPACE(c)));
          if (c != '\n') skip(p, '\n');
          p->lineno++;
          p->column = 0;
          goto retry;
        }
      }
    }
    if (p->lstate == EXPR_FNAME || p->lstate == EXPR_DOT) {
      p->lstate = EXPR_ARG;
    }
    else {
      p->lstate = EXPR_BEG;
    }
    if ((c = nextc(p)) == '=') {
      if ((c = nextc(p)) == '=') {
        return tEQQ;
      }
      pushback(p, c);
      return tEQ;
    }
    if (c == '~') {
      return tMATCH;
    }
    else if (c == '>') {
      return tASSOC;
    }
    pushback(p, c);
    return '=';

  case '<':
    c = nextc(p);
    if (c == '<' &&
        p->lstate != EXPR_DOT &&
        p->lstate != EXPR_CLASS &&
        !IS_END() &&
        (!IS_ARG() || space_seen)) {
      int token = heredoc_identifier(p);
      if (token)
        return token;
    }
    if (p->lstate == EXPR_FNAME || p->lstate == EXPR_DOT) {
      p->lstate = EXPR_ARG;
    }
    else {
      p->lstate = EXPR_BEG;
      if (p->lstate == EXPR_CLASS) {
        p->cmd_start = TRUE;
      }
    }
    if (c == '=') {
      if ((c = nextc(p)) == '>') {
        return tCMP;
      }
      pushback(p, c);
      return tLEQ;
    }
    if (c == '<') {
      if ((c = nextc(p)) == '=') {
        pylval.id = intern("<<",2);
        p->lstate = EXPR_BEG;
        return tOP_ASGN;
      }
      pushback(p, c);
      return tLSHFT;
    }
    pushback(p, c);
    return '<';

  case '>':
    if (p->lstate == EXPR_FNAME || p->lstate == EXPR_DOT) {
      p->lstate = EXPR_ARG;
    }
    else {
      p->lstate = EXPR_BEG;
    }
    if ((c = nextc(p)) == '=') {
      return tGEQ;
    }
    if (c == '>') {
      if ((c = nextc(p)) == '=') {
        pylval.id = intern(">>",2);
        p->lstate = EXPR_BEG;
        return tOP_ASGN;
      }
      pushback(p, c);
      return tRSHFT;
    }
    pushback(p, c);
    return '>';

  case '"':
    p->lex_strterm = new_strterm(p, str_dquote, '"', 0);
    return tSTRING_BEG;

  case '\'':
    p->lex_strterm = new_strterm(p, str_squote, '\'', 0);
    return parse_string(p);

  case '`':
    if (p->lstate == EXPR_FNAME) {
      p->lstate = EXPR_ENDFN;
      return '`';
    }
    if (p->lstate == EXPR_DOT) {
      if (cmd_state)
        p->lstate = EXPR_CMDARG;
      else
        p->lstate = EXPR_ARG;
      return '`';
    }
    p->lex_strterm = new_strterm(p, str_xquote, '`', 0);
    return tXSTRING_BEG;

  case '?':
    if (IS_END()) {
      p->lstate = EXPR_VALUE;
      return '?';
    }
    c = nextc(p);
    if (c < 0) {
      yyerror(p, "incomplete character syntax");
      return 0;
    }
    if (ISSPACE(c)) {
      if (!IS_ARG()) {
        int c2;
        switch (c) {
        case ' ':
          c2 = 's';
          break;
        case '\n':
          c2 = 'n';
          break;
        case '\t':
          c2 = 't';
          break;
        case '\v':
          c2 = 'v';
          break;
        case '\r':
          c2 = 'r';
          break;
        case '\f':
          c2 = 'f';
          break;
        default:
          c2 = 0;
          break;
        }
        if (c2) {
          char buf[256];
          char cc[] = { (char)c2, '\0' };

          strcpy(buf, "invalid character syntax; use ?\\");
          strncat(buf, cc, 2);
          yyerror(p, buf);
        }
      }
      ternary:
      pushback(p, c);
      p->lstate = EXPR_VALUE;
      return '?';
    }
    newtok(p);
    /* need support UTF-8 if configured */
    if ((ISALNUM(c) || c == '_')) {
      int c2 = nextc(p);
      pushback(p, c2);
      if ((ISALNUM(c2) || c2 == '_')) {
        goto ternary;
      }
    }
    if (c == '\\') {
      c = read_escape(p);
      tokadd(p, c);
    }
    else {
      tokadd(p, c);
    }
    tokfix(p);
    pylval.nd = new_str(p, tok(p), toklen(p));
    p->lstate = EXPR_ENDARG;
    return tCHAR;

  case '&':
    if ((c = nextc(p)) == '&') {
      p->lstate = EXPR_BEG;
      if ((c = nextc(p)) == '=') {
        pylval.id = intern("&&",2);
        p->lstate = EXPR_BEG;
        return tOP_ASGN;
      }
      pushback(p, c);
      return tANDOP;
    }
    else if (c == '.') {
      p->lstate = EXPR_DOT;
      return tANDDOT;
    }
    else if (c == '=') {
      pylval.id = intern_c('&');
      p->lstate = EXPR_BEG;
      return tOP_ASGN;
    }
    pushback(p, c);
    if (IS_SPCARG(c)) {
      yywarning(p, "'&' interpreted as argument prefix");
      c = tAMPER;
    }
    else if (IS_BEG()) {
      c = tAMPER;
    }
    else {
      c = '&';
    }
    if (p->lstate == EXPR_FNAME || p->lstate == EXPR_DOT) {
      p->lstate = EXPR_ARG;
    }
    else {
      p->lstate = EXPR_BEG;
    }
    return c;

  case '|':
    if ((c = nextc(p)) == '|') {
      p->lstate = EXPR_BEG;
      if ((c = nextc(p)) == '=') {
        pylval.id = intern("||",2);
        p->lstate = EXPR_BEG;
        return tOP_ASGN;
      }
      pushback(p, c);
      return tOROP;
    }
    if (c == '=') {
      pylval.id = intern_c('|');
      p->lstate = EXPR_BEG;
      return tOP_ASGN;
    }
    if (p->lstate == EXPR_FNAME || p->lstate == EXPR_DOT) {
      p->lstate = EXPR_ARG;
    }
    else {
      p->lstate = EXPR_BEG;
    }
    pushback(p, c);
    return '|';

  case '+':
    c = nextc(p);
    if (p->lstate == EXPR_FNAME || p->lstate == EXPR_DOT) {
      p->lstate = EXPR_ARG;
      if (c == '@') {
        return tUPLUS;
      }
      pushback(p, c);
      return '+';
    }
    if (c == '=') {
      pylval.id = intern_c('+');
      p->lstate = EXPR_BEG;
      return tOP_ASGN;
    }
    if (IS_BEG() || (IS_SPCARG(c) && arg_ambiguous(p))) {
      p->lstate = EXPR_BEG;
      pushback(p, c);
      if (c >= 0 && ISDIGIT(c)) {
        c = '+';
        goto start_num;
      }
      return tUPLUS;
    }
    p->lstate = EXPR_BEG;
    pushback(p, c);
    return '+';

  case '-':
    c = nextc(p);
    if (p->lstate == EXPR_FNAME || p->lstate == EXPR_DOT) {
      p->lstate = EXPR_ARG;
      if (c == '@') {
        return tUMINUS;
      }
      pushback(p, c);
      return '-';
    }
    if (c == '=') {
      pylval.id = intern_c('-');
      p->lstate = EXPR_BEG;
      return tOP_ASGN;
    }
    if (c == '>') {
      p->lstate = EXPR_ENDFN;
      return tLAMBDA;
    }
    if (IS_BEG() || (IS_SPCARG(c) && arg_ambiguous(p))) {
      p->lstate = EXPR_BEG;
      pushback(p, c);
      if (c >= 0 && ISDIGIT(c)) {
        return tUMINUS_NUM;
      }
      return tUMINUS;
    }
    p->lstate = EXPR_BEG;
    pushback(p, c);
    return '-';

  case '.':
    p->lstate = EXPR_BEG;
    if ((c = nextc(p)) == '.') {
      if ((c = nextc(p)) == '.') {
        return tDOT3;
      }
      pushback(p, c);
      return tDOT2;
    }
    pushback(p, c);
    if (c >= 0 && ISDIGIT(c)) {
      yyerror(p, "no .<digit> floating literal anymore; put 0 before dot");
    }
    p->lstate = EXPR_DOT;
    return '.';

    start_num:
  case '0': case '1': case '2': case '3': case '4':
  case '5': case '6': case '7': case '8': case '9':
  {
    int is_float, seen_point, seen_e, nondigit;
    int suffix = 0;

    is_float = seen_point = seen_e = nondigit = 0;
    p->lstate = EXPR_ENDARG;
    newtok(p);
    if (c == '-' || c == '+') {
      tokadd(p, c);
      c = nextc(p);
    }
    if (c == '0') {
#define no_digits() do {yyerror(p,"numeric literal without digits"); return 0;} while (0)
      int start = toklen(p);
      c = nextc(p);
      if (c == 'x' || c == 'X') {
        /* hexadecimal */
        c = nextc(p);
        if (c >= 0 && ISXDIGIT(c)) {
          do {
            if (c == '_') {
              if (nondigit) break;
              nondigit = c;
              continue;
            }
            if (!ISXDIGIT(c)) break;
            nondigit = 0;
            tokadd(p, tolower(c));
          } while ((c = nextc(p)) >= 0);
        }
        pushback(p, c);
        tokfix(p);
        if (toklen(p) == start) {
          no_digits();
        }
        else if (nondigit) goto trailing_uc;
        #ifdef MRB_SUFFIX_SUPPORT
        suffix = number_literal_suffix(p, NUM_SUFFIX_ALL);
        #endif
        pylval.nd = new_int(p, tok(p), 16, suffix);
        return tINTEGER;
      }
      if (c == 'b' || c == 'B') {
        /* binary */
        c = nextc(p);
        if (c == '0' || c == '1') {
          do {
            if (c == '_') {
              if (nondigit) break;
              nondigit = c;
              continue;
            }
            if (c != '0' && c != '1') break;
            nondigit = 0;
            tokadd(p, c);
          } while ((c = nextc(p)) >= 0);
        }
        pushback(p, c);
        tokfix(p);
        if (toklen(p) == start) {
          no_digits();
        }
        else if (nondigit) goto trailing_uc;
        #ifdef MRB_SUFFIX_SUPPORT
        suffix = number_literal_suffix(p, NUM_SUFFIX_ALL);
        #endif
        pylval.nd = new_int(p, tok(p), 2, suffix);
        return tINTEGER;
      }
      if (c == 'd' || c == 'D') {
        /* decimal */
        c = nextc(p);
        if (c >= 0 && ISDIGIT(c)) {
          do {
            if (c == '_') {
              if (nondigit) break;
              nondigit = c;
              continue;
            }
            if (!ISDIGIT(c)) break;
            nondigit = 0;
            tokadd(p, c);
          } while ((c = nextc(p)) >= 0);
        }
        pushback(p, c);
        tokfix(p);
        if (toklen(p) == start) {
          no_digits();
        }
        else if (nondigit) goto trailing_uc;
        #ifdef MRB_SUFFIX_SUPPORT
        suffix = number_literal_suffix(p, NUM_SUFFIX_ALL);
        #endif
        pylval.nd = new_int(p, tok(p), 10, suffix);
        return tINTEGER;
      }
      if (c == '_') {
        /* 0_0 */
        goto octal_number;
      }
      if (c == 'o' || c == 'O') {
        /* prefixed octal */
        c = nextc(p);
        if (c < 0 || c == '_' || !ISDIGIT(c)) {
          no_digits();
        }
      }
      if (c >= '0' && c <= '7') {
        /* octal */
        octal_number:
        do {
          if (c == '_') {
            if (nondigit) break;
            nondigit = c;
            continue;
          }
          if (c < '0' || c > '9') break;
          if (c > '7') goto invalid_octal;
          nondigit = 0;
          tokadd(p, c);
        } while ((c = nextc(p)) >= 0);

        if (toklen(p) > start) {
          pushback(p, c);
          tokfix(p);
          if (nondigit) goto trailing_uc;
          #ifdef MRB_SUFFIX_SUPPORT
          suffix = number_literal_suffix(p, NUM_SUFFIX_ALL);
          #endif
          pylval.nd = new_int(p, tok(p), 8, suffix);
          return tINTEGER;
        }
        if (nondigit) {
          pushback(p, c);
          goto trailing_uc;
        }
      }
      if (c > '7' && c <= '9') {
        invalid_octal:
        yyerror(p, "Invalid octal digit");
      }
      else if (c == '.' || c == 'e' || c == 'E') {
        tokadd(p, '0');
      }
      else {
        pushback(p, c);
        #ifdef MRB_SUFFIX_SUPPORT
        suffix = number_literal_suffix(p, NUM_SUFFIX_ALL);
        #endif
        pylval.nd = new_int(p, "0", 10, suffix);
        return tINTEGER;
      }
    }

    for (;;) {
      switch (c) {
      case '0': case '1': case '2': case '3': case '4':
      case '5': case '6': case '7': case '8': case '9':
        nondigit = 0;
        tokadd(p, c);
        break;

      case '.':
        if (nondigit) goto trailing_uc;
        if (seen_point || seen_e) {
          goto decode_num;
        }
        else {
          int c0 = nextc(p);
          if (c0 < 0 || !ISDIGIT(c0)) {
            pushback(p, c0);
            goto decode_num;
          }
          c = c0;
        }
        tokadd(p, '.');
        tokadd(p, c);
        is_float++;
        seen_point++;
        nondigit = 0;
        break;

      case 'e':
      case 'E':
        if (nondigit) {
          pushback(p, c);
          c = nondigit;
          goto decode_num;
        }
        if (seen_e) {
          goto decode_num;
        }
        tokadd(p, c);
        seen_e++;
        is_float++;
        nondigit = c;
        c = nextc(p);
        if (c != '-' && c != '+') continue;
        tokadd(p, c);
        nondigit = c;
        break;

      case '_':       /* '_' in number just ignored */
        if (nondigit) goto decode_num;
        nondigit = c;
        break;

      default:
        goto decode_num;
      }
      c = nextc(p);
    }

    decode_num:
    pushback(p, c);
    if (nondigit) {
      trailing_uc:
      yyerror_c(p, "trailing non digit in number: ", (char)nondigit);
    }
    tokfix(p);
    if (is_float) {
#ifdef MRB_WITHOUT_FLOAT
      yywarning_s(p, "floating point numbers are not supported", tok(p));
      pylval.nd = new_int(p, "0", 10, 0);
      return tINTEGER;
#else
      double d;
      char *endp;

      errno = 0;
      d = mrb_float_read(tok(p), &endp);
      if (d == 0 && endp == tok(p)) {
        yywarning_s(p, "corrupted float value", tok(p));
      }
      else if (errno == ERANGE) {
        yywarning_s(p, "float out of range", tok(p));
        errno = 0;
      }
      #ifdef MRB_SUFFIX_SUPPORT
      suffix = number_literal_suffix(p, NUM_SUFFIX_ALL);
      #endif
      pylval.nd = new_float(p, tok(p), suffix);
      return tFLOAT;
#endif
    }
    #ifdef MRB_SUFFIX_SUPPORT
    suffix = number_literal_suffix(p, NUM_SUFFIX_ALL);
    #endif
    pylval.nd = new_int(p, tok(p), 10, suffix);
    return tINTEGER;
  }

  case ')':
  case ']':
    p->paren_nest--;
    /* fall through */
  case '}':
    COND_LEXPOP();
    CMDARG_LEXPOP();
    if (c == ')')
      p->lstate = EXPR_ENDFN;
    else
      p->lstate = EXPR_END;
    return c;

  case ':':
    c = nextc(p);
    if (c == ':') {
      if (IS_BEG() || p->lstate == EXPR_CLASS || IS_SPCARG(-1)) {
        p->lstate = EXPR_BEG;
        return tCOLON3;
      }
      p->lstate = EXPR_DOT;
      return tCOLON2;
    }
    if (!space_seen && IS_END()) {
      pushback(p, c);
      p->lstate = EXPR_BEG;
      return tLABEL_TAG;
    }
    if (!ISSPACE(c) || IS_BEG()) {
      pushback(p, c);
      p->lstate = EXPR_FNAME;
      return tSYMBEG;
    }
    pushback(p, c);
    p->lstate = EXPR_BEG;
    return ':';

  case '/':
    if (IS_BEG()) {
      p->lex_strterm = new_strterm(p, str_regexp, '/', 0);
      return tREGEXP_BEG;
    }
    if ((c = nextc(p)) == '=') {
      pylval.id = intern_c('/');
      p->lstate = EXPR_BEG;
      return tOP_ASGN;
    }
    pushback(p, c);
    if (IS_SPCARG(c)) {
      p->lex_strterm = new_strterm(p, str_regexp, '/', 0);
      return tREGEXP_BEG;
    }
    if (p->lstate == EXPR_FNAME || p->lstate == EXPR_DOT) {
      p->lstate = EXPR_ARG;
    }
    else {
      p->lstate = EXPR_BEG;
    }
    return '/';

  case '^':
    if ((c = nextc(p)) == '=') {
      pylval.id = intern_c('^');
      p->lstate = EXPR_BEG;
      return tOP_ASGN;
    }
    if (p->lstate == EXPR_FNAME || p->lstate == EXPR_DOT) {
      p->lstate = EXPR_ARG;
    }
    else {
      p->lstate = EXPR_BEG;
    }
    pushback(p, c);
    return '^';

  case ';':
    p->lstate = EXPR_BEG;
    return ';';

  case ',':
    p->lstate = EXPR_BEG;
    return ',';

  case '~':
    if (p->lstate == EXPR_FNAME || p->lstate == EXPR_DOT) {
      if ((c = nextc(p)) != '@') {
        pushback(p, c);
      }
      p->lstate = EXPR_ARG;
    }
    else {
      p->lstate = EXPR_BEG;
    }
    return '~';

  case '(':
    if (IS_BEG()) {
      c = tLPAREN;
    }
    else if (IS_SPCARG(-1)) {
      c = tLPAREN_ARG;
    }
    else if (p->lstate == EXPR_END && space_seen) {
      c = tLPAREN_ARG;
    }
    p->paren_nest++;
    COND_PUSH(0);
    CMDARG_PUSH(0);
    p->lstate = EXPR_BEG;
    return c;

  case '[':
    p->paren_nest++;
    if (p->lstate == EXPR_FNAME || p->lstate == EXPR_DOT) {
      p->lstate = EXPR_ARG;
      if ((c = nextc(p)) == ']') {
        if ((c = nextc(p)) == '=') {
          return tASET;
        }
        pushback(p, c);
        return tAREF;
      }
      pushback(p, c);
      return '[';
    }
    else if (IS_BEG()) {
      c = tLBRACK;
    }
    else if (IS_ARG() && space_seen) {
      c = tLBRACK;
    }
    p->lstate = EXPR_BEG;
    COND_PUSH(0);
    CMDARG_PUSH(0);
    return c;

  case '{':
    if (p->lpar_beg && p->lpar_beg == p->paren_nest) {
      p->lstate = EXPR_BEG;
      p->lpar_beg = 0;
      p->paren_nest--;
      COND_PUSH(0);
      CMDARG_PUSH(0);
      return tLAMBEG;
    }
    if (IS_ARG() || p->lstate == EXPR_END || p->lstate == EXPR_ENDFN)
      c = '{';          /* block (primary) */
    else if (p->lstate == EXPR_ENDARG)
      c = tLBRACE_ARG;  /* block (expr) */
    else
      c = tLBRACE;      /* hash */
    COND_PUSH(0);
    CMDARG_PUSH(0);
    p->lstate = EXPR_BEG;
    return c;

  case '\\':
    c = nextc(p);
    if (c == '\n') {
      p->lineno++;
      p->column = 0;
      space_seen = 1;
      goto retry; /* skip \\n */
    }
    pushback(p, c);
    return '\\';

  case '%':
    if (IS_BEG()) {
      int term;
      int paren;

      c = nextc(p);
      quotation:
      if (c < 0 || !ISALNUM(c)) {
        term = c;
        c = 'Q';
      }
      else {
        term = nextc(p);
        if (ISALNUM(term)) {
          yyerror(p, "unknown type of %string");
          return 0;
        }
      }
      if (c < 0 || term < 0) {
        yyerror(p, "unterminated quoted string meets end of file");
        return 0;
      }
      paren = term;
      if (term == '(') term = ')';
      else if (term == '[') term = ']';
      else if (term == '{') term = '}';
      else if (term == '<') term = '>';
      else paren = 0;

      switch (c) {
      case 'Q':
        p->lex_strterm = new_strterm(p, str_dquote, term, paren);
        return tSTRING_BEG;

      case 'q':
        p->lex_strterm = new_strterm(p, str_squote, term, paren);
        return parse_string(p);

      case 'W':
        p->lex_strterm = new_strterm(p, str_dword, term, paren);
        return tWORDS_BEG;

      case 'w':
        p->lex_strterm = new_strterm(p, str_sword, term, paren);
        return tWORDS_BEG;

      case 'x':
        p->lex_strterm = new_strterm(p, str_xquote, term, paren);
        return tXSTRING_BEG;

      case 'r':
        p->lex_strterm = new_strterm(p, str_regexp, term, paren);
        return tREGEXP_BEG;

      case 's':
        p->lex_strterm = new_strterm(p, str_ssym, term, paren);
        return tSYMBEG;

      case 'I':
        p->lex_strterm = new_strterm(p, str_dsymbols, term, paren);
        return tSYMBOLS_BEG;

      case 'i':
        p->lex_strterm = new_strterm(p, str_ssymbols, term, paren);
        return tSYMBOLS_BEG;

      default:
        yyerror(p, "unknown type of %string");
        return 0;
      }
    }
    if ((c = nextc(p)) == '=') {
      pylval.id = intern_c('%');
      p->lstate = EXPR_BEG;
      return tOP_ASGN;
    }
    if (IS_SPCARG(c)) {
      goto quotation;
    }
    if (p->lstate == EXPR_FNAME || p->lstate == EXPR_DOT) {
      p->lstate = EXPR_ARG;
    }
    else {
      p->lstate = EXPR_BEG;
    }
    pushback(p, c);
    return '%';

  case '$':
    p->lstate = EXPR_END;
    token_column = newtok(p);
    c = nextc(p);
    if (c < 0) {
      yyerror(p, "incomplete global variable syntax");
      return 0;
    }
    switch (c) {
    case '_':     /* $_: last read line string */
      c = nextc(p);
      if (c >= 0 && identchar(c)) { /* if there is more after _ it is a variable */
        tokadd(p, '$');
        tokadd(p, c);
        break;
      }
      pushback(p, c);
      c = '_';
      /* fall through */
    case '~':     /* $~: match-data */
    case '*':     /* $*: argv */
    case '$':     /* $$: pid */
    case '?':     /* $?: last status */
    case '!':     /* $!: error string */
    case '@':     /* $@: error position */
    case '/':     /* $/: input record separator */
    case '\\':    /* $\: output record separator */
    case ';':     /* $;: field separator */
    case ',':     /* $,: output field separator */
    case '.':     /* $.: last read line number */
    case '=':     /* $=: ignorecase */
    case ':':     /* $:: load path */
    case '<':     /* $<: reading filename */
    case '>':     /* $>: default output handle */
    case '\"':    /* $": already loaded files */
      tokadd(p, '$');
      tokadd(p, c);
      tokfix(p);
      pylval.id = intern_cstr(tok(p));
      return tGVAR;

    case '-':
      tokadd(p, '$');
      tokadd(p, c);
      c = nextc(p);
      pushback(p, c);
      gvar:
      tokfix(p);
      pylval.id = intern_cstr(tok(p));
      return tGVAR;

    case '&':     /* $&: last match */
    case '`':     /* $`: string before last match */
    case '\'':    /* $': string after last match */
    case '+':     /* $+: string matches last pattern */
      if (last_state == EXPR_FNAME) {
        tokadd(p, '$');
        tokadd(p, c);
        goto gvar;
      }
      pylval.nd = new_back_ref(p, c);
      return tBACK_REF;

    case '1': case '2': case '3':
    case '4': case '5': case '6':
    case '7': case '8': case '9':
      do {
        tokadd(p, c);
        c = nextc(p);
      } while (c >= 0 && ISDIGIT(c));
      pushback(p, c);
      if (last_state == EXPR_FNAME) goto gvar;
      tokfix(p);
      {
        unsigned long n = strtoul(tok(p), NULL, 10);
        if (n > INT_MAX) {
          yyerror(p, "capture group index must be <= " MRB_STRINGIZE(INT_MAX));
          return 0;
        }
        pylval.nd = new_nth_ref(p, (int)n);
      }
      return tNTH_REF;

    default:
      if (!identchar(c)) {
        pushback(p,  c);
        return '$';
      }
      /* fall through */
    case '0':
      tokadd(p, '$');
    }
    break;

    case '@':
      c = nextc(p);
      token_column = newtok(p);
      tokadd(p, '@');
      if (c == '@') {
        tokadd(p, '@');
        c = nextc(p);
      }
      if (c < 0) {
        if (p->tidx == 1) {
          yyerror(p, "incomplete instance variable syntax");
        }
        else {
          yyerror(p, "incomplete class variable syntax");
        }
        return 0;
      }
      else if (ISDIGIT(c)) {
        if (p->tidx == 1) {
          yyerror_c(p, "wrong instance variable name: @", c);
        }
        else {
          yyerror_c(p, "wrong class variable name: @@", c);
        }
        return 0;
      }
      if (!identchar(c)) {
        pushback(p, c);
        return '@';
      }
      break;

    case '_':
      token_column = newtok(p);
      break;

    default:
      if (!identchar(c)) {
        char buf[36];
        const char s[] = "Invalid char in expression: 0x";
        const char hexdigits[] = "0123456789ABCDEF";

        strcpy(buf, s);
        buf[sizeof(s)-1] = hexdigits[(c & 0xf0) >> 4];
        buf[sizeof(s)]   = hexdigits[(c & 0x0f)];
        buf[sizeof(s)+1] = 0;
        yyerror(p, buf);
        goto retry;
      }

      token_column = newtok(p);
      break;
  }

  do {
    tokadd(p, c);
    c = nextc(p);
    if (c < 0) break;
  } while (identchar(c));
  if (token_column == 0 && toklen(p) == 7 && (c < 0 || c == '\n') &&
      strncmp(tok(p), "__END__", toklen(p)) == 0)
    return -1;

  switch (tok(p)[0]) {
  case '@': case '$':
    pushback(p, c);
    break;
  default:
    if ((c == '!' || c == '?') && !peek(p, '=')) {
      tokadd(p, c);
    }
    else {
      pushback(p, c);
    }
  }
  tokfix(p);
  {
    int result = 0;

    switch (tok(p)[0]) {
    case '$':
      p->lstate = EXPR_END;
      result = tGVAR;
      break;
    case '@':
      p->lstate = EXPR_END;
      if (tok(p)[1] == '@')
        result = tCVAR;
      else
        result = tIVAR;
      break;

    default:
      if (toklast(p) == '!' || toklast(p) == '?') {
        result = tFID;
      }
      else {
        if (p->lstate == EXPR_FNAME) {
          if ((c = nextc(p)) == '=' && !peek(p, '~') && !peek(p, '>') &&
              (!peek(p, '=') || (peek_n(p, '>', 1)))) {
            result = tIDENTIFIER;
            tokadd(p, c);
            tokfix(p);
          }
          else {
            pushback(p, c);
          }
        }
        if (result == 0 && ISUPPER(tok(p)[0])) {
          result = tCONSTANT;
        }
        else {
          result = tIDENTIFIER;
        }
      }

      if (IS_LABEL_POSSIBLE()) {
        if (IS_LABEL_SUFFIX(0)) {
          p->lstate = EXPR_END;
          tokfix(p);
          pylval.id = intern_cstr(tok(p));
          return tIDENTIFIER;
        }
      }
      if (p->lstate != EXPR_DOT) {
        const struct kwtable *kw;

        /* See if it is a reserved word.  */
        kw = mrb_reserved_word(tok(p), toklen(p));
        if (kw) {
          enum mrb_lex_state_enum state = p->lstate;
          pylval.num = p->lineno;
          p->lstate = kw->state;
          if (state == EXPR_FNAME) {
            pylval.id = intern_cstr(kw->name);
            return kw->id[0];
          }
          if (p->lstate == EXPR_BEG) {
            p->cmd_start = TRUE;
          }
          if (kw->id[0] == keyword_do) {
            if (p->lpar_beg && p->lpar_beg == p->paren_nest) {
              p->lpar_beg = 0;
              p->paren_nest--;
              return keyword_do_LAMBDA;
            }
            if (COND_P()) return keyword_do_cond;
            if (CMDARG_P() && state != EXPR_CMDARG)
              return keyword_do_block;
            if (state == EXPR_ENDARG || state == EXPR_BEG)
              return keyword_do_block;
            return keyword_do;
          }
          if (state == EXPR_BEG || state == EXPR_VALUE)
            return kw->id[0];
          else {
            if (kw->id[0] != kw->id[1])
              p->lstate = EXPR_BEG;
            return kw->id[1];
          }
        }
      }

      if (IS_BEG() || p->lstate == EXPR_DOT || IS_ARG()) {
        if (cmd_state) {
          p->lstate = EXPR_CMDARG;
        }
        else {
          p->lstate = EXPR_ARG;
        }
      }
      else if (p->lstate == EXPR_FNAME) {
        p->lstate = EXPR_ENDFN;
      }
      else {
        p->lstate = EXPR_END;
      }
    }
    {
      mrb_sym ident = intern_cstr(tok(p));

      pylval.id = ident;
      if (last_state != EXPR_DOT && ISLOWER(tok(p)[0]) && local_var_p(p, ident)) {
        p->lstate = EXPR_END;
      }
    }
    return result;
  }
}

static int
yylex(void *lval, parser_state *p)
{
  p->ylval = lval;
  return parser_yylex(p);
}

static void
parser_init_cxt(parser_state *p, mrbc_context *cxt)
{
  if (!cxt) return;
  if (cxt->filename) mrb_parser_set_filename(p, cxt->filename);
  if (cxt->lineno) p->lineno = cxt->lineno;
  if (cxt->syms) {
    int i;

    p->locals = cons(0,0);
    for (i=0; i<cxt->slen; i++) {
      local_add_f(p, cxt->syms[i]);
    }
  }
  p->capture_errors = cxt->capture_errors;
  p->no_optimize = cxt->no_optimize;
  p->on_eval = cxt->on_eval;
  if (cxt->partial_hook) {
    p->cxt = cxt;
  }
}

static void
parser_update_cxt(parser_state *p, mrbc_context *cxt)
{
  node *n, *n0;
  int i = 0;

  if (!cxt) return;
  if (intn(p->tree->car) != NODE_SCOPE) return;
  n0 = n = p->tree->cdr->car;
  while (n) {
    i++;
    n = n->cdr;
  }
  cxt->syms = (mrb_sym *)mrb_realloc(p->mrb, cxt->syms, i*sizeof(mrb_sym));
  cxt->slen = i;
  for (i=0, n=n0; n; i++,n=n->cdr) {
    cxt->syms[i] = sym(n->car);
  }
}

void mrb_codedump_all(mrb_state*, struct RProc*);
void mrb_parser_dump(mrb_state *mrb, node *tree, int offset);

MRB_API void
mrb_parser_parse(parser_state *p, mrbc_context *c)
{
  struct mrb_jmpbuf buf1;
  p->jmp = &buf1;

  MRB_TRY(p->jmp) {
    int n = 1;

    p->cmd_start = TRUE;
    p->in_def = p->in_single = 0;
    p->nerr = p->nwarn = 0;
    p->lex_strterm = NULL;

    parser_init_cxt(p, c);

    if (p->mrb->jmp) {
      n = yyparse(p);
    }
    else {
      struct mrb_jmpbuf buf2;

      p->mrb->jmp = &buf2;
      MRB_TRY(p->mrb->jmp) {
        n = yyparse(p);
      }
      MRB_CATCH(p->mrb->jmp) {
        p->nerr++;
      }
      MRB_END_EXC(p->mrb->jmp);
      p->mrb->jmp = 0;
    }
    if (n != 0 || p->nerr > 0) {
      p->tree = 0;
      return;
    }
    if (!p->tree) {
      p->tree = new_nil(p);
    }
    parser_update_cxt(p, c);
    if (c && c->dump_result) {
      mrb_parser_dump(p->mrb, p->tree, 0);
    }
  }
  MRB_CATCH(p->jmp) {
    yyerror(p, "memory allocation error");
    p->nerr++;
    p->tree = 0;
    return;
  }
  MRB_END_EXC(p->jmp);
}

MRB_API parser_state*
mrb_parser_new(mrb_state *mrb)
{
  mrb_pool *pool;
  parser_state *p;
  static const parser_state parser_state_zero = { 0 };

  pool = mrb_pool_open(mrb);
  if (!pool) return NULL;
  p = (parser_state *)mrb_pool_alloc(pool, sizeof(parser_state));
  if (!p) return NULL;

  *p = parser_state_zero;
  p->mrb = mrb;
  p->pool = pool;

  p->s = p->send = NULL;
#ifndef MRB_DISABLE_STDIO
  p->f = NULL;
#endif

  p->cmd_start = TRUE;
  p->in_def = p->in_single = 0;

  p->capture_errors = FALSE;
  p->lineno = 1;
  p->column = 0;
#if defined(PARSER_TEST) || defined(PARSER_DEBUG)
  yydebug = 1;
#endif
  p->tsiz = MRB_PARSER_TOKBUF_SIZE;
  p->tokbuf = p->buf;

  p->lex_strterm = NULL;
  p->all_heredocs = p->parsing_heredoc = NULL;
  p->lex_strterm_before_heredoc = NULL;

  p->current_filename_index = -1;
  p->filename_table = NULL;
  p->filename_table_length = 0;

  return p;
}

MRB_API void
mrb_parser_free(parser_state *p) {
  if (p->tokbuf != p->buf) {
    mrb_free(p->mrb, p->tokbuf);
  }
  mrb_pool_close(p->pool);
}

MRB_API mrbc_context*
mrbc_context_new(mrb_state *mrb)
{
  return (mrbc_context *)mrb_calloc(mrb, 1, sizeof(mrbc_context));
}

MRB_API void
mrbc_context_free(mrb_state *mrb, mrbc_context *cxt)
{
  mrb_free(mrb, cxt->filename);
  mrb_free(mrb, cxt->syms);
  mrb_free(mrb, cxt);
}

MRB_API const char*
mrbc_filename(mrb_state *mrb, mrbc_context *c, const char *s)
{
  if (s) {
    size_t len = strlen(s);
    char *p = (char *)mrb_malloc(mrb, len + 1);

    memcpy(p, s, len + 1);
    if (c->filename) {
      mrb_free(mrb, c->filename);
    }
    c->filename = p;
  }
  return c->filename;
}

MRB_API void
mrbc_partial_hook(mrb_state *mrb, mrbc_context *c, int (*func)(struct mrb_parser_state*), void *data)
{
  c->partial_hook = func;
  c->partial_data = data;
}

MRB_API void
mrb_parser_set_filename(struct mrb_parser_state *p, const char *f)
{
  mrb_sym sym;
  size_t i;
  mrb_sym* new_table;

  sym = mrb_intern_cstr(p->mrb, f);
  p->filename_sym = sym;
  p->lineno = (p->filename_table_length > 0)? 0 : 1;

  for (i = 0; i < p->filename_table_length; ++i) {
    if (p->filename_table[i] == sym) {
      p->current_filename_index = (int)i;
      return;
    }
  }

  if (p->filename_table_length == UINT16_MAX) {
    yyerror(p, "too many files to compile");
    return;
  }
  p->current_filename_index = p->filename_table_length++;

  new_table = (mrb_sym*)parser_palloc(p, sizeof(mrb_sym) * p->filename_table_length);
  if (p->filename_table) {
    memmove(new_table, p->filename_table, sizeof(mrb_sym) * p->current_filename_index);
  }
  p->filename_table = new_table;
  p->filename_table[p->filename_table_length - 1] = sym;
}

MRB_API mrb_sym
mrb_parser_get_filename(struct mrb_parser_state* p, uint16_t idx) {
  if (idx >= p->filename_table_length) return 0;
  else {
    return p->filename_table[idx];
  }
}

#ifndef MRB_DISABLE_STDIO
MRB_API parser_state*
mrb_parse_file(mrb_state *mrb, FILE *f, mrbc_context *c)
{
  parser_state *p;

  p = mrb_parser_new(mrb);
  if (!p) return NULL;
  p->s = p->send = NULL;
  p->f = f;

  mrb_parser_parse(p, c);
  return p;
}
#endif

MRB_API parser_state*
mrb_parse_nstring(mrb_state *mrb, const char *s, size_t len, mrbc_context *c)
{
  parser_state *p;

  p = mrb_parser_new(mrb);
  if (!p) return NULL;
  p->s = s;
  p->send = s + len;

  mrb_parser_parse(p, c);
  return p;
}

MRB_API parser_state*
mrb_parse_string(mrb_state *mrb, const char *s, mrbc_context *c)
{
  return mrb_parse_nstring(mrb, s, strlen(s), c);
}

MRB_API mrb_value
mrb_load_exec(mrb_state *mrb, struct mrb_parser_state *p, mrbc_context *c)
{
  struct RClass *target = mrb->object_class;
  struct RProc *proc;
  mrb_value v;
  unsigned int keep = 0;

  if (!p) {
    return mrb_undef_value();
  }
  if (!p->tree || p->nerr) {
    if (c) c->parser_nerr = p->nerr;
    if (p->capture_errors) {
      char buf[256];

      strcpy(buf, "line ");
      dump_int(p->error_buffer[0].lineno, buf+5);
      strcat(buf, ": ");
      strncat(buf, p->error_buffer[0].message, sizeof(buf) - strlen(buf) - 1);
      mrb->exc = mrb_obj_ptr(mrb_exc_new(mrb, E_SYNTAX_ERROR, buf, strlen(buf)));
      mrb_parser_free(p);
      return mrb_undef_value();
    }
    else {
      if (mrb->exc == NULL) {
        mrb->exc = mrb_obj_ptr(mrb_exc_new_str_lit(mrb, E_SYNTAX_ERROR, "syntax error"));
      }
      mrb_parser_free(p);
      return mrb_undef_value();
    }
  }
  proc = mrb_generate_code(mrb, p);
  mrb_parser_free(p);
  if (proc == NULL) {
    if (mrb->exc == NULL) {
      mrb->exc = mrb_obj_ptr(mrb_exc_new_str_lit(mrb, E_SCRIPT_ERROR, "codegen error"));
    }
    return mrb_undef_value();
  }
  if (c) {
    if (c->dump_result) mrb_codedump_all(mrb, proc);
    if (c->no_exec) return mrb_obj_value(proc);
    if (c->target_class) {
      target = c->target_class;
    }
    if (c->keep_lv) {
      keep = c->slen + 1;
    }
    else {
      c->keep_lv = TRUE;
    }
  }
  MRB_PROC_SET_TARGET_CLASS(proc, target);
  if (mrb->c->ci) {
    mrb->c->ci->target_class = target;
  }
  v = mrb_top_run(mrb, proc, mrb_top_self(mrb), keep);
  if (mrb->exc) return mrb_nil_value();
  return v;
}

#ifndef MRB_DISABLE_STDIO
MRB_API mrb_value
mrb_load_file_cxt(mrb_state *mrb, FILE *f, mrbc_context *c)
{
  return mrb_load_exec(mrb, mrb_parse_file(mrb, f, c), c);
}

MRB_API mrb_value
mrb_load_file(mrb_state *mrb, FILE *f)
{
  return mrb_load_file_cxt(mrb, f, NULL);
}
#endif

MRB_API mrb_value
mrb_load_nstring_cxt(mrb_state *mrb, const char *s, size_t len, mrbc_context *c)
{
  return mrb_load_exec(mrb, mrb_parse_nstring(mrb, s, len, c), c);
}

MRB_API mrb_value
mrb_load_nstring(mrb_state *mrb, const char *s, size_t len)
{
  return mrb_load_nstring_cxt(mrb, s, len, NULL);
}

MRB_API mrb_value
mrb_load_string_cxt(mrb_state *mrb, const char *s, mrbc_context *c)
{
  return mrb_load_nstring_cxt(mrb, s, strlen(s), c);
}

MRB_API mrb_value
mrb_load_string(mrb_state *mrb, const char *s)
{
  return mrb_load_string_cxt(mrb, s, NULL);
}

#ifndef MRB_DISABLE_STDIO

static void
dump_prefix(node *tree, int offset)
{
  printf("%05d ", tree->lineno);
  while (offset--) {
    putc(' ', stdout);
    putc(' ', stdout);
  }
}

static void
dump_recur(mrb_state *mrb, node *tree, int offset)
{
  while (tree) {
    mrb_parser_dump(mrb, tree->car, offset);
    tree = tree->cdr;
  }
}

static void
dump_args(mrb_state *mrb, node *n, int offset)
{
  if (n->car) {
    dump_prefix(n, offset+1);
    printf("mandatory args:\n");
    dump_recur(mrb, n->car, offset+2);
  }
  n = n->cdr;
  if (n->car) {
    dump_prefix(n, offset+1);
    printf("optional args:\n");
    {
      node *n2 = n->car;

      while (n2) {
        dump_prefix(n2, offset+2);
        printf("%s=\n", mrb_sym_name(mrb, sym(n2->car->car)));
        mrb_parser_dump(mrb, n2->car->cdr, offset+3);
        n2 = n2->cdr;
      }
    }
  }
  n = n->cdr;
  if (n->car) {
    dump_prefix(n, offset+1);
    printf("rest=*%s\n", mrb_sym_name(mrb, sym(n->car)));
  }
  n = n->cdr;
  if (n->car) {
    dump_prefix(n, offset+1);
    printf("post mandatory args:\n");
    dump_recur(mrb, n->car, offset+2);
  }

  n = n->cdr;
  if (n) {
    mrb_assert(intn(n->car) == NODE_ARGS_TAIL);
    mrb_parser_dump(mrb, n, offset);
  }
}

/*
 * This function restores the GC arena on return.
 * For this reason, if a process that further generates an object is
 * performed at the caller, the string pointer returned as the return
 * value may become invalid.
 */
static const char*
str_dump(mrb_state *mrb, const char *str, int len)
{
  mrb_int ai = mrb_gc_arena_save(mrb);
  mrb_value s;
# if INT_MAX > MRB_INT_MAX / 4
  /* check maximum length with "\xNN" charactor */
  if (len > MRB_INT_MAX / 4) {
    len = MRB_INT_MAX / 4;
  }
# endif
  s = mrb_str_new(mrb, str, (mrb_int)len);
  s = mrb_str_dump(mrb, s);
  mrb_gc_arena_restore(mrb, ai);
  return RSTRING_PTR(s);
}
#endif

void
mrb_parser_dump(mrb_state *mrb, node *tree, int offset)
{
#ifndef MRB_DISABLE_STDIO
  int nodetype;

  if (!tree) return;
  again:
  dump_prefix(tree, offset);
  nodetype = intn(tree->car);
  tree = tree->cdr;
  switch (nodetype) {
  case NODE_BEGIN:
    printf("NODE_BEGIN:\n");
    dump_recur(mrb, tree, offset+1);
    break;

  case NODE_RESCUE:
    printf("NODE_RESCUE:\n");
    if (tree->car) {
      dump_prefix(tree, offset+1);
      printf("body:\n");
      mrb_parser_dump(mrb, tree->car, offset+2);
    }
    tree = tree->cdr;
    if (tree->car) {
      node *n2 = tree->car;

      dump_prefix(n2, offset+1);
      printf("rescue:\n");
      while (n2) {
        node *n3 = n2->car;
        if (n3->car) {
          dump_prefix(n2, offset+2);
          printf("handle classes:\n");
          dump_recur(mrb, n3->car, offset+3);
        }
        if (n3->cdr->car) {
          dump_prefix(n3, offset+2);
          printf("exc_var:\n");
          mrb_parser_dump(mrb, n3->cdr->car, offset+3);
        }
        if (n3->cdr->cdr->car) {
          dump_prefix(n3, offset+2);
          printf("rescue body:\n");
          mrb_parser_dump(mrb, n3->cdr->cdr->car, offset+3);
        }
        n2 = n2->cdr;
      }
    }
    tree = tree->cdr;
    if (tree->car) {
      dump_prefix(tree, offset+1);
      printf("else:\n");
      mrb_parser_dump(mrb, tree->car, offset+2);
    }
    break;

  case NODE_ENSURE:
    printf("NODE_ENSURE:\n");
    dump_prefix(tree, offset+1);
    printf("body:\n");
    mrb_parser_dump(mrb, tree->car, offset+2);
    dump_prefix(tree, offset+1);
    printf("ensure:\n");
    mrb_parser_dump(mrb, tree->cdr->cdr, offset+2);
    break;

  case NODE_LAMBDA:
    printf("NODE_LAMBDA:\n");
    dump_prefix(tree, offset);
    goto block;

  case NODE_BLOCK:
    block:
    printf("NODE_BLOCK:\n");
    tree = tree->cdr;
    if (tree->car) {
      dump_args(mrb, tree->car, offset+1);
    }
    dump_prefix(tree, offset+1);
    printf("body:\n");
    mrb_parser_dump(mrb, tree->cdr->car, offset+2);
    break;

  case NODE_IF:
    printf("NODE_IF:\n");
    dump_prefix(tree, offset+1);
    printf("cond:\n");
    mrb_parser_dump(mrb, tree->car, offset+2);
    dump_prefix(tree, offset+1);
    printf("then:\n");
    mrb_parser_dump(mrb, tree->cdr->car, offset+2);
    if (tree->cdr->cdr->car) {
      dump_prefix(tree, offset+1);
      printf("else:\n");
      mrb_parser_dump(mrb, tree->cdr->cdr->car, offset+2);
    }
    break;

  case NODE_AND:
    printf("NODE_AND:\n");
    mrb_parser_dump(mrb, tree->car, offset+1);
    mrb_parser_dump(mrb, tree->cdr, offset+1);
    break;

  case NODE_OR:
    printf("NODE_OR:\n");
    mrb_parser_dump(mrb, tree->car, offset+1);
    mrb_parser_dump(mrb, tree->cdr, offset+1);
    break;

  case NODE_CASE:
    printf("NODE_CASE:\n");
    if (tree->car) {
      mrb_parser_dump(mrb, tree->car, offset+1);
    }
    tree = tree->cdr;
    while (tree) {
      dump_prefix(tree, offset+1);
      printf("case:\n");
      dump_recur(mrb, tree->car->car, offset+2);
      dump_prefix(tree, offset+1);
      printf("body:\n");
      mrb_parser_dump(mrb, tree->car->cdr, offset+2);
      tree = tree->cdr;
    }
    break;

  case NODE_WHILE:
    printf("NODE_WHILE:\n");
    dump_prefix(tree, offset+1);
    printf("cond:\n");
    mrb_parser_dump(mrb, tree->car, offset+2);
    dump_prefix(tree, offset+1);
    printf("body:\n");
    mrb_parser_dump(mrb, tree->cdr, offset+2);
    break;

  case NODE_UNTIL:
    printf("NODE_UNTIL:\n");
    dump_prefix(tree, offset+1);
    printf("cond:\n");
    mrb_parser_dump(mrb, tree->car, offset+2);
    dump_prefix(tree, offset+1);
    printf("body:\n");
    mrb_parser_dump(mrb, tree->cdr, offset+2);
    break;

  case NODE_FOR:
    printf("NODE_FOR:\n");
    dump_prefix(tree, offset+1);
    printf("var:\n");
    {
      node *n2 = tree->car;

      if (n2->car) {
        dump_prefix(n2, offset+2);
        printf("pre:\n");
        dump_recur(mrb, n2->car, offset+3);
      }
      n2 = n2->cdr;
      if (n2) {
        if (n2->car) {
          dump_prefix(n2, offset+2);
          printf("rest:\n");
          mrb_parser_dump(mrb, n2->car, offset+3);
        }
        n2 = n2->cdr;
        if (n2) {
          if (n2->car) {
            dump_prefix(n2, offset+2);
            printf("post:\n");
            dump_recur(mrb, n2->car, offset+3);
          }
        }
      }
    }
    tree = tree->cdr;
    dump_prefix(tree, offset+1);
    printf("in:\n");
    mrb_parser_dump(mrb, tree->car, offset+2);
    tree = tree->cdr;
    dump_prefix(tree, offset+1);
    printf("do:\n");
    mrb_parser_dump(mrb, tree->car, offset+2);
    break;

  case NODE_SCOPE:
    printf("NODE_SCOPE:\n");
    {
      node *n2 = tree->car;
      mrb_bool first_lval = TRUE;

      if (n2 && (n2->car || n2->cdr)) {
        dump_prefix(n2, offset+1);
        printf("local variables:\n");
        dump_prefix(n2, offset+2);
        while (n2) {
          if (n2->car) {
            if (!first_lval) printf(", ");
            printf("%s", mrb_sym_name(mrb, sym(n2->car)));
            first_lval = FALSE;
          }
          n2 = n2->cdr;
        }
        printf("\n");
      }
    }
    tree = tree->cdr;
    offset++;
    goto again;

  case NODE_FCALL:
  case NODE_CALL:
  case NODE_SCALL:
    switch (nodetype) {
    case NODE_FCALL:
      printf("NODE_FCALL:\n"); break;
    case NODE_CALL:
      printf("NODE_CALL(.):\n"); break;
    case NODE_SCALL:
      printf("NODE_SCALL(&.):\n"); break;
    default:
      break;
    }
    mrb_parser_dump(mrb, tree->car, offset+1);
    dump_prefix(tree, offset+1);
    printf("method='%s' (%d)\n",
        mrb_sym_dump(mrb, sym(tree->cdr->car)),
        intn(tree->cdr->car));
    tree = tree->cdr->cdr->car;
    if (tree) {
      dump_prefix(tree, offset+1);
      printf("args:\n");
      dump_recur(mrb, tree->car, offset+2);
      if (tree->cdr) {
        dump_prefix(tree, offset+1);
        printf("block:\n");
        mrb_parser_dump(mrb, tree->cdr, offset+2);
      }
    }
    break;

  case NODE_DOT2:
    printf("NODE_DOT2:\n");
    mrb_parser_dump(mrb, tree->car, offset+1);
    mrb_parser_dump(mrb, tree->cdr, offset+1);
    break;

  case NODE_DOT3:
    printf("NODE_DOT3:\n");
    mrb_parser_dump(mrb, tree->car, offset+1);
    mrb_parser_dump(mrb, tree->cdr, offset+1);
    break;

  case NODE_COLON2:
    printf("NODE_COLON2:\n");
    mrb_parser_dump(mrb, tree->car, offset+1);
    dump_prefix(tree, offset+1);
    printf("::%s\n", mrb_sym_name(mrb, sym(tree->cdr)));
    break;

  case NODE_COLON3:
    printf("NODE_COLON3: ::%s\n", mrb_sym_name(mrb, sym(tree)));
    break;

  case NODE_ARRAY:
    printf("NODE_ARRAY:\n");
    dump_recur(mrb, tree, offset+1);
    break;

  case NODE_HASH:
    printf("NODE_HASH:\n");
    while (tree) {
      dump_prefix(tree, offset+1);
      printf("key:\n");
      mrb_parser_dump(mrb, tree->car->car, offset+2);
      dump_prefix(tree, offset+1);
      printf("value:\n");
      mrb_parser_dump(mrb, tree->car->cdr, offset+2);
      tree = tree->cdr;
    }
    break;

  case NODE_KW_HASH:
    printf("NODE_KW_HASH:\n");
    while (tree) {
      dump_prefix(tree, offset+1);
      printf("key:\n");
      mrb_parser_dump(mrb, tree->car->car, offset+2);
      dump_prefix(tree, offset+1);
      printf("value:\n");
      mrb_parser_dump(mrb, tree->car->cdr, offset+2);
      tree = tree->cdr;
    }
    break;

  case NODE_SPLAT:
    printf("NODE_SPLAT:\n");
    mrb_parser_dump(mrb, tree, offset+1);
    break;

  case NODE_ASGN:
    printf("NODE_ASGN:\n");
    dump_prefix(tree, offset+1);
    printf("lhs:\n");
    mrb_parser_dump(mrb, tree->car, offset+2);
    dump_prefix(tree, offset+1);
    printf("rhs:\n");
    mrb_parser_dump(mrb, tree->cdr, offset+2);
    break;

  case NODE_MASGN:
    printf("NODE_MASGN:\n");
    dump_prefix(tree, offset+1);
    printf("mlhs:\n");
    {
      node *n2 = tree->car;

      if (n2->car) {
        dump_prefix(tree, offset+2);
        printf("pre:\n");
        dump_recur(mrb, n2->car, offset+3);
      }
      n2 = n2->cdr;
      if (n2) {
        if (n2->car) {
          dump_prefix(n2, offset+2);
          printf("rest:\n");
          if (n2->car == (node*)-1) {
            dump_prefix(n2, offset+2);
            printf("(empty)\n");
          }
          else {
            mrb_parser_dump(mrb, n2->car, offset+3);
          }
        }
        n2 = n2->cdr;
        if (n2) {
          if (n2->car) {
            dump_prefix(n2, offset+2);
            printf("post:\n");
            dump_recur(mrb, n2->car, offset+3);
          }
        }
      }
    }
    dump_prefix(tree, offset+1);
    printf("rhs:\n");
    mrb_parser_dump(mrb, tree->cdr, offset+2);
    break;

  case NODE_OP_ASGN:
    printf("NODE_OP_ASGN:\n");
    dump_prefix(tree, offset+1);
    printf("lhs:\n");
    mrb_parser_dump(mrb, tree->car, offset+2);
    tree = tree->cdr;
    dump_prefix(tree, offset+1);
    printf("op='%s' (%d)\n", mrb_sym_name(mrb, sym(tree->car)), intn(tree->car));
    tree = tree->cdr;
    mrb_parser_dump(mrb, tree->car, offset+1);
    break;

  case NODE_SUPER:
    printf("NODE_SUPER:\n");
    if (tree) {
      dump_prefix(tree, offset+1);
      printf("args:\n");
      dump_recur(mrb, tree->car, offset+2);
      if (tree->cdr) {
        dump_prefix(tree, offset+1);
        printf("block:\n");
        mrb_parser_dump(mrb, tree->cdr, offset+2);
      }
    }
    break;

  case NODE_ZSUPER:
    printf("NODE_ZSUPER\n");
    break;

  case NODE_RETURN:
    printf("NODE_RETURN:\n");
    mrb_parser_dump(mrb, tree, offset+1);
    break;

  case NODE_YIELD:
    printf("NODE_YIELD:\n");
    dump_recur(mrb, tree, offset+1);
    break;

  case NODE_BREAK:
    printf("NODE_BREAK:\n");
    mrb_parser_dump(mrb, tree, offset+1);
    break;

  case NODE_NEXT:
    printf("NODE_NEXT:\n");
    mrb_parser_dump(mrb, tree, offset+1);
    break;

  case NODE_REDO:
    printf("NODE_REDO\n");
    break;

  case NODE_RETRY:
    printf("NODE_RETRY\n");
    break;

  case NODE_LVAR:
    printf("NODE_LVAR %s\n", mrb_sym_name(mrb, sym(tree)));
    break;

  case NODE_GVAR:
    printf("NODE_GVAR %s\n", mrb_sym_name(mrb, sym(tree)));
    break;

  case NODE_IVAR:
    printf("NODE_IVAR %s\n", mrb_sym_name(mrb, sym(tree)));
    break;

  case NODE_CVAR:
    printf("NODE_CVAR %s\n", mrb_sym_name(mrb, sym(tree)));
    break;

  case NODE_CONST:
    printf("NODE_CONST %s\n", mrb_sym_name(mrb, sym(tree)));
    break;

  case NODE_MATCH:
    printf("NODE_MATCH:\n");
    dump_prefix(tree, offset + 1);
    printf("lhs:\n");
    mrb_parser_dump(mrb, tree->car, offset + 2);
    dump_prefix(tree, offset + 1);
    printf("rhs:\n");
    mrb_parser_dump(mrb, tree->cdr, offset + 2);
    break;

  case NODE_BACK_REF:
    printf("NODE_BACK_REF: $%c\n", intn(tree));
    break;

  case NODE_NTH_REF:
    printf("NODE_NTH_REF: $%d\n", intn(tree));
    break;

  case NODE_ARG:
    printf("NODE_ARG %s\n", mrb_sym_name(mrb, sym(tree)));
    break;

  case NODE_BLOCK_ARG:
    printf("NODE_BLOCK_ARG:\n");
    mrb_parser_dump(mrb, tree, offset+1);
    break;

  case NODE_INT:
    printf("NODE_INT %s base %d\n", (char*)tree->car, intn(tree->cdr->car));
    break;

  case NODE_FLOAT:
    printf("NODE_FLOAT %s\n", (char*)tree);
    break;

  case NODE_NEGATE:
    printf("NODE_NEGATE:\n");
    mrb_parser_dump(mrb, tree, offset+1);
    break;

  case NODE_STR:
    printf("NODE_STR %s len %d\n", str_dump(mrb, (char*)tree->car, intn(tree->cdr)), intn(tree->cdr));
    break;

  case NODE_DSTR:
    printf("NODE_DSTR:\n");
    dump_recur(mrb, tree, offset+1);
    break;

  case NODE_XSTR:
    printf("NODE_XSTR %s len %d\n", str_dump(mrb, (char*)tree->car, intn(tree->cdr)), intn(tree->cdr));
    break;

  case NODE_DXSTR:
    printf("NODE_DXSTR:\n");
    dump_recur(mrb, tree, offset+1);
    break;

  case NODE_REGX:
    printf("NODE_REGX /%s/%s\n", (char*)tree->car, (char*)tree->cdr);
    break;

  case NODE_DREGX:
    printf("NODE_DREGX:\n");
    dump_recur(mrb, tree->car, offset+1);
    dump_prefix(tree, offset);
    printf("tail: %s\n", (char*)tree->cdr->cdr->car);
    if (tree->cdr->cdr->cdr->car) {
      dump_prefix(tree, offset);
      printf("opt: %s\n", (char*)tree->cdr->cdr->cdr->car);
    }
    if (tree->cdr->cdr->cdr->cdr) {
      dump_prefix(tree, offset);
      printf("enc: %s\n", (char*)tree->cdr->cdr->cdr->cdr);
    }
    break;

  case NODE_SYM:
    printf("NODE_SYM :%s (%d)\n", mrb_sym_dump(mrb, sym(tree)),
           intn(tree));
    break;

  case NODE_DSYM:
    printf("NODE_DSYM:\n");
    mrb_parser_dump(mrb, tree, offset+1);
    break;

  case NODE_WORDS:
    printf("NODE_WORDS:\n");
    dump_recur(mrb, tree, offset+1);
    break;

  case NODE_SYMBOLS:
    printf("NODE_SYMBOLS:\n");
    dump_recur(mrb, tree, offset+1);
    break;

  case NODE_LITERAL_DELIM:
    printf("NODE_LITERAL_DELIM\n");
    break;

  case NODE_SELF:
    printf("NODE_SELF\n");
    break;

  case NODE_NIL:
    printf("NODE_NIL\n");
    break;

  case NODE_TRUE:
    printf("NODE_TRUE\n");
    break;

  case NODE_FALSE:
    printf("NODE_FALSE\n");
    break;

  case NODE_ALIAS:
    printf("NODE_ALIAS %s %s:\n",
        mrb_sym_dump(mrb, sym(tree->car)),
        mrb_sym_dump(mrb, sym(tree->cdr)));
    break;

  case NODE_UNDEF:
    printf("NODE_UNDEF");
    {
      node *t = tree;
      while (t) {
        printf(" %s", mrb_sym_dump(mrb, sym(t->car)));
        t = t->cdr;
      }
    }
    printf(":\n");
    break;

  case NODE_CLASS:
    printf("NODE_CLASS:\n");
    if (tree->car->car == (node*)0) {
      dump_prefix(tree, offset+1);
      printf(":%s\n", mrb_sym_name(mrb, sym(tree->car->cdr)));
    }
    else if (tree->car->car == (node*)1) {
      dump_prefix(tree, offset+1);
      printf("::%s\n", mrb_sym_name(mrb, sym(tree->car->cdr)));
    }
    else {
      mrb_parser_dump(mrb, tree->car->car, offset+1);
      dump_prefix(tree, offset+1);
      printf("::%s\n", mrb_sym_name(mrb, sym(tree->car->cdr)));
    }
    if (tree->cdr->car) {
      dump_prefix(tree, offset+1);
      printf("super:\n");
      mrb_parser_dump(mrb, tree->cdr->car, offset+2);
    }
    dump_prefix(tree, offset+1);
    printf("body:\n");
    mrb_parser_dump(mrb, tree->cdr->cdr->car->cdr, offset+2);
    break;

  case NODE_MODULE:
    printf("NODE_MODULE:\n");
    if (tree->car->car == (node*)0) {
      dump_prefix(tree, offset+1);
      printf(":%s\n", mrb_sym_name(mrb, sym(tree->car->cdr)));
    }
    else if (tree->car->car == (node*)1) {
      dump_prefix(tree, offset+1);
      printf("::%s\n", mrb_sym_name(mrb, sym(tree->car->cdr)));
    }
    else {
      mrb_parser_dump(mrb, tree->car->car, offset+1);
      dump_prefix(tree, offset+1);
      printf("::%s\n", mrb_sym_name(mrb, sym(tree->car->cdr)));
    }
    dump_prefix(tree, offset+1);
    printf("body:\n");
    mrb_parser_dump(mrb, tree->cdr->car->cdr, offset+2);
    break;

  case NODE_SCLASS:
    printf("NODE_SCLASS:\n");
    mrb_parser_dump(mrb, tree->car, offset+1);
    dump_prefix(tree, offset+1);
    printf("body:\n");
    mrb_parser_dump(mrb, tree->cdr->car->cdr, offset+2);
    break;

  case NODE_DEF:
    printf("NODE_DEF:\n");
    dump_prefix(tree, offset+1);
    printf("%s\n", mrb_sym_dump(mrb, sym(tree->car)));
    tree = tree->cdr;
    {
      node *n2 = tree->car;
      mrb_bool first_lval = TRUE;

      if (n2 && (n2->car || n2->cdr)) {
        dump_prefix(n2, offset+1);
        printf("local variables:\n");
        dump_prefix(n2, offset+2);
        while (n2) {
          if (n2->car) {
            if (!first_lval) printf(", ");
            printf("%s", mrb_sym_name(mrb, sym(n2->car)));
            first_lval = FALSE;
          }
          n2 = n2->cdr;
        }
        printf("\n");
      }
    }
    tree = tree->cdr;
    if (tree->car) {
      dump_args(mrb, tree->car, offset);
    }
    mrb_parser_dump(mrb, tree->cdr->car, offset+1);
    break;

  case NODE_SDEF:
    printf("NODE_SDEF:\n");
    mrb_parser_dump(mrb, tree->car, offset+1);
    tree = tree->cdr;
    dump_prefix(tree, offset+1);
    printf(":%s\n", mrb_sym_dump(mrb, sym(tree->car)));
    tree = tree->cdr->cdr;
    if (tree->car) {
      dump_args(mrb, tree->car, offset+1);
    }
    tree = tree->cdr;
    mrb_parser_dump(mrb, tree->car, offset+1);
    break;

  case NODE_POSTEXE:
    printf("NODE_POSTEXE:\n");
    mrb_parser_dump(mrb, tree, offset+1);
    break;

  case NODE_HEREDOC:
    printf("NODE_HEREDOC (<<%s):\n", ((parser_heredoc_info*)tree)->term);
    dump_recur(mrb, ((parser_heredoc_info*)tree)->doc, offset+1);
    break;

  case NODE_ARGS_TAIL:
    printf("NODE_ARGS_TAIL:\n");
    {
      node *kws = tree->car;

      while (kws) {
        mrb_parser_dump(mrb, kws->car, offset+1);
        kws = kws->cdr;
      }
    }
    tree = tree->cdr;
    if (tree->car) {
      mrb_assert(intn(tree->car->car) == NODE_KW_REST_ARGS);
      mrb_parser_dump(mrb, tree->car, offset+1);
    }
    tree = tree->cdr;
    if (tree->car) {
      dump_prefix(tree, offset+1);
      printf("block='%s'\n", mrb_sym_name(mrb, sym(tree->car)));
    }
    break;

  case NODE_KW_ARG:
    printf("NODE_KW_ARG %s:\n", mrb_sym_name(mrb, sym(tree->car)));
    mrb_parser_dump(mrb, tree->cdr->car, offset + 1);
    break;

  case NODE_KW_REST_ARGS:
    printf("NODE_KW_REST_ARGS %s\n", mrb_sym_name(mrb, sym(tree)));
    break;

  default:
    printf("node type: %d (0x%x)\n", nodetype, (unsigned)nodetype);
    break;
  }
#endif
}
