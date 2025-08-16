rules not defined here are either from general.md or in other
files within the same folder

# Method
the method is the oposite of a function, it is impure by default
(expected to mutate a state) and is used for imperative / lower level
this will be the first part of the language to be implemented

no return type means void
```
<method> =
    [<attributes>],
    "meth", <ws>,
    ["for", <ws>, <type>], <ws>,
    <identifier>, [<ws>],
    <param>, [<ws>],
    [
    "->", [<ws>],
    <type>, [<ws>],
    ],
    <block>;
```

the following attributes are allowed
* entry: the method is an entry point of the program (I plan on making it priority level and depending on the arguments of the function)
* noreturn: the method does not return (any return should be considered an error including the end of block implicit return)
* pure: the method does not mutate the state allowing for it to be treated as a function
```
<attribute> =
    "entry"
    | "noreturn"
    | "pure"
    ;
```

```
<param> = 
    "(",
    {<expicit_var>}, <ws>,
    <type>, <ws>,
    <identifier>,
    ")";
```

there is no reason to forbid the void type but it should be considered a optional
in case of a void type use the behavior is up to the implementation
```
<expicit_var> =
    <type>, <ws>,
    ":", <ws>,
    <identifier>;
```

a block evluates to the value of the last expression in the block
empty block evaluates to void
(also some kind of keyword to break and yield some value might be implemented)
```
<block> =
    <block_start>,
    {
        [<ws>],
        <block_el>,
        [<ws>],
    },
    <block_end>;
```

note that appart from the
```<for>```,```<while>```
that can only evaluate to void
all these can evaluate to any type
note that ```<if>``` only evaluates to a type when
paired with an else statement
```
<block_el> =
    <statement> 
    | <if>
    | <while>
    | <for>
    | <block>
    ;
```
