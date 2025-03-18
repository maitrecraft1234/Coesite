{ (* -*- tuareg -*- *)
  open Lexing
  open Error
  (*open Position*)
  open CoesiteParser

  let next_line_and f lexbuf  =
    Lexing.new_line lexbuf;
    f lexbuf

  let error lexbuf =
    error "lexing" (lex_join lexbuf.lex_start_p lexbuf.lex_curr_p)

}

let newline = ('\010' | '\013' | "\013\010")

let blank   = [' ' '\009' '\012']

let digit = ['0'-'9']
let lower = ['a'-'z']
let upper = ['A'-'Z']

let alpha = (lower | upper)
let alphanum = (alpha | digit)

let identifier = alpha + (alphanum | '_') *


rule token = parse
  (** Layout *)
  | newline         { next_line_and token lexbuf  }
  | blank+          { token lexbuf                }
  | eof             { EOF                         }
  | "{"             { LHOOK                       }
  | "}"             { RHOOK                       }
  | "["             { LBRACKET                    }
  | "]"             { RBRACKET                    }
  | "("             { LPAREN                      }
  | ")"             { RPAREN                      }
  | ","             { COMMA                       }
  | "F"             { F                           }
  | ":="            { DEFINED                     }
  | "entry"         { ENTRY                       }
  | "impure"        { IMPURE                      }
  | "io"            { IO                          }
  | digit+ as x     { INT64 (Int64.of_string x)   }
  | identifier as id{ IDENT id                    }
  