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

<return> =
    "return",
    <ws>,
    <expression>

```
