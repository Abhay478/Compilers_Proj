struct Foo {
    a: u32
}

claim Foo is Group {
    (c = a + b) => {
        c.a = a.a + b.a;
    }
    (c = 0) => {
        c.a = 0;
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

fn main(): i32 {
    return 0;
}