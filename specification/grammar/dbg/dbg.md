# only rules from general are valid here


note that the statment defined here should most likely be an expression instead
in the rest of the language statments will end with a semicolon
and grouping cannot hold a statement but only an expression for example

```

<dbg> =
    "dbg",
    [<ws>],
    <block_start>,
    <statement>,
    <block_end>

<statement_no_left_req> = 
        <grouping>
        | <u_op>
        | <number_litteral>

<statement> = 
        <statement_no_left_req>
        | <bin_op_add>

<grouping> = "(", <statement>, ")"

<bin_op> = <bin_op_mul>

<bin_op_mul> = <statement_no_left_req>, {<bin_operator_mul>, <bin_op_mul>}

<bin_operator_mul> =
        "*"
        | "/"

<bin_op_add> =
        <bin_op_mul> , {<bin_operator_add>, <bin_op_add>}

<bin_operator_add> =
        "+"
        | "-"

<u_operator> =
    "-"

<u_op> = <u_operator>, <statement_no_left_req>

```
