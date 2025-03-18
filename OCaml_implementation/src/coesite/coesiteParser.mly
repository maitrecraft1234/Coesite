%{ (* -*- tuareg -*- *)

  open CoesiteAST
  (*
  open Position
  open Stdint *)

%}


%token<string> IDENT

(*
    Will be added later
    commented now so dune stops crying

%token<Stdint.int128> INT128 *)
%token<Stdint.int64> INT64 (*
%token<Stdint.int32> INT32
%token<Stdint.int16> INT16
%token<Stdint.int8> INT8

%token<Stdint.uint128> UINT128
%token<Stdint.uint64> UINT64
%token<Stdint.uint32> UINT32
%token<Stdint.uint16> UINT16
%token<Stdint.uint8> UINT8
*)

(* keywords *)
%token METH F


(* Attributes *)
%token IMPURE ENTRY IO

(* Symbols *)
%token LHOOK RHOOK LBRACKET RBRACKET LPAREN RPAREN COMMA EOF  DEFINED



%start<CoesiteAST.t> program
%%

%inline parens(X) : LPAREN x=X RPAREN {x}
%inline hooks(X) : LHOOK x=X RHOOK {x}
%inline brackets(X) : LBRACKET x=X RBRACKET {x}


program :
  | EOF { [] }
  | located(definition) COMMA program { ($1)::($3) }

attribute :
  | IMPURE  { `Impure }
  | ENTRY   { `Entry  }
  | IO      { `IO     }

body :
  | located(literal) { Literal $1 }

literal :
  | INT64 { Lit_int64 $1 }

ident :
  | IDENT { Id $1 }

definition :
  | METH { Method }
  | LBRACKET separated_list(COMMA, attribute) RBRACKET F located(ident) list(located(ident)) DEFINED located(body) { Function($2, $5, $6, $8)}


%inline located(X): x=X {
  Position.with_poss $startpos $endpos x
}
