# only rules from general are valid here

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
