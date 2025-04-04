* In this file we omit the `[<ws>]` constraints as they would waste memory space
on our beloved github servers hosting this repo.

We constrain ourselves to inductive types for the moment, this is not definitive.
to this end we use `constructors`, as any proper language does. A constructor
is a chain of letter that must that with an uppercase symbol.
```
<constructor> =
    {A-Z},
    <alpha>;
```

Before going further, it is necessary to introduce more syntax about how the types are
handled, for this we use `type_var` elements, which are universally quantified and
must start with a specific symbol, that for now will be set to `~` which is again not definitive

```
<type_var> =
    "~",
    {a-z},
    <alpha>;
```

Now in order to write down a type, which we need here, we set `ty` to be an element
that represents a type, we have two cases, wheter the type is just given as a variable
or if it is a specific type, either native or defined, in which case it might have arguments which need to be given in the shape of `ty` themselves
```
<ty> =
    <type_var>  |
    ( <identifier>,
      [<ty>]
    )           |
    (
    "(" [<ty>,] ")"
    )
    ;
```

We now almost have all the tools we need, we just use a temporary element
`cons_def` that will correspond to the definition of a `constructor` in a type.

```
<cons_def> =
    "|",
    <constructor>,
    [<ty>];
```

Finally, we give a grammar that allows us to create an `inductive` type :
```
<inductive> =
    "Ind",
    <identifier>,
    ":=",
    <type_vars>,
    [<cons_def>];
```

As an example, we can construct the following types as :
```
Ind bOoLeAn :=
    | tRuE
    | FaLsE

Ind peanoInteger :=
    | Zero
    | Succ peanoInteger

Ind list ~a :=
    | Nil
    | Cons (~a, list ~a)

Ind bintree ~a :=
    | Leaf
    | Node (bintree ~a, bintree ~a)
```