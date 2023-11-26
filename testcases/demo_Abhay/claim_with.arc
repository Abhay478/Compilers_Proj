struct Foo {
    a: u32
}

claim Foo is Group {
    (c = 0) => {
        c.a = 0;
    }
    (c = a + b) => {
        c.a = a.a + b.a;
    }
    (c = -a) => {
        c.a = -a.a;
    }
}

struct Bar {
    a: u32
}

fn foo_to_bar(foo: Foo) : Bar {
    let out: Bar;
    out.a = foo.a;
    return out;
}

fn bar_to_foo(bar: Bar) : Foo {
    let out: Foo;
    out.a = bar.a;
    return out;
}

claim Bar is Group with (foo_to_bar, bar_to_foo);

forge (a: u32) as (b: Bar) {
    b.a = a;
}

fn main(): i32 {
    let a: Bar = 5 as (Bar);
    let b: Bar = a + a;
    let c: Bar = -a;
    print(c.a as (str));
    print(b.a as (str));
    return 0;
}
