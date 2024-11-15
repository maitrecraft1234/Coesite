rules not defined here are either from general.md or in other
files within the same folder

# Method
the method is the oposite of a function, it is impure by default
(expected to mutate a state) and is used for imperative / lower level
this will be the first part of the language to be implemented

```
<method> =
    [<attributes>],
    "meth", <ws>,
    ["for", <ws>, <type>], <ws>,
    <identifier>, [<ws>],
    <param>, [<ws>],
    "->", [<ws>],
    <type>, [<ws>],
    <block>;

<attribute> =
    "entry"
    | "noreturn"
    | "pure"
    ;

<param> = 
    "(",
    {<expicit_var>}, <ws>,
    <type>, <ws>,
    <identifier>,
    ")";

<expicit_var> =
    <type>, <ws>,
    ":", <ws>,
    <identifier>;

<block> =
    <block_start>,
    {
        [<ws>],
        <block_el>,
        [<ws>],
    },
    <block_end>;

<block_el> =
    <statement> 
    | <if>
    | <while>
    | <for>
    | <block>
    | <return>
    ;
```
