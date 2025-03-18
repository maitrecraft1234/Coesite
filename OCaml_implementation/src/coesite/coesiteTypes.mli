type size = [`S16 | `S32 | `S64 | `S128]

type t = [
    | `Unsigned of size      (* unsigned integer of size size *)
    | `Integer of size      (* unsigned integer of size size *)
    | `Fint             (* fast int *)
    | `String
    | `Bool
    | `Void
]
