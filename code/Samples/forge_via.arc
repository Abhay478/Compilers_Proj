struct Bar {
    a: u8
}

struct Foo {
    a: u8
}

fn btf(f: Foo): BigRational {
    let b: Bar;
    b.a = f.a;
    return b;
}

fn ftb(b: BigRational): Foo {
    let f: Foo;
    f.a = b.a;
    return f;
}

claim Foo is Group with (btf, ftb);
