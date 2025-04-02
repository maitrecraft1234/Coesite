open Sexplib.Std
open Position

(** A program is a list of definitions. *)
type program = definition located list

[@@deriving sexp]

and definition =
  | Function of
    functional_attribute list *   (* Attributs de la fonction *)
    identifier located *          (* Nom de la fonction *)
    pattern located list *        (* patternes des arguments *)
    expression located            (* Corps de la fonction *)
  | Method
  | ASM_def
  | Macro

and functional_attribute = [`Impure | `Entry | `IO ]

and expression =
  | Literal of literal located
  | Variable of identifier located
  | Tuple of expression located list
  | Apply of expression located * expression located
  | Define of expression vdefinition * expression located

and pattern =
  | PLit of literal located
  | PVar of identifier located
  | PCons of constructor * pattern
  | PTuple of pattern located list (* non empty *)

and 'a vdefinition =
  identifier located * 'a located

and value_definition =
  | VDefinition of identifier located * expression located

and inductive_type =
  | Inductive of constructor located * ttype list

and type_var =
  | TVar of string

and constructor =
  | Constr of string

and identifier =
  | Id of string

and literal =
  | Lit_int64 of int64

type t = program

[@@deriving sexp]
