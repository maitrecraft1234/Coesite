```
<nonrec_expression> =
    <unary_op>
    | <grouping>
    | <block>
    | <function_call>
    ;



<expression> = 
    <binary_operation>
    | <nonrec_expression>
    ;

<binary_op> =
    <additive_binop>
    ;

<additive_operator> =
    "+",
    "-",
    ;

<additive_binop>
    <multiplicative_binop>,
    {
        <additive_operator>,
        <multiplicative_binop>
    }
    ;

<multiplicative_operation> =
    "*",
    "/",
    ;

<multiplicative_binop> =
    <nonrec_expression>,
    {
        <multiplicative_operator>,
        <nonrec_expression>
    }
```
