struct Foo {
    x: i32
}

enum Bar {
    One,
    Two
}

fn foo(a: Bar): i32 {
    let a: u32;
    return 4;
}

fn main(): i32 {
    let u: Foo;
    u.x = 3;
    let pfft: &Foo = &u;

    let q: Bar = Bar::One;
    let v: [Bar] = [q];
    let z: Bar = v[0];

    switch(z) {
        case Bar::One => {
            return 3;
        }
        default => {
            return 0;
        }
    }

    if(u.x > 1) {
        return 0;
    }
    else if (u.x == -1) {
        return 0;
    }
    else {
        return u.x;
    }

    return 0;
}