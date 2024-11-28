evaluates to the subexpression.
```
<grouping> =
    "(",
    <expression>,
    ")"
    ;
```

a function evaluates the the return value of the function.
(explicit or implicit)
```
<funtion_call> =
    <identifier>,
    "(",
    {
        <expression>,
        ",",
    },
    ")";
```


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

(* binary operation should have an expected type right and left and
a following evaluation hopefully this is explicited somewhere *)
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
