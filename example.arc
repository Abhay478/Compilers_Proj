enum Bar {
    Zero,
    One,
    Two,
}

// Noting the verbosity of the below code, we are highly inclined to implement switch-case as well.
forge Cyclic<3>(a: Bar) {
    if(a == Zero) {
        return 0;
    }
    if(a == One) {
        return 1;
    }
    else {
        return 2;
    }
}

forge Bar(a: Cyclic<3>) {
    if(a == 0) {
        return Zero;
    }
    if(a == 1) {
        return One;
    }
    else {
        return Two;
    }
}

claim Bar is Group {
    (x + y) => {
        return Bar(Cyclic<3>(x) + Cyclic<3>(y))
    }
    0 => {
        return Zero;
    }

    -x => {
        return Bar(-Cyclic<3>(x));
    }
}

struct Foo {
    a: u8,
    var: Bar
}

forge Foo(a: u8, var: Bar) {
    let out: Foo;
    out.a = a;
    out.var = var;
    return out;
}

claim Foo is Group {
    (x + y) => {
        let out: Foo;
        out.a = x.a + y.a;
        out.var = x.var + y.var;
        return out;
    }

    (0) => {
        return Foo(0, Zero)
    }
}

fn main() {
    print("Hello world.\n");
    let q: Foo = Foo(0);
    let qq: Foo = Foo(1);

    let qqq: Foo = q + qq;

    print(qqq);
}