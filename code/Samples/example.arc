enum Bar {
    Zero,
    One,
    Two
}

// Noting the verbosity of the below code, we are highly inclined to implement switch-case as well.
forge (a: Cyclic<3>) as (b: Bar) {
    if(a == Bar::Zero) {
        b = 0;
    }
    else if(a == Bar::One) {
        b = 1;
    }
    else {
        b = 2;
    }
}

forge Bar as (a: Cyclic<3>) {
    if(a == 0) {
        return Bar::Zero;
    }
    if(a == 1) {
        return Bar::One;
    }
    else {
        return Bar::Two;
    }
}

claim Bar is Group {
    (x + y) => {
        return (x as (Cyclic<3>) + y as (Cyclic<3>)) as (Bar);
    }
    0 => {
        return Bar::Zero;
    }

    -x => {
        return (- (x as Cyclic<3>)) as Bar;
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
