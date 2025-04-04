# only rules from general are valid here
* In this file we omit the `[<ws>]` constraints as they would waste memory space
on our beloved github servers hosting this repo.


We start by defining something that will not be useful until 2027, at least in this
part of the repo, and that is attributes. They are meant to give information
about the behavior of the function and can, at this moment in time be the following :

```
<attribute> =
    "impure" |
    "entry" |
    "io"
    ;
```

We then define patterns which will come in handy to reason about arguments of functions as well as in for pattern matchinng which is a maybe soonish or at some pointish coming feature.

```
<pattern> =
    "_" |
    "(" {<pattern>,} ")" |
    <constructor>, <pattern> |
    <literal> |
    <variable>;
```

Finally, the core of our work, we can (sadly only partially) set how functions are
defined, with a name given as an `identifier` and arguments given as `patterns`.

```
<function> =
    [<attributes>],
    "f" | "F" ,
    <identifier>,
    {<patterns>},
    <body>;
```


```
<params> =
    {
        <identifier>,
        ":",
        <type>
    };
```

```
<block> =
    <block_start>,
    {
        <statement>,
    },
    <block_end>;
    ;
```