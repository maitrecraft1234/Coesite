# only rules from general are valid here


note that the statment defined here should most likely be an expression instead
in the rest of the language statments will end with a semicolon
and grouping cannot hold a statement but only an expression for example

```

<dbg> =
    "dbg",
    {<ws>},
    <block_start>,
    <statement>,
    <block_end>

<statement_no_left_req> = 
        <grouping>
        | <u_op>
        | <number_litteral>

<statement> = 
        <statement_no_left_req>
        | <bin_op>

<grouping> = "(", <statement>, ")"

<bin_op> = <statement_no_left_req> <bin_operator> <statement>

<bin_operator> =
        "+"
        | "-"

<u_operator> =
    "-"

<u_op> = <u_operator> <statement>

```
