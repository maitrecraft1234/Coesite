```
<statement> =
    [<ws>],
    <expression>
    | <declaration>
    | <dbg> 
    ,
    [<ws>],
    ";";

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
