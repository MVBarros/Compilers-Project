/*
generated at Thu May 16 16:44:08 2019
by $Id: pburg.c,v 2.5 2017/11/16 09:41:42 prs Exp $
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define PBURG_PREFIX "yy"
#define PBURG_VERSION "2.5"
#define MAX_COST 0x7fff
#if defined(__STDC__) || defined(__cplusplus)
#define YYCONST const
#else
#define YYCONST
#endif

#line 1 "diy.brg"

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"
#include "tabid.h"
#include "postfix.h"

/*for fors*/
typedef struct double_lbl {
	int b_lbl;
	int e_lbl;
} doublelbl;

static doublelbl lbls[100];
static int dblcnt = 0;
extern FILE *outfp;
char *dupstr(const char *s);

static long brklbl[20], brkcnt; /* break labels */
/* label _L0 is a break without a while/switch) */

static char *extrns[100]; /* emit externs at the end only */
static int extcnt;
extern int localPos;

int lbl;
char *mklbl(int n) {
  static char buf[20];
  sprintf(buf, "_i%d", n);
  return strcpy(malloc(strlen(buf)+1),buf);
}

static void outstr(char *s) {
  while (*s) fprintf(outfp, pfCHAR, (unsigned char)*s++);
  fprintf(outfp, pfCHAR, 0);
}

int functionReturnType;

static char *mkfunc(char *s) {
  static char buf[80];
  strcpy(buf, "_");
  strcat(buf, s);
  return buf;
}

int isIntFunction(Node* p) {return p->info == 1 ? 1 : MAX_COST;}
int isInt(Node* p) {return (p->info == 1) ? 1 : MAX_COST;}


int isRealFunction(Node* p) {return p->info == 3 ? 1 : MAX_COST;}
int isReal(Node* p) {return p->info == 3 ? 1 : MAX_COST;}


int isString(Node* p) {return p->info == 2 ? 1 : MAX_COST;}
int isStringFunction(Node* p) {return p->info == 2 ? 1 : MAX_COST;}


int isIntPointer(Node* p) {return p->info == 11 ? 1 : MAX_COST;}

#ifndef PANIC
#define PANIC yypanic
static void yypanic(YYCONST char *rot, YYCONST char *msg, int val) {
	fprintf(stderr, "Internal Error in %s: %s %d\nexiting...\n",
		rot, msg, val);
	exit(2);
}
#endif
static void yykids(NODEPTR_TYPE, int, NODEPTR_TYPE[]);
#define yyfinit_NT 1
#define yybloco_NT 2
#define yyparams_NT 3
#define yyparam_NT 4
#define yylist_NT 5
#define yydecls_NT 6
#define yytipo_NT 7
#define yybase_NT 8
#define yyif_NT 9
#define yycond_NT 10
#define yystmt_NT 11
#define yyexpr_NT 12
#define yyifelse_NT 13
#define yycond2_NT 14
#define yywhile_NT 15
#define yydo_NT 16
#define yybegin_NT 17
#define yyfor_NT 18
#define yyforbody_NT 19
#define yyforin_NT 20
#define yyforinstr_NT 21
#define yyforstmt_NT 22
#define yyforstart_NT 23
#define yyiexpr_NT 24
#define yysexpr_NT 25
#define yyrexpr_NT 26
#define yyarguments_NT 27
#define yyilval_NT 28
#define yyilvec_NT 29
#define yyslvec_NT 30
#define yyrlval_NT 31
#define yyrlvec_NT 32
#define yyslval_NT 33
#define yysassign_NT 34
#define yyscmp_NT 35
#define yyiassign_NT 36
#define yyrassign_NT 37

static YYCONST char *yyntname[] = {
	0,
	"finit",
	"bloco",
	"params",
	"param",
	"list",
	"decls",
	"tipo",
	"base",
	"if",
	"cond",
	"stmt",
	"expr",
	"ifelse",
	"cond2",
	"while",
	"do",
	"begin",
	"for",
	"forbody",
	"forin",
	"forinstr",
	"forstmt",
	"forstart",
	"iexpr",
	"sexpr",
	"rexpr",
	"arguments",
	"ilval",
	"ilvec",
	"slvec",
	"rlval",
	"rlvec",
	"slval",
	"sassign",
	"scmp",
	"iassign",
	"rassign",
	0
};

static YYCONST char *yytermname[] = {
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "",
	/* 34 */ "FACTORIAL",
 "", "", "",
	/* 38 */ "MOD",
	/* 39 */ "AND",
 "",
	/* 41 */ "ARGB",
 "",
	/* 43 */ "MUL",
	/* 44 */ "ADD",
	/* 45 */ "NEXT",
	/* 46 */ "SUB",
 "",
	/* 48 */ "DIV",
 "", "", "", "", "", "", "", "", "", "", "",
	/* 60 */ "INSTR",
	/* 61 */ "LT",
	/* 62 */ "LOGIC_EQUAL",
	/* 63 */ "GT",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "",
	/* 92 */ "INDEX",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "",
	/* 124 */ "BLOCK",
	/* 125 */ "OR",
 "",
	/* 127 */ "LOGIC_NOT",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "", "",
	/* 258 */ "INT",
	/* 259 */ "REAL",
	/* 260 */ "ID",
	/* 261 */ "STR",
	/* 262 */ "DO",
	/* 263 */ "WHILE",
	/* 264 */ "IF",
	/* 265 */ "THEN",
	/* 266 */ "FOR",
	/* 267 */ "IN",
	/* 268 */ "UPTO",
	/* 269 */ "DOWNTO",
	/* 270 */ "STEP",
	/* 271 */ "BREAK",
	/* 272 */ "CONTINUE",
	/* 273 */ "VOID",
	/* 274 */ "INTEGER",
	/* 275 */ "STRING",
	/* 276 */ "NUMBER",
	/* 277 */ "CONST",
	/* 278 */ "PUBLIC",
	/* 279 */ "INCR",
	/* 280 */ "DECR",
	/* 281 */ "IFX",
	/* 282 */ "ELSE",
	/* 283 */ "ATR",
	/* 284 */ "NE",
	/* 285 */ "GE",
	/* 286 */ "LE",
	/* 287 */ "UMINUS",
	/* 288 */ "NOT",
	/* 289 */ "REF",
	/* 290 */ "LOCAL",
	/* 291 */ "POSINC",
	/* 292 */ "POSDEC",
	/* 293 */ "PTR",
	/* 294 */ "CALL",
	/* 295 */ "START",
	/* 296 */ "PARAM",
	/* 297 */ "NIL",
	/* 298 */ "LIST",
	/* 299 */ "ARGS",
	/* 300 */ "NONE",
	""
};

struct yystate {
	short cost[38];
	struct {
		unsigned int yyfinit:2;
		unsigned int yybloco:1;
		unsigned int yyparams:2;
		unsigned int yyparam:1;
		unsigned int yylist:2;
		unsigned int yydecls:2;
		unsigned int yytipo:2;
		unsigned int yybase:3;
		unsigned int yyif:1;
		unsigned int yycond:1;
		unsigned int yystmt:2;
		unsigned int yyexpr:3;
		unsigned int yyifelse:1;
		unsigned int yycond2:1;
		unsigned int yywhile:1;
		unsigned int yydo:1;
		unsigned int yybegin:1;
		unsigned int yyfor:1;
		unsigned int yyforbody:1;
		unsigned int yyforin:1;
		unsigned int yyforinstr:1;
		unsigned int yyforstmt:1;
		unsigned int yyforstart:1;
		unsigned int yyiexpr:6;
		unsigned int yysexpr:3;
		unsigned int yyrexpr:4;
		unsigned int yyarguments:2;
		unsigned int yyilval:3;
		unsigned int yyilvec:1;
		unsigned int yyslvec:1;
		unsigned int yyrlval:2;
		unsigned int yyrlvec:1;
		unsigned int yyslval:2;
		unsigned int yysassign:2;
		unsigned int yyscmp:1;
		unsigned int yyiassign:2;
		unsigned int yyrassign:1;
	} rule;
};

static short yynts_0[] = { yybloco_NT, yyparams_NT, 0 };
static short yynts_1[] = { yybloco_NT, 0 };
static short yynts_2[] = { yyparam_NT, 0 };
static short yynts_3[] = { yyparams_NT, yyparam_NT, 0 };
static short yynts_4[] = { yylist_NT, yydecls_NT, 0 };
static short yynts_5[] = { yydecls_NT, yyparam_NT, 0 };
static short yynts_6[] = { 0 };
static short yynts_7[] = { yytipo_NT, 0 };
static short yynts_8[] = { yybase_NT, 0 };
static short yynts_9[] = { yylist_NT, yybase_NT, 0 };
static short yynts_10[] = { yycond_NT, yystmt_NT, 0 };
static short yynts_11[] = { yyexpr_NT, 0 };
static short yynts_12[] = { yycond2_NT, yystmt_NT, 0 };
static short yynts_13[] = { yydo_NT, yyexpr_NT, 0 };
static short yynts_14[] = { yybegin_NT, yystmt_NT, 0 };
static short yynts_15[] = { yyexpr_NT, yyforbody_NT, 0 };
static short yynts_16[] = { yyforin_NT, yyforinstr_NT, 0 };
static short yynts_17[] = { yyforstmt_NT, yyexpr_NT, 0 };
static short yynts_18[] = { yystmt_NT, 0 };
static short yynts_19[] = { yyforstart_NT, yyexpr_NT, 0 };
static short yynts_20[] = { yyif_NT, 0 };
static short yynts_21[] = { yyifelse_NT, 0 };
static short yynts_22[] = { yywhile_NT, 0 };
static short yynts_23[] = { yyfor_NT, 0 };
static short yynts_24[] = { yyiexpr_NT, 0 };
static short yynts_25[] = { yysexpr_NT, 0 };
static short yynts_26[] = { yyrexpr_NT, 0 };
static short yynts_27[] = { yyarguments_NT, 0 };
static short yynts_28[] = { yyilval_NT, 0 };
static short yynts_29[] = { yyilvec_NT, yyexpr_NT, 0 };
static short yynts_30[] = { yyslvec_NT, yyexpr_NT, 0 };
static short yynts_31[] = { yyrlval_NT, 0 };
static short yynts_32[] = { yyrlvec_NT, yyexpr_NT, 0 };
static short yynts_33[] = { yyslval_NT, 0 };
static short yynts_34[] = { yysassign_NT, yyslval_NT, 0 };
static short yynts_35[] = { yyscmp_NT, yyscmp_NT, 0 };
static short yynts_36[] = { yyiassign_NT, yyilval_NT, 0 };
static short yynts_37[] = { yyiexpr_NT, yyiexpr_NT, 0 };
static short yynts_38[] = { yyrexpr_NT, yyrexpr_NT, 0 };
static short yynts_39[] = { yyrassign_NT, yyrlval_NT, 0 };
static short yynts_40[] = { yyarguments_NT, yyexpr_NT, 0 };

static short *yynts[] = {
	0,	/* 0 */
	yynts_0,	/* 1 */
	yynts_1,	/* 2 */
	yynts_2,	/* 3 */
	yynts_3,	/* 4 */
	yynts_4,	/* 5 */
	yynts_5,	/* 6 */
	yynts_6,	/* 7 */
	yynts_7,	/* 8 */
	yynts_6,	/* 9 */
	yynts_6,	/* 10 */
	yynts_6,	/* 11 */
	yynts_8,	/* 12 */
	yynts_9,	/* 13 */
	yynts_10,	/* 14 */
	yynts_11,	/* 15 */
	yynts_12,	/* 16 */
	yynts_10,	/* 17 */
	yynts_13,	/* 18 */
	yynts_14,	/* 19 */
	yynts_6,	/* 20 */
	yynts_15,	/* 21 */
	yynts_16,	/* 22 */
	yynts_17,	/* 23 */
	yynts_18,	/* 24 */
	yynts_19,	/* 25 */
	yynts_6,	/* 26 */
	yynts_8,	/* 27 */
	yynts_6,	/* 28 */
	yynts_6,	/* 29 */
	yynts_11,	/* 30 */
	yynts_20,	/* 31 */
	yynts_21,	/* 32 */
	yynts_22,	/* 33 */
	yynts_23,	/* 34 */
	yynts_1,	/* 35 */
	yynts_24,	/* 36 */
	yynts_25,	/* 37 */
	yynts_26,	/* 38 */
	yynts_27,	/* 39 */
	yynts_6,	/* 40 */
	yynts_6,	/* 41 */
	yynts_6,	/* 42 */
	yynts_28,	/* 43 */
	yynts_29,	/* 44 */
	yynts_30,	/* 45 */
	yynts_6,	/* 46 */
	yynts_6,	/* 47 */
	yynts_31,	/* 48 */
	yynts_32,	/* 49 */
	yynts_6,	/* 50 */
	yynts_6,	/* 51 */
	yynts_33,	/* 52 */
	yynts_6,	/* 53 */
	yynts_33,	/* 54 */
	yynts_25,	/* 55 */
	yynts_24,	/* 56 */
	yynts_34,	/* 57 */
	yynts_27,	/* 58 */
	yynts_6,	/* 59 */
	yynts_25,	/* 60 */
	yynts_35,	/* 61 */
	yynts_35,	/* 62 */
	yynts_35,	/* 63 */
	yynts_35,	/* 64 */
	yynts_35,	/* 65 */
	yynts_35,	/* 66 */
	yynts_35,	/* 67 */
	yynts_35,	/* 68 */
	yynts_24,	/* 69 */
	yynts_26,	/* 70 */
	yynts_6,	/* 71 */
	yynts_36,	/* 72 */
	yynts_37,	/* 73 */
	yynts_37,	/* 74 */
	yynts_37,	/* 75 */
	yynts_37,	/* 76 */
	yynts_37,	/* 77 */
	yynts_37,	/* 78 */
	yynts_37,	/* 79 */
	yynts_37,	/* 80 */
	yynts_37,	/* 81 */
	yynts_37,	/* 82 */
	yynts_37,	/* 83 */
	yynts_37,	/* 84 */
	yynts_37,	/* 85 */
	yynts_24,	/* 86 */
	yynts_24,	/* 87 */
	yynts_24,	/* 88 */
	yynts_28,	/* 89 */
	yynts_28,	/* 90 */
	yynts_28,	/* 91 */
	yynts_28,	/* 92 */
	yynts_28,	/* 93 */
	yynts_27,	/* 94 */
	yynts_6,	/* 95 */
	yynts_38,	/* 96 */
	yynts_38,	/* 97 */
	yynts_38,	/* 98 */
	yynts_38,	/* 99 */
	yynts_38,	/* 100 */
	yynts_38,	/* 101 */
	yynts_28,	/* 102 */
	yynts_39,	/* 103 */
	yynts_26,	/* 104 */
	yynts_6,	/* 105 */
	yynts_38,	/* 106 */
	yynts_26,	/* 107 */
	yynts_38,	/* 108 */
	yynts_38,	/* 109 */
	yynts_38,	/* 110 */
	yynts_24,	/* 111 */
	yynts_31,	/* 112 */
	yynts_27,	/* 113 */
	yynts_6,	/* 114 */
	yynts_11,	/* 115 */
	yynts_40,	/* 116 */
};


static YYCONST char *yystring[] = {
/* 0 */	0,
/* 1 */	"finit: ARGB(bloco,params)",
/* 2 */	"finit: ARGB(bloco,NIL)",
/* 3 */	"params: param",
/* 4 */	"params: NEXT(params,param)",
/* 5 */	"bloco: BLOCK(list,decls)",
/* 6 */	"decls: INSTR(decls,param)",
/* 7 */	"decls: NONE",
/* 8 */	"param: PARAM(tipo,ID)",
/* 9 */	"tipo: INTEGER",
/* 10 */	"tipo: STRING",
/* 11 */	"tipo: NUMBER",
/* 12 */	"list: base",
/* 13 */	"list: LIST(list,base)",
/* 14 */	"if: IF(cond,stmt)",
/* 15 */	"cond: expr",
/* 16 */	"ifelse: ELSE(cond2,stmt)",
/* 17 */	"cond2: IF(cond,stmt)",
/* 18 */	"while: WHILE(do,expr)",
/* 19 */	"do: DO(begin,stmt)",
/* 20 */	"begin: START",
/* 21 */	"for: INSTR(expr,forbody)",
/* 22 */	"forbody: FOR(forin,forinstr)",
/* 23 */	"forinstr: INSTR(forstmt,expr)",
/* 24 */	"forstmt: stmt",
/* 25 */	"forin: IN(forstart,expr)",
/* 26 */	"forstart: START",
/* 27 */	"stmt: base",
/* 28 */	"stmt: BREAK",
/* 29 */	"stmt: CONTINUE",
/* 30 */	"base: expr",
/* 31 */	"base: if",
/* 32 */	"base: ifelse",
/* 33 */	"base: while",
/* 34 */	"base: for",
/* 35 */	"base: bloco",
/* 36 */	"expr: iexpr",
/* 37 */	"expr: sexpr",
/* 38 */	"expr: rexpr",
/* 39 */	"expr: CALL(ID,arguments)",
/* 40 */	"expr: CALL(ID,VOID)",
/* 41 */	"ilval: LOCAL",
/* 42 */	"ilval: ID",
/* 43 */	"ilvec: ilval",
/* 44 */	"ilval: INDEX(ilvec,expr)",
/* 45 */	"ilval: INDEX(slvec,expr)",
/* 46 */	"rlval: LOCAL",
/* 47 */	"rlval: ID",
/* 48 */	"rlvec: rlval",
/* 49 */	"rlval: INDEX(rlvec,expr)",
/* 50 */	"slval: LOCAL",
/* 51 */	"slval: ID",
/* 52 */	"slvec: slval",
/* 53 */	"sexpr: STR",
/* 54 */	"sexpr: PTR(slval)",
/* 55 */	"sassign: sexpr",
/* 56 */	"sassign: iexpr",
/* 57 */	"sexpr: ATR(sassign,slval)",
/* 58 */	"sexpr: CALL(ID,arguments)",
/* 59 */	"sexpr: CALL(ID,VOID)",
/* 60 */	"scmp: sexpr",
/* 61 */	"iexpr: LT(scmp,scmp)",
/* 62 */	"iexpr: GT(scmp,scmp)",
/* 63 */	"iexpr: GE(scmp,scmp)",
/* 64 */	"iexpr: LE(scmp,scmp)",
/* 65 */	"iexpr: NE(scmp,scmp)",
/* 66 */	"iexpr: LOGIC_EQUAL(scmp,scmp)",
/* 67 */	"iexpr: AND(scmp,scmp)",
/* 68 */	"iexpr: OR(scmp,scmp)",
/* 69 */	"iassign: iexpr",
/* 70 */	"iassign: rexpr",
/* 71 */	"iexpr: INT",
/* 72 */	"iexpr: ATR(iassign,ilval)",
/* 73 */	"iexpr: ADD(iexpr,iexpr)",
/* 74 */	"iexpr: SUB(iexpr,iexpr)",
/* 75 */	"iexpr: DIV(iexpr,iexpr)",
/* 76 */	"iexpr: MOD(iexpr,iexpr)",
/* 77 */	"iexpr: MUL(iexpr,iexpr)",
/* 78 */	"iexpr: LT(iexpr,iexpr)",
/* 79 */	"iexpr: GT(iexpr,iexpr)",
/* 80 */	"iexpr: GE(iexpr,iexpr)",
/* 81 */	"iexpr: LE(iexpr,iexpr)",
/* 82 */	"iexpr: NE(iexpr,iexpr)",
/* 83 */	"iexpr: LOGIC_EQUAL(iexpr,iexpr)",
/* 84 */	"iexpr: AND(iexpr,iexpr)",
/* 85 */	"iexpr: OR(iexpr,iexpr)",
/* 86 */	"iexpr: FACTORIAL(iexpr)",
/* 87 */	"iexpr: NOT(iexpr)",
/* 88 */	"iexpr: UMINUS(iexpr)",
/* 89 */	"iexpr: INCR(ilval)",
/* 90 */	"iexpr: DECR(ilval)",
/* 91 */	"iexpr: POSINC(ilval)",
/* 92 */	"iexpr: POSDEC(ilval)",
/* 93 */	"iexpr: PTR(ilval)",
/* 94 */	"iexpr: CALL(ID,arguments)",
/* 95 */	"iexpr: CALL(ID,VOID)",
/* 96 */	"iexpr: LT(rexpr,rexpr)",
/* 97 */	"iexpr: GT(rexpr,rexpr)",
/* 98 */	"iexpr: GE(rexpr,rexpr)",
/* 99 */	"iexpr: LE(rexpr,rexpr)",
/* 100 */	"iexpr: LOGIC_EQUAL(rexpr,rexpr)",
/* 101 */	"iexpr: NE(rexpr,rexpr)",
/* 102 */	"iexpr: REF(ilval)",
/* 103 */	"rexpr: ATR(rassign,rlval)",
/* 104 */	"rassign: rexpr",
/* 105 */	"rexpr: REAL",
/* 106 */	"rexpr: ADD(rexpr,rexpr)",
/* 107 */	"rexpr: UMINUS(rexpr)",
/* 108 */	"rexpr: SUB(rexpr,rexpr)",
/* 109 */	"rexpr: MUL(rexpr,rexpr)",
/* 110 */	"rexpr: DIV(rexpr,rexpr)",
/* 111 */	"rexpr: iexpr",
/* 112 */	"rexpr: PTR(rlval)",
/* 113 */	"rexpr: CALL(ID,arguments)",
/* 114 */	"rexpr: CALL(ID,VOID)",
/* 115 */	"arguments: ARGS(NIL,expr)",
/* 116 */	"arguments: ARGS(arguments,expr)",
};

#ifndef TRACE
static void yytrace(NODEPTR_TYPE p, int eruleno, int cost, int bestcost)
{
	int op = OP_LABEL(p);
	YYCONST char *tname = yytermname[op] ? yytermname[op] : "?";
	fprintf(stderr, "0x%lx:%s matched %s with cost %d vs. %d\n", (long)p, tname, yystring[eruleno], cost, bestcost);
}
#endif

static short yydecode_finit[] = {
	0,
	1,
	2,
};

static short yydecode_bloco[] = {
	0,
	5,
};

static short yydecode_params[] = {
	0,
	3,
	4,
};

static short yydecode_param[] = {
	0,
	8,
};

static short yydecode_list[] = {
	0,
	12,
	13,
};

static short yydecode_decls[] = {
	0,
	6,
	7,
};

static short yydecode_tipo[] = {
	0,
	9,
	10,
	11,
};

static short yydecode_base[] = {
	0,
	30,
	31,
	32,
	33,
	34,
	35,
};

static short yydecode_if[] = {
	0,
	14,
};

static short yydecode_cond[] = {
	0,
	15,
};

static short yydecode_stmt[] = {
	0,
	27,
	28,
	29,
};

static short yydecode_expr[] = {
	0,
	36,
	37,
	38,
	39,
	40,
};

static short yydecode_ifelse[] = {
	0,
	16,
};

static short yydecode_cond2[] = {
	0,
	17,
};

static short yydecode_while[] = {
	0,
	18,
};

static short yydecode_do[] = {
	0,
	19,
};

static short yydecode_begin[] = {
	0,
	20,
};

static short yydecode_for[] = {
	0,
	21,
};

static short yydecode_forbody[] = {
	0,
	22,
};

static short yydecode_forin[] = {
	0,
	25,
};

static short yydecode_forinstr[] = {
	0,
	23,
};

static short yydecode_forstmt[] = {
	0,
	24,
};

static short yydecode_forstart[] = {
	0,
	26,
};

static short yydecode_iexpr[] = {
	0,
	61,
	62,
	63,
	64,
	65,
	66,
	67,
	68,
	71,
	72,
	73,
	74,
	75,
	76,
	77,
	78,
	79,
	80,
	81,
	82,
	83,
	84,
	85,
	86,
	87,
	88,
	89,
	90,
	91,
	92,
	93,
	94,
	95,
	96,
	97,
	98,
	99,
	100,
	101,
	102,
};

static short yydecode_sexpr[] = {
	0,
	53,
	54,
	57,
	58,
	59,
};

static short yydecode_rexpr[] = {
	0,
	103,
	105,
	106,
	107,
	108,
	109,
	110,
	111,
	112,
	113,
	114,
};

static short yydecode_arguments[] = {
	0,
	115,
	116,
};

static short yydecode_ilval[] = {
	0,
	41,
	42,
	44,
	45,
};

static short yydecode_ilvec[] = {
	0,
	43,
};

static short yydecode_slvec[] = {
	0,
	52,
};

static short yydecode_rlval[] = {
	0,
	46,
	47,
	49,
};

static short yydecode_rlvec[] = {
	0,
	48,
};

static short yydecode_slval[] = {
	0,
	50,
	51,
};

static short yydecode_sassign[] = {
	0,
	55,
	56,
};

static short yydecode_scmp[] = {
	0,
	60,
};

static short yydecode_iassign[] = {
	0,
	69,
	70,
};

static short yydecode_rassign[] = {
	0,
	104,
};

static int yyrule(void *state, int goalnt) {
	if (goalnt < 1 || goalnt > 37)
		PANIC("yyrule", "Bad goal nonterminal", goalnt);
	if (!state)
		return 0;
	switch (goalnt) {
	case yyfinit_NT:	return yydecode_finit[((struct yystate *)state)->rule.yyfinit];
	case yybloco_NT:	return yydecode_bloco[((struct yystate *)state)->rule.yybloco];
	case yyparams_NT:	return yydecode_params[((struct yystate *)state)->rule.yyparams];
	case yyparam_NT:	return yydecode_param[((struct yystate *)state)->rule.yyparam];
	case yylist_NT:	return yydecode_list[((struct yystate *)state)->rule.yylist];
	case yydecls_NT:	return yydecode_decls[((struct yystate *)state)->rule.yydecls];
	case yytipo_NT:	return yydecode_tipo[((struct yystate *)state)->rule.yytipo];
	case yybase_NT:	return yydecode_base[((struct yystate *)state)->rule.yybase];
	case yyif_NT:	return yydecode_if[((struct yystate *)state)->rule.yyif];
	case yycond_NT:	return yydecode_cond[((struct yystate *)state)->rule.yycond];
	case yystmt_NT:	return yydecode_stmt[((struct yystate *)state)->rule.yystmt];
	case yyexpr_NT:	return yydecode_expr[((struct yystate *)state)->rule.yyexpr];
	case yyifelse_NT:	return yydecode_ifelse[((struct yystate *)state)->rule.yyifelse];
	case yycond2_NT:	return yydecode_cond2[((struct yystate *)state)->rule.yycond2];
	case yywhile_NT:	return yydecode_while[((struct yystate *)state)->rule.yywhile];
	case yydo_NT:	return yydecode_do[((struct yystate *)state)->rule.yydo];
	case yybegin_NT:	return yydecode_begin[((struct yystate *)state)->rule.yybegin];
	case yyfor_NT:	return yydecode_for[((struct yystate *)state)->rule.yyfor];
	case yyforbody_NT:	return yydecode_forbody[((struct yystate *)state)->rule.yyforbody];
	case yyforin_NT:	return yydecode_forin[((struct yystate *)state)->rule.yyforin];
	case yyforinstr_NT:	return yydecode_forinstr[((struct yystate *)state)->rule.yyforinstr];
	case yyforstmt_NT:	return yydecode_forstmt[((struct yystate *)state)->rule.yyforstmt];
	case yyforstart_NT:	return yydecode_forstart[((struct yystate *)state)->rule.yyforstart];
	case yyiexpr_NT:	return yydecode_iexpr[((struct yystate *)state)->rule.yyiexpr];
	case yysexpr_NT:	return yydecode_sexpr[((struct yystate *)state)->rule.yysexpr];
	case yyrexpr_NT:	return yydecode_rexpr[((struct yystate *)state)->rule.yyrexpr];
	case yyarguments_NT:	return yydecode_arguments[((struct yystate *)state)->rule.yyarguments];
	case yyilval_NT:	return yydecode_ilval[((struct yystate *)state)->rule.yyilval];
	case yyilvec_NT:	return yydecode_ilvec[((struct yystate *)state)->rule.yyilvec];
	case yyslvec_NT:	return yydecode_slvec[((struct yystate *)state)->rule.yyslvec];
	case yyrlval_NT:	return yydecode_rlval[((struct yystate *)state)->rule.yyrlval];
	case yyrlvec_NT:	return yydecode_rlvec[((struct yystate *)state)->rule.yyrlvec];
	case yyslval_NT:	return yydecode_slval[((struct yystate *)state)->rule.yyslval];
	case yysassign_NT:	return yydecode_sassign[((struct yystate *)state)->rule.yysassign];
	case yyscmp_NT:	return yydecode_scmp[((struct yystate *)state)->rule.yyscmp];
	case yyiassign_NT:	return yydecode_iassign[((struct yystate *)state)->rule.yyiassign];
	case yyrassign_NT:	return yydecode_rassign[((struct yystate *)state)->rule.yyrassign];
	default:
		PANIC("yyrule", "Bad goal nonterminal", goalnt);
		return 0;
	}
}

static void yyclosure_bloco(NODEPTR_TYPE, int);
static void yyclosure_param(NODEPTR_TYPE, int);
static void yyclosure_base(NODEPTR_TYPE, int);
static void yyclosure_if(NODEPTR_TYPE, int);
static void yyclosure_stmt(NODEPTR_TYPE, int);
static void yyclosure_expr(NODEPTR_TYPE, int);
static void yyclosure_ifelse(NODEPTR_TYPE, int);
static void yyclosure_while(NODEPTR_TYPE, int);
static void yyclosure_for(NODEPTR_TYPE, int);
static void yyclosure_iexpr(NODEPTR_TYPE, int);
static void yyclosure_sexpr(NODEPTR_TYPE, int);
static void yyclosure_rexpr(NODEPTR_TYPE, int);
static void yyclosure_ilval(NODEPTR_TYPE, int);
static void yyclosure_rlval(NODEPTR_TYPE, int);
static void yyclosure_slval(NODEPTR_TYPE, int);

static void yyclosure_bloco(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 35, c + 0, p->cost[yybase_NT]);
	if (c + 0 < p->cost[yybase_NT]) {
		p->cost[yybase_NT] = c + 0;
		p->rule.yybase = 6;
		yyclosure_base(a, c + 0);
	}
}

static void yyclosure_param(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 3, c + 0, p->cost[yyparams_NT]);
	if (c + 0 < p->cost[yyparams_NT]) {
		p->cost[yyparams_NT] = c + 0;
		p->rule.yyparams = 1;
	}
}

static void yyclosure_base(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 27, c + 0, p->cost[yystmt_NT]);
	if (c + 0 < p->cost[yystmt_NT]) {
		p->cost[yystmt_NT] = c + 0;
		p->rule.yystmt = 1;
		yyclosure_stmt(a, c + 0);
	}
	yytrace(a, 12, c + 0, p->cost[yylist_NT]);
	if (c + 0 < p->cost[yylist_NT]) {
		p->cost[yylist_NT] = c + 0;
		p->rule.yylist = 1;
	}
}

static void yyclosure_if(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 31, c + 0, p->cost[yybase_NT]);
	if (c + 0 < p->cost[yybase_NT]) {
		p->cost[yybase_NT] = c + 0;
		p->rule.yybase = 2;
		yyclosure_base(a, c + 0);
	}
}

static void yyclosure_stmt(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 24, c + 1, p->cost[yyforstmt_NT]);
	if (c + 1 < p->cost[yyforstmt_NT]) {
		p->cost[yyforstmt_NT] = c + 1;
		p->rule.yyforstmt = 1;
	}
}

static void yyclosure_expr(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 30, c + 1, p->cost[yybase_NT]);
	if (c + 1 < p->cost[yybase_NT]) {
		p->cost[yybase_NT] = c + 1;
		p->rule.yybase = 1;
		yyclosure_base(a, c + 1);
	}
	yytrace(a, 15, c + 1, p->cost[yycond_NT]);
	if (c + 1 < p->cost[yycond_NT]) {
		p->cost[yycond_NT] = c + 1;
		p->rule.yycond = 1;
	}
}

static void yyclosure_ifelse(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 32, c + 0, p->cost[yybase_NT]);
	if (c + 0 < p->cost[yybase_NT]) {
		p->cost[yybase_NT] = c + 0;
		p->rule.yybase = 3;
		yyclosure_base(a, c + 0);
	}
}

static void yyclosure_while(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 33, c + 0, p->cost[yybase_NT]);
	if (c + 0 < p->cost[yybase_NT]) {
		p->cost[yybase_NT] = c + 0;
		p->rule.yybase = 4;
		yyclosure_base(a, c + 0);
	}
}

static void yyclosure_for(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 34, c + 0, p->cost[yybase_NT]);
	if (c + 0 < p->cost[yybase_NT]) {
		p->cost[yybase_NT] = c + 0;
		p->rule.yybase = 5;
		yyclosure_base(a, c + 0);
	}
}

static void yyclosure_iexpr(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 111, c + 1, p->cost[yyrexpr_NT]);
	if (c + 1 < p->cost[yyrexpr_NT]) {
		p->cost[yyrexpr_NT] = c + 1;
		p->rule.yyrexpr = 8;
		yyclosure_rexpr(a, c + 1);
	}
	yytrace(a, 69, c + 1, p->cost[yyiassign_NT]);
	if (c + 1 < p->cost[yyiassign_NT]) {
		p->cost[yyiassign_NT] = c + 1;
		p->rule.yyiassign = 1;
	}
	yytrace(a, 56, c + 1, p->cost[yysassign_NT]);
	if (c + 1 < p->cost[yysassign_NT]) {
		p->cost[yysassign_NT] = c + 1;
		p->rule.yysassign = 2;
	}
	yytrace(a, 36, c + 0, p->cost[yyexpr_NT]);
	if (c + 0 < p->cost[yyexpr_NT]) {
		p->cost[yyexpr_NT] = c + 0;
		p->rule.yyexpr = 1;
		yyclosure_expr(a, c + 0);
	}
}

static void yyclosure_sexpr(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 60, c + 0, p->cost[yyscmp_NT]);
	if (c + 0 < p->cost[yyscmp_NT]) {
		p->cost[yyscmp_NT] = c + 0;
		p->rule.yyscmp = 1;
	}
	yytrace(a, 55, c + 1, p->cost[yysassign_NT]);
	if (c + 1 < p->cost[yysassign_NT]) {
		p->cost[yysassign_NT] = c + 1;
		p->rule.yysassign = 1;
	}
	yytrace(a, 37, c + 0, p->cost[yyexpr_NT]);
	if (c + 0 < p->cost[yyexpr_NT]) {
		p->cost[yyexpr_NT] = c + 0;
		p->rule.yyexpr = 2;
		yyclosure_expr(a, c + 0);
	}
}

static void yyclosure_rexpr(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 104, c + 1, p->cost[yyrassign_NT]);
	if (c + 1 < p->cost[yyrassign_NT]) {
		p->cost[yyrassign_NT] = c + 1;
		p->rule.yyrassign = 1;
	}
	yytrace(a, 70, c + 1, p->cost[yyiassign_NT]);
	if (c + 1 < p->cost[yyiassign_NT]) {
		p->cost[yyiassign_NT] = c + 1;
		p->rule.yyiassign = 2;
	}
	yytrace(a, 38, c + 0, p->cost[yyexpr_NT]);
	if (c + 0 < p->cost[yyexpr_NT]) {
		p->cost[yyexpr_NT] = c + 0;
		p->rule.yyexpr = 3;
		yyclosure_expr(a, c + 0);
	}
}

static void yyclosure_ilval(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 43, c + 1, p->cost[yyilvec_NT]);
	if (c + 1 < p->cost[yyilvec_NT]) {
		p->cost[yyilvec_NT] = c + 1;
		p->rule.yyilvec = 1;
	}
}

static void yyclosure_rlval(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 48, c + 1, p->cost[yyrlvec_NT]);
	if (c + 1 < p->cost[yyrlvec_NT]) {
		p->cost[yyrlvec_NT] = c + 1;
		p->rule.yyrlvec = 1;
	}
}

static void yyclosure_slval(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 52, c + 1, p->cost[yyslvec_NT]);
	if (c + 1 < p->cost[yyslvec_NT]) {
		p->cost[yyslvec_NT] = c + 1;
		p->rule.yyslvec = 1;
	}
}

static void yylabel(NODEPTR_TYPE a, NODEPTR_TYPE u) {
	int c;
	struct yystate *p;

	if (!a)
		PANIC("yylabel", "Null tree in", OP_LABEL(u));
	STATE_LABEL(a) = p = (struct yystate *)malloc(sizeof *p);
	memset(p, 0, sizeof *p);
	p->cost[1] =
	p->cost[2] =
	p->cost[3] =
	p->cost[4] =
	p->cost[5] =
	p->cost[6] =
	p->cost[7] =
	p->cost[8] =
	p->cost[9] =
	p->cost[10] =
	p->cost[11] =
	p->cost[12] =
	p->cost[13] =
	p->cost[14] =
	p->cost[15] =
	p->cost[16] =
	p->cost[17] =
	p->cost[18] =
	p->cost[19] =
	p->cost[20] =
	p->cost[21] =
	p->cost[22] =
	p->cost[23] =
	p->cost[24] =
	p->cost[25] =
	p->cost[26] =
	p->cost[27] =
	p->cost[28] =
	p->cost[29] =
	p->cost[30] =
	p->cost[31] =
	p->cost[32] =
	p->cost[33] =
	p->cost[34] =
	p->cost[35] =
	p->cost[36] =
	p->cost[37] =
		0x7fff;
	switch (OP_LABEL(a)) {
	case 33: /* FACTORIAL */
		yylabel(LEFT_CHILD(a),a);
		/* iexpr: FACTORIAL(iexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyiexpr_NT] + 1;
		yytrace(a, 86, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 24;
			yyclosure_iexpr(a, c + 0);
		}
		break;
	case 37: /* MOD */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* iexpr: MOD(iexpr,iexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyiexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyiexpr_NT] + 1;
		yytrace(a, 76, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 14;
			yyclosure_iexpr(a, c + 0);
		}
		break;
	case 38: /* AND */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* iexpr: AND(scmp,scmp) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyscmp_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyscmp_NT] + 1;
		yytrace(a, 67, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 7;
			yyclosure_iexpr(a, c + 0);
		}
		/* iexpr: AND(iexpr,iexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyiexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyiexpr_NT] + 1;
		yytrace(a, 84, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 22;
			yyclosure_iexpr(a, c + 0);
		}
		break;
	case 40: /* ARGB */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* finit: ARGB(bloco,params) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yybloco_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyparams_NT] + 1;
		yytrace(a, 1, c + 0, p->cost[yyfinit_NT]);
		if (c + 0 < p->cost[yyfinit_NT]) {
			p->cost[yyfinit_NT] = c + 0;
			p->rule.yyfinit = 1;
		}
		if (	/* finit: ARGB(bloco,NIL) */
			OP_LABEL(RIGHT_CHILD(a)) == 296 /* NIL */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yybloco_NT] + 1;
			yytrace(a, 2, c + 0, p->cost[yyfinit_NT]);
			if (c + 0 < p->cost[yyfinit_NT]) {
				p->cost[yyfinit_NT] = c + 0;
				p->rule.yyfinit = 2;
			}
		}
		break;
	case 42: /* MUL */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* iexpr: MUL(iexpr,iexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyiexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyiexpr_NT] + 1;
		yytrace(a, 77, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 15;
			yyclosure_iexpr(a, c + 0);
		}
		/* rexpr: MUL(rexpr,rexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyrexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyrexpr_NT] + 1;
		yytrace(a, 109, c + 0, p->cost[yyrexpr_NT]);
		if (c + 0 < p->cost[yyrexpr_NT]) {
			p->cost[yyrexpr_NT] = c + 0;
			p->rule.yyrexpr = 6;
			yyclosure_rexpr(a, c + 0);
		}
		break;
	case 43: /* ADD */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* iexpr: ADD(iexpr,iexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyiexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyiexpr_NT] + 1;
		yytrace(a, 73, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 11;
			yyclosure_iexpr(a, c + 0);
		}
		/* rexpr: ADD(rexpr,rexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyrexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyrexpr_NT] + 1;
		yytrace(a, 106, c + 0, p->cost[yyrexpr_NT]);
		if (c + 0 < p->cost[yyrexpr_NT]) {
			p->cost[yyrexpr_NT] = c + 0;
			p->rule.yyrexpr = 3;
			yyclosure_rexpr(a, c + 0);
		}
		break;
	case 44: /* NEXT */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* params: NEXT(params,param) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyparams_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyparam_NT] + 0;
		yytrace(a, 4, c + 0, p->cost[yyparams_NT]);
		if (c + 0 < p->cost[yyparams_NT]) {
			p->cost[yyparams_NT] = c + 0;
			p->rule.yyparams = 2;
		}
		break;
	case 45: /* SUB */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* iexpr: SUB(iexpr,iexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyiexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyiexpr_NT] + 1;
		yytrace(a, 74, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 12;
			yyclosure_iexpr(a, c + 0);
		}
		/* rexpr: SUB(rexpr,rexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyrexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyrexpr_NT] + 1;
		yytrace(a, 108, c + 0, p->cost[yyrexpr_NT]);
		if (c + 0 < p->cost[yyrexpr_NT]) {
			p->cost[yyrexpr_NT] = c + 0;
			p->rule.yyrexpr = 5;
			yyclosure_rexpr(a, c + 0);
		}
		break;
	case 47: /* DIV */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* iexpr: DIV(iexpr,iexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyiexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyiexpr_NT] + 1;
		yytrace(a, 75, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 13;
			yyclosure_iexpr(a, c + 0);
		}
		/* rexpr: DIV(rexpr,rexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyrexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyrexpr_NT] + 1;
		yytrace(a, 110, c + 0, p->cost[yyrexpr_NT]);
		if (c + 0 < p->cost[yyrexpr_NT]) {
			p->cost[yyrexpr_NT] = c + 0;
			p->rule.yyrexpr = 7;
			yyclosure_rexpr(a, c + 0);
		}
		break;
	case 59: /* INSTR */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* decls: INSTR(decls,param) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yydecls_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyparam_NT] + 0;
		yytrace(a, 6, c + 0, p->cost[yydecls_NT]);
		if (c + 0 < p->cost[yydecls_NT]) {
			p->cost[yydecls_NT] = c + 0;
			p->rule.yydecls = 1;
		}
		/* for: INSTR(expr,forbody) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyforbody_NT] + 0;
		yytrace(a, 21, c + 0, p->cost[yyfor_NT]);
		if (c + 0 < p->cost[yyfor_NT]) {
			p->cost[yyfor_NT] = c + 0;
			p->rule.yyfor = 1;
			yyclosure_for(a, c + 0);
		}
		/* forinstr: INSTR(forstmt,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyforstmt_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 23, c + 0, p->cost[yyforinstr_NT]);
		if (c + 0 < p->cost[yyforinstr_NT]) {
			p->cost[yyforinstr_NT] = c + 0;
			p->rule.yyforinstr = 1;
		}
		break;
	case 60: /* LT */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* iexpr: LT(scmp,scmp) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyscmp_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyscmp_NT] + 1;
		yytrace(a, 61, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 1;
			yyclosure_iexpr(a, c + 0);
		}
		/* iexpr: LT(iexpr,iexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyiexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyiexpr_NT] + 1;
		yytrace(a, 78, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 16;
			yyclosure_iexpr(a, c + 0);
		}
		/* iexpr: LT(rexpr,rexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyrexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyrexpr_NT] + 1;
		yytrace(a, 96, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 34;
			yyclosure_iexpr(a, c + 0);
		}
		break;
	case 61: /* LOGIC_EQUAL */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* iexpr: LOGIC_EQUAL(scmp,scmp) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyscmp_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyscmp_NT] + 1;
		yytrace(a, 66, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 6;
			yyclosure_iexpr(a, c + 0);
		}
		/* iexpr: LOGIC_EQUAL(iexpr,iexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyiexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyiexpr_NT] + 1;
		yytrace(a, 83, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 21;
			yyclosure_iexpr(a, c + 0);
		}
		/* iexpr: LOGIC_EQUAL(rexpr,rexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyrexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyrexpr_NT] + 1;
		yytrace(a, 100, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 38;
			yyclosure_iexpr(a, c + 0);
		}
		break;
	case 62: /* GT */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* iexpr: GT(scmp,scmp) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyscmp_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyscmp_NT] + 1;
		yytrace(a, 62, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 2;
			yyclosure_iexpr(a, c + 0);
		}
		/* iexpr: GT(iexpr,iexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyiexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyiexpr_NT] + 1;
		yytrace(a, 79, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 17;
			yyclosure_iexpr(a, c + 0);
		}
		/* iexpr: GT(rexpr,rexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyrexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyrexpr_NT] + 1;
		yytrace(a, 97, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 35;
			yyclosure_iexpr(a, c + 0);
		}
		break;
	case 91: /* INDEX */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* ilval: INDEX(ilvec,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyilvec_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + (isInt(a));
		yytrace(a, 44, c + 0, p->cost[yyilval_NT]);
		if (c + 0 < p->cost[yyilval_NT]) {
			p->cost[yyilval_NT] = c + 0;
			p->rule.yyilval = 3;
			yyclosure_ilval(a, c + 0);
		}
		/* ilval: INDEX(slvec,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyslvec_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + (isInt(a));
		yytrace(a, 45, c + 0, p->cost[yyilval_NT]);
		if (c + 0 < p->cost[yyilval_NT]) {
			p->cost[yyilval_NT] = c + 0;
			p->rule.yyilval = 4;
			yyclosure_ilval(a, c + 0);
		}
		/* rlval: INDEX(rlvec,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyrlvec_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + (isReal(a));
		yytrace(a, 49, c + 0, p->cost[yyrlval_NT]);
		if (c + 0 < p->cost[yyrlval_NT]) {
			p->cost[yyrlval_NT] = c + 0;
			p->rule.yyrlval = 3;
			yyclosure_rlval(a, c + 0);
		}
		break;
	case 123: /* BLOCK */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* bloco: BLOCK(list,decls) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yylist_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yydecls_NT] + 0;
		yytrace(a, 5, c + 0, p->cost[yybloco_NT]);
		if (c + 0 < p->cost[yybloco_NT]) {
			p->cost[yybloco_NT] = c + 0;
			p->rule.yybloco = 1;
			yyclosure_bloco(a, c + 0);
		}
		break;
	case 124: /* OR */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* iexpr: OR(scmp,scmp) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyscmp_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyscmp_NT] + 1;
		yytrace(a, 68, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 8;
			yyclosure_iexpr(a, c + 0);
		}
		/* iexpr: OR(iexpr,iexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyiexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyiexpr_NT] + 1;
		yytrace(a, 85, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 23;
			yyclosure_iexpr(a, c + 0);
		}
		break;
	case 126: /* LOGIC_NOT */
		return;
	case 257: /* INT */
		/* iexpr: INT */
		yytrace(a, 71, 1 + 0, p->cost[yyiexpr_NT]);
		if (1 + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = 1 + 0;
			p->rule.yyiexpr = 9;
			yyclosure_iexpr(a, 1 + 0);
		}
		break;
	case 258: /* REAL */
		/* rexpr: REAL */
		yytrace(a, 105, 1 + 0, p->cost[yyrexpr_NT]);
		if (1 + 0 < p->cost[yyrexpr_NT]) {
			p->cost[yyrexpr_NT] = 1 + 0;
			p->rule.yyrexpr = 2;
			yyclosure_rexpr(a, 1 + 0);
		}
		break;
	case 259: /* ID */
		/* ilval: ID */
		c = (isInt(a));
		yytrace(a, 42, c + 0, p->cost[yyilval_NT]);
		if (c + 0 < p->cost[yyilval_NT]) {
			p->cost[yyilval_NT] = c + 0;
			p->rule.yyilval = 2;
			yyclosure_ilval(a, c + 0);
		}
		/* rlval: ID */
		c = (isReal(a));
		yytrace(a, 47, c + 0, p->cost[yyrlval_NT]);
		if (c + 0 < p->cost[yyrlval_NT]) {
			p->cost[yyrlval_NT] = c + 0;
			p->rule.yyrlval = 2;
			yyclosure_rlval(a, c + 0);
		}
		/* slval: ID */
		c = (isString(a));
		yytrace(a, 51, c + 0, p->cost[yyslval_NT]);
		if (c + 0 < p->cost[yyslval_NT]) {
			p->cost[yyslval_NT] = c + 0;
			p->rule.yyslval = 2;
			yyclosure_slval(a, c + 0);
		}
		break;
	case 260: /* STR */
		/* sexpr: STR */
		yytrace(a, 53, 1 + 0, p->cost[yysexpr_NT]);
		if (1 + 0 < p->cost[yysexpr_NT]) {
			p->cost[yysexpr_NT] = 1 + 0;
			p->rule.yysexpr = 1;
			yyclosure_sexpr(a, 1 + 0);
		}
		break;
	case 261: /* DO */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* do: DO(begin,stmt) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yybegin_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yystmt_NT] + 1;
		yytrace(a, 19, c + 0, p->cost[yydo_NT]);
		if (c + 0 < p->cost[yydo_NT]) {
			p->cost[yydo_NT] = c + 0;
			p->rule.yydo = 1;
		}
		break;
	case 262: /* WHILE */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* while: WHILE(do,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yydo_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 18, c + 0, p->cost[yywhile_NT]);
		if (c + 0 < p->cost[yywhile_NT]) {
			p->cost[yywhile_NT] = c + 0;
			p->rule.yywhile = 1;
			yyclosure_while(a, c + 0);
		}
		break;
	case 263: /* IF */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* if: IF(cond,stmt) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yycond_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yystmt_NT] + 0;
		yytrace(a, 14, c + 0, p->cost[yyif_NT]);
		if (c + 0 < p->cost[yyif_NT]) {
			p->cost[yyif_NT] = c + 0;
			p->rule.yyif = 1;
			yyclosure_if(a, c + 0);
		}
		/* cond2: IF(cond,stmt) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yycond_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yystmt_NT] + 1;
		yytrace(a, 17, c + 0, p->cost[yycond2_NT]);
		if (c + 0 < p->cost[yycond2_NT]) {
			p->cost[yycond2_NT] = c + 0;
			p->rule.yycond2 = 1;
		}
		break;
	case 264: /* THEN */
		return;
	case 265: /* FOR */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* forbody: FOR(forin,forinstr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyforin_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyforinstr_NT] + 0;
		yytrace(a, 22, c + 0, p->cost[yyforbody_NT]);
		if (c + 0 < p->cost[yyforbody_NT]) {
			p->cost[yyforbody_NT] = c + 0;
			p->rule.yyforbody = 1;
		}
		break;
	case 266: /* IN */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* forin: IN(forstart,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyforstart_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 25, c + 0, p->cost[yyforin_NT]);
		if (c + 0 < p->cost[yyforin_NT]) {
			p->cost[yyforin_NT] = c + 0;
			p->rule.yyforin = 1;
		}
		break;
	case 267: /* UPTO */
		return;
	case 268: /* DOWNTO */
		return;
	case 269: /* STEP */
		return;
	case 270: /* BREAK */
		/* stmt: BREAK */
		yytrace(a, 28, 1 + 0, p->cost[yystmt_NT]);
		if (1 + 0 < p->cost[yystmt_NT]) {
			p->cost[yystmt_NT] = 1 + 0;
			p->rule.yystmt = 2;
			yyclosure_stmt(a, 1 + 0);
		}
		break;
	case 271: /* CONTINUE */
		/* stmt: CONTINUE */
		yytrace(a, 29, 1 + 0, p->cost[yystmt_NT]);
		if (1 + 0 < p->cost[yystmt_NT]) {
			p->cost[yystmt_NT] = 1 + 0;
			p->rule.yystmt = 3;
			yyclosure_stmt(a, 1 + 0);
		}
		break;
	case 272: /* VOID */
		return;
	case 273: /* INTEGER */
		/* tipo: INTEGER */
		yytrace(a, 9, 0 + 0, p->cost[yytipo_NT]);
		if (0 + 0 < p->cost[yytipo_NT]) {
			p->cost[yytipo_NT] = 0 + 0;
			p->rule.yytipo = 1;
		}
		break;
	case 274: /* STRING */
		/* tipo: STRING */
		yytrace(a, 10, 0 + 0, p->cost[yytipo_NT]);
		if (0 + 0 < p->cost[yytipo_NT]) {
			p->cost[yytipo_NT] = 0 + 0;
			p->rule.yytipo = 2;
		}
		break;
	case 275: /* NUMBER */
		/* tipo: NUMBER */
		yytrace(a, 11, 0 + 0, p->cost[yytipo_NT]);
		if (0 + 0 < p->cost[yytipo_NT]) {
			p->cost[yytipo_NT] = 0 + 0;
			p->rule.yytipo = 3;
		}
		break;
	case 276: /* CONST */
		return;
	case 277: /* PUBLIC */
		return;
	case 278: /* INCR */
		yylabel(LEFT_CHILD(a),a);
		/* iexpr: INCR(ilval) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyilval_NT] + 1;
		yytrace(a, 89, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 27;
			yyclosure_iexpr(a, c + 0);
		}
		break;
	case 279: /* DECR */
		yylabel(LEFT_CHILD(a),a);
		/* iexpr: DECR(ilval) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyilval_NT] + 1;
		yytrace(a, 90, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 28;
			yyclosure_iexpr(a, c + 0);
		}
		break;
	case 280: /* IFX */
		return;
	case 281: /* ELSE */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* ifelse: ELSE(cond2,stmt) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yycond2_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yystmt_NT] + 1;
		yytrace(a, 16, c + 0, p->cost[yyifelse_NT]);
		if (c + 0 < p->cost[yyifelse_NT]) {
			p->cost[yyifelse_NT] = c + 0;
			p->rule.yyifelse = 1;
			yyclosure_ifelse(a, c + 0);
		}
		break;
	case 282: /* ATR */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* sexpr: ATR(sassign,slval) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yysassign_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyslval_NT] + 1;
		yytrace(a, 57, c + 0, p->cost[yysexpr_NT]);
		if (c + 0 < p->cost[yysexpr_NT]) {
			p->cost[yysexpr_NT] = c + 0;
			p->rule.yysexpr = 3;
			yyclosure_sexpr(a, c + 0);
		}
		/* iexpr: ATR(iassign,ilval) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyiassign_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyilval_NT] + 1;
		yytrace(a, 72, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 10;
			yyclosure_iexpr(a, c + 0);
		}
		/* rexpr: ATR(rassign,rlval) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyrassign_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyrlval_NT] + 1;
		yytrace(a, 103, c + 0, p->cost[yyrexpr_NT]);
		if (c + 0 < p->cost[yyrexpr_NT]) {
			p->cost[yyrexpr_NT] = c + 0;
			p->rule.yyrexpr = 1;
			yyclosure_rexpr(a, c + 0);
		}
		break;
	case 283: /* NE */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* iexpr: NE(scmp,scmp) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyscmp_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyscmp_NT] + 1;
		yytrace(a, 65, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 5;
			yyclosure_iexpr(a, c + 0);
		}
		/* iexpr: NE(iexpr,iexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyiexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyiexpr_NT] + 1;
		yytrace(a, 82, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 20;
			yyclosure_iexpr(a, c + 0);
		}
		/* iexpr: NE(rexpr,rexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyrexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyrexpr_NT] + 1;
		yytrace(a, 101, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 39;
			yyclosure_iexpr(a, c + 0);
		}
		break;
	case 284: /* GE */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* iexpr: GE(scmp,scmp) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyscmp_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyscmp_NT] + 1;
		yytrace(a, 63, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 3;
			yyclosure_iexpr(a, c + 0);
		}
		/* iexpr: GE(iexpr,iexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyiexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyiexpr_NT] + 1;
		yytrace(a, 80, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 18;
			yyclosure_iexpr(a, c + 0);
		}
		/* iexpr: GE(rexpr,rexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyrexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyrexpr_NT] + 1;
		yytrace(a, 98, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 36;
			yyclosure_iexpr(a, c + 0);
		}
		break;
	case 285: /* LE */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* iexpr: LE(scmp,scmp) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyscmp_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyscmp_NT] + 1;
		yytrace(a, 64, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 4;
			yyclosure_iexpr(a, c + 0);
		}
		/* iexpr: LE(iexpr,iexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyiexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyiexpr_NT] + 1;
		yytrace(a, 81, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 19;
			yyclosure_iexpr(a, c + 0);
		}
		/* iexpr: LE(rexpr,rexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyrexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyrexpr_NT] + 1;
		yytrace(a, 99, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 37;
			yyclosure_iexpr(a, c + 0);
		}
		break;
	case 286: /* UMINUS */
		yylabel(LEFT_CHILD(a),a);
		/* iexpr: UMINUS(iexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyiexpr_NT] + 1;
		yytrace(a, 88, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 26;
			yyclosure_iexpr(a, c + 0);
		}
		/* rexpr: UMINUS(rexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyrexpr_NT] + 1;
		yytrace(a, 107, c + 0, p->cost[yyrexpr_NT]);
		if (c + 0 < p->cost[yyrexpr_NT]) {
			p->cost[yyrexpr_NT] = c + 0;
			p->rule.yyrexpr = 4;
			yyclosure_rexpr(a, c + 0);
		}
		break;
	case 287: /* NOT */
		yylabel(LEFT_CHILD(a),a);
		/* iexpr: NOT(iexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyiexpr_NT] + 1;
		yytrace(a, 87, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 25;
			yyclosure_iexpr(a, c + 0);
		}
		break;
	case 288: /* REF */
		yylabel(LEFT_CHILD(a),a);
		/* iexpr: REF(ilval) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyilval_NT] + 0;
		yytrace(a, 102, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 40;
			yyclosure_iexpr(a, c + 0);
		}
		break;
	case 289: /* LOCAL */
		/* ilval: LOCAL */
		c = (isInt(a));
		yytrace(a, 41, c + 0, p->cost[yyilval_NT]);
		if (c + 0 < p->cost[yyilval_NT]) {
			p->cost[yyilval_NT] = c + 0;
			p->rule.yyilval = 1;
			yyclosure_ilval(a, c + 0);
		}
		/* rlval: LOCAL */
		c = (isReal(a));
		yytrace(a, 46, c + 0, p->cost[yyrlval_NT]);
		if (c + 0 < p->cost[yyrlval_NT]) {
			p->cost[yyrlval_NT] = c + 0;
			p->rule.yyrlval = 1;
			yyclosure_rlval(a, c + 0);
		}
		/* slval: LOCAL */
		c = (isString(a));
		yytrace(a, 50, c + 0, p->cost[yyslval_NT]);
		if (c + 0 < p->cost[yyslval_NT]) {
			p->cost[yyslval_NT] = c + 0;
			p->rule.yyslval = 1;
			yyclosure_slval(a, c + 0);
		}
		break;
	case 290: /* POSINC */
		yylabel(LEFT_CHILD(a),a);
		/* iexpr: POSINC(ilval) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyilval_NT] + 1;
		yytrace(a, 91, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 29;
			yyclosure_iexpr(a, c + 0);
		}
		break;
	case 291: /* POSDEC */
		yylabel(LEFT_CHILD(a),a);
		/* iexpr: POSDEC(ilval) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyilval_NT] + 1;
		yytrace(a, 92, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 30;
			yyclosure_iexpr(a, c + 0);
		}
		break;
	case 292: /* PTR */
		yylabel(LEFT_CHILD(a),a);
		/* sexpr: PTR(slval) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyslval_NT] + 1;
		yytrace(a, 54, c + 0, p->cost[yysexpr_NT]);
		if (c + 0 < p->cost[yysexpr_NT]) {
			p->cost[yysexpr_NT] = c + 0;
			p->rule.yysexpr = 2;
			yyclosure_sexpr(a, c + 0);
		}
		/* iexpr: PTR(ilval) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyilval_NT] + 1;
		yytrace(a, 93, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 31;
			yyclosure_iexpr(a, c + 0);
		}
		/* rexpr: PTR(rlval) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyrlval_NT] + 1;
		yytrace(a, 112, c + 0, p->cost[yyrexpr_NT]);
		if (c + 0 < p->cost[yyrexpr_NT]) {
			p->cost[yyrexpr_NT] = c + 0;
			p->rule.yyrexpr = 9;
			yyclosure_rexpr(a, c + 0);
		}
		break;
	case 293: /* CALL */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		if (	/* expr: CALL(ID,arguments) */
			OP_LABEL(LEFT_CHILD(a)) == 259 /* ID */
		) {
			c = ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyarguments_NT] + 1;
			yytrace(a, 39, c + 0, p->cost[yyexpr_NT]);
			if (c + 0 < p->cost[yyexpr_NT]) {
				p->cost[yyexpr_NT] = c + 0;
				p->rule.yyexpr = 4;
				yyclosure_expr(a, c + 0);
			}
		}
		if (	/* expr: CALL(ID,VOID) */
			OP_LABEL(LEFT_CHILD(a)) == 259 && /* ID */
			OP_LABEL(RIGHT_CHILD(a)) == 272 /* VOID */
		) {
			c = 1;
			yytrace(a, 40, c + 0, p->cost[yyexpr_NT]);
			if (c + 0 < p->cost[yyexpr_NT]) {
				p->cost[yyexpr_NT] = c + 0;
				p->rule.yyexpr = 5;
				yyclosure_expr(a, c + 0);
			}
		}
		if (	/* sexpr: CALL(ID,arguments) */
			OP_LABEL(LEFT_CHILD(a)) == 259 /* ID */
		) {
			c = ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyarguments_NT] + (isStringFunction(a));
			yytrace(a, 58, c + 0, p->cost[yysexpr_NT]);
			if (c + 0 < p->cost[yysexpr_NT]) {
				p->cost[yysexpr_NT] = c + 0;
				p->rule.yysexpr = 4;
				yyclosure_sexpr(a, c + 0);
			}
		}
		if (	/* sexpr: CALL(ID,VOID) */
			OP_LABEL(LEFT_CHILD(a)) == 259 && /* ID */
			OP_LABEL(RIGHT_CHILD(a)) == 272 /* VOID */
		) {
			c = (isStringFunction(a));
			yytrace(a, 59, c + 0, p->cost[yysexpr_NT]);
			if (c + 0 < p->cost[yysexpr_NT]) {
				p->cost[yysexpr_NT] = c + 0;
				p->rule.yysexpr = 5;
				yyclosure_sexpr(a, c + 0);
			}
		}
		if (	/* iexpr: CALL(ID,arguments) */
			OP_LABEL(LEFT_CHILD(a)) == 259 /* ID */
		) {
			c = ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyarguments_NT] + (isIntFunction(a));
			yytrace(a, 94, c + 0, p->cost[yyiexpr_NT]);
			if (c + 0 < p->cost[yyiexpr_NT]) {
				p->cost[yyiexpr_NT] = c + 0;
				p->rule.yyiexpr = 32;
				yyclosure_iexpr(a, c + 0);
			}
		}
		if (	/* iexpr: CALL(ID,VOID) */
			OP_LABEL(LEFT_CHILD(a)) == 259 && /* ID */
			OP_LABEL(RIGHT_CHILD(a)) == 272 /* VOID */
		) {
			c = (isIntFunction(a));
			yytrace(a, 95, c + 0, p->cost[yyiexpr_NT]);
			if (c + 0 < p->cost[yyiexpr_NT]) {
				p->cost[yyiexpr_NT] = c + 0;
				p->rule.yyiexpr = 33;
				yyclosure_iexpr(a, c + 0);
			}
		}
		if (	/* rexpr: CALL(ID,arguments) */
			OP_LABEL(LEFT_CHILD(a)) == 259 /* ID */
		) {
			c = ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyarguments_NT] + (isRealFunction(a));
			yytrace(a, 113, c + 0, p->cost[yyrexpr_NT]);
			if (c + 0 < p->cost[yyrexpr_NT]) {
				p->cost[yyrexpr_NT] = c + 0;
				p->rule.yyrexpr = 10;
				yyclosure_rexpr(a, c + 0);
			}
		}
		if (	/* rexpr: CALL(ID,VOID) */
			OP_LABEL(LEFT_CHILD(a)) == 259 && /* ID */
			OP_LABEL(RIGHT_CHILD(a)) == 272 /* VOID */
		) {
			c = (isRealFunction(a));
			yytrace(a, 114, c + 0, p->cost[yyrexpr_NT]);
			if (c + 0 < p->cost[yyrexpr_NT]) {
				p->cost[yyrexpr_NT] = c + 0;
				p->rule.yyrexpr = 11;
				yyclosure_rexpr(a, c + 0);
			}
		}
		break;
	case 294: /* START */
		/* begin: START */
		yytrace(a, 20, 1 + 0, p->cost[yybegin_NT]);
		if (1 + 0 < p->cost[yybegin_NT]) {
			p->cost[yybegin_NT] = 1 + 0;
			p->rule.yybegin = 1;
		}
		/* forstart: START */
		yytrace(a, 26, 1 + 0, p->cost[yyforstart_NT]);
		if (1 + 0 < p->cost[yyforstart_NT]) {
			p->cost[yyforstart_NT] = 1 + 0;
			p->rule.yyforstart = 1;
		}
		break;
	case 295: /* PARAM */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		if (	/* param: PARAM(tipo,ID) */
			OP_LABEL(RIGHT_CHILD(a)) == 259 /* ID */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yytipo_NT] + 0;
			yytrace(a, 8, c + 0, p->cost[yyparam_NT]);
			if (c + 0 < p->cost[yyparam_NT]) {
				p->cost[yyparam_NT] = c + 0;
				p->rule.yyparam = 1;
				yyclosure_param(a, c + 0);
			}
		}
		break;
	case 296: /* NIL */
		return;
	case 297: /* LIST */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* list: LIST(list,base) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yylist_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yybase_NT] + 0;
		yytrace(a, 13, c + 0, p->cost[yylist_NT]);
		if (c + 0 < p->cost[yylist_NT]) {
			p->cost[yylist_NT] = c + 0;
			p->rule.yylist = 2;
		}
		break;
	case 298: /* ARGS */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		if (	/* arguments: ARGS(NIL,expr) */
			OP_LABEL(LEFT_CHILD(a)) == 296 /* NIL */
		) {
			c = ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 0;
			yytrace(a, 115, c + 0, p->cost[yyarguments_NT]);
			if (c + 0 < p->cost[yyarguments_NT]) {
				p->cost[yyarguments_NT] = c + 0;
				p->rule.yyarguments = 1;
			}
		}
		/* arguments: ARGS(arguments,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyarguments_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 0;
		yytrace(a, 116, c + 0, p->cost[yyarguments_NT]);
		if (c + 0 < p->cost[yyarguments_NT]) {
			p->cost[yyarguments_NT] = c + 0;
			p->rule.yyarguments = 2;
		}
		break;
	case 299: /* NONE */
		/* decls: NONE */
		yytrace(a, 7, 0 + 0, p->cost[yydecls_NT]);
		if (0 + 0 < p->cost[yydecls_NT]) {
			p->cost[yydecls_NT] = 0 + 0;
			p->rule.yydecls = 2;
		}
		break;
	default:
		PANIC("yylabel", "Bad terminal", OP_LABEL(a));
	}
}

static void yykids(NODEPTR_TYPE p, int eruleno, NODEPTR_TYPE kids[]) {
	if (!p)
		PANIC("yykids", "Null tree in rule", eruleno);
	if (!kids)
		PANIC("yykids", "Null kids in", OP_LABEL(p));
	switch (eruleno) {
	case 116: /* arguments: ARGS(arguments,expr) */
	case 110: /* rexpr: DIV(rexpr,rexpr) */
	case 109: /* rexpr: MUL(rexpr,rexpr) */
	case 108: /* rexpr: SUB(rexpr,rexpr) */
	case 106: /* rexpr: ADD(rexpr,rexpr) */
	case 103: /* rexpr: ATR(rassign,rlval) */
	case 101: /* iexpr: NE(rexpr,rexpr) */
	case 100: /* iexpr: LOGIC_EQUAL(rexpr,rexpr) */
	case 99: /* iexpr: LE(rexpr,rexpr) */
	case 98: /* iexpr: GE(rexpr,rexpr) */
	case 97: /* iexpr: GT(rexpr,rexpr) */
	case 96: /* iexpr: LT(rexpr,rexpr) */
	case 85: /* iexpr: OR(iexpr,iexpr) */
	case 84: /* iexpr: AND(iexpr,iexpr) */
	case 83: /* iexpr: LOGIC_EQUAL(iexpr,iexpr) */
	case 82: /* iexpr: NE(iexpr,iexpr) */
	case 81: /* iexpr: LE(iexpr,iexpr) */
	case 80: /* iexpr: GE(iexpr,iexpr) */
	case 79: /* iexpr: GT(iexpr,iexpr) */
	case 78: /* iexpr: LT(iexpr,iexpr) */
	case 77: /* iexpr: MUL(iexpr,iexpr) */
	case 76: /* iexpr: MOD(iexpr,iexpr) */
	case 75: /* iexpr: DIV(iexpr,iexpr) */
	case 74: /* iexpr: SUB(iexpr,iexpr) */
	case 73: /* iexpr: ADD(iexpr,iexpr) */
	case 72: /* iexpr: ATR(iassign,ilval) */
	case 68: /* iexpr: OR(scmp,scmp) */
	case 67: /* iexpr: AND(scmp,scmp) */
	case 66: /* iexpr: LOGIC_EQUAL(scmp,scmp) */
	case 65: /* iexpr: NE(scmp,scmp) */
	case 64: /* iexpr: LE(scmp,scmp) */
	case 63: /* iexpr: GE(scmp,scmp) */
	case 62: /* iexpr: GT(scmp,scmp) */
	case 61: /* iexpr: LT(scmp,scmp) */
	case 57: /* sexpr: ATR(sassign,slval) */
	case 49: /* rlval: INDEX(rlvec,expr) */
	case 45: /* ilval: INDEX(slvec,expr) */
	case 44: /* ilval: INDEX(ilvec,expr) */
	case 25: /* forin: IN(forstart,expr) */
	case 23: /* forinstr: INSTR(forstmt,expr) */
	case 22: /* forbody: FOR(forin,forinstr) */
	case 21: /* for: INSTR(expr,forbody) */
	case 19: /* do: DO(begin,stmt) */
	case 18: /* while: WHILE(do,expr) */
	case 17: /* cond2: IF(cond,stmt) */
	case 16: /* ifelse: ELSE(cond2,stmt) */
	case 14: /* if: IF(cond,stmt) */
	case 13: /* list: LIST(list,base) */
	case 6: /* decls: INSTR(decls,param) */
	case 5: /* bloco: BLOCK(list,decls) */
	case 4: /* params: NEXT(params,param) */
	case 1: /* finit: ARGB(bloco,params) */
		kids[0] = LEFT_CHILD(p);
		kids[1] = RIGHT_CHILD(p);
		break;
	case 112: /* rexpr: PTR(rlval) */
	case 107: /* rexpr: UMINUS(rexpr) */
	case 102: /* iexpr: REF(ilval) */
	case 93: /* iexpr: PTR(ilval) */
	case 92: /* iexpr: POSDEC(ilval) */
	case 91: /* iexpr: POSINC(ilval) */
	case 90: /* iexpr: DECR(ilval) */
	case 89: /* iexpr: INCR(ilval) */
	case 88: /* iexpr: UMINUS(iexpr) */
	case 87: /* iexpr: NOT(iexpr) */
	case 86: /* iexpr: FACTORIAL(iexpr) */
	case 54: /* sexpr: PTR(slval) */
	case 8: /* param: PARAM(tipo,ID) */
	case 2: /* finit: ARGB(bloco,NIL) */
		kids[0] = LEFT_CHILD(p);
		break;
	case 111: /* rexpr: iexpr */
	case 104: /* rassign: rexpr */
	case 70: /* iassign: rexpr */
	case 69: /* iassign: iexpr */
	case 60: /* scmp: sexpr */
	case 56: /* sassign: iexpr */
	case 55: /* sassign: sexpr */
	case 52: /* slvec: slval */
	case 48: /* rlvec: rlval */
	case 43: /* ilvec: ilval */
	case 38: /* expr: rexpr */
	case 37: /* expr: sexpr */
	case 36: /* expr: iexpr */
	case 35: /* base: bloco */
	case 34: /* base: for */
	case 33: /* base: while */
	case 32: /* base: ifelse */
	case 31: /* base: if */
	case 30: /* base: expr */
	case 27: /* stmt: base */
	case 24: /* forstmt: stmt */
	case 15: /* cond: expr */
	case 12: /* list: base */
	case 3: /* params: param */
		kids[0] = p;
		break;
	case 114: /* rexpr: CALL(ID,VOID) */
	case 105: /* rexpr: REAL */
	case 95: /* iexpr: CALL(ID,VOID) */
	case 71: /* iexpr: INT */
	case 59: /* sexpr: CALL(ID,VOID) */
	case 53: /* sexpr: STR */
	case 51: /* slval: ID */
	case 50: /* slval: LOCAL */
	case 47: /* rlval: ID */
	case 46: /* rlval: LOCAL */
	case 42: /* ilval: ID */
	case 41: /* ilval: LOCAL */
	case 40: /* expr: CALL(ID,VOID) */
	case 29: /* stmt: CONTINUE */
	case 28: /* stmt: BREAK */
	case 26: /* forstart: START */
	case 20: /* begin: START */
	case 11: /* tipo: NUMBER */
	case 10: /* tipo: STRING */
	case 9: /* tipo: INTEGER */
	case 7: /* decls: NONE */
		break;
	case 115: /* arguments: ARGS(NIL,expr) */
	case 113: /* rexpr: CALL(ID,arguments) */
	case 94: /* iexpr: CALL(ID,arguments) */
	case 58: /* sexpr: CALL(ID,arguments) */
	case 39: /* expr: CALL(ID,arguments) */
		kids[0] = RIGHT_CHILD(p);
		break;
	default:
		PANIC("yykids", "Bad rule number", eruleno);
	}
}

static void yyreduce(NODEPTR_TYPE p, int goalnt)
{
  int eruleno = yyrule(STATE_LABEL(p), goalnt);
  short *nts = yynts[eruleno];
  NODEPTR_TYPE kids[2];
  int i;

  for (yykids(p, eruleno, kids), i = 0; nts[i]; i++)
    yyreduce(kids[i], nts[i]);

  switch(eruleno) {
	case 1: /* finit: ARGB(bloco,params) */
#line 71 "diy.brg"
{if (functionReturnType != 3)fprintf(outfp, pfLOCAL pfLOAD pfPOP, 8);
															else if(functionReturnType == 3) fprintf(outfp, pfLOCAL pfLOAD2 pfDPOP, 8);}
		break;
	case 2: /* finit: ARGB(bloco,NIL) */
#line 73 "diy.brg"
{if (functionReturnType != 3) fprintf(outfp, pfLOCAL pfLOAD pfPOP, 8);
													 else if(functionReturnType == 3) fprintf(outfp, pfLOCAL pfLOAD2 pfDPOP, 8);}
		break;
	case 3: /* params: param */
#line 76 "diy.brg"

		break;
	case 4: /* params: NEXT(params,param) */
#line 77 "diy.brg"

		break;
	case 5: /* bloco: BLOCK(list,decls) */
#line 79 "diy.brg"

		break;
	case 6: /* decls: INSTR(decls,param) */
#line 81 "diy.brg"

		break;
	case 7: /* decls: NONE */
#line 82 "diy.brg"

		break;
	case 8: /* param: PARAM(tipo,ID) */
#line 84 "diy.brg"

		break;
	case 9: /* tipo: INTEGER */
#line 86 "diy.brg"

		break;
	case 10: /* tipo: STRING */
#line 87 "diy.brg"

		break;
	case 11: /* tipo: NUMBER */
#line 88 "diy.brg"

		break;
	case 12: /* list: base */
#line 91 "diy.brg"

		break;
	case 13: /* list: LIST(list,base) */
#line 92 "diy.brg"

		break;
	case 14: /* if: IF(cond,stmt) */
#line 95 "diy.brg"
{fprintf(outfp, pfLABEL, mklbl(LEFT_CHILD(p)->place)); }
		break;
	case 15: /* cond: expr */
#line 96 "diy.brg"
{p->place = ++lbl; fprintf(outfp, pfJZ, mklbl(p->place));}
		break;
	case 16: /* ifelse: ELSE(cond2,stmt) */
#line 99 "diy.brg"
{ fprintf(outfp, pfLABEL, mklbl(LEFT_CHILD(p)->place)); }
		break;
	case 17: /* cond2: IF(cond,stmt) */
#line 100 "diy.brg"
{ p->place = ++lbl; fprintf(outfp, pfJMP pfLABEL,
mklbl(p->place), mklbl(LEFT_CHILD(p)->place)); }
		break;
	case 18: /* while: WHILE(do,expr) */
#line 105 "diy.brg"
{ brkcnt--; fprintf(outfp, pfJNZ, mklbl(brklbl[brkcnt + 1])); }
		break;
	case 19: /* do: DO(begin,stmt) */
#line 106 "diy.brg"
{  p->place = LEFT_CHILD(p)->place;}
		break;
	case 20: /* begin: START */
#line 107 "diy.brg"
{ p->place = ++lbl; fprintf(outfp, pfLABEL, mklbl(lbl)); p->place = (brklbl[++brkcnt] = lbl); }
		break;
	case 21: /* for: INSTR(expr,forbody) */
#line 111 "diy.brg"

		break;
	case 22: /* forbody: FOR(forin,forinstr) */
#line 112 "diy.brg"
{fprintf(outfp, pfLABEL, mklbl(lbls[--dblcnt].e_lbl));}
		break;
	case 23: /* forinstr: INSTR(forstmt,expr) */
#line 113 "diy.brg"
{fprintf(outfp, pfJMP, mklbl(lbls[dblcnt - 1].b_lbl));}
		break;
	case 24: /* forstmt: stmt */
#line 114 "diy.brg"
{}
		break;
	case 25: /* forin: IN(forstart,expr) */
#line 115 "diy.brg"
{fprintf(outfp, pfJZ, mklbl(++lbl)); lbls[dblcnt].e_lbl = lbl; brklbl[brkcnt++] = lbls[dblcnt++].e_lbl;}
		break;
	case 26: /* forstart: START */
#line 116 "diy.brg"
{fprintf(outfp, pfLABEL, mklbl(++lbl)); lbls[dblcnt].b_lbl = lbl; }
		break;
	case 27: /* stmt: base */
#line 120 "diy.brg"

		break;
	case 28: /* stmt: BREAK */
#line 121 "diy.brg"
{ fprintf(outfp, pfJMP, mklbl(brklbl[brkcnt - p->value.i])); }
		break;
	case 29: /* stmt: CONTINUE */
#line 122 "diy.brg"
{ fprintf(outfp, pfJMP, mklbl(brklbl[p->value.i])); }
		break;
	case 30: /* base: expr */
#line 125 "diy.brg"
{fprintf(outfp, pfTRASH, (int)p->place); }
		break;
	case 31: /* base: if */
#line 126 "diy.brg"

		break;
	case 32: /* base: ifelse */
#line 127 "diy.brg"

		break;
	case 33: /* base: while */
#line 128 "diy.brg"

		break;
	case 34: /* base: for */
#line 129 "diy.brg"

		break;
	case 35: /* base: bloco */
#line 130 "diy.brg"

		break;
	case 36: /* expr: iexpr */
#line 134 "diy.brg"
{p->place = 4;}
		break;
	case 37: /* expr: sexpr */
#line 135 "diy.brg"
{p->place = 4;}
		break;
	case 38: /* expr: rexpr */
#line 136 "diy.brg"
{p->place = 8;}
		break;
	case 39: /* expr: CALL(ID,arguments) */
#line 139 "diy.brg"
{fprintf(outfp, pfCALL pfTRASH pfPUSH, mkfunc(LEFT_CHILD(p)->value.s),
														 (int)((RIGHT_CHILD(p)->place))); p->place = IDfind(LEFT_CHILD(p)->value.s, NULL) == 3 ? 8: 4;}
		break;
	case 40: /* expr: CALL(ID,VOID) */
#line 141 "diy.brg"
{fprintf(outfp, pfCALL pfPUSH, mkfunc(LEFT_CHILD(p)->value.s));
												p->place = IDfind(LEFT_CHILD(p)->value.s, NULL) == 3 ? 8: 4;}
		break;
	case 41: /* ilval: LOCAL */
#line 146 "diy.brg"
{fprintf(outfp, pfLOCAL, p->value.i * (pfWORD/4));}
		break;
	case 42: /* ilval: ID */
#line 147 "diy.brg"
{fprintf(outfp, pfADDR, p->value.s);}
		break;
	case 43: /* ilvec: ilval */
#line 148 "diy.brg"
{fprintf(outfp, pfLOAD);}
		break;
	case 44: /* ilval: INDEX(ilvec,expr) */
#line 149 "diy.brg"
{ fprintf(outfp, pfIMM pfMUL pfADD, 4);}
		break;
	case 45: /* ilval: INDEX(slvec,expr) */
#line 150 "diy.brg"
{fprintf(outfp, pfADD);}
		break;
	case 46: /* rlval: LOCAL */
#line 152 "diy.brg"
{fprintf(outfp, pfLOCAL, p->value.i * (pfWORD/4));}
		break;
	case 47: /* rlval: ID */
#line 153 "diy.brg"
{fprintf(outfp, pfADDR, p->value.s);}
		break;
	case 48: /* rlvec: rlval */
#line 154 "diy.brg"
{fprintf(outfp, pfLOAD);}
		break;
	case 49: /* rlval: INDEX(rlvec,expr) */
#line 155 "diy.brg"
{ fprintf(outfp, pfIMM pfMUL pfADD, 8);}
		break;
	case 50: /* slval: LOCAL */
#line 158 "diy.brg"
{fprintf(outfp, pfLOCAL, p->value.i * (pfWORD/4));}
		break;
	case 51: /* slval: ID */
#line 159 "diy.brg"
{fprintf(outfp, pfADDR, p->value.s);}
		break;
	case 52: /* slvec: slval */
#line 160 "diy.brg"
{fprintf(outfp, pfLOAD);}
		break;
	case 53: /* sexpr: STR */
#line 163 "diy.brg"
{	lbl++; fprintf(outfp, pfRODATA pfALIGN pfLABEL, mklbl(lbl));
					outstr(p->value.s); fprintf(outfp, pfTEXT pfADDR, mklbl(lbl));}
		break;
	case 54: /* sexpr: PTR(slval) */
#line 166 "diy.brg"
{fprintf(outfp, pfLOAD);}
		break;
	case 55: /* sassign: sexpr */
#line 168 "diy.brg"
{fprintf(outfp, pfDUP);}
		break;
	case 56: /* sassign: iexpr */
#line 169 "diy.brg"
{fprintf(outfp, pfDUP); /*assign to pointer type*/}
		break;
	case 57: /* sexpr: ATR(sassign,slval) */
#line 171 "diy.brg"
{fprintf(outfp, pfSTORE);}
		break;
	case 58: /* sexpr: CALL(ID,arguments) */
#line 172 "diy.brg"
{fprintf(outfp, pfCALL pfTRASH pfPUSH, mkfunc(LEFT_CHILD(p)->value.s),
													 (int)((RIGHT_CHILD(p)->place))); p->place = IDfind(LEFT_CHILD(p)->value.s, NULL) == 3 ? 8: 4;}
		break;
	case 59: /* sexpr: CALL(ID,VOID) */
#line 174 "diy.brg"
{fprintf(outfp, pfCALL pfPUSH, mkfunc(LEFT_CHILD(p)->value.s));
																			 p->place = IDfind(LEFT_CHILD(p)->value.s, NULL) == 3 ? 8: 4;}
		break;
	case 60: /* scmp: sexpr */
#line 178 "diy.brg"
{fprintf(outfp, pfLOAD);}
		break;
	case 61: /* iexpr: LT(scmp,scmp) */
#line 179 "diy.brg"
{fprintf(outfp, pfLT);}
		break;
	case 62: /* iexpr: GT(scmp,scmp) */
#line 180 "diy.brg"
{fprintf(outfp, pfGT);}
		break;
	case 63: /* iexpr: GE(scmp,scmp) */
#line 181 "diy.brg"
{fprintf(outfp, pfGE);}
		break;
	case 64: /* iexpr: LE(scmp,scmp) */
#line 182 "diy.brg"
{fprintf(outfp, pfLE);}
		break;
	case 65: /* iexpr: NE(scmp,scmp) */
#line 183 "diy.brg"
{fprintf(outfp, pfNE);}
		break;
	case 66: /* iexpr: LOGIC_EQUAL(scmp,scmp) */
#line 184 "diy.brg"
{fprintf(outfp, pfEQ);}
		break;
	case 67: /* iexpr: AND(scmp,scmp) */
#line 185 "diy.brg"
{fprintf(outfp, pfAND);}
		break;
	case 68: /* iexpr: OR(scmp,scmp) */
#line 186 "diy.brg"
{fprintf(outfp, pfOR);}
		break;
	case 69: /* iassign: iexpr */
#line 189 "diy.brg"
{fprintf(outfp, pfDUP);}
		break;
	case 70: /* iassign: rexpr */
#line 192 "diy.brg"
{fprintf(outfp, pfD2I pfDUP);}
		break;
	case 71: /* iexpr: INT */
#line 194 "diy.brg"
{fprintf(outfp, pfIMM, p->value.i);}
		break;
	case 72: /* iexpr: ATR(iassign,ilval) */
#line 195 "diy.brg"
{fprintf(outfp, pfSTORE);}
		break;
	case 73: /* iexpr: ADD(iexpr,iexpr) */
#line 196 "diy.brg"
{fprintf(outfp, pfADD);}
		break;
	case 74: /* iexpr: SUB(iexpr,iexpr) */
#line 197 "diy.brg"
{fprintf(outfp, pfSUB);}
		break;
	case 75: /* iexpr: DIV(iexpr,iexpr) */
#line 198 "diy.brg"
{fprintf(outfp, pfDIV);}
		break;
	case 76: /* iexpr: MOD(iexpr,iexpr) */
#line 199 "diy.brg"
{fprintf(outfp, pfMOD);}
		break;
	case 77: /* iexpr: MUL(iexpr,iexpr) */
#line 200 "diy.brg"
{fprintf(outfp, pfMUL);}
		break;
	case 78: /* iexpr: LT(iexpr,iexpr) */
#line 201 "diy.brg"
{fprintf(outfp, pfLT);}
		break;
	case 79: /* iexpr: GT(iexpr,iexpr) */
#line 202 "diy.brg"
{fprintf(outfp, pfGT);}
		break;
	case 80: /* iexpr: GE(iexpr,iexpr) */
#line 203 "diy.brg"
{fprintf(outfp, pfGE);}
		break;
	case 81: /* iexpr: LE(iexpr,iexpr) */
#line 204 "diy.brg"
{fprintf(outfp, pfLE);}
		break;
	case 82: /* iexpr: NE(iexpr,iexpr) */
#line 205 "diy.brg"
{fprintf(outfp, pfNE);}
		break;
	case 83: /* iexpr: LOGIC_EQUAL(iexpr,iexpr) */
#line 206 "diy.brg"
{fprintf(outfp, pfEQ);}
		break;
	case 84: /* iexpr: AND(iexpr,iexpr) */
#line 207 "diy.brg"
{fprintf(outfp, pfAND);}
		break;
	case 85: /* iexpr: OR(iexpr,iexpr) */
#line 208 "diy.brg"
{fprintf(outfp, pfOR);}
		break;
	case 86: /* iexpr: FACTORIAL(iexpr) */
#line 209 "diy.brg"
{/*fprintf(outfp)*/ /*FIXME*/}
		break;
	case 87: /* iexpr: NOT(iexpr) */
#line 210 "diy.brg"
{fprintf(outfp, pfIMM pfEQ, 0);}
		break;
	case 88: /* iexpr: UMINUS(iexpr) */
#line 211 "diy.brg"
{fprintf(outfp, pfNEG);}
		break;
	case 89: /* iexpr: INCR(ilval) */
#line 216 "diy.brg"
{fprintf(outfp, pfDUP pfINCR pfLOAD, 1);}
		break;
	case 90: /* iexpr: DECR(ilval) */
#line 217 "diy.brg"
{fprintf(outfp, pfDUP pfDECR pfLOAD, 1);}
		break;
	case 91: /* iexpr: POSINC(ilval) */
#line 218 "diy.brg"
{fprintf(outfp, pfDUP pfLOAD pfSWAP pfINCR, 1);}
		break;
	case 92: /* iexpr: POSDEC(ilval) */
#line 219 "diy.brg"
{fprintf(outfp, pfDUP pfLOAD pfSWAP pfDECR, 1);}
		break;
	case 93: /* iexpr: PTR(ilval) */
#line 222 "diy.brg"
{if (LEFT_CHILD(p)->place == 2) { fprintf(outfp, pfLDCHR);}
                        else {fprintf(outfp, pfLOAD);}}
		break;
	case 94: /* iexpr: CALL(ID,arguments) */
#line 226 "diy.brg"
{fprintf(outfp, pfCALL pfTRASH pfPUSH, mkfunc(LEFT_CHILD(p)->value.s), (int)((RIGHT_CHILD(p)->place)));
																					 p->place = IDfind(LEFT_CHILD(p)->value.s, NULL) == 3 ? 8: 4;}
		break;
	case 95: /* iexpr: CALL(ID,VOID) */
#line 229 "diy.brg"
{fprintf(outfp, pfCALL pfPUSH, mkfunc(LEFT_CHILD(p)->value.s));
																			p->place = IDfind(LEFT_CHILD(p)->value.s, NULL) == 3 ? 8: 4;}
		break;
	case 96: /* iexpr: LT(rexpr,rexpr) */
#line 235 "diy.brg"
{fprintf(outfp, pfDCMP pfIMM pfLT, 0);}
		break;
	case 97: /* iexpr: GT(rexpr,rexpr) */
#line 236 "diy.brg"
{fprintf(outfp, pfDCMP pfIMM pfGT, 0);}
		break;
	case 98: /* iexpr: GE(rexpr,rexpr) */
#line 237 "diy.brg"
{fprintf(outfp, pfDCMP pfIMM pfGE, 0);}
		break;
	case 99: /* iexpr: LE(rexpr,rexpr) */
#line 238 "diy.brg"
{fprintf(outfp, pfDCMP pfIMM pfLE, 0);}
		break;
	case 100: /* iexpr: LOGIC_EQUAL(rexpr,rexpr) */
#line 239 "diy.brg"
{fprintf(outfp, pfDCMP pfIMM pfEQ, 0);}
		break;
	case 101: /* iexpr: NE(rexpr,rexpr) */
#line 240 "diy.brg"
{fprintf(outfp, pfDCMP pfIMM pfNE, 0);}
		break;
	case 102: /* iexpr: REF(ilval) */
#line 245 "diy.brg"

		break;
	case 103: /* rexpr: ATR(rassign,rlval) */
#line 249 "diy.brg"
{fprintf(outfp, pfSTORE2);}
		break;
	case 104: /* rassign: rexpr */
#line 250 "diy.brg"
{fprintf(outfp, pfDUP2);}
		break;
	case 105: /* rexpr: REAL */
#line 251 "diy.brg"
{lbl++; fprintf(outfp, pfRODATA pfALIGN pfLABEL pfDOUBLE, mklbl(lbl), p->value.r);
					fprintf(outfp, pfTEXT pfADDR pfLOAD2, mklbl(lbl));}
		break;
	case 106: /* rexpr: ADD(rexpr,rexpr) */
#line 253 "diy.brg"
{fprintf(outfp, pfDADD);}
		break;
	case 107: /* rexpr: UMINUS(rexpr) */
#line 254 "diy.brg"
{fprintf(outfp, pfDNEG);}
		break;
	case 108: /* rexpr: SUB(rexpr,rexpr) */
#line 255 "diy.brg"
{fprintf(outfp, pfDSUB);}
		break;
	case 109: /* rexpr: MUL(rexpr,rexpr) */
#line 256 "diy.brg"
{fprintf(outfp, pfDMUL);}
		break;
	case 110: /* rexpr: DIV(rexpr,rexpr) */
#line 257 "diy.brg"
{fprintf(outfp, pfDDIV);}
		break;
	case 111: /* rexpr: iexpr */
#line 258 "diy.brg"
{fprintf(outfp, pfI2D);}
		break;
	case 112: /* rexpr: PTR(rlval) */
#line 261 "diy.brg"
{fprintf(outfp, pfLOAD2);}
		break;
	case 113: /* rexpr: CALL(ID,arguments) */
#line 264 "diy.brg"
{fprintf(outfp, pfCALL pfTRASH pfDPUSH, mkfunc(LEFT_CHILD(p)->value.s),
														 (int)((RIGHT_CHILD(p)->place))); p->place = IDfind(LEFT_CHILD(p)->value.s, NULL) == 3 ? 8: 4;}
		break;
	case 114: /* rexpr: CALL(ID,VOID) */
#line 267 "diy.brg"
{fprintf(outfp, pfCALL pfDPUSH, mkfunc(LEFT_CHILD(p)->value.s));
																			 p->place = IDfind(LEFT_CHILD(p)->value.s, NULL) == 3 ? 8: 4;}
		break;
	case 115: /* arguments: ARGS(NIL,expr) */
#line 271 "diy.brg"
{p->place = RIGHT_CHILD(p)->place; }
		break;
	case 116: /* arguments: ARGS(arguments,expr) */
#line 272 "diy.brg"
{p->place = LEFT_CHILD(p)->place + RIGHT_CHILD(p)->place;}
		break;
	default: break;
  }
}

int yyselect(NODEPTR_TYPE p)
{
	yylabel(p,p);
	if (((struct yystate *)STATE_LABEL(p))->rule.yyfinit == 0) {
		fprintf(stderr, "No match for start symbol (%s).\n", yyntname[1]);
		return 1;
	}
	yyreduce(p, 1);
	return 0;
}


#line 275 "diy.brg"

#include "y.tab.h"
extern void yyerror(const char*);
extern char **yynames;
extern int trace;
extern int localCounter;

void externs()
{
  int i;

  for (i = 0; i < extcnt; i++)
    if (extrns[i])
      fprintf(outfp, pfEXTRN, extrns[i]);
}


void function(int pub, Node *type, char *name, Node *body)
{
	Node *bloco = LEFT_CHILD(body);
	IDpop();
	if (bloco != 0) { /* not a forward declaration */
		long par;
		int fwd = IDfind(name, &par);
		if (fwd > 40) yyerror("duplicate function");
		else {
			IDreplace(fwd+40, name, par);
			fflush(stdout);
  		fprintf(outfp, pfTEXT pfALIGN pfGLOBL pfLABEL pfENTER, mkfunc(name), pfFUNC, mkfunc(name), - localPos * (pfWORD/4));
  		functionReturnType = type->value.i;
  		printNode(body, stdout, yynames);
  		yyselect(body);
  		fprintf(outfp, pfLEAVE pfRET); /* just in case ... */
			freeNode(body);
			for (int i = 0; i < extcnt; i++)
		    if (extrns[i] && strcmp(extrns[i], mkfunc(name)) == 0) extrns[i] = 0;
		}
	}
	else {
		char* buffer = (char*) malloc(sizeof(char) * 80);
		*buffer = '\0';
  		strcpy(buffer, "_");
  		strcat(buffer, name);
		extrns[extcnt++] = buffer;
	}
}


void declare(int pub, int cnst, Node *type, char *name, Node *value)
{
  int typ;
  if (!value) {
    if (!pub && cnst) yyerror("local constants must be initialised");

    if (pub ) {
    //	variable is extern
    	fprintf(outfp, pfEXTRN, name);
    }
    //if(!pub && !cnst) {
    //	fprintf(outfp, pfGLOBL pfBSS pfALIGN pfLABEL pfBYTE, name, name ,name);
    //}
    //}
    //}

    return;
  }
  if (value->attrib = INT && value->value.i == 0 && type->value.i > 10)
  	return; /* NULL pointer */
  if ((typ = value->info) % 10 > 5) typ -= 5;
  if (type->value.i != typ)
    yyerror("wrong types in initialization");
}
