each statement evaluates to the value of the last expression in the statement.
```
<statement> =
    [<ws>],
    <expression>
    | <declaration>
    | <dbg> 
    | <return> 
    ,
    [<ws>],
    ";"
    ;
```

a declaration is a statement that binds a value to a name.
this evaluates to the value of the expression.
when the type is omitted, the type is inferred from the expression.
the chosen type will be the least specific type that can hold the value of the expression.
(eg. if the expression can be an int or a i8, the type will be int)
if the type cannot be inferred, an error will be thrown before the execution.
```
<declaration> =
    "let",
    <identifier>,
    [
        ":",
        <type>,
    ]
    "=",
    <expression>
    | <block>
    ;
```

return evaluates to void.
it is used to give a value to the caller of the function.
the value is the value of the expression.
```
<return> =
    "return",
    <ws>,
    <expression>
```
